#pragma once

#include<iostream>
#include<cmath>

template<typename T>
struct Vec2 {
    union {
        struct {T x, y;};
        struct {T u, v;};
        T raw[2];
    };
    Vec2();
    Vec2(T x, T y);
    Vec2<T> operator+(const Vec2<T> v) const;
    Vec2<T> operator-(const Vec2<T> v) const;
    T operator*(const Vec2<T> v) const;
    Vec2<T> operator*(const T v) const;
    // cross
    T operator^(const Vec2<T> v) const;
    T norm() const;
    void normalize();
    T& operator[](const size_t idx) const;
};

template<typename T>
std::ostream& operator<<(std::ostream& s, const Vec2<T>& v);

typedef Vec2<int> Vec2i;
typedef Vec2<float> Vec2f;
typedef Vec2<unsigned char> Vec2uc;

// implementation

template<typename T>
Vec2<T>::Vec2() : x(0), y(0) {}

template<typename T>
Vec2<T>::Vec2(T x, T y) : x(x), y(y) {}

template<typename T>
Vec2<T> Vec2<T>::operator+(const Vec2<T> v) const {
    return Vec2<T>(x + v.x, y + v.y);
}

template<typename T>
Vec2<T> Vec2<T>::operator-(const Vec2<T> v) const {
    return Vec2<T>(x - v.x, y - v.y);
}

template<typename T>
T Vec2<T>::operator*(const Vec2<T> v) const {
    return x * v.x + y * v.y;
}

template<typename T>
Vec2<T> Vec2<T>::operator*(const T f) const {
    return Vec2<T>(f * x, f * y);
}

template<typename T>
T Vec2<T>::operator^(const Vec2<T> v) const {
    return x * v.y - y * v.x;
}

template<typename T>
T Vec2<T>::norm() const {
    return std::sqrt(x * x + y * y);
}

template<typename T>
void Vec2<T>::normalize() {
    *this *= (1.0 / norm());
}

template<typename T>
T& Vec2<T>::operator[](const size_t idx) const {
    return raw[idx];
}

template<typename T>
std::ostream& operator<<(std::ostream& s, const Vec2<T>& v) {
    return s << '(' << v.x << ',' << v.y << ')';
}
