#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int decideMove(int board[9], int player)
{
    int n = 0;
    // build n untake, then random. then loop to n untaken and take spot.
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 0)
        {
            n++;
        }
    }
    return (rand() % n +1);
}

bool checkWinner(int board[], int move, int player)
{
    if (move % 3 == 0)
    {
        if ((board[0] == board[3]) && (board[3] == board[6]) && (board[6] == player))
        {
            return true;
        }
        if ((board[move] == board[move+1]) && (board[move+1] == board[move+2]) && (board[move+2] == player))
        {
            return true;
        }
    }
    else if (move % 3 == 1)
    {
        if ((board[1] == board[4]) && (board[4] == board[7]) && (board[7] == player))
        {
            return true;
        }
        if ((board[move] == board[move+1]) && (board[move+1] == board[move-1]) && (board[move-1] == player))
        {
            return true;
        }
    }
    else if (move % 3 == 2)
    {
        if ((board[2] == board[5]) && (board[5] == board[8]) && (board[8] == player))
        {
            return true;
        }
        if ((board[move] == board[move-1]) && (board[move-1] == board[move-2]) && (board[move-2] == player))
        {
            return true;
        }
    }
    return false;
}

bool makeMove(int board[], int move, int player)
{
    // make the Nth move.
    int cnt = 0;
    bool winner = false;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 0)
        {
            cnt++;
        }
        if (cnt == move)
        {
            board[i] = player;
            winner = checkWinner(board, i, player);
            break;
        }
    }

    // record move and board in history
    // Check winner
    return winner;
}

void printBoard(int board[])
{
    cout << board[0] << board[1] << board[2] << endl;
    cout << board[3] << board[4] << board[5] << endl;
    cout << board[6] << board[7] << board[8] << endl;
}

int playGame()
{
    int player = rand() % 2 + 1;
    int board[9] = {0};
    cout << "First player: " << player << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << "Loop: " << i << "Player:  " << player << endl;
        int nthOpen = decideMove(board, player);
        cout << "Nth open: " << nthOpen << endl;
        if(makeMove(board, nthOpen, player))
        {
            printBoard(board);
            cout << "Winner! Player: " << player << endl;
            break;
        }
        printBoard(board);
        
        player = player % 2 + 1;
    }
}
int main()
{
    srand (time(NULL));
    playGame();
    cout << "Hello world: " << endl;
    return 0;
}

