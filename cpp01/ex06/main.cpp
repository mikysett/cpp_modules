#include <iostream>
#include "Karen.hpp"

int	main(int argc, char **argv)
{
	Karen missK;

	if (argc != 2)
	{
		std::cout << "Invalid number of arguements" << std::endl;
		return (1);
	}
	missK.complain(argv[1]);
	return (0);
}
