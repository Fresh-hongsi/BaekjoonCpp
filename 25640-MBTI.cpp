#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	string st;
	cin >> st;

	int n = 0;
	cin >> n;

	vector<string> s;
	for (int i = 0; i < n; i++)
	{
		string s1;
		cin >> s1;
		s.push_back(s1);
	}

	int result = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == st)
		{
			result++;
		}
	}

	cout << result;
	return 0;
}
