# Session 02
## Review
### main
Every executable has an entrant function called main, which is invoked when executing the program. It has two valid signatures:

```c++
int main() {
    // bla bla bla

    return 0; // 0 indicates that everything is peachy
}
```

The second version takes two arguments:
- int : the number of arguments that the executable is called with
- char* argv[] : an array of c style strings representing those arguments. ( you might also see the second argument written as `char** arvg`. Its effectively the same thing and we will get into that when we discuss pointers...)

```c++
int main(int argc, char* argv[] ) {
    \\ bla bla bla 
    return 0;
}
```

## data types

C++ is a strongly typed language. All variables have an explicit type which cannot be changed at runtime, unlike python. 

The atomic datatypes are ( off the top of my head):

* bool
* char
* wchar
* short
* int
* long
* long long 
* float
* double

for each of the int types , there exists an unsigned type, which does not allow for negative numbers.

short, int,  int, long, and long long all belong to the family of integers. They differ in terms of the range of integers which they represent/can hold. They can each be spelled explicitly (ie short int, long int)

float, double belong to the family of real numbers. They too differ in terms of the range that each can hold.

## namespaces
C ++ allows you to wrap code in a namespace in order to organize and protect symbols. Namespaces are roughly equivalent to python's nested module definitions.

```python
import os
os.path.dirname() 

def dirname(foo): 
    print "dir dir dir", foo
    
os.path.dirname("/foo/bar") 

 
```

Namspaces are defined like so:

```c
namespace foo {
    void bar() {
        std::cout << "I am in a namespace" << std::endl
    }
}
```

You reference symbols in a namespace by prefixing them with their namespace, followed by `::`

```
foo::bar();
```

You can also either selectively import a symbol into the current namespace:
```
using foo::bar;
bar();
```
or import everything in a namespace into the current namespace:
```
using namespace foo;
bar();
```

Why am i telling you this now? There are many useful libraries which live in the `std` namespace. We will now look at a couple of them.

## CPP Preprocessor: including other code

All commands prefixed by a pound symbol are preprocessor directives. The preprocess runs as the first step in compilation. One of the primary roles of the preprocess is to include other files into cpp files. This is generally analogous to python's import statement. We will get into what is going on here a bit more later. 

There are two forms which we are interested in:
```
#include <LIBRARY> 
#include "myHeader.h"
```

The former is used to include headers for compiled libraries and the latter is used to include non-precompiled headers, generally in your own project.

There are a ton of useful libraries which ship with c++. Lets look at two of them in an example:

iostream and string.


```
#include <iostream>
#include <string>


int main() {
    std::string name{"Freddy"};
    std::cout << "hello " << name << std::endl;
    return 0;
}
```

## Declaration, Initialization, Definition, and Assignment

Lets talk about terminology, because its fun.

### Declaration

when you name a variable and define its type, that is a declaration. 

example 
```
int foo;
```

### Initialization

Assigning an initial value to a variable.

example of declaration and initialization
```
int foo = 0;
```

### Definition 

In the case of functions, classes, and structs, we can differentiate between declaration and definition. If you provide a definition for your function, class, struct, you are providing an implementation...

### Assignment

Assigning a new value to a variable

```
int foo;
foo = 7;
foo = 12
```

## Functions

Functions in python and c++ are very similar. In python, to declare a function, you do so using the *def* keyword:

```
def foo(bar):
    """
    do something
    """
```

C++ has no such keyword. Instead, the compiler recognizes functions by their *shape".

### Basic Function Declaration

All function declarations look like this:

```
<return type> <function name> ( <parameters>);
```

examples

```
void greet(std::string);
int addtwo(int);
```

So why would you split up the declaration and the definition? There are a couple of more advanced topics where this comes into play. Without going into two much detail:
 
 (2) It is common practice to split up work into header files (.h or .hpp) which contain declarations for data structures, and implementation files (.cpp) which contain implementations. It allows you as an author to expose an interface to a client but keep the implementation hidden. We will look at this later.
 
 (1) You sometimes have to make the compiler aware of the shape of a function, class, or struct, in a different location from its implementation, so that other components may reference it.

### Function definition

If you go a step farther and provide an implementation, you would simply be adding the guts of the code to the end.


```
<return type> <function name> ( <parameters>){ <implementation> };
```

examples
```
void greet(std::string name) {
    std::cout << " Hello " << name << std::endl;
}

int addtwo( int num ) {
    return num + 2;
}
```
### references - part 1

In c++, you can create a reference or alias to a variable by using the `&`. This is commonly used in function declarations for two reasons:
(1) avoid making a copy of a variable because it is large
(2) allow a function to mutate a parameter variable. ( remember, functions are pass by value in C++ )

Note :
    The ampersand has a second use, which is to take the address of a variable. We will go over this soon when we cover pointers...
    
Here is a simple main function:
```
using namespace std;
int main() {
    string aname = "Ralf";
    cout << "before " << aname << endl;
    foo(aname);
    cout << "after " << aname << endl;
    
return 0;
}
```

observe the difference between this:
```
void foo(string name) {
    name = "foo";
}
```

and this:
```
void foo(string &name) {
    name = foo;
}

```

Be careful. The following is not a reference:

```
int bar = 1;
int foo = &bar;
cout << foo << endl;;
```

but this is

```
int bar = 1;
int& foo = bar;

cout << foo << endl;
```
### const keyword

In c++, we have a *const* keyword which can appear in function parameter lists, return declarations, and after method names to signify the fact that the user won't be mutating said data.

example

compiles
```
void printfoo(const std::string& foo) {
    cout << foo << endl;
}
```

error
```
void printfoo(const std::string& foo) {
    foo = "bla";
}
```
