#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int map[1001][1001];
bool visited[1001][1001] = { false, };
int M = 0; //행 크기
int N = 0; //열 크기
queue<pair<int, int>> q;
int di[4] = { -1,0,1,0 }; //상우하좌 움직일 때 행의 변위
int dj[4] = { 0,1,0,-1 }; //상우하좌 움직일 때 열의 변위
int counter = 0; //모든 토마토가 익는 데까지 걸리는 날짜 

int qControlSize = 0; //익은 토마토 중에 현재 날짜에 대응하는 토마토만 큐에서 빼서 bfs하기 위한 값
int nextQcontrolSize = 0; //bfs하다 추가로 익을 수 있는 토마토가 발견된 경우 이 값을 증가시켜줌으로써 다시 main함수에서 bfs호출했을 때 전에 갱신됐던 nextQcontrolSize는 이미 qControlSize에 저장되어있으므로 다음 날짜에서 찾을 때도 qControlSize가 0이 될때까지 해당 토마토들을 bfs해주면 됨


void bfs(void)
{
	
	while (qControlSize>0) //이 반복문은 같은 날짜에 같이 익은 토마토들만 큐에서 빼서 bfs할 수 있게 하기 위함
	{
		int curi = q.front().first; //꺼낸 토마토의 행 인덱스
		int curj = q.front().second; //꺼낸 토마토의 열 인덱스
		visited[curi][curj] = true; //해당 토마토 방문표시
		q.pop(); //큐 가장 앞에 있던 토마토 꺼내기
		qControlSize--; //같은 날짜에 익어있던 토마토 개수 -1 해주기-> 이 값이 0이되면 같은 날짜에 익은 토마토를 다 꺼낸 것이므로 main함수로 갈 수 있도록함

		for (int i = 0; i < 4; i++) //상우하좌 돌아가며 익을 수 있는 토마토가 있는지 확인
		{
			int nexti = curi + di[i];
			int nextj = curj + dj[i];

			if (nexti >= 0 && nexti < M && nextj >= 0 && nextj < N && visited[nexti][nextj] == false && map[nexti][nextj] == 0) //범위 안에 있는 토마토이고, 토마토가 이미 방문안됐고, 토마토가 안익었다면
			{
				visited[nexti][nextj] = true; //토마토 방문표시
				map[nexti][nextj] = 1; //익을 예정임을 표시
				q.push(make_pair(nexti, nextj)); //다음에 이함수가 호출됐을 때 이 익은 토마토에서 다시 bfs해봐야하므로 큐에 push
				nextQcontrolSize++; //다음 qControlSize를 알아내기 위해 nextQcontrolSize++해주기
				
			}
		}

	}

 	if (!q.empty()) //만약 큐가 다 비지 않아서 다음에 또 bfs함수를 main에서 호출할 여지가 있는 경우
	{
		qControlSize = nextQcontrolSize; //같이 익은 토마토가 큐의 처음부터 어느 인덱스까지 있는지 알려주기 위해 nextQcontrolSize를 qControlSize에 대입연산자 적용
		nextQcontrolSize = 0; //nextQcontrolSize은 다시 구해줘야하므로 0으로 초기화
		counter++; //같은날짜에익은 토마토 모두 확인하고 익음표시해줬으므로 +1해주기
	}
	
	return;
}

void check() 
//모든 bfs가 끝난 후 상황을 조사하는 과정
//다 익을 수 있는 경우->날짜
//다 못익는 경우 -> -1
//이미 상자 안 토마토가 다 익어있는 경우 -> 0
//을 출력해주기 위한 함수
{
	bool flag = true;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == -1 || map[i][j] == 1)
				continue;

			else
			{
				flag = false;
				cout << -1;
				return;
			}
		}
	}

	if (flag == true)
	{
		cout << counter;
		return;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N >> M;

	//토마토 상자를 초기화해주는 과정
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp = 0;
			cin >> temp;
			map[i][j] = temp;
			if (map[i][j] == 1) //처음부터 익어있던 토마토는 q에 push해서 bfs함수 호출 시 바로 이 토마토들부터 너비우선탐색 할 수 있도록 함
			{
				q.push(make_pair(i, j));
				qControlSize++; //다음 bfs시 내가 큐에서 꺼내볼 토마토 개수 count
			}
		}
	}

	while (!q.empty()) //큐가 빌때까지 너비우선탐색 시도
	{
		bfs();
	}

	check(); //탐색 종료 후 다 익는데 얼마나 걸릴 지 count값 출력
	//다 익을 수 있는 경우->날짜
	//다 못익는 경우 -> -1
	//이미 상자 안 토마토가 다 익어있는 경우 -> 0
	return 0;

}
