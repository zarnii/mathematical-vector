# Описание
**Библиотека, реализующая работу с математическими векторами**

# Начало
Для подключения создайте папку includes и поместите туда файл vectors.h и подключите.
```C++
#include "../includes/vectors.h"
```
Или поместите файл в папку с ***cpp*** файлом и подключите.
```C++
#include "vectors.h"
```
## Vector 2D
```C++
//Создание вектора
vectors::Vector2D<int> vec = vectors::Vector2D<int>(1, 2, 3, 4);
```
Конструктор класса ***Vector2D*** создает вектор в двумерном пространстве с координатами *x1=1 y1=2* - координаты начала вектора и *x2=3 y2=4* - координаты конца вектора.

Конструктор класса:
```C++
template <typename vector_type>
	Vector2D<vector_type>::Vector2D(vector_type x_begin, vector_type y_begin, vector_type x_end, vector_type y_end) {
		this->begin.x = x_begin;
		this->begin.y = y_begin;

		this->end.x = x_end;
		this->end.y = y_end;
	}
```
## Vector 3D
```C++
//Создание вектора
vectors::Vector3D<int> vec = vectors::Vector3D<int>(1, 2, 3, 4, 5, 6);
```
Конструктор класса ***Vector3D*** создает вектор в трехмерном пространстве с координатами *x1=1 y1=2 z1=3* - координаты начала вектора и *x2=4 y2=5 z2=6* - координаты конца вектора.

Конструктор класса: 
```C++
template<typename vector_type>
	Vector3D<vector_type>::Vector3D(vector_type x_begin, vector_type y_begin, vector_type z_begin, vector_type x_end, vector_type y_end, vector_type z_end) {
		this->begin.x = x_begin;
		this->begin.y = y_begin;
		this->begin.z = z_begin;

		this->end.x = x_end;
		this->end.y = y_end;
		this->end.z = z_end;
	}
```
## Методы классов
+ *GetCords* - возвращает указатель на массив с координатами. Для Vector2D - {x1, y1, x2, y2}. Для Vector3D {x1, y1, z1, x2, y2, z2}.
Пример:
```C++
vectors::Vector2D<int> vec = vectors::Vector2D<int>(2, 2, 4, 4);
int* cords1 = vec.getCords();
```
+ *LenVec* - возвращает длину вектора типа *double*.
Пример:
```C++
vectors::Vector2D<int> vec = vectors::Vector2D<int>(2, 2, 4, 4);
double len = vec.LenVec2D();
```

## Математические действия с векторами
+ *AddlVec2dByTriange* - Сложение Vector2D методом треугольника. На вход принимает массив с координатами векторов. Данная функция создает новый вектор
Функция:
```C++
template <typename vector_type>
	Vector2D<vector_type> AddlVec2dByTriange(vector_type cords1[], vector_type cords2[]) {
		vector_type deltaX = cords2[2] - cords2[0];
		vector_type deltaY = cords2[3] - cords2[1];

		Vector2D<vector_type> vec(cords1[0], cords1[1], cords1[2] + deltaX, cords1[3] + deltaY);
		return vec;
	}
```
Пример:
```C++
vectors::Vector2D<int> vec = vectors::Vector2D<int>(2, 2, 4, 4);
vectors::Vector2D<int> vec = vectors::Vector2D<int>(2, 2, 5, 5);

```
