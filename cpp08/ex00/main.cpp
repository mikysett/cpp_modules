#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> v;
	for (int i = 1; i < 5; i++)
		v.push_back(i);
    int n1 = 3;
    int n2 = 5;
 
    std::vector<int>::const_iterator result1 = easyfind(v, n1);
    std::vector<int>::const_iterator result2 = easyfind(v, n2);
 
    (result1 != v.end())
        ? std::cout << "v contains " << n1 << '\n'
        : std::cout << "v does not contain " << n1 << '\n';
 
    (result2 != v.end())
        ? std::cout << "v contains " << n2 << '\n'
        : std::cout << "v does not contain " << n2 << '\n';
	return (0);
}
