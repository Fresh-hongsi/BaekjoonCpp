//수학
//정수론

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


//약수를 모두 입력 받아 오름차순 정렬
// 어떤 구하고자 하는 수가 x이면
// 1*x = 1보다 큰 가장 작은 약수*x보다 작은 가장 큰 약수
//따라서 x를 구하려고 하면 입력받은 수 중 가장 작은 수 * 입력받은 수 중 가장 큰 수
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	int result = v[0] * v[v.size() - 1];
	cout << result;

}
