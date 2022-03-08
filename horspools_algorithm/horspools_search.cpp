#include <iostream>
#include <cstring>
#include <math.h>
#include <stdlib.h>

//Horspool's Algorithm

//To run the program, type in terminal:
//./a.out < input_file.in
//The input file must have the text, then pattern on a new line.

//GLOBALS
static int number_of_comparisons {0};

//PROTOTYPES

int string_match(char text[], char pattern[]);
bool elements_match(char text[], char pattern[], int start_marker, int end_marker);
void initialize_ascii(int ascii_table[], char pattern[], int p_length);

int main()
{
	char text[1000] = {0};
	char pattern[200] = {0};

	std::cout << "\n\nEnter a string of text." << std::endl;
	std::cin >> text;
	std::cin.ignore(1000, '\n');

	std::cout << "Enter a pattern to search the text for." << std::endl;
	std::cin >> pattern;
	std::cin.ignore(1000, '\n');

	int match = string_match(text, pattern);

	if (match == -1)
		std::cout << "\nNo match! Sorry!";
	else
		std::cout << "\nStarting index: " << match;

	std::cout << "\nNumber of comparisons: " << number_of_comparisons << std::endl << std::endl;

	return 0;
}

//General horspool's function
int string_match(char text[], char pattern[])
{
	int t_length = strlen(text);			
	int p_length = strlen(pattern);

	int ascii_table[128];	

	initialize_ascii(ascii_table, pattern, p_length);

	int diff = p_length - 1;	//last spot in the pattern array and amount used to calculate return index if match is found.
	int start_marker = diff;	//End of pattern comparison
	int match_start = -1;

	while (start_marker < t_length)
	{
		++number_of_comparisons;
		if (text[start_marker] == pattern[diff] && 
				elements_match(text, pattern, start_marker - diff, start_marker))	//If the last pattern element matches, check if the whole pattern matches the current text slot.
		{
			match_start = start_marker - diff;																	//If it does, end the loop and calculate the first index of word in text to return.
			start_marker = t_length;
		}

		start_marker += ascii_table[text[start_marker]];											//If it doesn't, add the value of the start_marker's character in the ascii table to start_marker.
	}
	
	return match_start;
}



//Check if the substring of text matches the pattern.
bool elements_match(char text[], char pattern[], int start, int end)
{
	int i = start, j = 0;	//Start i at the first element of the text substring, start j at pattern's 0.

	while (i < end)
	{
		++number_of_comparisons;
		if (text[i] != pattern[j]) return false;
		
		++i, ++j;
	}
	
	return true;
}


//Initialize the ascii table with the correct pattern values.
void initialize_ascii(int ascii_table[], char pattern[], int p_length)
{
	for (int i = 0; i < 128; ++i)
		ascii_table[i] = p_length;

	int pattern_val = p_length - 1;	//number to set the pattern's characters' values to. This will be used to get how much the start_marker should move.

	for (int i = 0; i < p_length - 1; ++i, --pattern_val)	//Fill from 0-length-1 in decreasing integers.
	{
		ascii_table[pattern[i]] = pattern_val;
	}

}

