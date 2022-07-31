//math
//implementation

#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	cin >> n;

	while (n--)
	{
		long a = 0;
		long b = 0;
		cin >> a >> b;
		long c = (pow(a, ((b+3)%4)+1)); //지수계산의 유용성 -> 지수는 4주기로 끊어지는 것을 알 수 있음
										//3^2=9 3^6=729
		long r = (c) % 10;
		if (r == 0)
			cout << "10" << endl;
		else
			cout << r << '\n';
	}
	return 0;
}
