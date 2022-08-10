//brute-force

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

int goal = 0; //이동하려고 하는 채널
int brokenNum = 0; //고장난 버튼 개수
vector<bool> broken(11, false); //고장난 버튼 개수를 담은 배열


int check(int channel)
{
	string ch = to_string(channel); 
	int length = ch.length();

	int curChannelLength = 0;
	for (int i = 0; i < length; i++)
	{
		if (broken[ch[i] - 48] == true)
		{
			return 0;
		}

		else
		{
			curChannelLength++;
		}
	}

	return curChannelLength;
}
int main(void)
{
	cin >> goal >> brokenNum; //이동하려는 채널과 고장난 버튼 개수 입력받음
	
	//고장난 버튼을 배열에 초기화
	for (int i = 0; i < brokenNum; i++) 
	{
		int temp = 0;
		cin >> temp;
		broken[temp] = true;
	}


	int cur = 100; //현재 내가 보고 있는 채널번호
	int ans = 0; //답을 저장할 변수

	//+ 또는 -로만 채널을 움직였을 때 눌러야하는 버튼의 횟수를 계산
	if (goal >= cur) //100번 이상의 채널로 옮기려고 할 경우 +버튼 누르는 횟수
	{
		ans = goal - cur;
	}
	else //100번 미만의 채널로 옮기려고 할 경우 -버튼 누르는 횟수
	{
		ans = cur - goal;
	}


	//모든 채널에 대해 눌러야하는 (숫자, +, -버튼)의 횟수를 계산 후 앞에서 구한 (+,-)만 사용해서 목표지점까지 가는 횟수와의 비교를 통해 최소값 구함
	for (int i = 0; i <= 1000000; i++)
	{
		int len = check(i); //i채널에 가기 위해 눌러야하는 숫자의 개수, 만약 len이 0이라면 불가능한 버튼이 있어 못가는 경우이므로 continue처리
		if (len == 0)
		{
			continue;
		}

		int usingNumButtonAns = len + abs(goal - i); //i채널로 가기 위해 누르는 버튼 수+옮겨진 i채널에서 목표 채널까지 -또는 +누르는 횟수를 더한 값

		if (usingNumButtonAns < ans) //전에 구한 최소값보다 작은 값이 생긴다면 변경
		{
			ans = usingNumButtonAns;
		}
	}

	cout << ans;
	return 0;
}
