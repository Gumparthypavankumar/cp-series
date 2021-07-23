#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, cows;
int positions[N];

/*
    Problem Link: https://www.spoj.com/problems/AGGRCOW/
    Approach: 
    For Each Distance place cow at beginning position and in every iteration check whether the distance between lastcow and current position is greater than minimum distance because only then we will be able to place the cow if yes decrement the count of cows because we are placing that cow at given position and assign current position to lastCowPos. After traversing all the positions check if count of cows is 0 if yes that means all th cows are placed else return false
*/
bool canPlaceCows(int minDist) {
    int lastCowPos = -1;
    int cows_ct = cows;
    for (int i = 0; i < n; i++) {
        if ((positions[i] - lastCowPos >= minDist) || (lastCowPos == -1)) {
            lastCowPos = positions[i];
            cows_ct--;
        }
        if (cows_ct == 0)
            break;
    }
    return cows_ct == 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> cows;
        for (int i = 0; i < n; i++) {
            cin >> positions[i];
        }
        sort(positions, positions + n);
        int low = 0, high = 1e9, mid;
        while (high - low > 1) {
            mid = (low + high) / 2;
            if (canPlaceCows(mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        if (canPlaceCows(high)) {
            cout << high << endl;
        } else {
            cout << low << endl;
        }
    }
    return 0;
}