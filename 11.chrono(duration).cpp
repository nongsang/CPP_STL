#include <iostream>
#include <chrono>
#include <ratio>

using namespace std;
//using namespace chrono;

int main()
{
	chrono::duration<int> sec(20);			//chrono::seconds sec(20);
	chrono::duration<double, ratio<60>> halfminute(0.5);	// 실수형으로 나타내고 싶으면 이렇게 새롭게 정의해줘야 한다.
	chrono::duration<long, ratio<1, 1000>> millisec(1);
	cout << sec.count() << endl;
	cout << halfminute.count() << endl;
	cout << millisec.count() << endl;
}

// 2행
// 시간을 표현하는 라이브러리이다.

// 3행
// 시간의 단위를 나타내기 위해서 ratio를 사용한다.

// 6행
// chrono는 기본적으로 std에 속해있으며, using을 사용하여 chrono를 계속 사용할 수 있다.

// 10행
// 기간(duration)을 사용하여 기간 단위의 개수를 나타낸다.
// <>안에 자료형을 정의해주며, 갯수를 정의해주면 된다.
// 잘 쓰이는 단위는 chrono::seconds, chrono::minutes 등으로 이미 정의가 되어있다.

// 11행
// <>안에 자료형과 단위를 정해주어 자신만의 단위를 정의해줄 수 있다.
// chrono::minutes, chrono::hours 등 미리 정의된 단위는 자료형의 단위가 unsigned int형이다.
// 따라서 0.5분처럼 실수형으로 표현하고 싶으면 예시에서처럼 새롭게 정의해줘야 한다.

// 12행
// long형의 자료형으로 표현하고 단위는 1/1000이다.
// 따라서 밀리세컨드를 표현하고 있다.
// 하지만 chrono::milliseconds로 이미 정의 되어 있다.

// 13 ~ 15행
// conut()를 사용하여 기간(duration)이 몇개 있는지 알려준다.
// 정의해준 자료형의 따라 정수개, 실수개로 알려준다.