#include "Vec2.hpp"

Vec2 operator+(const Vec2 & v1, const Vec2 & v2) {
    return Vec2{v1.x_ + v2.x_, v1.y_ + v2.y_};
}

Vec2 operator*(double k, const Vec2 & v) {
    return Vec2{k*v.x_, k*v.y_};
}

Vec2 operator-(const Vec2 & v1, const Vec2 & v2) {
    return Vec2{v1.x_ + v2.x_, v1.y_ + v2.y_};
}

