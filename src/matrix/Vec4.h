#pragma once

#include<iostream>
#include<cmath>

template<typename T>
struct Vec4 {
    union {
        struct {T x, y, z, t;};
        struct {T u, v, w, s;};
        T raw[4];
    };
    Vec4();
    Vec4(T x, T y, T z, T t);
    Vec4<T> operator+(const Vec4<T> v) const;
    Vec4<T> operator-(const Vec4<T> v) const;
    T operator*(const Vec4<T> v) const;
    Vec4<T> operator*(const T v) const;
    T norm() const;
    void normalize();
    T& operator[](const size_t idx) const;
};

template<typename T>
Vec4<T> cross(const Vec4<T> a, const Vec4<T> b, const Vec4<T> c);

template<typename T>
std::ostream& operator<<(std::ostream& s, const Vec4<T>& v);

typedef Vec4<int> Vec4i;
typedef Vec4<float> Vec4f;
typedef Vec4<unsigned char> Vec4uc;

// implementation

template<typename T>
Vec4<T>::Vec4() : x(0), y(0), z(0), t(0) {}

template<typename T>
Vec4<T>::Vec4(T x, T y, T z, T t) : x(x), y(y), z(z), t(t) {}

template<typename T>
Vec4<T> Vec4<T>::operator+(const Vec4<T> v) const {
    return Vec4<T>(x + v.x, y + v.y, z + v.z, t + v.t);
}

template<typename T>
Vec4<T> Vec4<T>::operator-(const Vec4<T> v) const {
    return Vec4<T>(x - v.x, y - v.y, z - v.z, t - v.t);
}

template<typename T>
T Vec4<T>::operator*(const Vec4<T> v) const {
    return x * v.x + y * v.y + z * v.z + t * v.t;
}

template<typename T>
Vec4<T> Vec4<T>::operator*(const T f) const {
    return Vec4<T>(f * x, f * y, f * z, f * t);
}

template<typename T>
T Vec4<T>::norm() const {
    return std::sqrt(x * x + y * y + z * z + t * t);
}

template<typename T>
void Vec4<T>::normalize() {
    *this *= (1.0 / norm());
}

template<typename T>
T& Vec4<T>::operator[](const size_t idx) const {
    return raw[idx];
}

template<typename T>
Vec4<T> cross(const Vec4<T> a, const Vec4<T> b, const Vec4<T> c) {
    return Vec4<T>(
              a.y * b.z * c.w + a.z * b.w * c.y + a.w * b.y * c.z - a.y * b.w * c.z - a.z * b.y * c.w - a.w * b.z * c.y,
            -(a.x * b.z * c.w + a.z * b.w * c.x + a.w * b.x * c.z - a.x * b.w * c.z - a.z * b.x * c.w - a.w * b.z * c.x),
              a.x * b.y * c.w + a.y * b.w * c.x + a.w * b.x * c.y - a.x * b.w * c.y - a.y * b.x * c.w - a.w * b.y * c.x,
            -(a.x * b.y * c.z + a.y * b.z * c.x + a.z * b.x * c.y - a.x * b.z * c.y - a.y * b.x * c.z - a.z * b.y * c.x)
        );
}

template<typename T>
std::ostream& operator<<(std::ostream& s, const Vec4<T>& v) {
    return s << '(' << v.x << ',' << v.y << ',' << v.z << ',' << v.t << ')';
}
