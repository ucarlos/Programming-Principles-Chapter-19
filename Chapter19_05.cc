/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 02/21/2020
 * 
 * Chapter 19_05
 * Define a class Int having a single member of class int . Define construc-
 * tors, assignment, and operators + , – , * , / for it. Test it, and improve 
 * its design as needed (e.g., define operators << and >> for convenient I/O).
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Int{
public:
    int get_value() const { return value; }
    void set_value(int new_val) { value = new_val; }

    Int()=default;
    explicit Int(int new_val) : value{new_val} { }

    // Copy assignmeents
    Int(const Int &int_object) { this->value = int_object.value; }
    Int& operator=(const Int &);
    Int operator+(const Int &);
    Int operator*(const Int &);
    Int operator-(const Int &);
    Int operator/(const Int &);
private:
    int value{0};

};


// Operator function definitions

Int& Int::operator=(const Int &i)= default;

Int Int::operator+(const Int &i){
    int temp = this->value + i.value;
    return Int{temp};
}

Int Int::operator-(const Int &i){
    int temp = this->value - i.value;
    return Int{temp};
}

Int Int::operator*(const Int &i){
    int temp = this->value * i.value;
    return Int{temp};
}

Int Int::operator/(const Int &i){
    if (!i.value)
	throw runtime_error("Error: Division by Zero.");

    int temp = this->value / i.value;
    return Int{temp};
    
}

ostream& operator<<(ostream &os, const Int &i){
    return os << i.get_value();
}

istream& operator>>(istream &is, Int &i){
    int val;
    cin >> val;
    i = Int(val);
    return is;
}


int main(void){
    Int example1;
    cout << "Please enter a number." << endl;
    cin >> example1;
    cout << "Example 1 value: " << example1.get_value() << endl;

    Int example2{15};
    cout << "Example 2 value: " << example2.get_value() << endl;

    Int example3 = example1 * example2;
    cout << "Example 3 value: " << example3.get_value() << endl;

    Int example4 = example1 + example2;
    cout << "Example 4 value: " << example4.get_value() << endl;

    Int example5 = example1 - example2;
    cout << "Example 5 value: " << example5.get_value() << endl;
    
    Int example6 = Int{5} / Int{1};
    cout << "Example 6 value: " << example6.get_value() << endl;
    
    return 0;
}
