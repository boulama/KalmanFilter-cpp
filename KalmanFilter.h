#ifndef KALMAN_FILTER_H_
#define KALMAN_FILTER_H_

class KalmanFilter {
public:
    KalmanFilter(double process_variance, double measurement_variance);
    double update(double measurement);

private:
    double process_variance_;
    double measurement_variance_;
    double posteri_estimate_;
    double posteri_error_estimate_;
};

#endif // KALMAN_FILTER_H_
