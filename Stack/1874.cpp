#include <iostream>
using namespace std;

class Stack
{
private:
    int *data;
    int top;
    int capacity;

public:
    Stack(int size) : capacity(size), top(-1)
    {
        data = new int[capacity];
    }

    ~Stack()
    {
        delete[] data;
    }

    void Push(int val)
    {
        data[++top] = val;
    }

    void Pop()
    {
        top--;
    }

    int Top()
    {
        return data[top];
    }

    bool IsEmpty()
    {
        return top == -1;
    }
};

int main()
{
    // cin, cout 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size;
    cin >> size;
    cin.ignore();

    Stack s(size);
    int val = 0;
    string output;

    for (int i = 0; i < size; i++)
    {
        int n;
        cin >> n;
        if (n > val)
        {
            for (int j = val; j < n; j++)
            {
                s.Push(j + 1);
                output += "+\n";
            }
            s.Pop();
            output += "-\n";
            val = n;
        }
        else
        {
            int top = s.Top();
            if (n >= top)
            {
                s.Pop();
                output += "-\n";
            }
            else
            {
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << output;
    }

    return 0;
}
