// https://www.acmicpc.net/problem/3986

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
    int ans = 0;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        string input;
        cin >> input;
        int l = input.length();
        int count = l;
        Stack *s = new Stack(l);
        s->Push(s, {input[0]});
        for (int j = 1; j < l; j++)
        {
            if (s->TopS(s) == input[j])
            {
                s->Pop(s);
                count -= 2;
            }
            else
            {
                s->Push(s, {input[j]});
            }
        }

        if (count == 0)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}