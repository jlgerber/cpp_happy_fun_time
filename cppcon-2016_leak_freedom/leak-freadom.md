# Leak Freadom

## Lifetime guarantees

Lifetime safety targets these classes of bugs:
- no dangling/invalid deref ( use after delete)
- no null deref
- no leaks (delte objects when no longer used, delete only once)

This years talk is about owners....

## Goal - Ensure an object will be destroyed once it is no longer needed.

### 3 strategies in order of frequency

#### 1 Prefer scoped lifetime

##### natural examples
Locals & member objects, directly owned.

##### Cost
Zero: Tied directly to another lifetime

##### Frequency
80% of objets

#### 2 - Else prefer make_unique & unique_ptr or container
If the object must have its own lifetime (ie the heap) and ownership can be unique w/o owning cycles. 

#### Natural examples
Implementations of trees, lists

#### Cost
Same as new/delete & malloc/free 

#### Frequency
Some amount of the last 20%

### 3 - Else prefer make_shared & shared_ptr
If the object must have its own lifetime, and shared ownership w/o owning cycles.  Automates reference counting four you. 

#### Natural Examples
Node-based DAGS, incl.trees that share out references

#### Cost
Automates shared object usge in library.

#### Frequency 
The least frequent ( somewhere in that last 20%)

- Don't use owneing raw pointers and dont use explicit delete
- Don't create ownership cycles across modules by owning "upward"
- Use weak_ptr to break cycles

# Examples

## HAS-A
Q: What is the natural ownership abstraction for containing another object?. 

A: Data Member.

- Declares lifetime by construction.
- Zero extra allocation

## Decoupled HAS-A
Q: what's the natural ownership abstraction for a decoupled member?
 
A: unique_ptr
Note - if it shouldn't be null, remember to write your own move operations appropriately.
- delcares lifetime by construction
- correct - can see without looking at funciton bodies there are no leaks
- efficient - equal space / time to correctly written manual new/delete
- robust: striclty nested lifetime

## Pimple Idiom ( compilation firewal )
Q: what is the natural ownership abstraction for a Pimple?

A: const unique_ptr 

- declares lifetime by construction
- correct: can see without looking at funciton bodies that there are no leaks
- efficient: equal space & time to correctly wirtten manual new/delete by hand

## Dynamic array member
Q: How can we express a fixed but dynamic size ( set size @ runtime but it doesn't change) member array?
 
A: const unique_ptr<[]>

## Tree 
Q: What is the natural ownership abstraction for a tree?

A: unique_ptr 

Only Manual Part: Update parent pointer when reparenting. Enforce invariant: `left->parent == this && right->parent== this`

### One issue with a tree of unique_ptrs - stack size concerns when deleting.
#### destructors are recursive by default.
```
void release_subtree(unique_ptr<Node> n) {
    // destroy here
}
// calls n->!Node()
// calls n->children[0]->~Node()
// calls n->children[0]->children[0]->~Node();
// ...etc
```
Pro: Automatic and correct

Con: unbound stack depth.

#### Iterative (manual options)

```
void release_subtree(unqique_ptr<Node> n) {
    while(n->children.size() >0 ) {
        auto leaf = &n->children;
        while(leaf[0]->children.size() > 0 ) {
            leaf=&leaf[0]->children;
        }
        leaf.pop_front(); //found leaf, drop it
    }
} // destroy *n iteself here
```

Con: Manual optimization.

Pro: Bounded stack depth.

### trade off for releasing an N-node subtree
- default: prompt, recusive. O(N)
- iterative, in-place: prompt, naviate subtree and run  dtors bottom up. O(NlogN)
- Iterative, copy: Move ptrs to the nodes to be pruned to a flattened local-scoep heap list, ahten run dtors iteratively. +O(N)
- Iterative, deferred: Move ptrs to the nodes to be pruned to a flattend side list, run destructors later iteratively. +O(N) -dtors

## Doubly linked list
Q: whats the natural ownership abstraction for a doubly linked list?

A: unique_ptr down, raw ptr back up.
Only manual part: update previous pointer when relinking. ENforce envariant: `next->prev == this`

FYI: a linked list is a tree of breadth 1.

- Beware of recursive destruction. 

## Tree that hands out strong refs
Q: what is the natural ownership abstraction?

A: shared_ptr

## Dag of hea p objects

A: shared_ptr

## Factory
Q: natural onwership when a factory returns a heap object?

A: unique_ptr or shared_ptr + make_shared