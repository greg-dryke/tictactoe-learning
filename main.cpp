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

int playGame()
{
    int player = rand() % 2 + 1;
    int board[9] = int[9];
    cout << "First player: " << player << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << "Loop: " << i << "Player:  " << player << endl;
        int nthOpen = decideMove(board, player);
        cout << "Nth open" << nthOpen << endl;
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

