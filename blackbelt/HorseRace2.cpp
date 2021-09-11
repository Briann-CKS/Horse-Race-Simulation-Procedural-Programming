//HorseRace.cpp

#include <iostream>
#include <cstdlib>
#include <time.h>

//Declare and initialize constant variable
const int TrackLength = 15;

//Declare and initalize the initial position of each horse to zero
int horse0_defpos=0, horse1_defpos=0, horse2_defpos=0, horse3_defpos=0, horse4_defpos=0;

//Declare functions used for this horse race program
// print_Track function to print the horse tracks by taking the horse array passed by reference, position and horse number as its parameters
void print_Track (char horseArr[], int position, char num);

// A function to determine whether the horse will move forward or remain in its original position
int coin_flip();

// A function to start the race and make changes in the horses' position with horse array passed by reference
int start_race (char horseArr0[], char horseArr1[], char horseArr2[], char horseArr3[], char horseArr4[]); 

// Start main function
int main()
{
	//Declare the character array for each horse in main function
	char horse0[TrackLength], horse1[TrackLength], horse2[TrackLength], horse3[TrackLength], horse4[TrackLength];
	int seed; // Declare seed 
	int winner; // Declare winner 
	std::cout << "Please enter a random seed: "; // Prompt user to input seed number
	std::cin >> seed; // Get seed number from user
	srand(seed); // Use the seed number in the srand function
	
	// Call the start_race function and the horse winner is returned
	winner = start_race(horse0, horse1, horse2, horse3, horse4);

	// Print out the horse winner
	std::cout << "Horse " << winner << " wins!\n" << std::endl;

	return 0;
} // End main function

// Start print_Track function
void print_Track (char horseArr[], int position, char num)
{
	int j=0; // Delare and initialize j to keep track of the element in each character array 
	
	// Use a for loop to run through the array until it reaches the current position of the horse 
	for (int i=0; i < position; i++)
	{
		horseArr[i] = '.'; // Put . into the array before arriving at the position of the horse in the track 
		j++;
	}
		
	horseArr[j] = num; // Put the number of the horse at its current position
	j++;

	// Use a for loop to run through the array after it passes the position of the horse
	for (int i=0; i < (TrackLength-position-1); i++)
	{
		horseArr[j] = '.'; // Put . into the array after the position of the horse in the track
		j++;
	}
 
	// Use a for loop to run through each element of the array
	for (int i=0; i < TrackLength; i++)
	{
		std::cout << horseArr[i]; // Print each element of the array out, which is basically the track of the horse
	}

	std::cout << std::endl;
} // End print_Track function

// Start coin_flip function
int coin_flip ()
{
	int coin = rand() % 2; // Initialize the coin to be an integer with value of either 1 or 0
	if (coin == 1) // If the value is 1, return 1
	{
		return 1;
	}
	else // If the value is 0, return 0
	{
		return 0;
	} 
} // End coin_flip function

// Start start_race function
int start_race (char horseArr0[], char horseArr1[], char horseArr2[], char horseArr3[], char horseArr4[])
{
	int winner = 0; // Declare winner integer
	bool not_end = true; // A boolean variable is declare for the while loop 
	while (not_end) // Run the while loop as long as the not_end variable is still true
	{
		// Increment the position of each horse by 1 if the coin_flip function returns 1, and do nothing if the function returns 0
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

		//Print the track of each horse
		print_Track (horseArr0, horse0_defpos, '0');
		print_Track (horseArr1, horse1_defpos, '1');
		print_Track (horseArr2, horse2_defpos, '2');
		print_Track (horseArr3, horse3_defpos, '3');
		print_Track (horseArr4, horse4_defpos, '4');
		std::cout << "\n" << std::endl; 

		// If any of the horses reaches the end point of the track first, the not_end variable will become false, and the horse number is returned as the winner of this race
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
            		continue; // If none of the horses reaches the end point yet, continue running the while loop
        	}
    	}
   	 return winner;
} // End start_race function

