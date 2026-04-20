/*#include <iostream>
using namespace std;

class Graph
{
    int cost[10][10];
    int n;

public:
    Graph();
    void create();
    void display();
    void prims();
};


Graph::Graph()
{
    cout << "Enter total number of cities: ";
    cin >> n;
}

void Graph::create()
{
    cout << "Enter cost matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
}


void Graph::prims()
{
    int nearest[10];
    int t[10][2];
    int mincost = 0;
    int u = 0; //u is the starting vertex

    for(int i = 0; i < n; i++)
        nearest[i] = u;

    nearest[u] = -1;  

    for(int i = 0; i < n - 1; i++)
    {
        int min = 9999;
        int j = -1;
        
        for(int k = 0; k < n; k++)
        {
            if(nearest[k] != -1 &&
               cost[k][nearest[k]] < min)
            {
                min = cost[k][nearest[k]];
                j = k;
            }
        }

        t[i][0] = j;
        t[i][1] = nearest[j];

        mincost += cost[j][nearest[j]];

        nearest[j] = -1; 

        for(int k = 0; k < n; k++)
        {
            if(nearest[k] != -1 &&
               cost[k][j] < cost[k][nearest[k]])
            {
                nearest[k] = j;
            }
        }
    }

   cout << "\nMinimum Spanning Tree:\n";
cout << "Edge \tWeight\n";

for(int i = 0; i < n - 1; i++)
{
    cout << t[i][0] << " - " << t[i][1] 
         << "\t" << cost[t[i][0]][t[i][1]] << endl;
}

cout << "\nTotal Minimum Cost = " << mincost << endl;

}
void Graph::display()
{
    cout << "\nCost Matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    Graph g;
    g.create();
    g.display();
    g.prims();
    return 0;
}
*/
#include <iostream>
using namespace std;
class graph
{
    int cost[10][10];
    int n;

public:
    graph();
    void create();
    void display();
    void prims(int v);
};

graph::graph() {
    cout << "\nEnter Total cities: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = 999;
        }
    }
}

void graph::create() {
    char c;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "\nDo you have an edge between vertex "
            << i << " and vertex " << j << "? (y/n): ";
            cin >> c;
            if (c == 'y' || c == 'Y') {
                cout << "Enter the cost: ";
                cin >> cost[i][j];
                cost[j][i] = cost[i][j];
            }
        }
    }
}

void graph::prims(int v) {
    int nearest[10];
    int t[10][3];
    int min_cost = 0;
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (i == v)
            nearest[i] = -1;
        else
            nearest[i] = v;
    }

    for (int i = 0; i < n - 1; i++) {

        int min = 999;
        int j = -1;

        for (int k = 0; k < n; k++) {
            if (nearest[k] != -1 &&
                cost[k][nearest[k]] < min) {

                min = cost[k][nearest[k]];
                j = k;
            }
        }

        t[r][0] = nearest[j];
        t[r][1] = j;
        t[r][2] = min;

        min_cost += min;
        r++;

        nearest[j] = -1;

        for (int k = 0; k < n; k++) {
            if (nearest[k] != -1 &&
                cost[k][j] < cost[k][nearest[k]]) {

                nearest[k] = j;
            }
        }
    }

    cout << "\nMinimum Spanning Tree Edges:\n";
    for (int i = 0; i < r; i++) {
        cout << t[i][0] << " - " << t[i][1]
             << "  [Cost: " << t[i][2]<<"]"<< endl;
    }

    cout << "\n TCM= " << min_cost << endl;
}


	
void graph::display() {
    cout << "\nAdjacency Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << cost[i][j] << "\t";
        }
        cout << endl;
    }
}
int main() {
    graph g;
    int v;
    g.create();
    g.display();
    cout << "\nEnter the starting vertex: ";
    cin >> v;
    g.prims(v);
    return 0;
}