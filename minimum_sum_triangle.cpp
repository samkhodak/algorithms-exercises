#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

//Dynamic programming exercise for finding the minimum sum of a triangle of numbers.

const int SIZE = 4;

//Prototypes
void display_matrix(int array[][SIZE]);
int memoized_sum(int array[][SIZE], vector<vector<int>> &, int i, int j);
int tabulated_sum(int triangle[][SIZE]);

int main()
{

	int triangle[SIZE][SIZE] = {0};
	vector<vector<int>> path_check(SIZE, vector<int>(SIZE, -1));

	srand(time(NULL));

	//Generate random numbers to fill the array.
	for (int i = 0; i < SIZE; ++i)	
	{
		for (int j = 0; j <= i; ++j)
			triangle[i][j] = rand() % 15;
	}

	display_matrix(triangle);

	cout << "\n\nMemoized min. path sum: " << memoized_sum(triangle, path_check, 0, 0) << endl << endl;
	cout << "\n\nTabulated min. path sum: " << tabulated_sum(triangle) << endl << endl;

		

	return 0;
}

//Display the 'triangle'.	
void display_matrix(int array[][SIZE])
{
	cout << "\n\n";
	for (int i = 0; i < 4; ++i)	
	{
		cout << i << " [ ";

		for (int j = 0; j <= i; ++j)
			cout << array[i][j] << " ";

		cout << "]" << endl;
	}
}


//Memoized attempt. i represents y-axis matrix and j represents x-axis nodes.
int memoized_sum(int triangle[][SIZE], vector<vector<int>> & path_check, int i, int j)
{
	//Base case for if recursion goes past the lowest level
	if (i == SIZE)
		return 0;

	if (path_check[i][j] > -1)
		return path_check[i][j];

	//Minimum sum of this node's path automatically has its own value included.
	int min_sum {triangle[i][j]};	
	
	//Add the smallest of this node's two children path sums to this node's sum.
	min_sum += min(memoized_sum(triangle, path_check, i+1, j), memoized_sum(triangle, path_check, i+1, j+1));
	
	//Update the checking matrix with this node's smallest path sum.
	path_check[i][j] = min_sum;

	return min_sum;
}


//Calculate sums from the bottom up. Saves the double vector space.
int tabulated_sum(int triangle[][SIZE])
{
	
	int sums[SIZE];

	//Fill array with "sums" of bottom row - their own values.
	for (int i = 0; i < SIZE; ++i)
		sums[i] = triangle[SIZE - 1][i];

	//Ending number for row-traversal.
	int k = SIZE - 1;
	//Starting from 2nd-to-last row, calculate path sums and move up a row.
	//This method works on one SIZE array that calculates the smallest sum of its element and itself + 1.
	for (int i = SIZE - 2; i >= 0; --i, --k)	
	{
		for (int j = 0; j < k; ++j)
			sums[j] = triangle[i][j] + min(sums[j], sums[j+1]);
	}

	return sums[0];
}
