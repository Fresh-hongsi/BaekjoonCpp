#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	string a;
	string b;

	cin >> a >> b;

	//min값 구하기
	string minfora = a;
	string minforb = b;
	string maxfora = a;
	string maxforb = b;
	for (int i = 0; i < minfora.length(); i++)
	{
		if (minfora[i] == '6')
		{
			minfora[i] = '5';
		}
	}

	for (int i = 0; i < minforb.length(); i++)
	{
		if (minforb[i] == '6')
		{
			minforb[i] = '5';
		}
	}

	int minforaInt = stoi(minfora);
	int minforbInt = stoi(minforb);
	int mininum = minforaInt + minforbInt;

	for (int i = 0; i < maxfora.length(); i++)
	{
		if (maxfora[i] == '5')
		{
			maxfora[i] = '6';
		}
	}

	for (int i = 0; i < maxforb.length(); i++)
	{
		if (maxforb[i] == '5')
		{
			maxforb[i] = '6';
		}
	}

	int maxforaInt = stoi(maxfora);
	int maxforbInt = stoi(maxforb);
	int maximum = maxforaInt + maxforbInt;

	cout << mininum << ' ' << maximum;
	return 0;
}
