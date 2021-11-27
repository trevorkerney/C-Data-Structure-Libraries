# TCombination

A new (to me) way of using trees to implement a map-like data structure where searches and insertions are always O(l), where l is the length of the key; this is why I say searching is linear, despite linear time complexity typically being a worst-case scenario.

This data structure, by design, uses quite a bit more memory than the data it holds uses, making it very inefficient for small datasets where other search methods would be plenty fast. As far as I'm aware, this extra memory usage is required to maintain the speed of searches and insertions.

Deletions are typically very expensive. The only case I'm aware of where they aren't expensive, is when you delete a key that is the beginning of a longer key. For example, if you delete the key "cat", when "catwalk" is also a key in the combination, the deletion will be just as fast as a search or insertion.

to be continued...