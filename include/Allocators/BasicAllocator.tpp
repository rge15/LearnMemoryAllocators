#ifndef BASIC_ALLOCATOR_TPP
#define BASIC_ALLOCATOR_TPP

#include "BasicAllocator.h"
#include <typeinfo>

namespace Allocators
{
    template <typename T>
    T* BasicAllocator<T>::allocate(std::size_t n) {
        AddLogMessage( std::format("allocate() called for {} elements of type {}", n, typeid(T).name()) );
        void* ptr = ::operator new(n * sizeof(T));
        if (!ptr) {
            throw std::bad_alloc();
        }
        return static_cast<T*>(ptr);
    }

    template <typename T>
    void BasicAllocator<T>::deallocate(T* ptr, std::size_t n) noexcept {
        AddLogMessage( std::format("deallocate() called for {} elements of type {}", n, typeid(T).name()) );
        if (ptr != nullptr) {
            ::operator delete(ptr);
        }
    }

    template <typename T>
    bool BasicAllocator<T>::operator==(const BasicAllocator& other) const {
        return true;
    }

    template <typename T>
    bool BasicAllocator<T>::operator!=(const BasicAllocator& other) const {
        return false;
    }

} //namespace Allocators
#endif // BASIC_ALLOCATOR_TPP