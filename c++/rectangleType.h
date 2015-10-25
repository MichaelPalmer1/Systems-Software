/* Michael Palmer
 * CSCI 3232
 * February 9, 2015
 */

class rectangleType {
	public:
		void setDim(double l, double w);
		double getArea() const;
		double getPerimeter() const;
		void print() const;
		rectangleType();
	protected:
		double length;
		double width;
};
