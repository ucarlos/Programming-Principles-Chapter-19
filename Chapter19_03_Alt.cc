/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 08/20/2020 at 02:59 PM
 * 
 * Chapter09_03.cc
 * 
 * Write a template class Pair that can hold a pair of values of any type.
 * Use this to implement a simple symbol table like the one we used in the
 * calculator (§7.8).
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>

template<class A, class B> class Pair{
public:
    Pair()=default;
    Pair(A fi, B sec) : first{fi}, second{sec} { }
    
    A get_first() const{ return first; }
    B get_second() const{ return second; }

    void set_first(A val){ first = val; }
    void set_second(B val) { second = val; }

    
private:
    A first{A()};
    B second{B()};
};

int main(void){
    // A simple symbol table
    std::vector<Pair<std::string, char>> table;
    table.push_back(Pair<std::string, char>("quit", 'q'));
    table.push_back(Pair<std::string, char>("prompt", '>'));
    table.push_back(Pair<std::string, char>("exponent", '*'));
    table.push_back(Pair<std::string, char>("add", '+'));
    table.push_back(Pair<std::string, char>("minus", '-'));

    std::cout << "Contents of table: \n";
    for (const auto &i : table)
	std::cout << "[" << i.get_first() << " " << i.get_second() << "]\n";

    std::cout << std::endl;
}
