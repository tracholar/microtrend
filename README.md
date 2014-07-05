# 趋势科技2014编程比赛
## Q012 Prime crossword puzzle in a cell-matrix

## Q013 Proxy log retrospection

## Q016 2048

## Q020 Mirror Mirror

## Q021 President Election of T Republic

## Minimum value
Given a 32-bit integer array, calculate the lowest possible value between 2 integers in 
an array. 
Note that the order of the numbers cannot be changed. Your program must evaluate 
the subtraction equation for any given array from right to left. For example, in the 
third line from example below starting at 98, your program should evaluate the 
following equations:
*  98 - 55
*  98 - 33
*  98 - 1500
*  98 - 700
*  98 - 500
But, your program should not evaluate:
*  98 - 2
*  98 - 5 
*  98 - 34 
*  98 - 24

###Input Format
>20  
>10 20 -30 1 5 7 9 66 -100 101  
>500 700 1500 33 55 98 2 5 34 28  

The first line of the input displays the total number of elements in the array (less than 
300,000). The subsequent lines display the array elements separated by spaces and 
newline characters.

###Output Format
Output the lowest integer value evaluated from the list.

The first line of the input displays the total number of elements in the array (less than 
300,000). The subsequent lines display the array elements separated by spaces and 
newline characters.

###Output Format
Output the lowest integer value evaluated from the list.

###Sample Input/Output
Given the following input:
>20  
>10 20 -30 1 5 7 9 66 -100 101  
>500 700 1500 33 55 98 2 5 34 28  

The output should be:
>  -1498