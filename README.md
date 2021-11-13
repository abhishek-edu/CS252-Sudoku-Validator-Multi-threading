# cs252-assignment-odd-sem2021

*Checking solution of the Sudoku using Multi-Threading* 

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

#  How to Use
  * 1.Download sku.c file on the Linux Machine
  * 2.Open terminal and go to the location where sku.c is saved.
  * 3.To compile the this code we need to type "gcc sku.c -o sku -lpthreads"  and press enter
  * 4.Then It will show the result , whether the solution is Valid Or not for the default sudoku which is entered in the source code.
  * 5.If we want to Validate a particular sudoku then , opn sku.c file and change the values of  board[9][9] to the one which you want to validate
  
  
    
