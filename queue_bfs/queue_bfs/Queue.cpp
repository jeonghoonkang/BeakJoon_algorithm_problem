#include "Queue.h"


void Queue::enqueue(int data) {
	if (tail == QUE_LEN) {
		cout << "fully~" << endl;

	}
	else {
		Arr[tail] = data;
		tail++;
		size++;
	}
};
int Queue::dequeue() {
	if (isEmpty()) {
		return NULL;
	}
	else {

		size--;
		return Arr[front++];
	}
};
bool Queue::isEmpty() {
	if (size == 0) return TRUE;
	else return FALSE;
}
bool Queue::isFool() {
	if (size == QUE_LEN) return TRUE;
	else return FALSE;
};
int Queue::top(){
	return Arr[tail];
};
void Queue::show() {
	for (int i = front; i < tail; i++) {
		cout << Arr[i] << " ";

	}
	cout <<"front : "<<front<< "tail : "<<tail<<endl;
	
};