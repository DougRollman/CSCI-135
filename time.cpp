// time.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

enum Genre { ACTION, COMEDY, DRAMA, ROMANCE, THRILLER };

class Time
{
public:
	int h;
	int m;

private:

};

class Movie {
public:
	string title;
	Genre genre;     // only one genre per movie
	int duration;    // in minutes
};

class TimeSlot {
public:
	Movie movie;     // what movie
	Time startTime;  // when it starts
};




void printMovie(Movie mv) {
	string g;
	switch (mv.genre) {
	case ACTION: g = "ACTION"; break;
	case COMEDY: g = "COMEDY"; break;
	case DRAMA: g = "DRAMA";  break;
	case ROMANCE: g = "ROMANCE"; break;
	case THRILLER: g = "THRILLER"; break;
	}
	cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

int minutesSinceMidnight(Time time) {
	int mins = ((time.h % 24) * 60) + time.m;
	return mins;
}
int minutesUntil(Time earlier, Time later) {
	int early = minutesSinceMidnight(earlier);
	int late = minutesSinceMidnight(later);
	int minutesUntil = late - early;
	return minutesUntil;
}



Time addMinutes(Time time0, int min) {
	int timeInMins = minutesSinceMidnight(time0);
	int tempTime = timeInMins + min;
	Time newTime;
	newTime.h = tempTime / 60;
	newTime.m = tempTime % 60;
	return newTime;
}
void printTimeSlot(TimeSlot ts) {
	int duration = ts.movie.duration;
	Time endTime = addMinutes(ts.startTime, duration);
	printMovie(ts.movie);
	cout << " [starts at " << ts.startTime.h << ':' << ts.startTime.m << ", ends by " << endTime.h << ":" << endTime.m << "]";

}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
	int duration = ts.movie.duration;
	Time newTime = addMinutes(ts.startTime, duration);
	TimeSlot newSlot;
	newSlot.startTime = newTime;
	newSlot.movie = nextMovie;
	return newSlot;
}
bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
	bool flag = true;
	int ts1Start = minutesSinceMidnight(ts1.startTime);
	int ts2Start = minutesSinceMidnight(ts2.startTime);
	if (ts1Start > ts2Start) {
		//ts2 starts first
		if ((ts2Start + ts2.movie.duration) > ts1Start) {
			flag = true;
		}
		else {
			flag = false;
		}
	}
	if (ts2Start > ts1Start) {
		//ts1 starts first
		if ((ts1Start + ts1.movie.duration) > ts2Start) {
			flag = true;
		}
		else {
			flag = false;
		}
	}
	return flag;
}
int main()
{
	Movie movie1 = { "Back to the Future", COMEDY, 116 };
	Movie movie2 = { "Black Panther", ACTION, 134 };
	Movie movie3 = { "Frozen", COMEDY, 128 };
	Movie movie4 = { "Se7en" , THRILLER, 118 };

	TimeSlot morning = { movie1, {9, 15} };
	TimeSlot daytime = { movie2, {12, 15} };
	TimeSlot evening = { movie2, {16, 45} };
	TimeSlot night = {movie4, {19, 01} };
	TimeSlot midday = { movie3, {5, 25} };

	cout << movie2.genre;
	/*
	* Expected Output
	Enter first time:  10 30
	Enter second time: 13 40

	These moments of time are X and Y minutes after midnight.
	The interval between them is Z minutes.
	*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
