#include <iostream>
#include <stack>
using namespace std;

int main()
{   stack<char> S;
    S.push('a');
    S.push('b');
    S.push('c');
    cout<<S.top()<<" ";
    cout<<S.top()<<" ";
    cout<<S.top()<<" ";
    S.pop();
    cout<<S.top()<<" ";
    S.pop();
    cout<<S.top()<<" ";
    S.pop();
    S.pop();
    S.pop();
    return 0;
}
