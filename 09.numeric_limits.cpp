#include <iostream>
//#include <limits>	// 있어야 한계값을 알 수 있는 라이브러리를 쓸 수 있다.
using namespace std;

int main()
{
	cout << numeric_limits<int>::max() << endl;
}

// 2행
// 한계값을 알려주는 함수들을 가지고 있는 라이브러리이다.
// 근데 그냥 iostream에 포함되어있으니 굳이 안써도 된다.

// 7행
// 사용방법이다.
// <>안에 자료형을 넣고 max()로 최대 한계, min()으로 최소 한계를 구할 수 있다.