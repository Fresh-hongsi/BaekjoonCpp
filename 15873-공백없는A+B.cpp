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

	int result = 0;

	for (int i = 0; i < temp.length(); i++)
	{
		int t = temp[i] - 48;
		if (t == 0)
		{
			result +=9;
		}
		else
		{
			result += t;
		}
		
	}

	cout << result;
	return 0;
}
