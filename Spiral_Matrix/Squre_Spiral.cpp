#include<vector>

using namespace std;

vector<vector<int> > generateMatrix(int n) {

        vector<vector<int> > ret(n, vector<int>(n, 0));

        int cnt = 1;

        for(int i = 0; i < n / 2; i++)
        {
            //top
            for(int j = i; j < n - i; j++)
            {
                ret[i][j] = cnt; cnt++;
            }

            //right
            for(int j = i + 1; j < n - i; j++)
            {
                ret[j][n-i-1] = cnt; cnt++;
            }

            //bottom
            for(int j = n - 2 - i; j >= i; j--)
            {
                ret[n-1-i][j] = cnt; cnt++;
            }

            //left
            for(int j = n - 2 - i; j >= i + 1; j--)
            {
                ret[j][i] = cnt; cnt++;
            }
        }

        if(n%2)
        {
            ret[n/2][n/2] = cnt;
        }

        return ret;
    }
