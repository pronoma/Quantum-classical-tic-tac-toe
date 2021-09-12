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

// A function to show the current board status 
void showBoard(char board[][SIDE]) 
{ 
    printf("\n\n"); 
      
    printf("\t\t\t  %c | %c  | %c  \n", board[0][0], board[0][1], board[0][2]); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t  %c | %c  | %c  \n", board[1][0], board[1][1], board[1][2]); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t  %c | %c  | %c  \n\n", board[2][0], board[2][1], board[2][2]); 
   
    return; 
} 

// A function to show the instructions 
void showInstructions() 
{ 
    printf("\t\t Quantum Tic-Tac-Toe\n\n"); 
    printf("Enter Classical or Quantum Move\n");
    printf("For classical move, choose row and column numbers from 1 to 3 as below of an empty cell and play\n\n");
    printf("For quantum move, choose row and column of one empty cell (as control) and ");
    printf("one filled cell (as target) and play\n");
    printf("FIRST PLAYER'S favoured move is 'X'\n");
    printf("SECOND PLAYER'S favoured move is 'O'\n");
    printf("Condition for winning is same as classical tic-tac-toe\n\n");
    
    printf("\t\t\t  1 1 | 1 2  | 1 3 \n"); 
    printf("\t\t\t--------------------\n"); 
    printf("\t\t\t  2 1 | 2 2  | 2 3  \n"); 
    printf("\t\t\t--------------------\n"); 
    printf("\t\t\t  3 1 | 3 2  | 3 3  \n\n"); 
      
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n"); 
  
    return; 
} 

// A function to declare the winner of the game 
void declareWinner(int whoseTurn) 
{ 
    if (whoseTurn == PLAYERFIRST) 
        printf("FIRST PLAYER has won\n"); 
    else
        printf("SECOND PLAYER has won\n"); 
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
void initialise(char board[][SIDE], int control[], int target[]) 
{ 
    //srand(time(0));  
    // Initially the board is empty 
    for (int i=0; i<SIDE; i++) 
    { 
        for (int j=0; j<SIDE; j++) 
            board[i][j] = ' '; 
    } 

    for (int i=0; i<SIDE*SIDE; i++)
    {
        control[i] = -1;
        target[i] = -1;
    }  
    return; 
} 

// A function to play a classical move
void cmove(char board[][SIDE], int control[], int target[], int whoseTurn)
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

    printf("Player chose row %d and column %d\n", (row+1), (column+1));

    int num = (rand()% (2));
    if (num == 1)
    {
        board[row][column] = PLAYERFIRSTMOVE;  
        if (whoseTurn == PLAYERFIRST)
        {
            printf("FIRST PLAYER got an %c in row %d and column %d\n", PLAYERFIRSTMOVE, (row+1), (column+1));  
        }    
        else if (whoseTurn == PLAYERSECOND)
        {
            printf("SECOND PLAYER got an %c in row %d and column %d\n", PLAYERFIRSTMOVE, (row+1), (column+1));  
        }
    }
    else if (num == 0)
    {
        board[row][column] = PLAYERSECONDMOVE;
        if (whoseTurn == PLAYERFIRST)
        {
            printf("FIRST PLAYER got an %c in row %d and column %d\n", PLAYERSECONDMOVE, (row+1), (column+1));  
        }    
        else if (whoseTurn == PLAYERSECOND)
        {
            printf("SECOND PLAYER got an %c in row %d and column %d\n", PLAYERSECONDMOVE, (row+1), (column+1));  
        }       
    }

    if (control[cell]!= -1)
    {
        int targetrow = target[cell]/3;
        int targetcolumn = target[cell]%3;

        if (control[cell] == num)
        {
            if (board[targetrow][targetcolumn] == PLAYERFIRSTMOVE)
            {
                board[targetrow][targetcolumn] = PLAYERSECONDMOVE;
            }
            else
            {
                board[targetrow][targetcolumn] = PLAYERFIRSTMOVE;
            }
            printf("Since player of quantum move got control cell in it's favour, target cell (%d %d) flipped to %c\n", targetrow+1, targetcolumn+1, board[targetrow][targetcolumn]);        
        }
        else
        {
            printf("Since player of quantum move got control cell against it's favour, target cell remains unchanged\n");
        }
        
    }

    showBoard(board);     
    
    return;
}

