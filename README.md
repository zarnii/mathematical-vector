# Описание
**Библиотека, реализующая работу с математическими векторами**

# Подключение
Для подключения используйте папку lib и vectors.h из папки src

# Vector2D
## Конструкторы
+ ```C++
  Vector2D(double x, double y);
  ```
+ ```C++
  Vector2D();
  ```

## Поля
+ X - координата x.
+ Y - координата y.

# Vector3D
## Конструкторы
+ ```C++
  Vector3D(double x, double y, double z)
  ```
+ ```C++
  Vector3D()
  ```
## Поля
+ X - координата x.
+ Y - координата y.
+ Z - кордината z.


## Методы
+ ***GetX()*** - возвращает координату X.
+ ***GetY()*** - возвращает координату Y.
+ ***GetZ()*** - возвращает координату Z (только для Vector3D).
+ ***Lenght()*** - возвращает длину вектора.
+ ****GetCords()*** - возвршает указатель на массив с координатами.
+ ***Normalize()*** - нормализует данный вектор.
+ ***NormalizeNew()*** - нормализует координаты данного вектора и создает новый.

## Операторы
+ "+" - сложение векторов.
```C++
Vector2D vec1 = Vector2D(1, 1);
Vector2D vec2 = Vector2D(4, 1);
Vector2D vec3 = vec1 + vec2; //Vector2D(5, 2)
```
```C++
Vector3D vec1 = Vector3D(3, 4, 0);
Vector3D vec2 = Vector3D(4, 4, 2);
Vector3D vec3 = vec1 + vec2; //Vector3D(7, 8, 2)
```
+ "-" - вычитание векторов.
```C++
Vector2D vec1 = Vector2D(1, 1);
Vector2D vec2 = Vector2D(4, 1);
Vector2D vec3 = vec1 - vec2; //Vector2D(-3, 0)
```
```C++
Vector3D vec1 = Vector3D(3, 4, 0);
Vector3D vec2 = Vector3D(4, 4, 2);
Vector3D vec3 = vec1 - vec2; //Vector3D(-1, 0, -2)
```
+ "\*" - умножение векторов.
```C++
Vector2D vec1 = Vector2D(1, 1);
Vector2D vec2 = Vector2D(4, 1);
Vector2D vec3 = vec1 * vec2; //Vector2D(4, 1)
```
```C++
Vector3D vec1 = Vector3D(3, 4, 0);
Vector3D vec2 = Vector3D(4, 4, 2);
Vector3D vec3 = vec1 * vec2; //Vector3D(12, 16, 0)
```
+ "/" - деление векторов.
```C++
Vector2D vec1 = Vector2D(4, 1);
Vector2D vec2 = Vector2D(2, 1);
Vector2D vec3 = vec1 / vec2; //Vector2D(2, 1)
```
```C++
Vector3D vec1 = Vector3D(4, 4, 1);
Vector3D vec2 = Vector3D(4, 2, 2);
Vector3D vec3 = vec1 * vec2; //Vector3D(1, 2, 0.5)
```
# Функции
+ ***Scalar*** - возвращает сколярное произведение двух векторов.
```C++
Vector3D vec1 = Vector3D(3, 4, 0);
Vector3D vec2 = Vector3D(4, 4, 2);
double scalar = Scalar(vec1, vec2);
cout << scalar; // >> 28
```
+ ***Angle*** - возвращает угол между векторами в градусах.
```C++
Vector3D vec1 = Vector3D(3, 4, 0);
Vector3D vec2 = Vector3D(4, 4, 2);
double angle = Angle(vec1, vec2);
cout << angle; // >> 0.933333
```
