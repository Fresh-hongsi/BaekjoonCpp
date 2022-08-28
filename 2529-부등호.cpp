#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int n; //부등호의 개수
char a[20]; //부등호를 담을 배열
vector<string> ans; //부등호 조건에 맞는 수들을 저장할 배열
bool check[10]; //해당 숫자가 사용되었는 지 아닌 지 체크해줄 배열

bool ok(string num) //num으로 넘어온 문자열이 모두 부등호 조건에 부합하는 지 확인
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '<')
        {
            if (num[i] - 48 > num[i + 1] - 48)
            {
                return false;
            }
        }

        else if (a[i] == '>')
        {
            if (num[i] - 48 < num[i + 1] - 48)
            {
                return false;
            }
        }

        
    }

    
    return true;

}


void go(int index, string num)
{
    if (index == n + 1) //탈출조건 -> 부등호 개수보다 1개 더 많이 숫자가 담겨있다면
    {
        if (ok(num)) //부등호 검사가 모두 통과되었다면 정답 가능성이 있으므로 정답 배열에 push back
        {
            ans.push_back(num);
        }

        return;
    }

    for (int i = 0; i<=9; i++)
    {
        if (check[i] == true) //해달 숫자가 이미 선택되었다면 다른 숫자를 그 다음에 넣어야함
        {
            continue;
        }
        if (check[i] == false) //해당 숫자가 방문되지 않았다면 그 숫자를 문자열에 포함시키고 다음 함수 호출
        {
            check[i] = true;
            go(index + 1, num + to_string(i));
            check[i] = false;
        }
    }
}


int main(void)
{
    cin >> n; //부등호의 개수 입력받음
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    go(0, ""); //제일 앞 수가 0인 것부터 시작해보기


    auto p = minmax_element(ans.begin(), ans.end()); //조건에 부합하는 가장 작은 수 집합과 가장 큰 수 집합을 찾기
   
    
    cout << *p.second << '\n'; //가장 큰 수 출력
    cout << *p.first << '\n'; //가장 작은 수 출력
    return 0;
}
