#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	string s;

	cin >> s;
	string temp;
	vector<string> arr;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ',')
		{
			temp += s[i];
		}

		if (s[i] == ',')
		{
			arr.push_back(temp);
			temp.clear();
		}
	}

	arr.push_back(temp);

	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		int part = 0;
		part = stoi(arr[i]);
		sum+=part;
	}

	cout << sum;
	return 0;
}
