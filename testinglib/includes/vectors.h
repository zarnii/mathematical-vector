#pragma once
#include <math.h>
namespace vectors {

	template <typename vector_type>
	class Vector2D {

		struct BEGIN {
			vector_type x;
			vector_type y;
		}begin;

		struct END {
			vector_type x;
			vector_type y;
		}end;

	public:
		/*
		*\brief �����������
		*\param x_begin x ���������� ������ �������
		*\param y_begin y ���������� ������ �������
		*\param x_end x ���������� ����� �������
		*\param y_end y ���������� ����� �������
		*/
		Vector2D(vector_type x_begin, vector_type y_begin, vector_type x_end, vector_type y_end);

		/*
		*\brief ����������� ��� ����������.
		*/
		Vector2D();

		/*
		*\brief ��������� ������� � ������������.
		*\return ��������� �� ������
		*/
		vector_type* GetCords();

		/*
		*\brief ��������� ����� 2D �������.
		*\return �����
		*/
		double LenVec2D();

	};


	//����������� ������ Vector2D
	template <typename vector_type>
	Vector2D<vector_type>::Vector2D(vector_type x_begin, vector_type y_begin, vector_type x_end, vector_type y_end) {
		this->begin.x = x_begin;
		this->begin.y = y_begin;

		this->end.x = x_end;
		this->end.y = y_end;
	}



	//����������� ������ Vector2D
	template <typename vector_type>
	Vector2D<vector_type>::Vector2D() {
		this->begin.x = 0;
		this->begin.y = 0;

		this->end.x = 0;
		this->end.y = 0;
	}


	//����� ������ Vector2D
	template <typename vector_type>
	vector_type* Vector2D<vector_type>::GetCords() {
		vector_type* cords = new vector_type[4]{ begin.x, begin.y, end.x, end.y };
		return cords;
	}


	//����� ������ Vector2D
	template<typename vector_type>
	double Vector2D<vector_type>::LenVec2D() {
		double len = sqrt(pow(end.x - begin.x, 2) + pow(end.y - begin.y, 2));
		return len;
	}



	template <typename vector_type>
	class Vector3D {

		//����� ������ �������
		struct BEGIN {
			vector_type x;
			vector_type y;
			vector_type z;
		}begin;

		//����� ����� �������
		struct END {
			vector_type x;
			vector_type y;
			vector_type z;
		}end;

	public:
		/*
		*\brief �����������.
		*\param x_begin ���������� ������ x
		*\param y_begin ���������� ������ y
		*\param z_begin ���������� ������ z
		*\param x_end ���������� ����� x
		*\param y_end ���������� ����� y
		*\param z_end ���������� ����� z
		*/
		Vector3D(vector_type x_begin, vector_type y_begin, vector_type z_begin, vector_type x_end, vector_type y_end, vector_type z_end);

		/*
		*\brief ����������� ��� ����������.
		*/
		Vector3D();


		/*
		*\brief ��������� ������� ��������� �������.
		*\return ��������� �� ������ [x_begin, y_begin, z_begin, x_end, y_end, z_end] 
		*/
		vector_type* GetCords();

		/*
		*\brief ��������� ����� 3D �������.
		*/
		double LenVec3D();
	};


	//����������� ������ Vector3D
	template<typename vector_type>
	Vector3D<vector_type>::Vector3D(vector_type x_begin, vector_type y_begin, vector_type z_begin, vector_type x_end, vector_type y_end, vector_type z_end) {
		this->begin.x = x_begin;
		this->begin.y = y_begin;
		this->begin.z = z_begin;

		this->end.x = x_end;
		this->end.y = y_end;
		this->end.z = z_end;
	}


	template<typename vector_type>
	Vector3D<vector_type>::Vector3D() {
		this->begin.x = 0;
		this->begin.y = 0;
		this->begin.z = 0;

		this->end.x = 0;
		this->end.y = 0;
		this->end.z = 0;
	}

	template<typename vector_type>
	vector_type* Vector3D<vector_type>::GetCords() {
		vector_type* cords = new vector_type[6]{ begin.x, begin.y, begin.z, end.x, end.y, end.z };
		return cords;
	}

	template<typename vector_type>
	double Vector3D<vector_type>::LenVec3D() {
		double len = sqrt(pow(end.x - begin.x, 2) + pow(end.y - begin.y, 2) + pow(end.z - begin.z));
		return len;
	}

	/*
	*\brief �������� Vector2D �������� ������������
	*\param cords1 ���������� ������� 1
	*\param cords2 ���������� ������� 2
	*\return ������ ���� Vector2D
	*/
	template <typename vector_type>
	Vector2D<vector_type> AddlVec2dByTriange(vector_type cords1[], vector_type cords2[]) {
		vector_type deltaX = cords2[2] - cords2[0];
		vector_type deltaY = cords2[3] - cords2[1];

		Vector2D<vector_type> vec(cords1[0], cords1[1], cords1[2] + deltaX, cords1[3] + deltaY);
		return vec;
	}


