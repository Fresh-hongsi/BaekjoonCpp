#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int music = 0;
	int mean = 0;

	cin >> music >> mean;

	int result = music * (mean - 1) + 1;
	cout << result;
	return 0;
}
