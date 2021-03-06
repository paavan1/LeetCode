#include<vector>

using namespace std;

bool isValid(int cnt, vector<char> &sBoard, char c)
    {
        int x = cnt / 9, y = cnt % 9;

        for(int i = 0; i < 9; i++)
        {
            if(sBoard[x*9 + i] == c) return false;
            if(sBoard[i*9 + y] == c) return false;
        }

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(sBoard[(x / 3 * 3 + i)*9 + y/3*3 + j ] == c) return false;
            }
        }

        return true;
    }

    bool dfs(vector<vector<char> > &board, vector<char> &sBoard, int cnt)
    {
        if(cnt == 81) return true;

        int x = cnt / 9, y = cnt % 9;

        if(board[x][y] != '.')
        {
            sBoard[cnt] = board[x][y];
            return dfs(board, sBoard, cnt + 1);
        }

        for(int i = 1; i <= 9; i++)
        {

            if(isValid(cnt, sBoard, '0' + i))
            {
                sBoard[cnt] = '0' + i;
                if(dfs(board, sBoard, cnt+1)) return true;
            }

        }

        sBoard[cnt] = '.';

        return false;
    }

    void solveSudoku(vector<vector<char> > &board) {

        vector<char> sBoard;

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                sBoard.push_back(board[i][j]);
            }
        }

        dfs(board, sBoard, 0);

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                board[i][j] = sBoard[i*9 + j];
            }
        }
    }
