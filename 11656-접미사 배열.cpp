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

	string temp;
	cin >> temp;

	vector<string> arr;
	string temp2;
	int length = temp.length();
	for (int i = 0; i < length; i++)
	{
		temp2 = "";
		for (int j = i; j < length; j++)
		{
			
			temp2+=temp[j];
		}
		arr.push_back(temp2);
	}


	sort(arr.begin(), arr.end());

	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << '\n';
	}

	return 0;

	
}
