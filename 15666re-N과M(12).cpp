#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int N = 0;
int M = 0;
vector<int> arr;
vector<int> seq;

void bt(int cur) {
	if (seq.size() == M) {
		for (int i = 0; i < seq.size(); i++) {
			cout << seq[i] << ' ';
		}
		cout << '\n';
		return;
	}


	int xx = 0;
	for (int i = cur; i < arr.size(); i++) {
		if (xx != arr[i]) {
			seq.push_back(arr[i]);
			xx = arr[i];
			bt(i);
			seq.pop_back();
		}
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



	return 0;
}
