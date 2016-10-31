# Structs and Classes

C++ has two data structures that resemble python classes. They are structs and classes.

They are so similar that, rather than talk about them separately, I will discuss classes and then come back and talk about the trivial differences between classes and structs.

Before we delve into the guts of c++ classes, we should probably talk about what they are about. The goal of the Class construct is to allow a developer to  model a user defined type which behaves like a built in type. In order to achieve this goal, C++ and Python both provide a rich set of operators which may be specialized to achieve parity between custom and built in types. 

In Python, you can implement a wide variety of [dunder methods](shttp://infohost.nmt.edu/tcc/help/pubs/python/web/special-methods.html) to customize mathematical operations, comparison, and more. (by dunder methods, I mean double underscore methods. `__add__ __sub__ __setattr__` etc)

In C++, you can customize all of the mathematical operations ( `+ - * / += -= *= /= ++ --`), comparison ( `== < > <= >= !=` ), assignment ( `=` ), and more.
 
Both languages provide these facilities so that you may create data types for yourself which behave just like the built in ones.

Great. Lets get going....

## Classes 

 Since this is a class for folks who are python savvy, let's compare c++ classes to python classes.
 
### class Keyword
 
 Like in python, in c++, a class is defined using the class keyword:
 
#### Python
 
 ```
 # python
 class Person(object):
 ```
#### C++
 ```
 class Person {
 };
 ```
 
### Self Reference

In python, each instance method has an explicit reference to itself, commonly spelled out as *self*, which all instance methods are passed explicitly as their first parameter.

C++ has an implicit reference to itself, called *this* which is a pointer to itself ( we cover pointers elsewhere ). However, you rarely need to use *this*, as C++ is usually smart enough to recognize references to member functions and data. 

For completeness sake ( hopefully this isn't confusing ), consider a greet method defined in a person class in python and c++, which we assume has an instance variable called *myname*:

python
```
...
def greet(self, other):
    print "Hello {}, my name is {}".format(other, self.myname )
```

c++
```
...
void greet(const std::string& other) {
    cout << "Hello "<< other << ", my name is " << myname << endl;
}
```

### Access Specifiers - Private, Public, Protected 

One thing you might have fussed with in python a bit is the notion of privacy. You probably have prefixed variables with an underscore as a way of telling the rest of the world that a variable is part of an implementation, and shouldn't be mucked with. You might have even gone so far as to use two underscores in order to invoke name mangling. Well, no offense to python, but its implementation of privacy is second rate and you can get around it. Privacy is kind of like what sexist dinosaurs would have referred to as a "gentlemen's agreement". Phoey!

In a c++ class, all of your variables and functions are defined under an access specifier. And there are three of them:
- public
- private
- protected 

Public data and functions may be accessed by anyone. Instance methods, external callers, you name it.

Private data and functions may only be accessed internally by other functions within the class.

Lastly, protected data and functions may only be accessed by internal functions / data or by internal mechanisms of classes which inherit from the class in which the protected data lives.

Oh, and access specifiers may be used more than once. Anything following an access specifier belongs to it. And class data is private by default. So if you see data or methods but no specifier, that data and those methods are private....

Example Time:

```
// person defined with all public methods
class Person {
 public:
    // constructor 
    Person(std::string name) : name(name) {};
    std::string name
};

//
class PrivatePerson {
private:
    std::string name;
public:
    PrivatePerson(std::string name) : name(name) {};
};
//
class ProtectedPerson {
protected:
    std::string name;
public:
    ProtectedPerson(std::string nm) : name(nm) {}
};

class Man : public ProtectedPerson {
    public:
    void greet() { std::cout << "Hi, my name is "<< name << std::endl;}
}
//
// main funciton

int main() {
    // this works
    Person dude("The Dude");
    std::cout << dude.name << std::endl;
    
    // this doesnt
    PrivatePerson privateDude("The Private Dude");
    std::cout << privateDude.name << std::endl;
    
    // protected
    Man theDude("The Dude");
    theDude.greet(); 
    // this doesnt work
    theDude.name = "Shelly";
    
    return 0;
};
```

### Constructor

Python has the initializer, otherwise known to true geeks as the dunderinit (__init__). Technically, this is an initializer, not a constructor, but let's gloss over that.

In C++, you have one or more constructor member functions. I say one or more, because c++ supports overloaded functions in addition to default parameters. So, for any function, you can redefine it multiple times, as long as the parameters differ in each version. This added flexibility is useful, because c++ is strictly typed... so, getting back to the constructor, let's take a look at how it is formed. 

Adding to our person class:

```
Person {
    std::string firstname, lastname;
public:
    Person() : firstname(""), lastname("") {}; // default constructor 
    Person(const std::string& fname, const std::string& lname) const : firstname(fname), lastname(lname) {}; // parameterized constructor
}
```

So, let's talk about this. There are a couple of interesting things going on here. First, we have something called the *member initializer list*. it appears after the parens and before the brackets. It starts with a colon. See it? 

```
somefunction() : <intializier list> {}
```
The initializer list is a comma separated list of data members which may be initialized form the parameter list of the function, or any constants, using method or uniform initialization notation (assuming you are compiling with c++11 support). 

## Operator Overloading

In C++ you can define custom behavior for wide variety of operators. Doing so is known as *operator overloading*. Let's take a look at how this works by looking at overloading addition.

#### Binary  & Unary Operators
In general, binary operators (operators operating on two items) and unary operators (operators operating on one item) are overloaded by defining class methods which return an instance of the class in question, are named "operator" followed by the actual operator in question, and take a const reference to an instance of the class. So for addition, the declaration looks like this ( assuming we have a Point class):

```
class Point {
    ...
public:
    ...
    Point operator+(const Point& rhs); 
    Point operator++(const Point& rhs);
};
```

Python would be similar, although python does not have `++` or `--` operators..
```
class Point(object):
    ...
    def __add__(self, other):
        ...
```

#### Relational Operators 
Relational operators return a boolean, and take a const reference to the containing class. So, continuing our example of Point:

```
class Point {
    ...
public:
    ...
    Point operator+(const Point& rhs); 
    Point operator++(conts Point& rhs);
    bool operator==(const Point& rhs);
};
```

Once again, Python looks like this (foregoing implementation):

```
class Point(object):
    ...
    def __add__(self, other):
        ...
    def __eq__(self, other):
        ...
```
