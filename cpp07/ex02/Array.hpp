#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>

template <typename T>
class Array
{
private:
	T* a;
	unsigned int size;
public:
	Array()
		: a(new T[0])
		, size(0)
	{}

	Array(unsigned int size)
		: a(new T[size])
		, size(size)
	{}

	Array( const Array &oldArray )
		: a(new T[oldArray.size])
		, size(oldArray.size)
	{
		for (unsigned int i = 0; i < size; i++)
			a[i] = oldArray.a[i];
	}

	Array<T>& operator= ( const Array<T> &oldArray )
	{
		delete[] a;
		a = new T[oldArray.size];
		size = oldArray.size;
		for (unsigned int i = 0; i < size; i++)
			a[i] = oldArray.a[i];
		
		// Could be replaced by:
		// delete[] a;
		// a = Array(oldArray);
	}

	T& operator[] ( unsigned int pos )
	{
		if (pos >= size)
			throw std::exception();
		else
			return (a[pos]);
	}

	const T& operator[] ( unsigned int pos ) const
	{
		if (pos >= size)
			throw std::exception();
		else
			return (a[pos]);
	}

	~Array()
	{
		delete[] a;
	}
};


#endif
