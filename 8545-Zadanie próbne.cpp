#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	vector<char> arr;

	string temp;
	cin >> temp;

	for (int i = temp.length() - 1; i >= 0; i--)
	{
		char k = temp[i];
		arr.push_back(k);
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i];
	}
}
