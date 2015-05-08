/*In a daily share trading, a buyer buys shares in the morning and sells it on same day. If the trader is allowed to make at most 
2 transactions in a day, where as second transaction can only start after first one is complete (Sell->buy->sell->buy). 
Given stock prices throughout day, find out maximum profit that a share trader could have made.*/
#include <iostream>
using namespace std;

int maxProfit(int price[], int n) {
	int maxPrice, minPrice;
	int *profit = new int[n];
	int maxProfit = 0;
	maxPrice = price[n-1];
	for(int i = 0; i < n; i++) {
		profit[i] = 0;
	}
	for(int i = n-2; i >= 0; i--) {
		if(maxPrice < price[i]) {
			maxPrice = price[i];
		}
		profit[i] = max(profit[i+1], maxPrice - price[i]);
	}

	minPrice = price[0];
	for(int i = 1; i < n; i++) {
		if(minPrice > price[i]) {
			minPrice = price[i];
		}
		profit[i] = max(profit[i-1], (price[i] - minPrice) + profit[i]);
	}
	int result = profit[n-1];
 
    delete [] profit; // To avoid memory leak
 
    return result;
}

int main()
{
    int price[] = {200, 300, 400, 401, 450, 500, 550};
    int n = sizeof(price)/sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfit(price, n) << endl;;
    return 0;
}