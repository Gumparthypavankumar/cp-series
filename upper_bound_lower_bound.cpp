#include <bits/stdc++.h>
using namespace std;

// Find lower Bound and Upper bound of a number
// Lower bound will return a number that is equal to or greater than given number or else it returns -1
int lower_bound(vector<int> &v, int element) {
    int low = 0, high = v.size() - 1;
    while (high - low > 1) {
        int mid = (high + low) / 2;
        if (v[mid] < element) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    if (v[low] >= element) {
        return low;
    }
    if (v[high] >= element) {
        return high;
    }
    return -1;
}

// Upper bound will only return a number that is greater than given number if not present return -1
int upper_bound(vector<int> &v, int element) {
    int low = 0, high = v.size() - 1;
    while (high - low > 1) {
        int mid = (high + low) / 2;
        if (v[mid] <= element) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    if (v[low] > element) {
        return low;
    }
    if (v[high] > element) {
        return high;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int element;
    cin >> element;
    // Array must be sorted
    sort(a.begin(), a.end());
    int lb = lower_bound(a, element);
    int ub = upper_bound(a, element);
    cout << "Lower Bound : " << (lb != -1 ? a[lb] : -1) << "\n";
    cout << "Upper Bound : " << (ub != -1 ? a[ub] : -1) << "\n";
    return 0;
}