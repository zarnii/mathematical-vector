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

//Операторы
vectors::Vector2D vectors::Vector2D::operator+(vectors::Vector2D value)
{
	return Vector2D(this->x + value.x, 
					this->y + value.y);
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

//Операторы
vectors::Vector3D vectors::Vector3D::operator+(vectors::Vector3D value)
{
	return Vector3D(this->x + value.x,
					this->y + value.y,
					this->z + value.z);
}