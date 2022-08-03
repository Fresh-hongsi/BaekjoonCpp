//Data Sturcture
//Deque

#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	deque<pair<int, int>> dq; //dq 각 요소는 pair, pair.first=해당 요소의 초기 순서, pair.second=다음 몇번 째 풍선을 터뜨릴 지에 대한 이동량

	int N = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int temp = 0;
		cin >> temp;
		dq.push_back(pair<int, int>(i, temp)); //풍선의 순서번호와 다음 풍선과의 거리(이동량) 정보를 덱의 요소로 저장
	}

	pair<int,int> cur; //현재 터뜨릴 풍선
	bool flag = true; //터뜨릴 풍선이 덱의 맨 앞에 있는지 맨 뒤에 있는 지 확인시켜주는 변수

	while (1)
	{
		if (flag == true) //flag가 true라면 터뜨릴 풍선이 덱의 맨 앞에 있음
		{
			cur = dq.front(); //터뜨릴 풍선을 cur에 저장
			dq.pop_front(); //풍선 터뜨리기
			cout << cur.first << ' '; //cur.first는 풍선의 번호인데, 이를 출력
		}

		if (flag == false) //flag가 false라면 터뜨릴 풍선이 덱의 맨 뒤에 있음
		{
			cur = dq.back(); //터뜨릴 풍선을 cur에 저장
			dq.pop_back(); //풍선 터뜨리기
			cout << cur.first << ' '; //cur.first는 풍선의 번호인데, 이를 출력
		}
		
		if (dq.empty()) //만약 다 터뜨렸다면 반복문 탈출
		{
			break;
		}

		if (cur.second>0) //cur.second는 현재 터뜨린 풍선으로부터 다음 터뜨릴 풍선까지의 거리, 방향 정보 담김. 이 값이 양수라면 시계방향으로 움직여야함
		{
			for (int i = 0; i < cur.second-1; i++) //해당 수만큼 이동하기
			{
				pair<int, int> temp = dq.front();
				dq.pop_front();
				dq.push_back(temp);
				
			}
			flag = true; //시계방향으로 움직였다면 다음 터뜨릴 풍선은 덱의 맨 앞에 있음
		}

		else
		{
			cur.second = -(cur.second); //cur.second가 음수이므로 이를 양수로 변환에 다음 풍선까지의 거리계산
			for (int i = 0; i < cur.second-1; i++) //해당 수만큼 이동하기
			{
				pair<int, int> temp = dq.back();
				dq.pop_back();
				dq.push_front(temp);
				
			}
			flag = false; //반시계방향으로 움직였다면 다음 터뜨릴 풍선은 덱의 맨 뒤에 있음
		}


	}

		
	
}
