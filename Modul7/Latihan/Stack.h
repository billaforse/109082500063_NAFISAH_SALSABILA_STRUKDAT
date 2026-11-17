#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#define MAXSTACK 20

typedef int infotype;

struct Stack {
    infotype info[MAXSTACK];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif