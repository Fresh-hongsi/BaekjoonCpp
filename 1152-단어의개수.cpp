#include <iostream>
#include <string>
using namespace std;
int main() 
{
    string str;
    getline(cin, str); //str은 공백을 포함한 문자열이 저장됨

    int count = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            count++;


    }

    if (str[0] == ' ') //맨앞이 공백이면 count개수 하나 빼줌
        count--;

    if (str[str.length() - 1] != ' ') //맨 뒤가 문자일때는 count개수 하나 증가
    {
        count++;
    }
    cout << count;
    return 0;
}
