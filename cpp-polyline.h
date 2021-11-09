#pragma once
using namespace std;
namespace cpp
{
	struct point
	{
		double _x;
		double _y;
		
	};

	class polyline
	{
	private:
		point* _vertices;
		int _n; //number of vertices
	public:
		polyline();//default constructor
		polyline(int n);//with the parameter
		polyline(const polyline& rhs);//copy
		void swap(polyline&);
		int get_n() const;
		~polyline();
		point& operator[](const int index);
		point operator[](const int index) const;
		polyline& operator=(const polyline& rhs);
		polyline operator+(const polyline& s);
		bool operator==(polyline& rhs);
		polyline& operator<(struct point t);//adding a vertex to the beginning of a polyline
		polyline& operator>(struct point t);//adding a vertex to the end of a polyline
		double distance();
	};

	ostream& operator<<(ostream& out, const point& p_i);
	istream& operator>>(istream& in, point& p_i);
	ostream& operator<<(ostream& out, const polyline& p);
	istream& operator>>(istream& in, polyline& p);
	void print_collection(polyline* ptr, int& n_polyline);
	void add_object(polyline* ptr, polyline newPolyline, int& n_polyline);
	void delete_object(polyline* ptr, int index, int& n_polyline);
	void delete_all_object(polyline* ptr);
	
}