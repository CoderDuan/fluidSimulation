#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
public:
	float x, y, z;

	Vector3(float x, float y, float z)
	: x(x), y(y), z(z) {}

	Vector3 operator + (const Vector3 &v) {
		return Vector3(x+v.x, y+v.y, z+v.z);
	}

	Vector3 &operator += (const Vector3 &v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Vector3 operator - (const Vector3 &v) {
		return Vector3(x-v.x, y-v.y, z-v.z);
	}

	Vector3 &operator -= (const Vector3 &v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	Vector3 operator * (const float &t) {
		return Vector3(x*t, y*t, z*t);
	}

	Vector3 &operator *= (const float &t) {
		x *= t;
		y *= t;
		z *= t;
		return *this;
	}

	Vector3 operator / (const float &t) {
		return Vector3(x/t, y/t, z/t);
	}

	Vector3 &operator /= (const float &t) {
		x /= t;
		y /= t;
		z /= t;
		return *this;
	}
};

#endif