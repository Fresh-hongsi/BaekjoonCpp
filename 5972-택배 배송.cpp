//다익스트라(개선된 형태: 우선순위큐)를 활용한 풀이

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_NODE 50001
#define MAX_EDGE 100002
#define INF 66666666

int N; //헛간의 수
int M; //간선의 수

vector<pair<int,int>>map[MAX_NODE]; //간선정보 저장할 인접리스트
int dk[MAX_NODE]; //현서가 모든 헛간까지 가는데 줘야할 최소 여물 값


void dijkstra(int start)
{
	dk[start] = 0;

	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int start_to_cur_dist = -pq.top().first;

		pq.pop();

		if (dk[cur] < start_to_cur_dist)
			continue;

		else
		{
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

}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		dk[i] = INF;
	}

	for (int i = 0; i < M; i++)
	{
		int s; //간선의 시작점
		int e; //간선의 도착점
		int c; //해당 간선에 있는 소의 수

		cin >> s >> e >> c;

		//양방향 간선이므로 이렇게 처리
		map[s].push_back(make_pair(c, e));
		map[e].push_back(make_pair(c, s));
	}


	dijkstra(1);

	cout << dk[N]; //처음 위치에서부터 목적지까지 가는데 필요한 최소 여물 비용 출력
	return 0;





}
