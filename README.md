# C++ Design Patterns

I'm writing these to gain greater control and knowledge of my code.

All of these fall under the MIT license unless there is a different license within the design pattern's directory.

---
## Data Structures

### TArray
Essentially a basic array with resizing methods.

- Positioning: Unmanaged.
- Parallelism: None, unsafe.
- Memory Format: Sequential.
- Searching: Linear.
- Sorting: None.

### TAVLTree
Self balancing binary tree with recursive methods.

- Positioning: Objects inserted in order and erased by value.
- Parallelism: None, unsafe.
- Memory Format: Tree.
- Searching: Implicitly binary.
- Sorting: Implicitly automatic binary.

### TBinaryTree
Binary tree with recursive methods.

- Positioning: Objects inserted in order and erased by value.
- Parallelism: None, unsafe.
- Memory Format: Tree.
- Searching: Implicitly binary.
- Sorting: Implicitly automatic binary.

### TCombination
Map-like structure offering lightning fast searches and insertions with very large datasets. Quite inefficient with memory usage; by design the combination uses much more memory than the data it holds, which is required to maintain it's search and insertion speed.

- Positioning: Objects inserted and erased by key.
- Parallelism: None, unsafe.
- Memory Format: Tree.
- Searching: Constant.
- Sorting: Unneccessary.

### TUDLList (Unbounded Doubly Linked List)
Doubly linked list with no maximum size or random access.

- Positioning: Managed, objects can be pushed and pulled from front and back.
- Parallelism: None, unsafe.
- Memory Format: Nonsequential, linear.
- Searching: Linear.
- Sorting: None.

Objects can be inserted and erased from within the list using **TUDLListIterator**.

### TVector
Multipurpose sequential array with lots of access methods and optimizations for specialized use.

- Positioning: Managed, objects pushed to end and pulled from end.
- Parallelism: None, unsafe.
- Memory Format: Sequential.
- Searching: Linear, Binary.
- Sorting: Quick.
