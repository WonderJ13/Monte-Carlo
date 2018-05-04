#include <iostream>
#include <stdlib.h>
#include <time.h>

bool aboutToDrown(int, int);

int main(int argc, char** argv)
{
	/* Deaths:
	 * Starvation (hunger > 60)
	 * Boredom (steps > 80)
	 */
	/* Places:
	 * Pizza Hut (x=-3, y=-5)
	 * Bank (x=-5, y=-2)
	 * Lake (Rect from (x=4, y=5) to (x=9, y=9))
	 * Origin (x=0, y=0)
	 * Airport (x=9, y=-2)
	 */

	srand(time(NULL));
	int rounds = 1000000;

	int starvation = 0;
	int boredom = 0;
	int bankEntrances = 0;
	int pizzaHutEntrances = 0;
	int successes = 0;
	int successfulSteps = 0;
	for(int i = 0; i < rounds; i++)
	{
		int xPos = 0;
		int yPos = 0;
		int hunger = 0;
		bool cash = false;
		bool dead = false;
		bool gotCash = false;
		bool pizzaAte = false;

		int steps;

		for(steps = 0; steps < 80; steps++)
		{
			int dir = rand() % 4;
			if(dir == 0) { //North
				yPos++;
			} else if(dir == 1) { //East
				xPos++;
			} else if(dir == 2) { //South
				yPos--;
			} else { //West
				xPos--;
			}

			//If man is about to drown in ocean or lake
			if(aboutToDrown(xPos, yPos)) {
				int xNew = xPos;
				int yNew = yPos;
				while(aboutToDrown(xNew, yNew)) {
					xNew = xPos;
					yNew = yPos;
					int newDir = rand() % 4;
					if(newDir == 0) { //North
						yNew++;
					} else if(newDir == 1) { //East
						xNew++;
					} else if(newDir == 2) { //South
						yNew--;
					} else { //West
						xNew--;
					}
				}
				xPos = xNew;
				yPos = yNew;
			}

			if(xPos == -5 && yPos == -2) { //At the bank
				cash = true;
				gotCash = true;
			}

			if(xPos == -3 && yPos == -5 && cash) { //At the Pizza Hut
				cash = false;
				pizzaAte = true;
				hunger = 0;
			}

			if(hunger > 60) {
				dead = true;
				starvation++;
			}

			if(dead || (xPos == 9 && yPos == -2)) { //Break from simulation if dead or made it to airport
				break;
			}
			hunger++;
		}
		if(steps >= 80) {
			boredom++;
			dead = true;
		}

		if(!dead) {
			successes++;
			successfulSteps += steps;
		}

		if(pizzaAte) {
			pizzaHutEntrances++;
		}

		if(gotCash) {
			bankEntrances++;
		}
	}
	std::cout << "Successes: " << (double)successes / (double)rounds << std::endl;
	std::cout << "Average steps for success: " << (double)successfulSteps / (double)successes << std::endl;
	std::cout << "Death by boredom: " << (double)boredom / (double)rounds << std::endl;
	std::cout << "Death by starvation: " << (double)starvation / (double)rounds << std::endl;
	std::cout << "Rate of getting cash: " << (double)bankEntrances / (double)rounds << std::endl;
	std::cout << "Rate of getting pizza: " << (double)pizzaHutEntrances / (double)rounds << std::endl;
	return 0;
}

bool aboutToDrown(int x, int y) {
	return (x > 10 || y > 10 || x < -10 || y < -10 || (x > 4 && x < 9 && y > 5 && y < 9));
}