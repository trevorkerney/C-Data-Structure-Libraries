# TArray

My C++ Array implementation.

Essentially a basic array with resizing methods.

---

Positioning: None.

Memory format: Sequential.

Maximum capacity (MAX_CAPACITY) of TArray is 65535.

---

### Searching Algorithms
- linear

The use of find() with non-[fundamental types](https://www.cplusplus.com/reference/type_traits/is_fundamental/) requires explicit specialization of the private compare() method. The template is as follows:
```
explspec short TArray<myType>::compare(const myType& obj1, const myType& obj2) const
{
    int comparison =    /* DO COMPARISON HERE */;

                /* COMPARISON SHOULD BE POSITIVE IF obj1 IS LARGER */
    
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
```
This must be implemented after the inclusion of TVector and before the use of any method that uses searching/sorting methods.

Replace all instances of "myType" with the name of the type/class.

*explspec* is a #define that expands to "template<>". You don't have to use it, but I think it improves readability.

---

## Public Methods:

(c): constructor

(d): destructor

(=): assignment operator

(o): non-assignment operator

---
### TArray(int p_initial_capacity = 0); (c)

Initializes the array.

parameters:
- initial_size: the memory capacity initally allocated for the list. The default is 0. Throws error if less than 0 or greater than the maximum capacity.

---
### TArray(const TArray& p_other); (c)

Initializes the array and copies another array's contents to itself.

parameters:
- other: the TArray to copy.

---
### ~TArray(); (d)

Deallocates the memory allocated to the array, if any.

---
### TArray& operator=(const TArray& p_other); (=)

Copies another array's contents into itself.

parameters:
- other: the TArray to copy

---
### type& at(const long& index) const;

Returns value at index. Throws error if index is out of range.

parameters:
- index: the index at which the array is accessed.

---
### type& operator[](const long& index) const; (o)

Returns value at index. Throws error if index is out of range.

parameters:
- index: the index at which the array is accessed.

---
### int capacity() const;

Returns the capacity of the array.

---
### unsigned int reserve(const long& amount);

Manually expands the array's capacity. Returns the amount of new spaces in the array's capacity. Trying to reserve more than the array's maximum capacity does not throw an error, but simply reserves the maximum capacity. Any call to reserve when the array's capacity is at maximum capacity will immediately return 0.

parameters:
- amount: the new capacity of the array.

---
### long find(const type& searched) const;

Finds and returns the value referred to by searched.

parameters:
- searched: the object to find.
