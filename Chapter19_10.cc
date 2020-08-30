/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 03/02/2020
 * 
 * Chapter 19_10
 * Implement a simple unique_ptr supporting only a constructor, destructor,
 * –> , * , and release() . In particular, don’t try to implement an assignment
 * or a copy constructor.
 * -----------------------------------------------------------------------------
 */
#include <iostream>
#include <new>
using namespace std;

template<typename T> class unique_ptr{
public:
    unique_ptr(T *val) : ptr{val} { }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    
    ~unique_ptr(){ delete ptr; }
    T* release();
private:
    T *ptr;
};

template<typename T> T* unique_ptr<T>::release(){
    T *newptr = ptr;
    ptr = nullptr;
    return newptr;
}


// Test program
int main(void){
    unique_ptr<int> list = new int[5];


}
