#pragma once

#include<iostream>
#include<cmath>

template<typename T>
struct Vec3 {
    union {
        struct {T x, y, z;};
        struct {T u, v, w;};
        T raw[3];
    };
    Vec3();
    Vec3(T x, T y, T z);
    Vec3<T> operator+(const Vec3<T> v) const;
    Vec3<T> operator-(const Vec3<T> v) const;
    T operator*(const Vec3<T> v) const;
    Vec3<T> operator*(const T v) const;
    // cross
    Vec3<T> operator^(const Vec3<T> v) const;
    T norm() const;
    void normalize();
    T& operator[](const size_t idx) const;
};

template<typename T>
std::ostream& operator<<(std::ostream& s, const Vec3<T>& v);

typedef Vec3<int> Vec3i;
typedef Vec3<float> Vec3f;
typedef Vec3<unsigned char> Vec3uc;

// implementation

template<typename T>
Vec3<T>::Vec3() : x(0), y(0), z(0) {}

template<typename T>
Vec3<T>::Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

template<typename T>
Vec3<T> Vec3<T>::operator+(const Vec3<T> v) const {
    return Vec3<T>(x + v.x, y + v.y, z + v.z);
}

template<typename T>
Vec3<T> Vec3<T>::operator-(const Vec3<T> v) const {
    return Vec3<T>(x - v.x, y - v.y, z - v.z);
}

template<typename T>
T Vec3<T>::operator*(const Vec3<T> v) const {
    return x * v.x + y * v.y + z * v.z;
}

template<typename T>
Vec3<T> Vec3<T>::operator*(const T f) const {
    return Vec3<T>(f * x, f * y, f * z);
}

template<typename T>
Vec3<T> Vec3<T>::operator^(const Vec3<T> v) const {
    return Vec3<T>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

template<typename T>
T Vec3<T>::norm() const {
    return std::sqrt(x * x + y * y + z * z);
}

template<typename T>
void Vec3<T>::normalize() {
    *this *= (1.0 / norm());
}

template<typename T>
T& Vec3<T>::operator[](const size_t idx) const {
    return raw[idx];
}

template<typename T>
std::ostream& operator<<(std::ostream& s, const Vec3<T>& v) {
    return s << '(' << v.x << ',' << v.y << ',' << v.z << ')';
}
