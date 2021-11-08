#include <iostream>
#include "bsq.hpp"
#include "Point.hpp"

// Those two testing functions are taken from dda_silv repo (thanks make ;))
static void testing_point_class(void) {
	Point a;
	Point const b(3.14f, 42.42f);
	Point const c(b);

	std::cout << a << std::endl;

	a = c;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}

// results should be t, f, f, f, t
static void testing_bsp(void) {
	Point const a(0.0f, 0.0f);
	Point const b(2.0f, 2.0f);
	Point const c(2.5f, 1.0f);
	Point const p1(1.5f, 1.0f);
	Point const p2(1.5f, 0.5f);
	Point const p3(1.0f, 1.0f);
	Point const p4(-0.1f, -0.1f);
	Point const p5(1.0f, 0.5f);

	std::cout << "Test Point 1: " << (bsp(a, b, c, p1) ? "true" : "false") << std::endl;
	std::cout << "Test Point 2: " << (bsp(a, b, c, p2) ? "true" : "false") << std::endl;
	std::cout << "Test Point 3: " << (bsp(a, b, c, p3) ? "true" : "false") << std::endl;
	std::cout << "Test Point 4: " << (bsp(a, b, c, p4) ? "true" : "false") << std::endl;
	std::cout << "Test Point 5: " << (bsp(a, b, c, p5) ? "true" : "false") << std::endl;
}

int	main(void)
{
	Point a(10., 4.654);
	Point b(a);
	Point c;
	Point d = a;

	d = c;
	c = a;

	std::cout << "a: [" << &a << "] " << a << std::endl
		<< "b: [" << &b << "] " << b << std::endl
		<< "c: [" << &c << "] " << c << std::endl
		<< "d: [" << &d << "] " << d << std::endl;

	testing_point_class();
	testing_bsp();

	return (0);
}
