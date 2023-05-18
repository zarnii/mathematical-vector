#pragma once

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows

namespace vectors 
{
	class Vector2D
	{
		double x;
		double y;
	public:
		//Конструкторы
		Vector2D(double x, double y);
		Vector2D();
		
		//Методы
		double GetX();
		double GetY();
		double Length();
		double* GetCords();
		void Normalize();
		Vector2D NormalizeNew();
		
		//Операторы
		Vector2D operator+(Vector2D value);
		Vector2D operator-(Vector2D value);
		Vector2D operator*(Vector2D value);
		Vector2D operator*(double value);
		Vector2D operator/(Vector2D value);
	};

	class Vector3D
	{
		double x;
		double y;
		double z;
	public:
		//Конструкторы
		Vector3D(double x, double y, double z);
		Vector3D();

		//Методы
		double GetX();
		double GetY();
		double GetZ();
		double Length();
		double* GetCords();
		void Normalize();
		Vector3D NormalizeNew();

		//Операторы
		Vector3D operator+(Vector3D value);
		Vector3D operator-(Vector3D value);
		Vector3D operator*(Vector3D value);
		Vector3D operator*(double value);
		Vector3D operator/(Vector3D value);
	};

	double Scalar(Vector2D vec1, Vector2D vec2);
	double Scalar(Vector3D vec1, Vector3D vec2);
	double Angle(Vector2D vec1, Vector2D vec2);
	double Angle(Vector3D vec1, Vector3D vec2);
}