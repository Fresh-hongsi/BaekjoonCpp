//dfs
//brute force
// 2024.4.13 재풀이

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int>visited(21, false); //해당 사람이 선택되었는지 저장할 배열
int N = 0; //사람 수
vector<int> startTeam; //스타트 팀에 배정된 사람 번호 저장
vector<int> linkTeam; //링크 팀에 배정된 사람 번호 저장
int startSum = 0; //스타트 팀의 시너지 총합 값
int linkSum = 0; //링크 팀의 시너지 총합 값
vector<int> difference; //모든 경우의 수에 대해 스타트팀과 링크 팀의 차이값을 저장할 배열
vector<vector<int>> arr(20, vector<int>(20, 0)); //시너지 값(행렬) 저장할 이자춴 배열

void dfs(int cur)
{

	if (visited[cur] == false) //해당 사함이 선택되지 않았다면
	{
		visited[cur] = true; //해당 사람을 스타트팀에 선택하기
		startTeam.push_back(cur); //해당 사람을 스타트팀에 배정
	}


	if (startTeam.size() == (N / 2)) //스타트팀에 들어갈 모든 사람이 선택되었다면 함수호출 종료
	{
		return;
	}

	
	
	for (int i = cur + 1; i <= N; i++) //다음 선택할 사람들에 대해
	{
		if (visited[i] == false) //아직 그 사람이 선택되지 않았다면
		{
			
			dfs(i); //스타트 팀에 넣어보기

			if (startTeam.size() == N / 2) //아직 인원이 다 차서 호출 함수가 종료된 것이라면
			{
				for (int j = 1; j <= N; j++) //스타트팀에 배정되지 않은 사람들을 링크 팀에 배정하기
				{
					if (visited[j] == false)
					{
						linkTeam.push_back(j);
					}
				}

				for (int m = 0; m < startTeam.size() - 1; m++) //배정 완료된 스타트팀과 링크팀의 시너지 총합 값 계산
				{
					for (int n = m + 1; n < startTeam.size(); n++)
					{
						startSum += arr[startTeam[m] - 1][startTeam[n] - 1];
						startSum += arr[startTeam[n] - 1][startTeam[m] - 1];
						linkSum += arr[linkTeam[m] - 1][linkTeam[n] - 1];
						linkSum += arr[linkTeam[n] - 1][linkTeam[m] - 1];
					}
				}
				int diffTemp = abs(startSum - linkSum); //시너지 값의 차이 계산
				difference.push_back(diffTemp); //차이들을 저장할 배열에 해당 경우에 대한 차이값을 저장
			}
			
			visited[i] = false; //마지막으로 팀에 들어갔던 사람을 배정 안함 처리
			startTeam.pop_back(); //스타트 팀에 마지막으로 들어갔던 사람을 제외해보기
			linkTeam.clear(); //다른 case를 조사할 것이므로 linkteam은 다음 startteam에 따라 결정되도록 비워주기
			
			linkSum = 0; //링크 팀시너지 총 합값 다음 case 구하기 위해 0으로 초기화
			startSum = 0; //스타트 팀시너지 홍 합값 다음 case구하기 위해 0으로 초기화
		}
	}
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

	dfs(1); //팀을 나누는 것은 dfs(1)로 시작하는 것만 구하면 모든 경우의 수에 대해 검사 가능
	sort(difference.begin(), difference.end()); //오름차순 정렬된 값의 첫번째 값이 두 팀 시너지 값의 최소값
	cout << difference[0]; //정답 출력
	return 0;

}
