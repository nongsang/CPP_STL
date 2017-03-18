#include <iostream>
using namespace std;

template <typename T1, typename T2>			// 템플릿을 2개 사용한다?
const T1& Max(const T1& a, const T2& b)
{
	return a > b ? a : b;
}

int main()
{
	int char1_HP = 300;
	double char1_MP = 400.34;

	double MaxValue1 = Max(char1_HP, char1_MP);
	cout << "HP와 MP 중 큰 값은 " << MaxValue1 << endl;

	double MaxValue2 = Max(char1_MP, char1_HP);
	cout << "HP와 MP 중 큰 값은 " << MaxValue2 << endl;
}

// 예제들은 'Thinking about C++ STL 프로그래밍'에서 가져온다.
// 추가 예제가 있다면 'Thinking about C++11 STL 프로그래밍 2판' 또는 'C++14 STL 철저 입문', 'C++11 표준 라이브러리'에서 가져온다.

// 4번 줄
// 템플릿으로 제너릭 프로그래밍을 시작한다.
// 템플릿을 2개 선언하여 사용한다.
// 전혀 다른 값을 2개 받아서 사용할 수 있게 끔 하기 위해서다.

// 5번 줄
// 만약 템플릿을 사용하지 않았다면 입력받는 자료형에 대한 내용들을 전부 정의해줘야 할 것이다.
// 템플릿을 사용하면서 하나하나 자료형에 대해서 정의해주지 않아도 된다.
// 여기서 중요한 것은 파라미터가 서로 다른 템플릿이라는 것이다.
// 서로 다른 값을 받아서 처리할 수 있게 하기 위함이다.
// 하지만 문제가 발생할 수 있는데 int, double값을 주면 return 값은 int형이 된다.
// 왜냐하면 반환형은 T1이며 파라미터는 T1, T2이기 때문에 int형이 먼저 입력이 되면 반환형이 int형으로 자동 처리되는 것.
// 이런 것은 점차 해결법을 알아보자.
// 사실 일반 함수를 정의하면 쉽다.

// 이렇게 자료형에 구애받지 않는 것을 '제너릭하다'라고 한다.
// generic programming은 자료형에 구애받지 않고 '포괄적으로' 프로그래밍하는 것이다.