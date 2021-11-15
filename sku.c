/* Chapter 4 , Project-1 Assignment of Book Operating System by Silberschatz 

  Thanks @ https://github.com/SLynne/CSc4320_OperatingSystems/blob/master/Assignment_2_SourceCode.c for the reference
  
   
*/


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


int board[9][9]= 
{ 
        {6, 2, 4, 5, 3, 9, 1, 8, 7}, 
        {5 , 1, 9, 7, 2, 8, 6, 3, 4}, 
        {8, 3, 7, 6, 1, 4, 2, 9, 5}, 
        {1, 4, 3, 8, 6, 5 , 7, 2, 9}, 
        {9, 5, 8, 2, 4, 7, 3, 6, 1}, 
        {7, 6, 2, 3, 9, 1, 4, 5, 8}, 
        {3 , 7, 1, 9, 5, 6, 8, 4, 2},
        {4, 9, 6, 1, 8, 2, 5, 7, 3}, 
        {2, 8, 5, 4, 7, 3, 9, 1, 6} 
}; 
//The sudoku problem  is imported into this board
/* We will need to declare an array of integer values that is visible to each thread. The value in the array (0 or 1) indicates whether the worker thread's number is valid (see "Returning Results to the Parent Thread" in the textbook's project description) */
int valid[11]; //When the threads are joined, if that thread is a valid part of a sudoku puzzle, it returns 1 to valid[], else it returns 0
int subgridCt = 2; //used to track through valid array sections for the 3x3 subgrids


/* We will need a structure to store the information to be passed to each thread (see "Passing Parameters to Each Thread" in the textbook's project description)*/
typedef struct
{
    
    int row;
    int column;
    
}parameters;

//declare the threads
pthread_t col_thread, row_thread, first_thread, second_thread, third_thread, fourth_thread, fifth_thread, sixth_thread, seventh_thread, eighth_thread, ninth_thread;

/* Declare the thread that checks columns, rows and 3x3 subgrids */
void *column_worker(void *param); 	
void *row_worker(void *param);
void *square_worker(void *param);


int main()
{
   
     
   
        /*We need to assign values to the structure variable. Then We can create multiple worker threads by passing the information using the structure variable*/
        parameters *checkRows = (parameters *) malloc(sizeof(parameters));
        checkRows->row = 0;
        checkRows->column = 0;
       
        parameters *checkCols = (parameters *) malloc(sizeof(parameters));
        checkCols->row = 0;
        checkCols->column = 0;
       
        parameters *first3by3 = (parameters *) malloc(sizeof(parameters));
        first3by3->row = 0;
        first3by3->column = 0;
        
        parameters *second3by3 = (parameters *) malloc(sizeof(parameters));
        second3by3->row = 0;
        second3by3->column = 3;
     
        parameters *third3by3 = (parameters *) malloc(sizeof(parameters));
        third3by3->row = 0;
        third3by3->column = 6;
      
        parameters *fourth3by3 = (parameters *) malloc(sizeof(parameters));
        fourth3by3->row = 3;
        fourth3by3->column = 0;
       
        parameters *fifth3by3 = (parameters *) malloc(sizeof(parameters));
        fifth3by3->row = 3;
        fifth3by3->column = 3;
       
        parameters *sixth3by3 = (parameters *) malloc(sizeof(parameters));
        sixth3by3->row = 3;
        sixth3by3->column = 6;
       
        parameters *seventh3by3 = (parameters *) malloc(sizeof(parameters));
        seventh3by3->row = 6;
        seventh3by3->column = 0;
    
        parameters *eighth3by3 = (parameters *) malloc(sizeof(parameters));
        eighth3by3->row = 6;
        eighth3by3->column = 3;
      
        parameters *ninth3by3 = (parameters *) malloc(sizeof(parameters));
        ninth3by3->row = 6;
        ninth3by3->column = 6;
        
        
        //return values? this is used for pthread join
        void * rows;
        void * cols;
        void * first_square;
        void * second_square;
        void * third_square;
        void * fourth_square;
        void * fifth_square;
        void * sixth_square;
        void * seventh_square;
        void * eighth_square;
        void * ninth_square;
        
        
        //create the pthreads(pthread_t, pthread_attr (NULL), pthread function, copy of struct for pthread)
        pthread_create(&col_thread, NULL, column_worker, (void *) checkCols);
        pthread_create(&row_thread, NULL, row_worker, (void *) checkRows);
        pthread_create(&first_thread, NULL, square_worker, (void *) first3by3);
        pthread_create(&second_thread, NULL, square_worker, (void *) second3by3);
        pthread_create(&third_thread, NULL, square_worker, (void *) third3by3);
        pthread_create(&fourth_thread, NULL, square_worker, (void *) fourth3by3);
        pthread_create(&fifth_thread, NULL, square_worker, (void *) fifth3by3);
        pthread_create(&sixth_thread, NULL, square_worker, (void *) sixth3by3);
        pthread_create(&seventh_thread, NULL, square_worker, (void *) seventh3by3);
        pthread_create(&eighth_thread, NULL, square_worker, (void *) eighth3by3);
        pthread_create(&ninth_thread, NULL, square_worker, (void *) ninth3by3);
     
        

	/*We need to call pthread_join() for each children thread so that the parent will wait*/
	pthread_join(col_thread, &cols);
        pthread_join(row_thread, &rows);
        pthread_join(first_thread, &first_square);
        pthread_join(second_thread, &second_square);
        pthread_join(third_thread, &third_square);
        pthread_join(fourth_thread, &fourth_square);
        pthread_join(fifth_thread, &fifth_square);
        pthread_join(sixth_thread, &sixth_square);
        pthread_join(seventh_thread, &seventh_square);
        pthread_join(eighth_thread, &eighth_square);
        pthread_join(ninth_thread, &ninth_square);
        
	
        /* Finally, after all children returns, you can check the status array that is visible to everyone and see if it is valid. You then print out the final checking result*/
	int k=0;
    while(k < 11)
    {
	
            /*if the thread is valid (contains all numbers 1-9) then the value of valid[k] will be 1, continue to check all elements of valid until 
             either the array ends (k = 11) or the value of valid[k] is 0. If the loop terminates on its own (k = 11), then print the "is Solved" statement and 
             * exit the program. If the value is 0 then there is a thread that did was not a valid part of a sudoku puzzle and the whole puzzle is invalid. Print 
             * the "NOT Solved" statement and end the program.
             */
            
            if(valid[k] == 1)
	    {               
		k++;
            }
            else
	    {
                printf("The Sudoku Puzzle is NOT solved. \n");
                exit(0);
            }
            
     }
        printf("The Sudoku Puzzle is solved. \n");
	

	return 0;
}




