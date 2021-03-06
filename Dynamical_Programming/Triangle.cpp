#include<vector>
#include<climits>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {

        int n = triangle.size();

        if(n == 0) return 0;

        vector<int> DP(n,0);

        DP[0] = triangle[0][0];

        for(int i = 1; i < n; i++)
        {
            DP[i] = DP[i-1] + triangle[i][i];

            for(int j = i - 1 ; j >= 1; j--)
            {
                DP[j] = DP[j] < DP[j-1] ? DP[j] : DP[j-1];
                DP[j] += triangle[i][j];
            }

            DP[0] = DP[0] + triangle[i][0];

        }

        int min = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            min = min < DP[i] ? min : DP[i];
        }

        return min;
    }
