# Memory Management

Two sessions ago, we began exploring classes. We started by talking about constructors, and then delved into copy constructors and assignment operators. Unfortunately, neither the assignment operator nor the copy constructor makes much sense with concrete data types; these methods only really make sense when talking about pointers and managed memory. So today, we are going to get on with one of the most important aspects of C++ - memory management. First, we are going to talk about traditional memory management. Then we are going to delve into c+11's helper classes which make the topic much simpler.

## Manual Memory Management

Managing memory manually is pretty simple; it doesnt require complex maths or twisted logic. However, it does require very rigid book keeping and forethought. As Python programmers you have been freed of the drudgery of thinking about all of this. Well, not any more. Welcome to the exciting world of managing memory. 

In order to learn how to manage memory, you really only need to learn about a pair of commands - *new* an *delete*. As you might expect, new allocates memory on the heap, and delete frees memory on the heap. Here is a simple example of memory creation and deletion:

```
#include <iostream>
#include <string>

int main(){
    // allocate a string on the heap, assigning it to a pointer
    std::string *name = new std::string("Fred Flinstone");
    // use the pointer as we have already learned to do
    std::cout<< "his name is "<< *name << std::endl;
    // delete the memory
    delete name;
    return 0;
}
```

Simple eh? There is actually one variation of this when allocating an array of something. It looks like this:

```
#include <iostream<
#include <string>

int main() {
    std::string* names = new std::string[2] { std::string("fred"),  std::string("barney")};
    std::string << names[0] << " " << names[1] << std::endl;
    
    delete[] names;
}
```

So what is the big deal? Well let's combine this with a class and see. We are going to create a very simple Person class. Here it is:

```
class Person{
    std::string* firstname;
    std::string* lastname;
 Public:
    Person(const std::string& fn, const std::string& ln) :
    firstname(new std::string(fn)), 
    lastname(new std::string(ln))
    {};
    
    void greet() const {std::cout << "hi my name is " << firstname << " " << lastname << std::endl;};
    
}

```

And we will use Person in main.

```
#include "Person.h"
#include <iostream>

int main() {
    Person person("Troy" "Mclure");
    person.greet();
}
```

## First Problem - who is cleaning up person?

The first problem we have here is that Person allocated two strings - firstname and lastname - but didn't dealocate them. We are going to take care of that right now. To handle this automagically, we are going to implement a destructor. The destructor signature looks exactly like a default constructor, but with a tilda (~) in front. For person, that is `~Person`.

### Destructor Implementation

Our Person destructor implementation is going to look like this:

```
~Person() {
    std::cout << "Person destructor called " << std::endl;
    
    // delete any memory we have allocated
    delete firstname;
    delete lastname;
}
```

Great. Now that we have a destructor cleaning up for us, everything is peachy. We don't have to worry about cleaning up. Right? Let's give it a try:

main.cpp
```
#include "Person.h"
#include <iostream>

using std;;cout;
using std::cin;

void use_person() {
    Person bob("Bob", "Bitchen");
    bob.greet();
}

int main() {
    use_person();
    cout << "we are done"<< endl;
    return 0;
}
```

Well that worked. We are done. Memory management isn't so bad. What's all the fuss? Well hold on there bub. We aren't done. Let's take a look at some problems...


main2.cpp
```
#include "Person.h"
#include <iostream>

using std;;cout;
using std::cin;

void use_person() {
    Person bob("Bob", "Bitchen");
    Person bob2 = bob;
    bob.greet();
    bob2.greet();
}

int main() {
    use_person();
    cout << "we are done"<< endl;
    return 0;
}
```

Ouch. So what is going on here? when we assign bob to bob2, the compiler generates a default copy constructor for us, and that default copy constructor does a piecewise copy of all the variables. In other words. bob2.firstname, a pointer to string, is getting set to the *address* of bob.firstname. And when bob and bob2 go out of scope at the end of *use_person()*, they both try and delete the same memory for firstname and lastname!

So how do we fix this? Rememeber the copy constructor? This is what it is for. 

# The Rule of 3

The rule of 3 states that whenever you have to create a destructor to clean up memory, you have to implement a copy constructor and an assignment operator as well. So lets go ahead and do that in Person.

Person.h
```
Person {
...
public:
...
    Person(const Person& other);
    Person& operator=(const Person& other);
}
```

Person.cpp
```
#include <string>
using std::string;

...

Person::Person(const Person& other) {
    firstname = string(other->firstname);
    lastname = string(other->lastname);
}

// assignment operator
Person& Person::Person(const Person& other) {
    // if the address of me is not the same as the address of other
    if(this != &other) {
        if (firstname != nullptr)
            delete firstname;
        if (lastname != nullptr)
            delete lastname;
        firstname = string(other->firstname);
        lastname = string(other->lastname);
    }
    return *this;
}
```