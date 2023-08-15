// https://www.acmicpc.net/problem/10828

#include <iostream>
#include <string>

using namespace std;

typedef struct
{
    int key;
} Element;

typedef struct
{
    Element *stack;
    int top;
    int max_size;
} Stack;

Stack *CreatS(int max_size)
{
    // Stack *s = (Stack *)malloc(sizeof(Stack));
    // s->stack = (Element *)malloc(max_size * sizeof(Element));
    Stack *s = new Stack;
    s->stack = new Element[max_size];
    s->top = -1;
    s->max_size = max_size;

    return s;
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

void Push(Stack *s, Element item)
{
    // if (IsFullS(s))
    // {
    //     cout << "Stack is Full!" << endl;
    // }
    // else
    // {
        s->stack[++s->top] = item;
        // cout << s->stack[s->top].key << endl;
        // cout << s->stack->key << endl;
    // }
}

Element *Pop(Stack *s)
{
    if (IsEmptyS(s))
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << s->stack[s->top].key << endl;
        return &(s->stack[s->top--]);
    }
}

void Size(Stack *s)
{
    cout << s->top + 1 << endl;
}

void Top(Stack *s)
{
    if (IsEmptyS(s))
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << s->stack[s->top].key << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    Stack *s = CreatS(n);
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        // string cal, val;
        // cal = cal.substr(0, input.find(" "));
        // val = val.substr(input.find(" ")+1, input.length());
        string input;
        int res;
        getline(cin, input);
        string cal = input.substr(0, input.find(" "));
        string val = input.substr(input.find(" ") + 1);
        res = atoi(val.c_str());

        if (cal == "push")
        {
            Push(s, {res});
        }
        else if (cal == "pop")
        {
            Element *pop = Pop(s);
        }
        else if (cal == "size")
        {
            Size(s);
        }
        else if (cal == "empty")
        {
            if (IsEmptyS(s))
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
            Top(s);
        }
    }

    free(s->stack);
    free(s);

    return 0;
}