#include <iostream>
//#include <utility>
using namespace std;

int g_id{ 0 };	// 호출번호를 알아보기 위해서 선언

class CTest
{
	char* m_data{ nullptr };	// 동적할당용
	size_t m_size{ 0 };			// 동적할당할 때 크기를 전달하는 용도
	int m_id;					// 누가 호출이되는지 알아보는 용도
public:
	CTest()						// 디폴트 생성자
	{
		m_id = ++g_id;
		cout << "[" << m_id << "]" << " 디폴트 생성자 - " << m_size << endl;
	};

	CTest(int n) : m_size(n)	// 변환생성자
	{
		m_id = ++g_id;
		m_data = new char[m_size];
		cout << "[" << m_id << "]" << " 변환생성자 - " << m_size << endl;
	}

	CTest(const CTest& other)	// 복사생성자
	{
		m_id = ++g_id;
		m_size = other.m_size;
		m_data = new char[m_size];
		memcpy(m_data, other.m_data, m_size);	// 원본의 메모리를 복사해온다
		cout << "[" << m_id << "]" << " 복사생성자 - " << m_size << endl;
	}

	CTest(CTest&& other)		// r-value 참조
	{
		m_id = ++g_id;
		m_data = other.m_data;	// 동적할당된 상태에서 얕은 복사를 한다.
		m_size = other.m_size;	// 이것도 얕은 복사

		other.m_data = nullptr;	// 원본은 필요없으니 초기화
		other.m_size = 0;		// 이것도
		cout << "[" << m_id << "]" << " 이동생성자 - " << m_size << endl;
	}

	~CTest() {
		if (m_data != nullptr)	// 동적할당 되어있다면
			delete[] m_data;	// 메모리 해제
		cout << "[" << m_id << "]" << " 소멸자 - " << m_size << endl;
	}

	CTest& operator=(const CTest& other)
	{
		if (m_data != nullptr)	// 이미 동적할당 되어있으니까
			delete[] m_data;	// 메모리 해제를 먼저한다.
		m_size = other.m_size;	// 메모리 크기를 먼저 복사하고
		m_data = new char[m_size];	// 메모리크기만큼 다시 동적할당
		memcpy(m_data, other.m_data, m_size);	// 동적할당했으면 메모리복사는 memcpy로 해야한다.
		cout << "할당연산자 - " << m_size << endl;
		return *this;
	}
};

int main()
{
	CTest a;
	CTest b(1000);
	CTest c = move(b);		// 중요하다.
	a = move(c);			// 이것도
}

// CPP_Abstraction/29.move_semantics과 CPP_Abstraction/33.move_assignment_operator_overloading의 확장이다.

// 9행
// 동적할당할 때 필요한 크기를 전달하는 용도로 size_t를 선언하였다.
// size_t는 usigned int형으로 객체의 크기를 정하는 용도이므로 자주 사용하자.
// 편하게 int형으로 선언해도 되지만 더 정확하게 사용하기 위해서 쓰는 것.

// 35 ~ 44행
// r-value 참조를 정의해줬다.
// 임시객체가 생성이 되면 곧바로 사라지므로 깊은복사로 자원을 낭비할바에 차라리 얕은복사로 데이터는 이동하고 원본을 없애버린다.

// 66행
// 디폴트 생성자가 불린다.

// 67행
// 1000의 크기를 갖게끔 변환생성자를 호출한다.

// 68행
// std::move()함수는 <utility>에 정의되어있다.
// 함수 이름만 들어보면 데이터를 이동한다는 의미로 생각이 된다.
// 하지만 move()함수는 이동에 관련된 어떤 행동도 취하지 않는다.
// 단순하게 객체 및 변수를 r-value로 변환해주기만 할 뿐이다.
//
// 현재 새롭게 생성되는 객체에 기존에 있던 b객체를 r-value로 casting해줘서 대입연산을 해주고 있다.
// 그 결과 데이터를 가지고 있던 b는 데이터를 c로 이동시키고 b는 없는것이 됬다.
// b가 소멸한 것은 아니지만 아무런 데이터를 가지고 있지 않다.

// 69행
// 여기서도 move()를 사용해주었다.
// 여기서 68행과 다른 것은 이미 생성이 되어있는 객체에 r-value로 casting하고 대입하고 있다.
// 이번에는 이동생성자가 불리는 것이 아닌 할당연산자가 불린다.

// 정리하면
// 1. move()는 객체나 변수를 r-value로 변환하는 역할이다.
// 2. 새롭게 생성하는 객체에 move()로 변환한 객체를 대입하면 이동생성자가 호출되며, 변환한 객체의 데이터를 이동시켜 가져온다.
// 3. 기존에 있던 객체에 move()로 대입해도 새롭게 생성하는 것이 아니기 떄문에 단순 대입연산자가 호출된다.
// 4. 그리고 이것들은 동적할당할 때 유용하다.