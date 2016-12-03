# Modern C++
What is modern c++? Well, the definition has changed over time. Here are some isms though...

## Looping over every element in a collection? - Prefer range-for

```
for(auto& e: s) {...use(e);...}
```

Note: range-for does not support early break. If you need early break, you cannot use it.

## Don't use Owning *, new, or delete
 
 C++98 had you do this...
 ```
 widget* factory();
 void caller() {
    widget* w = factory();
    gadget * g = new gadget();
    use(*w, *g);
    delete g;
    delete w;
 }
 ```
 
 modern c++ 
 ```
 unique_ptr<widget> factory();
 void caller() {
    auto w = factory();
    auto g = make_unique<gadget>();
    use(*W, *g);
 }
 ```
 
 For new, use make_unique, make_shared if the resource is truly shared. For delete, use nothing.
 
 Non-owning references and pointers are still great.
 
 ```
 // if w is required
 void f(widget& w) {
    use(w);
 }
    
 // if w is optional
 void g(widget* w) {
    if(w) use(w);
 }
 ```
 
 Using the functions in modern C++
 ```
 auto upw = make_unique<widget>();
 f(*upw);
 
 auto spw = make_shared<wdiget>();
 g(spw.get())
 ```
 
 ### Anti-Pattern 1
 Routinely passing a smart pointer, even by reference... Don't do it. 
 ```
 void f( shared_ptr<widget>& w) {
    use(w);
 }
 ```
 
 ### Anti-Pattern 2
 Loops
 
 ```
 refcnt_ptr<widget> w =...;
 for(auto& e : baz) {
    auto w2 = w;
    use(w2, e, whatever);
 }
 ```
 
 reference counted smart pointers are about managing an object's lifetime. Copy/assign one only when you intend on manipulating the object's lifetime.
 
 ## Creation / Consumption of Smart Pointers
 
 - return a unique_ptr from factories. 
 - Accept a unique_ptr for functions which hold ownership. This will force a std::move to use it.
 - Accept a unique_ptr reference if you want to reseat ( change what is pointed to )
 ```
 unique_ptr<widget> factory();
 
 void sink(unique_ptr<widget> w); // sink - consumes widget
 
 void reseat(unqiue_ptr<widget>&); // will or might reseat ptr
 ```
 
 ### Anti Pattern 1
 
 never accept a const smaprt pointer reference. There is no reason to do so. Use a raw pointer instead.
 
 ## Auto 