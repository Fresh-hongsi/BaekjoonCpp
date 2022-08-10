//Sorting
//Implementation

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int i, int j)
{
	return i > j;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0; //응시자
	int k = 0; //상 받는 사람
	vector<int> score;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		score.push_back(temp);
	}

	sort(score.begin(), score.end(),compare);
	cout << score[k - 1]; //커트라인이 되는 점수 인덱스는 상 받는 마지막 사람의 인덱스임
	return 0;

}
