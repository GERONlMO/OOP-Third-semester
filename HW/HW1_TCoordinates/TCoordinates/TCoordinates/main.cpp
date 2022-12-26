#include <iostream>
#include <fstream>
using namespace std;

template <class Type> class TCoordinates;

template <class Type>
class TCoordinates {
	Type x;
	Type y;
public:
	TCoordinates(Type x, Type y) : x(x), y(y) {
		this->x = x;
		this->y = y;
	}

	TCoordinates() : x(0), y(0) {
		x = y = 0;
	}


	template <class Type2>
	TCoordinates(const TCoordinates<Type2>& coor) {
		this->x = coor.x;
		this->y = coor.y;
	}

	template <class Type2>
	TCoordinates<Type>& operator=(const TCoordinates<Type2>& coor) {
		if (this == &coor) return *this;
		this->x = coor.x;
		this->y = coor.y;
		return *this;
	}

	TCoordinates<Type>& operator+(TCoordinates<Type> coor) {
		TCoordinates<Type> temp(this->x + coor.x, this->y + coor.y);
		return temp;
	}

	TCoordinates<Type>& operator-(TCoordinates<Type> coor) {
		TCoordinates<Type> temp(this->x - coor.x, this->y - coor.y);
		return temp;
	}


	void print() {
		cout << x << " " << y << endl;
	}

	friend ostream& operator<<(ostream& out, TCoordinates& coor) {
		out << "X: " << coor.x << "\tY: " << coor.y << endl;
		return out;
	}
};


int main() {
	TCoordinates<double> coor1(1, 0);
	coor1.print();
	cout << coor1;

	TCoordinates<double> coor2(0, 1.1);
	coor2.print();
	cout << coor2;

	TCoordinates<double> coor3 = coor1 + coor2;
	coor3.print();
	cout << coor3;

}