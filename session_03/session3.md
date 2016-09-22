# Structs and Classes

C++ has two data structures that resemble python classes. They are structs and classes.

They are so similar that, rather than talk about them separately, I will discuss classes and then come back and talk about the trivial differences between classes and structs.

So, on with it.

## classes 

 Since this is a class for folks who are python savvy, let's compare c++ classes to python classes.
 
 #### class keyword
 
 Like in python, in c++, a class is defined using the class keyword:
 
 ##### Python
 
 ```
 # python
 class Person(object):
 ```
 ##### C++
 ```
 class Person {
 };
 ```
 
#### Self reference

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

#### Access Specifiers - Privacy, Publicy, protected-cy 

One thing you might have fussed with in python a bit is the notion of privacy. You might have prefixed variables with an underscore as a way of telling the rest of the world that said variable is part of an implementation, and shouldn't be mucked with. You might have even gone so far as to use two underscores in order to invoke name mangling. Well, no offense to python, but its implementation of privacy is second rate and you can get around it. Privacy is kind of like what sexist dinosaurs would have referred to as a "gentlemen's agreement". Phoey!

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

#### Constructor

Python has the initializer, otherwise known to true geeks as the dunderinit (__init__). Technically, this is an initializer, not a constructor, but lets gloss over that.

In C++, you have one or more constructor member functions. I say one or more, because c++ supports overloaded functions in addition to default parameters. So, for any function, you can redefine it multiple times, as long as the parameters differ in each version. This added flexibility is useful, because c++ is strictly typed... so, getting back to the constructor, lets take a look at how it is formed. 

Adding to our person class:

```
Person {
    std::string firstname, lastname;
public:
    Person() : firstname(""), lastname("") {}; // default constructor 
    Person(std::string fname, std::string lname) : firstname(fname), lastname(lname) {}; // parameterized constructor
}
```

So, lets talk about this. 