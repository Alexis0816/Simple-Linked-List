#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    int value;
    Node<T> *next;
};

template <class T>
class LinkedList
{
private:
    Node<T> *head;
    int nodes{};

public:
    LinkedList() : head(nullptr), nodes(0) {}
    ~LinkedList() {}

    T front() { return head->value; }

    T back()
    {
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp->value;
    }

    void push_front(T val)
    {
        auto *newNode = new Node<T>;
        newNode->value = val;
        newNode->next = head;
        head = newNode;
        nodes++;
    }

    void push_back(T val)
    {
        auto *newNode = new Node<T>;
        newNode->next = nullptr;
        newNode->value = val;
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        nodes++;
    }

    int size() { return nodes; }

    void display()
    {
        auto *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void clear()
    {
        while (head != nullptr)
        {
            Node<T> *temp = head; // temp = save head
            head = head->next;    // update head
            delete temp;          // bye nodo inicial
        }
        nodes = 0;
    }

    Node<T> *getMiddle(Node<T> *head)
    {
        if (!head)
        {
            return nullptr;
        }
        auto slow = head;
        auto fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node<T> *merge(Node<T> *left, Node<T> *right)
    {
        if (!left || !right)
        {
            return !left ? right : left;
        }

        Node<T> *result = nullptr;
        if (left->value <= right->value)
        {
            result = left;
            result->next = merge(left->next, right);
        }
        else
        {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    Node<T> *mergeSort(Node<T> *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        Node<T> *middleNode = getMiddle(head);
        auto a = head;
        auto b = middleNode->next;
        middleNode->next = nullptr;

        a = mergeSort(a);
        b = mergeSort(b);
        return merge(a, b);
    }

    void sort()
    {
        head = mergeSort(head);
    }

    bool is_empty() { return !head; }

    T &operator<<(int pos)
    {
        auto *temp = head;
        for (int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }
        return temp->value;
    }

    void reverse()
    {
        Node<T> *prev = nullptr, *current = head, *now;
        while (current != nullptr)
        {
            now = current->next;
            current->next = prev;
            prev = current;
            current = now;
        }
        head = prev;
    }
};

int main()
{
    LinkedList<int> head;
    head.push_front(10);
    head.push_front(20);
    head.display();
    cout << head.size() << endl;
    head.push_front(30);
    head.push_front(40);
    head.push_front(50);
    head.display();
    cout << head.size() << endl;
    head.push_back(100);
    head.display();
    cout << head.size() << endl;

    cout << head.front() << endl;
    cout << head.back() << endl;

    head.sort();
    head.display();

    head.reverse();
    head.display();
    
    return 0;
}