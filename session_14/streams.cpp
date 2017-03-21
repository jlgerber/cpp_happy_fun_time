//
// Created by jlgerber on 3/20/17.
//

#define FMT_HEADER_ONLY 1

#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <fstream>
#include <ostream>
#include <memory>
#include <string>
#include <cstdio>
#include "fmt/format.h"


void basic_output() {
    std::cout << "this is an example of basic output using streams" << std::endl;
    int meaning_of_life=42;
    std::cout << "Obviously, the meaning of life is " << meaning_of_life << std::endl;
}

void stderr_out () {
    std::cerr << "And this is an example of writing to stderr. ERROR he screamed." << std::endl;
}

void using_ios() {
    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase) ;
    std::cout << "I like to yell in emails " << 77 << std::endl;
    std::cout << std::endl;
}

void inline_formatting() {
    using namespace std;
    cout << "HEX " << hex << 27 << endl;
    cout << "DEC " << dec << 27 << endl;
    cout << endl;
}

void useful_formatters() {
    using namespace std;
    cout << "This is how booleans print normally (true): " << true << endl;
    cout << boolalpha << "I am always 'write' about spelling (true): " << true << " (even when i am wrong)" << endl;
    cout << endl;
}

void useful_formatting() {
    using namespace std;
    cout << setw(22) << left << 1 << setw(22) << left<< 23 << setw(22) << left<< 45 << endl;
    cout <<  setw(22) << right << 1 <<  setw(22)<< right<<23 <<  setw(22)<< right<< 45 << endl;
    cout <<  setw(22)  << internal << 1<<  setw(22) << internal<< 23 <<  setw(22)<< internal<<45 << endl;
}

void getinput() {
    int age;
    using namespace std;
    cout << "How old are you?";
    cin >> age;
    cout << "Did you say that you are " << age << " years old?" << endl;
    cout << "did i fail? " << cin.fail() << endl;
}

void getmultiinput() {
    int age;
    int height;
    using namespace std;
    cout << "State your age and height" ;
    cin >> age >> height;
    if(cin.fail()) {

        cout << "well that was a cheeky answer. I have to fix that" << endl;
        cin.clear();
        return;
    }
    cout << "So you are "<< age <<" years old and " << height << " feet tall "<< endl;
    cin.ignore(); // need this to deal with user return
}

void getlinefromuser() {

    using namespace std;
    string feelings;

    cout << "Tell me how you are feeling" << endl;
   getline(cin, feelings);
    cout << "so you are feeling like this." << feelings << endl;

}

void writefile() {
    using namespace std;
    ofstream fh("/tmp/bla.txt", ios::trunc); // try this with ios::app
    if(fh) {
        fh << "this is a test. we are writing to a file." << endl;
    }
}

void readfile() {
    using namespace std;
    ifstream fh("/tmp/bla.txt");
    if(fh) {
        for(std::string line; getline(fh, line);) {
            cout << line << endl;
        }
    }
}

template<typename ... Args>
std::string string_format( const std::string& format, Args ... args )
{
    size_t size = snprintf( nullptr, 0, format.c_str(), args ... ) + 1; // Extra space for '\0'
    std::unique_ptr<char[]> buf( new char[ size ] );
    snprintf( buf.get(), size, format.c_str(), args ... );
    return std::string( buf.get(), buf.get() + size - 1 ); // We don't want the '\0' inside
}


void sprintfstyle() {

    std::cout << string_format("I lke %d eggs in my soup. And I like %s too.", 3, "you") << std::endl;

}

void fmtstyle() {
    using namespace std;
    string message = fmt::format("The answer is {}. That's right, {}", 42, "forty-two");
    cout << message << endl;

}
int main() {
    std::cout << std::endl;
    basic_output();
    stderr_out();
    using_ios();
    inline_formatting();
    useful_formatters();
    useful_formatting();
    //getinput();
    //getmultiinput();
    //getlinefromuser();
    writefile();
    readfile();
    sprintfstyle();
    fmtstyle();
    return 0;
}