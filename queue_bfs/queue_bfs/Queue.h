#include <stdio.h>
#include <iostream>
using namespace std;
typedef int Data;
#define TRUE 1
#define FALSE 0
#define QUE_LEN 100

#pragma once

class Queue
{
	Data Arr[QUE_LEN];
	int front;
	int tail;
	int size;

public:
	Queue() {
		size = 0;
		front = 0;
		tail = 0;

	};
	void enqueue(int data);
	int dequeue();
	bool isEmpty();
	bool isFool();
	int top();
	void show();
};

