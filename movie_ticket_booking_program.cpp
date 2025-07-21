#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Movie
{
	string title;
	double price;
};

void displayMovies(const vector<Movie>& movies)
{
	cout << "Available Movies:\n";
	for (int i = 0; i < movies.size(); i++)
	{
		cout << i + 1  <<". "<< movies[i].title << " -  $" << movies[i].price << endl;
	}
	
}

int main() {
	vector <Movie> movies = {
		{"Inception", 12.99},
		{"The Matrix", 9.99},
		{"Interstellar", 14.99},
		{"The Godfather", 15.99}
	};
	int movieChoice, numberOfTickets;
	double totalCost;

	cout << "Welcome to the Movie Ticket Booking System!\n";
	displayMovies(movies);

	cout << "Please select a movie by entering the corresponding number: ";
	cin >> movieChoice;

	if (movieChoice < 1 || movieChoice > movies.size()) {
		cout << "Invalid choice. Exiting the program.\n";
		return 0;
	}


	cout << "Enter the number of tickets you want to purchase: ";
	cin >> numberOfTickets;

	if (numberOfTickets <= 0) {
		cout << "Invalid number of tickets. Exiting the program.\n";
		return 0;
	}

	totalCost = movies[movieChoice - 1].price * numberOfTickets;

	cout << "\nBooking Details:\n";
	cout << "Movie: " << movies[movieChoice - 1].title << endl;
	cout << "Number of Tickets: " << numberOfTickets << endl;
	cout << "Total Cost: $" << totalCost << endl;

	cout << "Thank you for your purchase!\n";

	return 0;
}

