#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<string> arr; //변환된 숫자를 담을 배열
string start; //수열의 첫번째 항인 문자열
int mul = 0; //제곱수
int finalIdx = 0; //반복수열이 시작되는 문자열의 인덱스

string change(string s)//문자열을 입력받은 제곱수에 맞춰 변환할 배열
{
	int total = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int temp = s[i] - '0';
		total += pow(temp, mul);
	}

	string t = to_string(total);
	return t;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> start >> mul; //수열의 첫번째 항과 제곱수를 입력받음
	
	arr.push_back(start); //수열이 담길 배열에 넣어줌

	bool flag = false; //flag가 true가 되면 반복수열이 되는 항의 번호를 구한 것이므로 반복문 탈출할 것
	while (flag==false)
	{
		int index = arr.size(); //현재 배열에 담긴 항의 수
		string last = arr[index-1]; //마지막 항의 번호에 해당하는 문자열
		string temp = change(last); //마지막 항에 해당하는 문자열을 수열 법칙에 맞게 변환

		for (int i = 0; i < index; i++) //변환된 항을 초항부터 끝까지 일치하는 게 있는 지 확인, 일치하는게 있다면 반복수열임을 찾은 것
		{
			if (temp == arr[i])
			{
				flag = true;
				finalIdx = i; //반복 수열이 시작되는 항 번호 -> 곧 우리가 구해야 할 값
				break;
			}
		}

		if (flag == false) //만약 반복수열을 아직 못찾았다면 수열에 추가하고 다시 과정 반복
		{
			arr.push_back(temp);
		}
		
	}

	cout << finalIdx; //반복수열을 찾은 경우 결과값 출력
	return 0;



}
