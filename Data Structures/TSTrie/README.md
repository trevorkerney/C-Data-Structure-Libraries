# TSTrie (Sequential Trie)

Sequential trie with recursive methods.

This data structure, by design, uses quite a bit more memory than the data it holds uses, making it very inefficient for small datasets where other search methods would be plenty fast. This extra memory usage is required to maintain true constant time complexity of searches and insertions.

Deletions are typically very expensive. The only case I'm aware of where they aren't expensive, is when you delete a key that is the beginning of a longer key. For example, if you delete the key "cat", when "catwalk" is also a key in the trie, the deletion will be just as fast as a search or insertion.

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
### TSTrie() *(c)*

Initializes the trie.

---
### TSTrie(const TSTrie<type>& other) *(c)*

Initializes the trie and copies another trie's contents to itself.

parameters:
- other: the TSTrie to copy.

---
### ~TSTrie() *(d)*

Deallocates the memory allocated to the trie, if any.

---
### TSTrie<type>& operator=(const TSTrie<type>& other) *(=)*

Copies another trie's contents into itself.

parameters:
- other: the TSTrie to copy

---
### void insert(const string key, const type value)

Inserts an object into the trie behind the specified key.

parameters:
- key: the string used to locate the value
- value: the object to be inserted

---
### void erase(const string key)

Erases the object held by the specified key.

Throws error if key is not in trie.

parameters:
- key: the string used to locate the value.

---
### type& get(const string key)

Returns a reference to the value held by the specified key.

parameters:
- key: the string used to locate the value

---
### bool contains_key(const string key) const

Returns whether or not the trie contains the specified key.

parameters:
- key: the key in question

---
### bool is_empty() const

Returns whether or not the trie has at least 1 key in it.

---
### void print_keys_inorder()

Prints all keys in the trie in alphabetical order.

Longer keys print first. i.e. "catwalk" would be printed before "cat".

---
### void print_keys_preorder()

Prints all keys in the trie in alphabetical order.

Shorter keys print first. i.e. "cat" would be printed before "catwalk".
