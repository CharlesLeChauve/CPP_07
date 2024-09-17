// main.cpp

#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

template <typename T>
void increment(T& element) {
    element += 1;
}

void toUpperCase(char& element) {
    if (element >= 'a' && element <= 'z') {
        element = element - ('a' - 'A');
    }
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};

    std::cout << "ints : ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    iter(intArray, 5, increment<int>);

    std::cout << "incremented ints: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3};

    std::cout << "Doubles : ";
    iter(doubleArray, 3, printElement<double>);
    std::cout << std::endl << std::endl;

	iter(doubleArray, 3, increment<double>);
	std::cout << "Incremented doubles: ";
    iter(doubleArray, 3, printElement<double>);
    std::cout << std::endl << std::endl;


    std::string stringArray[] = {"Hello", "fucking", "world"};

    std::cout << "Tableau de chaînes : ";
    iter(stringArray, 3, printElement<std::string>);
    std::cout << std::endl << std::endl;

    char charArray[] = {'h', 'e', 'l', 'l', 'o'};

    std::cout << "Tableau de caractères original : ";
    iter(charArray, 5, printElement<char>);
    std::cout << std::endl;

    iter(charArray, 5, toUpperCase);

    std::cout << "Tableau de caractères en majuscules : ";
    iter(charArray, 5, printElement<char>);
    std::cout << std::endl;

    return 0;
}