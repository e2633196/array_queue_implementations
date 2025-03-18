# array_implementations
Implementations on an integer array like a queue

Implementing a queue using dynamically allocated arrays in C, where -1 serves as a sentinel value marking the end. The key functions include:

Printing the queue (print_integer_array): Displays and prints elements separated by commas, stopping at -1.
Enqueue operation (enqueue): Adds a new value at the end of the queue, reallocating memory and maintaining -1 at the end.
Dequeue operation (dequeue): Removes and returns the front element, shifts remaining elements, and resizes memory.
Accessing the front (front): Returns the front element without removing it.
Merging two queues (merge_queues): Combines two sorted queues into a single sorted queue, maintaining duplicates and appending -1 at the end.
Memory management is crucial, requiring careful use of malloc() and realloc(), and I tried to implement a queue by using them
