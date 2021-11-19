# TBinaryTree

My C++ Binary Tree implementation.

Binary tree with mostly recursive methods.

---

Positioning: Objects inserted in order and erased by value.

Parallelism: N/A

Memory format: Binary tree.

---

The use of TBinaryTree with non-[fundamental types](https://www.cplusplus.com/reference/type_traits/is_fundamental/) (except strings) requires explicit specialization of the private compare() method. The declaration is as follows:
```
explspec short TBinaryTree<myType>::compare(const myType& obj1, const myType& obj2) const
```
The body of this method should return 1 if obj1 is greater than obj2, 0 if equal, and -1 if lesser.

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
