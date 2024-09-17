#include <cstddef>

template <typename T>
void	iter(T* array, size_t arrLen, void(*f)(T&))
{
	for (size_t i = 0; i < arrLen; ++i)
		f(array[i]);
}

template <typename T>
void	iter(T* array, size_t arrLen, void(*f)(const T&))
{
	for (size_t i = 0; i < arrLen; ++i)
		f(array[i]);
}