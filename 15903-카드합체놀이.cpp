#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<long long, vector<long long>, greater<long long>> pq; // top에 오는 숫자가 가장 작고, 오름차순 정렬

	int N = 0; // 카드 개수
	int fusion = 0; // 합체 횟수

	// 입력
	cin >> N >> fusion;
	for (int i = 0; i < N; i++)
	{
		long long temp = 0;
		cin >> temp;

		pq.push(temp);

	}

	// 카드 합치기 - 작은 수들을 pop하고 합친 후 push해주기
	for (int i = 0; i < fusion; i++)
	{
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();

		long long r = a + b;
		pq.push(r);
		pq.push(r);
	}

	// 최종 결과 덧셈
	long long result = 0;
	while(!pq.empty())
	{
		result += pq.top();
		pq.pop();
	}

	cout << result;
	return 0;
}
