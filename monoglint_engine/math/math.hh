#pragma once

/*

DEPENDENCIES
core

*/

#include "core/core.hh"

namespace math {
    template <typename T>
    struct vec2 {
        vec2(const T x, const T y)
            : x(x), y(y) {}

        vec2(const vec2& other) {
            x = other.x;
            y = other.y;
        }

        T x, y;
    };

    template <typename T>
    struct vec3 {
        vec3(const T x, const T y, const T z)
            : x(x), y(y), z(z) {}

        vec3(const vec3& other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }

        T x, y, z;
    };
}