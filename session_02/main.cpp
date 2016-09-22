#include <iostream>
#include <string>
#include <memory>

using namespace std;

void sizes() {
    cout << "bits in byte " << CHAR_BIT << endl;
    cout << "size in bytes of the following data types" << endl;
    cout<< "bool "<< sizeof(bool) << endl;
    cout<< "char "<< sizeof(char) << endl;
    cout<< "int "<< sizeof(int) << endl;
    cout<< "long "<< sizeof(long) << endl;
    cout<< "float "<< sizeof(float) << endl;
    cout<< "double "<< sizeof(double) << endl;
}


struct Person {
    string name;

    Person() : name("") {}
    Person(const string &name) : name(name) {}
    friend ostream &operator<<(ostream &os, const Person &person);
};

 ostream &operator<<(ostream &os, const Person &person) {
    os << "name: " << person.name;
    return os;
}

void eg1() {
    int a = 1;
    cout << "a = " << a << endl;

    int b(1);
    // different ways of constructing variables
    Person john{ "John" }; //<--
    Person bip = Person("bip");
    Person jo("jo");

    Person fred;
    int n;

    cout << john <<  " " << bip <<" "<< jo << endl;
}


class Name /*[: InheritsFrom] */ {
protected:
    string first,last;

public:
    // __init__(blbllb)
    // dont specify a return type
    // match the name of the class
    // default constructor takes no argurments
    //
    Name() : first(""), last("") {
        cout << "default constructor called" << endl;
    }

    Name(const string& first) : first(first), last("None of your Beeeezwax") {
        cout << "constructor called" << endl;
    }

    Name(const string& first, const string& last) : first(first), last(last) {
        cout << "constructor called" << endl;
    }

    friend ostream &operator<<(ostream &os, const Name &name);

private:
    int c;
};

// __str__()
ostream &operator<<(ostream &os, const Name &name) {
    os << "first: " << name.first << " last: " << name.last << " c: " << name.c;
    return os;
}

void name_eg() {
    Name myname{"John", "Zim"};
    Name yourname = Name("Fred");
    cout <<  myname << " " << yourname << endl;
    //cout << myname.first << endl;


}
int main() {
    using namespace std;

      name_eg();


    return 0;

}