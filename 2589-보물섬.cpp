#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;


int N = 0;
int M = 0;
int map[51][51] = { 0, };
bool visited[51][51] = { false, };
int result = 0;
int di[4] = {-1,0,1,0};
int dj[4] = { 0,1,0,-1 };


int bfs(pair<int, int> start,int curDepth)
{
	int starti = start.first;
	int startj = start.second;
	int time = curDepth;

	visited[starti][startj] = true;
	queue< pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(starti, startj), time));
	
	while (!q.empty())
	{
		int curi = q.front().first.first;
		int curj = q.front().first.second;
		int curTime = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (curi + di[i] >= 0 && curi + di[i] < N && curj + dj[i]>=0 && curj + dj[i] < M && visited[curi + di[i]][curj + dj[i]] == false && map[curi + di[i]][curj + dj[i]] == 1)
			{
				q.push(make_pair(make_pair(curi + di[i], curj + dj[i]), curTime+1));
				visited[curi + di[i]][curj + dj[i]] = true;

				if (time <= curTime + 1)
				{
					time = curTime + 1;
				}
			}
		}
	}

	return time;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char temp = 0;
			cin >> temp;
			if (temp == 'W')
			{
				map[i][j] = 0;
			}

			if (temp == 'L')
			{
				map[i][j] = 1;
			}
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((map[i][j]==1)&&(visited[i][j]==false))
			{
				int tempResult=bfs(make_pair(i,j),0);
				if (tempResult > result)
				{
					result = tempResult;
				}
			}

			memset(visited, false, sizeof(visited));

			


		}
	}

	cout << result;

}
