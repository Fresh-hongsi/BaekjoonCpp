//수학
//다이나믹프로그래밍
//조합론

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T = 0;
	cin >> T;

	vector<vector <int>> v(30,vector<int>(30,0)); //30*30 2차원 벡터 0으로 초기화
	//점화식: v[i][j] = v[i-1][1]+ ---- + v[i-1][j-1] 임
	//dp문제이므로 입력에 상관 없이 30*30에 미리 값을 구해 놓으면 입력이 들어올 경우 그에 해당하는 값만 출력해주면 된다.

	for (int i = 1; i < 30; i++)
	{
		v[1][i] = i;
		
	}

	//값 구하기
	for (int i = 2; i < 30; i++)
	{
		for (int j = 1; j < 30; j++)
		{
			for (int k = 1; k < j; k++)
			{
				v[i][j] += v[i - 1][k];
			}
		}
	}

	//입력 받아서 출력
	while (T--)
	{
		int N = 0;
		int M = 0;
		cin >> N >> M;
		cout << v[N][M] << '\n';
		

	}
	return 0;
}
