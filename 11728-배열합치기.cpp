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

	vector<int> a1;
	

	int asize = 0;
	int bsize = 0;

	cin >> asize >> bsize;

	for (int i = 0; i < asize+bsize; i++)
	{
		int temp = 0;
		cin >> temp;

		a1.push_back(temp);
	}

	sort(a1.begin(), a1.end());

	for (int i = 0; i < asize + bsize; i++)
	{
		cout << a1[i] << ' ';
	}

	return 0;





}
