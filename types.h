#pragma once
#include <cmath>      // std::sqrt
#include <ostream>    // std::ostream
#include <algorithm>  // std::clamp (C++17)

/*
____   ____             __
\   \ /   /____   _____/  |_  ___________  ______
 \   Y   // __ \_/ ___\   __\/  _ \_  __ \/  ___/
  \     /\  ___/\  \___|  | (  <_> )  | \/\___ \
   \___/  \___  >\___  >__|  \____/|__|  /____  >
			  \/     \/                       \/
*/


struct vector2
{
    float x{}, y{};

    constexpr vector2() = default;
    constexpr vector2(float source_x, float source_y) : x(source_x), y(source_y) {}

    // ----- compound assignment -----
    vector2& operator+=(const vector2& source) { x += source.x; y += source.y; return *this; }
    vector2& operator-=(const vector2& source) { x -= source.x; y -= source.y; return *this; }
    vector2& operator*=(const vector2& source) { x *= source.x; y *= source.y; return *this; } // element-wise
    vector2& operator/=(const vector2& source) { x /= source.x; y /= source.y; return *this; } // element-wise

    vector2& operator*=(float s) { x *= s; y *= s; return *this; }
    vector2& operator/=(float s) { x /= s; y /= s; return *this; }

    // ----- unary -----
    constexpr vector2 operator-() const { return { -x, -y }; }

    // ----- non-compound -----
    friend vector2 operator+(vector2 left, const vector2& source) { return left += source; }
    friend vector2 operator-(vector2 left, const vector2& source) { return left -= source; }
    friend vector2 operator*(vector2 left, const vector2& source) { return left *= source; } // element-wise
    friend vector2 operator/(vector2 left, const vector2& source) { return left /= source; } // element-wise

    friend vector2 operator*(vector2 v, float s) { return v *= s; }
    friend vector2 operator*(float s, vector2 v) { return v *= s; } // symmetry
    friend vector2 operator/(vector2 v, float s) { return v /= s; }

    // ----- comparisons -----
    bool operator==(const vector2& source) const
    {
        return x == source.x && y == source.y;
    }

    bool operator!=(const vector2& source) const
    {
        return !(*this == source);
    }

    // ----- vector math -----
    float dot(const vector2& source) const
    {
        return x * source.x + y * source.y;
    }

    // in 2D, cross product can be represented as a scalar (signed area)
    float cross(const vector2& source) const
    {
        return x * source.y - y * source.x;
    }

    float length_squared() const
    {
        return this->dot(*this);
    }

    float length() const
    {
        return std::sqrt(length_squared());
    }

    vector2 normalized() const
    {
        float len = length();
        if (len > 0.0f) 
		{
            return *this / len;
        }
        return { 0.0f, 0.0f };
    }

    void normalize()
    {
        float len = length();
        if (len > 0.0f) 
		{
            *this /= len;
        }
    }

    // ----- i/o -----
    friend std::ostream& operator<<(std::ostream& os, const vector2& v)
    {
        return os << "(" << v.x << ", " << v.y << ")";
    }

    // ----- utilities -----
    float distance(const vector2& other) const
    {
        return (other - *this).length();
    }

    static vector2 lerp(const vector2& a, const vector2& b, float t)
    {
        return a + (b - a) * t;
    }

    static vector2 clamp(const vector2& v, const vector2& min, const vector2& max)
    {
        return 
		{
            std::clamp(v.x, min.x, max.x),
            std::clamp(v.y, min.y, max.y)
        };
    }
};

struct vector3 
{
    float x{}, y{}, z{};

    constexpr vector3() = default;
    constexpr vector3(float source_x, float source_y, float source_z) : x(source_x), y(source_y), z(source_z) {}

    // ----- compound assignment -----
    vector3& operator+=(const vector3& source) { x += source.x; y += source.y; z += source.z; return *this; }
    vector3& operator-=(const vector3& source) { x -= source.x; y -= source.y; z -= source.z; return *this; }
    vector3& operator*=(const vector3& source) { x *= source.x; y *= source.y; z *= source.z; return *this; } // element-wise
    vector3& operator/=(const vector3& source) { x /= source.x; y /= source.y; z /= source.z; return *this; } // element-wise

    vector3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    vector3& operator/=(float s) { x /= s; y /= s; z /= s; return *this; }

    // ----- unary -----
    constexpr vector3 operator-() const { return { -x, -y, -z }; }

    // ----- non-compound -----
    friend vector3 operator+(vector3 left, const vector3& source) { return left += source; }
    friend vector3 operator-(vector3 left, const vector3& source) { return left -= source; }
    friend vector3 operator*(vector3 left, const vector3& source) { return left *= source; } // element-wise
    friend vector3 operator/(vector3 left, const vector3& source) { return left /= source; } // element-wise

    friend vector3 operator*(vector3 v, float s) { return v *= s; }
    friend vector3 operator*(float s, vector3 v) { return v *= s; } // symmetry
    friend vector3 operator/(vector3 v, float s) { return v /= s; }

    // ----- comparisons -----
    bool operator==(const vector3& source) const 
    {
        return x == source.x && y == source.y && z == source.z;
    }

