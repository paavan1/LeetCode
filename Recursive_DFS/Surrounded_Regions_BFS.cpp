#include<vector>
#include<queue>

using namespace std;

 void bfs(vector<vector<char> > &board, int s_x, int s_y){

        int m = board.size(), n = board[0].size();

        if(s_x < 0 || s_x >= m || s_y < 0 || s_y >= n || board[s_x][s_y] != 'O') return;

        queue<int> workingQ;
        workingQ.push(s_x);
        workingQ.push(s_y);

        int x = 0, y = 0;
        while(workingQ.empty() == false)
        {
            x = workingQ.front(); workingQ.pop();
            y = workingQ.front(); workingQ.pop();

            if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') continue;
            board[x][y] = 'Y';
            workingQ.push(x-1); workingQ.push(y);
            workingQ.push(x+1); workingQ.push(y);
            workingQ.push(x); workingQ.push(y-1);
            workingQ.push(x); workingQ.push(y+1);
        }
    }

    void solve(vector<vector<char>> &board) {
        if(board.size() == 0 || board[0].size() == 0) return;

        int m = board.size(), n = board[0].size();

        for(int i = 0; i < n; i++)
        {
            bfs(board, 0, i);
            bfs(board, m-1, i);
        }

        for(int i = 0; i < m; i++)
        {
            bfs(board, i, 0);
            bfs(board, i, n-1);
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



