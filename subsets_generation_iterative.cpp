#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    for (int i = 0; i < (1 << nums.size()); i++)
    {
        vector<int> temp;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i & (1 << j))
            {
                temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        nums.push_back(k);
    }
    vector<vector<int>> result = subsets(nums);
    for (auto subset : result)
    {
        cout << "[";
        for (auto elem : subset)
        {
            cout << elem << ",";
        }
        cout << "]"
             << ",";
    }
    return 0;
}