# C++ Design Patterns

<a href="https://scan.coverity.com/projects/trevorkerney-cpp-design-patterns">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/23919/badge.svg"/>
</a>

---

I'm writing these to gain greater control and knowledge of my code.

All of these fall under the MIT license unless there is a different license within the design pattern's directory.

---
## Data Structures

### TArray
Essentially a basic array with resizing functions.

- Positioning: unmanaged.
- Parallelism: N/A (will be synchronized per-index).
- Memory Format: Sequential.
- Searching: Linear.
- Sorting: None.

### TUDLList (Unbounded Doubly Linked List)
Doubly linked list with no maximum size or random access.

- Positioning: managed, objects can be pushed and pulled from front and back.
- Parallelism: N/A (will be synchronized per-node).
- Memory Format: Nonsequential, linear.
- Searching: Linear.
- Sorting: None (possibly coming).

Objects can be inserted and erased from within the list using **TUDLListIterator**.

### TVector
Multipurpose sequential array with lots of access methods and optimizations for specialized use.

- Positioning: managed, objects pushed to end and pulled from end.
- Parallelism: N/A (will be synchronized).
- Memory Format: Sequential.
- Searching: Linear, Binary.
- Sorting: Quick.

### TBD
- Queue
- Stack

---
## Monitoring

### TBD
- State Machine
- Subject/Observer
