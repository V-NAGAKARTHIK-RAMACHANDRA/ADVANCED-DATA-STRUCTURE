# ADVANCED-DATA-STRUCTURE
.Linear Probing: Checks next available slot sequentially  
. Quadratic Probing: Uses 𝑖 jumps to reduce clustering  
. Double Hashing: Uses a second hash function for step size 
. Separate Chaining: Uses linked lists at each index


 1. Linear Probing 
When a collision occurs (two keys map to the same index), the algorithm checks the next slot sequentially (index + 1, index + 2, …) until it finds an empty position.

Pros:
Simple to implement.
Efficient for low load factors.

Cons:
Causes primary clustering (long runs of occupied slots), which slows down future insertions and searches.

 2. Quadratic Probing
Instead of checking slots one by one, it uses quadratic jumps:
newIndex = (ℎ(𝑘) + 𝑖2) % SIZE
where 𝑖 = 1,2,3,… .

Pros:
Reduces clustering compared to linear probing.
Distributes keys more evenly.

Cons:
May still suffer from secondary clustering (keys with same initial hash follow the same probe sequence).
Requires careful choice of table size to ensure all slots are reachable.

 3. Double Hashing
Uses a second hash function to calculate the step size for probing:
newIndex = (h1(k) + i . h2(k)) % SIZE
where ℎ1 is the primary hash and ℎ2 is the secondary hash.

Pros:
Minimizes clustering (both primary and secondary).
Provides better distribution of keys.

Cons:
Slightly more complex (requires two hash functions).
Must ensure ℎ2(𝑘) never evaluates to 0.

 4. Separate Chaining
Each index of the hash table stores a linked list (or dynamic structure). If multiple keys hash to the same index, they are stored in that list.

Pros:
Simple and flexible.
No clustering issues.
Table can handle more elements than its size.

Cons:
Requires extra memory for pointers.
Search time depends on the length of chains (can degrade if many collisions occur).
