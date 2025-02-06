// C++ Program to find the next generation
// of a given matrix of cells
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void printMat(vector<vector<int>> nextGen){
    int m = nextGen.size(), n = nextGen[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << nextGen[i][j] << " ";
        }
        cout << endl;
    }
}
// Function to find the next generation
vector<vector<int>> findNextGen(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();

    // create matrix to store cells of next generation.
    vector<vector<int>> nextGen(m, vector<int>(n, 0));

    // Directions of eight possible neighbors
    vector<vector<int>> directions = 
    {{0, 1}, {1, 0}, {0, -1}, 
     {-1, 0}, {1, 1}, {-1, -1},
     {1, -1}, {-1, 1}};

    // Iterate over the matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            // Count the number of live neighbors
            int live = 0;
            for (auto dir : directions) {
                int x = i + dir[0];
                int y = j + dir[1];

                // Check if the neighbor is live
                if (x >= 0 && x < m && y >= 0 && y < n && (mat[x][y] == 1)) {
                    live++;
                }
            }

            // If current cell is live and number of live neighbors
            // is less than 2 or greater than 3, then the cell will die
            if (mat[i][j] == 1 && !(live == 2 || live == 3)) {
                nextGen[i][j] = 0;
            }

            // If current cell is dead and number of live neighbors
            // is equal to 3, then the cell will become live
            else if (mat[i][j] == 0 && live == 3) {
                nextGen[i][j] = 1;
            }

            // else the state of cells
            // will remain same.
            else {
                nextGen[i][j] = mat[i][j];
            }
        }
    }
    printMat(nextGen);
    cout << "+++++++++++++++++++++" << endl;
    if(nextGen != mat){
        
        Sleep(2000);
        system("cls");
        findNextGen(nextGen);
    }
}

int main() {
    vector<vector<int>> mat = 
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
     };
    findNextGen(mat);
    return 0;
 
}