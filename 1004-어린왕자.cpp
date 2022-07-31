//Geometry

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

//어린왕자 문제
//출발점 포함 행성계 + 도착점 포함 행성계 - (공통 행성계*2) 가 결과값
//행성계에 포함되어있는 지는 반지름과 점과점사이 거리값의 비교를 통해 알아낼 수 있음
//출발점과 입력받은 행성계의 중심 사이의 거리 < 행성계의 반지름 * 반지름 이면 출발점이 행성계에 포함됨
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T = 0;
	cin >> T;

	while (T--)
	{
		int sx; //출발점 x좌표
		int sy; //출발점 y좌표
		int dx; //도착점 x좌표
		int dy; //도착점 y좌표

		cin >> sx >> sy >> dx >> dy;

		int planet = 0; //행성계 수
		cin >> planet;

		int startInclude = 0; //출발점 포함 행성계
		int departureInclude = 0; //도착점 포함 행성계
		int commonInclude = 0; //공통으로 포함하는 행성계

		for (int i = 0; i < planet; i++)
		{
			bool startFlag = false; //해당 행성계가 출발점 포함하는지 확인해주는 변수
			bool departrueFlag = false; //해당 행성계가 도착점 포함하는지 확인해주는 변수

			int px; //입력받은 행성계 x좌표
			int py; //입력받은 행성계 y좌표
			int pr; //입력받은 행성계 반지름
			cin >> px >> py >> pr;


			if (((sx - px) * (sx - px)) + ((sy - py) * (sy - py)) < (pr) * (pr))
				//만일 해당 행성계가 출발점 포함한다면
			{
				startInclude++;
				startFlag = true;
			}

			if (((dx - px) * (dx - px)) + ((dy - py) * (dy - py)) < (pr) * (pr))
				//만일 해당 행성계가 도착점 포함한다면
			{
				departureInclude++;
				departrueFlag = true;
			}

			if (startFlag == true && departrueFlag == true) //공통으로 포함하는 행성 수 count
			{
				commonInclude++;
			}


		}

		//공식
		int result = startInclude + departureInclude - (2 * commonInclude);
		cout << result << '\n';


	}
	return 0;
}
