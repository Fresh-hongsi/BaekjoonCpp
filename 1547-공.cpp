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


	int M = 0;
	cin >> M;
	vector<int> arr(4, 0);
	arr[1] = 1;

	while (M--)
	{
		int a = 0;
		int b = 0;

		cin >> a >> b;


		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}


	for (int i = 1; i < 4; i++)
	{
		if (arr[i] == 1)
		{
			cout << i;
			break;
		}
	}

	return 0;
}
