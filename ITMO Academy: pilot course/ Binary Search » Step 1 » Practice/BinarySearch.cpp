// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
#include <bits/stdc++.h>

using namespace std;

void binary_search(int *arr, int target, int l, int r)
{

    int mid = (r + l) / 2;

    if (l > r)
    {
        cout << "NO\n";
        return;
    }

    if (arr[mid] == target)
    {
        cout << "YES\n";
        return;
    }
    else if (arr[mid] > target)
    {
        binary_search(arr, target, l, mid - 1);
    }
    else if (arr[mid] < target)
    {
        binary_search(arr, target, mid + 1, r);
    }
}

int main()
{

    int n, k, target;

    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < k; i++)
    {
        cin >> target;
        binary_search(arr, target, 0, n - 1);
    }

    return 0;
}