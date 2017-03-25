#include <iostream>
#include <tuple>		// tuple 사용
//#include <utility>	// 없어도 상관 없다.
#include <string>		// string 사용

using namespace std;

class Item
{
	int m_nitemID{ 0 };
public:
	int GetID() const { return m_nitemID; }
	void SetID(const int nParam) { m_nitemID = nParam; }
};

void TestFunc(tuple<int, double, char>& param )
{
	cout << "TestFunc()" << endl;
	cout << get<0>(param) << ", " << get<1>(param) << ", " << get<2>(param) << endl;
}

int main()
{
	Item item;
	item.SetID(10001);
	tuple<int, string, Item> UserItem = tuple<int, string, Item>(1, "Jacking", item);
	//auto UserItem = tuple<int, string, Item>(1, "Jacking", item);

	cout << std::get<0>(UserItem) << ", " << get<1>(UserItem) << ", " << get<2>(UserItem).GetID() << endl;

	cout << endl;

	get<0>(UserItem) = 2;
	get<1>(UserItem) = "Jecking75";
	get<2>(UserItem).SetID(10002);

	cout << get<0>(UserItem) << ", " << get<1>(UserItem) << ", " << get<2>(UserItem).GetID() << endl;

	cout << endl;

	tuple<int, double> a = pair<int, double>(1, 2.3);	// pair를 tuple에 넣을 수 있다?
	cout << get<0>(a) << ", " << get<1>(a) << endl;

	TestFunc(make_tuple(4, 5.6, 'a'));		// tuple도 pair와 마찬가지로 make함수가 있다.

	cout << "size : " << tuple_size<tuple<int, float, string>>::value << endl;	// 요소의 갯수 구하기
	//cout << "element : " << tuple_element<0, tuple<int, float, string>>::type << endl;	// pair의 요소의 자료형이 뭔지 알려준다.

	cout << endl;

	int i = 0;
	double d;
	std::tie(std::ignore, d) = a;
	cout << i << ", " << d << endl;
}

// DB에서 사용하는 tuple 맞다.
// DB의 행을 나타내는 tuple은 2개 이상의 자료형을 묶어서 하나의 변수로 만들 수 있다.

// 2행
// tuple을 사용하기 위한 라이브러리이다.
// string처럼 꼭 include를 해줘야 사용이 가능하다.
// include 안하면 선언할 수 있을 것처럼 보여도 선언도 못하고 사용도 못한다.

// 3행
// tuple도 pair와 마찬가지로 <utility>에 속해있다.
// 하지만 <iostream>에 기본으로 들어가있으므로 utility는 사용하지 않아도 된다.

// 25행
// 3개의 다른 자료형들을 모아서 하나의 변수로 만드는 tuple선언이다.
// 2개의 다른 자료형들을 하나의 변수로 만드는 pair와는 달리 tuple은 2개이상을 하나로 만들 수 있다.

// 26행
// STL에서는 auto를 사용해서 길고 귀찮은 자료형을 자동으로 정해준다.
// 근데 그냥 ()로 초기값을 주는게 더 편하다.

// 28행
// get을 사용하여 tuple의 각각의 요소에 접근할 수 있다.
// std에 있는 클래스이며 <>로 배열과 같이 사용하면 된다.

// 32 ~ 34행
// get으로 요소에 접근하기도 하며 값을 수정할 수도 있다.

// 40행
// pair로 정의된 값들을 tuple에 복사할 수 있다.
// 하지만 tuple의 요소의 갯수가 같을 경우에만 저장 가능하다.
// 서로 다른 클래스끼리 값을 저장할 수 있다는 점에서 충격적인 기능이다.

// 41행
// pair에서 값을 받은 tuple은 각 요소에 get으로 접근할 수 밖에 없다.
// 즉, first, second를 사용할 수 없다는 뜻이다.

// 44행
// pair처럼 tuple도 make함수가 존재한다.
// make를 사용해서 이름없는 객체를 만들 수 있다.

// 46행
// tuple_size<>::value로 요소의 갯수를 알아낼 수 있다.
// pair에도 사용이 가능하다.
// 애초에 tuple에서 나온거다.

// 47행
// tuple_element<>:type으로 요소의 자료형을 알 수 있다.
// 근데 어떻게 된건지 사용할 수 없다.
// 뭔가 다른게 있는듯?

// 53행
// tie를 사용하여 정의된 tuple의 값들을 다른 변수에 차례로 복사할 수 있다.
// 하지만 ignore를 사용해서 복사를 원하지 않는 변수를 정해줘서 복사하지 않을 수 있다.