#include<vector>

using namespace std;

//two pointers
    int threeSumClosest(vector<int> &num, int target) {

        sort(num.begin(), num.end());

        int temp = 0, sum = num[0] + num[1] + num[2];

        for(int i = 0; i < num.size(); i++)
        {
            if(i && num[i] == num[i-1]) continue;

            int j = i + 1, k = num.size() - 1;

            while(j < k)
            {
                temp = num[i] + num[j] + num[k];

                if(abs (temp - target ) < abs(sum - target) ) {sum = temp;}

                if( temp == target){
                    return sum;
                }else if(temp > target){
                    k--;
                }else{
                    j++;
                }
            }
        }

        return sum;
    }
