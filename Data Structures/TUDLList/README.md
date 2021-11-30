# TUDLList

My C++ Unbounded Doubly Linked List implementation.

Doubly linked list with no maximum size or random access.

Access to objects within the list is provided by **TUDLListIterator**.

---

Positioning: Objects pushed and pulled from front and back.

Parallelism: None, unsafe.

Memory format: Nonsequential, linear.

---

## Public Methods:

(c): constructor

(d): destructor

(=): assignment operator

---
### TUDLList() *(c)*

Initializes the list.

---
### TUDLList(const TUDLList& other) *(c)*

Initializes the list and copies another list's contents to itself.

parameters:
- other: the TUDLList to copy.

---
### ~TUDLList() *(d)*

Deallocates the memory allocated to the list, if any.

---
### TUDLList& operator=(const TUDLList& other) *(=)*

Copies another list's contents into itself.

parameters:
- other: the TUDLList to copy

---
### void push_back(const type& obj)

Inserts a new object at the back of the list.

parameters:
- obj: the object to be inserted into the list.

---
### void push_front(const type& obj)

Inserts a new object at the front of the list.

parameters:
- obj: the object to be inserted into the list.

---
### type pull_back()

Removes the object at the back of the list. Returns removed object. Throws error if list is empty.

---
### type pull_front()

Removes the object at the front of the list. Returns removed object. Throws error if list is empty.

---
### TUDLListIterator<type>* iterator(const short& start = 0)

Returns a heap-allocated iterator of the list.

TUDLList keeps track of these iterators, so you are not required to delete them manually. TUDLList does not, however, keep track of when iterators become lost due to the nodes they point to being erased. You are encouraged to keep track of those yourself, and call the clear() method on them whenever they become lost. The clear() method will preemptively destroy the iterator and remove it from its master's list of iterators. You do not have to do this though; all iterators obtained from this method will be destroyed upon the destruction of their master TUDLList.

parameters:
- start: whether the iterator should start at the front or back of the list. Starts at back if start is negative. Default is 0, therefore, by default, the iterator starts at the front of the list.

## TUDLListIterator Public Methods:

### bool has_next() const

Returns whether or not the iterator's current node has a node after it.

### type& next()

Sets current node to the node after the current node and returns its value.

### bool has_prev() const

Returns whether or not the iterator's current node has a node before it.

### type& prev()

Sets current node to the node before the current node and returns its value.

### type value() const

Returns the value of the current node.

### void clear()

Removes the iterator from its master's list of iterators, then destroys it. Useful for when the iterator becomes lost.
