#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<string> arr; //농구선수 이름 입력받아 저장할 배열

	int inputNum = 0;
	cin >> inputNum;

	while (inputNum--)
	{
		string temp;
		cin >> temp;

		arr.push_back(temp); //농구선수 이름 입력받아 저장
	}
	sort(arr.begin(), arr.end()); //농구선수 이름을 사전식 정렬


	string s = "abcdefghijklmnopqrstuvwxyz"; //이름의 첫번째 알파벳을 KEY로 두고 그에 해당하는 이름을 가진 사람의 수를 COUNT하기 위한 MAP을 생성시키기 위해 string 에 알파벳들을 저장함


	map<char, int> alphabetMap; //알파벳에 대한 이름의 수를 count하기 위한 map 생성


	for (int i = 0; i < 26; i++) //알파벳에 따른 이름의 수를 0으로 세팅하는 map 초기화 과정
	{
		alphabetMap.insert(pair<char,int>(s[i], 0));
		
	}

	for (auto& i : arr) //전체 농구선수 중 해당 알파벳을 첫번째 element로 가진 사람이 있다면 해당 alpabet에 대한 map의 value인 count값을 1 증가시켜주는 과정
	{
		if (alphabetMap.find(i[0]) != alphabetMap.end()) //해당 농구 선수의 첫번째 알파벳이 map의 key에 존재한다면
		{
			alphabetMap[i[0]]++; //해당 key의 값을 1 증가시켜줌
		}
	}

	int null = 0; //해당 알바벳에 대응하는 농구선수가 5명 미만일 경우를 check해주기 위한 변수
	
	for (auto& i : alphabetMap) //map을 순회하면서 해당 알파벳에 대응하는 값이 5이상이면 해당 알파벳을 출력
	{
		
		if (i.second >= 5)
		{
			cout << i.first;
			null++;
		}
	}

	if (null == 0) //5명 이상인 알파벳이 한개도 없다면 PREDAJA출력
	{
		cout << "PREDAJA";
	}

	return 0;

	
	




	
}
