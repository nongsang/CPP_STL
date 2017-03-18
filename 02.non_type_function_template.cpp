#include <iostream>
using namespace std;

template <typename T, int Val>	// T는 기존 캐릭터의 HP, 경험치, 
T AddValue(T& CurValue)
{
	return CurValue + Val;
}

const int EVENT_ADD_HP_VALUE = 50; // 이벤트에 의해 추가 될 HP 값
const int EVENT_ADD_EXP_VALUE = 30; // 이벤트에 의해 추가 될 경험치
const int EVENT_ADD_MONEY_VALUE = 10000; // 이벤트에 의해 추가 될 돈


void main()
{
	int Char_HP = 250;
	cout << Char_HP << "에서 이벤트에 의해 " << AddValue<int, EVENT_ADD_HP_VALUE>(Char_HP) << "로 변경" << endl;

	float Char_EXP = 378.89f;
	cout << Char_EXP << "에서 이벤트에 의해 " << AddValue<float, EVENT_ADD_EXP_VALUE>(Char_EXP) << "로 변경" << endl;

	int Char_MONEY = 34567890;
	cout << Char_MONEY << "에서 이벤트에 의해 " << AddValue<int, EVENT_ADD_MONEY_VALUE>(Char_MONEY) << "로 변경" << endl;
}

// 온라인 게임에서 특정한 이벤트가 있을 때 기념으로 HP, 경험치, 돈을 추가로 주는 경우가 있다.
// HP, 경험치, 돈은 서로 다른 자료형이기 때문에 템플릿 T를 사용하여 정의해주면 편하게 프로그래밍이 가능하다.
// 그리고 T 부분에만 HP, 경험치, 돈을 집어넣어주면 필요한 자료형이 자동으로 결정이 되는 것.

// 10 ~ 12번 줄
// const로 선언한 것을 잘 봐라

// 17, 20, 23번 줄
// 템플릿으로 정의한 함수를 사용하는 방법이다.
// CPP_Abstraction/62.template_parameter에서 설명한 바 있다.
// 여기서는 좀더 나아갔다.
//
// 4번 줄에서 템플릿으로 2개의 파라미터를 갖게끔 해줬다.
// 한개는 제너릭, 하나는 int형이다.
// 그러므로 '함수이름<사용할 자료형, const 자료>(함수에 입력할 인수)'로 사용해야 한다.
// 여기서 10 ~ 12번 줄에서 const를 사용하여 선언한 이유가 나온다.
// const가 아니면 템플릿으로 값을 전달할 수 없다.
// 이벤트에서 잘 사용할 수 있다니까 기억해두자.