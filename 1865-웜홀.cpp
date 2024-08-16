#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <functional>
using namespace std;

typedef tuple<int, int, int> edge;

int tc = 0;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> tc;

	while (tc--) {
		vector<edge> elist;
		vector<int> min_length(500, 987654321);

		int n = 0;
		int m = 0;
		int w = 0;
		cin >> n >> m >> w;

		// 간선 세팅
		for (int i = 0; i < m; i++) {
			int s = 0;
			int e = 0;
			int v = 0;
			cin >> s >> e >> v;

			elist.push_back(make_tuple(s - 1, e - 1, v));
			elist.push_back(make_tuple(e - 1, s - 1, v));
		}

		// 웜홀 세팅
		for (int i = 0; i < w; i++) {
			int s = 0;
			int e = 0;
			int v = 0;
			cin >> s >> e >> v;

			elist.push_back(make_tuple(s - 1, e - 1, -1*v));
		}

		min_length[0] = 0;
		// 벨만 포드 적용 (n-1 회)
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < elist.size(); j++) {
				int s = get<0>(elist[j]);
				int e = get<1>(elist[j]);
				int v = get<2>(elist[j]);

				if ( min_length[e] > min_length[s] + v) {
					min_length[e] = min_length[s] + v;
				}
			}
		}

		// 한번 더 시도하면서, 값이 감소하는 게 있으면 음의 사이클 존재
		bool flag = false;
		for (int i = 0; i < elist.size(); i++) {
			int s = get<0>(elist[i]);
			int e = get<1>(elist[i]);
			int v = get<2>(elist[i]);

			if ( min_length[e] > min_length[s] + v) {
				flag = true; // 음의 사이클 존재
				break;
			}
		}

		/*for (int i = 0; i < elist.size(); i++) {
			cout << min_length[i] << ' ';
		}*/

		if (flag == true) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;

}
