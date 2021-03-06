#include<vector>

using namespace std;
void solve(vector<vector<char>> &board) {

        if(board.size() == 0 || board[0].size() == 0) return;

        int m = board.size(), n = board[0].size();

        for(int i = 0; i < n; i++)
        {
            dfs(board, 0, i);
            dfs(board,m - 1,i);
        }

        for(int i = 0; i < m; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char> > &board, int x, int y){

        int m = board.size(), n = board[0].size();

        if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') return;

        board[x][y] = 'Y';
        dfs(board, x - 1, y);
        dfs(board, x + 1, y);
        dfs(board, x, y - 1);
        dfs(board, x, y + 1);
    }
