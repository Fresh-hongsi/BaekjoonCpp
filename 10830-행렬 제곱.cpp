#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//분할정복을 이용한 거듭제곱
// C^n일 경우
//n이 짝수 -> C^(n/2) * C^(n/2)
//n이 홀수 -> C^(n/2의 몫) * C^(n/2의 몫)* C

//int로 문제 풀 시 틀림 -> long long으로 해야함
class Matrix
{
public:
	long long rows;
	long long cols;
	vector<vector<long long>> matrix;

	Matrix(int m, int n)
	{
		this->rows = m;
		this->cols = n;
		matrix.resize(m, vector<long long>(n));	//m행 n열의 이차원 벡터 matrix 생성
	}
};

Matrix MultiplyMatrix(Matrix temp1, Matrix temp2) //두개의 행렬을 곱해주는 함수
{
	long long MatrixLength = temp1.rows; //n*n행렬인 temp1과 temp2를 곱할 것이므로 행렬의 행, 열 길이는 같다

	Matrix ResultMatrix(MatrixLength, MatrixLength); //두 행렬을 곱한 결과 행렬
	for (int i = 0; i < MatrixLength; i++)
	{
		for (int j = 0; j < MatrixLength; j++)
		{
			
			for (int k = 0; k < MatrixLength; k++)
			{
				ResultMatrix.matrix[i][j] = (ResultMatrix.matrix[i][j] + ((temp1.matrix[i][k] * temp2.matrix[k][j]) % 1000)) % 1000;
			}
		}
	}

	return ResultMatrix;
}

Matrix DevideAndConquer(Matrix init, long long power) //거듭제곱수 크기를 줄여가며 분할정복
{
	if (power == 1) //만약 거듭제곱수가 1이면 반환
	{
		return init;
	}

	Matrix tempMatrix = DevideAndConquer(init, power / 2); //재귀를 타고 들어가며 분할하기

	if (power %2== 0) //거듭제곱수가 짝수였다면
	{
		return MultiplyMatrix(tempMatrix, tempMatrix); //n이 짝수 -> C^(n/2) * C^(n/2)
	}

	else
	{
		return MultiplyMatrix(init, MultiplyMatrix(tempMatrix, tempMatrix)); //n이 홀수 -> C^(n/2의 몫) * C^(n/2의 몫)* C
	}
}
int main(void)
{
	long long N = 0; //행렬의 행,열 크기
	long long B = 0; //거듭제곱수

	cin >> N >> B;

	Matrix initial(N, N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> initial.matrix[i][j];
		}
	}

	Matrix Result=DevideAndConquer(initial, B);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Result.matrix[i][j] % 1000 << ' ';
		}

		cout << '\n';
	}

	return 0;


}
