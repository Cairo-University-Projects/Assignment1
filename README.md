# Introduction
In this project we have made the dynamic array and linked list from scratch.

# Index 
1. We will start with [how to run the program](#How-to-run-the-program)
2. Then we wil move to [How does it work](#How-does-it-work)
3. After that [Which is better](#Which-is-better) where we will do some comparisons.
4. We will end with [Resources](#Resources)


## How to run the program
Click on the student.exe file after compilation

## How does it work
Once you start the program the cmd will ask you to choose between dynamic array or linked list to use.

If you choose dynamic array -pressed 2- it will ask you to enter number of students


![start](screenshots/start.gif)

If you choose linked list -pressed 1- it will ask you to enter number of students

![start](screenshots/start2.gif)



## Which is better
 * Insertion at the beginning, if the array is not empty the linked list will be the winner as it is O(1) while the dynamic array is O(n).
 * Insertion at the end, both will be the same if linked list is at the end as it will be O(1) and the array will insert at last position array[size] if the dynamic array's capacity is still greater than the size. However, if the linked list was at the beginning it will be O(n), and if the size==capacity then the array will be       O(n). So, here it will depend.
 * Insertion at the middle, it will depend on how many elements after that position but almost linked list will be the winner as it always at inserting O(1) but dynamic array needs to shift all the element after that position.

## Resources
 - [Geeks for Geeks](https://www.geeksforgeeks.org)
 - [Tutorialspoint](https://www.tutorialspoint.com/index.htm)
 - [Blackboard](http://cu.blackboard.com)

