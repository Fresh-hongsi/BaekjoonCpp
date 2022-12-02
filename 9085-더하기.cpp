#include <iostream>
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


	for (int i = 0; i < tc; i++)
	{
		int num = 0;
		cin >> num;

		
		int result = 0;
		for (int i = 0; i < num; i++)
		{
			int temp = 0;
			cin >> temp;
			result += temp;
			
		}
		cout << result << '\n';
	}

	return 0;


}
