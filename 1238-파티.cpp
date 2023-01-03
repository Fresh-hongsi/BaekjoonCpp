#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 33333333
#define MAX_CITY 1001
#define MAX_EDGE 10001

vector<pair<int, int>> map[MAX_CITY]; //간선 정보 저장할 인접리스트
int dk[MAX_CITY][MAX_CITY]; //각 정점에 대응하는 모든 정점에 대한 최단경로를 저장할 이차원 배열 dk[2][4]->2번 정점에 대한 dk를 할 건데, 2번 정점의 dk배열에서 2->4로 가는 최단 경로 값
int N = 0; //도시 정점 수
int M = 0; //도시 간선 수
int X = 0; //파티 도시 정점

void dijkstra(int start)
{
	//발전된 형태의 다익스트라 알고리즘 ->  우선순위 큐 이용

	dk[start][start] = 0; //시작정점에 대응하는 dk를 처리할 것 시작정점에서 시작 정점에 대응하는 최단경로는 0으로 세팅

	priority_queue<pair<int, int>> pq; 

	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int start_to_cur_dist = -pq.top().first; //우선순위 큐의 디폴트 정렬 순서는 가장 큰 값이 top에 존재하므로, 음수화 시켜서 실제 간선비용 값이 가장 작은 게 위에 오도록 함

		pq.pop();

		if (dk[start][cur] < start_to_cur_dist)
			continue;

		else
		{
			for (int i = 0; i < map[cur].size(); i++)
			{
				int next = map[cur][i].second;
				int start_to_next_dist = start_to_cur_dist+map[cur][i].first;

				if (dk[start][next] > start_to_next_dist)
				{
					dk[start][next] = start_to_next_dist;
					pq.push(make_pair(-start_to_next_dist, next)); //새로 계산된 간선정보( - 시작->next정점 비용, next정점) 을 우선순위 큐에 삽입
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

	cin >> N >> M >> X;

	for (int i = 1; i <= N; i++) //dk의 모든 배열을 INF값으로 초기화
	{
		for (int j = 1; j <= N; j++)
		{
			int temp = INF;
			dk[i][j] = temp;
		}
		
	}

	for (int i = 1; i <= M; i++) //간선 정보 map 이중리스트에 삽입
	{
		int s, e, c;
		cin >> s >> e >> c;

		map[s].push_back(make_pair(c, e));
	}

	
	for (int i = 1; i <= N; i++) //모든 정점에 대해서, 그 정점으로부터 다른 모든 정점까지의 최단경로값을 계산해 dk이차원 배열에 저장
	{
		dijkstra(i);
	}

	int max = 0; //해당 정점-> 파티 장소 + 파티장소->해당 정점 값이 가장 큰 값을 담을 변수

	for (int i = 1; i <= N; i++)
	{
		int temp = dk[i][X] + dk[X][i];
		if (max < temp)
		{
			max = temp;
		}
	}

	cout << max;
	return 0;

}
