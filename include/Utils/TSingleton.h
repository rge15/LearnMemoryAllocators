#pragma once
#include <iostream>
#include <mutex>
#include <memory>

#define INITIALIZE_SINGLETON(T)                             \
    template class Singleton<T>;                 \
    template <>                                             \
    std::unique_ptr<T> Singleton<T>::m_instance = nullptr;  \
    template <>                                             \
    std::mutex Singleton<T>::m_mutex{};

#define SINGLETON_CONSTRUCTOR(T)    \
    private:                        \
        T();                        \
    friend class Singleton<T>;      \

template <typename T>
class Singleton {
public:
    static T& GetInstance() {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (!m_instance) {
            m_instance.reset(new T());
        }
        return *m_instance;
    }

protected:
    Singleton() = default;
    
    virtual ~Singleton() = default;

private:
    static std::unique_ptr<T> m_instance;

    static std::mutex m_mutex;

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};