# push_swap
A sorting algorithm program based in C. 
The project does not allow the math.h library, and only allows for two official "stacks". The project was completed using radix sort and bit shifting to allow for only two "stacks". 
The purpose of this project is to take numbers (Up to 500) with values between INT_MIN and INT_MAX and organize them from smallest to largest. The project was created using /arrays/ vs /linked lists/ because arrays are quicker when ran (though very difficult to implement with memory). 

HOW MY PUSH_SWAP WORKS
1. The program is compiled using a Makefile that checks for -Werror -Wextra -Wall if you want to add another check you can add -g and use a debugger or also add -fsanitize=address...the tester does not work when these are added, so make sure to update the Makefile based on how you want to test. The tester does need Checker_Mac to work. COMPILE with make in the command line.

2. Once the program is made you can run via the command line ./push_swap (vs ./a.out) and the numbers you wish to be sorted. Less than two numbers does not need to be sorted and will simply return.

3. The program will take your input from the command line and check for errors, then index the array. Errors include: duplicate numbers, characters that are not numbers (letters, symbols, etc.) numbers that are smaller than the INT_MIN or larger than the INT_MAX. If there are errors in the command line input the program will return "Error" and end. Once the error checks are completed we will index the input. This is done by changing the strings to individual ints, then finding the smallest integer in the list and changing the value to 1, each iteration of this will change the value one higher, so if the list is 32 -2305834 8 the values will change to 3 1 2. This was a necessary step in order to bitshift properly, as binary numbers handle negative numbers less ideally than we need for this project. This also helps during testing to be able to visualize the index better. The value can never be zero, and we use zero as a terminator to indicate the end of the array(s)/stack(s) by using calloc to fill the array(s)/stack(s) with zeros. Indexing does not change the position of the numbers, as this would be cheating, it only changes the values.

4. The program determines how many numbers there are and decides which sorting method to use. 3 to 5 numbers are hard coded as the radix algorithm is not optomized for the smaller size. (Example: 5 numbers with radix takes 23 "actions" whereas when hard-coded takes a max of 12 "actions". In order to receive credit for 5 numbers we cannot have more than 12 actions.) 

5. Each method is eqipped with the ability to access 11 different "actions". These actions are what the program will do to sort the numbers.
ACTIONS:
sa is swap in stack a, so the number in position 0 and the number in position 1 are swapped. 
sb is swap in stack b, so the number in position 0 and the number in position 1 are swapped. 
ss is swap in stack a and stack b, so the number in position 0 and the number in position 1 are swapped simultaneously. 
ra is rotate in stack a, so the entire stack rotates up one, the first element in position 0 becomes the last number in the final position. 
rb is rotate in stack b, so the entire stack rotates up one, the first element in position 0 becomes the last number in the final position. 
rr is rotate in stack a and stack b, so the entire stack rotates up one, the first element in position 0 becomes the last number in the final position of each stack simultaneously.
rra is reverse rotate in stack a, so the entire stack rotates down one position, the last element becomes the first element in position 0. 
rrb is reverse rotate in stack b, so the entire stack rotates down one position, the last element becomes the first element in position 0.
rrr is reverse rotate in stack a and stack b, so the entire stack rotates down one position, the last element becomes the first element in position 0 simultaneously.
pa is push to a, this happens when there is at least one value in the b stack, which will then be pushed to the 0 position in the a stack. The rest of the a stack will then move down one position to make sure we do not overwrite any values. The values in stack b will all be moved up one location to accomodate losing one value. 
pb is push to b, this happens when there is at least one value in the a stack, which will then be pushed to the 0 position in the b stack. The rest of the a stack will then move down one position to make sure we do not overwrite any values. The values in stack a will all be moved up one location to accomodate losing one value.

Radix sort:
After the program is aware of how many values there are to sort it will select. 6 numbers and above will automatically be sorted using radix. 
Radix is a sorting algorithm that sorts by using the ones position of of a number and sorts it into 10 different stacks.
Example: 300, 75, 76, 1, 23
0: 300
1: 1
2:
3: 23
4:
5: 75
6: 76
8:
9:
The radix sorter will then do this again based on the tens position. Then again in the hundreds position and so on, ending when the largest number has been sorted. The issue with this method is that we are only allowed two stacks. This is when bit shifting comes into play. Bit shifting checks the position you set (for this program I check the ones position each time) and shifts the bit each round. So round one 300 is 300, then the next round 300 is 30, then the third round 300 is 3. Bit shifting also changes the number from decimal (base ten) to binary (base two) base two works perfectly because we have only two stacks. If the bit being checked is 0 it is pushed to b, if it is 1 it stays in a and is rotated if necessary. Each round all numbers that have been pushed to stack b are pushed back to stack a and the program starts over until all the numbers are in order. 
Example: 100101100 (300) 1001011 (75) 1001100 (76) 1 (1) 10111 (23)
(Stack b)0: 100101100 1001100 
(Stack a)1: 1001011 1 10111
This will continue for each bit, so for the number 23 it will check each bit and each round would go as such (1)(1)(1)(0)(1). What if there is a larger number? What will happen? The number will be filled with leading zeros so 300 is the largest and has 9 digits, so it will be bitshifted 9 times, so 23 will be filled with 4 leading 0's this does not change the value, but makes sure to continue to account for number each round.(0)(0)(0)(0)(1)(0)(1)(1)(1)

6. Each time an action is used to sort the values the action will write to the terminal what was used. Once the program has completely sorted the numbers it will return. 

This list will not be readable if you have 500 numbers, as it will be a lot to keep track of, which is why there is a checker, which checks to see if the moves you used in fact would sort the list, and I have uploaded a tester made by a friend that will also check all the values and edge cases. 
