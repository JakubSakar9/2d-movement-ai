#pragma once

#include <cmath>

class Vector2 {
    public:
        inline Vector2(float x, float y) : x(x), y(y) {}
        float x;
        float y;
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
