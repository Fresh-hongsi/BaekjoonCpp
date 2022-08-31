//Graph
//DFS

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define RED 2
#define BLUE 3

vector<int> vect[20001]; //인접리스트
int visited[20001];      //방문기록
int V, E;

/* DFS 실행 */
void DFS(int start)
{
    //방문안한 점이면 RED
    if (visited[start] == 0)
        visited[start] = RED;

    //연결된 점들 방문
    for (int i = 0; i < vect[start].size(); i++)
    {
        int idx = vect[start][i];
        if (visited[idx] == 0) //방문 안한 점이면
        {
            //요소에 방문기록 남김(색칠하기)
            if (visited[start] == RED)
                visited[idx] = BLUE;
            else if (visited[start] == BLUE)
                visited[idx] = RED;

            //요소별로 방문
            DFS(idx);
        }
    }
}

/* 이분그래프 검사 */
int check()
{
    //인접한 노드와 색이 같으면 이분그래프 X
    for (int i = 1; i <= V; i++)
    {
        //연결된게 자기자신 뿐일 경우엔 size가 0이라서 돌아가지 않는다.
        for (int j = 0; j < vect[i].size(); j++)
        {
            int idx = vect[i][j];
            if (visited[i] == visited[idx])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int T;    //테스트케이스
    int u, v; //노드 담을 변수

    cin >> T;
    while (T--)
    {
        cin >> V >> E;
        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            vect[u].push_back(v);
            vect[v].push_back(u);
        }


        //빠짐없이 방문하기 위해 1부터 원소 개수까지 다 방문해봄
        for (int i = 1; i <= V; i++)
        {
            if (visited[i] == 0)
                DFS(i);
        }

        if (check() == 0) //이분그래프인지 검사
            cout << "NO\n";
        else
            cout << "YES\n";

        memset(visited, 0, sizeof(visited));
        memset(vect, 0, sizeof(vect));
    }
}
