#include <iostream>
#include <stdlib.h>
#include <time.h>

double chance_of_getting_right_seat(int passenger, int total_passengers);

int main() {
	srand(time(NULL));
	int n = 100;
	int rounds = 10000000;
	int passenger_gets_right_seat[n];
	for(int i = 0; i < n; i++) { //Initialize array
		passenger_gets_right_seat[i] = 0;
	}
	for(int round = 0; round < rounds; round++) {
		int seats[n];
		for(int i = 0; i < n; i++) { //Initialize array
			seats[i] = -1;
		}

		seats[rand() % n] = 0;
		for(int passenger = 1; passenger < n; passenger++) {
			if(seats[passenger] != -1) {
				int seat = rand() % n;
				while(seats[seat] != -1) {
					seat = rand() % n;
				}
				seats[seat] = passenger;
			} else {
				seats[passenger] = passenger;
			}
		}

		for(int i = 0; i < n; i++) {
			if(seats[i] == i) passenger_gets_right_seat[i]++;
		}
	}

	for(int i = 0; i < n; i++) {
		std::cout << "Simulated probability for passenger " << (i + 1) << ":  "
		<< (double)passenger_gets_right_seat[i] / (double)rounds << std::endl;
		std::cout << "Calculated probability for passenger " << (i + 1) << ": "
		<< chance_of_getting_right_seat(i+1, n);
		//This next line is just to get the entire output to appear onto my terminal
		//The if statement can be removed if need be
		if(i < n-1) std::cout << std::endl << std::endl;
	}
}

double chance_of_getting_right_seat(int k, int n) {
	if(k == 1) return 1.0 / n;
	else return (((double)n) + 1 - k) / (((double)n) + 2 - k);
}