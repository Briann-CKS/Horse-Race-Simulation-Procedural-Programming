//HorseRace.cpp

#include <iostream>
#include <cstdlib>
#include <time.h>

const int TrackLength = 15;

char horse0[TrackLength], horse1[TrackLength], horse2[TrackLength], horse3[TrackLength], horse4[TrackLength];

int horse0_defpos=0, horse1_defpos=0, horse2_defpos=0, horse3_defpos=0, horse4_defpos=0;

void print_Track (char horseArr[], int position, char num);
int coin_flip ();
int start_race ();

int main()
{
	int seed;
	int winner;
	std::cout << "Please enter a random seed: ";
	std::cin >> seed;
	srand(seed);
	
	print_Track (horse0, horse0_defpos, '0');
	print_Track (horse1, horse1_defpos, '1');
	print_Track (horse2, horse2_defpos, '2');
	print_Track (horse3, horse3_defpos, '3');
	print_Track (horse4, horse4_defpos, '4');
	std::cout << "\n" << std:: endl;

	winner = start_race();

	std::cout << "Horse " << winner << " wins!\n" << std::endl;

	return 0;
}


void print_Track (char horseArr[], int position, char num)
{
	int j=0;
	for (int i=0; i < position; i++)
	{
		horseArr[i] = '.';
		j++;
	}

	horseArr[j] = num;
	j++;

	for (int i=0; i < (TrackLength-position-1); i++)
	{
		horseArr[j] = '.';
		j++;
	}
 
	for (int i=0; i < TrackLength; i++)
	{
		std::cout << horseArr[i];
	}

	std::cout << std::endl;
}


int coin_flip ()
{
	int coin = rand() % 2;
	if (coin == 1)
	{
		return 1;
	}
	else 
	{
		return 0;
	} 
}

int start_race()
{
	int winner = 0;
	bool not_end = true;
	while (not_end)
	{
		if (coin_flip() == 1)
		{
			horse0_defpos++;
		}

		if (coin_flip()==1)
        	{
           		horse1_defpos++;
        	}

		if (coin_flip()==1)
        	{
			horse2_defpos++;
        	}

        	if (coin_flip()==1)
        	{
			horse3_defpos++;
        	}

	        if (coin_flip()==1)
		{
			horse4_defpos++;
		}

		
		print_Track (horse0, horse0_defpos, '0');
		print_Track (horse1, horse1_defpos, '1');
		print_Track (horse2, horse2_defpos, '2');
		print_Track (horse3, horse3_defpos, '3');
		print_Track (horse4, horse4_defpos, '4');
		std::cout << "\n" << std::endl; 

		if (horse0_defpos == 15)
		{
            		not_end = false;
            		return winner = 0;
        	}
        	else if (horse1_defpos == 15)
        	{
            		not_end = false;
            		return winner = 1;
        	}
        	else if (horse2_defpos == 15)
        	{
            		not_end = false;
            		return winner = 2;
        	}
        	else if (horse3_defpos == 15)
        	{
            		not_end = false;
            		return winner = 3;
        	}
        	else if (horse4_defpos == 15)
        	{
            		not_end = false;
            		return winner = 4;
        	}
        	else
        	{
            		continue;
        	}
    	}
   	 return winner;
}

