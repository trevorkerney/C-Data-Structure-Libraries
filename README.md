# C++ Design Patterns

I'm writing these to gain greater control and knowledge of my code.

All of these fall under the MIT license unless there is a different license within the design pattern's directory.

---
## Data Structures

### TArray
Essentially a basic array with resizing functions.

- Positioning: unmanaged.
- Parallelism: N/A
- Memory Format: Sequential.
- Searching: Linear.
- Sorting: None.

### TBinaryTree
Binary tree with mostly recursive methods.

- Positioning: Objects inserted in order and erased by value.
- Parallelism: N/A
- Memory Format: Binary tree.
- Searching: Implicitly binary.
- Sorting: Implicitly automatic binary.

### TUDLList (Unbounded Doubly Linked List)
Doubly linked list with no maximum size or random access.

- Positioning: managed, objects can be pushed and pulled from front and back.
- Parallelism: N/A
- Memory Format: Nonsequential, linear.
- Searching: Linear.
- Sorting: None

Objects can be inserted and erased from within the list using **TUDLListIterator**.

### TVector
Multipurpose sequential array with lots of access methods and optimizations for specialized use.

- Positioning: managed, objects pushed to end and pulled from end.
- Parallelism: N/A
- Memory Format: Sequential.
- Searching: Linear, Binary.
- Sorting: Quick.
