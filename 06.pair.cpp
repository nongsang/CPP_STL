#include <iostream>
//#include <utility>	// 없어도 상관 없다.
#include <string>
using namespace std;

class CTest
{
	int m_Data;
public:
	CTest(int nParam) :m_Data(nParam) {}
	int GetData() const { return m_Data; }
};

void TestFunc(pair<char, string> Param)
{
	cout << "TestFunc()" << endl;
	cout << "make pair : " << Param.first << ", " << Param.second << endl;
}

int main()
{
	pair<int, float> a;					// pair 선언방법
	cout << "a : " << a.first << ", " << a.second << endl;	// first, second로 각 요소에 접근가능

	pair<const char*, int> b("b", 1);
	cout << "b : " << b.first << ", "<< b.second << endl;
	
	pair<char, CTest> c('c', CTest(2));	// class도 요소로 묶기 가능
	cout << "c : " << get<0>(c) << ", " << get<1>(c).GetData() << endl;	// tuple에서 사용하는 get으로 요소에 접근하는 방법도 가능

	cout << "size : " << tuple_size<pair<const char*, int>>::value << endl;	// tuple에서 요소의 갯수 구하기
	//cout << "element : " << tuple_element<0, pair<int, float>>::type << endl;	// pair의 요소의 자료형이 뭔지 알려준다.

	TestFunc(make_pair('d', "4"));	// make_pair로 값을 가지면서 이름이 없는 pair를 생성할 수 있다.

	pair<int, float> e(1, 3.3);		// 복사생성 방법
	cout << e.first << ", " << e.second << endl;
}

// 2행
// pair의 구조는 utility에 정의되어있다.
// 하지만 iostream에도 있으니 굳이 utility없어도 상관없다.
// pair는 기본적으로 구조체이므로 모든 멤버는 공개되어있다.

// 3행
// string 컨테이너를 사용하기 위해서 선언하였다.
// 말 그대로 문자열을 다루는 컨테이너인데, CString과 같은 기능들이다.
// 나중에 다시 설명한다.

// 22행
// pair를 선언하는 방법이다.
// 두개의 다른 자료를 하나로 엮어서 하나의 변수로 사용한다.
// 아무값도 주지 않고 생성하면 두 값은 0으로 초기화한다.

// 23행
// 첫번째 값과 두번째 값에 각각, first, second로 접근 가능하다.

// 28행
// 기본자료형 뿐만 아니고 자신이 만든 클래스, 컨테이너도 묶을 수 있다.
// CTest b(2);로 만들어서 b를 전달하지 않고 CTest(2)를 사용하여 값을 가진 이름없는 객체를 바로 전달이 가능하다.

// 29행
// tuple에 있는 get을 사용하여 각 요소에 접근할 수 있다.

// 31행
// tuple에서 사용하는 tuple_size::value로 요소가 몇개있는지 구할 수 있다.

// 32행
// tuple_element:type으로 요소의 자료형이 뭔지 알 수 있다.
// 하지만 왜인지 안되네.

// 34행
// make_pair로 값을 가지지만 이름없는 pair를 함수로 전달할 수 있다.

// 14 ~ 18행
// pair를 파라미터로 받는 함수를 정의하였다.
// 여기서 중요한 것은 파라미터로 받는 pair의 요소가 string이 있다는 것이다.
// string은 문자열을 받는다는 점에서 const char*와 다를건 없다.
// 하지만 덧셈연산, 비교연산 등의 여러 기능들이 있다는게 다르다.
// string 컨테이너는 클래스이므로 생성자가 호출된다.
// 그러므로 단순한 문자열을 다룬다면 const char*를 사용하는게 더 좋을것이다.

// 36행
// pair를 복사생성하는 방법이다.
// 그냥 대입연산자를 사용해도 괜찮다.
// 하지만 대입연산자는 기존에 있던 객체를 대입할 때만 사용하자.
// ()를 사용하는 방법은 클래스의 초기화에 사용하는게 좋다.