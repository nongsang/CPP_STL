#include <iostream>
using namespace std;

const int MAX_COUNT = 100;	// ����ġ�� ���� ������ �� �ִ� �ִ� ����

template <typename T>
class Stack		// ���� ���� Ŭ����
{
	T m_aData[MAX_COUNT];
	int m_nCount;
public:
	Stack() { Clear(); }			// �����ϸ� Clear() �޼��� ȣ��
	void Clear() { m_nCount = 0; }	// ȣ���ϸ� ���ڰ��� 0����;
	int Count() { return m_nCount; }
	bool IsEmpty()					// ������ �����?
	{
		return 0 == m_nCount ? true : false;	// �̰� �����غ��̴µ�?
	}
	bool push(T Data)					// Ǫ���ϸ�
	{
		if (m_nCount >= MAX_COUNT)		// �ִ밪�� �Ѵ��� Ȯ��
			return false;

		m_aData[m_nCount] = Data;		// �ȳ����� ����ġ���� ����
		++m_nCount;						// ���� �������� �Ѿ��.

		return true;
	}
	T pop()								// ���ÿ��� �����鼭 �� ���
	{
		if (m_nCount < 1)				// ���� �ٴ��� ������ �ϸ�
			return 0;					// �翬�� �ȵ�

		--m_nCount;						// �ƴϸ� ��ġ�� �Ѵܰ� ������
		return m_aData[m_nCount];		// ����� �� ���
	}
};

int main()
{
	Stack<double> kExpStack;

	cout << "ù���� ���� ���� - ���� ����ġ 145.5f" << endl;
	kExpStack.push(145.5f);

	cout << "�ι�° ���� ����- ���� ����ġ 183.25f" << endl;
	kExpStack.push(183.25f);

	cout << "����° ���� ����- ���� ����ġ162.3f" << endl;
	kExpStack.push(162.3f);

	int Count = kExpStack.Count();
	for (int i = 0; i < Count; ++i)
	{
		cout << "���� ����ġ->" << kExpStack.pop() << endl;
	}

	cout << endl << endl;

	Stack<int> kStackMoney;
	cout << "ù��° ���� ����- ���� �� 1000023" << endl;
	kStackMoney.push(1000023);

	cout << "�ι�° ���� ����- ���� �� 1000234" << endl;
	kStackMoney.push(1000234);

	cout << "����° ���� ����- ���� �� 1000145" << endl;
	kStackMoney.push(1000145);

	Count = kStackMoney.Count();

	for (int i = 0; i < Count; ++i)
	{
		cout << "���� ��->" << kStackMoney.pop() << endl;
	}
}

// ���ø��� �̿��Ͽ� ���� ����ְ� ���� ������ �������.
// ���ø� ������ �Ͽ����Ƿ� double, int��� ���ĸ� ������ָ� � ���̵� ������� �� �ִ�.

// 15 ~ 18�� ��
// ���� �����ڸ� �̿��� ������ �Ǻ����.
// if ~ else�� ����ϴ� �ͺ��� �����غ��̴� ����ص���.