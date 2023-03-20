#include <iostream>
using namespace std;

int main(void)
{
	long long a = 0;
	cin >> a;

	long long count = 0;
	
	
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= a; j++)
		{
			count++;
		}
	}


	cout << count<<'\n';
	cout << 2;
	return 0;
}
