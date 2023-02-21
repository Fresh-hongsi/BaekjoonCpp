#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;


int N = 0; //지도 크기
int map[101][101] = { 0, }; //육지와 대륙 구분하는 지도, bfs함수 다 돌리면 대륙은 대륙번호가 2부터 차례로 표현되고, 바다는 0으로 표시됨
bool visited[101][101] = { false, }; //방문표시배열
int result = 999999; //결과값은 모든 계산 후에 가장 짧은 다리 길이로 구해짐
int di[4] = { -1,0,1,0 }; //행 변위 
int dj[4] = { 0,1,0,-1 }; //열 변위
int continentNum = 2; //시작 대륙번호는 2부터


//대륙 번호 매기기
void bfs(pair<int, int> start, int contNum)
{
	int starti = start.first;
	int startj = start.second;
	int num = contNum; //이 대륙의 번호 지정

	visited[starti][startj] = true;
	map[starti][startj] = num;
	queue< pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(starti, startj), num));

	while (!q.empty())
	{
		int curi = q.front().first.first;
		int curj = q.front().first.second;
		int curNum = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			//범위가 지도 안에 있고, 방문이 아직 안되었고, 육지라면 대륙번호로 해당 지도 좌표에 표시
			if (curi + di[i] >= 0 && curi + di[i] < N && curj + dj[i] >= 0 && curj + dj[i] < N && visited[curi + di[i]][curj + dj[i]] == false && map[curi + di[i]][curj + dj[i]] == 1)
			{
				q.push(make_pair(make_pair(curi + di[i], curj + dj[i]), curNum));
				visited[curi + di[i]][curj + dj[i]] = true;
				map[curi + di[i]][curj + dj[i]] = curNum;

			}
		}
	}

	
}

//대륙간의 최단경로 찾기
int bfs2(pair<int, int> start, int depth)
{
	int starti = start.first;
	int startj = start.second;
	int startDepth = depth; //현재 다리 길이

	visited[starti][startj] = true;
	int currentContinent = map[starti][startj];
	queue< pair<pair<int, int>, int> > q2;
	q2.push(make_pair(make_pair(starti, startj), depth));
	int tresult = 0; //start좌표에서 시작해서 구한 다리길이 
	bool flag = false; //우선 flag=false처리

	while (!q2.empty())
	{
		int curi = q2.front().first.first;
		int curj = q2.front().first.second;
		int curDepth = q2.front().second;
		q2.pop();
		for (int i = 0; i < 4; i++)
		{
			//범위가 지도 안에 있고, 방문되지 않았고, 욱지가 아니라 바다라면 큐에 저장
			if (curi + di[i] >= 0 && curi + di[i] < N && curj + dj[i] >= 0 && curj + dj[i] < N && visited[curi + di[i]][curj + dj[i]] == false && map[curi + di[i]][curj + dj[i]] == 0)
			{
				q2.push(make_pair(make_pair(curi + di[i], curj + dj[i]), curDepth + 1));
				visited[curi + di[i]][curj + dj[i]] = true;


			}

			//범위가 지도 안에 있고, 방문되지 않았고, 다른 대륙을 찾았다면 현재 depth를 tresult에 저장하고 함수 반환시도
			if (curi + di[i] >= 0 && curi + di[i] < N && curj + dj[i] >= 0 && curj + dj[i] < N && visited[curi + di[i]][curj + dj[i]] == false && map[curi + di[i]][curj + dj[i]] != currentContinent && map[curi + di[i]][curj + dj[i]] != 0)
			{

				tresult = curDepth;
				flag = true;
				break;


			}


		}

		//유효한 다리 길이를 찾았다면 while문 탈출
		if (flag == true)
		{
			break;
		}


	}

	//유효한 다리 길이라면(시작좌표 근처가 바다여서 다른 대륙을 찾을 수 있었던 경우라면) 찾은 다리길이 반환
	if (tresult > 0)
	{
		return tresult;
	}
	//유효하지 않은 다리 길이라면(다른 대륙을 찾을 수 없었던 경우라면) 애초에 불가능한 경우이므로 최대값으로 해서 반환
	else 
	{

		return 99999;
	}
}
	



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	//초기 지도 입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp = 0;
			cin >> temp;
			map[i][j] = temp;
		}
	}

	//지도에서 대륙찾아서 대륙번호로 지도에 표시
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if ((map[i][j] == 1))
			{
				bfs(make_pair(i, j),continentNum);
				continentNum++;
				
			}

			




		}
	}

	//모든 좌표를 돌아가며 다리를 만들어보기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] != 0)
			{
				int tempResult=bfs2(make_pair(i, j),0);
				//만약 찾은 다리 길이가 result보다 작은 경우라면 계속 갱신해나가면서 최소 다리길이 찾기
				if (result > tempResult)
				{
					result = tempResult;
				}
			}
			memset(visited, false, sizeof(visited));
		}
	}

	cout << result;
	return 0;

	

}
