#include <iostream>
//#include <utility>
using namespace std;

int g_id{ 0 };	// ȣ���ȣ�� �˾ƺ��� ���ؼ� ����

class CTest
{
	char* m_data{ nullptr };	// �����Ҵ��
	size_t m_size{ 0 };			// �����Ҵ��� �� ũ�⸦ �����ϴ� �뵵
	int m_id;					// ���� ȣ���̵Ǵ��� �˾ƺ��� �뵵
public:
	CTest()						// ����Ʈ ������
	{
		m_id = ++g_id;
		cout << "[" << m_id << "]" << " ����Ʈ ������ - " << m_size << endl;
	};

	CTest(int n) : m_size(n)	// ��ȯ������
	{
		m_id = ++g_id;
		m_data = new char[m_size];
		cout << "[" << m_id << "]" << " ��ȯ������ - " << m_size << endl;
	}

	CTest(const CTest& other)	// ���������
	{
		m_id = ++g_id;
		m_size = other.m_size;
		m_data = new char[m_size];
		memcpy(m_data, other.m_data, m_size);	// ������ �޸𸮸� �����ؿ´�
		cout << "[" << m_id << "]" << " ��������� - " << m_size << endl;
	}

	CTest(CTest&& other)		// r-value ����
	{
		m_id = ++g_id;
		m_data = other.m_data;	// �����Ҵ�� ���¿��� ���� ���縦 �Ѵ�.
		m_size = other.m_size;	// �̰͵� ���� ����

		other.m_data = nullptr;	// ������ �ʿ������ �ʱ�ȭ
		other.m_size = 0;		// �̰͵�
		cout << "[" << m_id << "]" << " �̵������� - " << m_size << endl;
	}

	~CTest() {
		if (m_data != nullptr)	// �����Ҵ� �Ǿ��ִٸ�
			delete[] m_data;	// �޸� ����
		cout << "[" << m_id << "]" << " �Ҹ��� - " << m_size << endl;
	}

	CTest& operator=(const CTest& other)
	{
		if (m_data != nullptr)	// �̹� �����Ҵ� �Ǿ������ϱ�
			delete[] m_data;	// �޸� ������ �����Ѵ�.
		m_size = other.m_size;	// �޸� ũ�⸦ ���� �����ϰ�
		m_data = new char[m_size];	// �޸�ũ�⸸ŭ �ٽ� �����Ҵ�
		memcpy(m_data, other.m_data, m_size);	// �����Ҵ������� �޸𸮺���� memcpy�� �ؾ��Ѵ�.
		cout << "�Ҵ翬���� - " << m_size << endl;
		return *this;
	}
};

int main()
{
	CTest a;
	CTest b(1000);
	CTest c = move(b);		// �߿��ϴ�.
	a = move(c);			// �̰͵�
}

// CPP_Abstraction/29.move_semantics�� CPP_Abstraction/33.move_assignment_operator_overloading�� Ȯ���̴�.

// 9��
// �����Ҵ��� �� �ʿ��� ũ�⸦ �����ϴ� �뵵�� size_t�� �����Ͽ���.
// size_t�� usigned int������ ��ü�� ũ�⸦ ���ϴ� �뵵�̹Ƿ� ���� �������.
// ���ϰ� int������ �����ص� ������ �� ��Ȯ�ϰ� ����ϱ� ���ؼ� ���� ��.

// 35 ~ 44��
// r-value ������ ���������.
// �ӽð�ü�� ������ �Ǹ� ��ٷ� ������Ƿ� ��������� �ڿ��� �����ҹٿ� ���� ��������� �����ʹ� �̵��ϰ� ������ ���ֹ�����.

// 66��
// ����Ʈ �����ڰ� �Ҹ���.

// 67��
// 1000�� ũ�⸦ ���Բ� ��ȯ�����ڸ� ȣ���Ѵ�.

// 68��
// std::move()�Լ��� <utility>�� ���ǵǾ��ִ�.
// �Լ� �̸��� ���� �����͸� �̵��Ѵٴ� �ǹ̷� ������ �ȴ�.
// ������ move()�Լ��� �̵��� ���õ� � �ൿ�� ������ �ʴ´�.
// �ܼ��ϰ� ��ü �� ������ r-value�� ��ȯ���ֱ⸸ �� ���̴�.
//
// ���� ���Ӱ� �����Ǵ� ��ü�� ������ �ִ� b��ü�� r-value�� casting���༭ ���Կ����� ���ְ� �ִ�.
// �� ��� �����͸� ������ �ִ� b�� �����͸� c�� �̵���Ű�� b�� ���°��� ���.
// b�� �Ҹ��� ���� �ƴ����� �ƹ��� �����͸� ������ ���� �ʴ�.

// 69��
// ���⼭�� move()�� ������־���.
// ���⼭ 68��� �ٸ� ���� �̹� ������ �Ǿ��ִ� ��ü�� r-value�� casting�ϰ� �����ϰ� �ִ�.
// �̹����� �̵������ڰ� �Ҹ��� ���� �ƴ� �Ҵ翬���ڰ� �Ҹ���.

// �����ϸ�
// 1. move()�� ��ü�� ������ r-value�� ��ȯ�ϴ� �����̴�.
// 2. ���Ӱ� �����ϴ� ��ü�� move()�� ��ȯ�� ��ü�� �����ϸ� �̵������ڰ� ȣ��Ǹ�, ��ȯ�� ��ü�� �����͸� �̵����� �����´�.
// 3. ������ �ִ� ��ü�� move()�� �����ص� ���Ӱ� �����ϴ� ���� �ƴϱ� ������ �ܼ� ���Կ����ڰ� ȣ��ȴ�.
// 4. �׸��� �̰͵��� �����Ҵ��� �� �����ϴ�.