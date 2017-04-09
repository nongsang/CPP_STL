#include <iostream>
#include <ratio>
#include <limits>

using namespace std;

int main()
{
	typedef ratio<1, 2> a;								// ½ = 0.5를 표현
	//cout << a.num << '/' << a.den << endl;		// num은 분자, den은 분모

	typedef ratio<1, numeric_limits<long long>::max()> b;	// 새로운 type 정의
	cout << b::num << '/' << b::den << endl;				// 웬만하면 이렇게 쓰자

	cout << ratio_add<ratio<2, 3>, ratio<3, 2>>::num << '/' << ratio_add<ratio<2, 3>, ratio<3, 2>>::den << endl;

	//cout << ratio_add<a, b>::num << endl;				// 이렇게는 못쓴다.
	//cout << ratio_multiply<b, ratio<1, 2>>::num << endl;	// 이렇게도 못쓴다.
	//cout << ratio_multiply<ratio<1, numeric_limits<long long>::max()>, ratio<1, 2>>::num << endl;	// 오버플로우
	//cout << ratio_divide<ratio<1, 2>, ratio<0, 1>>::num << endl;	// 0으로 나누는건 안된다.

	cout << ratio_equal<ratio<1, 1>, ratio<2, 2>>::value << endl;
}

// 2행
// 분수를 사용하기 위한 라이브러리

// 9행
// 분수를 나타내는 하나의 변수 생성
// 근데 웬만하면 이렇게 쓰지 말자

// 10행
// 분수를 나타내는 변수의 분자(num), 분모(den)을 나타낸다.

// 12행
// typedef를 이용해서 새로운 type을 선언한다.
// numeric_limits를 이용해서 정의해줄 수 있다.
// 분수를 정의할 때 웬만하면 typedef를 사용해서 정의해주자

// 13행
// 새롭게 정의한 분수타입 b의 분자와 분모를 출력한다.

// 15행
// 분수끼리 더하여 결과값의 분자와 분모를 출력한다.

// 17행
// 새로운 type으로 선언한 변수끼리 더하는 연산이다.
// 하지만 새로운 type으로는 연산을 할 수 없다.
// 15행처럼 밖에 사용할 수 없다.

// 18행
// 17행과 마찬가지로 불가능하다.

// 19행
// 결과값이 표현할 수 있는 값보다 더 작기 때문에 언더플로우가 발생한다.
// 오버플로우, 언더플로우가 발생하면 컴파일 타임에서 오류를 뿜어낸다.

// 20행
// 분수를 0으로 나누는 경우에도 컴파일 타임에에서 오류를 뿜는다.

// 21행
// 두 분수의 값을 비교하는 경우에는 value를 사용하여 1이면 같고, 0이면 다름을 표현한다.