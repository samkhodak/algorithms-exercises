#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;


//Prototypes
void display_triangle(vector<vector<long long>> & triangle, int n, int k);
void initialize_triangle(vector<vector<long long>> & triangle, int n, int k);

int main()
{
	int n {0};
	int k {0};

	cout << "Enter n." << endl;
	cin >> n;
	cin.ignore(100, '\n');

	cout << "Enter k." << endl;
	cin >> k;
	cin.ignore(100, '\n');
	
	//Vector that simulates Pascal's triangle
	vector<vector<long long>> triangle(n + 1, vector<long long>(n + 1, 1));

	initialize_triangle(triangle, n, k);	
	display_triangle(triangle, n, k);	

	cout << "\n\nn choose k for n = " << n << " and k = " << k << ": " << triangle[n][k] << endl << endl;
	

	return 0;
}

void display_triangle(vector<vector<long long>> & triangle, int n, int k)
{
	if (n > 20)
	{
		cout << "\n\nn is too large to display the triangle. Sorry!" << endl << endl;
		return;
	}

	cout << "\n\nPascal's triangle\n\n";
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= i; ++j)
			cout << "[" << triangle[i][j] << "]";
		cout << "\n";
	}
	
}

void initialize_triangle(vector<vector<long long>> & triangle, int n, int k)
{
	//The vector has been initialized with n+1 rows, n+1 elements in each row, just 
	//like the bottom row of the pascal triangle.

	//We can start our loop from i = 2, because first two levels of pascal's triangle are already 1s.
	//We will go while i <= n, since the vector size is n + 1.
	for (int i = 2; i <= n; ++i)
	{
		//We want to stop calculating at j < i, since the last element of the row is already a 1.
		for (int j = 1; j < i; ++j)
			triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; 
			//This will calculate pascal's value in each box of pascal's triangle.
	}
}