void qmove(char board[][SIDE], int control[], int target[], int whoseTurn)
{
    int controlrow, controlcolumn, controlcell, targetrow, targetcolumn, targetcell;

    controlcell = (rand()% (SIDE*SIDE));
    controlrow = controlcell/3;
    controlcolumn = controlcell%3;

    while (board[controlrow][controlcolumn]!= ' ')
        {
            controlcell = (rand()% (SIDE*SIDE));
            controlrow = controlcell/3;
            controlcolumn = controlcell%3;
        }

    int entangled = 0;
    while (entangled == 0)
    {
        if (control[controlcell] != -1)
        {
            controlcell = (rand()% (SIDE*SIDE));
            controlrow = controlcell/3;
            controlcolumn = controlcell%3;
            continue;
        }
        entangled = 1;
    }

    while (board[controlrow][controlcolumn]!= ' ')
        {
            controlcell = (rand()% (SIDE*SIDE));
            controlrow = controlcell/3;
            controlcolumn = controlcell%3;
        }

    control[controlcell] = whoseTurn;
   
    targetcell = (rand()% (SIDE*SIDE));
    targetrow = targetcell/3;
    targetcolumn = targetcell%3;

    while (board[targetrow][targetcolumn]== ' ')
        {
            targetcell = (rand()% (SIDE*SIDE));
            targetrow = targetcell/3;
            targetcolumn = targetcell%3;
        }

    target[controlcell] = targetcell;

    printf("Player chose control cell as (%d %d)\n", (controlrow+1), (controlcolumn+1));
    printf("Player chose target cell as (%d %d)\n", (targetrow+1), (targetcolumn+1));
    printf("Cells (%d %d) and (%d %d) are entangled\n", (controlrow+1), (controlcolumn+1), (targetrow+1), (targetcolumn+1));

    showBoard(board);

    return;
}

// A function to check the type of move
void usersMove(char board[][SIDE], int control[], int target[], int whoseTurn)
{
    int move_type;
    move_type = (rand()% (2));
    int classic = 1;
    int quantum = 0;
     
    if (move_type == 1 || (move_type == 0 && classic == (quantum+1) && quantum!=0))
    {
        printf("Player chose Classical move\n");
        cmove(board, control, target, whoseTurn);
        classic++; 
    }
    else
    {
        printf("Player chose Quantum move\n");
        qmove(board, control, target, whoseTurn);
        quantum++;
    }

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
    int control[(SIDE*SIDE)], target[(SIDE*SIDE)];

    // Initialise the game 
    initialise(board, control, target); 
      
    // Show the instructions before playing 
    showInstructions(); 
    int count =0;
      
    // Keep playing till the game is over or it is a draw 
    while (gameOver(board) == 1 &&  filled(board) == 1) 
    {
        //int entry;
        //printf("Enter any number for next move");
        //scanf(" %d", &entry);

        if (count == 0)
        {
            printf("FIRST PLAYER chose Classical move\n");
            count = 1;
            cmove(board, control, target, whoseTurn);
        }
        else
        {
            usersMove(board, control, target, whoseTurn);
        }
        

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
        printf("It's a draw\n"); 
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
    playTicTacToe(PLAYERFIRST);

    char playAgain;
    printf("Do you want to play again? (Y/N) \n");
    scanf(" %c", &playAgain);
    while (playAgain == 'Y' || playAgain == 'y')
    {
        playTicTacToe(PLAYERFIRST);
        printf("Do you want to play again? (Y/N) \n");
        scanf(" %c", &playAgain);
    }

    return (0); 
} 
