#include <iostream>
#include <chrono>
#include <ratio>

using namespace std;
//using namespace chrono;

int main()
{
	chrono::duration<int> sec(20);			//chrono::seconds sec(20);
	chrono::duration<double, ratio<60>> halfminute(0.5);	// �Ǽ������� ��Ÿ���� ������ �̷��� ���Ӱ� ��������� �Ѵ�.
	chrono::duration<long, ratio<1, 1000>> millisec(1);
	cout << sec.count() << endl;
	cout << halfminute.count() << endl;
	cout << millisec.count() << endl;
}

// 2��
// �ð��� ǥ���ϴ� ���̺귯���̴�.

// 3��
// �ð��� ������ ��Ÿ���� ���ؼ� ratio�� ����Ѵ�.

// 6��
// chrono�� �⺻������ std�� ����������, using�� ����Ͽ� chrono�� ��� ����� �� �ִ�.

// 10��
// �Ⱓ(duration)�� ����Ͽ� �Ⱓ ������ ������ ��Ÿ����.
// <>�ȿ� �ڷ����� �������ָ�, ������ �������ָ� �ȴ�.
// �� ���̴� ������ chrono::seconds, chrono::minutes ������ �̹� ���ǰ� �Ǿ��ִ�.

// 11��
// <>�ȿ� �ڷ����� ������ �����־� �ڽŸ��� ������ �������� �� �ִ�.
// chrono::minutes, chrono::hours �� �̸� ���ǵ� ������ �ڷ����� ������ unsigned int���̴�.
// ���� 0.5��ó�� �Ǽ������� ǥ���ϰ� ������ ���ÿ���ó�� ���Ӱ� ��������� �Ѵ�.

// 12��
// long���� �ڷ������� ǥ���ϰ� ������ 1/1000�̴�.
// ���� �и������带 ǥ���ϰ� �ִ�.
// ������ chrono::milliseconds�� �̹� ���� �Ǿ� �ִ�.

// 13 ~ 15��
// conut()�� ����Ͽ� �Ⱓ(duration)�� � �ִ��� �˷��ش�.
// �������� �ڷ����� ���� ������, �Ǽ����� �˷��ش�.