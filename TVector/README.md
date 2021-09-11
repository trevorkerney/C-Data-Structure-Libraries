# TVector

My C++ Vector implementation.

Positioning: Objects pushed to end and pulled from end.

Memory format: Sequential.

Maximum size (MAX_SIZE) of TVector is 65535.

---

## Member Functions:
### TVector(const unsigned int& initial_size = 2, const unsigned int& growth_multiplier = 2); (constructor)

Allocates vector on the heap.

parameters:
- initial_size: the memory capacity initally allocated for the list. The default is 2. Throws error if less than 2 or greater than MAX_SIZE.
- growth_multiplier: the capacity multiplier used for automatic resizing. The default is 2. (*READ void set_growth_multiplier(float p_multiplier);*).

### ~TVector(); (destructor)

Deallocates vector.

### type& at(const int& index) const;

Returns value at index. Throws error if index is out of range.

parameters:
- index: the index at which the vector is accessed.

### type& operator[](const int& index) const;

Returns at(index);

parameters:
- index: the index at which the vector is accessed.

### unsigned int size() const;

Returns current amount of objects in vector.

### void set_growth_multiplier(float multiplier);

Sets the value the vector's capacity is multiplied by to obtain the size of the new array to be allocated when automatically resizing.

### float growth_multiplier(float multiplier) const;

*read void set_growth_multiplier(float p_multiplier);*

Returns the growth_multiplier.

### unsigned int reserve(const int& amount);

Manually expands the vector's capacity. Returns amount of new spaces in vector's capacity. Trying to reserve more than the vector's maximum capacity does not throw an error, but simply reserves the maximum capacity. Any call to reserve when vector's capacity is at maximum size will immediately return 0.

parameters:
- amount: the new capacity of the vector.

### unsigned int shrink();

Shrinks the capacity of the vector to the size of the vector.

### void push(const type& obj);

Inserts a new object at the end of the vector. Throws error if vector is at maximum size.

parameters:
- obj: the object to be inserted into the vector.

### void push(const type* objs, const int& size);

Traverses through an array calling push(obj) on every object in the array.

parameters:
- objs: an array of objects.
- size: the size of the array.

### type pull();

Removes the object at the end of the vector. Returns removed object. Throws error if vector is empty.

### void insert(const type obj, const int& index);

Inserts a new object at index and shifts further objects once torward the end. Throws error if vector is at maximum size.

parameters:
- obj: the object to be inserted into the vector.
- index: the index at which the obj will be inserted into the vector.

### type erase(const int& index);

Removes the object at index and shifts further object once torward the front.

parameters:
- index: the index at which the obj will be erased from the vector.