    bool operator!=(const vector3& source) const
    {
        return !(*this == source);
    }

    // ----- vector math -----
    float dot(const vector3& source) const 
    {
        return x * source.x + y * source.y + z * source.z;
    }

    vector3 cross(const vector3& source) const 
    {
        return {
            y * source.z - z * source.y,
            z * source.x - x * source.z,
            x * source.y - y * source.x
        };
    }

    float length_squared() const 
    {
        return this->dot(*this);
    }

    float length() const 
    {
        return std::sqrt(length_squared());
    }

    vector3 normalized() const 
    {
        float len = length();
        if (len > 0.0f) {
            return *this / len;
        }
        return { 0.0f, 0.0f, 0.0f };
    }

    void normalize() 
    {
        float len = length();
        if (len > 0.0f) 
		{
            *this /= len;
        }
    }

    // ----- i/o -----
    friend std::ostream& operator<<(std::ostream& os, const vector3& v) 
    {
        return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    }

    // ----- utilities -----
    float distance(const vector3& other) const
    {
        return (other - *this).length();
    }

    static vector3 lerp(const vector3& a, const vector3& b, float t) 
    {
        return a + (b - a) * t;
    }

    static vector3 clamp(const vector3& v, const vector3& min, const vector3& max) 
    {
        return 
		{
            std::clamp(v.x, min.x, max.x),
            std::clamp(v.y, min.y, max.y),
            std::clamp(v.z, min.z, max.z)
        };
    }
};

struct vector4
{
    float x{}, y{}, z{}, w{};

    constexpr vector4() = default;
    constexpr vector4(float source_x, float source_y, float source_z, float source_w)
        : x(source_x), y(source_y), z(source_z), w(source_w) {
    }

    // ----- compound assignment -----
    vector4& operator+=(const vector4& source) { x += source.x; y += source.y; z += source.z; w += source.w; return *this; }
    vector4& operator-=(const vector4& source) { x -= source.x; y -= source.y; z -= source.z; w -= source.w; return *this; }
    vector4& operator*=(const vector4& source) { x *= source.x; y *= source.y; z *= source.z; w *= source.w; return *this; } // element-wise
    vector4& operator/=(const vector4& source) { x /= source.x; y /= source.y; z /= source.z; w /= source.w; return *this; } // element-wise

    vector4& operator*=(float s) { x *= s; y *= s; z *= s; w *= s; return *this; }
    vector4& operator/=(float s) { x /= s; y /= s; z /= s; w /= s; return *this; }

    // ----- unary -----
    constexpr vector4 operator-() const { return { -x, -y, -z, -w }; }

    // ----- non-compound -----
    friend vector4 operator+(vector4 left, const vector4& source) { return left += source; }
    friend vector4 operator-(vector4 left, const vector4& source) { return left -= source; }
    friend vector4 operator*(vector4 left, const vector4& source) { return left *= source; } // element-wise
    friend vector4 operator/(vector4 left, const vector4& source) { return left /= source; } // element-wise

    friend vector4 operator*(vector4 v, float s) { return v *= s; }
    friend vector4 operator*(float s, vector4 v) { return v *= s; } // symmetry
    friend vector4 operator/(vector4 v, float s) { return v /= s; }

    // ----- comparisons -----
    bool operator==(const vector4& source) const
    {
        return x == source.x && y == source.y && z == source.z && w == source.w;
    }

    bool operator!=(const vector4& source) const
    {
        return !(*this == source);
    }

    // ----- vector math -----
    float dot(const vector4& source) const
    {
        return x * source.x + y * source.y + z * source.z + w * source.w;
    }

    float length_squared() const
    {
        return this->dot(*this);
    }

    float length() const
    {
        return std::sqrt(length_squared());
    }

    vector4 normalized() const
    {
        float len = length();
        if (len > 0.0f) 
		{
            return *this / len;
        }
        return { 0.0f, 0.0f, 0.0f, 0.0f };
    }

    void normalize()
    {
        float len = length();
        if (len > 0.0f)
		{
            *this /= len;
        }
    }

    // ----- i/o -----
    friend std::ostream& operator<<(std::ostream& os, const vector4& v)
    {
        return os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
    }

    // ----- utilities -----
    float distance(const vector4& other) const
    {
        return (other - *this).length();
    }

    static vector4 lerp(const vector4& a, const vector4& b, float t)
    {
        return a + (b - a) * t;
    }

    static vector4 clamp(const vector4& v, const vector4& min, const vector4& max)
    {
        return {
            std::clamp(v.x, min.x, max.x),
            std::clamp(v.y, min.y, max.y),
            std::clamp(v.z, min.z, max.z),
            std::clamp(v.w, min.w, max.w)
        };
    }
};

/*
   _____          __         .__
  /     \ _____ _/  |________|__|__  ___
 /  \ /  \\__  \\   __\_  __ \  \  \/  /
/    Y    \/ __ \|  |  |  | \/  |>    <
\____|__  (____  /__|  |__|  |__/__/\_ \
        \/     \/                     \/
*/

// We do this in a struct so it is more convienient to read it in memory
struct matrix
{
    float mvp_matrix[16];
};



