#ifndef __ALLOCATOR_HPP__
#define __ALLOCATOR_HPP__
#include "Storage.hpp"

template<typename T>
class AllocatorX {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;

    AllocatorX() = default;
    template<class U>
    constexpr AllocatorX(const AllocatorX<U>&) noexcept {}

    [[nodiscard]] T* allocate(std::size_t bufferSize) {
        return reinterpret_cast<T*>(Storage::GetBuffer());
    }

    void deallocate(T* ptr, std::size_t bufferSize) noexcept {}

    template<class U>
    bool operator==(const AllocatorX<U>&) { return true; }
    template<class U>
    bool operator!=(const AllocatorX<U>&) { return false; }
};
#endif