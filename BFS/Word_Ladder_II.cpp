#include<string>
#include<unordered_set>
#include<vector>
#include<map>
#include<queue>

using namespace std;

void buildSolutionGraph(string start, string end, unordered_set<string> &dict, map<string, vector<string> > &pred)
    {
        map<string, int> level;
        queue<string> workingQ;

        workingQ.push(start);
        level.insert(pair<string,int>(start,1));

        int i = 0, j = 0, cnt1 = 1, cnt2 = 0, max = -1, cur_level = 1;
        string cur, nbd;


        while(workingQ.empty() == false)
        {
            cur = workingQ.front();
            workingQ.pop();
            cnt1--;

            //find all neighbors
            for(i = 0; i < cur.size(); i++)
            {
                nbd = cur;
                for(j = 0; j < 26; j++)
                {
                    nbd[i] = 'a' + j;

                    if(dict.find(nbd) == dict.end()) continue;

                    //the neighbor is in the upper level
                    if(level.find(nbd) != level.end() && level[nbd] < cur_level + 1)
                    {
                        continue;
                    }

                    if(level.find(nbd) == level.end())
                    {
                        workingQ.push(nbd);
                        level.insert(pair<string,int>(nbd,cur_level+1));
                        cnt2++;

                        //find the target!
                        if(nbd == end)
                        {
                            max = cur_level + 1;
                        }
                    }

                    //add edges to solution graph
                    if(pred.find(nbd) == pred.end())
                    {
                        vector<string> temp;    temp.push_back(cur);
                        pred.insert(pair<string, vector<string> >(nbd, temp));
                    }else{
                        pred[nbd].push_back(cur);
                    }


                }
            }

            //goto next level
            if(cnt1 == 0 && cnt2 != 0)
            {
                cnt1 = cnt2; cnt2 = 0; cur_level++;
                if(max != - 1 && cur_level == max) break;
            }
        }//while

    }//buildSolutionGraph

    //graph traverse using recursive DFS
    void graphTraverse(string start, map<string, vector<string>> &pred, vector<vector<string>> &ret, vector<string> &path)
    {
        if(path[0] == start)
        {
            ret.push_back(path);
            return;
        }

        vector<string> pred_list = pred[path[0]];

        for(int i = 0; i < pred_list.size(); i++)
        {
            path.insert(path.begin(),pred_list[i]);
            graphTraverse(start, pred, ret, path);
            path.erase(path.begin());
        }

    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {

        vector<vector<string>> ret;
        vector<string> path;

        if(start == end)
        {
            path.push_back(start);
            path.push_back(end);
            ret.push_back(path);
            return ret;
        }

        map<string, vector<string> > pred;
        buildSolutionGraph(start, end, dict, pred);


        path.push_back(end);
        graphTraverse(start, pred, ret, path);

        return ret;

    }
