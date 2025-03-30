#include <iostream>

class List
{
public:
    List() : head(nullptr), tail(nullptr), theCount(0) {}
    ~List();

    void insert(int value);
    void append(int value);
    int is_present(int value) const;
    int is_empty() const { return head == nullptr; }
    int count() const { return theCount; }

private:
    class ListCell
    {
    public:
        ListCell(int value, ListCell* cell = nullptr)
            : val(value), next(cell) {
        }

        int val;
        ListCell* next;
    };

    ListCell* head;
    ListCell* tail;
    int theCount;
};

List::~List()
{
    while (head != nullptr)
    {
        ListCell* temp = head;
        head = head->next;
        delete temp;
    }
}

void List::insert(int value)
{
    ListCell* newCell = new ListCell(value, head);
    head = newCell;
    if (tail == nullptr)
        tail = head;
    theCount++;
}

void List::append(int value)
{
    ListCell* newCell = new ListCell(value);
    if (tail != nullptr)
    {
        tail->next = newCell;
        tail = newCell;
    }
    else
    {
        head = tail = newCell;
    }
    theCount++;
}

int List::is_present(int value) const
{
    ListCell* current = head;
    while (current != nullptr)
    {
        if (current->val == value)
            return 1;
        current = current->next;
    }
    return 0;
}
