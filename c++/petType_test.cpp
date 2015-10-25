#include <iostream>
#include "petType.h"
#include "dogType.h"
using namespace std;

void callPrint(petType& p);

int main() {
	petType pet("Lucky");
	dogType dog("Tommy", "German Shepherd");

	pet.print();
	cout << endl;
	dog.print();

	cout << "*** Calling the function callPrint ***" << endl;
	callPrint(pet);
	cout << endl;
	callPrint(dog);
	return 0;
}

void callPrint(petType& p) {
	p.print();
}
