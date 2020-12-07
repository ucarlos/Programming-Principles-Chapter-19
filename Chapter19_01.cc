/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 02/17/2020
 * 
 * Chapter 19_01
 * Write a template function f() that adds the elements of one vector<T> to
 * the elements of another; for example, f(v1,v2) should do v1[i]+=v2[i] for
 * each element of v1 .
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>

using namespace std;

template<typename T> void add_vectors(vector<T> &vector1, vector<T> &vector2){
    // In this case, set the number of elements added to vector 1
    // to be either vector2 or vector1 (if vector1.size < vector2.size)
    unsigned int size = (vector1.size() <= vector2.size()) ? vector1.size()
		: vector2.size();

    for (unsigned int i = 0; i < size; i++)
		vector1[i] += vector2[i];
}

int main(void){
    vector<int> list1 = { 1, 2, 3, 4, 5, 6 };
    vector<int> list2 = { 1, 2, 3, 4, 5, 6 };
    
    add_vectors(list1, list2);

    cout << "Results of adding both vectors:\n";
    for (int i : list1)
		cout << i << " ";
    cout << endl;
    
}
