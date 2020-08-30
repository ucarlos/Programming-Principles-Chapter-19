/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 02/17/2020 
 * 
 * Chapter 19_02
 * Write a template function that takes a vector<T> vt and a vector<U> vu as
 * arguments and returns the sum of all vt[i]*vu[i] s.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
using namespace std;

// Only use with T types that are numerical (Integer, Double)
template<typename T> T vector_product(vector<T> &list1, vector<T> &list2){
    
    if (list1.size() != list2.size()){
	    cerr << "Error: Vector sizes are not the same.\n";
	    return -1; // Not possible
    }

    T sum = T();
    for (int i = 0; i < list1.size(); i++){
        sum += (list1[i] * list2[i]);
    }

    return sum;
}

int main(void){
    vector<long> list1 = {1, 2, 3, 4, 5};
    vector<long> list2 = {10, 20, 30, 40, 50};

    short sum = vector_product(list1, list2);
    cout << "The sum of list1 is list2 is:\n" << sum << endl;


}

