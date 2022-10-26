#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main(void)
{
	int s;

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;

		string ss = to_string(s);
		vector<int> arr;

		for (int j = 0; j< ss.length(); j++)
		{
			int a = ss[j]-48;
			arr.push_back(a);
		}

		sort(arr.begin(),arr.end());

		int temp = arr[0];
		int result = 1;
		for (int k = 1; k < arr.size(); k++)
		{

			if (arr[k] != temp)
			{
				result++;
				temp = arr[k];
			}


		}

		cout << result << '\n';
	}
	



}
