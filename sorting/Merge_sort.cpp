#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int mid, int r) {
    int left_size = mid - l + 1;
    int right_size = r - mid;
    int left[left_size + 1], right[right_size + 1];
    for (int i = 0; i < left_size; i++) {
        left[i] = a[i + l];
    }
    for (int i = 0; i < right_size; i++) {
        right[i] = a[mid + i + 1];
    }
    left[left_size] = right[right_size] = INT_MAX;
    int L = 0, R = 0;
    for (int i = l; i <= r; i++) {
        if (left[L] <= right[R]) {
            a[i] = left[L];
            L++;
        } else {
            a[i] = right[R];
            R++;
        }
    }
}

void Merge_sort(int a[], int l, int r) {
    if (l == r)
        return;
    int mid = (l + r) / 2;
    Merge_sort(a, l, mid);
    Merge_sort(a, mid + 1, r);
    merge(a, l, mid, r);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}