#include <iostream>

int main() {
    KalmanFilter kalman_filter(0.01, 0.1); // init w process variance & measurement variance

    // Example measurements
    double measurements[] = {1.1, 1.2, 1.3, 1.4, 1.5};

    // Apply Kalman filter to each measurement
    for (double measurement : measurements) {
        double filtered_measurement = kalman_filter.update(measurement);
        std::cout << "Measurement: " << measurement << ", Filtered Measurement: " << filtered_measurement << std::endl;
    }

    return 0;
}
