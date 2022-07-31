#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sequence(20,0); //입력받은 수열
int answer = 0; //정답 개수
int N = 0;
int S = 0;


void backtracking(int cur, int sum) //cur은 현재 인덱스, sum은 전항까지의 합
{

	if (cur == N) //끝까지 가지치기 탈출조건
	{
		return;
	}

	if (sum+sequence[cur] == S) //조건 만족하면 정답 추가하기
	{
		answer++;
	}

	
	backtracking(cur + 1, sum + sequence[cur]); //이번 항 선택하고 가지 뻗기
	backtracking(cur + 1, sum); //이번 항 선택 안하고 가지 뻗기






}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		cin >> sequence[i];
	}

	backtracking(0, 0); //백트래킹 시작. 1번항을 더하기 전에 기본 조건을 줌
	cout << answer;
}
