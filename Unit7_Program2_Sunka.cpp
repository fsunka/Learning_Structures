/* Sunka Unit7_Program2 2-18-19
Dr McMillan COSC 1436-57004 Spring 2019

Using program1 as a guide, develop separate functions for each structure that will display the values in the structure. 
Then develop an additional function will display all the values for each entity in the event structure – using the results from the separate functions.
Run the program with a populated structure and display the results.

*/
#include <iostream>
#include <string>
#include <iomanip> // to handle the leading zeros
#include "Input_Validation_Extended.h"
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

void changeTimeOfDay(timeOfDay &t)
{
	cout << "Hour (24 hour format): ";
	t.Hour = validateShort(t.Hour);
	while(t.Hour <0 || t.Hour > 23)
	{
		cout << "Invalid entry. Try again. Hour: ";
		t.Hour = validateShort(t.Hour);
	}	
	cout << "Minutes: ";
	t.Minute = validateShort(t.Minute);
	while(t.Minute <0 || t.Minute > 59)
	{
		cout << "Invalid entry. Try again. Minutes: ";
		t.Minute = validateShort(t.Minute);
	}	
	cout << "Second: ";
	t.Second = validateShort(t.Second);
	while(t.Second <0 || t.Second > 59)
	{
		cout << "Invalid entry. Try again. Second: ";
		t.Second = validateShort(t.Second);
	}
	
}

void changeAppDate(appDate &a)
{
	cout << "\nDay of Month: ";
	a.dayOfMonth = validateShort(a.dayOfMonth);
	while(a.dayOfMonth < 1 || a.dayOfMonth > 31)
	{
		cout << "Invalid entry. Try again. Day of Month: ";
		a.dayOfMonth= validateShort(a.dayOfMonth);
	}
	cout << "Month: ";
	a.month = validateShort(a.month);
	while(a.month < 1 || a.month > 12)
	{
		cout << "Invalid entry. Try again. Month: ";
		a.month = validateShort(a.month);
	}
	cout << "Year: ";
	a.year = validateShort(a.year);
	
}

void changeEvent(event &e)
{
	char urgency = '\0';
	
	cout << "\nNew Event Name: ";
	getline(cin, e.eventName);
	changeAppDate(e.eventDate);
	changeTimeOfDay(e.eventTime);
	cout << "\nIs it urgent? (y/n) ";
	urgency = validateChar(urgency);
	if(urgency == 'y' || urgency == 'Y')
	{
		e.isUrgent = true;
	}
	else
	{
		e.isUrgent = false;
	}
	
}

int main()
{
	event today = {"President's Day", {2, 53, 0}, {18, 2, 2019}, true};
	
	printEvent(today); //print before
	changeEvent(today); //ask for changes
	printEvent(today); // print after
	
	return 0;
}
