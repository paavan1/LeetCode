#include<vector>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {

        int m = matrix.size(), n = matrix[0].size();

        int low = 0, high = m*n - 1, mid = 0;

        while(low <= high)
        {
            mid = (low + high) / 2;
            int num = matrix[mid/n][mid%n];

            if(num == target){
                return true;
            }else if(num > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return false;
    }
