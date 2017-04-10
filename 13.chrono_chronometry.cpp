#include <iostream>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

int main()
{
	high_resolution_clock::time_point tp = high_resolution_clock::now();	// 현재 시간을 시간 지점으로 정의한다.

	// 측정하고 싶은 알고리즘

	//system_clock::time_point du = high_resolution_clock::now() - tp;	// 이건 불가능
	auto du = high_resolution_clock::now() - tp;	// 알고리즘이 실행된 시간을 측정
	cout << duration_cast<nanoseconds>(du).count() << endl;	// 시간 단위 변환하여 출력
}

// 10행
// 시간 지점을 현재 시간으로 정의한다.
// 여기서 중요한 것은 system_clock이 아닌 high_resolution_clock이라는 것이다.
// clock의 종류는 3가지가 있다.
// 1. system_clock : 기본 clock, 기본 단위는 마이크로세컨드, 시스템의 시간을 되돌리면 -값이 나올 수 있다.
// 2. steady_clock : 기본 단위는 밀리세컨드, 시스템의 시간을 되돌려도 정확히 진행된 시간을 측정할 수 있다.
// 3. high_resolution_clock : 기본 단위는 마이크로세컨드, 시스템의 시간을 되돌려도 정확히 진행된 시간을 측정할 수 있다.

// 12행
// 시간 지점을 정의하고, 측정하고 싶은 알고리즘을 정의한다.

// 14행
// system_clock에도 time_point가 있으며, high_resolution_clock에도 time_point가 존재한다.
// 하지만 system_clock로 얻은 time_point는 high_resolution_clock로 얻은 time_point를 저장 할 수 없다.

// 15행
// auto를 사용하여 긴 자료형을 편하게 정의할 수 있다.
// 하지만 auto를 쓰더라도 제대로된 자료형을 알아야 한다.
// 바로 steady_clock::time_point이다.
// steady_clock::time_point가 high_resolution_clock::time_point의 기본 자료형이며, high_resolution_clock::time_point로 받아도 된다.

// 16행
// duration_cast를 사용하여 단위를 변환할 수 있다.
// <>안에 단위를 넣어주면 된다.
// 최소 나노세컨드까지 단위를 변경할 수 있다.