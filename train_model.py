import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report, accuracy_score

# 1. Load the dataset
df = pd.read_csv('compost_data.csv')

# 2. Basic Data Inspection
print("--- Dataset Info ---")
print(df.info())
print("\n--- Class Distribution ---")
print(df['Label'].value_counts())

# 3. Visualization (Optional but recommended for coursework screenshots)
plt.figure(figsize=(10, 6))
sns.scatterplot(data=df, x='Temperature', y='Humidity', hue='Label', style='Label')
plt.title('Sia-Compost: Temperature vs Humidity Clusters')
plt.show()

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
with open('model.h', 'w') as f:
    f.write(c_code)

print("\n--- Phase 2 Complete ---")
print("Success! 'model.h' has been generated. This is your 'Edge Brain'.")