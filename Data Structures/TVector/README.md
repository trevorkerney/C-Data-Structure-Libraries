# TVector

My C++ Vector implementation.

Positioning: Objects pushed to back and pulled from back.

Memory format: Sequential.

Maximum capacity (MAX_CAPACITY) of TVector is 65535.

### Searching Algorithms
- linear
- binary

### Sorting Algorithms
- quick (single pivot, found with median of 3)

The use of searching and sorting functions with TVectors of non-[fundamental types](https://www.cplusplus.com/reference/type_traits/is_fundamental/) requires explicit specialization of the private compare() method. The template is as follows:
```
explspec short TVector<myType>::compare(const myType& obj1, const myType& obj2) const
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
This must be implemented after the inclusion of TVector and before the use of any function that uses searching/sorting methods.

Replace all instances of "myType" with the name of the type/class.

*explspec* is a #define that expands to "template<>". You don't have to use it, but I think it improves readability.

## Public Methods:

(c): constructor

(d): destructor

(=): assignment operator

(o): non-assignment operator

(s/s): uses searching and/or sorting

---
### TVector(const unsigned int& initial_size = 0, const unsigned int& growth_multiplier = 2); (c)

Initializes the vector.

parameters:
- initial_size: the memory capacity initally allocated for the list. The default is 0. Throws error if less than 0 or greater than the maximum capacity.
- growth_multiplier: the capacity multiplier used for automatic resizing. The default is 2. (*READ void set_growth_multiplier(float p_multiplier);*).

---
### TVector(const TVector& other); (c)

Initializes the vector and copies another vector's contents to itself.

parameters:
- other: the TVector to copy.

---
### ~TVector(); (d)

Deallocates the memory allocated to the vector, if any.

---
### TVector& operator=(const TVector& p_other); (=)

Copies another vector's contents into itself.

parameters:
- other: the TVector to copy

---
### type& at(const long& index) const;

Returns value at index. Throws error if index is out of range.

parameters:
- index: the index at which the vector is accessed.

---
### type& operator[](const long& index) const; (o)

Returns value at index. Throws error if index is out of range.

parameters:
- index: the index at which the vector is accessed.

---
### unsigned int size() const;

Returns current amount of objects in vector.

---
### void set_growth_multiplier(const float& multiplier);

Sets the value the vector's capacity is multiplied by to obtain the size of the new array to be allocated when automatically resizing.

parameters:
- multiplier: the capacity multiplier of the vector

---
### float growth_multiplier() const;

*READ void set_growth_multiplier(float p_multiplier);*

Returns the growth_multiplier.

---
### unsigned int reserve(const long& amount);

Manually expands the vector's capacity. Returns the amount of new spaces in the vector's capacity. Trying to reserve more than the vector's maximum capacity does not throw an error, but simply reserves the maximum capacity. Any call to reserve when the vector's capacity is at maximum capacity will immediately return 0.

parameters:
- amount: the new capacity of the vector.

---
### unsigned int shrink();

Shrinks the capacity of the vector to the size of the vector.

---
### long find(const type& searched, bool sorted = false, const searchingMethod& searching_method = searchingMethod::binary) const;

Finds and returns the index of the value referred to by searched. If sorted is true, the searching method provided is used. If false, linear search is used.

Use this find() function when the list doesn't need to be sorted beforehand. (i.e. it either already is sorted or doesn't need to be)

parameters:
- searched: the object to find.
- sorted: whether or not the list is sorted. The default is false. Setting this value to true when the list is not sorted will result in an unreliable search.
- searching_method: the searching method to use if the list is sorted. The default is binary search.

---
### long find(const type& searched, const sortingMethod& sorting_method, const searchingMethod& searching_method) const; (s/s)

Sorts the vector, then finds and returns the index of the value referred to by searched.

Use this find() function when you want the list to be sorted beforehand to optimize the search.

parameters:
- searched: the object to find.
- sorting_method: the sorting method to use.
- searching_method: the searching method to use.

---
### bool contains(const type& searched, bool sorted = false, const searchingMethod& searching_method = searchingMethod::binary) const;

Returns whether or not the vector contains the value referred to by searched. If sorted is true, the searching method provided is used. If false, linear search is used.

Essentially:
```
if (find(searched) >= 0)
    return true;
return false;
```

Use this contains() function when the list doesn't need to be sorted beforehand. (i.e. it either already is sorted or doesn't need to be)

parameters:
- searched: the object to find.
- sorted: whether or not the list is sorted. The default is false. Setting this value to true when the list is not sorted will result in an unreliable search.
- searching_method: the searching method to use if the list is sorted. The default is binary search.

---
### bool contains(const type& searched, const sortingMethod& sorting_method, const searchingMethod& searching_method) const; (s/s)

Sorts the vector, then returns whether or not the vector contains the value referred to by searched.

Essentially:
```
if (find(searched, sorting_method, searching_method) >= 0)
    return true;
return false;
```

Use this contains() function when you want the list to be sorted beforehand to optimize the search.

parameters:
- searched: the object to find.
- sorting_method: the sorting method to use.
- searching_method: the searching method to use.

---
### void push(const type& obj);

Inserts a new object at the back of the vector. Throws error if vector is at maximum size.

parameters:
- obj: the object to be inserted into the vector.

---
### void push(const type* objs, const long& size);

Traverses through an array pushing every object into the array.

Essentially:
```
for (obj in objs)
    push(obj);
```

parameters:
- objs: an array of objects.
- size: the size of the array.

---
### type pull();

Removes the object at the back of the vector. Returns removed object. Throws error if vector is empty.

---
### void insert(const type& obj, const long& index);

Inserts a new object at index and shifts further objects once torward the back. Throws error if vector is at maximum size.

parameters:
- obj: the object to be inserted into the vector.
- index: the index at which the obj will be inserted into the vector.

---
### void emplace(const type& obj, bool sorted = false, const searchingMethod& searching_method = searchingMethod::binary)

Inserts a new object at the correct position in the list if it were organized, and shifts further objects once torwards the back.

Essentially:
```
index = find(obj, sorted, searching_method);
if (index < 0)
    index = (index + 1) * -1;
insert(obj, index)
```

Use this emplace() function when the list doesn't need to be sorted beforehand. (i.e. it either already is sorted or doesn't need to be)

parameters:
- obj: the object to find.
- sorted: whether or not the list is sorted. The default is false. Setting this value to true when the list is not sorted will result in an unreliable search.
- searching_method: the searching method to use if the list is sorted. The default is binary search.

---
### void emplace(const type& obj, const sortingMethod& sorting_method, const searchingMethod& searching_method)

Sorts the vector, then inserts a new object at the correct position in the list, and shifts further objects once torwards the back.

Essentially:
```
index = find(obj, sorting_method, searching_method);
if (index < 0)
    index = (index + 1) * -1;
insert(obj, index)
```

Use this emplace() function when you want the list to be sorted beforehand to optimize the search.

parameters:
- obj: the object to find.
- sorting_method: the sorting method to use.
- searching_method: the searching method to use.

---
### type erase(const long& index);

Removes the object at index and shifts further objects once torward the front.

parameters:
- index: the index at which the obj will be erased from the vector.

---
### type extract(const type& searched, bool sorted = false, const searchingMethod& searching_method = searchingMethod::binary);

Finds, removes, and returns the value referred to by searched, and shifts all further elements once torward the front. Throws error if value referred to by searched isn't present in the array. If sorted is true, the searching method provided is used. If false, linear search is used.

Essentially:
```
erase(find(searched));
```

Use this extract() function when the list doesn't need to be sorted beforehand. (i.e. it either already is sorted or doesn't need to be)

parameters:
- searched: the object to find.
- sorted: whether or not the list is sorted. The default is false. Setting this value to true when the list is not sorted will result in an unreliable search.
- searching_method: the searching method to use if the list is sorted. The default is binary search.

---
### type extract(const type& searched, const sortingMethod& sorting_method, const searchingMethod& searching_method); (s/s)

Sorts the vector, then finds, removes, and returns the value referred to by searched, and shifts all further elements once torward the front. Throws error if value referred to by searched isn't present in the array.

Essentially:
```
erase(find(searched, sorting_method, searching_method));
```

Use this extract() function when you want the list to be sorted beforehand to optimize the search.

parameters:
- searched: the object to find.
- sorting_method: the sorting method to use.
- searching_method: the searching method to use.

---
### void sort(const sortingMethod& method = sortingMethod::quick); (s/s)

Sorts the vector using the provided sorting and comparison methods. Throws error if sorting method provided is invalid.

paramters:
- method: the sorting method to use. The default is quick sort.