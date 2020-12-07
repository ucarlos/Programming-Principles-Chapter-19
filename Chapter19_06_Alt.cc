/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 08/20/2020 at 04:52 PM
 * 
 * Chapter19_06.cc
 * Repeat the previous exercise, but with a class Number<T> where T can be
 * any numeric type. Try adding % to Number and see what happens when
 * you try to use % for Number<double> and Number<int> .
 *
 * The operator would usually when doing modulo with double/float.
 *
 * 
 * -----------------------------------------------------------------------------
 */
#include <iostream>
#include <cmath>
using namespace std;

template<class T> class Number{
public:
    
    Number()=default; // Default constructor
    Number(T v) : val{v} { } //
    
    Number(Number &i){ val = i.val; } // Copy constructor
    // Copy assignment
    Number& operator=(const Number &i){ val = i.val; return *this; }

    
    Number operator+(const Number &i);
    Number operator-(const Number &i);
    Number operator*(const Number &i);
    Number operator/(const Number &i);
    Number operator%(const Number &i);

    // istream and ostream overloading:
    // friend ostream& operator<< (ostream &os, const Number &i){
    // 	return os << i.value();
    // }
    template<class U> friend ostream& operator<< (istream &is, const Number<U> &i);
    
    template<class U> friend istream& operator>> (istream &is, const Number<U> &i);
    
    T value() const{ return val; }
    void set_value(T newval){ val = newval; }

private:
    T val{T()};
};

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

    T val = static_cast<T>(fmodl(this->val, i.val));
    Number<T> num(val);
    return num;
}


int main(void){
    Number<long> i1{15};
    Number<long> i2{17};
    Number<long> i3;

    i3 = i1 % i2;
    cout << "Normal modulo: \n";
    cout << i1 << " % " << i2 << " = " << i3 << endl;

    Number<double> i4{16.12};
    Number<double> i5{14.42};
    Number<double> i6;
    i6 = i4 % i5;
    
    cout << "Fmod modulo: \n";
    cout << i4 << " % " << i5 << " = " << i6 << endl;


}
