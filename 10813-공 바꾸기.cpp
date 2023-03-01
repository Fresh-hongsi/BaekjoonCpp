#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int M = 0;
	vector<int> basketArr;
	cin >> N >> M;

	for (int i = 0; i <= N; i++)
	{
		int ballNum = i;
		basketArr.push_back(i);

		
	}

	for (int i = 0; i < M; i++)
	{
		int s = 0;
		int e = 0;
		cin >> s >> e;

		int temp = basketArr[s];
		basketArr[s] = basketArr[e];
		basketArr[e] = temp;
	}


	for (int i = 1; i <= N; i++)
	{
		cout << basketArr[i] << ' ';
	}

	return 0;
}
