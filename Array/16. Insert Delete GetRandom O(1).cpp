// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet
{
public:
    unordered_map<int, int> ump;
    vector<int> nums;

    RandomizedSet()
    {
    }

    bool insert(int val)
    {

        if (ump.find(val) != ump.end())
            return false;

        nums.push_back(val);
        ump[val] = nums.size() - 1;

        return true;
    }

    bool remove(int val)
    {

        if (ump.find(val) == ump.end())
            return false;

        int idx = ump[val];
        int last = nums.back();
        nums[idx] = last;
        ump[last] = idx;
        ump.erase(val);
        nums.pop_back();
        return true;
    }

    int getRandom()
    {

        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */