#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Node for adjacency list
class gnode {
public:
    int vertex;
    gnode *next;
};

// Graph class
class graph {
    gnode *head[20];
    int visited[20];
    int n;

public:
    // Constructor
    graph() {
        cout << "Enter number of vertices: ";
        cin >> n;

        for(int i = 0; i < n; i++) {
            head[i] = new gnode;
            head[i]->vertex = i;
            head[i]->next = NULL;
        }
    }

    // Create graph
    void create() {
        int v;
        char ans;
        gnode *temp, *curr;

        for(int i = 0; i < n; i++) {
            temp = head[i];
            do {
                cout << "Enter adjacent vertex of " << i << ": ";
                cin >> v;

                if(v == i) {
                    cout << "Self loop not allowed\n";
                } else {
                    curr = new gnode;
                    curr->vertex = v;
                    curr->next = NULL;

                    temp->next = curr;
                    temp = temp->next;
                }

                cout << "Add more? (y/n): ";
                cin >> ans;

            } while(ans == 'y' || ans == 'Y');
        }
    }

    // Reset visited array
    void resetVisited() {
        for(int i = 0; i < n; i++)
            visited[i] = 0;
    }

    // DFS Recursive
    void DFS_recursive(int v) {
        cout << v << " ";
        visited[v] = 1;

        gnode *temp = head[v]->next;

        while(temp != NULL) {
            int w = temp->vertex;
            if(!visited[w])
                DFS_recursive(w);
            temp = temp->next;
        }
    }

    void DFS_start() {
        int v;
        resetVisited();
        cout << "Enter starting vertex for DFS (recursive): ";
        cin >> v;
        DFS_recursive(v);
    }

    // DFS using Stack
    void DFS_stack(int v) {
        resetVisited();
        stack<int> s;

        s.push(v);
        visited[v] = 1;

        while(!s.empty()) {
            v = s.top();
            s.pop();
            cout << v << " ";

            gnode *temp = head[v]->next;
            while(temp != NULL) {
                int w = temp->vertex;
                if(!visited[w]) {
                    s.push(w);
                    visited[w] = 1;
                }
                temp = temp->next;
            }
        }
    }

    // BFS using Queue
    void BFS(int v) {
        resetVisited();
        queue<int> q;

        q.push(v);
        visited[v] = 1;

        while(!q.empty()) {
            v = q.front();
            q.pop();
            cout << v << " ";

            gnode *temp = head[v]->next;
            while(temp != NULL) {
                int w = temp->vertex;
                if(!visited[w]) {
                    q.push(w);
                    visited[w] = 1;
                }
                temp = temp->next;
            }
        }
    }
};

// Main function
int main() {
    graph g;
    g.create();

    cout << "\nDFS Recursive: ";
    g.DFS_start();

    int start;

    cout << "\nEnter starting vertex for DFS (Stack): ";
    cin >> start;
    cout << "DFS using Stack: ";
    g.DFS_stack(start);

    cout << "\nEnter starting vertex for BFS: ";
    cin >> start;
    cout << "BFS Traversal: ";
    g.BFS(start);

    return 0;
}