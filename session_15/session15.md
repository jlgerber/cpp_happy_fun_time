# session 15 - Serialization Formats

There are a couple of formats which we need to learn how to read and write so that we can be productive. The big ones
for us are Yaml, Json, Xml. Lets start with YAML.

## YAML

Yaml is a markup language which we have been using for quite some time. It's "clever" title stands for "YAML Ain't 
Markup Language". It's spec may be found at [yaml.org](http://yaml.org). In order to read and write yaml, we are going
to use a popular library - [yaml-cpp](https://github.com/jbeder/yaml-cpp). So, open your favorite browser, and go 
over to the yaml-cpp project on github, because the first step is going to be getting the library.
 
 ## Downloading and Building yaml-cpp
 
 In order to use yaml-cpp, we need to pull it down. When you go to the url, you will notice a couple of 
 things. First, this is not a header only library, which means we have to build and install it somewhere. Second, 
 its last major tagged release is dependent upon BOOST. Now, we love boost, but we don't want the hassle of dealing 
 with a boost dependency if we don't need to. Fortunately, the trunk code has attempted to excise boost. It just needs
 some additional testing. Well, that's what we are going to do. So, click on the *clone or download* button and do 
 as it says. Navigate to the place you want to run the build from ( I do it it ~/src on my machine ) in a shell and
 type the following:
 
 ```
 git clone https://github.com/jbeder/yaml-cpp.git
 ```
 
 Now, follow the directions on github for building it. Navigate into the project, create a *build* directory, and go
 into it. Then run ```cmake ..``` with appropriate flags to build the library. You might be wondering what those 
 appropriate flags are. Well, there are at least two that I can thing of:
 
 If we want to build a shared library, we need to specify -DBUILD_SHARED_LIBS=ON . Otherwise, we will build a static
 library (which is fine by the way).
 
 If we want to control where the install directive puts the results of the build (assuming we are not copying files
 out by hand or we are just relying on the default pathing), we need to use the -DCMAKE_INSTALL_PREFIX=<install_path>.
 This is going to prepend the provided path to the location of the install. So, if the project in question normally 
 installs to */usr/local/bin*, and you use ```-DCMAKE_INSTALL_PREFIX=/home/jlgerber``` ( or better yet your own 
 home directory instead of mine ), then you will end up installing to */home/jlgerber/usr/local/bin*. It is important
 to note this, as you will need to subsequently USE these paths to configure our upcoming project. Also, if you are on 
 windows, this **ISN'T** going to work, due to those pesky drive letters. Anyway, I am going to run the following:
 
 ```
 cmake .. -DCMAKE_INSTALL_PREFIX=/home/<your homedir name>
 make 
 make install
 ```
 
 If you installed to your home directory, please note the addition of two subdirectories - *include* for all of the 
 headers, and *lib/* where it puts your libyaml-cpp.a file.
 
 While you are in the build directory, cd into the *test* subdirectory and run the provided tests. You might as well, 
 they took longer to build than the actual library.
 
 ```
 cd test
 ./run-tests
 ```
 
 ## Setting up a simple yaml file for reading
 
 Before we can read a yaml file, we need one. Lets create a dummy file to go over the fun things we can do with 
 YAML. Create a books.yaml somewhere with the following contents:
 
```

---
-
    name: Remembrance of Things Past
    author: Marcel Proust
    opening:
        For a long time I used to go to bed early. Sometimes, when I had put out my candle, my eyes woudl close so
        quickly that I had not even time to say I'm going to sleep. 
    cost: 36.95
-
    name: Look Homeward Angel
    author: Thomas Wolfe 
    opening:
        A destiny that leads the English to the Dutch is strange enough; but one that leads from Epsom into Pennsylvania,
        and thence into the hills that shut Altamont over the proud coral cry of the cock, and the soft stone smile of 
        an angel, is touched by the dark miracle of chance which makes new magic in a dusty world.
    cost: 15.00
-
    name: Clia
    author: Lawrence Durrell
    opening:
        The oranges were more plentiful than usual that year. They glowed in their arbours of burnished green leaf like 
        lanterns, flickering up there among the sunny woods.
    cost: 4.99
-
    name: Hunger
    author: Knut Hamsun
    opening:
        All of this happened while I was walking around starving in Christiania -- that strange city no one escapes from
        until it has left its mark on him....
    cost: 10.00      
```

So now that you (a) know a least four books sitting on my shelf, and (b) have a suitably complex yaml example, lets 
learn how to deserialize yaml.

## Deserializing Yaml

Time to create a new project. Remember to configure the include path and library path to look at the yaml library we 
just installed. If you are using cmake, your CMakeLists.txt will look something like this:

```
cmake_minimum_required(VERSION 3.2)

project(ReadingYaml)

set(CMAKE_CXX_STANDARD 11)

include_directories( /home/jlgerber/include )

link_directories( /home/jlgerber/lib )

file(GLOB cpps src/*.cpp)
file(GLOB hpps src/*.hpp)

add_executable( read-yaml ${cpps} ${hpps})
target_link_library( read-yaml yaml-cpp)
```

Now, create your main function and lets get down to brass tacks.
 
```
#include <iostream>

#include "yaml-cpp/yaml.h"

int main() {
    readYaml();
    return 0;
}
``` 

### Easing into it
Ok, lets ease into reading some yaml. Before we tackle the file above, we are going to get our feet wet with some basics.
First, Yaml is stored in memory as a tree of YAML::Nodes. Each document has a root node, and child nodes. Let's create a
sequence:

```
void readYaml() {
    YAML::Node node = YAML::Load("[1, 2, 3]");
    assert(node.Type() == YAML::NodeType::Sequence);
    assert(node.IsSequence()); // a shortcut to the code above
}
```

Sequences and Maps are contained in special Collection nodes, which act a bit like STL vectors amd maps. In our example
above, we can iterate over the sequence one of two ways: 

```
for(std::size_t i=0; i < node.size(); i++) {
    std::cout << node[i].as<int>() << "\n";
}
```

Or using iterators:

```
for(YAML::const_iterator it=node.begin(); it != node.end(); ++it) {
    std::cout << it->as<int>() << "\n";
}
```

In either case, we have to fetch the contents of the child, and we have to provide type information when we do so. This
is handled by the ```as``` template function.

### Reading the file
We are going to read that yaml file from above, starting with a blank readYaml function, and filling out out slowly.

```
void readYaml() {

}
```

Ok, well lets load the file. We can do this using the ```YAML::LoadFile function```

```
YAML::Node books_root = YAML::LoadFile("/home/jlgerber/books.yaml");
```

Ok, we now have a YAML::Node. Let's check to make sure it is what we think it is. Looking at our document, the top node
should be a sequence type.

```
assert(books_root.IsSequence());
```


