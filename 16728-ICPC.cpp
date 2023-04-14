#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{

	int a1 = 0;
	int b1 = 0;
	int a2 = 0;
	int b2 = 0;
	cin >> a1 >> b1>>b2>>a2;

	int aTotal = a1 + a2;
	int bTotal = b1 + b2;

	if (aTotal > bTotal)
	{
		cout << "Persepolis";
	}

	else if (bTotal > aTotal)
	{
		cout << "Esteghlal";
	}

	else if(aTotal==bTotal)
	{
		if (a2>b1)
		{
			cout << "Persepolis";
		}

		else if (b1>a2)
		{
			cout << "Esteghlal";
		}

		else
		{
			cout<<"Penalty";
		}
	}

	
	
	return 0;
}
