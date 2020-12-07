/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 03/02/2020
 * 
 * Chapter 19_12
 * Define a File_handle class with a constructor that takes a string argu-
 * ment (the file name), opens the file in the constructor, and closes it in the
 * destructor.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <fstream>
#include <filesystem>
//#include <boost/filesystem.hpp>
using namespace std;

void handle_file(fstream &fs, string s);

class File_handle{
public:
    explicit File_handle(string s) : file_name{s} {
        // First handle opening the file.
		handle_file(fs, s);
    }
    
    ~File_handle(){
		// Close the file.
		fs.close();
    }

    void change_file(string s);
    string get_filename() const { return file_name; }
    fstream& file() { return fs; }
private:
    fstream fs;
    string file_name;
};

// Using boost here:
// void handle_file(fstream &fs, string s){
//     boost::filesystem::path path {s};
//         if (boost::filesystem::exists(path)) // Boost library works as well.
//             fs.open(s, ios_base::in | ios_base::app);
//         else // Assume that this file doesn't exist, so create it.
//             fs.open(s, ios_base::out);
// }

// Standard Library here:
void handle_file(fstream &fs, string s){
    if (std::filesystem::exists(s))
		fs.open(s, ios_base::in | ios_base ::app);
    else // if file doesn't exist, then create it.
		fs.open(s, ios_base::out);

    
}

void File_handle::change_file(string s){
    fs.close();
    handle_file(fs, s);
    file_name = s;
}


int main(void){
    File_handle fh("../Chapter19_12.txt");
    fh.file() << "Hello There! This sentence was added in Chapter19_12.cc!"
			  << endl;
    cout << "It is done." << endl;
    
	

}
