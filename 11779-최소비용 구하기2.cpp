//우선순위 큐를 활용한 다익스트라 -> 1753 - 1916번 순서대로 우선 참고!

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

vector<int> adjPath(MAX_NODE, 0); //해당 인덱스에 대응하는 값은 해당 인덱스에 오기 바로 전의 최단경로가 되는 정점 -> ex: adjPath[5]=4 : 5번 정점으로 가는 최단 경로가 되기 위해 바로 전에 필수적으로 들러야하는 정점
//이렇게 저장했을 때, end정점으로부터 start정점이 나올 때까지 역추적, 그 과정에서 나오는 값을 후에 path1 배열에 저장 후 역순으로 출력할 것임 -> start정점으로부터 end정점까지의 경로 추적 완성 

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
				adjPath[next] = cur; //next까지의 거리가 갱신되었으므로 현재 next로 최단경로로 가기 위해선 반드시 cur을 들러야함. 이 정보를 adjPath에 저장
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
	

	dijkstra(start); //헤당 시작정점으로부터 모든 정점까지의 최단경로 탐색 후 dk배열에 저장

	cout << dk[end]; //시작 정점으로부터 end정점까지의 최단경로 길이 출력
	cout << '\n';

	vector<int>path1; //start부터 end까지 가기 위한 path정점들이 역순으로 저장될 배열
	path1.push_back(end); //우선 끝 정점을 넣어줌
	
	int c = end; //c값이 idx가 되어 경로가 되는 정점을 찾아줄 것임
	while (c!=start) //c가 start가 되면 경로가 되는 path정점 다 찾은 것이므로 반복문 탈출 
	{
		int temp = adjPath[c];
		path1.push_back(temp);
		c = temp;
	}

	cout << path1.size() << '\n'; //path1에 저장된 정점의 길이=경로에 포함되어있는 도시의 개수

	for (int i = path1.size() - 1; i >= 0; i--) //path1에 저장되어있는 path도시를 역순으로 출력
	{
		cout << path1[i] << ' ';
	}
	return 0;



}
