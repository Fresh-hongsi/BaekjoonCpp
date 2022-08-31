//Graph
//DFS

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> relation(2000);
vector<bool> visited(2000, false);
bool flag = false;

void dfs(int cur, int number) //현재 정점, 현재까지 관계맺은 사람 수
{
	if (visited[cur] == false) //만약 방문되지 않은 정점이라면
	{
		visited[cur] = true; //방문 표시
		number += 1; //친구관계 수 증가
	}

	if (number == 5) //만약 친구관계수가 5이면 1출력 후 flag값 true로 만든 후 프로세스 종료
	{
		cout << 1;
		flag = true;
		exit(0);
	}

	for (auto i : relation[cur]) //현재 정점과 인접한 정점 중에
	{
		if (visited[i] != true) //방문되지 않은 정점이 있다면
		{
			visited[i] = true; //방문
			number += 1; //친구관계 수 증가
			dfs(i, number); //정점과 친구관계수를 다시 세팅하여 함수 호출
			
			//---------------//만일 더 뻗어나갈 곳이 없어 전 함수가 호출 종료된 경우
			visited[i] = false; //해당 정점 방문 표시 취소
			number -= 1; //친구관계 수 감소

		}
		
			
	}

}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0; //사람 수
	int M = 0; //친구 관계 수

	cin >> N >> M;

	for (int i = 0; i < M; i++) //인접리스트 입력받아 저장
	{
		int from = 0;
		int to = 0;

		cin >> from >> to;

		relation[from].push_back(to);
		relation[to].push_back(from);
	}

	
	for (int i = 0; i <= N - 1; i++) //시작 정점을 바꿔가며 규칙에 맞는 조건이 있는지 확인
	{
		dfs(i,0);
		fill(visited.begin(), visited.end(), false); //시작 정점이 바뀔때마다 visited배열은 초기화
		
	}

	if (flag == false) //만약 그런 관계를 하나도 못찾았다면 0출력
	{
		cout << 0;
	}


}
