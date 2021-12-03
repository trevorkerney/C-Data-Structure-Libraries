# Data Structures

## TArray
Essentially a basic array with resizing methods.

- Positioning: unmanaged.
- Parallelism: None, unsafe.
- Memory Format: Sequential.

### Searching Methods
- Linear

### Public Methods
- at - returns value at an index.
- operator[] - returns value at an index.
- capacity - returns the capacity of the array.
- reserve - expands the array's capacity.
- find - finds and returns the index of a value.

---
## TAVLTree
Self balancing binary tree with recursive methods.

- Positioning: Objects inserted in order and erased by value.
- Parallelism: None, unsafe.
- Memory format: Tree.

### Public Methods
- insert - inserts an object into its ordered position in the tree.
- erase - erases an object from the tree.
- contains - returns whether or not the object is in the tree.

---
## TBinaryTree
Binary tree with recursive methods.

- Positioning: Objects inserted in order and erased by value.
- Parallelism: None, unsafe.
- Memory format: Tree.

### Public Methods
- insert - inserts an object into its ordered position in the tree.
- erase - erases an object from the tree.
- contains - returns whether or not the object is in the tree.

---
## STrie
Sequential trie with recursive methods. Quite inefficient with memory usage; by design the combination uses much more memory than the data it holds, which is required to maintain true constant time complexity with searches and insertions.

- Positioning: Objects inserted and erased by key.
- Parallelism: None, unsafe.
- Memory Format: Tree.

### Public Methods
- insert - inserts a value into the combination.
- erase - removes a value from the combination.
- get - returns a reference to a specified value in the combination.
- contains_key - returns where or not a specified key is in the combination.
- is_empty - returns whether or not the combination is empty.
- print_keys_inorder - prints keys in alphabetical order. Longer keys print first.
- print_keys_preorder - prints keys in alphabetical order. Shorter keys print first.

---
## TUDLList
Doubly linked list with no maximum size or random access.

- Positioning: managed, objects pushed and pulled from front and back.
- Parallelism: None, unsafe.
- Memory Format: Nonsequential, linear.

### Searching Methods
- Linear

### Public Methods
- push_back - inserts a new object at the back of the list.
- push_front - inserts a new object at the front of the list.
- pull_back - removes the object at the back of the list and returns it.
- pull_front - removes the object at the front of the list and returns it.
- iterator - returns an iterator for the list.

### TUDLListIterator Public Methods:
- has_next - returns whether or not the iterator's current node has a node after it.
- next - sets iterator's current node to the node after current node and returns its value.
- has_prev - returns whether or not the iterator's current node has a node before it.
- prev - sets iterator's current node to the node before current node and returns its value.
- value - returns value of the iterator's current node.
- clear - removes the iterator from its master's iterator list and destroys itself.

---
## TVector
Multipurpose sequential array implementation with lots of access methods and optimizations for specialized use.

- Positioning: managed, objects pushed to end and pulled from end.
- Parallelism: None, unsafe.
- Memory Format: Sequential.

### Searching Methods
- Linear
- Binary

### Sorting Methods
- Quick

### Public Methods
- at - returns value at an index.
- operator[] - returns value at an index.
- size - returns current amount of objects in vector.
- set_growth_multiplier - sets the growth multiplier.
- growth_multiplier - returns the growth_multiplier.
- reserve - manually expands the vector's capacity.
- shrink - shrinks the capacity of the vector to the size of the vector.
- find - finds and returns the index of a value.
- contains - returns whether or not the vector contains a value.
- push - inserts a new object at the back of the vector.
- pull - removes the object at the back of the vector and returns it.
- insert - inserts a new object at an index and shifts further objects once torward the back.
- emplace - inserts a new object at the correct position in the list if it were organized, and shifts further objects once torwards the back.
- erase - removes the object at an index and shifts further objects once torward the front.
- extract - finds, removes, and returns a value, and shifts all further elements once torward the front.
- sort - sorts the vector.
