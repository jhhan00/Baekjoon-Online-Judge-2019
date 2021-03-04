#include <iostream>
#include <string>
#define MAX 10000
using namespace std;

int que[MAX];
int fr = 0;
int bk = 0;

void push(int c)
{
    que[bk] = c;
    bk = (bk + 1) % MAX;
}

void pop()
{
    if(fr == bk)
        cout << "-1" << endl;
    else
    {
        cout << que[fr++] << endl;
        if(fr >= MAX)
            fr = fr - MAX;
    }
}

void issize()
{
    int sz;
    if(fr > bk)
        sz = bk + MAX - fr;
    else
        sz = bk - fr;
    cout << sz << endl;
}

void isempty()
{
    if(fr == bk)
        cout << "1" << endl;
    else
        cout << "0" << endl;
}

void frontprint()
{
    if(fr == bk)
        cout << "-1" << endl;
    else
        cout << que[fr] << endl;
}

void backprint()
{
    if(fr == bk)
        cout << "-1" << endl;
    else
    {
        if(bk == 0)
            cout << que[bk + MAX] << endl;
        else
            cout << que[bk - 1] << endl;
    }
}

int main()
{
    isempty();
    push(1);
    backprint();
    push(2);
    push(3);
    issize();
    backprint();
    pop();
    pop();
    isempty();
    pop();
    pop();

}
