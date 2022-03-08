#include <iostream>
#include <math.h>
#include <stdlib.h>

//Heap Sort
//Take an array of random numbers and sort it with recursion and traversal.

void gen_random_array(int input[], const int n);
void display_heap(int input[], const int n);
void sort_heap(int to_sort[], const int n);
void swap_down(int input[], int x, const int n);
void make_heap(int input[], int n);

int main()
{
	int n {0};
	std::cout << "\nEnter N. \n\nN: ";
	std::cin >> n;
	std::cin.ignore(100, '\n');

	int * to_sort = new int[n];
	gen_random_array(to_sort, n);
	display_heap(to_sort, n);


	make_heap(to_sort, n);
	sort_heap(to_sort, n);


	std::cout << "NEW ARRAY";
	display_heap(to_sort, n);

	return 0;

}


//Fill the array with random integers that range from 0-n.
void gen_random_array(int input[], const int n)
{
	for (int i = 0; i < n; ++i)	
	{
		srand(time(NULL) + i);
		input[i] = rand() % n;
	}
}


//Display the array.
void display_heap(int input[], const int n)
{
	std::cout << "\n\n";
	for (int i = 0; i < n; ++i)	
	{
		std::cout << "[" << input[i] << "]";
	}
	std::cout << "\n\n";
}



//Sort the heap by swapping-down.
void sort_heap(int to_sort[], int n)
{
	int temp {0};
	
	for (int i = (n - 1); i >= 0; --i)	//Start at the last node and decrement
	{
		temp = to_sort[0];								//Swap first and last node
		to_sort[0] = to_sort[i];
		to_sort[i] = temp;

		swap_down(to_sort, 0, i);					//Reheap from top down. Since index 0 is always greatest number after
	}																		//reheap, you're swapping largest to end and remaking a smaller heap.
}




//left child of A[x] = A[2x+1]
//Right child of A[x] = A[2x+2]
//Parent of A[x] = A[(x-1)/2]
//Swap the subtree's parent and children to make heaps.
void swap_down(int input[], int parent, const int n)
{
	int left_child = (2 * parent) + 1;
	int right_child = (2 * parent) + 2;
	int largest = parent;
	
	if (left_child < n && input[left_child] > input[largest])
	{
		largest = left_child;			//Check what child is larger and save that index.
	}
	if (right_child < n && input[right_child] > input[largest])	
	{
		largest = right_child;
	}
	
	if (largest != parent)			//If a child is larger than parent, swap it and reheap the child tree.
	{														//Otherwise, this will return from recursion.
		int temp = input[parent];
		input[parent] = input[largest];
		input[largest] = temp;

		swap_down(input, largest, n); 
	}
}


//Call the swap_down function for every parent node in the heap.
void make_heap(int input[], int n)
{
	int top = (n / 2) - 1;
	for (int i = top; i >= 0; --i)
	{
		swap_down(input, i, n);
	}
}
