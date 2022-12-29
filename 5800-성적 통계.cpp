#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool comp(int a, int b)
{
	return b<a;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int cl = 0;
	cin >> cl;

	for (int i = 0; i < cl; i++)
	{
		vector<int> arr;
		int clNum = 0;
		cin >> clNum;
		int temp = 0;
		for (int j = 0; j < clNum; j++)
		{
			
			cin >> temp;
			arr.push_back(temp);
		}

		sort(arr.begin(), arr.end(),comp);
		int M = arr[0];
		int m = arr[clNum-1];
		
		int g = 0;
		for (int i = 1; i < clNum; i++)
		{
			int t = arr[i-1] - arr[i];
			if (g < t)
				g = t;
		}
		cout << "Class " << i + 1 << endl;
		cout << "Max " << M << ", " << "Min " << m << ", " << "Largest gap " << g << endl;
	}

	return 0;
}
