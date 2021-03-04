#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long pn[90];
    pn[0]=1; pn[1]=1;
    for(int i=2; i<90; i++)
        pn[i]=pn[i-1] + pn[i-2];
    cout << pn[n-1] << endl;
    return 0;
}
