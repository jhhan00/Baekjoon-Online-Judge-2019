#include <iostream>
#include <string>
using namespace std;

int top = -1;
char tk[100];

void push(char c)
{
    tk[++top] = c;
}

void pop()
{
    if(top == -1)
        cout << "Cannot pop!" << endl;
    else
    {
        cout << tk[top--] << endl;
    }
}

int main()
{
    int k;
    string ch = "([])";
    cout << ch << endl;
    int s = ch.size();
    for(int i=0; i<s; i++)
    {
        push(ch[s]);
        if(tk[top] == ')')
        {
            pop();
            pop();
            k = 2;
        }
        else if(tk[top] == ']')
        {
            pop();
            pop();
            k = 3;
        }
    }
}
