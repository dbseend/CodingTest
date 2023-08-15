// https://www.acmicpc.net/problem/10828

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
        top = -1;
        max_size = max_stack_size;
        stack = new Element[max_size];
    }

    void Push(Stack *s, Element item)
    {
        // if (IsFullS(s))
        // {
        //     // cout << "Stack is Full!" << endl;
        // }
        // else
        // {
        stack[++top] = item;
        // }
    }
    Element Pop(Stack *s)
    {
        if (IsEmptyS(s))
        {
            cout << "-1" << endl;
            Element errorElement = {-1};
            return errorElement;
        }
        else
        {
            cout << s->stack[top].key << endl;
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

    void SizeS(Stack *s)
    {
        cout << s->top + 1 << endl;
    }

    void TopS(Stack *s)
    {
        if (IsEmptyS(s) == true)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << s->stack[top].key << endl;
        }
    }

    ~Stack()
    {
        delete (stack);
    }
};

int main()
{
    int size;
    cin >> size;
    Stack *s = new Stack(size);
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
            s->Push(s, {res});
        }
        else if (cal == "pop")
        {
            s->Pop(s);
        }
        else if (cal == "size")
        {
            s->SizeS(s);
        }
        else if (cal == "empty")
        {
            if (s->IsEmptyS(s) == true)
            {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
        else if (cal == "top")
        {
            s->TopS(s);
        }
    }

    return 0;
}
