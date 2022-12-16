#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>>arr;


int main(void)
{
	int tc = 0;

	cin >> tc;

	int counter = 0;
	

	for (int i = 0; i < tc; i++)
	{
		int num = 0;
		int pos = 0;

		cin >> num >> pos;

		for (int j = 0; j < arr.size(); j++)
		{
			if (num == arr[j].first)
			{
				if (pos != arr[j].second)
				{
					counter++;
					
					arr[j].first = 100;
					
				}

				else
				{
					arr[j].first = 100;
				}
			}
		}
		arr.push_back(pair<int, int>(num, pos));



		
	}

	cout << counter;
	return 0;
}
