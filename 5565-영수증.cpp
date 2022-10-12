#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> book;

	for (int i = 0; i < 10; i++)
	{
		int temp = 0;
		cin >> temp;
		book.push_back(temp);
	}

	int total = 0;
	for (int i = 1; i <= 9; i++)
	{
		total += book[i];
		
	}

	cout << book[0] - total;

	return 0;
}
