#pragma once
#include <math.h>
namespace vectors {

	template <typename vector_type>
	class Vector2D {

		struct BEGIN {
			vector_type x_begin;
			vector_type y_begin;
		}begin;

		struct END {
			vector_type x_end;
			vector_type y_end;
		}end;

	public:
		/*
		*\brief  онструктор
		*\param x_begin x координата начала вектора
		*\param y_begin y координата начала вектора
		*\param x_end x координата конца вектора
		*\param y_end y координата конца вектора
		*/
		Vector2D(vector_type x_begin, vector_type y_begin, vector_type x_end, vector_type y_end);

		/*
		*\brief ѕустой конструктор
		*/
		Vector2D();

		/*
		*\brief ѕолучение координат
		*\return возвращает указатель на массив с координатами
		*/
		vector_type* getCords();

		/*
		*\brief ѕолучение длины
		*\return длина
		*/
		double lenVec2D();

	};

	
	template <typename vector_type>
	Vector2D<vector_type>::Vector2D(vector_type x_begin, vector_type y_begin, vector_type x_end, vector_type y_end) {
		this->begin.x_begin = x_begin;
		this->begin.y_begin = y_begin;

		this->end.x_end = x_end;
		this->end.y_end = y_end;
	}


	template <typename vector_type>
	Vector2D<vector_type>::Vector2D() {
		this->begin.x_begin = 0;
		this->begin.y_begin = 0;

		this->end.x_end = 0;
		this->end.y_end = 0;
	}


	template <typename vector_type>
	vector_type* Vector2D<vector_type>::getCords() {
		vector_type* cords = new vector_type[4]{ begin.x_begin, begin.y_begin, end.x_end, end.y_end };
		return cords;
	}


	template<typename vector_type>
	double Vector2D<vector_type>::lenVec2D() {
		double len = sqrt(((end.x_end - begin.x_begin) * (end.x_end - begin.x_begin)) * ((end.y_end - begin.y_begin) * (end.y_end - begin.y_begin)));
		return len;
	}

	/*
	*\brief —ложение вектором правилом треугольника
	*\param cords1 координаты вектора 1
	*\param cords2 координаты вектора 2
	*\return объект типа Vector2D
	*/
	template <typename vector_type>
	Vector2D<vector_type> additionalVecByTriange(vector_type cords1[], vector_type cords2[]) {
		vector_type deltaX = cords2[2] - cords2[0];
		vector_type deltaY = cords2[3] - cords2[1];

		Vector2D<vector_type> vec(cords1[0], cords1[1], cords1[2] + deltaX, cords1[3] + deltaY);
		return vec;
	}

	/*
	*\brief ѕроверка коллинеарности векторов
	*\param cords1 координаты вектора 1
	*\param cords2 координаты вектора 2
	*\return true - коллинеарны, иначе - false
	*/
	template <typename vector_type>
	bool isCollinear(vector_type cords1[], vector_type cords2[]) {
		vector_type AB[2]{ cords1[2] - cords1[0], cords1[3] - cords1[1] };
		vector_type CD[2]{ cords2[2] - cords2[0], cords2[3] - cords2[1] };


		if ((double)AB[0] / CD[0] == (double)AB[1] / CD[1]) {
			return true;
		}
		else {
			return false;
		}
	}

};
