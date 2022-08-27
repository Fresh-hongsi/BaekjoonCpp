#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	

	vector<int> mine;
	vector<int> original;

	original.push_back(1);
	original.push_back(1);
	original.push_back(2);
	original.push_back(2);
	original.push_back(2);
	original.push_back(8);
	for (int i = 0; i < 6; i++)
	{
		int temp = 0;
		cin >> temp;
		mine.push_back(temp);
	}

	for (int i = 0; i < 6; i++)
	{
		int temp = original[i] - mine[i];
		cout << temp << ' ';
	}

	return 0;

}
