#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
	/* Deaths:
	 * Ocean (x or y > 10 || x or y < -10)
	 * Cannibal Village
	 * Thirst (thirstLevel > 100)
	 * Starvation (steps > 300)
	 */
	/* Places:
	 * Cannibal Village (x=2, y=-4)
	 * Spring [thirstLevel = 0] (x=-3, y=-3)
	 * Origin (x=0, y=0)
	 * Airport (x=6, y=7)
	 */
	srand(time(NULL));
	int rounds = 1000000;

	int drowned = 0;
	int eaten = 0;
	int thirst = 0;
	int starvation = 0;
	int successes = 0;
	int successfulSteps = 0;
	for(int i = 0; i < rounds; i++)
	{
		int xPos = 0;
		int yPos = 0;
		int thirstLevel = 0;
		int steps;
		bool dead = false;

		for(steps = 0; steps < 300; steps++)
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

			thirstLevel++;
			if(xPos == -3 && yPos == -3) { //Made it to the spring
				thirstLevel = 0;
			}

			if(xPos > 10 || yPos > 10 || xPos < -10 || yPos < -10) { //Drowned in the Ocean
				drowned++;
				dead = true;
			} else if(xPos == 2 && yPos == -4) { //Killed by cannibals
				eaten++;
				dead = true;
			}
			if(thirstLevel > 100) { //Died of thirst
				thirst++;
				dead = true;
			}
			if(dead || (xPos == 6 && yPos == 7)) { //Break from simulation if dead or made it to airport
				break;
			}
		}
		if(steps == 300) {
			starvation++;
			dead = true;
		}

		if(!dead) {
			successes++;
			successfulSteps += steps;
		}
	}
	std::cout << "Successes: " << (double)successes / (double)rounds << std::endl;
	std::cout << "Average steps for success: " << (double)successfulSteps / (double)successes << std::endl;
	std::cout << "Death by thirst: " << (double)thirst / (double)rounds << std::endl;
	std::cout << "Death by cannibals: " << (double)eaten / (double)rounds << std::endl;
	std::cout << "Death by drowning: " << (double)drowned / (double)rounds << std::endl;
	std::cout << "Death by starvation: " << (double)starvation / (double)rounds << std::endl;
	return 0;
}