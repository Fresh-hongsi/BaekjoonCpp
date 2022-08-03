//Graph
//DFS

#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int node = 0; //컴퓨터 수
int edge = 0; //간선 수
vector<int>adjList[101]; //인접리스트
vector<bool> visited(101, false); //방문표시 배열
int infected = 0; //감염된 컴퓨터 총 개수


void dfs(int start)
{
	int cur = start; //현재 참조하고 있는 정점
	visited[cur] = true; //방문했으므로 true표시
	infected++; //해당 컴 바이러스 감염됨

	for (auto& i : adjList[cur]) //cur의 인접 컴퓨터 중에
	{
		if (visited[i] != true) //방문하지 않은 곳이 있다면
		{
			dfs(i); //해당 컴을 다음 노드로 하고 dfs 진행
		}
	}

}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	

	cin >> node;
	cin >> edge;

	

	while (edge--) //인접리스트에 양뱡향 간선 세팅하는 과정
	{
		int from;
		int to;
		cin >> from >> to;

		adjList[from].push_back(to);
		adjList[to].push_back(from);
	}

	

	dfs(1); //시작 정점을 1로 세팅
	cout << infected-1; //총 감염 컴퓨터 수에서 초기 1번 컴퓨터 뺀 값이 결과값임
	return 0;
}
