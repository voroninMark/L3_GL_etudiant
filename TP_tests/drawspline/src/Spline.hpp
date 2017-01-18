#ifndef SPLINE_HPP_
#define SPLINE_HPP_

#include "Vec2.hpp"
#include <vector>

// Spline cubique 2D
class Spline {

    private:
        std::vector<double> times_;
        std::vector<Vec2> values_;

    public:
        void addKey(double t, const Vec2 & P);
        Vec2 getValue(double t) const;
        double getStartTime() const;
        double getEndTime() const;
};

#endif
