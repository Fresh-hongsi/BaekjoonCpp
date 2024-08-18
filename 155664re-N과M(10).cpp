#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>
using namespace std;

// 조합 찾기
int N = 0;
int M = 0;
vector<bool> visited(10001, false);
vector<int> seq;
vector<int> arr;
vector<vector<int>> v;

void bt(int cur) {

	if (seq.size() == M) {
		v.push_back(seq);
		return;
	}

	for (int i = cur; i < arr.size(); i++) {
		seq.push_back(arr[i]);
		bt(i + 1);
		seq.pop_back();
	}
	

}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;

		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	bt(0);

	sort(v.begin(), v.end());

	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}



	return 0;
}

//1 7 9 9 
//
//1 7
//1 9
//1 9
//7 1
//7 9
//7 9
//9 1
//9 7
//9 9
//9 1
//9 7 
//9 9
