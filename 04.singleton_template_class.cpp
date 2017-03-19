#include <iostream>
using namespace std;

template <typename T>
class CSingleton
{
private:
	static T* _Singleton;//{ nullptr };	// �����Ҵ�� �������
public:
	CSingleton() {}
	virtual ~CSingleton() {}

	static T* GetSingleton()		// �̱������� ��ü ����
	{
		if (nullptr == _Singleton)
			_Singleton = new T;

		return _Singleton;
	}

	static void Release()
	{
		delete _Singleton;
		_Singleton = nullptr;
	}
};

template <typename T>
T* CSingleton<T>::_Singleton = nullptr;	// static ����� ��������� �ܺο��� �ʱ�ȭ�ؾ� ��

class CObject : public CSingleton<CObject>	// �̱��� Ŭ���� ���ø��� ��� �����鼭 �Ķ���Ϳ� �� Ŭ������ �ѱ��.
{
private:
	int _nValue;
public:
	CObject() : _nValue(10) {}
	void SetValue(int Value) { _nValue = Value; }
	int GetValue() { return _nValue; }
};

void main()
{
	CObject* obj1 = CObject::GetSingleton();
	cout << obj1->GetValue() << endl;

	// MyObj2�� Myobj1�� ������ ��ü�̴�.
	CObject* obj2 = CObject::GetSingleton();
	obj2->SetValue(20);

	cout << obj1->GetValue() << endl;
	cout << obj2->GetValue() << endl;
}

// CPP_Abstraction/67.class_template_inheritance�� Ȯ���̴�.
// ���ø����� ���ǵ� Ŭ������ ����� ����� �̱����̶�� �������� ������ ���̴�.

// 8�� ��
// �ڷ����� ���ֹ����ʰ� �����Ҵ��ϱ� ���ؼ� T�� ����Ͽ���.
// �Դٰ� �����Ѵٸ� ��� ����ϱ� ���� static���� �����ߴ�.
// ������ static������ �ϸ� ���ο��� �ʱ�ȭ�� �����Ƿ� �ܺο��� �ֱ�ȭ�� ����� �Ѵ�.
// 29�� �� ����

// 13 ~ 19�� ��
// �̱����� �����ϴ� �޼����̴�.
// static���� ����� ��������� �̿��Ͽ� �̱����� �������� ������ ����, �����ϸ� ��ü�� ��ġ�� �˷��ش�.
// �̰� ���߿� �ٽ� ����

// 29�� ��
// � Ÿ���� ������ �������� ���� �̱��� Ŭ������ �ִ� T*Ÿ�� ��������� _Singleton�� nullptr�� �ʱ�ȭ�Ѵ�.
// static���� ����� ��������� �̷��� Ŭ���� �ܺο����� �ʱ�ȭ�� �����ϴ�.
// CPP_Abstraction/19.static_member.cpp�� �����ϸ� �ȴ�.

// 31�� ��
// ��ü Ŭ������ ����� �̱��� Ŭ������ ����� �޴´�.
// CObject�� ����ϸ� �ڵ����� �̱��� Ŭ������ �������� ���� �ڷ������� CObject������ ����Ѵٴ� ���� �ȴ�.
// CPP_Abstraction/67.class_template_inheritance������ ����� ������ public CTest<T>�� ����߱⿡ ��ü�� ������ �� CTest<int>ó�� �ڷ����� ����ؾ� �ߴ�.
// ������ CObject�� �����ϸ� �ڵ����� CObject�� �̱������� �Ѱ��ֹǷ� �ڷ����� ����� ������ ����.

// 43�� ��
// CObject�� GetSingleton()�̶�� �޼��带 ���� ���������ϰ� �ִ�.

// 47�� ��
// CObject�� GetSingleton()�̶�� �޼��带 ���� �� ���������ϰ� �ִ�.
// �̷��� �⺻������ CObject�� ��ü�� 2���� �����Ѵ�.
// ������ ���⼭�� ��ü�� ���Ӱ� �������� �ʴ´�.
// ������ 13 ~ 19�� �ٿ��� �������ְ� �ִ�.
// ó�� ��ü�� ������ �� �̱����� ���ؼ� 1���� ��ü�� �����ϵ��� ���س��� �����̴�.
// ���� ���� ��Ȳ�� CObject��ü�� obj1�� obj2�� ������ CObject�� ����Ű�� �ִ� ��Ȳ�̴�.

// 48 ~ 51�� ��
// obj1�� obj2�� ������ �ϳ��� CObject�� ���� �����ϰ� ������ �����ִ� �����̴�.
// �ϳ��� �����͸� ���� ��ü�� ���� �ٲ��.
// �� �����͸� �̿��Ͽ� ��ü�� ���� ����ϸ� �ΰ��� ���� ���� ����.

// ������� ���� �̱����� C++11�� shared_ptr�� ���� ����� �ϰ��ִ�.