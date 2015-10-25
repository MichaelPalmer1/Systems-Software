/* Michael Palmer
 * CSCI 3232
 * February 9, 2015
 */

#include <iostream>
#include "boxType.h"
using namespace std;

void boxType::setDim(double l, double w, double h) {
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

	if(h > 0) {
		height = h;
	} else {
		height = 0;
	}
}

double boxType::getSurfaceArea() const {
	double a1 = length * width * 2;
	double a2 = length * height * 2;
	double a3 = width * height * 2;
	return a1 + a2 + a3;
}

void boxType::print() const {
	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
	cout << "Surface Area: " << getSurfaceArea() << endl;
}

boxType::boxType() {
	setDim(0, 0, 0);
}

rectangleType::rectangleType() {

}
