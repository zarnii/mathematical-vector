// vectorsLIB.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "vectors.h"
#include "math.h"

//Конструкторы
vectors::Vector2D::Vector2D(double x, double y) 
{
	this->x = x;
	this->y = y;
}

vectors::Vector2D::Vector2D()
{
	this->x = 0;
	this->y = 0;
}

//Методы
double vectors::Vector2D::GetX()
{
	return x;
}

double vectors::Vector2D::GetY()
{
	return y;
}

double vectors::Vector2D::Length()
{
	return sqrt( pow(x,2) + pow(y, 2) );
}

double* vectors::Vector2D::GetCords()
{
	return new double[2] {x, y};
}

void vectors::Vector2D::Normalize()
{
	double invert_len = 1 / this->Length();
	this->x *= invert_len;
	this->y *= invert_len;
}

vectors::Vector2D vectors::Vector2D::NormalizeNew()
{
	double invert_len = 1 / this->Length();
	double x = this->x * invert_len;
	double y = this->y * invert_len;
	return Vector2D(x, y);
}


//Операторы
vectors::Vector2D vectors::Vector2D::operator+(Vector2D value)
{
	return Vector2D(this->x + value.x, 
					this->y + value.y);
}

vectors::Vector2D vectors::Vector2D::operator-(Vector2D value)
{
	return Vector2D(this->x - value.x,
					this->y - value.y);
}

vectors::Vector2D vectors::Vector2D::operator*(Vector2D value)
{
	return Vector2D(this->x * value.x,
					this->y * value.y);
}

vectors::Vector2D vectors::Vector2D::operator*(double value)
{
	return Vector2D(this->x * value,
					this->y * value);
}

vectors::Vector2D vectors::Vector2D::operator/(Vector2D value)
{
	return Vector2D(this->x / value.x,
					this->y / value.y);
}



//Конструкторы
vectors::Vector3D::Vector3D(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

vectors::Vector3D::Vector3D()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

//Методы
double vectors::Vector3D::GetX()
{
	return x;
}

double vectors::Vector3D::GetY()
{
	return y;
}

double vectors::Vector3D::GetZ()
{
	return z;
}

double vectors::Vector3D::Length()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z,2));
}

double* vectors::Vector3D::GetCords()
{
	return new double[3] {x, y, z};
}

void vectors::Vector3D::Normalize()
{
	double invert_len = 1 / this->Length();
	this->x *= invert_len;
	this->y *= invert_len;
	this->z *= invert_len;
}

vectors::Vector3D vectors::Vector3D::NormalizeNew()
{
	double invert_len = 1 / this->Length();
	double x = this->x * invert_len;
	double y = this->y * invert_len;
	double z = this->z * invert_len;

	return Vector3D(x, y, z);
}


//Операторы
vectors::Vector3D vectors::Vector3D::operator+(Vector3D value)
{
	return Vector3D(this->x + value.x,
					this->y + value.y,
					this->z + value.z);
}

vectors::Vector3D vectors::Vector3D::operator-(Vector3D value)
{
	return Vector3D(this->x - value.x,
					this->y - value.y, 
					this->z - value.z);
}

vectors::Vector3D vectors::Vector3D::operator*(Vector3D value)
{
	return Vector3D(this->x * value.x,
					this->y * value.y,
					this->z * value.z);
}

vectors::Vector3D vectors::Vector3D::operator*(double value)
{
	return Vector3D(this->x * value,
					this->y * value,
					this->z * value);
}

vectors::Vector3D vectors::Vector3D::operator/(Vector3D value)
{
	return Vector3D(this->x / value.x,
					this->y / value.y,
					this->z / value.z);
}


//Функции namespace
double vectors::Scalar(vectors::Vector2D vec1, vectors::Vector2D vec2)
{
	return(vec1.GetX() * vec2.GetX() + vec1.GetY() * vec2.GetY());
}

double vectors::Scalar(vectors::Vector3D vec1, vectors::Vector3D vec2)
{
	return(vec1.GetX() * vec2.GetX() + vec1.GetY() * vec2.GetY() + vec1.GetZ() * vec2.GetZ());
}

double vectors::Angle(vectors::Vector2D vec1, vectors::Vector2D vec2)
{
	double scalar = vectors::Scalar(vec1, vec2);

	double len_vec1 = vec1.Length();
	double len_vec2 = vec2.Length();

	return scalar / (len_vec1 * len_vec2);
}

double vectors::Angle(vectors::Vector3D vec1, vectors::Vector3D vec2)
{
	double scalar = vectors::Scalar(vec1, vec2);

	double len_vec1 = vec1.Length();
	double len_vec2 = vec2.Length();

	return scalar / (len_vec1 * len_vec2);
}