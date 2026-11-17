#include "stack.h"

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAXSTACK - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "stack penuh" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = -1;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "stack kosong" << endl;
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int i = 0;
    int j = S.top;
    while (i < j) {
        infotype temp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = temp;
        i++;
        j--;
    }
}

void pushAscending(Stack &S, infotype x) {
    Stack T;
    createStack(T);
    while (!isEmpty(S) && S.info[S.top] > x) {
        push(T, pop(S));
    }
    push(S, x);
    while (!isEmpty(T)) {
        push(S, pop(T));
    }
}

void getInputStream(Stack &S) {
    char c;
    cin.get(c);
    while (c != '\n' && !isFull(S)) {
        if (c >= '0' && c <= '9') {
            push(S, c - '0');
        }
        cin.get(c);
    }
}