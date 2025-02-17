// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D

#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<int> balloons;
vector<pair<int, pair<int, int>>> assistant;

bool good(int clock)
{
    int acc = 0;
    for (int i = 0; i < n; i++)
    {
        int t = assistant[i].first;
        int z = assistant[i].second.first;
        int y = assistant[i].second.second;

        if (clock < t)
        {
            balloons[i] = 0;
            continue;
        }

        int size_segment = (t * z) + y;
        int quantity_integers = floor(clock / size_segment);
        int quantity_balloons = quantity_integers * z;
        int remaining = clock % size_segment;
        int quantity_remaining = min(remaining, z);

        acc += quantity_balloons + quantity_remaining;

        balloons[i] = quantity_balloons + quantity_remaining;
    }

    return (acc >= m);
}

int main(int argc, char const *argv[])
{
    cin >> m >> n;

    balloons.resize(n + 1);
    assistant.resize(n + 1);

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
        r = r << 1;
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
    for (int i = 0; i < n; i++)
    {
        cout << balloons[i] << " ";
    }

    return 0;
}
