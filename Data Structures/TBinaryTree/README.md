# TBinaryTree

version beta-1.0

My C++ Binary Tree implementation.

Binary tree with mostly recursive methods.

Access to objects within the list is provided by **TBinaryTreeIterator**.

---

Positioning: Objects inserted in order and erased by value.

Memory format: Binary tree.

---

The use of TBinaryTree with non-[fundamental types](https://www.cplusplus.com/reference/type_traits/is_fundamental/) (except strings) requires explicit specialization of the private compare() method. The declaration is as follows:
```
explspec short TBinaryTree<myType>::compare(const myType& obj1, const myType& obj2) const
```
The body of this function should return 1 if obj1 is greater than obj2, 0 if equal, and -1 if lesser.

This must be implemented after the inclusion of TBinaryTree and before the use of any of TBinaryTree's methods.

Replace all instances of "myType" with the name of the type/class.

*explspec* is a #define that expands to "template<>". You don't have to use it, but I think it improves readability.

---

## Public Methods:

(c): constructor

(d): destructor

(=): assignment operator

---
### TBinaryTree() *(c)*

Initializes the tree.

---
### TBinaryTree(const TBinaryTree<type>& other) *(c)*

Initializes the tree and copies another tree's contents to itself.

parameters:
- other: the TBinaryTree to copy.

---
### ~TBinaryTree() *(d)*

Deallocates the memory allocated to the tree, if any.

---
### TBinaryTree<type>& operator=(const TBinaryTree<type>& other)

Copies another tree's contents into itself.

parameters:
- other: the TBinaryTree to copy

---
### void insert(const type& obj)

Inserts the object at it's ordered position in the tree. Duplicates are ignored.

parameters:
- obj: the object to be inserted into the tree.

---
### bool erase(const type& obj)

Finds and removes the object. Returns whether or not the object to be erased was in the tree.

parameters:
- obj: the value of the object to be erased from the tree.

---
### bool contains(const type& obj) const

Finds whether or not the tree contains the object.

parameters:
- obj: the value of the searched object

---
### TBinaryTreeIterator<type>* iterator() const

Returns a heap-allocated iterator of the tree.

TBinaryTree keeps track of these iterators, so you are not required to delete them manually. TBinaryTree does not, however, keep track of when iterators become lost due to the nodes they point to being erased. You are encouraged to keep track of those yourself, and call the clear() method on them whenever they become lost. The clear() method will preemptively destroy the iterator and remove it from its master's list of iterators. You do not have to do this though; all iterators obtained from this method will be destroyed upon the destruction of their master TBinaryTree.

## TBinaryTreeIterator Public Methods:

### bool has_lesser() const

Returns whether or not the iterator's current node has a lesser node.

### type& lesser()

Sets the iterator's current node to it's lesser node and returns its value.

### bool has_greater() const

Returns whether or not the iterator's current node has a greater node.

### type& greater()

Sets the iterator's current node to it's greater node and returns its value.

### type value() const

Returns the value of the iterator's current node.

### void clear()

Removes the iterator from its master's list of iterators, then destroys it. Useful for when the iterator becomes lost.
