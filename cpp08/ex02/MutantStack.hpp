#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
	typedef typename std::stack<T>::container_type::iterator iter;
	MutantStack()
	{}
	MutantStack(const MutantStack<T>& other)
	{
		*this = other;
	}
	MutantStack<T>& operator=(const MutantStack<T>& other)
	{
		this->c = other.c;
		return (*this);
	}
	~MutantStack()
	{}
	iter begin( void )
	{
		return (this->c.begin());
	}
	iter end( void )
	{
		return (this->c.end());
	}
};

#endif
