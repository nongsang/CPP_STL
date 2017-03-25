#include <iostream>
#include <tuple>		// tuple ���
//#include <utility>	// ��� ��� ����.
#include <string>		// string ���

using namespace std;

class Item
{
	int m_nitemID{ 0 };
public:
	int GetID() const { return m_nitemID; }
	void SetID(const int nParam) { m_nitemID = nParam; }
};

void TestFunc(tuple<int, double, char>& param )
{
	cout << "TestFunc()" << endl;
	cout << get<0>(param) << ", " << get<1>(param) << ", " << get<2>(param) << endl;
}

int main()
{
	Item item;
	item.SetID(10001);
	tuple<int, string, Item> UserItem = tuple<int, string, Item>(1, "Jacking", item);
	//auto UserItem = tuple<int, string, Item>(1, "Jacking", item);

	cout << std::get<0>(UserItem) << ", " << get<1>(UserItem) << ", " << get<2>(UserItem).GetID() << endl;

	cout << endl;

	get<0>(UserItem) = 2;
	get<1>(UserItem) = "Jecking75";
	get<2>(UserItem).SetID(10002);

	cout << get<0>(UserItem) << ", " << get<1>(UserItem) << ", " << get<2>(UserItem).GetID() << endl;

	cout << endl;

	tuple<int, double> a = pair<int, double>(1, 2.3);	// pair�� tuple�� ���� �� �ִ�?
	cout << get<0>(a) << ", " << get<1>(a) << endl;

	TestFunc(make_tuple(4, 5.6, 'a'));		// tuple�� pair�� ���������� make�Լ��� �ִ�.

	cout << "size : " << tuple_size<tuple<int, float, string>>::value << endl;	// ����� ���� ���ϱ�
	//cout << "element : " << tuple_element<0, tuple<int, float, string>>::type << endl;	// pair�� ����� �ڷ����� ���� �˷��ش�.

	cout << endl;

	int i = 0;
	double d;
	std::tie(std::ignore, d) = a;
	cout << i << ", " << d << endl;
}

// DB���� ����ϴ� tuple �´�.
// DB�� ���� ��Ÿ���� tuple�� 2�� �̻��� �ڷ����� ��� �ϳ��� ������ ���� �� �ִ�.

// 2��
// tuple�� ����ϱ� ���� ���̺귯���̴�.
// stringó�� �� include�� ����� ����� �����ϴ�.
// include ���ϸ� ������ �� ���� ��ó�� ������ ���� ���ϰ� ��뵵 ���Ѵ�.

// 3��
// tuple�� pair�� ���������� <utility>�� �����ִ�.
// ������ <iostream>�� �⺻���� �������Ƿ� utility�� ������� �ʾƵ� �ȴ�.

// 25��
// 3���� �ٸ� �ڷ������� ��Ƽ� �ϳ��� ������ ����� tuple�����̴�.
// 2���� �ٸ� �ڷ������� �ϳ��� ������ ����� pair�ʹ� �޸� tuple�� 2���̻��� �ϳ��� ���� �� �ִ�.

// 26��
// STL������ auto�� ����ؼ� ��� ������ �ڷ����� �ڵ����� �����ش�.
// �ٵ� �׳� ()�� �ʱⰪ�� �ִ°� �� ���ϴ�.

// 28��
// get�� ����Ͽ� tuple�� ������ ��ҿ� ������ �� �ִ�.
// std�� �ִ� Ŭ�����̸� <>�� �迭�� ���� ����ϸ� �ȴ�.

// 32 ~ 34��
// get���� ��ҿ� �����ϱ⵵ �ϸ� ���� ������ ���� �ִ�.

// 40��
// pair�� ���ǵ� ������ tuple�� ������ �� �ִ�.
// ������ tuple�� ����� ������ ���� ��쿡�� ���� �����ϴ�.
// ���� �ٸ� Ŭ�������� ���� ������ �� �ִٴ� ������ ������� ����̴�.

// 41��
// pair���� ���� ���� tuple�� �� ��ҿ� get���� ������ �� �ۿ� ����.
// ��, first, second�� ����� �� ���ٴ� ���̴�.

// 44��
// pairó�� tuple�� make�Լ��� �����Ѵ�.
// make�� ����ؼ� �̸����� ��ü�� ���� �� �ִ�.

// 46��
// tuple_size<>::value�� ����� ������ �˾Ƴ� �� �ִ�.
// pair���� ����� �����ϴ�.
// ���ʿ� tuple���� ���°Ŵ�.

// 47��
// tuple_element<>:type���� ����� �ڷ����� �� �� �ִ�.
// �ٵ� ��� �Ȱ��� ����� �� ����.
// ���� �ٸ��� �ִµ�?

// 53��
// tie�� ����Ͽ� ���ǵ� tuple�� ������ �ٸ� ������ ���ʷ� ������ �� �ִ�.
// ������ ignore�� ����ؼ� ���縦 ������ �ʴ� ������ �����༭ �������� ���� �� �ִ�.