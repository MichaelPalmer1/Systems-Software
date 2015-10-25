/* Michael Palmer
 * CSCI 3232
 * February 9, 2015
 */

#include "rectangleType.h"
class boxType: public rectangleType {
	public:
		void setDim(double l, double w, double h);
		double getSurfaceArea() const;
		void print() const;
		boxType();
	private:
		double height;
};