	/*
	*\brief �������� Vector3D �������� ������������.
	*\param cords1 ���������� ������� 1
	*\param cords2 ���������� ������� 2
	*\return ������ ���� Vector3D
	*/
	template <typename vector_type>
	Vector3D<vector_type> AddVec3dByTriange(vector_type cords1[], vector_type cords2[]) {
		vector_type deltaX = cords2[3] - cords2[0];
		vector_type deltaY = cords2[4] - cords2[1];
		vector_type deltaZ = cords2[5] - cords2[2];

		Vector3D<vector_type> vec(cords1[0], cords1[1], cords1[2], cords1[3] + deltaX, cords1[4] + deltaY, cords1[5] + deltaZ);
		return vec;
	}


	/*
	*\brief ��������� Vec2D.
	*\param cords1 ���������� ������� 1
	*\param cords2 ���������� ������� 2
	*\return ������ ���� Vector2D
	*/
	template <typename vector_type>
	Vector2D<vector_type> SubVec2d(vector_type cords1[], vector_type cords2[]) {
		vector_type deltaX = cords2[2] - cords2[0];
		vector_type deltaY = cords2[3] - cords2[1];

		Vector2D<vector_type> vec(cords1[2], cords1[3], cords1[0] + deltaX, cords1[1] + deltaY);
		return vec;
	}


	/*
	*\brief ��������� Vec3D.
	*\param cords1 ���������� ������� 1
	*\param cords2 ���������� ������� 2
	*\return ������ ���� Vector3D
	*/
	template <typename vector_type>
	Vector3D<vector_type> SubVec3d(vector_type cords1[], vector_type cords2[]) {
		vector_type deltaX = cords2[3] - cords2[0];
		vector_type deltaY = cords2[4] - cords2[1];
		vector_type deltaZ = cords2[5] - cords2[2];

		Vector3D<vector_type> vec(cords1[3], cords1[4], cords1[5], cords1[0] + deltaX, cords1[1] + deltaY, cords1[2] + deltaZ);
		return vec;
	}


	/*
	*\brief ��������� ������������ Vec2D.
	*\param cords1 ���������� ������� 1
	*\param cords2 ���������� ������� 2
	*\return �����
	*/
	template <typename vector_type>
	Vector2D<vector_type> ScalarMultVec2d(vector_type cords1[], vector_type cords2[]) {
		vector_type deltaX1 = cords1[2] - cords1[0];
		vector_type deltaY1 = cords1[3] - cords1[1];
		
		vector_type deltaX2 = cords2[2] - cords2[0];
		vector_type deltaY2 = cords2[3] - cords2[1];

		return deltaX1 * deltaX2 + deltaY1 * deltaY2;
	}


	/*
	*\brief ��������� ������������ Vec3D.
	*\param cords1 ���������� ������� 1
	*\param cords2 ���������� ������� 2
	*\return �����
	*/
	template <typename vector_type>
	Vector2D<vector_type> ScalarMultVec3d(vector_type cords1[], vector_type cords2[]) {
		vector_type deltaX1 = cords1[3] - cords1[0];
		vector_type deltaY1 = cords1[4] - cords1[1];
		vector_type deltaZ1 = cords1[5] - cords1[2];

		vector_type deltaX2 = cords2[3] - cords2[0];
		vector_type deltaY2 = cords2[4] - cords2[1];
		vector_type deltaZ2 = cords2[5] - cords2[2];

		return (deltaX1 * deltaX2) + (deltaY1 * deltaY2) + (deltaZ1 * deltaZ2);
	}


	/*
	*\brief ���������� cos Vec2D
	*\param cords1 ���������� ������� 1
	*\param cords2 ���������� ������� 2
	*\return �����
	*/
	template <typename vector_type>
	double cosVec2D(vector_type cords1[], vector_type cords2[]) {
		vector_type aX = cords1[2] - cords1[0];
		vector_type aY = cords1[3] - cords1[1];

		vector_type bX = cords2[2] - cords2[0];
		vector_type bY = cords2[3] - cords2[1];

		return (aX * bX + aX * bX) / (sqrt(pow(aX, 2) + pow(aY, 2)) * sqrt(pow(bX, 2) + pow(bY, 2)));
	}


	/*
	*\brief ���������� cos Vec3D
	*\param cords1 ���������� ������� 1
	*\param cords2 ���������� ������� 2
	*\return �����
	*/
	template <typename vector_type>
	double cosVec3D(vector_type cords1[], vector_type cords2[]) {
		vector_type aX = cords1[3] - cords1[0];
		vector_type aY = cords1[4] - cords1[1];
		vector_type aZ = cords1[5] - cords1[2];

		vector_type bX = cords2[3] - cords2[0];
		vector_type bY = cords2[4] - cords2[1];
		vector_type bZ = cords2[5] - cords2[2];

		return (aX * bX + aX * bX + aZ * bZ) / (sqrt(pow(aX, 2) + pow(aY, 2) + pow(aZ, 2)) * sqrt(pow(bX, 2) + pow(bY, 2) + pow(bZ, 2));
	}

	/*
	*\brief �������� �������������� ��������
	*\param cords1 ���������� ������� 1
	*\param cords2 ���������� ������� 2
	*\return true - �����������, ����� - false
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
