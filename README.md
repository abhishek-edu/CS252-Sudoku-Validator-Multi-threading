# cs252-assignment-odd-sem2021

*Checking solution of the Sudoku using Multi-Threading* 
# Disclaimer
* This Problem is taken From the 10th edition Book of "Operating System Concepts"  by Avi Silberschatz ,Peter Baer Galvin and Greg Gagne .
* Project 1 of Chapter no. 4
* Taken help from source code found @ https://github.com/SLynne/CSc4320_OperatingSystems/blob/master/Assignment_2_SourceCode.c

   # Project 1 — Sudoku Solution Validator
A Sudoku puzzle uses a 9 × 9 grid in which each column and row, as well as
each of the nine 3 × 3 subgrids, must contain all of the digits 1 ⋅ ⋅ ⋅ 9. Figure
4.26 presents an example of a valid Sudoku puzzle. This project consists of
designing a multithreaded application that determines whether the solution
to a Sudoku puzzle is valid.
There are several different ways of multithreading this application. One
suggested strategy is to create threads that check the following criteria:

   * A thread to check that each column contains the digits 1 through 9
   * A thread to check that each row contains the digits 1 through 9
   * Nine threads to check that each of the 3 × 3 subgrids contains the digits 1 through 9


![image](https://user-images.githubusercontent.com/93817723/141765559-0d4a48e3-9845-488c-a8b2-7abf8a2bfc86.png)


#  How to Use
  * Download sku.c file on the Linux Machine
  * Open terminal and go to the location where sku.c is saved.
  * To compile the this code we need to type "gcc -lpthread"  and press enter
  * type "./a.out" and press enter
  * Then It will show the result , whether the solution is Valid Or not for the default sudoku which is entered in the source code.
  * If we want to Validate a particular sudoku then , opn sku.c file and change the values of  board[9][9] to the one which you want to validate
  
  
    
