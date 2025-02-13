#ifndef SpecialArray
#define SpecialArray

#include <stdint.h>
#include "Arduino.h"

/*********************/
/*      List         */
/*********************/
class byteList
{
public:
        byteList(uint_8t sizeMax);
        ~byteList();

        byteList *insert(uint_8t pos, uint_8t val);
        bool isEmpty();
        byteList *drop(uint_8t pos);
        uint_8t size();
        uint_8t element(uint_8t pos);
        void show();

private:
        uint_8t *tab;
        uint_8t sizeMax;
        uint_8t sizeList;
};

/**
 * @brief Construct a new uint_8t List::uint_8t List object
 *
 * @param sizeMax
 */
byteList::byteList(uint_8t sizeMax) : sizeMax(sizeMax), sizeList(0)
{
        tab = new uint_8t[sizeMax];
}

/**
 * @brief Destroy the uint_8t List::uint_8t List object
 *
 */
byteList::~byteList()
{
        delete[] tab;
}

/**
 * @brief insert a value in the list at a given position
 *
 * @param pos
 * @param val
 * @return byteList*
 */
byteList *byteList::insert(uint_8t pos, uint_8t val)
{
        if ((pos < 0) || (pos > sizeList) || (sizeList == sizeMax))
        {
                return this;
        }
        for (uint_8t i = sizeList - 1; i >= pos; i--)
        {
                tab[i + 1] = tab[i];
        }
        tab[pos] = val;
        sizeList++;
        return this;
}

/**
 * @brief test if the byteList is empty
 *
 * @return true
 * @return false
 */
bool byteList::isEmpty()
{
        return (sizeList == 0);
}

/**
 * @brief Drop the element at the given position
 *
 * @param pos
 * @return byteList*
 */
byteList *byteList::drop(uint_8t pos)
{
        if ((pos < 0) || (pos >= sizeList))
        {
                return this;
        }
        for (uint_8t i = pos; i < sizeList - 1; i++)
        {
                tab[i] = tab[i + 1];
        }
        sizeList--;
        return this;
}

/**
 * @brief return the size of the list
 *
 * @return uint_8t
 */
uint_8t byteList::size()
{
        return sizeList;
}

/**
 * @brief return the element at the given position or -1 if the position is out of range
 *
 * @param pos
 * @return uint_8t (-1 if the position is out of range)
 */
uint_8t byteList::element(uint_8t pos)
{
        if (pos < 0 || pos >= sizeList)
        {
                return -1;
        }
        return tab[pos];
}

/**
 * @brief show the entire list trough serial.print()
 *
 */
void byteList::show()
{
        for (uint_8t i = 0; i < sizeList; i++)
        {
                Serial.print(tab[i]);
                if (i < sizeList - 1)
                {
                        Serial.print(", ");
                }
        }
        Serial.println();
}

/*********************/
/*      Stack        */
/*********************/

/**
 * @brief a single StackElement
 *
 */
struct StackElement
{
        uint_8t value;
        StackElement *next;
};

/**
 * @brief Stack class (LIFO)
 *
 */
class byteStack
{
public:
        byteStack();
        ~byteStack();

        void push(uint_8t val);
        bool pop();
        uint_8t size();
        bool isEmpty();
        uint_8t top();

private:
        uint_8t sizeStack;
        StackElement *head;
};

/**
 * @brief Construct a new uint_8t Stack::uint_8t Stack object
 *
 */
byteStack::byteStack() : sizeStack(0), head(nullptr) {}

/**
 * @brief Destroy the uint_8t Stack::uint_8t Stack object
 *
 */
byteStack::~byteStack()
{
        while (!isEmpty())
        {
                pop();
        }
}

/**
 * @brief push a value in the stack
 *
 * @param val
 */
void byteStack::push(uint_8t val)
{
        StackElement *e = new StackElement;
        e->value = val;
        e->next = head;
        head = e;
        sizeStack++;
}

/**
 * @brief pop the top value of the stack
 *
 * @return true if the stack is sucessfully popped
 * @return false if the stack is empty
 */
bool byteStack::pop()
{
        if (!isEmpty())
        {
                StackElement *e = head;
                head = e->next;
                delete e;
                sizeStack--;
                return true;
        }
        return false;
}

/**
 * @brief return the size of the stack
 *
 * @return uint_8t
 */
uint_8t byteStack::size()
{
        return sizeStack;
}

/**
 * @brief test if the stack is empty
 *
 * @return true
 * @return false
 */
bool byteStack::isEmpty()
{
        return (sizeStack == 0);
}

/**
 * @brief return the top value of the stack or -1 if the stack is empty
 *
 * @return uint_8t
 */
uint_8t byteStack::top()
{
        if (!isEmpty())
        {
                return head->value;
        }
        return -1;
}

/*********************/
/*      Queue        */
/*********************/

struct QueueElement
{
        uint_8t value;
        QueueElement *prev;
        QueueElement *next;
};

/**
 * @brief a class for atail (FIFO) with head andtail
 *
 */
class byteQueue
{
public:
        byteQueue();
        ~byteQueue();

        void enqueue(uint_8t val);
        bool dequeue();
        uint_8t size();
        bool isEmpty();
        uint_8t front();

private:
        uint_8t sizeQueue;
        QueueElement *head;
        QueueElement *queue;
};

/**
 * @brief Construct a new uint_8t Queue::uint_8t Queue object
 *
 */
byteQueue::byteQueue() : sizeQueue(0), head(nullptr), tail(nullptr) {}

/**
 * @brief Destroy the uint_8t Queue::uint_8t Queue object
 *
 */
byteQueue::~byteQueue()
{
        while (!isEmpty())
        {
                dequeue();
        }
}

/**
 * @brief add an element to the Queue
 *
 * @param val
 */
void byteQueue::enqueue(uint_8t val)
{
        QueueElement *e = new QueueElement;
        e->value = val;
        e->prev = nullptr;
        e->next = nullptr;

        if (queue == nullptr)
        {
                head = e;
                tail = e;
        }
        else
        {
                tail->next = e;
                e->prev = tail;
                tail = e;
        }
        sizeQueue++;
}

/**
 * @brief remove the first element of the Queue
 *
 * @return true if successufully dequeued
 * @return false if there is no element to dequeue
 */
bool byteQueue::dequeue()
{
        if (!isEmpty())
        {
                QueueElement *e = head;
                if (head->next == nullptr)
                {
                        tail = nullptr;
                }
                else
                {
                        head->next->prev = nullptr;
                }
                head = head->next;
                delete e;
                sizeQueue--;
                return true;
        }
        return false;
}

/**
 * @brief return the size of the Queue
 *
 * @return uint_8t
 */
uint_8t byteQueue::size()
{
        return sizeQueue;
}

/**
 * @brief test if the Queue is empty
 *
 * @return true
 * @return false
 */
bool byteQueue::isEmpty()
{
        return (sizeQueue == 0);
}

/**
 * @brief show the front of the Queue or -1 if the Queue is empty
 *        front = head = first element to be dequeued
 * @return uint_8t
 */
uint_8t byteQueue::front()
{
        if (!isEmpty())
        {
                return head->value;
        }
        return -1;
}
#endif