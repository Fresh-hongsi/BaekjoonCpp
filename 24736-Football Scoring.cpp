#include <iostream>
using namespace std;

int main(void)
{
	int a, b, c, d, e;

	for (int i = 0; i < 2; i++)
	{
		cin >> a >> b >> c >> d >> e;
		int result = (a * 6 + b * 3 + c * 2 + d * 1 + e * 2);
		cout << result << ' ';
	}

	return 0;

	
	

}
