// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D

#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<int> balloons;
//           t         z    y
vector<pair<int, pair<int, int>>> assistant;

bool good(int clock)
{
    int acc = 0;
    for (int i = 0; i < n; i++)
    {
        int t = assistant[i].first;
        int z = assistant[i].second.first;
        int y = assistant[i].second.second;

        int segment = (t * z) + y;
        int remaining = (clock % segment);

        int quantity_segment = (clock / segment) * z;
        if (remaining >= t * z)
        {
            quantity_segment += z;
        }
        else
        {
            quantity_segment += (remaining / t);
        }

        acc += quantity_segment;
    }

    return (acc >= m);
}

int main(int argc, char const *argv[])
{
    cin >> m >> n;

    balloons.resize(n);
    assistant.resize(n);

    for (int i = 0; i < n; i++)
    {
        int t, z, y;
        cin >> t >> z >> y;
        assistant[i].first = t;
        assistant[i].second.first = z;
        assistant[i].second.second = y;
    }

    int l = 0, r = 1;

    while (!good(r))
    {
        l = r;
        r << 1;
    }

    while ((l + 1) < r)
    {
        int mid = (r + l) / 2;
        if (good(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    cout << r << "\n";

    return 0;
}
