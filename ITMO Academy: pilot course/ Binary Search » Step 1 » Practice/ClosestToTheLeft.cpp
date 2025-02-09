// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;

    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while (k--)
    {
        int l = -1, r = n;
        int target;
        cin >> target;
        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] <= target)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        cout << (l + 1) << "\n";
    }

    return 0;
}
