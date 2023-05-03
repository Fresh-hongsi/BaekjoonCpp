#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a = 0;
	int b = 0;

	cin >> a >> b;

	int ar = 0;
	int br = 0;

	ar = 7 * a;
	br = 13 * b;

	if (ar > br)
	{
		cout << "Axel";
	}

	else if (ar < br)
	{
		cout << "Petra";
	}

	else
	{
		cout << "lika";
	}

	return 0;
}
