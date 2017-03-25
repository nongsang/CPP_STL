#include <iostream>
//#include <utility>	// ��� ��� ����.
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
	pair<int, float> a;					// pair ������
	cout << "a : " << a.first << ", " << a.second << endl;	// first, second�� �� ��ҿ� ���ٰ���

	pair<const char*, int> b("b", 1);
	cout << "b : " << b.first << ", "<< b.second << endl;
	
	pair<char, CTest> c('c', CTest(2));	// class�� ��ҷ� ���� ����
	cout << "c : " << get<0>(c) << ", " << get<1>(c).GetData() << endl;	// tuple���� ����ϴ� get���� ��ҿ� �����ϴ� ����� ����

	cout << "size : " << tuple_size<pair<const char*, int>>::value << endl;	// tuple���� ����� ���� ���ϱ�
	//cout << "element : " << tuple_element<0, pair<int, float>>::type << endl;	// pair�� ����� �ڷ����� ���� �˷��ش�.

	TestFunc(make_pair('d', "4"));	// make_pair�� ���� �����鼭 �̸��� ���� pair�� ������ �� �ִ�.

	pair<int, float> e(1, 3.3);		// ������� ���
	cout << e.first << ", " << e.second << endl;
}

// 2��
// pair�� ������ utility�� ���ǵǾ��ִ�.
// ������ iostream���� ������ ���� utility��� �������.
// pair�� �⺻������ ����ü�̹Ƿ� ��� ����� �����Ǿ��ִ�.

// 3��
// string �����̳ʸ� ����ϱ� ���ؼ� �����Ͽ���.
// �� �״�� ���ڿ��� �ٷ�� �����̳��ε�, CString�� ���� ��ɵ��̴�.
// ���߿� �ٽ� �����Ѵ�.

// 22��
// pair�� �����ϴ� ����̴�.
// �ΰ��� �ٸ� �ڷḦ �ϳ��� ��� �ϳ��� ������ ����Ѵ�.
// �ƹ����� ���� �ʰ� �����ϸ� �� ���� 0���� �ʱ�ȭ�Ѵ�.

// 23��
// ù��° ���� �ι�° ���� ����, first, second�� ���� �����ϴ�.

// 28��
// �⺻�ڷ��� �Ӹ� �ƴϰ� �ڽ��� ���� Ŭ����, �����̳ʵ� ���� �� �ִ�.
// CTest b(2);�� ���� b�� �������� �ʰ� CTest(2)�� ����Ͽ� ���� ���� �̸����� ��ü�� �ٷ� ������ �����ϴ�.

// 29��
// tuple�� �ִ� get�� ����Ͽ� �� ��ҿ� ������ �� �ִ�.

// 31��
// tuple���� ����ϴ� tuple_size::value�� ��Ұ� ��ִ��� ���� �� �ִ�.

// 32��
// tuple_element:type���� ����� �ڷ����� ���� �� �� �ִ�.
// ������ ������ �ȵǳ�.

// 34��
// make_pair�� ���� �������� �̸����� pair�� �Լ��� ������ �� �ִ�.

// 14 ~ 18��
// pair�� �Ķ���ͷ� �޴� �Լ��� �����Ͽ���.
// ���⼭ �߿��� ���� �Ķ���ͷ� �޴� pair�� ��Ұ� string�� �ִٴ� ���̴�.
// string�� ���ڿ��� �޴´ٴ� ������ const char*�� �ٸ��� ����.
// ������ ��������, �񱳿��� ���� ���� ��ɵ��� �ִٴ°� �ٸ���.
// string �����̳ʴ� Ŭ�����̹Ƿ� �����ڰ� ȣ��ȴ�.
// �׷��Ƿ� �ܼ��� ���ڿ��� �ٷ�ٸ� const char*�� ����ϴ°� �� �������̴�.

// 36��
// pair�� ��������ϴ� ����̴�.
// �׳� ���Կ����ڸ� ����ص� ������.
// ������ ���Կ����ڴ� ������ �ִ� ��ü�� ������ ���� �������.
// ()�� ����ϴ� ����� Ŭ������ �ʱ�ȭ�� ����ϴ°� ����.