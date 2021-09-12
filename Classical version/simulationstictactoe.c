#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <time.h>
  
#define PLAYERFIRST 1 
#define PLAYERSECOND 0 

#define SIDE 3 // Length of the board 

// Computer will move with 'O' 
// and human with 'X' 
#define PLAYERFIRSTMOVE 'X' 
#define PLAYERSECONDMOVE 'O' 

int playerFirstWin = 0;
int playerSecondWin = 0;
int draw = 0;

// A function to show the current board status 
// void showBoard(char board[][SIDE]) 
// { 
//     printf("\n\n"); 
      
//     printf("\t\t\t  %c | %c  | %c  \n", board[0][0], board[0][1], board[0][2]); 
//     printf("\t\t\t--------------\n"); 
//     printf("\t\t\t  %c | %c  | %c  \n", board[1][0], board[1][1], board[1][2]); 
//     printf("\t\t\t--------------\n"); 
//     printf("\t\t\t  %c | %c  | %c  \n\n", board[2][0], board[2][1], board[2][2]); 
   
//     return; 
// } 

// // A function to show the instructions 
// void showInstructions() 
// { 
//     printf("\t\t Quantum Tic-Tac-Toe\n\n"); 
//     printf("Enter Classical or Quantum Move\n");
//     printf("For classical move, choose row and column numbers from 1 to 3 as below of an empty cell and play\n\n");
//     printf("For quantum move, choose row and column of one empty cell (as control) and ");
//     printf("one filled cell (as target) and play\n");
//     printf("FIRST PLAYER'S favoured move is 'X'\n");
//     printf("SECOND PLAYER'S favoured move is 'O'\n");
//     printf("Condition for winning is same as classical tic-tac-toe\n\n");
    
//     printf("\t\t\t  1 1 | 1 2  | 1 3 \n"); 
//     printf("\t\t\t--------------------\n"); 
//     printf("\t\t\t  2 1 | 2 2  | 2 3  \n"); 
//     printf("\t\t\t--------------------\n"); 
//     printf("\t\t\t  3 1 | 3 2  | 3 3  \n\n"); 
      
//     printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n"); 
  
//     return; 
// } 

// A function to declare the winner of the game 
void declareWinner(int whoseTurn) 
{ 
    if (whoseTurn == PLAYERFIRST) 
    {
        //printf("FIRST PLAYER has won\n"); 
        playerFirstWin++;
    }
    else
    {
        //printf("SECOND PLAYER has won\n"); 
        playerSecondWin++;
    }
    return; 
} 
  
// A function that returns 0 if any of the row 
// is crossed with the same player's move 
int rowCrossed(char board[][SIDE]) 
{ 
    for (int i=0; i<SIDE; i++) 
    { 
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&  board[i][0] != ' ') 
            return (0); 
    } 
    return(1); 
} 
  
// A function that returns 0 if any of the column 
// is crossed with the same player's move 
int columnCrossed(char board[][SIDE]) 
{ 
    for (int i=0; i<SIDE; i++) 
    { 
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&  board[0][i] != ' ')
            return (0); 
    }
    
    return(1); 
} 
  
// A function that returns 0 if any of the diagonal 
// is crossed with the same player's move 
int diagonalCrossed(char board[][SIDE]) 
{ 
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&  board[0][0] != ' ') 
        return(0); 
          
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') 
        return(0); 
  
    else 
        return(1); 
} 
  
// A function that returns 0 if the game is over 
// else it returns a 1 
int gameOver(char board[][SIDE]) 
{ 
    int row= rowCrossed(board);
    int column= columnCrossed(board);
    int diagonal= diagonalCrossed(board); 

    if (row==0 || column==0 || diagonal==0)
    {
        return 0;
    }

    else
    {
        return 1;
    }
    
} 

// A function to initialise the game  
void initialise(char board[][SIDE]) 
{ 
    //srand(time(0));  
    // Initially the board is empty 
    for (int i=0; i<SIDE; i++) 
    { 
        for (int j=0; j<SIDE; j++) 
            board[i][j] = ' '; 
    } 

    return; 
} 

// A function to play a move
void move(char board[][SIDE], int whoseTurn)
{
    int row, column, cell;
    cell = (rand()% (SIDE*SIDE));
    row = cell/3;
    column = cell%3;
    //to prevent rewriting of cell
    while (board[row][column]!= ' ')
        {
            cell = (rand()% (SIDE*SIDE));
            row = cell/3;
            column = cell%3;
        }

    if (whoseTurn == PLAYERFIRST)
    {   
        board[row][column]= PLAYERFIRSTMOVE;
        //printf("FIRST PLAYER put a %c in row %d and column %d\n", PLAYERFIRSTMOVE ,(row+1), (column+1));
    }
    else if (whoseTurn == PLAYERSECOND)
    {
        board[row][column]= PLAYERSECONDMOVE;
        //printf("SECOND PLAYER put a %c in row %d and column %d\n", PLAYERSECONDMOVE ,(row+1), (column+1));
    }

    //showBoard(board);     
    
    return;
}


// to check if board has been filled
int filled(char board[][SIDE])
{
    for (int i=0; i<SIDE; i++)
    {
        for (int j=0; j<SIDE; j++)
        {
            if (board[i][j] == ' ')
            {
                return 1;
            }
        }
    }
    return 0;
}

// A function to play Tic-Tac-Toe 
void playTicTacToe(int whoseTurn) 
{ 
    // A 3*3 Tic-Tac-Toe board for playing  
    char board[SIDE][SIDE]; 

    // Initialise the game 
    initialise(board); 
      
    // Show the instructions before playing 
    //showInstructions(); 
      
    // Keep playing till the game is over or it is a draw 
    while (gameOver(board) == 1 &&  filled(board) == 1) 
    {
        move(board, whoseTurn);
        
        //usersMove(board, control, target, whoseTurn);
        if (whoseTurn == PLAYERFIRST)
        {
            whoseTurn = PLAYERSECOND;
        }
        else if (whoseTurn == PLAYERSECOND)
        {
            whoseTurn = PLAYERFIRST;
        }
    } 

    // If the game has drawn 
    if (gameOver(board) == 1 &&  filled(board) == 0) 
    {
        //printf("It's a draw\n"); 
        draw++;
    }
        
    else
    { 
        // Toggling the user to declare the actual 
        // winner 
        if (whoseTurn == PLAYERFIRST) 
            whoseTurn = PLAYERSECOND; 
        else if (whoseTurn == PLAYERSECOND) 
            whoseTurn = PLAYERFIRST; 
          
        // Declare the winner 
        declareWinner(whoseTurn); 
    } 
    return; 
} 

// Driver program 
int main() 
{
    srand(time(0));

    int n = 1000000;
    for (int i=1; i<=n; i++)
    {
        playTicTacToe(PLAYERFIRST);
    }

    float probfirst, probsecond, probdraw;
    probfirst = ((float)playerFirstWin)/n;
    probsecond = ((float)playerSecondWin)/n;
    probdraw = ((float)draw)/n;

    printf("PROBABILITY OF FIRST PLAYER WINNING THE GAME = %f \n", probfirst);
    printf("PROBABILITY OF SECOND PLAYER WINNING THE GAME = %f \n", probsecond);
    printf("PROBABILITY OF THE GAME ENDING IN A DRAW= %f \n", probdraw);

    return (0); 
} 
