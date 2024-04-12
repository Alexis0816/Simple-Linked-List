#include "ForwardList.hpp"

// testeo
int main()
{
    ForwardList<int> head;
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

    cout << head.pop_back() << endl;
    head.display();

    cout << head.pop_front() << endl;
    head.display();

    return 0;
}