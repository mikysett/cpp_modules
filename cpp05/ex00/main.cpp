#include <iostream>
#include "Bureaucrat.hpp"

// Tests taken from dda-silv repo, thanks dude ;)
static void test_high_init(void) {
	std::cout << "test_high_init" << std::endl;

	try {
		Bureaucrat greg("Greg", -1);

		std::cout << greg << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void test_low_init(void) {
	std::cout << "test_low_init" << std::endl;

	try {
		Bureaucrat greg("Greg", 255);

		std::cout << greg << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void test_increment(void) {
	std::cout << "test_increment" << std::endl;

	try {
		Bureaucrat greg("Greg", 5);

		std::cout << greg << std::endl;
		while (1) {
			greg.incrementGrade();
			std::cout << greg << std::endl;
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void test_decrement(void) {
	std::cout << "test_decrement" << std::endl;

	try {
		Bureaucrat greg("Greg", 140);

		std::cout << greg << std::endl;
		while (1) {
			greg.decrementGrade();
			std::cout << greg << std::endl;
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main(void) {
	test_high_init();
	test_low_init();
	test_increment();
	test_decrement();
}
