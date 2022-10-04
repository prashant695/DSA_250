// https://leetcode.com/problems/merge-intervals/

// Method - 1
// Using Stack
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end());
        stack<vector<int>> st;
        vector<vector<int>> res;
        for (int i = 0; i < v.size(); i++)
        {
            if (st.empty() == true)
                st.push({v[i][0], v[i][1]});
            else if (v[i][0] <= st.top()[1] && v[i][1] >= st.top()[1])
            {
                int x = st.top()[0];
                st.pop();
                st.push({x, v[i][1]});
            }
            else if (v[i][0] <= st.top()[1] && v[i][1] < st.top()[1])
            {
            }
            else if (v[i][0] > st.top()[1])
                st.push({v[i][0], v[i][1]});
        }
        while (st.empty() == false)
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};

// Method - 2
// No auxillary space
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end());
        int l1 = v[0][0];
        int r1 = v[0][1];

        vector<vector<int>> res;

        for (int i = 1; i < v.size(); i++)
        {
            int l2 = v[i][0];
            int r2 = v[i][1];
            // for overlapping
            if (r1 >= l2)
                r1 = max(r1, r2);
            // for non-overlapping
            else
            {
                res.push_back({l1, r1});
                l1 = l2;
                r1 = r2;
            }
        }

        res.push_back({l1, r1});
        return res;
    }
};