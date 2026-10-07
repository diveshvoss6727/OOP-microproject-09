#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    float marks;

public:

    void setRecord(int roll, string studentName, float studentMarks)
    {
        rollNo = roll;
        name = studentName;
        marks = studentMarks;
    }

    void input()
    {
        cout << "Enter Roll No: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display()
    {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks << endl;
    }

    int getRollNo()
    {
        return rollNo;
    }

    void update()
    {
        cout << "Enter New Name: ";
        cin >> name;

        cout << "Enter New Marks: ";
        cin >> marks;

        cout << "Record Updated Successfully!\n";
    }
};

int main()
{
    Student s[50];
    s[0].setRecord(1, "Archit", 77);
    s[1].setRecord(2, "Aarav", 84);
    s[2].setRecord(3, "Diya", 91);
    s[3].setRecord(4, "Kabir", 76);
    s[4].setRecord(5, "Meera", 88);
    s[5].setRecord(6, "Ishaan", 69);
    s[6].setRecord(7, "Anaya", 95);
    s[7].setRecord(8, "Rohan", 73);
    s[8].setRecord(9, "Sana", 82);
    s[9].setRecord(10, "Vikram", 79);

    int choice, n = 10, roll, found;

    do
    {
        cout << "\n===== SMART STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                if(n >= 50)
                {
                    cout << "Storage full! Cannot add more students.\n";
                    break;
                }
                s[n].input();
                n++;
                cout << "Student Added Successfully!\n";
                break;

            case 2:
                if(n == 0)
                    cout << "No records found!\n";
                else
                {
                    for(int i = 0; i < n; i++)
                    {
                        s[i].display();
                    }
                }
                break;

            case 3:
                cout << "Enter Roll No to Search: ";
                cin >> roll;

                found = 0;

                for(int i = 0; i < n; i++)
                {
                    if(s[i].getRollNo() == roll)
                    {
                        s[i].display();
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    cout << "Student Not Found!\n";

                break;

            case 4:
                cout << "Enter Roll No to Update: ";
                cin >> roll;

                found = 0;

                for(int i = 0; i < n; i++)
                {
                    if(s[i].getRollNo() == roll)
                    {
                        s[i].update();
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    cout << "Student Not Found!\n";

                break;

            case 5:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}
