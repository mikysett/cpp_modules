#include "main.hpp"

int	main(void)
{
	int nb_tests = 10;
	for (int i = 0; i < nb_tests; i++)
	{
		Base* test = generate();
		
		std::cout << "identify(ptr):";
		identify(test);
		std::cout << std::endl;

		std::cout << "identify(ref):";
		identify(*test);
		std::cout << std::endl << std::endl;
	}
	return (0);
}

Base* generate(void)
{
	static bool seedInitialized = false;
	if (!seedInitialized)
	{
		srand(time(0));
		seedInitialized = true;
	}

	int randomBase = rand() % 3;
	if (randomBase == 0)
		return (new A);
	else if (randomBase == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	if (p == NULL)
		return ;
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C";	
}

void identify(Base& p)
{
	if (dynamic_cast<A*>(&p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B*>(&p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C*>(&p) != NULL)
		std::cout << "C";	
}
