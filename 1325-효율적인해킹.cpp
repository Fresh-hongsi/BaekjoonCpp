//Graph
//BFS


#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int vertex = 0; //컴퓨터 개수
int edge = 0; //신뢰관계 간선 개수
vector<int>adjList[100001]; //신뢰관계 인접 리스트
vector<bool>visited(100001, false);
vector<int> resultSet(100001,0); //해당 컴퓨터를 시작 정점으로 했을 때 몇개의 컴퓨터를 해킹할 수 있는지 저장하는 배열
int maximum = 0; //하나의 컴퓨터를 해킹헀을 때 가장 많이 해킹할 수 있는 최대 컴퓨터 개수

//bfs 방식으로 탐색
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	int curInfected = 1; //초기 start 컴퓨터는 해킹 되었으므로 해킹 값 +1 시켜줌

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto& i : adjList[cur]) //다음 방향 간선에 있는 컴퓨터들에 대해
		{
			if (visited[i] != true) //방문되지 않았다면
			{
				q.push(i);
				visited[i] = true; //방문 표시
				curInfected++; //해킹 값 +1
			}
		}
	}

	resultSet[start] = curInfected; //시작 컴퓨터값을 인덱스로 하여 해킹 최대 컴퓨터 개수 저장
	
	if (maximum < curInfected) //최대값 갱신 과정
	{
		maximum = curInfected;
	}
	
	
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> vertex >> edge; //컴퓨터 개수와 신뢰관계 간선 개수 입력받음


	//단방향 그래프, 신뢰관계 잘 살펴보면 반대방향으로 인접리스트 작성해야함
	//신뢰관계를 인접리스트로 표현
	for (int i = 1; i <= edge; i++)
	{
		int from = 0;
		int to = 0;
		cin >> to >> from;

		
		adjList[from].push_back(to);

	}

	//각 컴퓨터에 대해 bfs방식 취함. 한 컴퓨터에 대해 bfs 방식 취했으면 다시 visited배열을 초기 상태로 돌려놔야함
	for (int i=1;i<=vertex;i++)
	{
		
		bfs(i);
		fill(visited.begin(), visited.end(), false);

	}


	
	
	//각 컴퓨터에 대해 최대 해킹값을 갖는 컴퓨터의 번호 출력
	for (int i=1;i<=vertex;i++)
	{
		if (resultSet[i] == maximum)
		{
			cout << i << ' ';
		}
	}

	return 0;


}
