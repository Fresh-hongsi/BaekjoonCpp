#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc = 0;

	cin >> tc;

	while (tc--)
	{
		string temp;
		cin >> temp;

		string result;

		char a = temp[0];
		char b = temp[temp.length() - 1];
		result += a;
		result += b;

		cout << result;
		cout << '\n';
	}

	return 0;
}
