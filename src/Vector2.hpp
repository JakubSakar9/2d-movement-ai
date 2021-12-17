#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdlib>

class Vector2 {
    public:
        Vector2() : Vector2(0., 0.) {}
        inline Vector2(float _x, float _y) : x{_x}, y{_y} {}
        double x;
        double y;
        inline float Norm() {
            return sqrt(x * x + y * y);
        }
};

inline Vector2 operator+(Vector2 &u, const Vector2& v) {
    return Vector2(u.x + v.x, u.y + v.y);
}

inline Vector2 operator*(Vector2 &v, const float &a){
    return Vector2(a * v.x, a * v.y);
}

inline Vector2 RandVector(float amplitude) {
    float param = (std::rand() / (RAND_MAX + 1.)) * M_PI * 2;
    Vector2 tmp = Vector2(cos(param), sin(param));
    return tmp * amplitude;
}
