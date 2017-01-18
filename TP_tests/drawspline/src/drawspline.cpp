#include "Spline.hpp"
#include <iostream>

using namespace std;

int main() {

    // begin

    // create spline
    Spline spline;

    // add keys
    double t;
    Vec2 P;
    while (cin >> t and cin >> P.x_ and cin >> P.y_) {
        spline.addKey(t, P);
    }

    // compute values
    double deltaT = (spline.getEndTime() - spline.getStartTime()) / 100.0;
    for (double t=spline.getStartTime(); t<spline.getEndTime(); t+=deltaT) {
        Vec2 Pt = spline.getValue(t);
        cout << t << " " << Pt.x_ << " " << Pt.y_ << "\n";
    }

    // end

    return 0;
}

