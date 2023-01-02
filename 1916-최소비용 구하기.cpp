//우선순위 큐를 활용한 다익스트라 -> 1753번 우선 참고!

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_NODE 1001
#define MAX_EDGE 100001
#define MAX_COST 333333333

int N = 0; //도시의 개수(정점)
int M = 0; //버스의 개수(간선)
vector<pair<int, int>>map[MAX_EDGE]; //인접리스트
int dk[MAX_NODE]; //시작 정점으로부터 해당 정점까지의 최단거리 정보


void dijkstra(int st)
{
	dk[st] = 0; //우선 시작정점부터 시작 정점까지의 거리는 0

	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(0, st));

	while (!pq.empty())
	{
		int cur = pq.top().second;

		int start_to_cur_dist = -pq.top().first;

		pq.pop();


		if (dk[cur] < start_to_cur_dist)
		{
			continue;
		}

		for (int i = 0; i < map[cur].size(); i++)
		{
			int next = map[cur][i].second;
			int start_to_next_dist = start_to_cur_dist + map[cur][i].first;

			if (dk[next] > start_to_next_dist)
			{
				dk[next] = start_to_next_dist;
				pq.push(make_pair(-dk[next], next));
			}



		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int start = 0; //시작 정점
	int end = 0; //도착 정점

	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		int s = 0;
		int e = 0;
		int cost = 0;

		cin >> s >> e >> cost;

		map[s].push_back(make_pair(cost, e));
	}

	for (int i = 1; i <= N; i++)
	{
		dk[i] = MAX_COST;
	}

	cin >> start >> end; //최단비용 값을 알고싶어하는 시작정점과 끝정점을 입력받음

	dijkstra(start);

	cout << dk[end];
	return 0;



}
