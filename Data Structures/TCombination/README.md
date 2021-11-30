# TCombination

A new (to me) way of using trees to implement a map-like data structure where searches and insertions are always O(l), where l is the length of the key.

This data structure, by design, uses quite a bit more memory than the data it holds uses, making it very inefficient for small datasets where other search methods would be plenty fast. As far as I'm aware, this extra memory usage is required to maintain the speed of searches and insertions.

Deletions are typically very expensive. The only case I'm aware of where they aren't expensive, is when you delete a key that is the beginning of a longer key. For example, if you delete the key "cat", when "catwalk" is also a key in the combination, the deletion will be just as fast as a search or insertion.

---

Positioning: Objects inserted and erased by key.

Parallelism: None, unsafe.

Memory format: Tree.

---

## Public Methods:

(c): constructor

(d): destructor

(=): assignment operator

---
### TCombination() *(c)*

Initializes the combination.

---
### TCombination(const TCombination<type>& other) *(c)*

Initializes the combination and copies another combination's contents to itself.

parameters:
- other: the TCombination to copy.

---
### ~TCombination() *(d)*

Deallocates the memory allocated to the combination, if any.

---
### TCombination<type>& operator=(const TCombination<type>& other) *(=)*

Copies another combination's contents into itself.

parameters:
- other: the TCombination to copy

---
### void insert(const string key, const type value)

Inserts an object into the combination behind the specified key.

parameters:
- key: the string used to locate the value
- value: the object to be inserted

---
### void erase(const string key)

Erases the object held by the specified key.

Throws error if key is not in combination.

parameters:
- key: the string used to locate the value.

---
### type& get(const string key)

Returns a reference to the value held by the specified key.

parameters:
- key: the string used to locate the value

---
### bool contains_key(const string key) const

Returns whether or not the combination contains the specified key.

parameters:
- key: the key in question

---
### bool is_empty() const

Returns whether or not the combination has at least 1 key in it.

---
### void print_keys_inorder()

Prints all keys in the combination in alphabetical order.

Longer keys print first. i.e. "catwalk" would be printed before "cat".

---
### void print_keys_preorder()

Prints all keys in the combination in alphabetical order.

Shorter keys print first. i.e. "cat" would be printed before "catwalk".
