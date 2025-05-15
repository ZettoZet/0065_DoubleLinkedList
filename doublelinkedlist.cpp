#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan NIM: ";
        cin >> nim;

        // Step 1: Allocate memory for new node
        Node *newNode = new Node();

        // step 2: Assign value to the data fields
        newNode->noMhs = nim;

        // step 3: Insert at beginning if list is empty or nim is smallest
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\n NIM sudah ada" << endl;
                return;
            }
            // step 4: newNode.next = START
            newNode->next = START;

            // step 5: START.prev = newNode (if START exists)
            if (START != NULL)
            {
                START->prev = newNode;
            }

            // step 6: newNode.prev = NULL
            newNode->prev = NULL;

            // step 7: START = newNode
            START = newNode;
            return;
        }

        // insert in between Node
        // Step 8: Locate position for insertion

        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nNIM tidak boleh duplikat" << endl;
            return;
        }

        // Step 9 : Insert between current and current->next
        newNode->next = current->next; // Step 9a : newNode.next = current.next
        newNode->prev = current;       // step 9b : newNode.prev = current

        // insert last node
        if (current->next != NULL)
        {
            current->next->prev = newNode; // step 9c : current.next.prev = newNode
        }
        current->next = newNode; // step 9d: current.next = newNode
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nMasukkan NIM yang akan dihapus: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        // Step1: Search for the node to be deleted
        while (current != NULL && current->noMhs != rollNo)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "\nNIM tidak ditemukan" << endl;
            return;
        }

        // Step 2: If node is at the beginning
        if (current == START)
        {
            START = current->next; // step 2a : START = START.next
            if (START != NULL)
            {
                START->prev = NULL; // step 2b : START.prev = NULL
            }
        }
        else
        {
            // Step 3 : Link previous node to next of current
            current->prev->next = current->next;

            // Step 4 : If current is not the last node
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
        }
        // Step 5 : Delete the node
        delete current;

        cout << "\nNIM " << rollNo << " berhasil dihapus" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // Step 1: Mark first node as currentNode
        Node *currentNode = START;

        // Step2: Repeat until currentNode == NULL
        cout << "\nData Mahasiswa yang ada di dalam list adalah: " << endl;
        int i = 0;

        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << endl;

            // Step 3: Move to next node
            currentNode = currentNode->next;
            i++;
        }
    }

    void revtraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // Step 1: Move to last node
        Node *currentNode = START;
        int i = 0;
        while (currentNode = START)
        {
            currentNode = currentNode->next;
            i++;
        }

        // Step 2: Traverse backward
        cout << "\n Data mahasiswa yang ada di dalam list dalam urutan terbalik adalah: " << endl;
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            // Step 3: Move to previous node
            currentNode = currentNode->prev;
            i--;
        }
    }

    void searchData()
    {
        
    }
};