#include <iostream>
#include <cmath>
using namespace std;

class Nqueen {
private:
    int x[20];   

public:
    void queen(int k, int n) {
        for (int i = 1; i <= n; i++) {
            if (place(k, i)) {
                x[k] = i;
                if (k == n) {
                    display(n);  
                } else {
                    queen(k + 1, n);
                }
            }
        }
    }

    bool place(int k, int i) {
        for (int j = 1; j < k; j++) {
            if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
                return false;
            }
        }
        return true;
    }

    void display(int n) {
        cout << "Solution: ";
        for (int i = 1; i <= n; i++) {
            cout << x[i] << " ";
            
        }
        cout << endl;
    }
};

int main()
{
    Nqueen obj;
    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    obj.queen(1, n);

    return 0;
}