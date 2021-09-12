#include <stdio.h>
#include <math.h> 
  
#define COMPUTER 1 
#define USER 2 
  
#define SIDE 3 // Length of the board 
  
// Computer will move with 'O' 
// and human with 'X' 
#define COMPUTERMOVE 'O' 
#define USERMOVE 'X' 

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
    printf("\t\t\t  Tic-Tac-Toe\n\n"); 
    printf("Choose row and column numbers from 1 to 3 as below and play\n\n");
    printf("COMPUTER will play first\n");
      
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
    if (whoseTurn == COMPUTER) 
        printf("COMPUTER has won\n"); 
    else
        printf("USER has won\n"); 
    return; 
} 
  
// A function that returns true if any of the row 
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
  
// A function that returns true if any of the column 
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
  
// A function that returns true if any of the diagonal 
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
  
// A function that returns true if the game is over 
// else it returns a false 
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
    
    // Initially the board is empty 
    for (int i=0; i<SIDE; i++) 
    { 
        for (int j=0; j<SIDE; j++) 
            board[i][j] = ' '; 
    } 
      
    return; 
} 

//A function to decide the next move of the computer
void nextMove(int moveIndex, char board[][SIDE], int whoseTurn)
{
    int bestRow, bestColumn, i, j;
    bestRow=-1;
    bestColumn=-1;

    for (i=0; i<SIDE; i++)
    {
        for (j=0; j<SIDE; j++)
        {
            //if the position has not been filled yet
            if (board[i][j]== ' ')
            {               
                board[i][j]= COMPUTERMOVE;

                // checking if the move causes computer to win
                if (gameOver(board)== 0)
                {
                    board[i][j]=' ';
                    bestRow= i;
                    bestColumn= j;
                    break;
                }

                //checking if the move causes user to win
                //if it does then the computer must occupy the space 
                //to prevent the user from winning
                board[i][j]= USERMOVE;

                if (gameOver(board)== 0)
                {
                    board[i][j]=' ';
                    bestRow= i;
                    bestColumn= j;
                    break;
                }
                
                //reinitializing the cell to blank space
                board[i][j]=' ';
            }
        }

        if (bestRow != -1)
        {
            break;
        }
    }

    if (bestRow== -1)
    {
        for (i=0; i<SIDE; i++)
        {
            for (j=0; j<SIDE; j++)
            {
                if (board[i][j]== ' ')
                {
                    bestRow= i;
                    bestColumn= j;
                    break;
                }
            }
            if (bestRow==i)
            {
                break;
            }
        }
    }

    board[bestRow][bestColumn]=COMPUTERMOVE;
    printf("COMPUTER put a %c in row %d and column %d", COMPUTERMOVE, (bestRow+1), (bestColumn+1));
    showBoard(board); 
    
    return;
}

//A function for the user's move
void usersMove(int moveIndex, char board[][SIDE], int whoseTurn)
{
    int row, column;
    printf("Enter row and column\n");
    scanf("%d %d", &row, &column);
    row--;
    column--;

    //to prevent rewriting of cell
    while (board[row][column]!= ' ' && row>=0 && row<SIDE && column>=0 && column<SIDE)
        {
            printf("Cell has already been filled. Enter again\n");
            scanf("%d %d", &row, &column);
            row--;
            column--;
        }

    //to check if the entered data are in the boundaries of the array
    while (row<0 || row>=SIDE || column<0 || column>=SIDE)
        {
            printf("Row and column numbers must be from 1-3. Enter again\n");
            scanf("%d %d", &row, &column);
            row--;
            column--;
        }
             
    board[row][column] = USERMOVE;
    printf("YOU put a %c in row %d and column %d", USERMOVE, (row+1), (column+1));
    showBoard(board); 
    
    return;
}


// A function to play Tic-Tac-Toe 
void playTicTacToe(int whoseTurn) 
{ 
    // A 3*3 Tic-Tac-Toe board for playing  
    char board[SIDE][SIDE]; 

    int entry;
      
    // Initialise the game 
    initialise(board); 
      
    // Show the instructions before playing 
    showInstructions(); 
      
    int moveIndex = 0; 
      
    // Keep playing till the game is over or it is a draw 
    while (gameOver(board) == 1 &&  moveIndex != SIDE*SIDE) 
    { 
        if (whoseTurn == COMPUTER && moveIndex==0) 
        {
            board[1][1] = COMPUTERMOVE;
            printf("COMPUTER put a %c in row %d and column %d", COMPUTERMOVE, 2, 2);
            showBoard(board); 
            moveIndex ++; 
            whoseTurn = USER; 
        } 
        

        else if (whoseTurn==COMPUTER && moveIndex!=0)
        {
            nextMove(moveIndex, board, whoseTurn);
            moveIndex ++; 
            whoseTurn = USER; 
        }
        
        
        else if (whoseTurn == USER)
        {
            usersMove(moveIndex, board, whoseTurn);
            moveIndex ++; 
            whoseTurn = COMPUTER;          
        } 
    } 
  
    // If the game has drawn 
    if (gameOver(board) == 1 &&  moveIndex == SIDE * SIDE) 
        printf("It's a draw\n"); 
    else
    { 
        // Toggling the user to declare the actual 
        // winner 
        if (whoseTurn == COMPUTER) 
            whoseTurn = USER; 
        else if (whoseTurn == USER) 
            whoseTurn = COMPUTER; 
          
        // Declare the winner 
        declareWinner(whoseTurn); 
    } 
    return; 
} 

// Driver program 
int main() 
{ 
    // play the game with COMPUTER starting first 
    playTicTacToe(COMPUTER); 

    char playAgain;
    printf("Do you want to play again? (Y/N) \n");
    {
        scanf(" %c", &playAgain);
        while (playAgain == 'Y' || playAgain == 'y')
        {
            playTicTacToe(COMPUTER);
            printf("Do you want to play again? (Y/N) \n");
            scanf(" %c", &playAgain);
        }
    }

    return (0); 
} 
