//dfs
//brute force

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int N = 0; //사람 수


vector<vector<int>> arr(20, vector<int >(20, 0)); //시너지 값(행렬) 저장할 이차원 배열
int maxValue = 987654321; //그냥 최대값
int result = 987654321; //결과를 내기 위해 큰 값 받아놓음


int teamCombination()
{
	//모든 조합에 대해 두 팀간의 시너지 값의 최소를 구하기 위해 v벡터에 조합이 될 0,1 값을 담음
	//01111 / 00111 / 00011 / 00001 의 케이스에 대해 각각 permutation함수를 적용하여 시너지를 구할 것임
	for (int i = 1; i < N; i++) 
	{
		vector<int> v;

		for (int a = 0; a < i; a++)
		{
			v.push_back(0);
		}

		for (int b = 0; b < N - i; b++)
		{
			v.push_back(1);
		}

		do
		{
			int startSum = 0; //스타트 팀의 시너지 총합 값
			int linkSum = 0; //링크 팀의 시너지 총합 값

			vector<int> startTeam; //스타트 팀에 배정된 사람 번호 저장
			vector<int> linkTeam; //링크 팀에 배정된 사람 번호 저장

			for (int i = 0; i < N; i++)
			{
				//v벡터에 0값이 들어가있던 인덱스는 스타트팀에 배정
				if (v[i] == 0)
				{
					startTeam.push_back(i);
				}

				//v벡터에 1값이 들어가있던 인덱스는 링크팀에 배정
				else
				{
					linkTeam.push_back(i);
				}
			}


			//스타트 팀원들 시너지 합 구하기
			for (int i = 0; i < startTeam.size() - 1; i++)
			{
				for (int j = i + 1; j < startTeam.size(); j++)
				{
					startSum += (arr[startTeam[i]][startTeam[j]] + arr[startTeam[j]][startTeam[i]]);
				}
			}

			//링크 팀원들 시너지 합 구하기
			for (int i = 0; i < linkTeam.size() - 1; i++)
			{
				for (int j = i + 1; j < linkTeam.size(); j++)
				{
					linkSum += (arr[linkTeam[i]][linkTeam[j]] + arr[linkTeam[j]][linkTeam[i]]);
				}
			}

			//계속해서 최소 차이가 되는 값을 구해나감
			result = min(result, abs(startSum - linkSum));
			
		} while (next_permutation(v.begin(), v.end()));
	}

	return result;
	
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> N; //사람 수 입력 받음

	for (int i = 0; i < N; i++) //팀이 되었을 떄의 시너지 값 입력받음
	{
		for (int j = 0; j < N; j++)
		{
			int temp = 0;
			cin >> temp;
			arr[i][j] = temp;
		}
	}


	int minValue=teamCombination(); //모든 조합을 통해 가장 두 팀간의 시너지 차이가 최소가되는 값 구해서 출력
	cout << minValue;
	
	return 0;

}
