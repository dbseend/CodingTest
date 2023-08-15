//https://www.acmicpc.net/problem/10845

#include <iostream>

using namespace std;

struct Element
{
    int key;
};

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
            // cout << "Queue is full." << endl;
        }
    }

    Element Dequeue()
    {
        Element empty_element = {-1};

        if (!IsEmptyQ())
        {
            front = (front + 1) % max_size;
            cout << queue[front].key << endl;
            return queue[front];
        }
        else
        {
            cout << "-1" << endl;
            return empty_element;
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

    // void PrintQ()
    // {
    //     int current = front;
    //     while (current != rear)
    //     {
    //         current = (current + 1) % max_size;
    //         cout << queue[current].key << " ";
    //     }
    //     cout << endl;
    // }

    void SizeQ()
    {
        int count = 0;
        int current = front;
        while (current != rear)
        {
            current = (current + 1) % max_size;
            count++;
        }

        cout << count << endl;
    }

    void FrontQ()
    {
        if (IsEmptyQ())
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << queue[(front + 1) % max_size].key << endl;
        }
    }

    void RearQ()
    {
        if (IsEmptyQ())
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << queue[rear].key << endl;
        }
    }

    ~Queue()
    {
        delete[] queue;
    }
};

int main()
{
    int size;
    cin >> size;
    Queue *q = new Queue(size);
    cin.ignore();

    for (int i = 0; i < size; i++)
    {
        string input;
        int res;
        getline(cin, input);
        string cal = input.substr(0, input.find(" "));
        string val = input.substr(input.find(" ") + 1);
        res = atoi(val.c_str());

        if (cal == "push")
        {
            q->Enqueue({res});
        }
        else if (cal == "pop")
        {
            q->Dequeue();
        }
        else if (cal == "size")
        {
            q->SizeQ();
        }
        else if (cal == "empty")
        {
            if (q->IsEmptyQ() == true)
            {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
        else if (cal == "front")
        {
            q->FrontQ();
        }
        else if (cal == "back")
        {
            q->RearQ();
        }
    }

    return 0;
}
