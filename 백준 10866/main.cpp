#include <iostream>
#include <cstdio>
#include <deque>
#include <string>
using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);
    deque<int> dq;
    int i, n;
    string cm;
    cin >> n;
    for(i=0; i<n ;i++){
        cin >> cm;
        if(cm == "push_front"){
            int k;
            cin >> k;
            dq.push_front(k);
        }
        else if(cm == "pop_front"){
            if(dq.empty())
                cout << "-1" << "\n";
            else{
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if(cm == "front"){
            if(dq.empty())
                cout << "-1" << "\n";
            else
                cout << dq.front() <<"\n";
        }
        else if(cm == "push_back"){
            int k;
            cin >> k;
            dq.push_back(k);
        }
        else if(cm == "pop_back"){
            if(dq.empty())
                cout << "-1" << "\n";
            else{
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if(cm == "back"){
            if(dq.empty())
                cout << "-1" << "\n";
            else
                cout << dq.back() <<"\n";
        }
        else if(cm == "size")
            cout << dq.size() << "\n";
        else if(cm == "empty")
            cout << dq.empty() << "\n";
    }
}
