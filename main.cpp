#include <iostream>
#include <exception>
#include <vector>
#include "Allocator.hpp"

int main() {
    try {
        Storage::Allocate(1_KB);
        std::vector<int, AllocatorX<int>> vec;
        vec.push_back(7);
        std::cout << vec.front();
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }

    return 0;
}