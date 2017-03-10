# Streams

While we have been using streams since the first session, writing data to standard out and standard err with our friends 
```cout``` and ```cerr```, and reading user input with ```cin```, we havent really touched on what streams are exactly,
and what you can do with them. 

Well, ultimately, C++ streams are an abstraction to handle character input and output in a uniform 
fashion, whether the target is a buffer, a file, a string, the networ, or any device that holds characters. Streams work 
with built in data types, and provide a simple mechanism to allow you to extend them to work with custom data types,
through the stream operators (<< and >> ).

Internally, streams are built on top of a character buffer - the streambuf - which is periodically 
flushed to the target. Because the buffer does not hold the entire contents of the stream in memory, (hence stream), 
the one thing you cannot do with a stream is access a random point in the stream. Streams are serial and they flow 
from or to the user to the destination. 

## basic output 

C++ provides standard stream objects for handling *Console I/O*. They include cin, cout, cerr, endl, and clog, adn they
are available via the **iostream** header. You remember these right? You should be using them all the time.

#### Review Time....
You write to standard output using the **cout** object, along with the stream operator **<<**. 

```
std::cout << "I am an output" << "hear me roar" << std::endl;
```

Cout will handle type conversion for you, so you can write basic types other than strings as well.

```
int meaning=42;
std::cout << "Meaning of life is supposedly " << meaning << std::endl;
```

Likewise, you can write to standard error almost exactly the same way:

```
std::cerr << "Warning Will, an ERRROR has occured. Leave Mission Control immediately" << std::endl;
```
## formatted output

C++ provides a separate library to help you control the formatting of streams. It is called **iomanip**. It provides
commands which you apply on the stream, and which change all subsequent interaction. There are a couple of ways of
achieving this. First, you can set flags on the stream object itself. Flags are provided in the *ios* header, which
may or may not come in when you include *iostream* (it is supposed to as of c++11). 

### setting flags on cout

You can set output stream flags using the ```setf``` method on cout or cerr. 

You cna reset output stream using ```unsetf```.


```
#include <iostream>
#include <ios>
using namespace std;

int main() {
cout.setf(ios::uppercase);
cout << "i like to yell in emails" << endl;
cout.unsetf(ios::uppercase);
cout<< "sometimes" << endl;

return 0;
}
```

We use binary OR to select multiple flags. 

```
#include <iostream>
#include <ios>
using namespace std;

int main() {
cout.setf(ios::uppercase | ios::showpos);
cout << "positive?" << 27 << " or negative " << -27 << endl;


return 0;
}
```

A word of warning. setf only turns flags off. It isn't smart enough to disable conflicting flags. That is your job.
For instance, the following wont work:

```
cout.setf(ios::hex);
cout << 27 << endl;
```

Because decimal input defaults to on (ios::dec). You have to do the following:

```
cout.unsetf(ios::dec);
cout.setf(ios::hex);
cout << 27 << endl;
```

### You can drop configuration commands directly into the stream

The previous mechanism tends to be a bit of a pain. Fortunately, C++ provides a better mechanism. You can drop formatting
directly into the stream and it sticks around until you turn it off.

```
cout << hex << 27 << endl;
cout << dec << 27 << endl;
```

#### Useful formatters

- boolalpha - booleans print true and false
- showpos - prefix positive numbers with +
- uppercase


These formatter has a related formatter formed by sticking the word "no" in front. This will turn the formatter off.
(eg noboolapha)

#### justifying text
- internal
- left
- right

Other formatters are part of exclusive groups.

###### floatfield group
- dec - decimal
- hex - base 16
- oct - base 8

##### formatting numbers
- fixed
- scientific
- normal
- showpoint - always show a decimal point

#### setw(n)
Sets the fill width of the input.

```
#include <iostream>
#include <iomanip>

int main() {

using namespace std;
cout << setw(7);
cout << 77 << 44 << "pizza" << endl;
return 0;
}
```

#### setfill(char)
Sets the fill character for manipulation. Can be used in concert with setw.

```
#include <iostream>
#include <iomanip>

int main() {

using namespace std;
cout << setfill('x') << setw(7);
cout << 77 << 44 << "pizza" << endl;
return 0;
}
```

#### setprecision(n)

setprecision is used to format floating point values on output operations. 

```
#include <iostream>
#include <iomanip>

int main() {
float num 4.3452635684786634634574;

using namespace std;
cout << setprecision(3) << "the number is " << num << endl;
return 0;
}
```

#### setiosflags (ios_base::fmtflags mask);

```
#include <iostream>     // std::cout, std::hex, std::endl
#include <iomanip>      // std::setiosflags

int main () {
  std::cout << std::hex;
  std::cout << std::setiosflags (std::ios::showbase | std::ios::uppercase);
  std::cout << 100 << std::endl;
  return 0;
}
```

#### ios::flags

The std::ios module has a number of flags which can be set to change the stream behavior, either by using setiosflags

## Input

## Error Handling

## dealing with files

## strings as streams