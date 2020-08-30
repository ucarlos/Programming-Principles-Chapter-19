/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 03/01/2020
 * 
 * Chapter 19_09
 * Re-implement vector::operator=() (§19.2.5) using an allocator (§19.3.7)
 * for memory management.
 *
 * Note:
 * This is copied from the vector_d_allocator.cc file, so to test whether
 * this works, just run Test_vector_d .
 * -----------------------------------------------------------------------------
 */

vector& vector::operator=(const vector& v){ // Copy assignment
    
    if (this == &v) return *this; // Self-assignment, no work needed

    if (v.sz <= space){ // enough space, no need for new allocation
	for (int i = 0; i < v.sz; i++){
	    // Should I destroy the current element, and construct it afterwords?
	    alloc.destroy(&elem[i]);
	    alloc.construct(&elem[i], v.elem[i]);
	    
	}

	sz = v.sz;
	return *this;
    }

    double *p = alloc.allocate(v.sz);
    for (int i = 0; i < v.sz; i++)
	alloc.construct(&v.elem[i], p[i]);
    alloc.deallocate(elem, space);
    
    sz = space = v.sz; // Set new size
    elem = p; // Set new elements

    return *this; // return a self-reference.
}
