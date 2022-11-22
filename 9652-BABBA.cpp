#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc = 0;
	cin >> tc;

	int acount = 1;
	int bcount = 0;
	int anext = 0;
	int bnext = 0;
	for (int i = 0; i < tc; i++)
	{
		anext = bcount;
		bnext = acount + bcount;

		acount = anext;
		bcount = bnext;
		
	}

	cout << anext << ' ' << bnext;
	return 0;
	
	return 0;
}
