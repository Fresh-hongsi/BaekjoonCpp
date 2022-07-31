//Data structure
//Map

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0; //메모장에 적힌 사이트 개수
	int M = 0; //확인할 사이트 개수

	cin >> N >> M;

	map<string,string> memo; //메모장에 담긴 사이트와 그에 해당하는 비밀번호

	while (N--) //메모장에 담긴 사이트와 비밀번호 입력받아 map에 key/value로 저장
	{
		string site;
		string password;
		cin >> site >> password;
		memo.insert(pair<string, string>(site, password));

	}

	while (M--) //입력받은 site에 대해 비밀번호 값 출력
	{
		string checkSite;
		
		cin >> checkSite;

		if (memo.find(checkSite) != memo.end()) //해당 사이트가 메모장에 존재한다면
		{
			cout << memo[checkSite] << '\n'; //그 사이트를 key로 하는 value값을 출력
		}
	}

	return 0;
}
