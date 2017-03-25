#include <iostream>
using namespace std;

const int MAX_ID_LENGTH = 21;

template<typename T>
class Stack
{
	T* m_aData;
	int m_nCount;
	int m_nSize;
public:
	explicit Stack(int size)
	{
		m_nSize = size;
		m_aData = new T[m_nSize];

		Clear();
	}
	~Stack() { delete[] m_aData; }

	void Clear() { m_nCount = 0; }
	int Count() { return m_nCount; }
	bool IsEmpty() { return 0 == m_nCount ? true : false; }
	int GetStackSize() { return m_nSize; }
	bool Push(T data)
	{
		if (m_nCount >= m_nSize)
			return false;
		m_aData[m_nCount] = data;
		++m_nCount;
	}
	T Pop()
	{
		if (m_nCount < 1)
			return 0;
		--m_nCount;
		return m_aData[m_nCount];
	}
};

template<>
class Stack<char*>
{
	char** m_ppData;	// 이 부분만 조금 특이하네
	int m_nCount;
	int m_nSize;
public:
	explicit Stack(int size)
	{
		m_nSize = size;
		m_ppData = new char *[m_nSize];		// 힙에 char*형 객체를 배열 형태로 size만큼 만든다.
		for (int i = 0; i < m_nSize; ++i)
			m_ppData[i] = new char[MAX_ID_LENGTH];	// 또 힙에 char형으로 MAX_ID_LENGTH크기의 객체를 만들고 각 char*형 객체들이 가리키게 한다.

		Clear();
	}
	~Stack()
	{
		for (int i = 0; i < m_nSize; ++i)
			delete[] m_ppData[i];
	}

	void Clear() { m_nCount = 0; }
	int Count() { return m_nCount; }
	bool IsEmpty() { return 0 == m_nCount ? true : false; }
	int GetStackSize() { return m_nSize; }
	bool Push(char* pID)
	{
		if (m_nCount >= m_nSize)
			return false;
		strncpy_s(m_ppData[m_nCount], MAX_ID_LENGTH, pID, MAX_ID_LENGTH - 1);	// 각 객체에 MAX_ID_LENGTH크기만큼 pID의 MAX_ID_LENGTH-1크기만큼 복사한다.
		m_ppData[m_nCount][MAX_ID_LENGTH - 1] = '\0';	// 각 객체가 가리키는 문자열 객체의 끝부분에 문자열 끝을 알림
		++m_nCount;
		return true;
	}
	char* Pop()
	{
		if (m_nCount < 1)
			return 0;
		--m_nCount;
		return m_ppData[m_nCount];
	}
};

int main()
{
	Stack<int> kStack1(64);
	cout << "스택의 크기는? " << kStack1.GetStackSize() << endl;

	kStack1.Push(10);
	kStack1.Push(11);
	kStack1.Push(12);

	int Count1 = kStack1.Count();
	for (int i = 0; i < Count1; ++i)
		cout << "유저의 레벨 변화 -> " << kStack1.Pop() << endl;

	cout << endl;

	char GameID1[MAX_ID_LENGTH] = "NiceChoi";
	char GameID2[MAX_ID_LENGTH] = "SuperMan";
	char GameID3[MAX_ID_LENGTH] = "Attom";

	Stack<char*> kStack2(64);
	kStack2.Push(GameID1);
	kStack2.Push(GameID2);
	kStack2.Push(GameID3);

	int Count2 = kStack2.Count();
	for (int i = 0; i < Count2; ++i)
		cout << "같이 게임을 한유저의 ID -> " << kStack2.Pop() << endl;
}

// 43번 줄
// char*형 즉, 문자열을 받은 stack클래스를 템플릿 특수화 해줬다.
// 클래스 템플릿 특수화는 CPP_Abstraction / 64.class_template_specialization에 정리

// 45번 줄
// char**형 멤버변수를 선언하였다.
// char*형의 배열형태로 생성하기 위한 것이다.

// 52번 줄
// 45번 줄에서 설명한 것처럼 char*형 객체를 배열형태로 선언하였다.
// char*는 가리키는 용도이므로 실질적으로 크기를 가지는 객체는 따로 있다.

// 54번 줄
// 힙에 실질적으로 크기를 가진 객체를 생성하여 이미 생성된 char*형 배열의 요소 각각이 가리키게끔 한다.

// 72번 줄
// char*형 객체 각각에 MAX_ID_LENGTH크기를 부여하고, pID의 MAX_ID_LENGTH - 1위치까지 복사하여 넣는다.
// 어차피 배열로 이루어졌기 때문에 문자열의 끝을 나타내는 '\0'을 위한 자리를 남기려 MAX_ID_LENGTH - 1라고 쓰지 않아도 된다.
// 그래도 있으면 알아보기 쉬우니까 써주자.
// 혹시 모르는 버그도 해결할 겸.