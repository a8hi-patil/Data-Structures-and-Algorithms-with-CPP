Heaps
-> Heap is a data structure.
-> A complete binary tree with satisfying the heap property is called heap.

Complete Binary Tree
-> When there is leaf nodes only on last level.
-> Node filling will be contineous. left -> right

Heap Property
->1. Min heap :: min heap val < root-> left and root-> right
->2. Max heap :: max heap val > root-> left and root-> right

Heap is implemented with array using 1 base indexing.
-> If parent index is = i
-> Left child index is = 2*i
-> Right child index is = 2*i +1

To find parent of child = i /2
