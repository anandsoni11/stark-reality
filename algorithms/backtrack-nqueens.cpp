#include <bits/stdc++.h>
using namespace std;

#define N 16

void print(int solution[N][N]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

bool is_safe(int board[N][N], int row, int col) {
    int i, j;
    for (int i=0; i<col; i++) {
        if (board[row][i] == 1) return false;
    }
    for (i=row, j=col; i>=0 && j>=0; i--, j--) {
        if (board[i][j] == 1) return false;
    }
    for (i=row, j=col; i<N && j>=0; i++, j--) {
        if (board[i][j] == 1) return false;
    }
    return true;
}

bool solve_n_queens_helper(int board[N][N], int col) {
    if (col >= N) return true;
    for (int i=0; i<N; i++) {
        if (is_safe(board, i, col)) {
            board[i][col] = 1;
            if (solve_n_queens_helper(board, col+1)) return true;
            board[i][col]=0;
        }
    }
    return false;
}

bool solve_n_queens()
{
    int board[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
 
    if ( solve_n_queens_helper(board, 0) == false )
    {
      printf("Solution does not exist");
      return false;
    }
 
    print(board);
    return true;
}
 
// driver program to test above function
int main()
{
    solve_n_queens();
    return 0;
}