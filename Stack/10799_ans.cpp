// https://www.acmicpc.net/problem/10799

#include <iostream>
#include <string>

using namespace std;

typedef struct
{
    char key;
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
        max_size = max_stack_size;
        top = -1;
    }

    void Push(Stack *s, Element item)
    {
        if (IsFullS(s))
        {
        }
        else
        {
            s->stack[++top] = item;
        }
    }

    Element Pop(Stack *s)
    {
        if (IsEmptyS(s))
        {
            Element error = {'e'};
            return error;
        }
        else
        {
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

    int SizeS(Stack *s)
    {
        return s->top + 1;
    }
};

int main()
{
    int res = 0;
    string input;
    cin >> input;
    int l = input.length();

    Stack *s = new Stack(l);
    for (int i = 0; i < l; i++)
    {
        if (input[i] == '(')
        {
            s->Push(s, {input[i]});
        }
        else if (input[i] == ')' && input[i - 1] == '(')
        {
            s->Pop(s);
            res += s->SizeS(s);
        }
        else
        {
            s->Pop(s);
            res++;
        }
    }

    cout << res << endl;
}