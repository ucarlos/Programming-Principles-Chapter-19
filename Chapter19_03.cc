/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 02/18/2020
 * 
 * Chapter 19_03
 *
 * Write a template class Pair that can hold a pair of values of any type.
 * Use this to implement a simple symbol table like the one we used in the
 * calculator (§7.8).
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

template<typename T> class Pair{ // T must have a default value.
public:
    explicit Pair (T val1) : pair1{val1}, pair2{val1} { }
    explicit Pair (T val1, T val2) : pair1{val1}, pair2{val2} { }
    Pair ()=default;
    string to_string() const;
    string to_string(string &seperator) const;
    T get_pair1() { return pair1; }
    T set_pair1(T &val) { pair1 = val; }
    T get_pair2() { return pair2; }
    T set_pair2(T &val) { pair2 = val; }
private:
    T pair1 {T()};
    T pair2 {T()};
};

template<typename T> string Pair<T>::to_string() const {
    ostringstream os;
    os << pair1 << " " << "," << pair2 << endl;
    return os.str();
}

template<typename T> string Pair<T>::to_string(string &seperator) const{
    ostringstream os;
    os << pair1 << seperator << pair2 << endl;
    return os.str();
}


int main(void){
    Pair<int> pair1(1, 2);
    Pair<string> pair2("Hello", "World!");
    Pair<vector<int>> pair3((vector<int>()), vector<int>());
    

}
