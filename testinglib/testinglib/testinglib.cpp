#include <iostream>
#include "../includes/vectors.h"


int main()
{
	vectors::Vector2D<int> vec = vectors::Vector2D<int>(2, 2, 4, 4);
	vectors::Vector2D<double> vec1 = vectors::Vector2D<double>(1, 3, 2.1, 5.1);

	int* cords1 = vec.getCords();
	double cords1_d[4]{ (double)cords1[0], (double)cords1[1], (double)cords1[2],(double)cords1[3] };

	double* cords2 = vec1.getCords();

	vectors::Vector2D<double> vec2 = vectors::additionalVecByTriange(cords1_d, cords2);
	
	double* cords3 = vec2.getCords();
	for (int i = 0; i < 4; i++)std::cout << cords3[i] << ' ';
	
}

