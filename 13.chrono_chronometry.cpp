#include <iostream>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

int main()
{
	high_resolution_clock::time_point tp = high_resolution_clock::now();	// ���� �ð��� �ð� �������� �����Ѵ�.

	// �����ϰ� ���� �˰���

	//system_clock::time_point du = high_resolution_clock::now() - tp;	// �̰� �Ұ���
	auto du = high_resolution_clock::now() - tp;	// �˰����� ����� �ð��� ����
	cout << duration_cast<nanoseconds>(du).count() << endl;	// �ð� ���� ��ȯ�Ͽ� ���
}

// 10��
// �ð� ������ ���� �ð����� �����Ѵ�.
// ���⼭ �߿��� ���� system_clock�� �ƴ� high_resolution_clock�̶�� ���̴�.
// clock�� ������ 3������ �ִ�.
// 1. system_clock : �⺻ clock, �⺻ ������ ����ũ�μ�����, �ý����� �ð��� �ǵ����� -���� ���� �� �ִ�.
// 2. steady_clock : �⺻ ������ �и�������, �ý����� �ð��� �ǵ����� ��Ȯ�� ����� �ð��� ������ �� �ִ�.
// 3. high_resolution_clock : �⺻ ������ ����ũ�μ�����, �ý����� �ð��� �ǵ����� ��Ȯ�� ����� �ð��� ������ �� �ִ�.

// 12��
// �ð� ������ �����ϰ�, �����ϰ� ���� �˰����� �����Ѵ�.

// 14��
// system_clock���� time_point�� ������, high_resolution_clock���� time_point�� �����Ѵ�.
// ������ system_clock�� ���� time_point�� high_resolution_clock�� ���� time_point�� ���� �� �� ����.

// 15��
// auto�� ����Ͽ� �� �ڷ����� ���ϰ� ������ �� �ִ�.
// ������ auto�� ������ ����ε� �ڷ����� �˾ƾ� �Ѵ�.
// �ٷ� steady_clock::time_point�̴�.
// steady_clock::time_point�� high_resolution_clock::time_point�� �⺻ �ڷ����̸�, high_resolution_clock::time_point�� �޾Ƶ� �ȴ�.

// 16��
// duration_cast�� ����Ͽ� ������ ��ȯ�� �� �ִ�.
// <>�ȿ� ������ �־��ָ� �ȴ�.
// �ּ� ���뼼������� ������ ������ �� �ִ�.