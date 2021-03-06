#include<vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

        int start = 0, min = 0, sum = 0;

        for(int i = 0; i < gas.size(); i++)
        {
            sum = sum < 0 ? gas[i] - cost[i] : gas[i] - cost[i] + sum;

            if(sum < 0) {
                min = min < sum ? min : sum;
                start = i + 1;
            }
        }

        return start == gas.size() || sum + min < 0 ? -1 : start;

    }
