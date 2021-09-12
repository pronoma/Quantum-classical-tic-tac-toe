#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <time.h>
  
#define USERFIRST 1 
#define USERSECOND 0 

#define SIDE 3 // Length of the board 
  
// Computer will move with 'O' 
// and human with 'X' 
#define USERFIRSTMOVE 'X' 
#define USERSECONDMOVE 'O' 

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
    printf("FIRST PLAYER'S favoured move is 'X'");
    printf("SECOND PLAYER'S favoured move is 'O'");
    printf("Condition for winning is same as classical tic-tac-toe\n");
    
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
    if (whoseTurn == USERFIRST) 
        printf("FIRST USER has won\n"); 
    else
        printf("SECOND USER has won\n"); 
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
    srand(time(0));  
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
    printf("Enter row and column\n");
    scanf("%d %d", &row, &column);
    row--;
    column--;
    cell = row* 3 + column;
    //to prevent rewriting of cell
    while (board[row][column]!= ' ' && row>=0 && row<SIDE && column>=0 && column<SIDE)
        {
            printf("Cell has already been filled. Enter again\n");
            scanf("%d %d", &row, &column);
            row--;
            column--;
            cell = row* 3 + column;
        }

    //to check if the entered data are in the boundaries of the array
    while (row<0 || row>=SIDE || column<0 || column>=SIDE)
        {
            printf("Row and column numbers must be from 1-3. Enter again\n");
            scanf("%d %d", &row, &column);
            row--;
            column--;
            cell = row* 3 + column;
        }

    int num = (rand()% (2));
    if (num == 1)
    {
        board[row][column] = USERFIRSTMOVE;  
        if (whoseTurn == USERFIRST)
        {
            printf("FIRST PLAYER got an %c in row %d and column %d\n", USERFIRSTMOVE, (row+1), (column+1));  
        }    
        else if (whoseTurn == USERSECOND)
        {
            printf("SECOND PLAYER got an %c in row %d and column %d\n", USERFIRSTMOVE, (row+1), (column+1));  
        }
    }
    else if (num == 0)
    {
        board[row][column] = USERSECONDMOVE;
        if (whoseTurn == USERFIRST)
        {
            printf("FIRST PLAYER got an %c in row %d and column %d\n", USERSECONDMOVE, (row+1), (column+1));  
        }    
        else if (whoseTurn == USERSECOND)
        {
            printf("SECOND PLAYER got an %c in row %d and column %d\n", USERSECONDMOVE, (row+1), (column+1));  
        }       
    }

    if (control[cell]!= -1)
    {
        int targetrow = target[cell]/3;
        int targetcolumn = target[cell]%3;

        if (control[cell] == num)
        {
            if (board[targetrow][targetcolumn] == USERFIRSTMOVE)
            {
                board[targetrow][targetcolumn] = USERSECONDMOVE;
            }
            else
            {
                board[targetrow][targetcolumn] = USERFIRSTMOVE;
            }
            printf("Since player of quantum move got control cell in his/her favour, target cell (%d %d) flipped to %c\n", targetrow+1, targetcolumn+1, board[targetrow][targetcolumn]);        
        }
        else
        {
            printf("Since player of quantum move got control cell against his/her favour, target cell remains unchanged\n");
        }
        
    }

    showBoard(board);     
    
    return;
}

