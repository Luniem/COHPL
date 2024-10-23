#ifndef STACK_PRIV_H
#include <list>
using namespace std;

class Stack_priv: private list<int>{
    public:
        void push(int value);
};
#endif