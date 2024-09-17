#include <iostream>

template <typename T>
class Array
{
private:
	T* content;
	size_t len;
public:
	Array() : content(NULL), len(0) {}

	Array(unsigned int n) {
		content = new T[n];
		len = n;
	}

	Array(const Array& other) {
		this->len = other.size();
		if (len > 0) {
			content = new T[len];
			for (size_t i = 0; i < len; ++i) {
				content[i] = other.content[i];
			}
		} else {
			content = nullptr;
		}
	}

	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			this->len = other.size();
			if (len > 0)
			{
				delete[] this->content;
				this->content = new T[len];
				for (int i = 0; i < len; ++i)
					content[i] = other.content[i];
			} else {
				this->content = NULL;
			}
		}
		return (*this);
	}

	T& operator[](size_t index)
	{
		if (index >= this->size())
			throw (std::out_of_range("Out of the Array limits"));
		else
			return (this->content[index]);
	}

	const T& operator[](size_t index) const
	{
		if (index >= size())
			throw std::out_of_range("Out of the Array limits");
		return content[index];
	}

	size_t	size(void) const {
		return this->len;
	}

	~Array() {
		if (content)
			delete[] content;
	}
};

