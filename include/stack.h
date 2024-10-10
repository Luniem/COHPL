#ifndef STACK_H
#define STACK_H

class Stack {
    private:
        int* _pValues;

    public:
        int _size;

        Stack(int size);

        Stack(const Stack& other);

        ~Stack();

        Stack* operator=(const Stack& other);

        void push(int value);

        bool isEmpty() const;
};

#endif