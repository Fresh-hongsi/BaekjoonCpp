#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int snackPrice=0;
	int snackNum=0;
	int myMoney = 0;

	cin >> snackPrice >> snackNum >> myMoney;

	int totalPrice = snackNum * snackPrice;

	if (myMoney >= totalPrice)
	{
		cout << 0;
	}

	else
	{
		cout << totalPrice - myMoney;
	}

	return 0;
}
