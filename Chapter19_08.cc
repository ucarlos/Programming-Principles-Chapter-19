/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 02/22/2020
 * 
 * Chapter 19_08
 *
 * Implement an allocator (§19.3.7) using the basic allocation functions mal-
 * loc() and free() (§B.11.4). Get vector as defined by the end of §19.4 to
 * work for a few simple test cases. Hint: Look up “placement new ” and
 * “explicit call of destructor” in a complete C++ reference.
 *
 * Addendum:
 *
 * An explicit call of destructor is something like this:
 * p->~X(); 
 * And should only be called in rare cases. It should never be used for an 
 * object that is destroyed in the normal way (by its object going out of scope
 * or being deleted).
 * 
 * Placement new:
 * Placement new is a variation new operator in C++. Normal new operator 
 * does two things:
 * (1) Allocates memory (2) Constructs an object in allocated memory. 
 * Syntax:
 * new (address) (type) initializer
 * As we can see, we can specify an address where we want a new object of 
 * given type to be constructed.
 * 
 * -----------------------------------------------------------------------------
 */

#include "./Vector_double.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

template<typename T> class my_allocator{
public:
    T* allocate(int n);
    void deallocate(T *p, int n);

    void construct(T*p, const T&v);
    void destroy(T *p);
private:
    T *mem;
};


template<typename T> T* my_allocator<T>::allocate(int n){
    T *pointer = static_cast<T*>(calloc(n, sizeof(T)));
    return pointer;
}

template<typename T> void my_allocator<T>::deallocate(T *p, int n){
    for (int i = 0; i < n; i++)
	free(p[i]);
}

template<typename T> void my_allocator<T>::construct(T *p, const T &v) {
    T *pointer = new (p) T(v);
}

template<typename T> void my_allocator<T>::destroy(T *p){
    p->~T();
    
}

int main(void){
    std::cout << "Hello World!" << std::endl;

}