void qmove(char board[][SIDE], int control[], int target[], int whoseTurn)
{
    int controlrow, controlcolumn, controlcell, targetrow, targetcolumn, targetcell;
    
    printf("Enter row and column of Control cell\n");
    scanf("%d %d", &controlrow, &controlcolumn);
    controlrow--;
    controlcolumn--;
    controlcell = controlrow * 3 + controlcolumn;
    control[controlcell] = whoseTurn;

    while (board[controlrow][controlcolumn]!= ' ' && controlrow>=0 && controlrow<SIDE && controlcolumn>=0 && controlcolumn<SIDE)
        {
            printf("Note: Control cell must be in quantum state");
            printf("Cell has already been filled, i.e. in classical state. Enter again\n");
            scanf("%d %d", &controlrow, &controlcolumn);
            controlrow--;
            controlcolumn--;
            controlcell = controlrow * 3 + controlcolumn;
            control[controlcell] = whoseTurn;
        }

    //to check if the entered data are in the boundaries of the array
    while (controlrow<0 || controlrow>=SIDE || controlcolumn<0 || controlcolumn>=SIDE)
        {
            printf("Row and column numbers must be from 1-3. Enter again\n");
            scanf("%d %d", &controlrow, &controlcolumn);
            controlrow--;
            controlcolumn--;
            controlcell = controlrow * 3 + controlcolumn;
            control[controlcell] = whoseTurn;
        }

    
   
    printf("Enter row and column of Target cell\n");
    scanf("%d %d", &targetrow, &targetcolumn);
    targetrow--;
    targetcolumn--;
    targetcell = targetrow * 3 + targetcolumn;
    target[controlcell] = targetcell;

    while (board[targetrow][targetcolumn]== ' ' && targetrow>=0 && targetrow<SIDE && targetcolumn>=0 && targetcolumn<SIDE)
        {
            printf("Note: Target cell must be in classical state");
            printf("Cell is blank, i.e., in quantum state. Enter again\n");
            scanf("%d %d", &targetrow, &targetcolumn);
            targetrow--;
            targetcolumn--;
            targetcell = targetrow * 3 + targetcolumn;
            target[controlcell] = targetcell;
        }

    //to check if the entered data are in the boundaries of the array
    while (controlrow<0 || controlrow>=SIDE || controlcolumn<0 || controlcolumn>=SIDE)
        {
            printf("Row and column numbers must be from 1-3. Enter again\n");
            scanf("%d %d", &targetrow, &targetcolumn);
            targetrow--;
            targetcolumn--;
            targetcell = targetrow * 3 + targetcolumn;
            target[controlcell] = targetcell;
        }

    printf("Cells (%d %d) and (%d %d) are entangled", (controlrow+1), (controlcolumn+1), (targetrow+1), (targetcolumn+1));

    showBoard(board);

    return;
}

// A function to check the type of move
void usersMove(char board[][SIDE], int control[], int target[], int whoseTurn)
{
    char move_type;
    printf("Enter Classical Move (c) or Quantum Move (q)\n");
    scanf(" %c", &move_type);
    while (move_type!= 'c' && move_type!= 'q')
    {
        printf("Enter c for Classical move and q for Quantum move\n");
        scanf(" %c", &move_type);
    }
    if (move_type == 'c')
    {
        cmove(board, control, target, whoseTurn);
    }
    else
    {
        qmove(board, control, target, whoseTurn);
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
    int control[SIDE*SIDE], target[SIDE*SIDE];

    // Initialise the game 
    initialise(board, control, target); 
      
    // Show the instructions before playing 
    showInstructions(); 
      
    // Keep playing till the game is over or it is a draw 
    while (gameOver(board) == 1 &&  filled(board) == 1) 
    {
        usersMove(board, control, target, whoseTurn);
        if (whoseTurn == USERFIRST)
        {
            whoseTurn = USERSECOND;
        }
        else if (whoseTurn == USERSECOND)
        {
            whoseTurn = USERFIRST;
        }
    } 

    // If the game has drawn 
    if (gameOver(board) == 1 &&  filled(board) == 0) 
        printf("It's a draw\n"); 
    else
    { 
        // Toggling the user to declare the actual 
        // winner 
        if (whoseTurn == USERFIRST) 
            whoseTurn = USERSECOND; 
        else if (whoseTurn == USERSECOND) 
            whoseTurn = USERFIRST; 
          
        // Declare the winner 
        declareWinner(whoseTurn); 
    } 
    return; 
} 

// Driver program 
int main() 
{
    playTicTacToe(USERFIRST);

    char playAgain;
    printf("Do you want to play again? (Y/N) \n");
    scanf(" %c", &playAgain);
    while (playAgain == 'Y' || playAgain == 'y')
    {
        playTicTacToe(USERFIRST);
        printf("Do you want to play again? (Y/N) \n");
        scanf(" %c", &playAgain);
    }

    return (0); 
} 
