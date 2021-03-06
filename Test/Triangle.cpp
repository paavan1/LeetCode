#include<vector>
#include<climits>
#include<iostream>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {

        int n = triangle.size();

        if(n == 0) return 0;

        vector<int> DP(n,0);

        DP[0] = triangle[0][0];

        for(int i = 1; i < n; i++)
        {
            DP[i] = DP[i-1] + triangle[i][i];

            cout<<DP[i]<<" ";

            for(int j = i - 1 ; j >= 1; j--)
            {
                DP[j] = DP[j] < DP[j-1] ? DP[j] : DP[j-1];
                DP[j] += triangle[i][j];
                cout<<DP[j]<<" ";
            }

            DP[0] = DP[0] + triangle[i][0];
            cout<<DP[0]<<" ";
            cout<<endl;

        }

        int min = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            min = min < DP[i] ? min : DP[i];
        }

        return min;
    }

//	void test()
//	{
//		vector<vector<int> > triangle(3,vector<int>(3,0));
//		triangle[0][0] = -1;
//		triangle[1][0] = 2;triangle[1][1] = 3;
//		triangle[2][0] = 1;
//		triangle[2][1] = -1;
//		triangle[2][2] = 1;
//
//		cout<<minimumTotal(triangle)<<endl;
//	}
//
//	int main()
//	{
//		test();
//	}
