/*
  
 * Sudoku Solution Validator using multithreading 
 Thanks @github.com/crvargasm , i have taken help from the repo.
*/ 

/* Libraries */ 
#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

int sudoku [9] [9] = { 
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

bool verification[11]; // Fix for verification of threads finished with success (1) or failure (0) 
int auxSquares = 2; // used to validate the threads that go through the 3x3 squares 

typedef struct {// It helps us to pass the data to the thread 
    int row; 
    int column; 
} parameter; 

/* START WIRE DECLARATION */ 
pthread_t columns, row, first_frame, second_frame, third_frame, 
        fourth_frame, fifth_frame, sixth_frame, seventh_frame, eighth_frame, ninth_frame; 
/* FINAL THREADS DECLARATION */ 

/* we go through the columns */ 
void * go throughColumn (void * parameters) {

    parameter * column = (parameter *) parameters; 
    int columnInit = column-> column; 
    int rowInit = column-> row; 

    /* We sort the column */ 
    for (int i = InitialColumn; i <9; i ++) { 
        int col [9] = {0}; // Ordered column 
        for (int j = startRow; j <9; j ++) { 
            int aux = sudoku [i] [j]; 
            if (col [aux - 1] == 0 && aux> 0) {// If the position is free and the sudoku number is> 0 
                col [aux - 1] = aux; // Assign in position [a-1] the number a // eg col [(5-1)] = 5 
            } else if (aux <= 0) { 
                verification [0] = 0;
                printf ("Sorry, in column [% d] there is an invalid number. \n", j + 1); 
                pthread_exit (0); 
            } else { 
                check [0] = 0; 
                printf ("Sorry, in column [% d] there is a repeated number. \n", j + 1); 
                pthread_exit (0); 
            } 
        } 
    } 
    check [0] = 1; 
    pthread_exit (0); // We end the execution of the thread. 
} 

/* we go through the rows */ 
void * go throughRows (void * parameters) { 

    parameter * row = (parameter *) parameters; 
    int columnInit = row-> column; 
    int rowInitial = row-> row;

    for (int i = leadingColumn; i <9; i ++) { 
        int fil [9] = {0}; 
        for (int j = startRow; j <9; j ++) { 
            int aux = sudoku [i] [j]; 
            if (fil [aux - 1] == 0 && aux> 0) { 
                fil [aux - 1] = aux; 
            } else if (aux <= 0) { 
                check [0] = 0; 
                printf ("Sorry, in row [% d] there is an invalid number. \n", i + 1); 
                pthread_exit (0); 
            } else { 
                check [0] = 0; 
                printf ("Sorry, in row [% d] there is a repeated number. \n", i + 1); 
                pthread_exit (0); 
            } 
        }
    } 
    check [1] = 1; 
    pthread_exit (0); 
} 

/* we go through the 3x3 squares */ 
void * go 

    throughSquare (void * parameters) { parameter * squareW = (parameter *) parameters; 
    int rowInit = squareW-> row; 
    int columnInit = squareW-> column; 
    int square [9] = {0}; 

    for (int i = startRow; i <startRow + 3; ++ i) { 
        for (int j = startColumn; j <startColumn + 3; ++ j) { 
            int aux = sudoku [i] [j]; 
            if (square [aux - 1] == 0 && aux> 0) { 
                square [aux - 1] = aux; 
            } 
            else {
                check [auxSquares] = 0; 
                auxSquares ++; 
                pthread_exit (0); 
            } 
        } 
    } 
    check [auxSquare] = 1; 
    auxSquares ++; 
    pthread_exit (0); 
} 

int main () { 

    /* We assign (reserve) each parameter in memory and thus be able to pass easier the location of the Struct with & a */ 
    parameter * verifyRows = (parameter *) malloc (sizeof (parameter)); 
    checkRows-> row = 0; 
    checkRows-> column = 0; 

    parameter * checkColumns = (parameter *) malloc (sizeof (parameter)); 
    checkColumns-> row = 0;
    checkColumns-> column = 0; 

    parameter * frame1 = (parameter *) malloc (sizeof (parameter)); 
    table1-> row = 0; 
    table1-> column = 0; 

    parameter * frame2 = (parameter *) malloc (sizeof (parameter)); 
    table2-> row = 0; 
    table2-> column = 3; 

    parameter * frame3 = (parameter *) malloc (sizeof (parameter)); 
    table3-> row = 0; 
    table3-> column = 6; 

    parameter * frame4 = (parameter *) malloc (sizeof (parameter)); 
    table4-> row = 3; 
    table4-> column = 0; 

    parameter * frame5 = (parameter *) malloc (sizeof (parameter)); 
    square5-> row = 3; 
    table5-> column = 3;

    parameter * frame6 = (parameter *) malloc (sizeof (parameter)); 
    square6-> row = 3; 
    table6-> column = 6; 

    parameter * frame7 = (parameter *) malloc (sizeof (parameter)); 
    square7-> row = 6; 
    table7-> column = 0; 

    parameter * frame8 = (parameter *) malloc (sizeof (parameter)); 
    square8-> row = 6; 
    table8-> column = 3; 

    parameter * frame9 = (parameter *) malloc (sizeof (parameter)); 
    square9-> row = 6; 
    table9-> column = 6; 

    // We create the threads (Thread_t position, attributes: NULL, Perform works, (void *) argument to pass) 
    pthread_create (& columns, NULL, crossColumn, (void *) verifyColumns);
    pthread_create (& row, NULL, traverseRows, (void *) checkRows); 
    pthread_create (& first_frame, NULL, traverseSquare, (void *) frame1); 
    pthread_create (& second_frame, NULL, traverseSquare, (void *) frame2); 
    pthread_create (& third_frame, NULL, traverseSquare, (void *) frame3); 
    pthread_create (& room_frame, NULL, traverseSquare, (void *) frame4); 
    pthread_create (& fifth_frame, NULL, traverseSquare, (void *) frame5); 
    pthread_create (& sixth_frame, NULL, traverseSquare, (void *) frame6); 
    pthread_create (& seventh_frame, NULL, traverseSquare, (void *) frame7); 
    pthread_create (& eighth_frame, NULL, traverseSquare, (void *) frame8);
    pthread_create (& ninth_frame, NULL, traverseSquare, (void *) frame9); 

    / * This call causes thread 'a' to "sleep" until thread 'b' terminates. 
    ---- pthread_join (pthread_t identifier of the thread we want to wait for, (void) returnStatement **). ---- 
    If we put something not NULL in the "returnStatemente" it will return what the child thread has returned. * / 
    
    Pthread_join (columns, NULL); 
    pthread_join (row, NULL); 
    pthread_join (first_frame, NULL); 
    pthread_join (second_frame, NULL); 
    pthread_join (third_frame, NULL); 
    pthread_join (fourth_frame, NULL); 
    pthread_join (fifth_frame, NULL); 
    pthread_join (sixth_frame, NULL);
    pthread_join (seventh_frame, NULL); 
    pthread_join (eighth_frame, NULL); 
    pthread_join (ninth_frame, NULL); 

    /* We go through the verification matrix and check if it was solved or not */ 
    for (int k = 0; k <11; ++ k) { 
        if (! Verification [k]) { 
            printf ("\nUpss ... The Sudoku was NOT solved. \n "); 
            exit (0); 
        } 
    } 
    printf ("\nWell !!! Congratulations, the Sudoku game was solved. \n"); 
    return 0; 
}
