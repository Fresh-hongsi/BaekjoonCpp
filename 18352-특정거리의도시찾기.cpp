//Graph
//BFS
//Dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int vertex = 0; //도시 개수
int edge = 0; //간선 개수
int dist = 0; //시작정점과의 최단 거리 길이
int starting = 0; //시작 정점
vector<int> adjList[300001]; //인접리스트
vector<bool> visited(300001, false); //방문표시 배열
vector<int> length(300001, 0); //해당 정점이 시작 정점으로부터 얼마나 떨어져있는 지 저장해놓은 배열
vector<int>result; //dist거리만큼 떨어져 있는 간선을 저장한 배열



void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	length[start] = 0; //시작정점과 시작 정점과의 거리는 0

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto& i : adjList[cur])
		{
			if (visited[i] != true) //방문되지 않은 정점이라면
			{
				q.push(i);
				length[i] = length[cur]+1; //전 정점과의 거리 +1
				visited[i] = true; //방문표시
				if (length[i] == dist) //거리가 dist만큼 떨어진 정점이 발견되었다면
				{
					result.push_back(i); //result에 추가
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

	cin >> vertex >> edge >> dist >> starting;

	for (int i = 1; i <= edge; i++) //단방향 간선을 인접리스트에 세팅
	{
		int from = 0;
		int to = 0;
		cin >> from>>to;
		adjList[from].push_back(to);
	}

	bfs(starting); //시작점에 대하여 bfs시작
	
	if (result.size() == 0) //만약 해당 거리만큼 떨어져 있는 간선이 없다면 -1출력
	{
		cout << -1;
	}

	else //해당 거리만큼 떨어져 있는 간선이 있다면 오름차순 정렬 후 출력
	{
		sort(result.begin(), result.end());
	}

	for (auto& i : result)
	{
		cout << i << '\n';
	}

	return 0;



}

