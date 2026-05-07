#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class RandomForest {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        uint8_t votes[4] = { 0 };
                        // tree #1
                        if (x[0] <= 37.75) {
                            if (x[1] <= 66.8499984741211) {
                                if (x[2] <= 425.5) {
                                    if (x[2] <= 205.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[2] <= 285.5) {
                                            votes[3] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 35.60000038146973) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        if (x[0] <= 35.85000038146973) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 21.949999809265137) {
                                    if (x[2] <= 491.0) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }
                        }

                        else {
                            if (x[1] <= 41.14999961853027) {
                                if (x[1] <= 36.14999961853027) {
                                    if (x[0] <= 44.14999961853027) {
                                        if (x[2] <= 349.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    if (x[2] <= 330.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 41.14999961853027) {
                                    if (x[2] <= 287.5) {
                                        if (x[1] <= 60.75000190734863) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }

                                    else {
                                        if (x[2] <= 607.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[2] <= 235.0) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #2
                        if (x[2] <= 263.0) {
                            if (x[2] <= 165.5) {
                                if (x[2] <= 130.5) {
                                    if (x[2] <= 28.5) {
                                        if (x[1] <= 53.25) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }

                                    else {
                                        if (x[0] <= 33.35000038146973) {
                                            if (x[2] <= 52.5) {
                                                if (x[2] <= 35.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[2] <= 43.5) {
                                                        votes[3] += 1;
                                                    }

                                                    else {
                                                        votes[0] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 51.10000038146973) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[3] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 41.54999923706055) {
                                                if (x[0] <= 35.54999923706055) {
                                                    if (x[0] <= 34.5) {
                                                        if (x[0] <= 33.94999885559082) {
                                                            votes[0] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 49.55000019073486) {
                                                                votes[0] += 1;
                                                            }

                                                            else {
                                                                votes[3] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        if (x[0] <= 34.64999961853027) {
                                                            votes[3] += 1;
                                                        }

                                                        else {
                                                            if (x[0] <= 35.45000076293945) {
                                                                votes[3] += 1;
                                                            }

                                                            else {
                                                                votes[0] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[2] <= 100.0) {
                                                        if (x[2] <= 77.5) {
                                                            if (x[1] <= 63.85000038146973) {
                                                                votes[0] += 1;
                                                            }

                                                            else {
                                                                votes[3] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[0] += 1;
                                                        }
                                                    }

                                                    else {
                                                        if (x[1] <= 55.45000076293945) {
                                                            votes[0] += 1;
                                                        }

                                                        else {
                                                            votes[3] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 60.20000076293945) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[3] += 1;
                                                }
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[2] <= 153.5) {
                                        if (x[0] <= 39.39999961853027) {
                                            if (x[1] <= 53.70000076293945) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1] <= 55.15000057220459) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 60.89999771118164) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[2] <= 217.5) {
                                    if (x[1] <= 54.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[3] += 1;
                                    }
                                }

                                else {
                                    if (x[1] <= 58.60000228881836) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[3] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1] <= 61.14999961853027) {
                                if (x[2] <= 590.5) {
                                    if (x[2] <= 555.5) {
                                        if (x[2] <= 529.5) {
                                            if (x[2] <= 485.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[2] <= 489.0) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[0] <= 35.29999923706055) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 45.70000076293945) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[2] <= 586.5) {
                                                if (x[1] <= 59.64999961853027) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 36.05000019073486) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[2] <= 626.5) {
                                        if (x[0] <= 36.54999923706055) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[0] <= 41.45000076293945) {
                                                if (x[0] <= 40.29999923706055) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[2] <= 680.0) {
                                            if (x[2] <= 676.5) {
                                                if (x[2] <= 662.0) {
                                                    if (x[1] <= 53.29999923706055) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[1] <= 76.25) {
                                    if (x[0] <= 36.10000038146973) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[0] <= 38.45000076293945) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #3
                        if (x[1] <= 72.25) {
                            if (x[1] <= 36.14999961853027) {
                                if (x[1] <= 33.25) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[0] <= 30.15000057220459) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        if (x[2] <= 328.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[2] <= 618.5) {
                                    if (x[2] <= 230.0) {
                                        if (x[1] <= 57.25) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }

                                    else {
                                        if (x[0] <= 35.35000038146973) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[1] <= 52.89999961853027) {
                                        if (x[2] <= 626.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }

                                    else {
                                        if (x[0] <= 41.89999961853027) {
                                            if (x[1] <= 53.35000038146973) {
                                                if (x[0] <= 33.45000076293945) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1] <= 74.45000076293945) {
                                if (x[1] <= 72.45000076293945) {
                                    votes[3] += 1;
                                }

                                else {
                                    if (x[2] <= 281.5) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 46.75) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #4
                        if (x[2] <= 264.5) {
                            if (x[1] <= 55.35000038146973) {
                                if (x[0] <= 48.19999885559082) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[0] <= 48.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                votes[3] += 1;
                            }
                        }

                        else {
                            if (x[1] <= 52.35000038146973) {
                                if (x[0] <= 40.89999961853027) {
                                    if (x[1] <= 46.35000038146973) {
                                        if (x[2] <= 588.0) {
                                            if (x[0] <= 33.15000057220459) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }

                                    else {
                                        if (x[1] <= 51.45000076293945) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[2] <= 612.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[2] <= 642.5) {
                                    if (x[0] <= 35.55000114440918) {
                                        if (x[1] <= 68.8499984741211) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }

                                    else {
                                        if (x[2] <= 620.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[1] <= 59.30000114440918) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[1] <= 65.19999885559082) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 40.89999961853027) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #5
                        if (x[2] <= 264.5) {
                            if (x[1] <= 57.25) {
                                votes[0] += 1;
                            }

                            else {
                                votes[3] += 1;
                            }
                        }

                        else {
                            if (x[0] <= 38.25) {
                                if (x[0] <= 35.35000038146973) {
                                    if (x[0] <= 33.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        if (x[0] <= 33.14999961853027) {
                                            if (x[2] <= 479.0) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[2] <= 590.0) {
                                        if (x[2] <= 334.0) {
                                            votes[3] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 41.10000038146973) {
                                    if (x[2] <= 607.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #6
                        if (x[1] <= 69.20000076293945) {
                            if (x[1] <= 35.69999885559082) {
                                if (x[1] <= 34.25) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[1] <= 34.44999885559082) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[1] <= 53.14999961853027) {
                                    if (x[2] <= 602.5) {
                                        if (x[1] <= 40.10000038146973) {
                                            if (x[0] <= 35.85000038146973) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[2] <= 353.5) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 52.60000038146973) {
                                                if (x[0] <= 35.94999885559082) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 49.54999923706055) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[2] <= 230.5) {
                                                            votes[0] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 52.85000038146973) {
                                                    if (x[0] <= 32.80000019073486) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[2] <= 605.5) {
                                            if (x[0] <= 40.04999923706055) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[0] <= 44.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 37.70000076293945) {
                                        if (x[0] <= 34.80000114440918) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[1] <= 53.35000038146973) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[1] <= 62.64999961853027) {
                                                    if (x[1] <= 57.85000038146973) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        if (x[2] <= 643.0) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[3] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[2] <= 620.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[2] <= 629.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1] <= 73.79999923706055) {
                                if (x[1] <= 69.70000076293945) {
                                    votes[3] += 1;
                                }

                                else {
                                    if (x[0] <= 41.0) {
                                        if (x[0] <= 31.449999809265137) {
                                            if (x[2] <= 479.0) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[1] <= 74.45000076293945) {
                                    if (x[1] <= 74.35000228881836) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        if (x[2] <= 334.0) {
                                            votes[3] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[2] <= 342.5) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #7
                        if (x[1] <= 72.25) {
                            if (x[2] <= 212.5) {
                                if (x[2] <= 22.5) {
                                    if (x[1] <= 53.25) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[3] += 1;
                                    }
                                }

                                else {
                                    if (x[2] <= 180.5) {
                                        if (x[1] <= 59.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }

                                    else {
                                        if (x[1] <= 50.499999046325684) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[2] <= 626.5) {
                                    if (x[0] <= 35.35000038146973) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        if (x[0] <= 37.35000038146973) {
                                            if (x[0] <= 36.30000114440918) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[0] <= 41.04999923706055) {
                                                if (x[1] <= 59.80000114440918) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 40.64999961853027) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[2] <= 691.0) {
                                        if (x[0] <= 40.79999923706055) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[0] <= 45.35000038146973) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[0] <= 42.80000114440918) {
                                if (x[1] <= 74.20000076293945) {
                                    if (x[1] <= 73.95000076293945) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    if (x[2] <= 333.5) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[2] <= 269.0) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #8
                        if (x[0] <= 37.64999961853027) {
                            if (x[1] <= 66.8499984741211) {
                                if (x[2] <= 442.5) {
                                    if (x[1] <= 38.29999923706055) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    if (x[0] <= 35.60000038146973) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        if (x[2] <= 670.0) {
                                            if (x[2] <= 636.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[1] <= 74.1500015258789) {
                                    if (x[2] <= 540.0) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }
                        }

                        else {
                            if (x[1] <= 36.14999961853027) {
                                if (x[0] <= 44.14999961853027) {
                                    if (x[1] <= 34.25) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[0] <= 43.599998474121094) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                if (x[2] <= 236.5) {
                                    if (x[0] <= 44.54999923706055) {
                                        if (x[2] <= 85.0) {
                                            if (x[1] <= 64.25000190734863) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    if (x[0] <= 41.04999923706055) {
                                        if (x[1] <= 41.39999961853027) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[2] <= 612.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #9
                        if (x[2] <= 264.5) {
                            if (x[1] <= 57.75) {
                                if (x[0] <= 48.25) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[0] <= 48.44999885559082) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                votes[3] += 1;
                            }
                        }

                        else {
                            if (x[1] <= 52.25) {
                                if (x[1] <= 50.95000076293945) {
                                    if (x[1] <= 48.75) {
                                        if (x[0] <= 35.60000038146973) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[1] <= 37.64999961853027) {
                                                if (x[0] <= 45.0) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                if (x[0] <= 41.10000038146973) {
                                                    if (x[0] <= 39.75) {
                                                        if (x[1] <= 45.85000038146973) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 46.14999961853027) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[2] <= 642.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 37.79999923706055) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 38.04999923706055) {
                                    if (x[2] <= 512.5) {
                                        if (x[1] <= 68.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }

                                    else {
                                        if (x[0] <= 35.60000038146973) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[1] <= 53.85000038146973) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #10
                        if (x[0] <= 38.14999961853027) {
                            if (x[1] <= 66.8499984741211) {
                                if (x[0] <= 33.75) {
                                    if (x[0] <= 32.14999961853027) {
                                        if (x[2] <= 321.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }

                                    else {
                                        if (x[0] <= 33.45000076293945) {
                                            if (x[0] <= 33.35000038146973) {
                                                if (x[0] <= 32.35000038146973) {
                                                    if (x[1] <= 45.44999885559082) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 33.84999942779541) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[1] <= 38.29999923706055) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[0] <= 35.10000038146973) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[2] <= 650.5) {
                                                if (x[1] <= 51.85000038146973) {
                                                    if (x[2] <= 219.0) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 36.35000038146973) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[2] <= 582.5) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }
                        }

                        else {
                            if (x[1] <= 41.80000114440918) {
                                if (x[0] <= 44.04999923706055) {
                                    if (x[0] <= 40.10000038146973) {
                                        if (x[1] <= 36.39999961853027) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[1] <= 37.29999923706055) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    if (x[0] <= 44.25) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        if (x[2] <= 401.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 41.75) {
                                    if (x[2] <= 254.5) {
                                        if (x[1] <= 61.30000114440918) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }

                                    else {
                                        if (x[1] <= 48.04999923706055) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[1] <= 60.5) {
                                                if (x[1] <= 60.14999961853027) {
                                                    if (x[0] <= 40.55000114440918) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[1] <= 54.85000038146973) {
                                                            if (x[2] <= 634.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[2] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[2] <= 251.0) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #11
                        if (x[0] <= 37.64999961853027) {
                            if (x[2] <= 412.5) {
                                if (x[0] <= 34.0) {
                                    if (x[2] <= 109.5) {
                                        if (x[2] <= 108.5) {
                                            if (x[1] <= 50.04999828338623) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        if (x[1] <= 43.44999980926514) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[2] <= 95.5) {
                                        if (x[0] <= 36.75) {
                                            if (x[0] <= 35.54999923706055) {
                                                if (x[2] <= 76.0) {
                                                    if (x[0] <= 35.04999923706055) {
                                                        votes[3] += 1;
                                                    }

                                                    else {
                                                        votes[0] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[2] <= 81.0) {
                                                        votes[3] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 34.5) {
                                                            votes[0] += 1;
                                                        }

                                                        else {
                                                            if (x[1] <= 51.849998474121094) {
                                                                votes[0] += 1;
                                                            }

                                                            else {
                                                                votes[3] += 1;
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }

                                    else {
                                        if (x[0] <= 35.95000076293945) {
                                            votes[3] += 1;
                                        }

                                        else {
                                            if (x[0] <= 36.64999961853027) {
                                                if (x[0] <= 36.45000076293945) {
                                                    if (x[2] <= 144.5) {
                                                        votes[3] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 36.14999961853027) {
                                                            if (x[2] <= 178.5) {
                                                                votes[0] += 1;
                                                            }

                                                            else {
                                                                votes[3] += 1;
                                                            }
                                                        }

                                                        else {
                                                            if (x[1] <= 57.54999828338623) {
                                                                votes[0] += 1;
                                                            }

                                                            else {
                                                                votes[3] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }

                                            else {
                                                if (x[0] <= 36.95000076293945) {
                                                    votes[3] += 1;
                                                }

                                                else {
                                                    if (x[1] <= 52.70000171661377) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        votes[3] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[1] <= 53.14999961853027) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[0] <= 34.95000076293945) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        if (x[0] <= 35.89999961853027) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[0] <= 41.04999923706055) {
                                if (x[0] <= 38.25) {
                                    if (x[0] <= 38.0) {
                                        if (x[0] <= 37.80000114440918) {
                                            if (x[1] <= 49.15000057220459) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[2] <= 108.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[0] <= 38.14999961853027) {
                                            if (x[1] <= 38.04999923706055) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 38.64999961853027) {
                                        if (x[1] <= 69.74999809265137) {
                                            if (x[2] <= 263.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[1] <= 50.64999961853027) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }

                                    else {
                                        if (x[0] <= 39.35000038146973) {
                                            if (x[1] <= 41.89999961853027) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                if (x[2] <= 273.0) {
                                                    if (x[1] <= 64.25000190734863) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        votes[3] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 70.20000076293945) {
                                                if (x[2] <= 259.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    if (x[1] <= 48.54999923706055) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 40.70000076293945) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }
                                                }
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 46.04999923706055) {
                                    if (x[1] <= 36.89999961853027) {
                                        if (x[2] <= 352.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[0] <= 43.39999961853027) {
                                            if (x[1] <= 73.95000076293945) {
                                                if (x[2] <= 231.0) {
                                                    votes[0] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[0] <= 44.30000114440918) {
                                                if (x[2] <= 142.5) {
                                                    votes[3] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 47.25) {
                                        if (x[1] <= 32.35000038146973) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[0] <= 47.35000038146973) {
                                            if (x[1] <= 40.45000076293945) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[2] <= 230.5) {
                                                if (x[0] <= 49.19999885559082) {
                                                    if (x[1] <= 58.10000038146973) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        votes[3] += 1;
                                                    }
                                                }

                                                else {
                                                    votes[0] += 1;
                                                }
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #12
                        if (x[2] <= 264.5) {
                            if (x[1] <= 57.25) {
                                if (x[0] <= 48.19999885559082) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[1] <= 42.150001525878906) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                votes[3] += 1;
                            }
                        }

                        else {
                            if (x[2] <= 616.0) {
                                if (x[2] <= 575.5) {
                                    if (x[2] <= 317.5) {
                                        if (x[2] <= 311.5) {
                                            if (x[0] <= 37.25) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }

                                    else {
                                        if (x[2] <= 486.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[1] <= 43.0) {
                                                if (x[2] <= 495.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[2] <= 510.5) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[2] <= 529.5) {
                                                    if (x[0] <= 33.95000076293945) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }

                                                else {
                                                    if (x[1] <= 58.85000038146973) {
                                                        if (x[1] <= 57.94999885559082) {
                                                            if (x[2] <= 549.5) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[2] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[2] <= 581.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        if (x[0] <= 36.14999961853027) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[1] <= 52.89999961853027) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[1] <= 55.14999961853027) {
                                        if (x[1] <= 54.89999961853027) {
                                            if (x[2] <= 696.5) {
                                                if (x[2] <= 666.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[1] <= 54.150001525878906) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        votes[2] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[2] <= 683.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1] <= 68.19999694824219) {
                                            if (x[2] <= 638.5) {
                                                if (x[0] <= 42.04999923706055) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    votes[1] += 1;
                                                }
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[2] <= 747.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // tree #13
                        if (x[2] <= 262.0) {
                            if (x[0] <= 38.35000038146973) {
                                if (x[0] <= 34.89999961853027) {
                                    if (x[1] <= 48.64999961853027) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[3] += 1;
                                    }
                                }

                                else {
                                    if (x[1] <= 57.25) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[3] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[1] <= 59.400001525878906) {
                                    if (x[1] <= 42.150001525878906) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[2] <= 208.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }
                        }

                        else {
                            if (x[0] <= 37.64999961853027) {
                                if (x[2] <= 444.5) {
                                    if (x[0] <= 35.55000114440918) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }

                            else {
                                if (x[2] <= 685.5) {
                                    if (x[1] <= 38.0) {
                                        if (x[1] <= 36.64999961853027) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }

                                    else {
                                        if (x[1] <= 52.14999961853027) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            if (x[2] <= 620.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                if (x[2] <= 628.5) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    if (x[2] <= 664.5) {
                                                        votes[1] += 1;
                                                    }

                                                    else {
                                                        if (x[0] <= 41.19999885559082) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1] <= 51.60000038146973) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #14
                        if (x[2] <= 264.5) {
                            if (x[0] <= 38.64999961853027) {
                                if (x[1] <= 56.45000076293945) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }

                            else {
                                if (x[0] <= 43.0) {
                                    if (x[1] <= 61.30000114440918) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[3] += 1;
                                    }
                                }

                                else {
                                    if (x[2] <= 194.0) {
                                        if (x[0] <= 44.25) {
                                            if (x[1] <= 57.34999942779541) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        if (x[2] <= 203.0) {
                                            votes[3] += 1;
                                        }

                                        else {
                                            if (x[0] <= 47.54999923706055) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[0] <= 37.35000038146973) {
                                if (x[0] <= 35.60000038146973) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[2] <= 656.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 41.04999923706055) {
                                    if (x[0] <= 40.64999961853027) {
                                        if (x[0] <= 38.79999923706055) {
                                            if (x[2] <= 612.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #15
                        if (x[1] <= 74.1500015258789) {
                            if (x[1] <= 36.10000038146973) {
                                if (x[0] <= 27.449999809265137) {
                                    if (x[1] <= 30.649999618530273) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    if (x[1] <= 34.25) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[2] <= 341.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[2] <= 662.0) {
                                    if (x[1] <= 63.89999961853027) {
                                        if (x[1] <= 54.04999923706055) {
                                            if (x[0] <= 34.39999961853027) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                if (x[0] <= 39.35000038146973) {
                                                    if (x[2] <= 321.5) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        if (x[1] <= 46.5) {
                                                            votes[1] += 1;
                                                        }

                                                        else {
                                                            if (x[2] <= 616.0) {
                                                                votes[1] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }
                                                    }
                                                }

                                                else {
                                                    if (x[2] <= 204.5) {
                                                        votes[0] += 1;
                                                    }

                                                    else {
                                                        if (x[1] <= 37.64999961853027) {
                                                            if (x[0] <= 45.0) {
                                                                votes[2] += 1;
                                                            }

                                                            else {
                                                                votes[1] += 1;
                                                            }
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {
                                            if (x[1] <= 59.14999961853027) {
                                                if (x[2] <= 587.5) {
                                                    votes[1] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 37.05000114440918) {
                                                        votes[2] += 1;
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }

                                            else {
                                                if (x[1] <= 59.64999961853027) {
                                                    votes[2] += 1;
                                                }

                                                else {
                                                    if (x[0] <= 41.10000038146973) {
                                                        if (x[1] <= 60.85000038146973) {
                                                            votes[2] += 1;
                                                        }

                                                        else {
                                                            votes[1] += 1;
                                                        }
                                                    }

                                                    else {
                                                        votes[1] += 1;
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        if (x[2] <= 265.0) {
                                            votes[3] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[2] <= 691.0) {
                                        if (x[2] <= 689.0) {
                                            if (x[0] <= 41.19999885559082) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1] <= 74.45000076293945) {
                                if (x[2] <= 372.0) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[2] <= 313.5) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 4; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }

                        return classIdx;
                    }

                protected:
                };
            }
        }
    }
namespace Eloquent {
    namespace Projects {
        /**
         * CompostClassifier wraps the generated RandomForest model and provides
         * a predictLabel() method that maps class indices to human-readable labels.
         * Labels correspond to compost states: Dry, Normal, Ready, Wet.
         * Input features order: [Temperature, Humidity, Methane]
         */
        class CompostClassifier : public Eloquent::ML::Port::RandomForest {
            public:
                /**
                 * Predict readable label for features vector
                 */
                const char* predictLabel(float *x) {
                    switch (predict(x)) {
                        case 0: return "Dry";
                        case 1: return "Normal";
                        case 2: return "Ready";
                        case 3: return "Wet";
                        default: return "Unknown";
                    }
                }
        };
    }
}