/*thread code for child checking all columns*/

void *column_worker(void *params)
{
    int i, j; 
    
    parameters * c_worker = (parameters *) params;
    int beginCol = c_worker->column;
    int beginRow = c_worker->row;

    /*sorting sudoku column; this will put the column into a sorted order and check for duplicates
      if there are duplicates, this section is not valid and returns 0 for the column_worker;*/
    
    for(i = beginCol; i < 9; i++)
    {
     
	int col[9]= {0}; //array to hold sorted column
        
        for(j = beginRow; j < 9; j++)
	{
            
            int val = board[i][j]; //this specific value in the column
            
            /*if the coresponding array element for the value is 0, it has not been seen and 
		we will input this value to the sorted column array. */
            
	    if(col[val-1] == 0 && val > 0)
	    {
               col[val-1] = val;
		
            }
		/*if the value is not 0, then the value is a duplicate and the sudoku puzzle
		  is not solved or valid so the value of column_worker in valid is 0; */
            else{
		valid[0] = 0;
                pthread_exit(0);
            }
         }
    }   
    valid[0] = 1;
    pthread_exit(0);	       
}


/*thread code for child checking all rows*/
void *row_worker(void *params)
{

    int i, j; 
    
    parameters * r_worker = (parameters *) params;
    int beginCol = r_worker->column;
    int beginRow = r_worker->row;
    
    /*sorting sudoku row; this will put the row into a sorted order and check for duplicates
      if there are duplicates, this section is not valid and returns 0 for the row_worker;*/
    
    for(i = beginCol; i < 9; i++)
    {
        
        int row[9]= {0};//array to hold sorted row
        
        for(j = beginRow; j < 9; j++)
	{
            
            int val = board[i][j];
            
            /*if the corresponding array element for the value is 0, it has not been seen and 
		we will input this value to the sorted column array. */
            
            if(row[val-1] == 0 && val > 0)
	    {
                row[val-1] = val;
            }
            
            /*if the value is not 0, then the value is a duplicate and the sudoku puzzle
		  is not solved or valid so the value of column_worker in valid is 0. */
            
            else{
                valid[1] = 0;
		pthread_exit(0);
            }
        }
    }        
    valid[1] = 1;
    pthread_exit(0);
}


/*thread code for child checking all 3x3 subgrids*/
void *square_worker(void *params)
{
	
    int i, j;

    parameters * worker = (parameters *) params;
    int beginRow = worker->row;
    int beginCol = worker->column;
    
    /*sorting sudoku subgrids; this will put the 3x3 subgrid, as determined by the beginRow and beginCol parameters
      into a sorted order and check for duplicates. if there are duplicates, this section is not valid and returns 0 for the square_worker;*/
	
    int square[9] = {0}; //1d array to hold sorted 3x3 square

    for (i = beginRow; i < beginRow + 3; ++i) 
    {
        for (j = beginCol; j < beginCol + 3; ++j) 
	{
            
            int val = board[i][j];
            
            /*if the corresponding array element for the value is 0, it has not been seen and 
		we will input this value to the sorted column array. */
	   
            if (square[val-1] == 0 && val > 0) 
	    {
                square[val-1] = val;
            }
            
            /*if the value is not 0, then the value is a duplicate and the sudoku puzzle
		  is not solved or valid so the value of square_worker in valid is 0. */
            
            else{
                valid[subgridCt] = 0;
		subgridCt++;
		pthread_exit(0);
            }
        }
    }	
    valid[subgridCt] = 1;
    subgridCt++;
    pthread_exit(0);
}
