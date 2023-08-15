// https://www.acmicpc.net/problem/2164

#include <iostream>

using namespace std;

typedef struct
{
    int key;
} Element;

class Queue
{
private:
    int max_size;
    int rear, front;
    Element *queue;

public:
    Queue(int max_queue_size)
    {
        max_size = max_queue_size;
        rear = 0, front = 0;
        queue = new Element[max_size];
    }

    void Enqueue(Element item)
    {
        if (!IsFullQ())
        {
            rear = (rear + 1) % max_size;
            queue[rear] = item;
        }
        else
        {
        }
    }

    Element Dequeue()
    {
        Element err = {-1};

        if (!IsEmptyQ())
        {
            front = (front + 1) % max_size;
            return queue[front];
        }
        else
        {
            return err;
        }
    }

    bool IsFullQ()
    {
        return (rear + 1) % max_size == front;
    }

    bool IsEmptyQ()
    {
        return rear == front;
    }

    int SizeQ()
    {
        int count = 0;
        int current = front;
        while (current != rear)
        {
            current = (current + 1) % max_size;
            count++;
        }

        return count;
    }

    void ExchangeQ()
    {
        queue[(front+1) % max_size].key = queue[rear].key;
    }

    void PrintQ()
    {
        int current = front;
        while (current != rear)
        {
            current = (current + 1) % max_size;
            cout << queue[current].key << " ";
        }
        cout << endl;
    }

    void FrontQ()
    {
        cout << queue[(front + 1) % max_size].key << endl;
    }
    void RearQ()
    {
        cout << queue[rear].key << endl;
    }

    ~Queue()
    {
        delete[] queue;
    }
};

int main()
{
    int n;
    cin >> n;
    Queue *q = new Queue(n+1);
    for (int i = 0; i < n; i++)
    {
        q->Enqueue({i + 1});
    }

    int size = q->SizeQ();
    while (1)
    {
        if (size == 1)
        {
            break;
        }

        q->Dequeue();
        Element temp = q->Dequeue();
        q->Enqueue(temp);
        size--;
    }

    q->RearQ();

    return 0;
}