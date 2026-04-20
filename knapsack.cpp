#include <iostream>
using namespace std;

class Knapsack
{
private:
    int n, W;
    int weight[50], profit[50];
    int dp[50][50];

public:
    void input()
    {
        cout << "Enter number of items: ";
        cin >> n;

        cout << "Enter weights:\n";
        for (int i = 1; i <= n; i++)
            cin >> weight[i];

        cout << "Enter profits:\n";
        for (int i = 1; i <= n; i++)
            cin >> profit[i];

        cout << "Enter capacity: ";
        cin >> W;
    }

    void solve()
    {
       
        for (int w = 0; w <= W; w++)
            dp[0][w] = 0;

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        
        for (int i = 1; i <= n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                if (weight[i] <= w)
                {
                    dp[i][w] = max(profit[i] + dp[i - 1][w - weight[i]],
                                   dp[i - 1][w]);
                }
                else
                {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
    }

    void display()
    {
        cout << "\nDP Table:\n";
        for (int i = 0; i <= n; i++)
        {
            for (int w = 0; w <= W; w++)
                cout << dp[i][w] << " ";
            cout << endl;
        }

        cout << "\nMaximum Profit: " << dp[n][W] << endl;
    }

    void findItems()
    {
        int x[50] = {0};
        int i = n, w = W;

        while (i > 0 && w > 0)
        {
            if (dp[i][w] != dp[i - 1][w])
            {
                x[i] = 1;              // item selected
                w = w - weight[i];
            }
            else
            {
                x[i] = 0;              // item not selected
            }
            i--;
        }

        cout << "\nSelected items (x1 x2...):\n";
        for (int j = 1; j <= n; j++)
            cout << x[j] << " ";
        cout << endl;
    }
};

int main()
{
    Knapsack k;

    k.input();
    k.solve();
    k.display();
    k.findItems();

    return 0;
}