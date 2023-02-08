//사이클에 해당하는 모든 정점 찾는 문제

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <memory.h>
using namespace std;

int N = 0;
vector<int> map[3001]; //인접리스트
bool visited[3001] = { false, };//해당 인덱스에 해당하는 정점이 방문되었는가
bool finished[3001] = { false, }; //해당 인덱스로 시작하는 사이클이 검출되었는가
bool cyclicVertex[3001] = { false, };//사이클을 형성하는 정점이면 true표시
vector<int> parent(3001,0); //dfs할 떄 각 정점의 부모를 저장해놓는 필드
int dist = 0; //각 정점과 사이클을 이루는 정점까지의 최소거리
bool flag = false; //각 정점과 사이클을 이루는 정점까지의 최소거리를 구하는 과정에서 dfs를 하는데, dfs의 종료조건 플래그


void findCyclicVertex(int node, int next) //부모 자식 간의 관계 통해 사이클에 해당하는 정점을 표시하기
{
	cyclicVertex[node] = true; //해당 정점은 사이클 이루는 정점 중의 하나임

	if (node == next) //node와 next값이 같으면 모든 부모관계 조사 파악을 통해 사이클 이루는 정점을 모두 찾은 것(탈출조건)
	{
		return;
	}
	else
	{
		findCyclicVertex(parent[node], next); //다음 부모 관계 조사
	}
}

void findAllCycles(int node) //사이클을 찾는 함수
{
	visited[node] = true; //해당 정점 방문표시
	
	for (auto next : map[node])
	{
		if (visited[next] == false) //아직 next에 해당하는 정점에 방문하지 않았다면 -> 계속해서 현재 노드를 부모로 설정하고, next로 dfs시도
		{
			parent[next] = node; //현재 노드를 다음 노드의 부모로 설정
			findAllCycles(next); //dfs
		}
		//만약 next가 방문되었던 노드이고, 현재 노드의 부모가 next와 다르고(같으면 2개 정점간의 사이클이므로 안됨->사이클은 3개 이상의 정점들 간에 형성되어야함), next에 해당하는 정점을 시작으로 하는 사이클이 발견되지 않았다면 -> 사이클 검출가능
		else if (finished[next] == false && !(parent[node]==next))
		{
			findCyclicVertex(node, next); //사이클에 해당하는 정점 찾기
		}
	}
	finished[node] = true; //해당 정점으로 시작하는 사이클을 찾았음을 표시
}

void distance(int idx) 
{
	visited[idx] = true; //해당 정점 방문표시

	if (cyclicVertex[idx] == true) //탈출조건 -> idx가 사이클 이루는 정점 중에 하나가 되면 최단거리값인 dist를 구한 것임
	{
		flag = true;
		return;
		
	}
	for (auto next : map[idx]) //다음 정점 찾기
	{
		if (visited[next] == false ) //다음 정점이 방문안된 정점이면
		{
			dist++; //거리를 하나 늘려서
			distance(next); //최단거리 다시 찾기 시도
			if (flag == true) //만약 더 아래의 함수호출에서 최단거리를 찾아 반환된상태라면
			{
				return; //그대로 계속 반환
			}
			else //그게 아니라면 재귀 깊이 하나 줄이고(dist--)다시 next정점 세팅해서 최단거리 찾기 시도
			{
				dist--;
			}
		}
	}
	return; 
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 1; i <= N; i++) //인접리스트 저장
	{
		int s = 0;
		int e = 0;
		cin >> s >> e;

		map[s].push_back(e);
		map[e].push_back(s);

	}

	findAllCycles(1); //1번 정점부터 시작하는데, 이 함수 호출 한번만으로 모든 사이클을 찾고, 사이클을 이루는 정점들은 cyclicVertex에 저장될 것
	memset(visited, false, sizeof(visited)); //사이클을 이루는 모든 정점들을 찾으면, 이제 각 정점과 사이클을 이루는 정점들과의 최소거리를 찾기 위해 visited배열을 재활용해야하므로 visited배열을 초기화 처리해줌
	

	for (int i = 1; i <= N; i++)
	{
		dist = 0; //i번째 정점과 사이클 사이의 최단거리 값이 들어갈 변수 초기화
		flag = false; //매번 dfs할때마다 flag는 false처리 다시 해주기
		if (cyclicVertex[i] == true) //만약 i번째 정점이 사이클을 이루는 정점 중의 하나라면, dfs통해 구할 필요 없이 바로 최단거리는 0이므로 이를 출력
		{
			cout << 0 << ' ';
		}

		else
		{
			distance(i); //dfs로 i번쨰 정점과 사이클 이루는 정점까지의 최단거리 찾기
			memset(visited, false, sizeof(visited)); //i번쨰 정점과 사이클 이루는 정점까지의 최단거리를 dfs통해 구하면, 다시 visited배열을 초기화해줌
			
			cout <<dist << ' ';

		}
	}

	return 0;
	
	

}
