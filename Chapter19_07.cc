/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 08/20/2020 at 05:55 PM
 * 
 * Chapter09_07.cc
 * Try your solution to exercise 2 with some Numbers.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>

using namespace std;

template<class T> class Number{
public:    
    Number()=default; // Default constructor
    
    explicit Number(T v){ val = v; }

    // Copy constructor
    Number(const Number &i){ val = i.val; }
    
    // Copy assignment
    
    Number& operator=(const Number &i){ val = i.val; return *this; }

    Number operator+(const Number &i);
    Number operator-(const Number &i);
    Number operator*(const Number &i);
    Number operator/(const Number &i);
    Number operator%(const Number &i);

    template<class U> friend ostream& operator<< (istream &is, const Number<U> &i);
    
    template<class U> friend istream& operator>> (istream &is, const Number<U> &i);
    
    T value() const{ return val; }
    void set_value(T newval){ val = newval; }

private:
    T val{T{}};
};


// Normal Constructor:

template<class T> ostream& operator<<(ostream &os, const Number<T> i){
    return os << i.value();
}

template<class T> istream& operator>>(istream &is, Number<T> i){
    T val;
    is >> val;
    i = Number<T>{val};

    return is;
}

template<class T> Number<T> Number<T>::operator+(const Number<T> &i){
    Number<T> result(this->val + i.val);
    return result;
}

template<class T> Number<T> Number<T>::operator-(const Number<T> &i){
    Number<T> result(this->val - i.val);
    return result;
}

template<class T> Number<T> Number<T>::operator*(const Number<T> &i){
    Number<T> result(this->val * i.val);
    return result;
}

template<class T> Number<T> Number<T>::operator/(const Number<T> &i){
    if (!i.val)
	throw std::runtime_error("Cannot divide by zero.");

    Number<T> result(this->val / i.val);
    return result;
}

template<class T> Number<T> Number<T>::operator%(const Number<T> &i){
    if (!i.val)
	throw std::runtime_error("Cannot divide by zero.");

    T va = static_cast<T>(fmodl(this->val, i.val));
    Number<T> num(va);
    return num;
}



template<class T> T vector_sum(const vector<T> &v1, const vector<T> &v2){
    if (v1.empty() or v2.empty())
	throw runtime_error("Cannot work with empty vectors.");
    
    uint64_t max_size = (v1.size() > v2.size()) ? v2.size() : v1.size();

    T sum{T()};
    for (uint64_t i = 0; i < max_size; i++){
        //sum = v1[i] + v2[i] + sum;
    }

    return sum;
}

int main(void){
    vector<Number<double>> vec1, vec2;
    for (int i = 0; i < 10; i++)
	vec1.push_back(Number<double>(1.04 * i));
    

    for (int i = 0; i < 10; i++)
	vec2.push_back(Number<double>(1.09 * i));


    // Now apply function:
   	cout << "Sum of both vectors: " << vector_sum(vec1, vec2);
    Number<double> temp1{5};
    Number<double> temp2{4};
    Number<double> temp3{1};
    temp3 = temp1 + temp2 + temp3;
}
