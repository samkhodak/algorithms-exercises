#include <iostream>
#include <math.h>
#include <stdlib.h>

//Merge sort
//Take an array of random numbers and sort it with recursion and traversal.


int mergesort(int to_sort[], int low, int high);

int main()
{
	int a {0};
	int n {2000000000};	//Input size of array, as well as max size of random numbers.

	
		std::cout << "Enter n. \n N:";
		std::cin >> n;
		std::cin.ignore(100, '\n');

		int * to_sort = new int[n];

		//Generate random numbers to fill the array.
		for (int i = 0; i < n; ++i)	
		{
			srand(time(NULL) + i);
			to_sort[i] = rand() % n;
		}


		mergesort(to_sort, 0, n - 1);
		delete [] to_sort;

		std::cout << "\n\nN: " << n;

	return 0;
}



//Sort function: has low and high bounds
int mergesort(int to_sort[], int low, int high)
{
	//Base case for if the range (hi - lo) is 1 and therefore cannot be sorted.
	if (low >= high)
		return 0;


	int * copy_back = new int[high + 1];	//Array to sort into, then copy back sorted numbers to original array slice.
	int mid = (low + high) / 2;

	//Call recursively with first half slice, then second half slice. This sorts both halves independently.
	mergesort(to_sort, low, mid);
	mergesort(to_sort, mid + 1, high);


	//i and j are positioned at the beginning of each half of the current array slice.
	int i = low;
	int j = mid + 1;
	int k = 0;				//k is to increment the copy_back array


	//Compare corresponding elements of each half until one reaches the end of its slice.	[i][ ][ ][j][ ][ ]
	while (i <= mid && j <= high)
	{
		if (to_sort[i] <= to_sort[j])		//If i element is smaller, copy that to the temp array. If not, copy j. Increment smallest iterator.
		{
			copy_back[k] = to_sort[i];
			++i;
		}
		else
		{
			copy_back[k] = to_sort[j];
			++j;
		}
		++k;                                //Increment k in temp array each loop iteration.    [5][7][9] [2][8][9]
		                                    //                                                   i            j
	                                        //                                               cb [2][5][0] [0][0][0]
											//                                                         k

	while (i <= mid)									
	{
		copy_back[k] = to_sort[i];
		++k;
		++i;
	}

	while (j <= high)
	{
		copy_back[k] = to_sort[j];
		++k;
		++j;
	}


	for (i = low; i <= high; ++i)
	{
		to_sort[i] = copy_back[i - low];
	}

	delete [] copy_back;

	return 0;
}
