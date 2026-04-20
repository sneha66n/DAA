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
    MobileUser M[10];
    int n;
public:
    Records(int n1)
    {
        n = n1;
    }
    void accept();
    void display();
    void Linear_search();
    void Binary_search();
    void sort();   // needed for binary search
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

void Records::Linear_search()
{
    string search_name;
    cout << "Enter name to search: ";
    cin >> search_name;

    for(int i = 0; i < n; i++)
    {
        if(M[i].name == search_name)
        {
            cout << "Found:\n";
            cout << M[i].mobileno << "\t" << M[i].name << "\t" << M[i].billamount << endl;
            return;
        }
    }
    cout << "Not found\n";
}

// Sorting by mobile number
void Records::sort()
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(M[i].mobileno > M[j].mobileno)
            {
                MobileUser temp = M[i];
                M[i] = M[j];
                M[j] = temp;
            }
        }
    }
}

void Records::Binary_search()
{
    long int key;
    cout << "Enter mobile number to search: ";
    cin >> key;

    sort();  // mandatory for binary search

    int low = 0, high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(M[mid].mobileno == key)
        {
            cout << "Found:\n";
            cout << M[mid].mobileno << "\t" << M[mid].name << "\t" << M[mid].billamount << endl;
            return;
        }
        else if(key < M[mid].mobileno)
            high = mid - 1;
        else
            low = mid + 1;
    }

    cout << "Not found\n";
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
        cout << "\n1. Linear Search (by name)";
        cout << "\n2. Binary Search (by mobile no)";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                r.Linear_search();
                break;
            case 2:
                r.Binary_search();
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