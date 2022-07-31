#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;

	int minimum = 0;
	int temp1=0;
	int temp2=0;

	cin >> x >> y >> w >> h;

	temp1 = min(x, y);
	temp2 = min(w - x, h - y);
	minimum = min(temp1, temp2);
	cout << minimum;
}
