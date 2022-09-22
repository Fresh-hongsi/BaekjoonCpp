#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long room = 0;
	long long mainSight = 0;
	long long subSight = 0;
	vector<long long> member;
	long long mainDirector = 0;
	long long subDirector = 0;

	cin >> room;

	for (int i = 0; i < room; i++)
	{
		long long temp = 0;
		cin >> temp;
		member.push_back(temp);
	}


	cin >> mainSight >> subSight;

	for (int i = 0; i < room; i++)
	{
		mainDirector += 1;

		if (member[i] - mainSight <= 0)
			continue;
		int tmp = ((member[i] - mainSight) % subSight);

		if (tmp == 0)
		{
			subDirector += (member[i] - mainSight) / subSight;
		}

		else
		{
			subDirector += (member[i] - mainSight) / subSight+1;
		}
	}

	cout << mainDirector + subDirector;
	return 0;
}
