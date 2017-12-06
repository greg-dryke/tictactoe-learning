#include "main.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
//#include <vector>

using namespace std;

int decideMove(int board[9], int player)
{
    if (player == 2)
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

    int nth =  (rand() % n +1);
    int cnt = 0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 0)
        {
            cnt++;
        }
        if (cnt == nth)
        {
            return i;
        }

    }
    }
    else
    {
        int chosen =  makeCannedDecision(board, player);
        return chosen;
    }
}

int makeCannedDecision(int board[9], int player)
{
    if (board[4] == 0)
    {
        return 4;
    }
    else if (board[4] == player)
    {
        if (board[0] == player && board[8] == 0)
        {
            return 8;
        }
        else if (board[2] == player && board[6] == 0)
        {
            return 6;
        }
        else if (board[6] == player && board[2] == 0)
        {
            return 2;
        }
        else if (board[8] == player && board[0] == 0)
        {
            return 0;
        }
        else if (board[1] == player && board[7] == 0)
        {
            return 7;
        }
        else if (board[7] == player && board[1] == 0)
        {
            return 1;
        }
        else if (board[3] == player && board[5] == 0)
        {
            return 5;
        }
        else if (board[5] == player && board[3] == 0)
        {
            return 3;
        }
        else if (board[0] == 0)
        {
           return  0;
        }
        else if (board[2] == 0)
        {
            return 2;
        }
        else if (board[6] == 0)
        {
            return 6;
        }
        else if (board[8] == 0)
        {
            return 8;
        }
        else
        {
    
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 0)
        {
            return i;
        }
    }
        }
    
    }
    else
    {
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 0)
        {
            return i;
        }
    }

    }
    
}

bool checkDiags(int board[], int player)
{
    if ((board[0] == board[4]) && (board[4] == board[8]) && (board[8] == player))
    {
        return true;
    }
    else if ((board[2] == board[4]) && (board[4] == board[6]) && (board[6] == player))
    {
        return true;
    }
    return false;
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
        if (move == 0 || move == 2)
        {
            if (checkDiags(board, player))
            {
                return true;
            }
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
        if (move == 4)
        {
            if (checkDiags(board, player))
            {
                return true;
            }
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
        if (move == 6 || move == 8)
        {
            if (checkDiags(board, player))
            {
                return true;
            }
        }
    }
    return false;
}

bool makeNthMove(int board[], int move, int player)
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

bool makeMove(int board[], int move, int player)
{
            board[move] = player;
            return checkWinner(board, move, player);
           

}
void printBoard(int board[])
{
    cout << board[0] << board[1] << board[2] << endl;
    cout << board[3] << board[4] << board[5] << endl;
    cout << board[6] << board[7] << board[8] << endl;
    cout << endl;
}

int playGame()
{
    int moves;
    int player = rand() % 2 + 1;
    int board[9] = {0};
    cout << "First player: " << player << endl;
    for (int i = 0; i < 9; i++)
    {
        int nthOpen = decideMove(board, player);
        if(makeMove(board, nthOpen, player))
        {
            printBoard(board);
            cout << "Winner! Player: " << player << endl;
            moves = i+1;
            //return moves;
            return player;
        }
        printBoard(board);
        
        player = player % 2 + 1;
    }
    //return moves+1;
    return 0;
}

void printMoves(vector<int> & moves, int length)
{
    cout << "Starting to print array" << endl;
    int tie = 0;
    int p1 = 0;
    int p2 = 0;
    for (vector<int>::size_type g = 0; g != moves.size(); g++)
    {
        switch (moves[g])
        {
            case 0:
                tie++;
                break;
            case 1:
                p1++;
                break;
            case 2:
                p2++;
                break;
        }
        if (g % 10 == 0)
        {
            cout << endl;
        }
        cout <<  moves[g] << ", ";
    }
    cout << endl;
    cout << "Ties: " << tie << " P1: " << p1 << " P2: " << p2 << endl;
}

int main()
{
    int numGames = 1000;
    srand (time(NULL));
    vector<int> games = vector<int>();
    int sum = 0;
    for (int i = 0; i < numGames; i++)
    {
        int g = playGame();
        sum += g;
        games.push_back(g);
    }

    cout << "Sum: " << sum << endl;
    double avg = sum / (numGames * 1.0);
    cout << "Avg: " << avg << endl;
    printMoves(games, numGames);
    return 0;
}

