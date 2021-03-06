#include<vector>
#include<string>
#include<iostream>
#include<map>

using namespace std;

vector<int> findSubstring2(string S, vector<string> &L) {

        vector<int> ret;

        int m = S.size(), n = L.size(), k = n == 0 ? 0 : L[0].size();

        if(m == 0 || n == 0 || k == 0) return ret;

        map<string, int> stat;

        map<string, int> cnt;

        for(int i = 0; i < n; i++) stat[L[i]]++;

        string cur;

        int start = 0;

        for(int i = 0; i < k; i++)
        {//for different offset

            start = 0;
            cnt.clear();

            for(int j = 0; (j+1)*k + i <= m; j++)
            {//for each word

                cur = S.substr(i+j*k, k);

                if(stat.find(cur) == stat.end())
                {
                    cnt.clear(); start = j + 1;
                }else{
                    cnt[cur]++;

                    if(cnt[cur] > stat[cur])
                    {
                        while(S.substr(i + start*k,k) != cur)
                        {
                            cnt[S.substr(i+start*k,k)]--; start++;
                        }
                        cnt[cur]--; start++;
                    }

                    if(j - start + 1 == n) ret.push_back(i+start*k);
                }//else
            }//for
        }//for

        return ret;
    }

void test()
{
	string S("abaababbaba");
	vector<string> L;
	L.push_back("ab");
	L.push_back("ba");
	L.push_back("ab");
	L.push_back("ba");
	vector<int> ret = findSubstring2(S, L);

	for(unsigned i = 0; i < ret.size(); i++)
	{
		cout<<ret[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	test();
}
