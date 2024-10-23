#ifndef STACK_AGG_H
#include <list>
using namespace std;

class Stack_agg {
    private:
        list<int> _pValues;
    public:
        void push(int value);
        
};
#endif