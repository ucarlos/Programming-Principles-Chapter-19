/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 02/20/2020
 * 
 * Chapter 19_04
 * Modify class Link from §17.9.3 to be a template with the type of value
 * as the template argument. Then redo exercise 13 from Chapter 17 with
 * Link<God> .
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <new>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class God{
public:
    string name;
    string mythology;
    string vehicle;
    string weapon;

    God(string nam, string myth, string veh, string w) :
        name{nam}, mythology{myth}, vehicle{veh}, weapon{w} { }

    explicit God(string new_name) : name{new_name} { }
    God()=default;;
};


template<typename T> class Link{
public:
    T value;
    explicit Link(T newval) : value{newval} { }
    
    Link(T newval, Link<T> *previous, Link<T> *next) :
		value{newval}, prev{previous}, succ{next} { }
    
    Link<T>* insert(Link<T> *link);
    Link<T>* add(Link<T> *link);

    // Add in Order:
    Link<T>* add_ordered(Link<T> *link);

    Link<T>* erase();
    Link<T>* find(T value);
    Link<T>* begin(Link<T> *list);
    
    Link<T>* advance(int n) const;
    Link<T>* next() const { return succ; }
    Link<T>* previous() const { return prev; }
    string print_value();
private:
    Link<T> *prev{nullptr};
    Link<T> *succ{nullptr};
    unsigned int size{1};
};

bool operator<=(const God &god1, const God &god2);
bool operator==(const God &god1, const God &god2);
bool operator!=(const God &god1, const God &god2);


template<typename T> Link<T>* Link<T>::add_ordered(Link<T> *link){
    // The problem is that we need to sort this link before adding it.
    if (link == nullptr) return this;
    if (this == nullptr) return link;
    
    Link<T> *temp = this;
    // First use the <= operator. if value < link.value, break.
    while (temp->succ != nullptr){
		if (this->value <= temp->value)
			break;
		else temp = temp->succ;
    }

    // If temp->succ is really null, then just return the add.
    if (!temp->succ && this->size > 1) return temp->add(link);
    else return temp->insert(link);

}

bool operator<=(const God &god1, const God &god2){
    return (god1.name <= god2.name) && (god1.mythology <= god2.mythology)
		&& (god1.vehicle <= god2.vehicle) && (god1.weapon <= god2.weapon);

}

bool operator==(const God &god1, const God &god2){
    return (god1.name == god2.name) && (god1.mythology == god2.mythology)
		&& (god1.vehicle == god2.vehicle) && (god1.weapon == god2.weapon);
}

bool operator!=(const God &god1, const God &god2){
    return !(god1 == god2);
}

template<typename T> Link<T>* Link<T>::insert(Link<T> *link) {
    if (link == nullptr) return this;
    if (this == nullptr) return link;

    link->succ = this;
    if (prev) prev->succ = link;
    link->prev = prev;
    prev = link;
    size++;
    
    return link;
}

template<typename T> Link<T>* Link<T>::add(Link<T> *link){
    // first determine if n or this is nullptr.
    if (link == nullptr) return this;
    if (this == nullptr) return link;
    link->prev = this;
    if (succ){
		succ->prev = link;
		link->succ = succ;
    }

    succ = link;
    size++;
    return link;
}

template<typename T>
string Link<T>::print_value() {
    ostringstream os;
    os << value << "\n";
    return os.str();
}

template<typename T> Link<T>* begin(Link<T> *link){
    while (link->previous() != nullptr){
	    link = link->previous();
    }
    return link;
}


istream& operator>>(istream &is, Link<God> link) {
    string name, mythology, vehicle, weapon;
    is >> name >> mythology >> vehicle >> weapon;

    God god = God(name, mythology, vehicle, weapon);
    link.value = god;
    return is;

}
ostream& operator<<(ostream &os, const God &god){
    return os << "Name: " << god.name << endl
			  << "Mythology: " << god.mythology << endl
			  << "Vehicle: " << god.vehicle << endl
			  << "Weapon: " << god.weapon << endl;
}



void clear_buffer(Link<God> *link){
    link = begin(link);
    
    while (link->next() != nullptr){
		link = link->next();
		delete link->previous();
    }
    // Now delete link
    delete link;
}

void print_all(Link<God> *list){
    if (!list){
		cerr << "Warning: This list is empty.\n";
		return;
    }

    while (list){
		cout << list->value;
		list = list->next();
    }


}

void add_to_list(Link<God> *list, vector<string> &god_list, string mythology){
    Link<God> *new_link = nullptr;
    God temp_god;
    for (int i = 0; i < god_list.size(); i++){
		temp_god = God(god_list[i], mythology, "", "");
		new_link = new Link<God>(temp_god);
		list->add_ordered(new_link);
		list = begin(list);
    
    }

}

int main(void){
    God temp = God("Zeus", "Greek", "", "Lightning");
    Link<God> *greek_gods = new Link<God>(temp, nullptr, nullptr);
    temp = God("Ymir", "Norse", "", "");
    Link<God> *norse_gods = new Link<God>(temp, nullptr, nullptr);
    

    vector<string> greek_list = {"Apollo", "Hades", "Artemis", "Athena"};
    vector<string> norse_list = {"Odin", "Thor", "Freia", "Loki"};

    add_to_list(norse_gods, norse_list, string{"Norse"});
    add_to_list(greek_gods, greek_list, string{"Greek"});
    
    greek_gods = begin(greek_gods);
    norse_gods = begin(norse_gods);
    print_all(greek_gods);
    
    print_all(norse_gods);

    clear_buffer(greek_gods);
    clear_buffer(norse_gods);


}
