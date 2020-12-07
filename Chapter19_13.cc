/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 03/03/2020
 * 
 * Chapter 19_13
 *
 * Write a Tracer class where its constructor prints a string and its destructor
 * prints a string. Give the strings as constructor arguments. Use it to see
 * where RAII management objects will do their job (i.e., experiment with
 * Tracer s as local objects, member objects, global objects, objects allocated
 * by new , etc.). Then add a copy constructor and a copy assignment so that
 * you can use Tracer objects to see when copying is done.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <new>
#include <string>
using namespace std;

class Tracer{
public:
    Tracer() {
		cout << "Calling Tracer's constructor with no arguments!\n";
    }
    
    explicit Tracer(string s) : info{s} {
		cout << "Calling Tracer's constructor with a string argument \""
			 << info << "\" : \n";

    }

    ~Tracer(){
		cout << "Calling Tracer's destructor! with string \""
			 << info << "\"\n";

    }

    Tracer(Tracer &t); // Copy constructor
    Tracer& operator=(const Tracer &t); // Copy assignment

    string get_info() const { return info; }
    void set_info(string s) { info = s;}
    
private:
    string info{"Blank"};

};


Tracer::Tracer(Tracer &t){
    cout << "Calling Tracer's constructor with a Tracer& argument "
		 << " to copy:\n";
    
    info = t.get_info();

}

Tracer& Tracer::operator=(const Tracer &t){
    cout << "Calling Tracer's operator= with a Tracer& argument.\n";

    // Self-reference check
    if (this == &t) return *this;
    
    info = t.get_info();
    
    return *this;
}


int main(void){
    Tracer object1;
    Tracer object2{"Hello World!"};
    Tracer object3{"Goodnight!"};
    Tracer object4{object3};
    
    object4 = object3;
   


}
