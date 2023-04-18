#include <iostream>
using namespace std;


int main(void)
{
	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int num = 0;
		cin >> num;

		for (int j = 0; j < num; j++)
		{
			int a, b = 0;
			cin >> a >> b;

			cout << a + b << ' ' << a * b << endl;
		}

		
	}

	return 0;

	
}
