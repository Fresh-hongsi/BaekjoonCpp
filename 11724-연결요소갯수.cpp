//Graph
//DFS
//BFS

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int vertex = 0;
int edge = 0;
vector<int> adjList[1001];
vector<bool> visited(1001,false);


void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int next = q.front();
		q.pop();

		for (auto& i : adjList[next])
		{
			if (visited[i] != true)
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}



void dfs(int start)
{
	visited[start] = true;

	for (auto& i : adjList[start])
	{
		if (visited[i] != true)
		{
			dfs(i);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> vertex >> edge;
	int connectedC=0; //연결 요수 개수

	for (int i = 1; i <= edge; i++) //인접리스트 초기화
	{
		int from = 0;
		int to = 0;
		cin >> from >> to;

		adjList[from].push_back(to);
		adjList[to].push_back(from);
	}

	for (int i = 1; i <= vertex; i++) //방문 안해본 모든 정점에 대해 탐색해보기
	{
		if (visited[i] != true)
		{
			//bfs(i);
			dfs(i);
			connectedC++;
		}
	}

	cout << connectedC;
	return 0;
}
