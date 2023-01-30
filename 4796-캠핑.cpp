#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int l = 0;
	int p = 0;
	int v = 0;
	bool flag = true;
	int result = 0;
	int casenum = 1;

	while (1)
	{
		cin >> l >> p >> v;
		flag = true;
		result = 0;
		while (flag == true)
		{
			if (l == 0 && p == 0 && v == 0)
				return 0;

			if (v >= p)
			{
				result += l;
				v -= p;
			}

			else
			{
				if (l > v)
				{
					result += v;
				}

				else
				{
					result += l;
				}
				
				flag = false;
			}
		}

		cout << "Case " << casenum << ": " << result << endl;
		casenum++;
		

		
		

	}
}
