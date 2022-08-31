//Brute-Force
//BitMasking

#include <iostream>
#include <cstdio>
using namespace std;

int a[4][4];

int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            scanf("%1d", &a[i][j]);
        }
    }

    int ans = 0;
    // 0: -, 1 : |
    for (int s = 0; s < (1 << (n * m)); s++) {

        int sum = 0;

        for (int i = 0; i < n; i++)  //가로칸의 경우
        {
            int cur = 0;
            for (int j = 0; j < m; j++) 
            {
                int k = i * m + j; //다음 확인할 가로칸 인덱스

                if ((s & (1 << k)) == 0) //가로칸인 것을 비트마스킹을 통해 확인된 경우
                {
                    cur = cur * 10 + a[i][j]; //전의 cur값*10+현재값
                }
                else //가로칸이 아니면 cur값을 sum에 더하고 cur값 0으로 만들기
                {
                    sum += cur;
                    cur = 0;
                }
            }

            sum += cur; //네칸짜리 가로칸이 다 채워진 경우이므로 sum에 cur값 더해주기
        }

        for (int j = 0; j < m; j++) //세로칸의 경우
        {
            int cur = 0;
            for (int i = 0; i < n; i++) //다음 확인할 세로칸 인덱스
            {
                int k = i * m + j;
                if ((s & (1 << k)) != 0) //세로칸인 것을 비트마스킹을 통해 확인된 경우
                {
                    cur = cur * 10 + a[i][j]; //전의 cur값*10+현재값
                }
                else //세로칸이 아닌경우 cur값을 sum에 더하고 cur값 0으로 만들기
                {
                    sum += cur;
                    cur = 0;
                }
            }

            sum += cur;  //네칸짜리 세로칸이 다 채워진 경우이므로 sum에 cur값 더해주기
        }

        ans = max(ans, sum); //현재 구해진 sum값과 max값 비교해 최대값을 ans로 함
    }

    cout << ans << '\n';

    return 0;
}
