#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;

        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    unsigned long count;

public:
    List() : head(nullptr), tail(nullptr), count(0) {}

    ~List()
    {
        while (head)
            pop_front();
    }

    class Iterator
    {
    private:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}

        T& operator*() { return current->data; }

        Iterator& operator++()
        {
            current = current->next;
            return *this;
        }

        Iterator& operator--()
        {
            current = current->prev;
            return *this;
        }

        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return current != other.current; }

        Node* getNode() const { return current; }
    };

    void push_front(const T& value)
    {
        Node* node = new Node(value);

        if (!head)
        {
            head = tail = node;
        }
        else
        {
            node->next = head;
            head->prev = node;
            head = node;
        }

        count++;
    }

    void push_back(const T& value)
    {
        Node* node = new Node(value);

        if (!tail)
        {
            head = tail = node;
        }
        else
        {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }

        count++;
    }

    void pop_front()
    {
        if (!head) return;

        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;

        delete temp;
        count--;
    }

    void pop_back()
    {
        if (!tail) return;

        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;

        delete temp;
        count--;
    }

    void insert(Iterator pos, const T& value)
    {
        Node* current = pos.getNode();
        if (!current)
        {
            push_back(value);
            return;
        }
        if (current == head)
        {
            push_front(value);
            return;
        }

        Node* node = new Node(value);
        node->next = current;
        node->prev = current->prev;
        current->prev->next = node;
        current->prev = node;
        count++;
    }

    T& front() { return head->data; }
    T& back() { return tail->data; }
    const T& front() const { return head->data; }
    const T& back() const { return tail->data; }

    unsigned long size() const { return count; }

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};

int main()
{
    List<string> myList;
    myList.push_back("Second");
    myList.push_front("First");
    myList.push_back("Third");

    cout << "List contents:\n";
    for (auto it = myList.begin(); it != myList.end(); ++it)
    {
        cout << *it << endl;
    }

    cout << "\nSize: " << myList.size() << endl;
    cout << "Front: " << myList.front() << ", Back: " << myList.back() << endl;

    myList.pop_front();
    myList.pop_back();
    cout << "\nSize: " << myList.size() << endl;

    cout << "\nList contents:\n";
    for (auto it = myList.begin(); it != myList.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
