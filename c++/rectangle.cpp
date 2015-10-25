/* Michael Palmer
 * CSCI 3232
 * February 9, 2015
 */

#include <iostream>
#include "rectangleType.h"
using namespace std;

void rectangleType::setDim(double l, double w) {
	if(l > 0) {
		length = l;
	} else {
		length = 0;
	}

	if(w > 0) {
		width = w;
	} else {
		width = 0;
	}
}

double rectangleType::getArea() const {
	return length * width;
}

double rectangleType::getPerimeter() const {
	return (length * 2) + (width * 2);
}

void rectangleType::print() const {
	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
	cout << "Perimeter: " << getPerimeter() << endl;
	cout << "Area: " << getArea() << endl;
}

rectangleType::rectangleType() {
	setDim(0, 0);
}
