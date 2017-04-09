#include <iostream>
#include <ratio>
#include <limits>

using namespace std;

int main()
{
	typedef ratio<1, 2> a;								// �� = 0.5�� ǥ��
	//cout << a.num << '/' << a.den << endl;		// num�� ����, den�� �и�

	typedef ratio<1, numeric_limits<long long>::max()> b;	// ���ο� type ����
	cout << b::num << '/' << b::den << endl;				// �����ϸ� �̷��� ����

	cout << ratio_add<ratio<2, 3>, ratio<3, 2>>::num << '/' << ratio_add<ratio<2, 3>, ratio<3, 2>>::den << endl;

	//cout << ratio_add<a, b>::num << endl;				// �̷��Դ� ������.
	//cout << ratio_multiply<b, ratio<1, 2>>::num << endl;	// �̷��Ե� ������.
	//cout << ratio_multiply<ratio<1, numeric_limits<long long>::max()>, ratio<1, 2>>::num << endl;	// �����÷ο�
	//cout << ratio_divide<ratio<1, 2>, ratio<0, 1>>::num << endl;	// 0���� �����°� �ȵȴ�.

	cout << ratio_equal<ratio<1, 1>, ratio<2, 2>>::value << endl;
}

// 2��
// �м��� ����ϱ� ���� ���̺귯��

// 9��
// �м��� ��Ÿ���� �ϳ��� ���� ����
// �ٵ� �����ϸ� �̷��� ���� ����

// 10��
// �м��� ��Ÿ���� ������ ����(num), �и�(den)�� ��Ÿ����.

// 12��
// typedef�� �̿��ؼ� ���ο� type�� �����Ѵ�.
// numeric_limits�� �̿��ؼ� �������� �� �ִ�.
// �м��� ������ �� �����ϸ� typedef�� ����ؼ� ����������

// 13��
// ���Ӱ� ������ �м�Ÿ�� b�� ���ڿ� �и� ����Ѵ�.

// 15��
// �м����� ���Ͽ� ������� ���ڿ� �и� ����Ѵ�.

// 17��
// ���ο� type���� ������ �������� ���ϴ� �����̴�.
// ������ ���ο� type���δ� ������ �� �� ����.
// 15��ó�� �ۿ� ����� �� ����.

// 18��
// 17��� ���������� �Ұ����ϴ�.

// 19��
// ������� ǥ���� �� �ִ� ������ �� �۱� ������ ����÷ο찡 �߻��Ѵ�.
// �����÷ο�, ����÷ο찡 �߻��ϸ� ������ Ÿ�ӿ��� ������ �վ��.

// 20��
// �м��� 0���� ������ ��쿡�� ������ Ÿ�ӿ����� ������ �մ´�.

// 21��
// �� �м��� ���� ���ϴ� ��쿡�� value�� ����Ͽ� 1�̸� ����, 0�̸� �ٸ��� ǥ���Ѵ�.