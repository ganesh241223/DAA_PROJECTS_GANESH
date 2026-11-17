
#include <iostream>
#include <algorithm>
using namespace std;

#define N 4
#define INF 999999

int dp[1 << N][N];

int cost[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int tsp(int mask, int pos)
{
    if (mask == (1 << N) - 1)
        return cost[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;

    for (int city = 0; city < N; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newAns = cost[pos][city] +
                         tsp(mask | (1 << city), city);

            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main()
{
    fill(&dp[0][0], &dp[0][0] + (1 << N) * N, -1);

    cout << "Minimum travelling cost: "
         << tsp(1, 0);

    return 0;
}
