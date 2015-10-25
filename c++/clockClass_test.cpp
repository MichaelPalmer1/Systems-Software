/* Michael Palmer
 * CSCI 3232
 * February 11, 2015
 */

#include <iostream>
#include "clockType.h"
using namespace std;

int main() {
	// Initialize clock1 with time 22:58:59
	clockType clock1(22,58,59);
	cout << "clock1 Initial Time: ";
	clock1.printTime();

	// Initialize clock2 with default time of 0:0:0
	clockType clock2;
	cout << "clock2 Initial Time: ";
	clock2.printTime();
	cout << endl;

	// Check if clock1 time is same as clock2 time
	cout << "clock1 is same time as clock2: " << clock1.equalTime(clock2) << endl << endl;

	// Increment clock1 by 1 hour
	cout << "Incrementing clock1 by 1 hour" << endl;
	clock1.incrementHours();
        cout << "clock1 time is now ";
        clock1.printTime();

	// Increment clock1 by 1 minute
        cout << "Incrementing clock1 by 1 minute" << endl;
        clock1.incrementMinutes();
        cout << "clock1 time is now ";
        clock1.printTime();

	// Increment clock1 by 1 second
	cout << "Incrementing clock1 by 1 second" << endl;
	clock1.incrementSeconds();
	cout << "clock1 time is now ";
	clock1.printTime();
	cout << endl;

	// Check if clock1 time is same as clock2 time
	cout << "clock1 is same time as clock2: " << clock1.equalTime(clock2) << endl << endl;

	// Set clock2 time to 15:31:12
	cout << "Setting clock2 time to 15:31:12" << endl;
	clock2.setTime(15,31,12);

	// Get clock2 time
	int h, m, s;
	clock2.getTime(h, m, s);
	cout << "Retrieving clock2 time" << endl;
	cout << "Hour: " << h << endl;
	cout << "Minute: " << m << endl;
	cout << "Second: " << s << endl;
}
