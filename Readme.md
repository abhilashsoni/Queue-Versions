This small program implements a Version-Queue data structure. 
A Version-Queue maintains a version number along with normal Queue functionality. 
Every operation[Enqueue/Dequeue] on the Queue increments its version.

//// ******* Instructions *********

To compile run:
	g++ -std=c++11 -o queue.out queue.cpp

queue.out will be made from compilation.
Execute queue.out using ./queue.out
Instructions for enqueue, deque and print will be shown.
Enter the operations type and data accordingly


//// ****** Code Working ***********

I maintain a linked list (queue) for all the elements which have come so far. There are two pointers head and tail which tell us the current status of queue (where it is starting and ending). only insertions happen in list, no deletion. When there is a deletion, the head is changed to point it's next element. Each operation, be it deletion or insertion will create a new version. To maintain these versions, I am using a hashtable, which will store head and tail corresponding to a queue's version. Insertion will take O(1) time, deletion O(1), and printing a particular version O(k), where k is the size of queue at that version.