//기존의 O(V^2)방식의 벡터 활용 다익스트라에서 더 발전된 형태인 우선순위 큐를 이용한 O(VE)다익스트라 알고리즘
//기본 priority_queue와 pair을 같이 쓰면 첫번쨰 pair인자 기준으로 내림차순 정렬
// 첫번쨰 pair인자가 같다면 두번째 pair인자 기준으로 내림차순 정렬됨

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000
#define MAX_VERTEX 20001
#define MAX_EDGE 300001
vector<pair<int, int>>map[MAX_EDGE]; //인접리스트
int dk[MAX_VERTEX]; //시작 정점으로부터 해당 정점까지의 최단거리 정보


int V = 0; //정점의 개수
int E = 0; //간선의 개수
int start = 0; //시작 정점

void dijkstra(int s)
{
	dk[s] = 0; //시작 정점으로부터 시작 정점까지의 최단거리는 0


	//우선순위큐를 사용하는 순간 visited 필요 x, 우선순위 큐의 최상단 노드가 최단거리 정보 보유
	//pair<거리,도착노드>
	priority_queue<pair<int, int>> pq;


	pq.push(make_pair(0, s)); //거리=0, 도착노드:s

	while (!pq.empty())
	{
		// 기존의 우선 순위 큐는, 첫 번째 값을 기준으로 큰 값이 top 에 오도록 정렬되어있다.
		// 하지만, 해당 알고리즘에선, 비용 값을 음수화 한 뒤 첫번째 값으로 삽입하고, 도착 노드는 두번째 값으로 삽입한다.
		// 따라서, 비용이 가장 작은 값이 top 에 오도록 정렬되어있다.
		// 즉, 가장 최소 비용을 주장하는 경로부터 확인하게 된다.

		// 시작 노드에서 어떤 도착 노드까지의 최소 경로를 주장하는 pq 의 top 에서,
		// 도착 노드를 현재 노드로 설정한다.
		int cur = pq.top().second;

		//시작노드에서 현재 노드까지의 거리를 설정한다
		//거리는 음수화 되어있는 상태이므로 다시 양수화 해준다.
		int start_to_cur_dist = -pq.top().first;

		pq.pop();

		//이미 전에 계산되어있던 시작노드 s로부터 cur까지의 거리가 pq에서 뽑은 거리 정보보다 작다면 계산을 할 필요가 x
		if (start_to_cur_dist > dk[cur])
			continue;

		//이미 전에 계산되어있던 시작노드 s로부터 cur까지의 거리가 pq에서 뽑은 거리 정보보다 크다면 
		//cur을 시작점으로하는 간선의 거리정보와 도착정점 값을 pq에 삽입
		else
		{
			for (int i = 0; i < map[cur].size(); i++)
			{
				int next = map[cur][i].second; //cur을 시작점으로하는 간선의 도착정점 값
				int start_to_next_dist = start_to_cur_dist + map[cur][i].first;

				// 기존의, 시작 노드에서 다음 노드까지의 최소 비용보다
				// 새롭게 계산한, 시작 노드에서 다음 노드까지의 비용이 더 작다면
				// 최소 비용을 업데이트
				if (dk[next] > start_to_next_dist)
				{
					dk[next] = start_to_next_dist;
					// 이제, 갱신된 경로가 최소 비용임을 주장하기 위해
					// 우선 순위 큐에 해당 경로 삽입
					pq.push(make_pair(-start_to_next_dist, next));
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



	cin >> V >> E;


	cin >> start;

	for (int i = 1; i < V + 1; ++i) {
		dk[i] = INF;
	}

	for (int i = 0; i < E; i++) //간선 정보(시작점/종료점/가중치)를 입력받아 인접리스트에 저장
	{
		int s = 0;
		int e = 0;
		int value = 0;

		cin >> s >> e >> value;
		map[s].push_back(make_pair(value, e));


	}



	dijkstra(start);

	for (int i = 1; i <= V; i++)
	{
		if (dk[i] == INF)
		{
			cout << "INF" << '\n';
		}
		else
		{
			cout << dk[i] << '\n';
		}

	}

	return 0;


}
