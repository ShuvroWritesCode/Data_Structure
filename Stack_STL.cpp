#include <iostream>
#include <stack>

using namespace std;

int32_t main() {
    //Creation
    stack<int> stack1;

    //Insertion
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);

    //Deletion
    stack1.pop();

    //Top/peek Element
    cout << "Top element = " << stack1.top() << '\n';

    //isEmpty?
    if(stack1.empty()){
        cout << "The stack is empty" << '\n';
    }
    else{
        cout << "The stack is not empty" << '\n';
    }
  
    return 0;
}
