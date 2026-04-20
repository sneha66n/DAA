#include<iostream>
#include<string>
using namespace std;

class MobileUser
{
    long int mobileno;
    string name;
    long int billamount;
public:
    MobileUser()
    {
        mobileno = 0;
        name = "";
        billamount = 0;
    }
    friend class Records;
};

class Records
{
    MobileUser M[20], B[20];
    int n;

public:
    Records(int n1)
    {
        n = n1;
    }

    void accept();
    void display();

    // Quick Sort
    int partition(int p, int r);
    void quickSort(int p, int r);

    // Merge Sort
    void mergeSort(int low, int high);
    void merge(int low, int mid, int high);
};

void Records::accept()
{
    for(int i = 0; i < n; i++)
    {
        cout << "Enter mobile number, name and bill amount:\n";
        cin >> M[i].mobileno >> M[i].name >> M[i].billamount;
    }
}

void Records::display()
{
    cout << "\nMobileNo\tName\tBill\n";
    cout << "--------------------------------\n";
    for(int i = 0; i < n; i++)
    {
        cout << M[i].mobileno << "\t" << M[i].name << "\t" << M[i].billamount << endl;
    }
}

// 🔴 Quick Sort
int Records::partition(int p, int r)
{
    long int x = M[r].mobileno;
    int i = p - 1;
    MobileUser temp;

    for(int j = p; j < r; j++)
    {
        if(M[j].mobileno <= x)
        {
            i++;
            temp = M[i];
            M[i] = M[j];
            M[j] = temp;
        }
    }

    temp = M[i + 1];
    M[i + 1] = M[r];
    M[r] = temp;

    return (i + 1);
}

void Records::quickSort(int p, int r)
{
    if(p < r)
    {
        int q = partition(p, r);
        quickSort(p, q - 1);
        quickSort(q + 1, r);
    }
}

// 🔴 Merge Sort
void Records::mergeSort(int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;

        mergeSort(low, mid);
        mergeSort(mid + 1, high);

        merge(low, mid, high);
    }
}

void Records::merge(int low, int mid, int high)
{
    int h = low;
    int i = low;
    int j = mid + 1;
    int k;

    while(h <= mid && j <= high)
    {
        if(M[h].mobileno <= M[j].mobileno)
        {
            B[i] = M[h];
            h++;
        }
        else
        {
            B[i] = M[j];
            j++;
        }
        i++;
    }

    if(h > mid)
    {
        for(k = j; k <= high; k++)
        {
            B[i] = M[k];
            i++;
        }
    }
    else
    {
        for(k = h; k <= mid; k++)
        {
            B[i] = M[k];
            i++;
        }
    }

    for(k = low; k <= high; k++)
    {
        M[k] = B[k];
    }
}

int main()
{
    int n, ch;

    cout << "Enter number of records: ";
    cin >> n;

    Records r(n);
    r.accept();
    r.display();

    do
    {
        cout << "\nMENU";
        cout << "\n1. Quick Sort";
        cout << "\n2. Merge Sort";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                r.quickSort(0, n - 1);
                cout << "\nAfter Quick Sort:\n";
                r.display();
                break;

            case 2:
                r.mergeSort(0, n - 1);
                cout << "\nAfter Merge Sort:\n";
                r.display();
                break;

            case 3:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(ch != 3);

    return 0;
}