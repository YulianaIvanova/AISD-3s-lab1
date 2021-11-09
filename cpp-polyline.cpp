#include <cstdio>
#include <iostream>
#include <exception>
#include "cpp-polyline.h"
using namespace std;
namespace cpp
{
	polyline::polyline() : _n(0), _vertices(NULL) {};

	polyline::polyline(int n) :_n(n)
	{
		_vertices = new  point[_n];
	}


	void polyline::swap(polyline& rhs)
	{
		std::swap(_n, rhs._n);
		std::swap(_vertices, rhs._vertices);
	}

	polyline::polyline(const polyline& rhs) : _n(rhs._n)
	{
		_vertices = new  point[_n];
		for (int i = 0; i < _n; i++)
		{
			_vertices[i] = rhs._vertices[i];
		}
	}

	int polyline::get_n() const
	{
		return _n;
	}


	polyline::~polyline()
	{
		delete[] _vertices;
	}


	point& polyline::operator[](int index)
	{
		if (index > _n || index < 0)
			throw logic_error("out_of_bounds");
		else
			return _vertices[index];
	}

	point polyline::operator[](int index) const
	{
		if (index > _n || index < 0)
			throw logic_error("out_of_bounds");
		else
			return _vertices[index];
	}

	polyline& polyline::operator=(const polyline& rhs)
	{
		polyline copy(rhs);
		swap(copy);
		return *this;
	}

	polyline polyline::operator+(const polyline& s)
	{
		polyline res(_n + s._n - 1);
		for (int i = 0; i < _n; i++)
		{
			res._vertices[i] = _vertices[i];
		}
		for (int i = 0; i < s._n; i++)
		{
			int p = i;
			int q = i + 1;
			if (q == s._n) break;
			else
			{
				double dx = s._vertices[q]._x - s._vertices[p]._x;
				double dy = s._vertices[q]._y - s._vertices[p]._y;

				res._vertices[i + _n]._x = res._vertices[i + _n - 1]._x + dx;
				res._vertices[i + _n]._y = res._vertices[i + _n - 1]._y + dy;
			}
		}
		return res;
	}
	
	bool polyline::operator==(polyline& rhs)
	{
		double epsilon = 0.01f;
		if (abs(distance() - rhs.distance()) < epsilon)
			return true;
		return false;
	}

	//adding to the beginning
	polyline& polyline::operator<(struct point t)
	{
		point* tmp = new point[_n + 1];
		tmp[0] = t;

		for (int i = 0; i < _n; i++)
		{
			tmp[i + 1] = _vertices[i];
		}
		delete[] _vertices;
		_vertices = tmp;
		_n++;
		return *this;
	}

	//adding to the end
	polyline& polyline::operator>(struct point t)
	{
		point* tmp = new point[_n + 1];
		tmp[_n] = t;
		for (int i = 0; i < _n; i++)
		{
			tmp[i] = _vertices[i];
		}
		delete[] _vertices;
		_vertices = tmp;
		_n++;
		return *this;
	}

	double polyline::distance()
	{
		double len = 0;
		for (int i = 1; i < _n; ++i)
		{
			double dx = _vertices[i]._x - _vertices[i - 1]._x;
			double dy = _vertices[i]._y - _vertices[i - 1]._y;
			len += sqrt(dx * dx + dy * dy);
		}
		return len;
	}


	ostream& operator<<(ostream& out, const point& p_i)//vertex output
	{
		out << "X: " << p_i._x << '\n';
		out << "Y: " << p_i._y << '\n';
		out << '\n';
		return out;
	}

	istream& operator>>(istream& in, point& p_i)//entering a vertex
	{
		char data[32] = { 0 };
		char* pointer = data;
		in.getline(pointer, 32);
		pointer = pointer + 1;
		char* tmp = strchr(pointer, ';');
		int len_data = (tmp - pointer) / sizeof(char);
		char data_x[32] = { 0 };
		for (int j = 0; j < len_data; j++)
		{
			data_x[j] = pointer[j];
		}
		p_i._x = atof(data_x);

		pointer = tmp + 1;

		tmp = strchr(pointer, ')');
		len_data = (tmp - pointer) / sizeof(char);
		char data_y[32] = { 0 };
		for (int j = 0; j < len_data; j++)
		{
			data_y[j] = pointer[j];
		}
		p_i._y = atof(data_y);
		return in;
	}

	istream& operator>>(istream& in, polyline& p)//entering a polyline
	{
		int n;
		in >> n;
		in.get();
		polyline _p(n);
		for (int i = 0; i < n; i++)
		{
			point v;
			in >> v;
			_p[i] = v;
		}
		p = _p;
		return in;
	}
	ostream& operator<<(ostream& out, const polyline& p)//polyline output
	{
		for (int i = 0; i < p.get_n(); i++)
		{
			out << p[i];
		}
		out << '\n';
		return out;
	}

	
	void add_object(polyline* ptr, polyline newPolyline, int& n_polyline)
	{
		ptr[n_polyline] = newPolyline;
		n_polyline++;
	}

	void delete_object(polyline* ptr, int index, int& n_polyline)
	{
		if (n_polyline == 0)
		{
			throw "The collection is empty!Nothing to delete";
		}
		else if (index - 1 < 0 || index - 1 > n_polyline)
		{
			throw logic_error("Out of bounds");
		}
		else
		{
			
			for (int i = index - 1; i < n_polyline - 1; i++)
			{
				ptr[i] = ptr[i + 1];
			}
			n_polyline--;
		}
	}
		
	//void delete_all_object(polyline* ptr)
	//{
	//	delete []ptr;
	//	cout << "All object have been deleted!";
	//}
		
	void print_collection(polyline* ptr, int& n_polyline)
	{
		if (n_polyline == 0)
		{
			throw "The collection is empty!";
		}
		else
		{
			for (int i = 0; i < n_polyline; i++)
			{
				cout << "Polyline " << i + 1 << endl;
				{
					cout << ptr[i];
				}
				cout << '\n'; 
			}
		}
	}
}

