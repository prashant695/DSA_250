// https://leetcode.com/problems/invalid-transactions/

class Solution
{
public:
    vector<string> invalidTransactions(vector<string> &t)
    {
        vector<string> v;
        vector<string> name;
        vector<int> time;
        vector<int> amt;
        vector<string> city;
        string r = "";
        set<string> ss;
        map<string, int> m;
        int cnt = 0;
        for (int i = 0; i < t.size(); i++)
        {
            m[t[i]]++;
            for (int j = 0; j < t[i].size(); j++)
            {
                if (t[i][j] == ',' || j == t[i].size() - 1)
                {
                    if (j == t[i].size() - 1)
                        r += t[i][j];
                    if (cnt % 4 == 0)
                        name.push_back(r), r = "";
                    else if (cnt % 4 == 1)
                        time.push_back(stoi(r)), r = "";
                    else if (cnt % 4 == 2)
                        amt.push_back(stoi(r)), r = "";
                    else
                        city.push_back(r), r = "";
                    cnt++;
                }
                else
                    r += t[i][j];
            }
        }
        r = "";
        string a = "";
        int sz = ss.size();
        for (int i = 0; i < name.size(); i++)
        {
            for (int j = i + 1; j < name.size(); j++)
            {
                if (name[i] == name[j] && abs(time[i] - time[j]) <= 60 &&
                    city[i] != city[j])
                {
                    sz = ss.size();
                    a = to_string(amt[i]);
                    r += name[i] + ',' + to_string(time[i]) + ',' + a + ',' + city[i];
                    ss.insert(r);
                    if (ss.size() != sz || m[r])
                        v.push_back(r), m[r]--;
                    r = "";
                    r += name[j] + ',' + to_string(time[j]) + ',' + to_string(amt[j]) + ',' + city[j];
                    sz = ss.size();
                    ss.insert(r);
                    if (ss.size() != sz || m[r])
                        v.push_back(r), m[r]--;
                    r = "";
                }
            }
        }
        for (int i = 0; i < name.size(); i++)
        {
            if (name[i] != "1")
            {
                if (amt[i] > 1000)
                {
                    sz = ss.size();
                    r += name[i] + ',' + to_string(time[i]) + ',' + to_string(amt[i]) + ',' + city[i];
                    ss.insert(r);
                    if (ss.size() != sz || m[r])
                        v.push_back(r), m[r]--;
                    r = "";
                }
            }
        }
        return v;
    }
};