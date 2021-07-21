#ifndef __STORAGE_HPP__
#define __STORAGE_HPP__
#include <memory>

class Storage {
public:
    static void Allocate(std::uint64_t bufferSize);

    static std::uint8_t* GetBuffer() noexcept;
    static std::uint8_t* GetBufferAt(std::uint64_t offset);
    static std::uint64_t GetBufferSize() noexcept;

private:
    static std::unique_ptr<std::uint8_t> s_buffer;
    static std::uint64_t s_bufferSize;
};

constexpr std::uint64_t operator"" _B(unsigned long long number) {
    return number;
}

constexpr std::uint64_t operator"" _KB(unsigned long long number) {
    return number * 1024u;
}

constexpr std::uint64_t operator"" _MB(unsigned long long number) {
    return number * 1024u * 1024u;
}

constexpr std::uint64_t operator"" _GB(unsigned long long number) {
    return number * 1024u * 1024u * 1024u;
}
#endif