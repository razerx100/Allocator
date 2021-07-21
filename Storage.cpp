#include "Storage.hpp"
#include "GenericException.hpp"
#include <iostream>

std::unique_ptr<std::uint8_t> Storage::s_buffer;
std::uint64_t Storage::s_bufferSize;

void Storage::Allocate(std::uint64_t bufferSize) {
    s_buffer = std::make_unique<std::uint8_t>();
    s_bufferSize = bufferSize;
    std::cout << "Allocated " << bufferSize << " bytes.\n";
}

std::uint8_t* Storage::GetBuffer() noexcept {
    return s_buffer.get();
}

std::uint8_t* Storage::GetBufferAt(std::uint64_t offset) {
    if (offset < s_bufferSize)
        return s_buffer.get() + offset;
    else
        throw GenericException("Can't access memory out of buffer.");

    return nullptr;
}

std::uint64_t Storage::GetBufferSize() noexcept {
    return s_bufferSize;
}