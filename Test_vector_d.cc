/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 03/01/2020
 * 
 * Test_vector_d
 * This is just a driver for vector_d_allocator.cc.
 * -----------------------------------------------------------------------------
 */

#include "./vector_d_allocator.h"
#include <iostream>

int main(void){
    vector d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    d.push_back(6);

    cout << "Printing values of d (Before): \n";
    for (int i = 0; i < d.size(); i++)
		cout << d[i] << " ";
    cout << endl;
    vector e;
    e.push_back(10);
    e.push_back(20);
    e.push_back(30);
    e.push_back(40);
    e.push_back(50);

    cout << "Printing values of e: \n";
    for (int i = 0; i < e.size(); i++)
		cout << e[i] << " ";
    cout << endl;
    
    d = e;
    cout << "Printing values of d (After): \n";
    for (int i = 0; i < d.size(); i++)
		cout << d[i] << " ";
    cout << endl;
    


}
