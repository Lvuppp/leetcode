#include <cmath>
#include <iostream>
#include <iomanip>

long double vp, vf, a;

long double getDistance(long double x) {
	long double time_field = std::sqrt(x * x + (1 - a) * (1 - a)) / vp;
	long double time_forest = std::sqrt((1 - x) * (1 - x) + a * a) / vf;
	return time_field + time_forest;
}


int main()
{

	std::cin >> vp >> vf >> a;

	long double l = 0, r = 1;

	for (int i = 0; i < 1000; i++) {
		long double m1 = l + (r - l) / 3,
			m2 = r - (r - l) / 3;
		long double res1 = getDistance(m1), res2 = getDistance(m2);

		if (res1 == res2) {
			l = m1;
			r = m2;

			std::cout.precision(9); 
			std::cout << (l + r) / 2.0;
			return 0;
		}
		else if (res1 < res2) {
			r = m2;
		}
		else {
			l = m1;
		}
	}
	long double result = (l + r) / 2.0;
	std::cout.precision(9);

	std::cout << result;

	return 0;
}

//moondance bobfut.near