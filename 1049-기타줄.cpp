#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n = 0;
	int m = 0;

	cin >> n >> m;

	int packMin = 1000; //선택될 가장 싼 6개 가격
	int oneMin = 1000; //선택될 가장 싼 낱개 가격


	for (int i = 0; i < m; i++)
	{
		int packtemp = 0;
		int onetemp = 0;
		cin >> packtemp >> onetemp;

		if (packtemp <= packMin)
		{
			packMin = packtemp;
		}

		if (onetemp <= oneMin)
		{
			oneMin = onetemp;
		}


	}


	int packCounter = 0;
	int oneCounter = 0;
	if (oneMin * 6 < packMin)
	{
		packCounter = 0;
		oneCounter = n;

	}

	else
	{
		packCounter = n / 6;
		oneCounter = n - packCounter*6;
		if (oneCounter * oneMin > packMin)
		{
			oneCounter = 0;
			packCounter++;
		}


	}

	int result1 = 0;
	int result2 = 0;

	result1 = oneCounter * oneMin;
	result2 = packCounter * packMin + oneCounter * oneMin;

	int result = max(result1, result2);
	cout << result;
	



	
	return 0;
}
