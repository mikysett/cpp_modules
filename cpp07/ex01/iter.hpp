#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template<typename T, typename U> void iter(T a[], size_t size, U fn)
{
	for (size_t i = 0; i < size; i++)
		fn(a[i]);
}

// Test functions
int theDoubleInt(int nb);
float theDoubleFloat(float nb);
template<typename T> T theDoubleGen(T nb)
{
	std::cout << "nb * 2 = " << nb * 2 << std::endl;
	return (nb * 2);
}

#endif
