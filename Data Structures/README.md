# Data Structures

## TArray
Essentially a basic array with resizing functions.

- Positioning: unmanaged.
- Parallelism: N/A (will be per-index synchronized).
- Memory Format: Sequential.

### Searching Methods
- Linear

### Public Methods
- at - returns value at an index.
- operator[] - returns value at an index.
- capacity - returns the capacity of the array.
- reserve - manually expands the array's capacity.
- find - finds and returns the index of a value.

---
## TVector
Multipurpose sequential array implementation with lots of access methods and optimizations for specialized use.

- Positioning: managed, objects pushed to end and pulled from end.
- Parallelism: N/A (will be synchronized).
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

---
## TBD
- TQueue
- TStack
