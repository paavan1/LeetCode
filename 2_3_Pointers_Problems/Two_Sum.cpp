#include<vector>
#include<map>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {

        map<int,int> exist;

        vector<int> ret;

        for(int i = 0; i < numbers.size(); i++)
        {
            if(exist.find(target - numbers[i]) != exist.end())
            {
                ret.push_back(exist[target - numbers[i]]);
                ret.push_back(i+1);
                return ret;
            }

            if(exist.find(numbers[i]) == exist.end())
            {
                exist.insert(pair<int,int>(numbers[i], i+1));
            }
        }

        return ret;
    }
