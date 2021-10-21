#pragma once
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <conio.h>
#include <thread>
#include "Clock24.h"

//Author: David Robey
//Last updated: 9/16/2021 @ 11:16am
// prints controls
void printInstructions() {
	std::cout << "*************************" << std::endl;
	std::cout << std::left;
	std::cout << "*" << std::setw(23) << "1 - Adds an hour" << "*" << std::endl;
	std::cout << "*" << std::setw(23) << "2 - Adds a minute" << "*" << std::endl;
	std::cout << "*" << std::setw(23) << "3 - Adds a second" << "*" << std::endl;
	std::cout << "*" << std::setw(23) << "4 - Exits the program" << "*" << std::endl;
	std::cout << "*************************" << std::endl;
}
int main(int argc, char** argv){
	int cnt = 100;
	//retrieves local time
	std::time_t time = std::time(nullptr);
	std::tm tm = {};
	localtime_s(&tm, &time);
	//passes local time to variables
	int s = tm.tm_sec;
	int m = tm.tm_min;
	int h = tm.tm_hour;
	// intializes clock with variables s,m,h
	Clock24 clock(s, m, h);
	bool shouldExit = false;
	//run loop
	while (!shouldExit){
		//checks if key was pressed
		if (_kbhit() != 0){
			// Gets the key pressed and saves it into key
			//note... the longer you hold down a key, the more it changes the time.
			char key = _getch();
			if (key == '1') { //adds hour
				clock.addHour();
			}
			else if (key == '2'){//adds minute
				clock.addMinute();
			}
			else if (key == '3'){//adds second
				clock.addSecond();
			}
			else if (key == '4'){//exits loop
				shouldExit = true;
			}
		}
		//checks if cnt reaches 100 which makes it 1 second.
		if (cnt++ >= 100){
			// One second has passed.
			cnt = 0; //resets cnt to 0
			system("CLS"); //clears screen
			clock.updateClock();
			clock.printTime(); 
			printInstructions();
		}
		//sleeps the program for 10 milliseconds
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	return 0;
}
