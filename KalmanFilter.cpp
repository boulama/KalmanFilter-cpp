#include "KalmanFilter.h"

KalmanFilter::KalmanFilter(double process_variance, double measurement_variance) :
    process_variance_(process_variance),
    measurement_variance_(measurement_variance),
    posteri_estimate_(0.0),
    posteri_error_estimate_(1.0) {}

/*
* implemented from:
https://www.cs.unc.edu/~welch/media/pdf/kalman_intro.pdf
*/
double KalmanFilter::update(double measurement) {
    double priori_estimate = posteri_estimate_;
    double priori_error_estimate = posteri_error_estimate_ + process_variance_;

    double blending_factor = priori_error_estimate / (priori_error_estimate + measurement_variance_);
    posteri_estimate_ = priori_estimate + blending_factor * (measurement - priori_estimate);
    posteri_error_estimate_ = (1 - blending_factor) * priori_error_estimate;

    return posteri_estimate_;
}
