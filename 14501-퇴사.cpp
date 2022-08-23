//brute-force

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> requiredTime; //상담에 걸리는 시간 배열
vector<int> requiredPay; //상담했을 경우 받는 급여
vector<bool> checker(15000, false); //해당 상담을 채택했으면 true, 아니면 false
vector<int> costArr; //가능한 모든 조합의 급여 비용 계산값이 저장된 배열
int retirement_Date = 0;


bool comp(int a, int b) //내림차순 비교함수
{
	return a > b;
}

void dfs(int cur) //상담 가능한 모든 건수를 만들어서 그 떄의 급여값을 계산해주는 함수 -> 재귀, dfs
{
	if (cur >= retirement_Date + 1) //퇴사날짜보다 뒤의 상담은 받을 수 없음
	{
		return;
	}

	if (cur + requiredTime[cur] > retirement_Date+1) //퇴사날짜 전에 받은 상담일지라도, 퇴사 후까지 상담을 진행해야하면 받을 수 없음
	{

		return;
	}

	checker[cur] = true; //그 외의 경우 해당 상담을 채택


	for (int i = cur + requiredTime[cur]; i <= retirement_Date+1; i++) //받을 수 있는 모든 상담을 탐색
	{
		
		if (checker[i] != true) //아직 채택하지 않은 상담이라면
		{

			dfs(i); //그 상담을 채택하고 다른 또 받을 상담이 있는지 탐색
			
			int cost = 0; //dfs호출이 다 끝났다면 해당 조합을 1가지 찾았다는 것으로 그 조합일 때의 급여 계산
			for (int j = 0; j <= retirement_Date; j++)
			{
				if (checker[j] == true) //채택한 상담에 대해
				{
					cost += requiredPay[j]; //급여 계산
				}
			}
			costArr.push_back(cost); //계산된 급여를 급여 배열에 저장
			checker[i] = false; //마지막으로 채택한 상담을 false처리해야 다음 상담 조합을 짤 수 있음

		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> retirement_Date; //퇴사까지의 기간
	requiredTime.push_back(0); //날짜 인덱스를 1부터 시작하기 위해 0번째 상담 시간값 0 넣기
	requiredPay.push_back(0); //날짜 인덱스를 1부터 시작하기 위해 0번째 급여값 0 넣기

	for (int i = 0; i < retirement_Date; i++) //상담기간과 급여 비용 입력받음
	{
		int time = 0;
		int pay = 0;
		cin >> time >> pay;
		requiredTime.push_back(time);
		requiredPay.push_back(pay);
	}

	int max_pay = 0;
	costArr.push_back(0); //아무 상담도 하지 못할 경우를 대비해 0값을 급여 배열에 넣어주기

	for (int i = 1; i <= retirement_Date; i++) //1번째 날부터 마지막날까지 가능한 최대 급여비용 dfs로 탐색
	{
		dfs(i);
		fill(checker.begin(), checker.end(), false); //시작 날이 바뀔 때 checker함수 다시 써야하므로 false로 초기화
	}
	

	sort(costArr.begin(), costArr.end(),comp); //받을 수 있는 급여 최대값 찾기 위해 급여 배열을 내림차순정렬
	max_pay = costArr[0]; //정렬된 배열의 첫번째 인덱스에 최대 급여값 저장되어있음
	cout << max_pay;

	return 0;
	



}
