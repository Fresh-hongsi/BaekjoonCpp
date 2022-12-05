#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int tc = 0;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		string a;
		cin >> a;

		if (a.length() >= 6 && a.length() <= 9)
			cout << "yes";
		else
			cout << "no";

		cout << '\n';
	}

	return 0;
}
