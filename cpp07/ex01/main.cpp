#include "iter.hpp"

int	main(void)
{
	int a1[] = {1, 2, 3, 4, 5};
	float a2[] = {1.1, 2.2, 3.3, 4.4, 5.5};

	iter(a1, 5, theDoubleInt);
	std::cout << std::endl;
	iter(a2, 5, theDoubleFloat);
	std::cout << std::endl;
	std::cout << std::endl;

	iter(a1, 5, theDoubleGen<int>);
	std::cout << std::endl;
	iter(a2, 5, theDoubleGen<float>);
	return (0);
}

int theDoubleInt(int nb)
{
	std::cout << "nb * 2 = " << nb * 2 << std::endl;
	return (nb * 2);
}

float theDoubleFloat(float nb)
{
	std::cout << "nb * 2 = " << nb * 2 << std::endl;
	return (nb * 2);
}
