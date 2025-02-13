# SpecialArray

`SpecialArray` is a library for managing data structures such as lists, stacks (LIFO), and queues (FIFO), optimized to work with `uint8_t` values. These structures can be used in embedded projects with microcontrollers (e.g., Arduino).

## Installation

1. Download or clone this file into your Arduino project.
2. Include the `SpecialArray.h` file in your source code.

```cpp
#include "SpecialArray.h"
```

## Usage

### List

The byteList class allows you to manage a dynamic list of uint8_t values.

Main Methods:

* **insert(uint8_t pos, uint8_t val)**: Inserts a value at a specified position.
* **drop(uint8_t pos)**: Removes an element at a given position.
* **size()**: Returns the current size of the list.
* **element(uint8_t pos)**: Returns the element at the given position.
* **isEmpty()**: Checks if the list is empty.
* **show()**: Displays all elements of the list through the serial port.

Example Usage:
```cpp
byteList myList(5);  // Create a list with a max size of 5 elements

void setup() {
  Serial.begin(9600);
  
  // Inserting values
  myList.insert(0, 10);  
  myList.insert(1, 20);
  myList.insert(2, 30);

  // Displaying elements
  myList.show();

  // Dropping an element
  myList.drop(1);
  
  // Displaying after dropping an element
  myList.show();
}

void loop() {
  // Your code
}
```

### Stack

The byteStack class implements a stack (LIFO - Last In, First Out).

Main Methods:

* **push(uint8_t val)**: Pushes a value onto the stack.
* **pop()**: Removes the top element from the stack.
* **top()**: Returns the top element of the stack.
* **size()**: Returns the size of the stack.
* **isEmpty()**: Checks if the stack is empty.

Example Usage:

```cpp
byteStack myStack;  // Create an empty stack

void setup() {
  Serial.begin(9600);
  
  // Pushing values onto the stack
  myStack.push(10);
  myStack.push(20);
  myStack.push(30);

  // Displaying the size of the stack
  Serial.println(myStack.size());

  // Popping an element
  myStack.pop();
  
  // Displaying the top of the stack
  Serial.println(myStack.top());
}

void loop() {
  // Your code
}
```


### Queue

The byteQueue class implements a queue (FIFO - First In, First Out).

Main Methods:

* **enqueue(uint8_t val)**: Adds a value to the end of the queue.
* **dequeue()**: Removes the element from the front of the queue.
* **front()**: Returns the element at the front of the queue.
* **size()**: Returns the size of the queue.
* **isEmpty()**: Checks if the queue is empty.

Example Usage:

```cpp
byteQueue myQueue;  // Create an empty queue

void setup() {
  Serial.begin(9600);
  
  // Enqueuing values
  myQueue.enqueue(10);
  myQueue.enqueue(20);
  myQueue.enqueue(30);

  // Displaying the size of the queue
  Serial.println(myQueue.size());

  // Dequeuing an element
  myQueue.dequeue();
  
  // Displaying the front of the queue
  Serial.println(myQueue.front());
}

void loop() {
  // Your code
}
```

Examples
1. List Manipulation: This code demonstrates how to add, remove, and display elements in a list.
2. Stack Usage: Push and pop elements with display of the stack size and top element.
3. Queue Manipulation: Add and remove elements in a queue while tracking the front element.
