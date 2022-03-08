#include <iostream>
#include <stdlib.h>
using namespace std;

//Rod-cutting problem for finding the optimal sale price of a length-n rod's pieces.


//Prototypes
int memoized_price(int prices[], int saved_prices[], int length);
int tabulated_price(int prices[], int saved_prices[], int length);


int main()
{
	int prices[] {0, 2, 5, 9, 10, 12};

	//n is 1 less than the array size because 0 is a base case.
	int n = (sizeof(prices) / sizeof(prices[0])) - 1;	
	
	int price_check[n + 1] {0};

	/*	//Only use for memoization call
	for (int i = 1; i < n + 1; ++i)
		price_check[i] = -1;
	*/

	cout << "\n\nhighest price for n = " << n << " is " 
			 << tabulated_price(prices, price_check, n) << "." << endl << endl;
	
	return 0;
}

int memoized_price(int prices[], int saved_prices[], int length)
{
	int highest_price {0};
	int current_price {0};

	if (length == 0)
		return 0;
	
	//Check saved_prices array to see if this length's best price was already calculated.
	if (saved_prices[length] != -1)
		return saved_prices[length];

	//Loop goes through length passed in and checks which price is best for each possible length of two slices.
	for (int i = 1; i <= length; ++i)
	{
		current_price = prices[i] + memoized_price(prices, saved_prices, length - i);
		
		//Set highest to biggest of current and highest.
		highest_price = (current_price > highest_price) ? current_price : highest_price;	
	}

	//Update the now-calculated best price in the table!
	saved_prices[length] = highest_price;
	return highest_price;
}


int tabulated_price(int prices[], int saved_prices[], int length)
{
	int current_price {0};

	//For iterating through the saved_prices array to check each price.
	for (int i = 1; i < length + 1; ++i)
	{
		//For getting best price of each possible cut of length.
		for (int j = 1; j <= i; ++ j)
		{
			current_price = prices[j] + saved_prices[i - j];
			if (current_price > saved_prices[i])
				saved_prices[i] = current_price;
		}
	}

	return saved_prices[length];
}

