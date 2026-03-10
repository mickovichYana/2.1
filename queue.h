#ifndef QUEUE_H
#define QUEUE_H

#include <windows.h>
#include <iostream>

// FIX_ME: убрано using namespace std;

class Node {
public:
    int data;
    Node* next;
};
typedef Node* PNode;

void Add(int data, PNode& head, PNode& tail);

void Show_Initial(PNode head, PNode tail);

void Remove_Elements(int n, PNode& head, PNode& tail);

void Show_Final(PNode head, PNode tail);

#endif 