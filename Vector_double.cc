/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 02/23/2020
 * 
 * Vector_double.cc
 * Class definition of Vector_double.h
 * -----------------------------------------------------------------------------
 */

#include "Vector_double.h"

vector::vector(const vector& v){ // Copy constructor
    double *p = new double[v.sz];
    for (int i = 0; i < v.sz; i++)
	p[i] = v.elem[i];
    delete[] elem;
    
    sz = space = v.sz;
    elem = p;
    


}

vector& vector::operator=(const vector& v){ // Copy assignment
    
    if (this == &v) return *this; // Self-assignment, no work needed

    if (v.sz <= space){ // enough space, no need for new allocation
	for (int i = 0; i < v.sz; i++) // copy elements
	    elem[i] = v.elem[i];
	sz = v.sz;
	return *this;
    }

    double *p = new double[v.sz]; // Allocate new space
    for (int i = 0; i < v.sz; i++) // copy elements
	p[i] = v.elem[i];
    delete[] elem; // Deallocate old space
    sz = space = v.sz; // Set new size
    elem = p; // Set new elements

    return *this; // return a self-reference.
	
    
}

// Move constructor
vector::vector(vector&& v){
    // Copy v's elem , sz and space
    sz = space = v.sz;
    elem = v.elem;

    // Make the empty vector
    v.sz = 0;
    v.space = 0;
    v.elem = nullptr;
    
}


vector& vector::operator=(vector&& v){ // Move assignment
    delete[] elem; // deallocate old space
    elem = v.elem; // Copy v's elem, sz, and space
    sz = space = v.sz;
    
    v.elem = nullptr; // Make v the empty vector
    v.sz = 0;
    v.space = 0;

    return *this; // return a self-reference.
    

}

void vector::resize(int newsize){ //resize
    // Make the vector have newsize elements
    // initialize each new element with the default value 0.0
    reserve(newsize);
    
    for (int i = sz; i < newsize; i++) // Initialize new elements
	elem[i] = 0;
    sz = newsize;


}


void vector::push_back(double d){ //push_back
    // Increase vector size by one; initialize the new element with d
    if (space == 0)
	reserve(8);
    else if (sz == space)
	reserve(2 * space); // Get more space
    
    elem[sz++] = d;
    


}

void vector::reserve(int newalloc){ // reserve
    if (newalloc <= space) return; // Never decrease allocation
    double *p = new double[newalloc]; // allocate new space
    for (int i = 0; i < sz; i++) // Copy old elements
	p[i] = elem[i];

    delete[] elem; // deallocate old space
    elem = p;
    space = newalloc;
}
