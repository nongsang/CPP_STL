#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 5> arr{ 1, 2, 3, 4, 5 };

	cout << "범위기반 for : ";
	for (int &iter : arr)
		cout << iter << " ";
	cout << endl;

	cout << "iterator for : ";
	/*for (array<int,5>::const_iterator &iter = arr.begin(); iter != arr.end(); ++iter)
		cout << *iter << " ";
	cout << endl;*/

	for (auto &iter = arr.begin(); iter != arr.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	cout << "3번 값(arr.at(3)) : " << arr.at(3) << endl;
	cout << "첫번째 값(arr.front()) : " << arr.front() << endl;
	cout << "마지막 값(arr.back()) : " << arr.back() << endl;
	cout << "array의 위치(arr.data()) : " << arr.data() << endl;
	
	int* ptr = arr.data();
	cout << "ptr[2]의 값 : " << ptr[2] << endl;

	cout << "arr.fill(4) 후 : ";
	arr.fill(4);
	for (auto &iter : arr)
		cout << iter << " ";
	cout << endl;

	cout << "arr의 크기 : " << arr.size() << endl;
}

// 2행
// array를 사용하기 위한 라이브러리이다.
// 우리가 기본적으로 쓰는 배열맞다.

// 8행
// array를 선언하는 방법
// <>안에 자료형과 크기를 정의한다.
// 그리고 초기화자 목록을 사용하여 값을 한꺼번에 저장한다.
// C++에서 보여준 유니폼 초기화랑 똑같은 뜻이다.

// 11 ~ 13행
// C++11에서 보여준 범위기반 for loop다.
// arr에 있는 요소들을 iter가 순회하면서 복사하여 iter에 저장된 값을 출력하는 방식이다.
// 복사를 하면 자원을 많이 소모하므로 &를 붙여서 참조하는 형식으로 사용하자.

// 15 ~ 17행
// STL에서 자주 사용할 for문이다.
// 범위기반 for loop처럼 사용하는데, 반복자(iterator)라는 개념을 사용한다.
// 반복자는 포인터와 같은 개념이며, 각 원소를 순회하면서 가리키는 용도로 사용한다.
// for문에서 반복자인 iter를 생성하고, arr의 begin()부터 end()가 아닐때 까지 iter를 한칸씩 옮기면서 접근한다.
// 그리고 iter에 값을 저장하고 값을 출력한다.
// 이것 역시 복사가 기본이므로 &를 사용하여 자원을 아끼도록 하자.
// 이 방법은 STL에서만 먹히는 방법이므로 표준을 따르고 싶으면 11 ~ 13행처럼 범위기반 for loop를 사용하자.

// 24행
// at()을 사용하여 원하는 위치의 원소값을 출력한다.

// 25행
// front()를 사용하여 가장 앞의 원소값을 출력한다.

// 26행
// back()을 사용하여 가장 뒤의 원소값을 출력한다.

// 27행
// data()를 사용하여 배열의 첫번째 위치를 반환한다.

// 29, 30행
// 일반 배열처럼 포인터를 사용하여 배열의 위치를 저장할 수 있다.
// 배열의 위치를 저장한 포인터를 배열처럼 위치를 찍어서 출력할 수 있다.

// 33행
// fill()을 사용하여 모든 원소를 하나의 값으로 정의할 수 있다.

// 38행
// size()를 사용하여 배열의 크기를 구할 수 있다.
