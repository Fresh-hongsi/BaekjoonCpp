#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int month = 0;
	int day = 0;


	cin >> month >> day;

	if (month == 2 && day == 18)
	{
		cout << "Special";
	}

	else if ((month == 2 && day < 18) || (month<2))
	{
		cout << "Before";
	}

	else
	{
		cout << "After";
	}
  return 0;
}
