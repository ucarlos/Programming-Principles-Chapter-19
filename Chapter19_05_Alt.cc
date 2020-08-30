/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 08/20/2020 at 04:02 PM
 * 
 * Chapter09_05.cc
 * Define a class Int having a single member of class int . Define construc-
 * tors, assignment, and operators + , – , * , / for it. Test it, and improve 
 * its design as needed (e.g., define operators << and >> for convenient I/O).
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <stdexcept>

class Int{
public:
    
    Int()=default; // Default constructor
    Int(int v) : val{v} { } //
    
    Int(Int &i){ val = i.val; } // Copy constructor
    // Copy assignment
    Int& operator=(const Int &i){ val = i.val; return *this; }

    
    Int operator+(const Int &i);
    Int operator-(const Int &i);
    Int operator*(const Int &i);
    Int operator/(const Int &i);

    int value() const{ return val; }
    void set_value(int newval){ val = newval; }

    friend std::ostream& operator<<(std::ostream &os, const Int &i);
    friend std::istream& operator>>(std::istream &is, const Int &i);
private:
    int val{0};

};

std::ostream& operator<<(std::ostream &os, const Int &i){
    return os << i.val;
}

std::istream& operator>>(std::istream &is, Int &i){
    int val;
    is >> val;
    
    i = Int{val};
    
    return is;
}

Int Int::operator+(const Int &i){
    Int result(this->val + i.val);
    return result;
}

Int Int::operator-(const Int &i){
    Int result(this->val - i.val);
    return result;
}

Int Int::operator*(const Int &i){
    Int result(this->val * i.val);
    return result;
}

Int Int::operator/(const Int &i){
    if (!i.val)
	throw std::runtime_error("Cannot divide by zero.");

    Int result(this->val / i.val);
    return result;
}

int main(void){
    Int i1{15};
    Int i2{12};
    Int i3, i4;
    i3 = i1 - i2;
    i4 = i1 * i2 * i3;

    std::cout << "i1: " << i1.value() << "\n"
	      << "i2: " << i2.value() << "\n"
	      << "i3: " << i3.value() << "\n"
	      << "i4: " << i4.value() << "\n";
    
}
