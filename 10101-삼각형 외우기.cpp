#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	int a = 0;
	int b = 0;
	int c = 0;

	cin >> a >> b >> c;

	if (a + b + c == 180)
	{
		if (a == 60 && b == 60 && c == 60)
		{
			cout << "Equilateral";
		}

		else if (a == b || a==c ||b==c)
		{
			cout << "Isosceles";
		}

		else if (a != b && b != c && c != a)
		{
			cout << "Scalene";
		}

		
	}

	else
	{
		cout << "Error";
	}

	return 0;
}
