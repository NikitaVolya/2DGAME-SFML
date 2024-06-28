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
    private:
        Node* iterator_node;
        bool revers;
    public:
        Iterator(Node* node, bool isRevers = false) : iterator_node(node), revers(isRevers) {};
        Iterator(const Iterator& other) : iterator_node(other.iterator_node), revers(other.revers) {};

        T& value() { if (!iterator_node) throw std::out_of_range("Iterator is out of range"); return iterator_node->value; }

        bool operator==(const Iterator& other) const { return iterator_node == other.iterator_node; }
        bool operator!=(const Iterator& other) const { return iterator_node != other.iterator_node; }

        DoubleLinkedList<T>::Iterator& operator++()
        {
            if (!iterator_node)
                throw std::out_of_range("Iterator is out of range");
            if (revers)
                iterator_node = iterator_node->last;
            else
                iterator_node = iterator_node->next;
            return *this;
        }
        DoubleLinkedList<T>::Iterator& operator++(int)
        {
            Iterator tmp = *this;
            *this++;
            return tmp;
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

    Iterator begin() const { return Iterator(head); }
    Iterator rbegin() const { return Iterator(back, true); }
    Iterator end() const { return Iterator(nullptr); }
    Iterator rend() const { return Iterator(nullptr); }
   
    DoubleLinkedList<T>& add(const T& value);
    DoubleLinkedList<T>& pop();

    DoubleLinkedList<T>& append(const T& value);
    DoubleLinkedList<T>& popend();

    DoubleLinkedList<T>& remove(int index);
    DoubleLinkedList<T>& insert(int index, const T& value);

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
inline DoubleLinkedList<T>& DoubleLinkedList<T>::remove(int index)
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