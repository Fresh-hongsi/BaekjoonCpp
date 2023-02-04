#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
//위상 정렬을 이용해 사이클 찾기
// 모든 노드를 방문하기 전에 큐에 빈다면 사이클이 존재한다고 판단

int tc = 0;
int num = 0;
vector<int> map[1001]; //인접리스트
bool visited[1001]; //방문표시 배열

int cycleCounter = 0; //찾은 사이클 개수

void dfs(int node)
{
	visited[node] = true; //해당 정점 방문표시

	for (auto i: map[node]) //해당 정점에 연결된 다른 한개의 정점을 계속해서 깊이 우선 탐색
	{
		int next = i;
		if (visited[next] != true) //next 노드가 아직 방문되지 않았다면 dfs시도
		{
			dfs(next);
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> tc;

	while (tc--)
	{
		cycleCounter = 0; //tc마다 사이클 개수 0으로 초기화
		cin >> num;
		memset(map, 0, sizeof(map)); //tc마다 인접리스트 초기화
		memset(visited, false, sizeof(visited)); //tc마다 방문표시 배열 초기화

		for (int start = 1; start <= num; start++) //인접리스트 생성
		{
			int end = 0;
			cin >> end;

			map[start].push_back(end);

		}

		for (int i = 1; i <= num; i++) //dfs를 활용한 사이클 찾기
		{
			if (visited[i] != true) //만약 방문하지 않은 정점이라면 dfs로 사이클 찾기 시도
			{
				dfs(i);
				cycleCounter++; //다 찾았으면 사이클 개수 카운트 1 증가
			}
		}

		cout << cycleCounter << '\n';

	}

	return 0;

}
