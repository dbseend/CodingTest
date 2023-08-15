// https://www.acmicpc.net/problem/1874

#include <iostream>
#include <string>

using namespace std;

typedef struct
{
    int key;
} Element;

class Stack
{
private:
    int top;
    int max_size;
    Element *stack;

public:
    Stack(int max_stack_size)
    {
        stack = new Element[max_stack_size];
        top = -1;
        max_size = max_stack_size;
    }

    void Push(Stack *s, Element item)
    {
        if (IsFullS(s))
        {
            // cout << "Stack is Full!" << endl;
        }
        else
        {
            s->stack[++top] = item;
            // cout << "+" << endl;
        }
    }

    Element Pop(Stack *s)
    {
        if (IsEmptyS(s))
        {
            // cout << "Stack is Emtpty!" << endl;
            Element errorElement = {-1};
            return errorElement;
        }
        else
        {
            // cout << "-" << endl;
            return s->stack[top--];
        }
    }

    bool IsFullS(Stack *s)
    {
        if (s->top == s->max_size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool IsEmptyS(Stack *s)
    {
        if (s->top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int TopS(Stack *s)
    {
        return s->stack[top].key;
    }

    ~Stack()
    {
        delete (stack);
    }
};

int main()
{
    // cin, cout 최적화
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size;
    cin >> size;
    Stack *s = new Stack(size);
    cin.ignore();

    int val = 0;
    for (int i = 0; i < size; i++)
    {
        string output;
        int n;
        cin >> n;
        if (n > val)
        {
            for (int j = val; j < n; j++)
            {
                s->Push(s, {j + 1});
                output += "+\n";
            }
            s->Pop(s);
            output += "-\n";
            val = n;
        }
        else
        {
            int top = s->TopS(s);
            if (n >= top)
            {
                s->Pop(s);
                output += "-\n";
            }
            else
            {
                cout << "NO"
                     << "\n";
                exit(0);
            }
        }
        if (!output.empty() && output.back() == '\n')
        {
            output = output.substr(0, output.size() - 1);
        }

        cout << output << "\n" << std::flush;
    }

    return 0;
}