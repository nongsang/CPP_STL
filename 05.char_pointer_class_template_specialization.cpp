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
	char** m_ppData;	// �� �κи� ���� Ư���ϳ�
	int m_nCount;
	int m_nSize;
public:
	explicit Stack(int size)
	{
		m_nSize = size;
		m_ppData = new char *[m_nSize];		// ���� char*�� ��ü�� �迭 ���·� size��ŭ �����.
		for (int i = 0; i < m_nSize; ++i)
			m_ppData[i] = new char[MAX_ID_LENGTH];	// �� ���� char������ MAX_ID_LENGTHũ���� ��ü�� ����� �� char*�� ��ü���� ����Ű�� �Ѵ�.

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
		strncpy_s(m_ppData[m_nCount], MAX_ID_LENGTH, pID, MAX_ID_LENGTH - 1);	// �� ��ü�� MAX_ID_LENGTHũ�⸸ŭ pID�� MAX_ID_LENGTH-1ũ�⸸ŭ �����Ѵ�.
		m_ppData[m_nCount][MAX_ID_LENGTH - 1] = '\0';	// �� ��ü�� ����Ű�� ���ڿ� ��ü�� ���κп� ���ڿ� ���� �˸�
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
	cout << "������ ũ���? " << kStack1.GetStackSize() << endl;

	kStack1.Push(10);
	kStack1.Push(11);
	kStack1.Push(12);

	int Count1 = kStack1.Count();
	for (int i = 0; i < Count1; ++i)
		cout << "������ ���� ��ȭ -> " << kStack1.Pop() << endl;

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
		cout << "���� ������ �������� ID -> " << kStack2.Pop() << endl;
}

// 43�� ��
// char*�� ��, ���ڿ��� ���� stackŬ������ ���ø� Ư��ȭ �����.
// Ŭ���� ���ø� Ư��ȭ�� CPP_Abstraction / 64.class_template_specialization�� ����

// 45�� ��
// char**�� ��������� �����Ͽ���.
// char*���� �迭���·� �����ϱ� ���� ���̴�.

// 52�� ��
// 45�� �ٿ��� ������ ��ó�� char*�� ��ü�� �迭���·� �����Ͽ���.
// char*�� ����Ű�� �뵵�̹Ƿ� ���������� ũ�⸦ ������ ��ü�� ���� �ִ�.

// 54�� ��
// ���� ���������� ũ�⸦ ���� ��ü�� �����Ͽ� �̹� ������ char*�� �迭�� ��� ������ ����Ű�Բ� �Ѵ�.

// 72�� ��
// char*�� ��ü ������ MAX_ID_LENGTHũ�⸦ �ο��ϰ�, pID�� MAX_ID_LENGTH - 1��ġ���� �����Ͽ� �ִ´�.
// ������ �迭�� �̷������ ������ ���ڿ��� ���� ��Ÿ���� '\0'�� ���� �ڸ��� ����� MAX_ID_LENGTH - 1��� ���� �ʾƵ� �ȴ�.
// �׷��� ������ �˾ƺ��� ����ϱ� ������.
// Ȥ�� �𸣴� ���׵� �ذ��� ��.