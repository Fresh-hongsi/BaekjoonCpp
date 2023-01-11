#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//greedy 알고리즘
//어떤 방식으로 순열을 갖던지 간에 무조건 실의 길이가 최소가 되는 값은
//오름차순 정렬했을 때 2*{가장 큰 값을 갖는 구슬-가장 작은 값을 갖는 구슬| 이다.
//질문게시판 참조
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	cin >> n;

	vector<int>ball;

	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;

		ball.push_back(temp);

	}

	sort(ball.begin(), ball.end()); //오름차순 정렬
	int minVal = 2*(ball[n-1]-ball[0]); //그리디 적용


	cout << minVal;
	return 0;
}
