#include <iostream>
using namespace std;

#define N 5
int queue[N];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1 && rear == -1);
}

bool isFull() {
    return ((rear + 1) % N == front);
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Queue is Full\n";
    } else if (isEmpty()) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
    } else if (front == rear) {
        cout << queue[front] << " deleted\n";
        front = rear = -1;
    } else {
        cout << queue[front] << " deleted\n";
        front = (front + 1) % N;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
    } else {
        cout << "Queue is: ";
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % N;
        }
        cout << queue[rear] << "\n";
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
    } else {
        cout << queue[front] << "\n";
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); // should show full after this
    display();
    dequeue();
    dequeue();
    display();
    enqueue(60);
    enqueue(70);
    display();
    peek();

    if (isEmpty())
        cout << "Queue is Empty\n";
    else
        cout << "Queue is not Empty\n";

    if (isFull())
        cout << "Queue is Full\n";
    else
        cout << "Queue is not Full\n";

    return 0;
}
