#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <vector>
# include <deque>
# include <list>
# include <algorithm>
# include <exception>
# include <iostream>

template <typename T, typename TContainer>
typename TContainer::const_iterator easyfind(const TContainer& container, T toFind)
{
	return std::find(container.begin(), container.end(), toFind);
}

#endif
