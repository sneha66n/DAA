#include<iostream>
#include<fstream>
using namespace std;

class record
{
    int rollno, marks;
    char name[20];
    friend class student;
};

class hashing
{
    int rollno, pos;
public:
    hashing()
    {
        rollno = -1;
        pos = -1;
    }
    friend class student;
};

class student
{
    record rec;
    hashing h[10];
    int s, relt;

public:
    student();
    void create_wor();
    void create_wr();
    void modify();
    void retrieve();
    void delete_rec();
    void display();
    void displayall();
};

// Constructor
student::student()
{
    s = sizeof(record);
    relt = 0;
    for (int i = 0; i < 10; i++)
    {
        h[i].rollno = -1;
        h[i].pos = -1;
    }
}

// Without Replacement
void student::create_wor()
{
    fstream f("student.txt", ios::binary | ios::app | ios::out);
    char ans;
    int loc;

    do
    {
        cout << "\nEnter Roll No: ";
        cin >> rec.rollno;
        cout << "Enter Name: ";
        cin >> rec.name;
        cout << "Enter Marks: ";
        cin >> rec.marks;

        loc = rec.rollno % 10;

        if (h[loc].rollno == -1)
        {
            h[loc].rollno = rec.rollno;
            h[loc].pos = relt;
        }
        else
        {
            for (int i = 1; i < 10; i++)
            {
                int newloc = (loc + i) % 10;
                if (h[newloc].rollno == -1)
                {
                    h[newloc].rollno = rec.rollno;
                    h[newloc].pos = relt;
                    break;
                }
            }
        }

        f.write((char*)&rec, s);
        relt++;

        cout << "\nAdd more? (y/n): ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    f.close();
}

// With Replacement
void student::create_wr()
{
    fstream f("student.txt", ios::binary | ios::app | ios::out);
    char ans;
    int loc;

    do
    {
        cout << "\nEnter Roll No: ";
        cin >> rec.rollno;
        cout << "Enter Name: ";
        cin >> rec.name;
        cout << "Enter Marks: ";
        cin >> rec.marks;

        loc = rec.rollno % 10;

        if (h[loc].rollno == -1)
        {
            h[loc].rollno = rec.rollno;
            h[loc].pos = relt;
        }
        else
        {
            for (int i = 1; i < 10; i++)
            {
                int newloc = (loc + i) % 10;
                if (h[newloc].rollno == -1)
                {
                    h[newloc].rollno = rec.rollno;
                    h[newloc].pos = relt;
                    break;
                }
            }
        }

        f.write((char*)&rec, s);
        relt++;

        cout << "\nAdd more? (y/n): ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    f.close();
}

// Retrieve
void student::retrieve()
{
    fstream f("student.txt", ios::binary | ios::in);

    int roll;
    cout << "\nEnter Roll No to search: ";
    cin >> roll;

    record temp;
    bool found = false;

    while (f.read((char*)&temp, s))
    {
        if (temp.rollno == roll)
        {
            cout << "\nRecord Found:\n";
            cout << temp.rollno << "\t" << temp.name << "\t" << temp.marks << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nRecord not found!\n";

    f.close();
}

// Modify
void student::modify()
{
    fstream f("student.txt", ios::binary | ios::in | ios::out);

    int roll;
    cout << "\nEnter Roll No to modify: ";
    cin >> roll;

    record temp;

    while (f.read((char*)&temp, s))
    {
        if (temp.rollno == roll)
        {
            cout << "\nEnter New Data:\n";
            cout << "Roll No: ";
            cin >> temp.rollno;
            cout << "Name: ";
            cin >> temp.name;
            cout << "Marks: ";
            cin >> temp.marks;

            f.seekp(-s, ios::cur);
            f.write((char*)&temp, s);
            cout << "\nRecord Updated!\n";
            break;
        }
    }

    f.close();
}

// Delete
void student::delete_rec()
{
    fstream f("student.txt", ios::binary | ios::in);
    fstream t("temp.txt", ios::binary | ios::out);

    int roll;
    cout << "\nEnter Roll No to delete: ";
    cin >> roll;

    record temp;

    while (f.read((char*)&temp, s))
    {
        if (temp.rollno != roll)
            t.write((char*)&temp, s);
    }

    f.close();
    t.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    cout << "\nRecord Deleted!\n";
}

// Display single
void student::display()
{
    cout << rec.rollno << "\t" << rec.name << "\t" << rec.marks << endl;
}

// Display all
void student::displayall()
{
    fstream f("student.txt", ios::binary | ios::in);
    record temp;

    cout << "\nRollNo\tName\tMarks\n";

    while (f.read((char*)&temp, s))
    {
        cout << temp.rollno << "\t" << temp.name << "\t" << temp.marks << endl;
    }

    f.close();
}

// Main
int main()
{
    student s;
    int ch;
    char ans;

    do
    {
        cout << "\n1.Create WOR\n2.Create WR\n3.Retrieve\n4.Modify\n5.Delete\n6.Display All\n7.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1: s.create_wor(); break;
            case 2: s.create_wr(); break;
            case 3: s.retrieve(); break;
            case 4: s.modify(); break;
            case 5: s.delete_rec(); break;
            case 6: s.displayall(); break;
            case 7: return 0;
            default: cout << "Invalid choice\n";
        }

        cout << "\nContinue? (y/n): ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    return 0;
}