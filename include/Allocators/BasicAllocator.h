#ifndef BASIC_ALLOCATOR_HPP
#define BASIC_ALLOCATOR_HPP
#include "ImGuiAllocatorHandler.h"

namespace Allocators
{
    template <typename T>
    class BasicAllocator : public ImGuiAllocatorHandler
    {
        //TODO : Keep implementing the memory allocator
        public: 
            using value_type = T;

            BasicAllocator() = default;

            template <typename U>
            BasicAllocator(const BasicAllocator<U>&) {}

            value_type* allocate( size_t typesNum );

            void deallocate(value_type* ptr , size_t typesNum ) noexcept;

            bool operator==(const BasicAllocator& other) const;
            bool operator!=(const BasicAllocator& other) const;
    };
} // namespace Allocators

#include "BasicAllocator.tpp"

#endif // MY_ALLOCATOR_HPP