#pragma once

#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"

template <typename T>
Vec4<T> toVec4(Vec3<T> v) {
    return Vec4<T>(v.x, v.y, v.z, 1);
}

template <typename T>
Vec3<T> toVec3(Vec4<T> v) {
    return Vec3<T>(v.x / v.t, v.y / v.t, v.z / v.t);
}

