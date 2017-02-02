# Chapter 1

## Introduction
C++ is a strongly typed, compiled, high performance language, which evolved from c. It shares c's syntax, as well as c's ability to interface fairly directly with hardware. It can be used to write very "close to the metal" code, as well as highly abstracted code. C++ places more responsibilities on the developer, and it is likely that the two areas which will be the most alien to you, the python develoepr, are memory management and strict typing. However, the big payoff in taking these responsibilities on is the ability ( notice i didnt say guarantee ) of producing high performance code.

## structure of a c++ program

Like a python program, a C++ program can consist of many files. And like a python program, a c++ executable ultimately has a single entry point. In C++'s case that entry point is the **main function**. So let's write our first c++ program. Create a file called *hello.cpp* with the following in it:

```
#include <iostream> 

int main() {
    std::cout << "hello world" << std::endl;
    return 0;
}
```

And compile it on the command line:

```
g++ hello.cpp -o hello
```

Tada, you should have an executable called hello, which will greet the world when run. Even in this trivial program, we have a lot to talk about. So let's get at it.

## Braces - lots of braces

C++ is a descendant of C. As such, it uses braces to encapsulate scope. That stands in stark contrast to Python, which uses indentation to differentiate scope. So, you wrap blocks in curly braces to delineate scope. Formatting is strictly for readability. 

## statements

In python, statements end in newlines. In C++, statements end in semi colons. That means you can split statements over multiple lines without a problem. 

In Python you would have to do this:
```
foo \
=1

```

But in c++ you simply type this:
```
int foo
= 1;
```

## Data Types

C++ is a strongly typed language. All variables have an explicit type which cannot be changed at runtime, unlike python. When you declare a variable, you prefix it with its type name. And it *never ever changes*. That is a big change from Python, so soak it in. 

The atomic data types are ( off the top of my head):

* bool
* char
* wchar
* short
* int
* long
* long long 
* float
* double

For each of the int types , there exists an unsigned type, which does not allow for negative numbers.

short int, int, long, and long long all belong to the family of integers. They differ in terms of the range of integers which they represent/can hold. They can each be spelled explicitly (ie short int, long int)

float, double belong to the family of real numbers. They too differ in terms of the range that each can hold.

## Functions

Functions in python and c++ are very similar. In python, to declare a function, you do so using the *def* keyword:

```
def foo(bar):
    """
    do something
    """
    print "foo",bar
```

C++ has no such keyword. Instead, the compiler recognizes functions by their *shape". Additionally, when you define a function in C++, you are responsible for defining the explicit type, if any, that the function returns, as well as the types of all of the parameters, if any.

```
bool foo(string bar) {
    cout << "foo " << bar << endl;
    return true;
}
```

As you can see, function signatures start with a type (```bool`` in this case), followed by a name, and parens. Within the parens, you may have zero or more parameters. These parameters have to be explicitly typed. Above, you can see that we have one parameter, bar, which is of type string. After the parens, the body of the funciton is delineated with a pair of curly braces. It is considered good form to indent the body of the function, but formatting has no effect of the actual code. 

Finally, our function must return data, per its signature. It does so using the *return* keyword. 

## includes, the modules of the python world

In c++, like in python, you can split your implementation of a program up into multiple files. And like, python, you can leverage existing libraries to do much of the low level work for you; you are not stuck writing everything from scratch, and much of what is considered modern C++ is actually provided by the Standard Library, and not the language itself ( although the standard library is, well standard, and available on all compilers so...)

In python, you import modules. C++ doesnt have a module system ( yet. its on the way).However, you can include other code using the #include preprocessor directive. There are actually two forms:

```
#include<>
```
and 
```
#include ""
```
The <> form is used to include libraries which are provided externally. For instance, C++ ships with a large library, much like the standard library python ships with. 

The "" form is used to include other files which are in your project. These are similar to the internal import statements in a python package.

The directive ```#include <iostream>``` imports the iostream library which makes a number of functions and classes available to us in the ```std``` namespace. ( we will cover namespaces later ). A namespace is a label used to disambiguate names and avoid clashes. Namespaces prefix lables and are affixed using '::'. For example ```std::cout``` from above references *cout* in the *std* namespace. 


## The main function
Every executable has an entrant function called main, which is invoked when executing the program. The python equivalent, and there isn't a perfect one, would probably be this:

```
if __name__ == "__main__":
    from sys import argv
```

In C++, the main function has three valid forms. All the forms have one thing in common: they each must return an integer representing success or failure. Under normal circumstances, you return "0". If there are issues, you can return an error code, which is os specific. 

### The first form of main
The first form is:

```c++
int main() {
    // bla bla bla
    return 0; // 0 indicates that everything is peachy
}
```
It is a function with no arguments, which must return a *bool*, as mentioned above. This form is the easiest to write, but the least useful.

### the second form of main
The second, and most popular form of main, takes two arguments. The first is the number arguments passed to main when the program is run. The second is a list of c string arguments, passed on the command line when the program is run.

The second form is:

```
int main(int argc, char* argv[] ) {
    // bla bla bla 
    return 0;
}
```

In the second form, as you can see, the main function takes two arguments. They are:

- int argc: the number of arguments that the executable is called with.
- char* argv[] : an array of c style strings representing those arguments. ( you might also see the second argument written as `char** arvg`. Its effectively the same thing and we will get into that when we discuss pointers...)

By the way, the type signatures are required, but the names of the two arguments can be anything. By convention, they are *argc* and *argv*. You should probably stick to this naming, because that is what people expect. 

You can use either of the two forms for main, although I recommend using the former, simpler one, unless you need to access the calling parameters.

### The third form

The third form adds a third parameter to main which is a c string array of environment variables:

```
int main(int argc, char* argv[], char* env[] ) {
    // bla bla
    return 0;
}
```
Each string in the env array takes the form *VAR=Value*. We will learn later how to separate the VAR from the Value in order to make use of this information.

## Namespaces
C ++ allows you to wrap code in a namespace in order to organize and protect symbols. Namespaces are roughly equivalent to python's package definitions. However, unlike packages, which rely on the directory structure to form the shape, C++'s namespaces are explicitly defined with the *namespace* keyword.

```
import os
os.path.dirname() 

def dirname(foo): 
    print "dir dir dir", foo
    
os.path.dirname("/foo/bar")  
```

Namspaces are defined thusly in c++:

```
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
Or import everything in a namespace into the current namespace:
```
using namespace foo;
bar();
```

Why am i telling you this now? There are many useful libraries which live in the `std` namespace. We will take a look at a couple of them, but first we need to learn how to include them in our code.

## CPP Preprocessor: including other code

All commands prefixed by a pound symbol are preprocessor directives. The preprocessor runs as the first step in compilation. One of the primary roles of the preprocessor is to include other files into cpp files. This is generally analogous to python's import statement. We will get into what is going on here a bit more later. 

There are two forms which we are interested in:
```
#include <LIBRARY> 
#include "myHeader.h"
```

The former is used to include headers for compiled libraries and the latter is used to include non-precompiled headers, generally in your own project. The former searches in predefined locations, as well as locations explicitly specified via compiler flags. The latter ("") first searches in the directory in which the directive appears, and then degrades to the former (<>) behavior, in the event that the header file is not found.
