/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 03/02/2020
 * 
 * 
 * Chapter 19_11
 *
 * Design and implement a counted_ptr<T> that is a type that holds a
 * pointer to an object of type T and a pointer to a “use count” (an int )
 * shared by all counted pointers to the same object of type T . The use
 * count should hold the number of counted pointers pointing to a given
 * T . Let the counted_ptr ’s constructor allocate a T object and a use count
 * on the free store. Let counted_ptr ’s constructor take an argument to be
 * used as the initial value of the T elements. When the last counted_ptr
 * for a T is destroyed, counted_ptr ’s destructor should delete the T . Give
 * the counted_ptr operations that allow us to use it as a pointer. This is
 * an example of a “smart pointer” used to ensure that an object doesn’t
 * get destroyed until after its last user has stopped using it. Write a set
 * of test cases for counted_ptr using it as an argument in calls, container
 * elements, etc.
 * -----------------------------------------------------------------------------
 */

#include <new>
#include <stdexcept>
#include <iostream>

using namespace std;
template<typename T> class counted_ptr{
public:
    // What should I do with a constructor like this?
    explicit counted_ptr(T *pt) : ptr{pt} {
	    use_count = new int;
	    *use_count = 1;
    }

    counted_ptr(T *pt, int *u_count) : ptr{pt}, use_count{u_count}{
        *use_count = *use_count + 1;
    }
    counted_ptr(T *pt, int count, int *u_count, T &val);

    ~counted_ptr(){
		if (*use_count <= 1){
			delete use_count;
			delete[] ptr;
		}
		else
			*use_count = *use_count - 1;
    }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    const T* get_ptr() const { return ptr; }
    T* get_ptr() { return ptr; }
    
    int* get_usecount_ptr() { return use_count; }
    
    const int& get_usecount() const { return *use_count; }
    
private:
    T * ptr;
    int *use_count;
};

// This is very risky and should not be used unless you
// A) Have allocated enough memory for the pt
// B) count is the same as the allocated amount of memory
// I can't check if it is valid or not.
template<typename T> counted_ptr<T>::counted_ptr(T * pt, int count, int *u_count, T &val){
    if (count <= 0)
		throw runtime_error("Cannot have a negative count as an argument.");
    if (!pt)
		throw runtime_error("Cannot construct a counted_ptr using a nullptr and a count argument.");
    
    ptr = pt;
    use_count = u_count;
    
    for (int i = 0; i < count; i++)
		ptr[i] = val;
    
}


int main(void){
    counted_ptr<int> list(new int[3]);
    int *pint = list.get_usecount_ptr();
    counted_ptr<int> list2(& *list, pint);
    std::cout << "Some stuff here...";
    int *leek = list2.get_usecount_ptr();


}


