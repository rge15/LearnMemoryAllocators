#pragma once
#ifndef ASSERTS_HPP
#define ASSERTS_HPP

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <sstream>
#include <format>  // For C++20 std::format

// Check if the DEBUG macro is defined. If it is, assertions will be enabled.
#ifdef DEBUG
    #define ASSERT_ENABLED 0
#else
    #define ASSERT_ENABLED 1
#endif

// Helper macros for producing better error messages
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

// Default handler to output the message and terminate the program
#define ASSERT_HANDLER(message) \
    do { \
        ASSERT_HANDLER_FN(message); \
    } while(0)

// Custom assert failure handler function
static __forceinline void allocators_custom_assert_handler(const std::string& message) {
    std::cerr << "Assertion failed: " << message << "\n";
    std::cin.get();
    std::abort();
}

// User can define a custom assertion handler
#ifndef ASSERT_HANDLER_FN
    #define ASSERT_HANDLER_FN allocators_custom_assert_handler
#endif

#ifdef DEBUG
    #define ASSERT_MSG(condition, msg) ;
    #define ASSERT_MSG_FORMAT(condition, msg, ...) ;
#else
    #define ASSERT_MSG(condition, msg) \
    do { \
        if (!(condition)) { \
            ASSERT_HANDLER(msg); \
        } \
    } while(0)

    #define ASSERT_MSG_FORMAT(condition, msg, ...) \
        do { \
            if (!(condition)) { \
                std::string formatted_message = std::format(msg, __VA_ARGS__); \
                ASSERT_HANDLER(formatted_message); \
            } \
        } while(0)
#endif

#define STATIC_ASSERT(condition, msg) \
    static_assert(condition, msg)

#endif // ASSERTS_HPP