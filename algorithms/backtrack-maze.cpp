#include <bits/stdc++.h>
using namespace std;

#define N 4

void print(int solution[N][N]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

bool is_valid(int maze[N][N], int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) {
        return true;
    }
    return false;
}

bool solve_maze_helper(int maze[N][N], int x, int y, int solution[N][N]) {
    if (x == N-1 && y == N-1) {
        solution[x][y] = 1;
        return true;
    }

    if (is_valid(maze, x, y)) {
        solution[x][y] = 1;
        if (solve_maze_helper(maze, x+1, y, solution) == true) {
            return true;
        }
        if (solve_maze_helper(maze, x, y+1, solution) == true) {
            return true;
        }
        solution[x][y] = 0;
        return false;
    }
    return false;
}

bool solve_maze(int maze[N][N]) {
    int solution[N][N] = {{0,0,0,0},
                          {0,0,0,0},
                          {0,0,0,0},
                          {0,0,0,0}};
    if (solve_maze_helper(maze,0,0,solution) == false) {
        return false;
    }
    print(solution);
    return true;
}


int main() {
    int maze[N][N] = {{1,0,0,0},
                      {1,1,0,1},
                      {0,1,0,0},
                      {1,1,1,1}};
    solve_maze(maze);
    return 0; 
}