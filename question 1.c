#include <iostream>
using namespace std;

#define N 5
int queue[N];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1 && rear == -1);
}

bool isFull() {
    return (rear == N - 1);
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Overflow\n";
    } else if (isEmpty()) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Underflow\n";
    } else if (front == rear) {
        cout << queue[front] << " deleted\n";
        front = rear = -1;
    } else {
        cout << queue[front] << " deleted\n";
        front++;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
    } else {
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << "\n";
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
    display();
    peek();
    dequeue();
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
