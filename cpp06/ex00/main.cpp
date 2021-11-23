#include <iostream>
#include "Convert.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Incorrect input" << std::endl;
		return (1);
	}
	Convert conversion(argv[1]);
	conversion.printConversions();
	return (0);
}
