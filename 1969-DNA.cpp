#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc = 0;
	int leng = 0;

	cin >> tc >> leng;

	string temp;
	string longStr = "";
	string result;
	for (int i = 0; i < tc; i++)
	{
		cin >> temp;
		longStr += temp;

	}

	for (int i = 0; i < leng; i++)
	{
		vector<int> arr(4, 0);
		for (int j = 0; j < tc; j++)
		{
			char ch = longStr[(j * leng) + i];
			if (ch == 'A')
			{
				arr[0]++;
			}
			if (ch == 'C')
			{
				arr[1]++;
			}
			if (ch == 'G')
			{
				arr[2]++;
			}
			if (ch == 'T')
			{
				arr[3]++;
			}


		}

		int maxim = 0;
		int max1 = arr[0];
		for (int i = 1; i < 4; i++)
		{
			if (max1 < arr[i])
			{
				max1 = arr[i];
				maxim = i;
			}
		}

		char selected;
		if(maxim==0)
			selected = 'A';
		if (maxim == 1)
			selected = 'C';
		if (maxim == 2)
			selected = 'G';
		if (maxim == 3)
			selected = 'T';

		result += selected;
		
		
	}

	cout << result << endl;

	int resultConter = 0;
	for (int i = 0; i < longStr.length(); i++)
	{
		if (result[i%leng] != longStr[i])
			resultConter++;
	}

	cout << resultConter;
	

	
}
