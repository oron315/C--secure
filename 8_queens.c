/*------------------------------------------------------
* Filename: 8_queens.c
* Description: 
* Author: Emily Luskin and Oron Bar Hillel
-------------------------------------------------------*/

/*------------------------------------------------------
* Function Name - display
*
* Function Purpose - prints the board with the queens
*
* Parameters –  [IN board - int board[SIZE][SIZE]  matrix of int]
*
* Return Values - void
*
* Author - Emily Luskin and Oron Bar Hillel
-------------------------------------------------------*/

/*------------------------------------------------------
* Function Name - check_if_safe
*
* Function Purpose - checks if another queen can be on that 
*
* Parameters –  [IN int board[SIZE][SIZE], int row, int col - (x,y) in a square matrix.
*                 IN OUT - NULL]
*
* Return Values - bool
*
* Author - Emily Luskin and Oron Bar Hillel
-------------------------------------------------------*/
/*------------------------------------------------------
* Function Name - solved_board
*
* Function Purpose -  a recursive function that goes on all the rows and tries to
 find a good placement, if hasnt find goes back to the previous raw.
*
* Parameters –  [IN int board[SIZE][SIZE], int row, int col 
*                 IN OUT - NULL]
*
* Return Values - bool
*
* Author - Emily Luskin and Oron Bar Hillel
-------------------------------------------------------*/
#include <stdio.h>
#include <stdbool.h>
#define SIZE 8


void display(int board[SIZE][SIZE]);
bool check_if_safe(int board[SIZE][SIZE], int row, int col);
bool solve_board(int board[SIZE][SIZE], int row);


void display(int board[SIZE][SIZE]){
    for(int j = 0; j < SIZE; ++j){
        for(int i = 0; i < SIZE; ++i){
            if(board[i][j] == 0){
                printf("#  ");
            }else{
                printf("Q  ");
            }    
        }
        printf("\n");
    }
}



bool check_if_safe(int board[SIZE][SIZE], int row, int col){
    for(int i=0; i< SIZE; ++i){

        if(board[row + i][col + i] == 1 && (col + i) < SIZE && (row + i) < SIZE){
            return false;
        }
        if(board[row - i][col - i] == 1 && (col - i) >= 0 && (row - i) >= 0){
            return false;
        }
        if(board[row - i][col + i] == 1 && (col + i) < SIZE && (row - i) >= 0){
            return false;
        }
        if(board[row + i][col - i] == 1 && (col - i) >= 0 && (row + i) < SIZE){
            return false;
        }
    }
    
    for(int i=0; i<row; i++){
        if(board[i][col]==1){
            return false;
        }
    }
    for(int i= row-1, j=col-1; i>0 &&j>0 ; i--, j--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i= row-1, j=col+1; i>0 &&j>0 ; i--, j++){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
    
}



bool solve_board(int board[SIZE][SIZE], int row){
    if(row==SIZE){
        return true;
    }
    for(int col=0; col<SIZE; ++col){
        if (check_if_safe(board, row, col)){
            board[row][col] = 1;
            if (solve_board(board, row+1)){
                return true;
            }
            board[row][col]=0;

        }
    }
    return false;
}


int main(){ 
    
    int board[SIZE][SIZE] = {0}; 
    if (solve_board(board, 0)){
        printf("the solution: \n");
        display(board);
    }
    else{
        printf("falsed");
    }
    
    return 0;
}