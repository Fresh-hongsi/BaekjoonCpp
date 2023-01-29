#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int kill = 0;
	int death = 0;
	int assist = 0;
	char slash;

	cin >> kill>>slash >> death >>slash>> assist;

	if (death == 0 || kill + assist < death)
	{
		cout << "hasu";
	}

	else
	{
		cout << "gosu";
	}

	return 0;
}
