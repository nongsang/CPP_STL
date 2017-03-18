#include <iostream>
using namespace std;

template <typename T, int Val>	// T�� ���� ĳ������ HP, ����ġ, 
T AddValue(T& CurValue)
{
	return CurValue + Val;
}

const int EVENT_ADD_HP_VALUE = 50; // �̺�Ʈ�� ���� �߰� �� HP ��
const int EVENT_ADD_EXP_VALUE = 30; // �̺�Ʈ�� ���� �߰� �� ����ġ
const int EVENT_ADD_MONEY_VALUE = 10000; // �̺�Ʈ�� ���� �߰� �� ��


void main()
{
	int Char_HP = 250;
	cout << Char_HP << "���� �̺�Ʈ�� ���� " << AddValue<int, EVENT_ADD_HP_VALUE>(Char_HP) << "�� ����" << endl;

	float Char_EXP = 378.89f;
	cout << Char_EXP << "���� �̺�Ʈ�� ���� " << AddValue<float, EVENT_ADD_EXP_VALUE>(Char_EXP) << "�� ����" << endl;

	int Char_MONEY = 34567890;
	cout << Char_MONEY << "���� �̺�Ʈ�� ���� " << AddValue<int, EVENT_ADD_MONEY_VALUE>(Char_MONEY) << "�� ����" << endl;
}

// �¶��� ���ӿ��� Ư���� �̺�Ʈ�� ���� �� ������� HP, ����ġ, ���� �߰��� �ִ� ��찡 �ִ�.
// HP, ����ġ, ���� ���� �ٸ� �ڷ����̱� ������ ���ø� T�� ����Ͽ� �������ָ� ���ϰ� ���α׷����� �����ϴ�.
// �׸��� T �κп��� HP, ����ġ, ���� ����־��ָ� �ʿ��� �ڷ����� �ڵ����� ������ �Ǵ� ��.

// 10 ~ 12�� ��
// const�� ������ ���� �� ����

// 17, 20, 23�� ��
// ���ø����� ������ �Լ��� ����ϴ� ����̴�.
// CPP_Abstraction/62.template_parameter���� ������ �� �ִ�.
// ���⼭�� ���� ���ư���.
//
// 4�� �ٿ��� ���ø����� 2���� �Ķ���͸� ���Բ� �����.
// �Ѱ��� ���ʸ�, �ϳ��� int���̴�.
// �׷��Ƿ� '�Լ��̸�<����� �ڷ���, const �ڷ�>(�Լ��� �Է��� �μ�)'�� ����ؾ� �Ѵ�.
// ���⼭ 10 ~ 12�� �ٿ��� const�� ����Ͽ� ������ ������ ���´�.
// const�� �ƴϸ� ���ø����� ���� ������ �� ����.
// �̺�Ʈ���� �� ����� �� �ִٴϱ� ����ص���.