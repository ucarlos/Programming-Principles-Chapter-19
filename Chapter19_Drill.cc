/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 02/04/2020
 * 
 * Chapter 19 Drill
 * -----------------------------------------------------------------------------
 */
#include <iostream>
#include <new>
#include <string>
#include <vector>
using namespace std;

template<typename T> class S{
public:
    explicit S(T v) : val{v}{ }

    T get() { return val;}
    const T get() const { return val; }
    void operator=(const T &new_val);
    void read_val(T &v);
private:
    T val;
};

template<typename T>
void S<T>::operator=(const T &new_val){
    this->val = new_val;
}

template<typename T> void S<T>:: read_val(T &v){
    cin >> v;
};


int main(void){
    S<int> temp(2);
    S<double> temp1(2.5);
    S<string> temp2{"Hello"};

    
    
    S<vector<int>> temp3((vector<int>()));

    cout << "Testing output:\n";
    cout << "Temp1: " << temp.get() << "\n"
	 << "Temp2: " << temp1.get() << "\n"
	 << "Temp3: " << temp2.get() << "\n"
	 << "Temp4: " << temp3.get().size() << "\n";

    cout << "Testing read_val" << endl;

    int test0 = temp.get();
    temp.read_val(test0);
    double test1 = temp1.get();
    temp1.read_val(test1);
    string test2 = temp2.get();
    temp2.read_val(test2);
        
    return 0;
}
