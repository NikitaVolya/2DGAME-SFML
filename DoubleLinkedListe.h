#pragma once

#include <iostream>

template <typename T>
class DoubleLinkedList
{
private:
    struct Node
    {
        T value;
        Node* next;
        Node* last;
    };
    Node* head;
    Node* back;
    size_t size;
public:
    class Iterator
    {
    protected:
        Node* corent_node;
    public:
        Iterator(Node* node) : corent_node(node) {};
        Iterator(const Iterator& other) : corent_node(other.corent_node) {};
        Iterator() : corent_node(nullptr) {};

        T& value() { if (!corent_node) throw std::out_of_range("Iterator is out of range"); return corent_node->value; }
        const T& value() const { if (!corent_node) throw std::out_of_range("Iterator is out of range"); return corent_node->value; }

        operator bool() const { return corent_node; }

        virtual void operator++() = 0;

        T* operator->() { return &corent_node->value; }
        const T* operator->() const { return &corent_node->value; }

        T& operator*() { return value(); }
        const T& operator*() const { return value(); }
    };
    class Forward_Iterator : public DoubleLinkedList<T>::Iterator
    {
    public:
        Forward_Iterator(Node* node) : Iterator{ node } {};
        Forward_Iterator(const Iterator& other) : Iterator{ other } {};
        Forward_Iterator() : Iterator{} {}

        void operator++() override
        {
            if (!this->corent_node)
                throw std::out_of_range("Iterator is out of range");
            this->corent_node = this->corent_node->next;
        }
     };
    class Revers_Iterator : public DoubleLinkedList<T>::Iterator
    {
    public:
        Revers_Iterator(Node* node) : Iterator{ node } {};
        Revers_Iterator(const Iterator& other) : Iterator{ other } {};
        Revers_Iterator() : Iterator{} {}

        void operator++() override
        {
            if (!this->corent_node)
                throw std::out_of_range("Iterator is out of range");
            this->corent_node = this->corent_node->last;
        }
    };

    DoubleLinkedList() : head(nullptr), back(nullptr), size(0) {}
    DoubleLinkedList(const std::initializer_list<T>& lst);
    ~DoubleLinkedList() { clear(); }

    void clear();
    bool isClear() const { return !head; }
    size_t lenght() const { return size; }

    T& at(int index);
    const T& at(int index) const;

    T& operator[](int index) { return at(index); }
    const T& operator[](int index) const { return at(index); }

    Forward_Iterator begin() const { return Forward_Iterator(head); }
    Revers_Iterator rbegin() const { return Revers_Iterator(back); }
   
    DoubleLinkedList<T>& add(const T& value);
    DoubleLinkedList<T>& pop();

    DoubleLinkedList<T>& append(const T& value);
    DoubleLinkedList<T>& popend();

    DoubleLinkedList<T>& pop(int index);
    DoubleLinkedList<T>& insert(int index, const T& value);

    T remove(const T& value);

    int find(const T& value) const;

    std::ostream& print(std::ostream& out = std::cout, char endC = '\n') const;
    std::ostream& print(char endC) const { return print(std::cout, endC); }

    std::ostream& rprint(std::ostream& out = std::cout, char endC = '\n') const;
    std::ostream& rprint(char endC) const { return rprint(std::cout, endC); }
};

template<typename T>
inline DoubleLinkedList<T>::DoubleLinkedList(const std::initializer_list<T>& lst) : DoubleLinkedList()
{
    for (int i = 0; i < lst.size(); i++)
        append(*(lst.begin() + i));
}

template<typename T>
inline void DoubleLinkedList<T>::clear()
{
    Node* ptr = head;
    while (ptr)
    {
        Node* tmp = ptr;
        ptr = ptr->next;
        delete tmp;
    }
    size = 0;
    head = nullptr;
    back = nullptr;
}

template<typename T>
inline T& DoubleLinkedList<T>::at(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("index is out of range");

    Node* tmp = head;
    while (index--)
        tmp = tmp->next;
    return tmp->value;
}

