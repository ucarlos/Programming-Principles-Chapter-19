/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 02/21/2020
 * 
 * Chapter 19_06
 * Repeat the previous exercise, but with a class Number<T> where T can be
 * any numeric type. Try adding % to Number and see what happens when
 * you try to use % for Number<double> and Number<int> .
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
using namespace std;


// In lieu of C++20 concepts, make sure you use a element

template<typename T> class Number{ 
public:
    T get_value() const { return value; }
    void set_value(T new_val) { value = new_val; }

    Number()=default;
    explicit Number (T val) : value{val} { }

    // Operations
    Number<T>& operator=(T val);

private:
    T value{};
};

template<typename T> Number<T>& Number<T>::operator=(T val){ // Is this even necessary?
    this->set_value(val);
    return this;
}

// Operator Overloading declarations
template<typename T> Number<T> operator+(Number<T> &num1, Number<T> &num2);
template<typename T> Number<T> operator-(Number<T> &num1, Number<T> &num2);
template<typename T> Number<T> operator*(Number<T> &num1, Number<T> &num2);
template<typename T> Number<T> operator/(Number<T> &num1, Number<T> &num2);
template<typename T> Number<T> operator%(Number<T> &num1, Number<T> &num2);

template<typename T> istream& operator>>(istream &is, Number<T> &num1){
    T value;
    is >> value;
    num1 = Number<T>(value);

    return is;
}

template<typename T> ostream& operator<<(ostream &os, Number<T> &num1){
    return os << num1.get_value();
}

// Arithmetic Operators 
template<typename T> Number<T> operator+(Number<T> &num1, Number<T> &num2){
    T value = num1.get_value() + num2.get_value();
    return Number<T>(value);
}

template<typename T> Number<T> operator-(Number<T> &num1, Number<T> &num2){
    T value = num1.get_value() - num2.get_value();
    return Number<T>(value);
}

template<typename T> Number<T> operator*(Number<T> &num1, Number<T> &num2){
    T value = num1.get_value() * num2.get_value();
    return Number<T>(value);
}

template<typename T> Number<T> operator/(Number<T> &num1, Number<T> &num2){
    T value = num1.get_value() / num2.get_value();
    return Number<T>(value);
}

template <typename T> Number<T> operator%(Number<T> &num1, Number<T> &num2){
    T value = fmod(num1.get_value(), num2.get_value());
    return Number<T>(value);

}

int main(void){
    Number<int> num1(15);
    Number<int> num2(10);

    Number<double> num3(30);
    Number<double> num4(27);
    Number<double> num5 = num3 % num4;
    num1 = num1 + num2;
    num2 = num2 * num2;

    cout << num1 << endl;
    cout << num2 << endl;
    cout << num5 << endl;

}
