#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
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
		string a;
		string b;

		cin >> a >> b;

		int result = 0;
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] == b[i])
				continue;

			else
			{
				result++;

			}
		}

		cout <<"Hamming distance is "<< result<<'.' << '\n';



	}

	return 0;
}
