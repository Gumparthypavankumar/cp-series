#include <bits/stdc++.h>
using namespace std;

// This sorts in ascending order
void selection_sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i; // Minimum index till this point we always assume the curr position as minimum
        for (int j = i + 1; j < n; j++) {
            if (a[minIndex] > a[j]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    selection_sort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
