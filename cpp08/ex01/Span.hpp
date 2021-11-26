#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <algorithm>
# include <exception>

class Span
{
private:
	std::vector<int> vec;
	unsigned int max_size;
	unsigned int diff(int a, int b);
public:
	Span();
	Span( unsigned int max_size );
	Span( const Span &oldSpan );
	Span& operator= ( const Span &oldSpan );
	~Span();

	void addNumber( int nb );
	void addNumber( std::vector<int>::iterator begin, std::vector<int>::iterator end );
	unsigned int shortestSpan( void );
	unsigned int longestSpan( void );

	class MaxSizeException : public std::exception
	{
		const char* what( void ) const throw();
	};
	class ImpossibleSpanException : public std::exception
	{
		const char* what( void ) const throw();
	};
};

#endif
