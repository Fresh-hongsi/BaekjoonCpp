//math
//implementation

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minguk = 0;;
int manse=0;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 4; i++)
	{
		int temp = 0;
		cin >> temp;
		minguk += temp;
	}

	for (int i = 0; i < 4; i++)
	{
		int temp = 0;
		cin >> temp;
		manse += temp;
	}

	if (minguk < manse)
	{
		cout << manse;
	}
	else
	{
		cout << minguk;
	}

	return 0;


}
