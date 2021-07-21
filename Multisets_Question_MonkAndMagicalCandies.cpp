#include <bits/stdc++.h>
using namespace std;

// Problem link: https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/?fbclid=IwAR2kDiVkEaxu9dkCTCUhzXLuIccNn0Gz3dSfkaSUjlDE6Nb9UHMzt8HNDo4

/*
    Approach: 
    Since in the problem statement it is mentioned that in every iteration we need to pick the largest element so we need to arrange the data in the sorted order after every iteration for picking the largest element in O(1) time complexity if stored in an array but in case of multisets the data is ordered and it can also contain duplicates so with this mentioned we use multisets for storing data
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long ans = 0;
        multiset<long long> bags;
        for (int i = 0; i < n; i++)
        {
            long long candy;
            cin >> candy;
            bags.insert(candy);
        }
        while (k--)
        {
            auto last_it = --bags.end();
            long long value = *last_it;
            ans += value;
            bags.insert(value / 2); // O(log n)
            bags.erase(last_it);    // erase only the last item if we use value then it delets all the elements that matches this value so we use iterator to delete the element in O(1) Complexity
        }
        cout << ans << "\n";
    }
    return 0;
}