template<typename T>
inline const T& DoubleLinkedList<T>::at(int index) const
{
    if (index < 0 || index >= size)
        throw std::out_of_range("index is out of range");

    Node* tmp = head;
    while (index--)
        tmp = tmp->next;
    return tmp->value;
}

template<typename T>
inline DoubleLinkedList<T>& DoubleLinkedList<T>::add(const T& value)
{
    Node* newNode = new Node{ value, head, nullptr };
    if (head)
        head->last = newNode;
    head = newNode;
    if (size++ == 0)
        back = newNode;
    return *this;
}

template<typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::pop()
{
    if (isClear())
        throw std::out_of_range("is clear");
    
    Node* tmp = head;

    head = head->next;
    if (--size == 0)
        back = nullptr;

    delete tmp;
    return *this;
}

template<typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::append(const T& value)
{
    Node* newNode = new Node{ value, nullptr, back };
    if (back)
        back->next = newNode;
    back = newNode;
    if (size++ == 0)
        head = newNode;
    return *this;
}

template<typename T>
inline DoubleLinkedList<T>& DoubleLinkedList<T>::popend()
{
    if (isClear())
        throw std::out_of_range("is clear");

    Node* tmp = back;
    back = back->last;
    back->next = nullptr;
    if (--size == 0)
        head = nullptr;
    delete tmp;
    return *this;
}

template<typename T>
inline DoubleLinkedList<T>& DoubleLinkedList<T>::pop(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("index is out of range");

    Node* tmp = head;
    while (index--)
        tmp = tmp->next;
    if (tmp->last)
        tmp->last->next = tmp->next;
    else
        head = tmp->next;
    if (tmp->next)
        tmp->next->last = tmp->last;
    else
        back = tmp->last;
    delete tmp;
    size--;

    return *this;
}

template<typename T>
inline DoubleLinkedList<T>& DoubleLinkedList<T>::insert(int index, const T& value)
{
    if (index < 0 || index > size)
        throw std::out_of_range("index is out of range");
    if (index == size)
        return append(value);

    Node* tmp = head;
    while (index--)
        tmp = tmp->next;
    Node* newNode = new Node{ value, tmp, tmp->last };
    if (tmp->last)
        tmp->last->next = newNode;
    else
        head = newNode;
    tmp->last = newNode;
    size++;
    return *this;
}

template<typename T>
inline T DoubleLinkedList<T>::remove(const T& value)
{
    Node* tmp = head;
    while (tmp)
    {
        if (value == tmp->value)
        {
            if (tmp->last)
                tmp->last->next = tmp->next;
            else
                head = tmp->next;
            if (tmp->next)
                tmp->next->last = tmp->last;
            else
                back = tmp->last;

            T returnValue = tmp->value;

            delete tmp;
            size--;
            return returnValue;
        }

        tmp = tmp->next;
    }
    throw std::out_of_range("Element not found");
}

template<typename T>
inline int DoubleLinkedList<T>::find(const T& value) const
{
    Node* tmp = head;
    int index = 0;
    while (tmp)
    {
        if (tmp->value == value)
            return index;
        tmp = tmp->next;
        index++;
    }
    return -1;
}

template<typename T>
inline std::ostream& DoubleLinkedList<T>::print(std::ostream& out, char endC) const
{
    Node* tmp = head;
    out << "[ ";
    while (tmp)
    {
        out << tmp->value;
        tmp = tmp->next;
        if (tmp)
            out << ", ";
    }
    return out << " ]" << endC;
}

template<typename T>
inline std::ostream& DoubleLinkedList<T>::rprint(std::ostream& out, char endC) const
{
    Node* tmp = back;
    out << "[ ";
    while (tmp)
    {
        out << tmp->value;
        tmp = tmp->last;
        if (tmp)
            out << ", ";
    }
    return out << " ]" << endC;
}