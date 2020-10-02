#include <iostream>

#ifndef NDEBUG
#   define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << message << std::endl; \
            std::terminate(); \
        } \
    } while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif

template <class T>
bool isSorted(T* array, int n){
    for (int i = 0; i < n - 1; ++i) {
        if (array[i] > array[i+1]) {
            return false;
        }
    }
    return true;
}