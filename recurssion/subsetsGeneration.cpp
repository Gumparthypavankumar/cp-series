#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> allSubsets;

void generate(vector<int> &subsets, int index, vector<int> &nums)
{
    /*
            given = [1,2,3]
            algorithm:
             start with empty array
            step1 : iterate through array
            step2 : In each iteration consider the element or don't consider the element
            
                         []
                /                  \
              [1]                    []
           /       \              /      \
         [1,2]        [1]        [2]     []
        /     \      /   \      /   \    / \
      [1,2,3] [1,2] [1,3] [1] [2,3] [2] [3] [] // subsets
    */

    if (index == nums.size())
    {
        allSubsets.push_back(subsets);
        return;
    }

    // Not include the element at index
    generate(subsets, index + 1, nums);

    // include the element at index
    subsets.push_back(nums[index]);
    generate(subsets, index + 1, nums);
    subsets.pop_back();
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> empty;
    generate(empty, 0, nums);
    return allSubsets;
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