// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    cin >> k;

    int l, r;
    for (int i = 0; i < k; i++)
    {
        cin >> l >> r;
        auto indexL = lower_bound(arr, arr + n, l);
        auto indexR = upper_bound(arr, arr + n, r);
        cout << indexR - indexL << " ";
    }

    return 0;
}
