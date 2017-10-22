#include <iostream>
#include<string.h>
using namespace std;
 
int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int N, M, T;
int counter = 0;
char W[100];
char map [100][100];
 

void search(int row, int col)
{
    for (int idx = 0; idx < 8; idx++)
    {
        int nextRow = row + x[idx], nextCol = col + y[idx], i;
 
        for (i = 1; i < strlen(W); i++)
        {
            if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M)
                break;
 
            if (map[nextRow][nextCol] != W[i])
                break;
 
            nextRow += x[idx], nextCol += y[idx];
        }

        if (i == strlen(W))
            counter++;
    }
}

 
int main()
{
    do {
        cin >> T;
    } while (T < 1 || T > 100);
 
    for (int x=0; x < T; x++)
    {
        counter = 0;
 
        do {
            cin >> N;
        } while (N < 1 || N > 100);
        do {
            cin >> M;
        } while (M < 1 || M > 100);
 
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                cin >> map[i][j];
            }
        }
 
        do {
            cin >> W;
        } while (strlen(W) < 1 || strlen(W) > 100);
 
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if (map[i][j] == W[0])
                    search(i, j);
            }
        }
        cout << "Case " << x+1 << ": " << counter << endl;
    }
 
    return 0;   
}