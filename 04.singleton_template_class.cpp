#include <iostream>
using namespace std;

template <typename T>
class CSingleton
{
private:
	static T* _Singleton;//{ nullptr };	// 동적할당용 멤버변수
public:
	CSingleton() {}
	virtual ~CSingleton() {}

	static T* GetSingleton()		// 싱글톤으로 객체 생성
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
T* CSingleton<T>::_Singleton = nullptr;	// static 선언된 멤버변수는 외부에서 초기화해야 댐

class CObject : public CSingleton<CObject>	// 싱글톤 클래스 템플릿을 상속 받으면서 파라미터에 본 클래스를 넘긴다.
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

	// MyObj2는 Myobj1과 동일한 객체이다.
	CObject* obj2 = CObject::GetSingleton();
	obj2->SetValue(20);

	cout << obj1->GetValue() << endl;
	cout << obj2->GetValue() << endl;
}

// CPP_Abstraction/67.class_template_inheritance의 확장이다.
// 템플릿으로 정의된 클래스를 사용한 상속을 싱글턴이라는 개념으로 구현한 것이다.

// 8번 줄
// 자료형에 구애받지않고 동적할당하기 위해서 T를 사용하였다.
// 게다가 생성한다면 계속 사용하기 위해 static으로 선언했다.
// 하지만 static선언을 하면 내부에서 초기화를 없으므로 외부에서 최기화를 해줘야 한다.
// 29번 줄 참조

// 13 ~ 19번 줄
// 싱글턴을 생성하는 메서드이다.
// static으로 선언된 멤버변수를 이용하여 싱글턴이 존재하지 않으면 생성, 존재하면 객체의 위치를 알려준다.
// 이건 나중에 다시 설명

// 29번 줄
// 어떤 타입을 받을지 정해지지 않은 싱글톤 클래스에 있는 T*타입 멤버변수인 _Singleton을 nullptr로 초기화한다.
// static으로 선언된 멤버변수는 이렇게 클래스 외부에서만 초기화가 가능하다.
// CPP_Abstraction/19.static_member.cpp을 참조하면 된다.

// 31번 줄
// 객체 클래스를 만들고 싱글톤 클래스의 상속을 받는다.
// CObject를 사용하면 자동으로 싱글톤 클래스에 정해지지 않은 자료형들은 CObject형으로 사용한다는 뜻이 된다.
// CPP_Abstraction/67.class_template_inheritance에서는 상속을 받을때 public CTest<T>로 사용했기에 객체를 생성할 떄 CTest<int>처럼 자료형을 명시해야 했다.
// 지금은 CObject를 생성하면 자동으로 CObject를 싱글톤으로 넘겨주므로 자료형을 명시할 이유가 없다.

// 43번 줄
// CObject를 GetSingleton()이라는 메서드를 통해 동적생성하고 있다.

// 47번 줄
// CObject를 GetSingleton()이라는 메서드를 통해 또 동적생성하고 있다.
// 이러면 기본적으로 CObject형 객체가 2개가 존재한다.
// 하지만 여기서는 객체는 새롭게 생성되지 않는다.
// 이유는 13 ~ 19번 줄에서 설명해주고 있다.
// 처음 객체를 생성할 때 싱글톤을 통해서 1개의 객체만 생성하도록 정해놨기 때문이다.
// 따라서 현재 상황은 CObject객체를 obj1과 obj2가 생성된 CObject를 가리키고 있는 상황이다.

// 48 ~ 51번 줄
// obj1과 obj2가 생성된 하나의 CObject를 서로 공유하고 있음을 보여주는 문장이다.
// 하나의 포인터를 통해 객체의 값을 바꿨다.
// 두 포인터를 이용하여 객체의 값을 출력하면 두개의 값이 서로 같다.

// 여기까지 보면 싱글톤은 C++11의 shared_ptr과 같은 기능을 하고있다.