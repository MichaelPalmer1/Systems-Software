/* Michael Palmer
 * CSCI 3232
 * February 11, 2015
 */

#include <iostream>
#include "clockType.h"
using namespace std;

void clockType::setTime(int hours, int minutes, int seconds) {
	if (hours >= 0 && hours < 24) {
		hr = hours;
	}
	if (minutes >= 0 && minutes < 60) {
		min = minutes;
	}
	if (seconds >= 0 && seconds < 60) {
		sec = seconds;
	}
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const {
	hours = hr;
	minutes = min;
	seconds = sec;
}

void clockType::printTime() const {
	cout << hr << ":" << min << ":" << sec << endl;
}

void clockType::incrementSeconds() {
	if(sec == 59) {
		sec = 0;
		incrementMinutes();
	} else {
		sec++;
	}

}

void clockType::incrementMinutes() {
	if(min == 59) {
		min = 0;
		incrementHours();
	} else {
		min++;
	}
}

void clockType::incrementHours() {
	if(hr == 23) {
		hr = 0;
	} else {
		hr++;
	}
}

bool clockType::equalTime(const clockType& otherClock) const {
	int h, m, s;
	otherClock.getTime(h, m, s);
	if(hr == h && min == m && sec == s) {
		return 1;
	}
	return 0;
}

clockType::clockType(int hours, int minutes, int seconds) {
	setTime(hours, minutes, seconds);
}

clockType::clockType() {
	setTime(0, 0, 0);
}
