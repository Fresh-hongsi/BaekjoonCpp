//string
//implementation
//brute-force
//sorting

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;

	vector<string> manipulated; //조작된 문자열을 저장할 배열

	vector<pair<int, int>> p; //입력받은 문자열을 3등분으로 자를 인덱스 2개를 저장할 배열

	for (int i = 1; i <= s.size() - 2; i++) //문자열을 3등분으로 자를 인덱스 pair쌍을 p 배열에 저장
	{
		for (int j = i + 1; j <= s.size() - 1; j++)
		{
			p.push_back(pair<int, int>(i, j));
		}
	}



	
	
	for (auto& i : p) //자를 pair 인덱스 쌍을 순회하면서 3등분으로 자른 temp1, temp2, temp3 문자열을 각각 뒤집은 후 3개 temp를 합치기
	{
		string temp1;
		string temp2;
		string temp3;
		for (int l = 0; l < i.first; l++) //첫번째 잘린 문자열
		{
			temp1 += s[l];
		}

		for (int m = i.first; m < i.second; m++) //두번째 잘린 문자열
		{
			temp2 += s[m];
		}

		for (int n = i.second; n < s.size(); n++) //3번째 잘린 문자열
		{
			temp3 += s[n];
		}

		reverse(temp1.begin(), temp1.end()); //temp1 역순으로 뒤집기 
		reverse(temp2.begin(), temp2.end()); //temp2 역순으로 뒤집기
		reverse(temp3.begin(), temp3.end()); //temp3 역순으로 뒤집기
		string operated = temp1 + temp2 + temp3; //temp1 temp2 temp3 문자 합치기
		manipulated.push_back(operated); //합쳐진 문자열을 manipulated에 저장


	}

	sort(manipulated.begin(), manipulated.end()); //manipulated에 저장된 조작된 문자열을 사전식으로 정렬
	cout << manipulated[0]; //정렬된 문자열 중 첫번째 요소를 get해서 출력

		
	

	return 0;

}
