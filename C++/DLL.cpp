// // doubly linked list
// Write a menu driven program to perform the following on a doubly linked listi.)Insert an element at the rear end of the listii.)Delete an element from the rear end of the listiii.)Insert an element at a given position of the listiv.)Delete an element from a given position of the list
// DS LAB MANUAL                                                              32| P a g ev.)Insert an element after another elementvi.)Insert an element before another elementvii.)Traverse the listviii.)Reverse the lis

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};

class DLL
{
private:
    node *head;
    node *tail;

public:

    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse()
    {
        node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void insertAt(int pos, int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;

        if (pos == 1)
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        else
        {
            node *temp1 = head;
            for (int i = 0; i < pos - 2; i++)
            {
                temp1 = temp1->next;
            }
            temp->next = temp1->next;
            temp1->next->prev = temp;
            temp1->next = temp;
            temp->prev = temp1;
        }
    }

    void deleteAt(int pos)
    {
        if (pos == 1)
        {
            node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
        else
        {
            node *temp = head;
            for (int i = 0; i < pos - 2; i++)
            {
                temp = temp->next;
            }
            node *temp1 = temp->next;
            temp->next = temp1->next;
            temp1->next->prev = temp;
            delete temp1;
        }
    }

    void insertAfter(int pos, int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;

        node *temp1 = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next->prev = temp;
        temp1->next = temp;
        temp->prev = temp1;
    }

    void insertBefore(int pos, int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;

        node *temp1 = head;
        for (int i = 0; i < pos - 2; i++)
        {
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next->prev = temp;
        temp1->next = temp;
        temp->prev = temp1;
    }


};

int main()
{
    DLL d;
    int choice, data, pos;
    while (1)
    {
        cout << "1. Insert at rear end" << endl;
        cout << "2. Delete at rear end" << endl;
        cout << "3. Insert at given position" << endl;
        cout << "4. Delete at given position" << endl;
        cout << "5. Insert after given position" << endl;
        cout << "6. Insert before given position" << endl;
        cout << "7. Traverse" << endl;
        cout << "8. Reverse" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            d.insert(data);
            break;
        case 2:
            d.deleteAt(1);
            break;
        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter data: ";
            cin >> data;
            d.insertAt(pos, data);
            break;
        case 4:
            cout << "Enter position: ";
            cin >> pos;
            d.deleteAt(pos);
            break;
        case 5:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter data: ";
            cin >> data;
            d.insertAfter(pos, data);
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter data: ";
            cin >> data;
            d.insertBefore(pos, data);
            break;
        case 7:
            d.display();
            break;
        case 8:
            d.reverse();
            break;
        case 9:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}