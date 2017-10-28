#include "main.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
//#include <vector>

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
            return moves;
        }
        printBoard(board);
        
        player = player % 2 + 1;
    }
    return moves+1;
}

void printMoves(vector<int> & moves, int length)
{
    cout << "Starting to print array" << endl;
    for (vector<int>::size_type g = 0; g != moves.size(); g++)
    {
        if (g % 10 == 0)
        {
            cout << endl;
        }
        cout <<  moves[g] << ", ";
    }
    cout << endl;
}

int main()
{
    int numGames = 100;
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

