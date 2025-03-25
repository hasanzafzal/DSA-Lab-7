#include <iostream>
using namespace std;

class Queue 
{
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int size = 10);
    ~Queue();
    void enqueue(int x);
    int dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    int size();
};

Queue::Queue(int size) : capacity(size), front(0), rear(-1), count(0) 
{
    arr = new int[capacity];
}

Queue::~Queue() 
{
    delete[] arr;
}

void Queue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue Overflow\n";
        return;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = x;
    count++;
}

int Queue::dequeue() 
{
    if (isEmpty()) 
    {
        cout << "Queue Underflow\n";
        return -1;
    }
    int x = arr[front];
    front = (front + 1) % capacity;
    count--;
    return x;
}

int Queue::peek() 
{
    if (isEmpty()) 
    {
        cout << "Queue is Empty\n";
        return -1;
    }
    return arr[front];
}

bool Queue::isEmpty() 
{
    return count == 0;
}

bool Queue::isFull() 
{
    return count == capacity;
}

int Queue::size() 
{
    return count;
}

int main()                                                  //Program was completed till here at the time of evaluation.
{
    Queue q(5);
    cout << "Insert some elements into the queue:\n";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << "Queue elements are: ";
    Queue temp1 = q;
    while (!temp1.isEmpty()) 
    {
        cout << temp1.dequeue() << " ";
    }
    cout << endl;
    cout << "\nReverse Queue elements:\n";
    Queue temp2(5);
    int arr[5];
    int size = q.size();
    for (int i = 0; i < size; i++) 
    {
        arr[i] = q.dequeue();
    }
    for (int i = size - 1; i >= 0; i--)
    {
        temp2.enqueue(arr[i]);
    }
    cout << "Queue elements are: ";
    while (!temp2.isEmpty()) 
    {
        cout << temp2.dequeue() << " ";
    }
    cout << endl;
    return 0;
}