//dfs
//brute force

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int>visited(21, false);
int N = 0; //사람 수
vector<int> startTeam;
vector<int> linkTeam;
int startSum = 0;
int linkSum = 0;
vector<int> difference;
vector<vector<int>> arr(20, vector<int>(20, 0));

void dfs(int cur)
{

	if (visited[cur] == false)
	{
		visited[cur] = true;
		startTeam.push_back(cur);
	}


	if (startTeam.size() == (N / 2))
	{
		return;
	}

	
	
	for (int i = cur + 1; i <= N; i++)
	{
		if (visited[i] == false)
		{
			
			dfs(i);

			if (startTeam.size() == N / 2)
			{
				for (int j = 1; j <= N; j++)
				{
					if (visited[j] == false)
					{
						linkTeam.push_back(j);
					}
				}

				for (int m = 0; m < startTeam.size() - 1; m++)
				{
					for (int n = m + 1; n < startTeam.size(); n++)
					{
						startSum += arr[startTeam[m] - 1][startTeam[n] - 1];
						startSum += arr[startTeam[n] - 1][startTeam[m] - 1];
						linkSum += arr[linkTeam[m] - 1][linkTeam[n] - 1];
						linkSum += arr[linkTeam[n] - 1][linkTeam[m] - 1];
					}
				}
				int diffTemp = abs(startSum - linkSum);
				difference.push_back(diffTemp);
			}
			
			visited[i] = false;
			startTeam.pop_back();
			linkTeam.clear();
			
			linkSum = 0;
			startSum = 0;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp = 0;
			cin >> temp;
			arr[i][j] = temp;
		}
	}

	dfs(1);
	sort(difference.begin(), difference.end());
	cout << difference[0];
	return 0;

}
