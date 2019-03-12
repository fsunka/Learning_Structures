/* Sunka Unit7_Program1 2-18-19
Dr McMillan COSC 1436-57004 Spring 2019
Write a program that will create an event structure and initializes all of its fields with data. 
Dates and times do not need to be current but need to be valid date and times. */
#include <iostream>
#include <string>
#include <iomanip> // to handle the leading zeros
using namespace std;

struct timeOfDay{
	short int Hour;
	short int Minute;
	short int Second;	
};

struct appDate{
	short int dayOfMonth;
	short int month;
	short int year;
};

struct event{
	string eventName;
	timeOfDay eventTime;
	appDate eventDate;
	bool isUrgent;
};

void printTimeOfDay(timeOfDay &t)
{
	cout << "Time:\t\t" << setw(2) << setfill('0') << t.Hour << ":" << setw(2) << setfill('0') << t.Minute << ":" << setw(2) << setfill('0') << t.Second << endl;
}

void printAppDate(appDate &a)
{
	cout << "Date:\t\t" << setw(2) << setfill('0') << a.month << "/" << setw(2) << setfill('0') << a.dayOfMonth << "/" << a.year << endl;
}

void printEvent(event &e)
{
	cout << "\nEvent Name:\t" << e.eventName << endl;
	printAppDate(e.eventDate);
	printTimeOfDay(e.eventTime);
	if(e.isUrgent)
	{
		cout << "Urgent?\t\tYes!" << endl;
	}
	else
	{
		cout << "Urgent?\t\tNo" << endl;
	}
}

int main()
{
	event today = {"President's Day", {2, 53, 0}, {18, 2, 2019}, true};
	printEvent(today); //print event info
	
	return 0;
}
