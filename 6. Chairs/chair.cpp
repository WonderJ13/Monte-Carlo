#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

int main()
{
	srand(time(NULL));
	int games = 100000;
	for(int players = 2; players <= 20; players++)//Number of starting players
	{
		int wins[players];
		for(int j = 0; j < players; j++)//Initialize to 0
		{
			wins[j] = 0;
		}
		for(int j = 0; j < games; j++)//Games
		{
			std::vector<int> old_chairs;
			for(int k = 0; k < players; k++)//Initialize player IDs
			{
				old_chairs.push_back(k);
			}
			for(int remaining_chairs = players-1; remaining_chairs > 0; remaining_chairs--)//Number of new chairs
			{
				std::vector<int> new_chairs;
				for(int l = 0; l < remaining_chairs; l++)//Initialize unoccupied chairs
				{
					new_chairs.push_back(-1);
				}
				for(int chair = 0; chair < remaining_chairs+1; chair++)//For each chair
				{
					if(old_chairs[chair] == -1) continue;//Skip if it's unnocupied
					int chair_index = chair;
					if(chair == 0) {//Left-most can only go right
						//Do Nothing
					}
					else if(chair == remaining_chairs) {//Right-most can only go left
						chair_index--;
					}
					else {//Middle has a choice
						int dir = rand() % 2;
						if(dir == 0) chair_index--;
					}
					if(new_chairs[chair_index] == -1)//If decided chair happens to be unoccupied
					{
						new_chairs[chair_index] = old_chairs[chair];
					}
					else //Fight for the chair
					{
						int chance = rand() % 2;
						if(chance == 0) new_chairs[chair_index] = old_chairs[chair];
					}
				}
				old_chairs = new_chairs;//Reset
			}
			wins[old_chairs[0]]++;//old_chairs should have size 1 with the person in that chair being the winner
		}
		std::cout << "Stats for game with " << players << " players..." << std::endl;
		for(int j = 0; j < players; j++)
		{
			std::cout << "Player " << j+1 << " win rate: " << 100*(double)wins[j] / games << "%" << std::endl;
		}
		std::cout << std::endl;
	}
	system("pause");
}
