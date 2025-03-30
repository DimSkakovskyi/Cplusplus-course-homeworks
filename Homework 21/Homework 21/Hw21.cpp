#include<iostream>
#include<string>

using namespace std;

template <typename T>
class List
{
public:
    List() : head(nullptr), tail(nullptr), theCount(0) {}
    virtual ~List();

    void insert(T value);
    void append(T value);
    bool is_present(T value) const;
    bool is_empty() const { return head == nullptr; }
    int count() const { return theCount; }
    void swap_values(T& a, T& b);

    template <typename T>
    friend bool operator==(const List<T>& lhs, const List<T>& rhs);

private:
    class ListCell
    {
    public:
        ListCell(T value, ListCell* cell = nullptr)
            : val(value), next(cell) {
        }

        T val;
        ListCell* next;
    };

    ListCell* head;
    ListCell* tail;
    int theCount;
};

template <typename T>
List<T>::~List()
{
    while (head != nullptr)
    {
        ListCell* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void List<T>::insert(T value)
{
    ListCell* newCell = new ListCell(value, head);
    head = newCell;
    if (tail == nullptr)
        tail = head;
    theCount++;
}

template <typename T>
void List<T>::append(T value)
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

template <typename T>
bool List<T>::is_present(T value) const
{
    ListCell* current = head;
    while (current != nullptr)
    {
        if (current->val == value)
            return true;
        current = current->next;
    }
    return false;
}

template <typename T>
void swap_values(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
bool operator==(const List<T>& lhs, const List<T>& rhs)
{
    if (lhs.theCount != rhs.theCount)
        return false;

    typename List<T>::ListCell* curr1 = lhs.head;
    typename List<T>::ListCell* curr2 = rhs.head;

    while (curr1 != nullptr && curr2 != nullptr)
    {
        if (!(curr1->val == curr2->val))
            return false;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return true;
}

class Cat
{
public:
    Cat(const string& name = "Unknown", int age = 0)
        : name(name), age(age) {
    }

    // For comparison in is_present
    bool operator==(const Cat& other) const
    {
        return name == other.name && age == other.age;
    }

    void print() const
    {
        cout << "Cat: " << name << ", age: " << age << endl;
    }

private:
    string name;
    int age;
};

int main()
{
    //Strings
    List<string> stringList;
    stringList.append("apple");
    stringList.append("banana");
    stringList.insert("cherry");

    // Cats
    List<Cat> catList;
    catList.append(Cat("Whiskers", 3));
    catList.insert(Cat("Mittens", 2));
    catList.append(Cat("Shadow", 5));

    // Integers
    List<int> intList;
    intList.insert(10);
    intList.append(20);
    intList.insert(5);

    // Перевірка наявності елементів
    cout << "Is 'banana' in stringList? " << stringList.is_present("banana") << endl;
    cout << "Is Cat(\"Shadow\", 5) in catList? " << catList.is_present(Cat("Shadow", 5)) << endl;
    cout << "Is 20 in intList? " << intList.is_present(20) << endl;

    return 0;
}
