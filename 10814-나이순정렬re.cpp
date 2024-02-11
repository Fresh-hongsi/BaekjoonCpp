#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//stable sort를 사용하면, 원래 들어온 순서를 손상시키지 않고 있으므로 age정보에 의해서만 정렬해주면 된다
bool comp(pair<int, string>a, pair<int, string>b) {

	//나이가 다르면 나이 오름차순
	if (a.second != b.second) {
		return a.first < b.first;
	}

}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;


	vector<pair<int, string>> dic;

	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		string s;

		cin >> temp >> s;

		dic.push_back(make_pair(temp, s));
	}

	stable_sort(dic.begin(), dic.end(), comp);

	for (int i = 0; i < N; i++)
	{
		cout << dic[i].first << ' ' << dic[i].second << '\n';
	}

	return 0;



}
