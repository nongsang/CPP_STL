#include <iostream>
using namespace std;

const int MAX_COUNT = 100;	// 경험치나 돈을 저장할 수 있는 최대 개수

template <typename T>
class Stack		// 저장 스택 클래스
{
	T m_aData[MAX_COUNT];
	int m_nCount;
public:
	Stack() { Clear(); }			// 생성하면 Clear() 메서드 호출
	void Clear() { m_nCount = 0; }	// 호출하면 숫자값은 0으로;
	int Count() { return m_nCount; }
	bool IsEmpty()					// 스택이 비었니?
	{
		return 0 == m_nCount ? true : false;	// 이거 유용해보이는데?
	}
	bool push(T Data)					// 푸시하면
	{
		if (m_nCount >= MAX_COUNT)		// 최대값을 넘는지 확인
			return false;

		m_aData[m_nCount] = Data;		// 안넘으면 경험치값을 대입
		++m_nCount;						// 다음 스택으로 넘어간다.

		return true;
	}
	T pop()								// 스택에서 꺼내면서 값 출력
	{
		if (m_nCount < 1)				// 스택 바닥을 뚫으려 하면
			return 0;					// 당연히 안됨

		--m_nCount;						// 아니면 위치를 한단계 내리고
		return m_aData[m_nCount];		// 저장된 값 출력
	}
};

int main()
{
	Stack<double> kExpStack;

	cout << "첫번쨰 게임 종료 - 현재 경험치 145.5f" << endl;
	kExpStack.push(145.5f);

	cout << "두번째 게임 종료- 현재 경험치 183.25f" << endl;
	kExpStack.push(183.25f);

	cout << "세번째 게임 종료- 현재 경험치162.3f" << endl;
	kExpStack.push(162.3f);

	int Count = kExpStack.Count();
	for (int i = 0; i < Count; ++i)
	{
		cout << "현재 경험치->" << kExpStack.pop() << endl;
	}

	cout << endl << endl;

	Stack<int> kStackMoney;
	cout << "첫번째 게임 종료- 현재 돈 1000023" << endl;
	kStackMoney.push(1000023);

	cout << "두번째 게임 종료- 현재 돈 1000234" << endl;
	kStackMoney.push(1000234);

	cout << "세번째 게임 종료- 현재 돈 1000145" << endl;
	kStackMoney.push(1000145);

	Count = kStackMoney.Count();

	for (int i = 0; i < Count; ++i)
	{
		cout << "현재 돈->" << kStackMoney.pop() << endl;
	}
}

// 템플릿을 이용하여 값을 집어넣고 빼는 스택을 만들었다.
// 템플릿 선언을 하였으므로 double, int라는 형식만 명시해주면 어떤 값이든 집어넣을 수 있다.

// 15 ~ 18번 줄
// 삼항 연산자를 이용한 참거짓 판별기다.
// if ~ else를 사용하는 것보다 유용해보이니 기억해두자.