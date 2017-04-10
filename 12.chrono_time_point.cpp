#include <iostream>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

int main()
{
	system_clock::time_point tp;				// 시간 지점을 생성한다.
	time_t t = system_clock::to_time_t(tp);		// 시간 지점을 time_t에 저장한다.
	cout << t << endl;							// 그래도 값을 모른다.

	time(&t);					// 시간을 숫자로 변환한다.
	cout << t << endl;			// 출력하면 흐른 시간을 알 수 있다.

	string s = ctime(&t);		// 시간 지점을 ASCII로 변환하여 저장한다.
	s.resize(s.size() - 1);		// 변환으로 마지막에 자동으로 삽입되는 \n을 없애준다. 
	cout << s << endl;
}

// 10행
// 현 시각을 시간 지점으로 설정한다.

// 11행
// 1970년 1월 1일 0시 0분 0초를 기준으로 측정한 시간지점까지 얼마나 흘렀는지 계산하여 t에 저장한다.

// 12행
// 자료형이 time_t인 변수의 값을 출력해도 값을 알 수 없다.
// 단순히 시간 지점이기 때문

// 14행
// 시간 지점을 가진 time_t를 초 단위로 바꿔준다.
// 1970년 1월 1일 0시 0분 0초가 기준이므로 시간 지점 tp까지 몇초가 흘렀는지 알려준다.

// 17행
// 시간 지점을 가진 time_t를 표준 달력으로 변환해준다.
// 즉, 시간 지점을 가진 time_t를 O요일 O월 O일 O시 O분 O초 O년으로 변환해준다.
// time()은 초 단위로만 ctime()은 초 단위로도 표준 달력으로도 변환해줄 수 있다.
// ctime()을 사용하여 표준 달력으로 변환하려면 string 클래스를 사용하여 값을 저장해야 한다.

// 18행
// 표준달력으로 변환하면 마지막에 개행이 자동으로 삽입이 된다.
// size()를 이용하여 string의 크기를 구하여 -1을 하면 \n이 삭제되며, resize()를 사용하여 크기를 재정의해준다. 