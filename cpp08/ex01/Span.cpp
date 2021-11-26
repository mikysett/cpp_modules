#include "Span.hpp"

Span::Span()
	: max_size(0)
{}

Span::Span( unsigned int max_size )
	: max_size(max_size)
{}

Span::Span( const Span &oldSpan )
	: max_size(oldSpan.max_size)
{
	vec = oldSpan.vec;
}

Span& Span::operator= ( const Span &oldSpan )
{
	max_size = oldSpan.max_size;
	vec = oldSpan.vec;
	return (*this);
}

Span::~Span()
{}

void Span::addNumber( int nb )
{
	if (vec.size() == max_size)
		throw MaxSizeException();
	else
		vec.push_back(nb);
}

void Span::addNumber( std::vector<int>::iterator begin,
					std::vector<int>::iterator end )
{
	if (vec.size() + std::distance(begin, end) > max_size)
		throw MaxSizeException();
	else
		vec.insert(vec.end(), begin, end);
}

unsigned int Span::shortestSpan( void )
{
	int shortestSpan;
	int currentSpan;

	if (vec.size() <= 1)
	{
		throw ImpossibleSpanException();
		return (0);
	}
	std::sort(vec.begin(), vec.end());
	shortestSpan = diff(vec[0], vec[1]);
	for (unsigned int i = 0; i < vec.size() - 1; i++)
	{
		currentSpan = diff(vec[i], vec[i + 1]);
		if (currentSpan < shortestSpan)
			shortestSpan = currentSpan;
	}
	return (shortestSpan);
}

unsigned int Span::longestSpan( void )
{
	if (vec.size() <= 1)
		throw ImpossibleSpanException();
	else
		return diff(*std::max_element(vec.begin(), vec.end())
				, *std::min_element(vec.begin(), vec.end()));
}

unsigned int Span::diff(int min, int max)
{
	return max >= min
		? max - min
		: min - max;
}

const char* Span::MaxSizeException::what( void ) const throw()
{
	return ("Max size reached!");
}

const char* Span::ImpossibleSpanException::what( void ) const throw()
{
	return ("Impossible Span (not enought numbers)!");
}
