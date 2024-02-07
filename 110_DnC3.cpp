#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int row, int col, int arr[][3], vector<vector<bool>> &visited)
{
    if ((x >= 0 && x < row) && (y >= 0 && y < col) && (arr[x][y] == 1) && (visited[x][y] == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solveMaze(int arr[3][3], int row, int col, int i, int j, vector<vector<bool>> &visited, vector<string> &path, string output)
{

    if (i == row - 1 && j == col - 1)
    {
        // ~ Answer found
        path.push_back(output);
        return;
    }

    // ~ Down -> i+1,j
    if (isSafe(i + 1, j, row, col, arr, visited))
    {
        visited[i + 1][j] = true;
        solveMaze(arr, row, col, i + 1, j, visited, path, output + 'D');
        visited[i + 1][j] = false;
    }

    // ~ Left -> i,j-1
    if (isSafe(i, j - 1, row, col, arr, visited))
    {
        visited[i][j - 1] = true;
        solveMaze(arr, row, col, i, j - 1, visited, path, output + 'L');
        visited[i][j - 1] = false;
    }

    // ~ Right -> i,j+1
    if (isSafe(i, j + 1, row, col, arr, visited))
    {
        visited[i][j + 1] = true;
        solveMaze(arr, row, col, i, j + 1, visited, path, output + 'R');
        visited[i][j + 1] = false;
    }

    // ~ Up -> i-1,j
    if (isSafe(i - 1, j, row, col, arr, visited))
    {
        visited[i - 1][j] = true;
        solveMaze(arr, row, col, i - 1, j, visited, path, output + 'U');
        visited[i - 1][j] = false;
    }
}

int main()
{
    // * Rat in a maze
    // ! 0 --> rasta blocked hai
    // ! 1 --> rasta open hai

    int maze[3][3] = {{1, 0, 0},
                      {1, 1, 0},
                      {1, 1, 1}};

    if(maze[0][0] == 0){
        cout<<"No path Exists" <<endl;
        return 0;
    }

    int rows = 3;
    int col = 3;

    vector<vector<bool>> visited(rows, vector<bool>(col, false));
    visited[0][0] = true;

    vector<string> path;
    string output = "";

    solveMaze(maze, rows, col, 0, 0, visited, path, output);

    cout << "Printing the result" << endl;
    for (auto i : path)
    {
        cout << i << " ";
    }
    cout << endl;

    if(path.size() == 0){
        cout<<"No path exists"<<endl;
    }

    return 0;
}
