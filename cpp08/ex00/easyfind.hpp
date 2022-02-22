#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <vector>
# include <deque>
# include <list>
# include <algorithm>
# include <exception>
# include <iostream>

template <typename TContainer>
typename TContainer::const_iterator easyfind(const TContainer& container, int toFind)
{
	return std::find(container.begin(), container.end(), toFind);
}

#endif
