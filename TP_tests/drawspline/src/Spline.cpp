#include "Spline.hpp"
#include <cassert>
#include <cmath>
#include <string>

void Spline::addKey(double t, const Vec2 & P) {
    // keys should be added in ascending times
    assert(times_.empty() or t >= times_.back());

    times_.push_back(t);
    values_.push_back(P);
}

Vec2 Spline::getValue(double t) const {
    // invalid time
    assert(t >= getStartTime());
    assert(t < getEndTime());

    // find piece corresponding to t
    int i=2;
    while (times_[i] <= t) i++;

    // compute points and tangents
    const double G = (1+sqrt(5))/2;
    Vec2 P1 = values_[i-1];
    Vec2 P4 = values_[i];
    Vec2 R1 = G/(times_[i]-times_[i-2])*(values_[i]-values_[i-2]);
    Vec2 R4 = G/(times_[i+1]-times_[i-1])*(values_[i+1]-values_[i-1]);

    // compute hermite interpolation
    double tu = (t-times_[i-1]) / (times_[i]-times_[i-1]);
    double tu2 = tu*tu;
    double tu3 = tu2*tu;
    return (2*tu3 - 3*tu2 + 1) * P1
        + (-2*tu3 + 3*tu2) * P4
        + (tu3 - 2*tu2 + tu) * R1
        + (tu3 - tu2) * R4;
}

double Spline::getStartTime() const {
    // not enough keys
    assert(times_.size() > 3);

    return times_[1];
}

double Spline::getEndTime() const {
    // not enough keys
    assert(times_.size() > 3);

    return times_[times_.size()-2];
}

