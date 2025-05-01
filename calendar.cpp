#include <iostream>
#include <iomanip>

using namespace std;

int getStartDay(int month, int year) {
	int day = 1;
	int m[] = { 0,3,2,5,0,3,5,1,4,6,2,4 };
	if (month < 3) {
		year--;
	}
	return (year + year / 4 - year / 100 + year / 400 + m[month - 1] + day) % 7;
}

void printCalendar(int month, int year) {
	string months[] = { "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December" };
	int daysInMonth[] = { 31, (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28, 31, 30, 31, 30,	
		31, 31, 30, 31, 30, 31 };
	int startDay = getStartDay(month, year);
	cout << "Calendar for " << months[month - 1] << " " << year << endl;
	cout << "Su Mo Tu We Th Fr Sa" << endl;
	for (int i = 0; i < startDay; i++) {
		cout << "   ";
	}
	for (int day = 1; day <= daysInMonth[month - 1]; day++) {
		cout << setw(2) << day << " ";
		if ((day + startDay) % 7 == 0) {
			cout << endl;
		}
	}
}

int main() {
	int month, year;
	cout << "Enter month (1-12): ";
	cin >> month;
	cout << "Enter year: ";
	cin >> year;
	printCalendar(month, year);
	return 0;
}
