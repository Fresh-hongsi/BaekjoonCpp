#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<vector<int>> arr(9,vector<int>(9,0));
vector<int> input;

int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int temp = 0;
			cin >> temp;
			input.push_back(temp);
			arr[i][j] = temp;
		}
	}

	sort(input.begin(), input.end());
	int max1 = input[80];


	cout << max1<<endl;
	int count = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == max1 && count==0)
			{
				cout << i+1 << ' ' << j+1;
				count++;
				
			}
		}
	}
	return 0;

	
}
