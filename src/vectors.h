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
		
		//Операторы
		Vector2D operator+(Vector2D value);
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

		//Операторы
		Vector3D operator+(Vector3D value);
	};
}