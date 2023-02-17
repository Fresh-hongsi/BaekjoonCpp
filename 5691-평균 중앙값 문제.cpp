#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	while (1)
	{
		int a = 0;
		int b = 0;

		cin >> a >> b;

		if (a == 0 && b == 0)
			break;
		int c = min(a, b);
		int d = max(a, b);



		int e = 2 * c - d;
		cout << e << '\n';
	}
	


}
