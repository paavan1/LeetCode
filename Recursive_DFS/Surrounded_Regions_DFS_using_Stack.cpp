#include<vector>
#include<stack>

using namespace std;

//dfs using stack
    void dfs(vector<vector<char> > &board, int s_x, int s_y){

        int m = board.size(), n = board[0].size();

        if(s_x < 0 || s_x >= m || s_y < 0 || s_y >= n || board[s_x][s_y] != 'O') return;

        stack<int> workingS;
        workingS.push(s_x);
        workingS.push(s_y);

        int x = 0, y = 0;

        while(workingS.empty() == false)
        {
            y = workingS.top(); workingS.pop();
            x = workingS.top(); workingS.pop();

            if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') continue;

            board[x][y] = 'Y';
            workingS.push(x-1); workingS.push(y);
            workingS.push(x+1); workingS.push(y);
            workingS.push(x);   workingS.push(y-1);
            workingS.push(x);   workingS.push(y+1);
        }

    }

    void solve(vector<vector<char>> &board) {
        if(board.size() == 0 || board[0].size() == 0) return;

        int m = board.size(), n = board[0].size();

        for(int i = 0; i < n; i++)
        {
            dfs(board, 0, i);
            dfs(board, m-1, i);
        }

        for(int i = 0; i < m; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
