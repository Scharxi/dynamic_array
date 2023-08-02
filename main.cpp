#include <iostream>
#include "dynamic_array.hpp"

using namespace collections;

int main() {
    dynamic_array<int> arr;
    std::cout << "Capacity: " << arr.GetCapacity() << std::endl;
    arr.PushBack(1);
    std::cout << "Length: " << arr.GetLength() << std::endl;
    arr.PushBack(2);
    std::cout << "Length: " << arr.GetLength() << std::endl;
    arr.PushBack(3);
    std::cout << "Length: " << arr.GetLength() << std::endl;
    std::cout << "Capacity: " << arr.GetCapacity() << std::endl;
    int lastelement = arr.PopBack();
    std::cout << "Last Element: " << lastelement << std::endl;
    auto element = arr.get(1);
    std::cout << "Element at index one:  " << *element << std::endl;

    auto element2 = arr.get(5);
    std::cout << "Element at index five:  " << element2 << std::endl;

    std::cout << "Front Element: " << arr.Pop() << std::endl;
    arr.Clear();
    std::cout << "Front Element: " << arr.Pop() << std::endl;
}
