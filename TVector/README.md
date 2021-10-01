# TVector

My C++ Vector implementation.

Positioning: Objects pushed to back and pulled from back.

Memory format: Sequential.

Maximum capacity (MAX_CAPACITY) of TVector is 65535.

### Sorting Methods
- quick

### Searching Methods
- linear
- binary

---

## Member Functions:
### TVector(const unsigned int& initial_size = 0, const unsigned int& growth_multiplier = 2); (constructor)

Initializes the vector.

parameters:
- initial_size: the memory capacity initally allocated for the list. The default is 0. Throws error if less than 0 or greater than the maximum capacity.
- growth_multiplier: the capacity multiplier used for automatic resizing. The default is 2. (*READ void set_growth_multiplier(float p_multiplier);*).

### TVector(const TVector& other); (copy constructor)

Initializes the vector and copies another vector's contents to itself.

parameters:
- other: the TVector to copy

### ~TVector(); (destructor)

Deallocates the memory allocated to the vector, if any.

### TVector& operator=(const TVector& p_other);

Copies another vector's contents into itself.

parameters:
- other: the TVector to copy

### type& at(const int& index) const;

Returns value at index. Throws error if index is out of range.

parameters:
- index: the index at which the vector is accessed.

### type& operator[](const int& index) const;

Returns value at index. Throws error if index is out of range.

parameters:
- index: the index at which the vector is accessed.

### unsigned int size() const;

Returns current amount of objects in vector.

### void set_growth_multiplier(const float& multiplier);

Sets the value the vector's capacity is multiplied by to obtain the size of the new array to be allocated when automatically resizing.

parameters:
- multiplier: the capacity multiplier of the vector

### float growth_multiplier() const;

*READ void set_growth_multiplier(float p_multiplier);*

Returns the growth_multiplier.

### unsigned int reserve(const int& amount);

Manually expands the vector's capacity. Returns the amount of new spaces in the vector's capacity. Trying to reserve more than the vector's maximum capacity does not throw an error, but simply reserves the maximum capacity. Any call to reserve when the vector's capacity is at maximum capacity will immediately return 0.

parameters:
- amount: the new capacity of the vector.

### unsigned int shrink();

Shrinks the capacity of the vector to the size of the vector.

### void push(const type& obj);

Inserts a new object at the back of the vector. Throws error if vector is at maximum size.

parameters:
- obj: the object to be inserted into the vector.

### void push(const type* objs, const int& size);

Traverses through an array pushing every object into the array.

parameters:
- objs: an array of objects.
- size: the size of the array.

### type pull();

Removes the object at the back of the vector. Returns removed object. Throws error if vector is empty.

### void insert(const type& obj, const int& index);

Inserts a new object at index and shifts further objects once torward the back. Throws error if vector is at maximum size.

parameters:
- obj: the object to be inserted into the vector.
- index: the index at which the obj will be inserted into the vector.

### type erase(const int& index);

Removes the object at index and shifts further objects once torward the front.

parameters:
- index: the index at which the obj will be erased from the vector.

### int find(const type& searched, bool sorted = false, searchingMethod& searching_method = searchingMethod::binary) const;

Finds and returns the value referred to by searched. If sorted is true, the searching method provided is used. If false, linear search is used.

Use this find() function when the list doesn't need to be sorted beforehand. (i.e. it either already is sorted or doesn't need to be)

parameters:
- searched: the object to find.
- sorted: whether or not the list is sorted.
- searching_method: the searching method to use if the list is sorted.

### int find(const type& searched, const sortingMethod& sorting_method, const searchingMethod& searching_method) const;

Sorts the vector, then finds and returns the value referred to by searched.

Use this find() function when you want the list to be sorted beforehand to optimize the search.

parameters:
- searched: the object to find.
- sorting_method: the sorting method to use.
- searching_method: the searching method to use.

### bool contains(const type& searched, bool sorted = false, searchingMethod& searching_method = searchingMethod::binary) const;

Returns whether or not the vector contains the value referred to by searched.

Use this contains() function when the list doesn't need to be sorted beforehand. (i.e. it either already is sorted or doesn't need to be)

parameters:
- searched: the object to find.
- sorted: whether or not the list is sorted.
- searching_method: the searching method to use if the list is sorted..

### bool contains(const type& searched, const sortingMethod& sorting_method, const searchingMethod& searching_method) const;

Returns whether or not the vector contains the value referred to by searched.

Use this contains() function when you want the list to be sorted beforehand to optimize the search.

parameters:
- searched: the object to find.
- sorting_method: the sorting method to use.
- searching_method: the searching method to use.

### void sort(const sortingMethod& method = sortingMethod::quick);

Sorts the vector using the provided sorting and comparison methods. Throws error if sorting method provided is invalid.

paramters:
- method: the sorting method to use
