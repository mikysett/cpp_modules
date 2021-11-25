#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template<typename T, typename U> void iter(T a[], size_t size, U fn);

// Test functions
int theDoubleInt(int nb);
float theDoubleFloat(float nb);
template<typename T> T theDoubleGen(T nb);

#endif
