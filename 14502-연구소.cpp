#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int answer = 0;
int dx[4] = { 0, -1, 0 , 1 };
int dy[4] = { -1, 0, 1, 0 };

void check_bfs(vector<vector<int>> l)
{
	//바이러스 퍼트리기

	queue<pair<int, int>> q; //바이러스가 있는 인덱스를 저장하기 위한 큐 생성

	//모든 칸을 하나씩 순회하며 우선 바이러스가 있는 위치를 큐에 저장
	for (int i = 0; i < l.size(); i++)
	{
		for (int j = 0; j < l[i].size(); j++)
		{
			if (l[i][j] == 2)
			{
				q.emplace(i, j);
			}
		}
	}

	// 큐가 빌때까지 동작 ,현재 바이러스 위치에 대응하여 바이러스가 퍼질 수 있으면 다시 큐의 뒤에 삽입->퍼트리는 과정
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x > -1 && next_x<l.size() && next_y>-1 && next_y < l[x].size() && l[next_x][next_y] == 0)
			{
				l[next_x][next_y] = 2;
				q.emplace(next_x, next_y);
			}
		}
	}

	//0의 최대 개수 찾아 갱신
	int cntVirus = 0; //0인 곳의 개수 0으로 초기화

	for (int i = 0; i < l.size(); i++)
	{
		for (int j = 0; j < l[i].size(); j++)
		{
			if (l[i][j] == 0)
			{
				cntVirus++;
			}
		}
	}

	//최대값으로 갱신
	answer = max(cntVirus, answer);
}

void dfs(vector<vector<int>> lab, int x, int y, int cur)
{
	lab[x][y] = 1; //해당 위치에 벽을 세움

	if (cur == 0) //만일 벽이 다 세워졌다면 이제 바이러스를 퍼뜨린 후 최대값을 찾아봐야함
	{
		check_bfs(lab);
		return; //현재 -의 최대값이 answer에 있는 채로 dfs함수 종료
	}

	else
	{
		for(int i=x;i<lab.size();i++) //l.size()는 연구소의 세로 길이 (행의 수)
			for (int j = 0; j < lab[x].size(); j++) //l[x].size()는 연구소의 가로 길이 (열의 수) //중복이 생기지만 0열은 0부터 다시 처음부터 찾아줌
			{
				if (lab[i][j] == 0) //만일 현재 위치에서 쭉 다음 번 dfs시도할 공간이 발견되면
					dfs(lab, i, j, cur - 1); //dfs시도
			}
	}
}

int main(void)
{
	int N = 0; //연구소의 세로 길이
	int M = 0; //연구소의 가로 길이
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) //초기 연구실 상황 입력
	{
		for (int j = 0; j < M; j++)
		{
			int temp = 0;
			cin >> temp;
			v[i][j] = temp;
		}
	}
	

	//연구실의 1행 1열부터 마지막 행,열 인덱스까지 벽이 없는 빈 공간이라면 벽을 하나씩 세워본다. 
	//벽의 개수는 2개로 시작, 2->1->0이 되면 3개의 벽이 다 세워진 것임!
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++)
		{
			if (v[i][j] == 0)
			{
				dfs(v, i, j, 2);
			}
		}
	}

	cout << answer;
	return 0;

}
