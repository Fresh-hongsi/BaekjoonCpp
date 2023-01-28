#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int h1 = 0;
	int m1 = 0;
	int s1 = 0;
	int h2 = 0;
	int m2 = 0;
	int s2 = 0;
	int h3 = 0;
	int m3 = 0;
	int s3 = 0;
	int start = 0;
	int end = 0;
	int result = 0;
	for (int i = 0; i < 3; i++)
	{
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

		start = h1 * 3600 + m1 * 60 + s1;
		end = h2 * 3600 + m2 * 60 + s2;
		result = end - start;

		h3 = result / 3600;
		result = result - h3 * 3600;
		m3 = result / 60;
		result = result - m3 * 60;
		s3 = result;
		cout << h3 << ' ' << m3 << ' ' << s3 << endl;

	}

	return 0;
	
	
}
