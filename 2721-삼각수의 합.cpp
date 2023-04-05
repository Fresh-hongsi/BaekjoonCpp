#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;

		int result = 0;

		for (int k = 1; k <= temp; k++)
		{
			for (int j = 1; j <= k + 1; j++)
			{
				result += (k * j);
			}


		}

		cout << result << '\n';
	}
	

	return 0;
}
