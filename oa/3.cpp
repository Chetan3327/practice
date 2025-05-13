#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> applyOperations(vector<vector<int>>& board, vector<vector<int>>& operations) {
    int rows = board.size();
    int cols = board[0].size();
    vector<pair<int, int>> dirs = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (auto& op : operations) {
        int r = op[0], c = op[1];
        if (board[r][c] == 0) continue;

        int color = board[r][c];
        board[r][c] = 0;

        for (auto& d : dirs) {
            int nr = r + d.first, nc = c + d.second;
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == color) {
                board[nr][nc] = 0;
            }
        }

        for (int col = 0; col < cols; ++col) {
            int writeRow = rows - 1;
            for (int row = rows - 1; row >= 0; --row) {
                if (board[row][col] != 0) {
                    board[writeRow--][col] = board[row][col];
                }
            }
            while (writeRow >= 0) {
                board[writeRow--][col] = 0;
            }
        }
    }

    return board;
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> board(R, vector<int>(C));
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> board[i][j];

    int Q;
    cin >> Q;
    vector<vector<int>> operations(Q, vector<int>(2));
    for (int i = 0; i < Q; ++i)
        cin >> operations[i][0] >> operations[i][1];

    vector<vector<int>> result = applyOperations(board, operations);

    for (const auto& row : result) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}
