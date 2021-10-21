#pragma once
#include <iostream>
#include <iomanip>

#include "Clock24.h"
//Author: David Robey
// Last updated: 9/16/2021 @ 11:16am
// I like to seperate constructors from functions with a seperate public call
	Clock24::Clock24(int x, int y, int z) { //constructor for clock class. (seconds, minutes, hours)
		seconds = x;
		minutes = y;
		hours = z;
	};
	// can add more constructors in the future.

	void Clock24::addSecond() { //adds seconds
		if (seconds < 59) {
			seconds++;
		}
		else {
			seconds = 0;
			addMinute();
		}
	}
	void Clock24::addMinute() {//adds minutes
		if (minutes < 59) {
			minutes++;
		}
		else {
			minutes = 0;
			addHour();
		}
	}
	void Clock24::addHour() {//adds hours
		if (hours < 23) {
			hours++;
		}
		else {
			hours = 0;
		}
	}
	// prints for 24 hour clock
	void Clock24::printTime() {
		// 24 hour printing only
		std::cout << "*******************" << std::endl;
		std::cout << "*  24 hour clock  *" << std::endl;
		std::cout << std::right;
		std::cout << "*" << std::setw(4);
		std::cout << std::setw(4) << hours;
		std::cout << std::setw(1) << ":";
		std::cout << std::setw(2) << minutes;
		std::cout << std::setw(1) << ":";
		std::cout << std::setw(2) << seconds;
		std::cout << std::setw(8) << std::right << "*" << std::endl;
		std::cout << "*******************" << std::endl;
		// begins the wonky printing for 12 hour clock.
		bool pm;// used to tell if its am or pm
		if (hours >= 12) {
			pm = true;
		}
		else {
			pm = false;
		}
		if (pm == false) { //checks if PM
			std::cout << std::left;
			std::cout << "*******************" << std::endl;
			std::cout << "*  12 hour clock  *" << std::endl;
			//if hours is at 0, it forces a 12.
			if (hours == 0) {
				std::cout << std::right;
				std::cout << "*" << std::setw(4);
				std::cout << std::setw(4) << hours + 12;
				std::cout << std::setw(1) << ":";
				std::cout << std::setw(2) << minutes;
				std::cout << std::setw(1) << ":";
				std::cout << std::setw(2) << seconds;
				std::cout << std::setw(8) << std::right << "*" << std::endl;
			}
			else {// else its just normal AM
				std::cout << std::right;
				std::cout << "*" << std::setw(4);
				std::cout << std::setw(4) << hours;
				std::cout << std::setw(1) << ":";
				std::cout << std::setw(2) << minutes;
				std::cout << std::setw(1) << ":";
				std::cout << std::setw(2) << seconds;
				std::cout << std::setw(8) << std::right << "*" << std::endl;
			}
			std::cout << "*******************" << std::endl;
		}
		else if (pm == true) {// checks if it is pm
			std::cout << std::left;
			std::cout << "*******************" << std::endl;
			std::cout << "*  12 hour clock  *" << std::endl;
			//for 12 hour clock it checks  if hours is over 12 and if so resets it to 1
			std::cout << std::right;
			std::cout << "*" << std::setw(4);
			//sets it back 12 hours and places a PM at the end
			if (hours > 12) {
				std::cout << std::setw(4) << hours - 12;
			}
			else { //if it is 12:00:00 it doesn't set back by 12. 
				std::cout << std::setw(4) << hours;
			}
			std::cout << std::setw(1) << ":";
			std::cout << std::setw(2) << minutes;
			std::cout << std::setw(1) << ":";
			std::cout << std::setw(2) << seconds;
			std::cout << "PM";
			std::cout << std::setw(6) << "*" << std::right << std::endl;
			std::cout << "*******************" << std::endl;
		}
	}
	//handles update of clock
	void Clock24::updateClock() {
		if (seconds < 59) {
			addSecond();
		}
		else if (minutes < 59) {
			seconds = 0; //resets seconds to 0 at 60
			addMinute();
		}
		else if (hours < 24) {
			minutes = 0; //resets minutes to 0 after 60
			addHour();
		}
		else {
			hours = 0; // after hours reaches 24 it resets
		}
	}

