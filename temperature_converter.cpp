#include <iostream>
using namespace std;

void convertToCelsius(double temp, char scale) {
	if (scale == 'F' || scale == 'f') {
		double celsius = (temp - 32) * 5.0 / 9.0;
		cout << temp << " degrees Fahrenheit is " << celsius << " degrees Celsius." << endl;
	}
	else if (scale == 'K' || scale == 'k') {
		double celsius = temp - 273.15;
		cout << temp << " degrees Kelvin is " << celsius << " degrees Celsius." << endl;
	}
	else {
		cout << "Invalid scale. Please use 'F' for Fahrenheit or 'K' for Kelvin." << endl;
	}
}

void converToFahrenheit(double temp, char scale) {
	if (scale == 'C' || scale == 'c') {
		double fahrenheit = (temp * 9.0 / 5.0) + 32;
		cout << temp << " degrees Celsius is " << fahrenheit << " degrees Fahrenheit." << endl;
	}
	else if (scale == 'K' || scale == 'k') {
		double fahrenheit = (temp - 273.15) * 9.0 / 5.0 + 32;
		cout << temp << " degrees Kelvin is " << fahrenheit << " degrees Fahrenheit." << endl;
	}
	else {
		cout << "Invalid scale. Please use 'C' for Celsius or 'K' for Kelvin." << endl;
	}
}

void convertToKelvin(double temp, char scale) {
	if (scale == 'C' || scale == 'c') {
		double kelvin = temp + 273.15;
		cout << temp << " degrees Celsius is " << kelvin << " degrees Kelvin." << endl;
	}
	else if (scale == 'F' || scale == 'f') {
		double kelvin = (temp - 32) * 5.0 / 9.0 + 273.15;
		cout << temp << " degrees Fahrenheit is " << kelvin << " degrees Kelvin." << endl;
	}
	else {
		cout << "Invalid scale. Please use 'C' for Celsius or 'F' for Fahrenheit." << endl;
	}
}

int main() {
	double temperature;
	char scale;
	char choice;
	cout << "Welcome to the Temperature Converter!" << endl;
	cout << "Enter 'C' for Celsius, 'F' for Fahrenheit, or 'K' for Kelvin: " << endl;
	do {
		cout << "Enter the temperature scale you want to convert from: ";
		cin >> scale;
		cout << "Enter the temperature: ";
		cin >> temperature;

		switch (scale) {
		case 'C':
		case 'c':
			converToFahrenheit(temperature, scale);
			convertToKelvin(temperature, scale);
			break;
		case 'F':
		case 'f':
			convertToCelsius(temperature, scale);
			convertToKelvin(temperature, scale);
			break;
		case 'K':
		case 'k':
			convertToCelsius(temperature, scale);
			converToFahrenheit(temperature, scale);
			break;
		default:
			cout << "Invalid scale. Please use 'C', 'F', or 'K'." << endl;
		}
		cout << "Do you want to convert another temperature? (Y/N): ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');
	cout << "Thank you for using the Temperature Converter!" << endl;
	return 0;
}
