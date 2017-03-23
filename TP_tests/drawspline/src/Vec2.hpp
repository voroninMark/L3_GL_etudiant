#ifndef VEC2_HPP_
#define VEC2_HPP_

struct Vec2 {
    double x_;
    double y_;
};

Vec2 operator-(const Vec2 & v1, const Vec2 & v2);
Vec2 operator+(const Vec2 & v1, const Vec2 & v2);
Vec2 operator*(double k, const Vec2 & v);

#endif

