# TArray

This implementation is incomplete.

My C++ Array implementation.

Positioning: None.

Memory format: Sequential.

Maximum size (MAX_SIZE) of TArray is 65535.

---

## Member Functions:
## TVector(const unsigned int& initial_size = 2); (constructor)

Allocates array on the heap.

parameters:
- initial_size: the memory capacity initally allocated for the list. The default is 2. Throws error if less than 0 or greater than MAX_SIZE.

## ~TArray(); (destructor)

Deallocates array.

## type& at(const int& index) const;

Returns value at index. Throws error if index is out of range.

parameters:
- index: the index at which the vector is accessed.

## type& operator[](const int& index) const;

Returns at(index);

parameters:
- index: the index at which the vector is accessed.

## unsigned int size() const;

Returns current amount of objects in vector.

## unsigned int reserve(const int& amount);

Manually expands the vector's capacity. Returns amount of new spaces in vector's capacity. Trying to reserve more than the vector's maximum capacity does not throw an error, but simply reserves the maximum capacity. Any call to reserve when vector's capacity is at maximum size will immediately return 0.

parameters:
- amount: the new capacity of the vector.