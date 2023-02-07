#include <iostream>
using namespace std;

int main(void)
{
	int r = 0;
	int c = 0;

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << '*';
		}
		cout << endl;
	}

	return 0;
}
