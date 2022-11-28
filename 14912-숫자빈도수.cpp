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

	int n = 0;
	string k;
	cin >> n >> k;
	
	string total;
	int counter = 0;
	
	for (int i = 1; i <= n; i++)
	{
		string temp;
		temp = to_string(i);
		total += temp;
	}

	for (int i = 0; i < total.length(); i++)
	{
		if (total[i] == k[0])
		{
			counter++;
		}
	}

	cout << counter;
	return 0;
}
