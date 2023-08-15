// https://www.acmicpc.net/problem/9012

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
            // cout << "Stack is Full" << endl;
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
            // cout << "Stakc is Empty" << endl;
            Element errorElement = {'e'};
            return errorElement;
        }
        else
        {
            return s->stack[top--];
        }
    }

    bool IsFullS(Stack *s)
    {
        if (s->top + 1 == s->max_size)
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

    ~Stack()
    {
        delete (stack);
    }
};

int main()
{
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        string input;
        cin >> input;
        Stack *s = new Stack(input.length());

        int count = input.length(), count1 = 0, count2 = 0;
        for (int j = 0; j < input.length(); j++)
        {
            if (input[j] == '(')
            {
                s->Push(s, {input[j]});
                count1++;
            }
            else if (input[j] == ')')
            {
                count2++;
                if (count1 >= count2)
                {
                    for (int k = 0; k < 2; k++)
                    {
                        s->Pop(s);
                        count--;
                        count1--;
                        count2--;
                    }
                }
            }
        }
        if (count == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}