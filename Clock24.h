#pragma once
#include<iostream>
#include<iomanip>
//Author: David Robey
//Last updated: 9/16/2021 @ 11:16am
class Clock24 {
private:
	// private variables
	int seconds = 0;
	int minutes = 0;
	int hours = 0;

public: // I like to seperate constructors from functions with a seperate public call
	Clock24(int x, int y, int z);
	// can add more constructors in the future.
public:
	void addSecond();
	void addMinute();
	void addHour();
	// prints for 24 hour clock
	void printTime();
	//handles update of clock
	void updateClock();
};