import argparse
import os
from pathlib import Path

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report, accuracy_score

def parse_args():
    """Parse command-line arguments for dataset, outputs, and plotting behavior."""
    parser = argparse.ArgumentParser(description="Train compost classifier and export model.h")
    parser.add_argument("--data", default="compost_data.csv", help="Path to labeled CSV dataset")
    parser.add_argument("--output-model", default="model.h", help="Output path for generated C++ header")
    parser.add_argument("--plot-output", default="training_scatter.png", help="Output image path for the scatter plot")
    parser.add_argument("--show-plot", action="store_true", help="Display plot window interactively")
    return parser.parse_args()

def main():
    """Run the training pipeline, save visualization, evaluate model, and export C++ header."""
    args = parse_args()
    cwd = Path.cwd().resolve()
    for output_path in (args.plot_output, args.output_model):
        output_dir = Path(output_path).expanduser().resolve().parent
        if output_dir != cwd:
            os.makedirs(output_dir, exist_ok=True)

    # 1. Load the dataset
    df = pd.read_csv(args.data)

    # 2. Basic Data Inspection
    print("--- Dataset Info ---")
    print(df.info())
    print("\n--- Class Distribution ---")
    print(df['Label'].value_counts())

    # 3. Visualization
    plt.figure(figsize=(10, 6))
    sns.scatterplot(data=df, x='Temperature', y='Humidity', hue='Label', style='Label')
    plt.title('Sia-Compost: Temperature vs Humidity Clusters')
    plt.tight_layout()
    plt.savefig(args.plot_output, dpi=150)
    if args.show_plot:
        plt.show()
    plt.close()
    print(f"\nSaved plot: {args.plot_output}")

    # 4. Prepare Features and Labels
    X = df[['Temperature', 'Humidity', 'Methane']]
    y = df['Label']

    # 5. Split data (80% training, 20% testing)
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    # 6. Initialize and Train Random Forest
    # We keep n_estimators low (e.g., 10-20) to ensure the model fits on the ESP32 later
    model = RandomForestClassifier(n_estimators=15, max_depth=10, random_state=42)
    model.fit(X_train, y_train)

    # 7. Evaluate
    y_pred = model.predict(X_test)
    print("\n--- Model Evaluation ---")
    print(f"Accuracy: {accuracy_score(y_test, y_pred) * 100:.2f}%")
    print("\nClassification Report:")
    print(classification_report(y_test, y_pred))

    from micromlgen import port

    # 8. Convert the model to C++ code
    # This translates the Random Forest logic into a C++ class
    c_code = port(model, class_name='CompostClassifier', features=X.columns)

    # 9. Save it as a header file for your VS Code project
    with open(args.output_model, 'w') as f:
        f.write(c_code)

    print("\n--- Phase 2 Complete ---")
    print(f"Success! '{args.output_model}' has been generated. This is your 'Edge Brain'.")

if __name__ == "__main__":
    main()
