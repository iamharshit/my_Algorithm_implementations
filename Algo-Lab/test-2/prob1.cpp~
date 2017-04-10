//Given a Queue stored in circular array, output the no of elements

#include<bits/stdc++.h>
using namespace std;

struct queue_ds{
	int front;
	int rear;
	int item[100];
};

void en_queue(queue_ds *q, int x){
	q->item[q->rear] = x;
	q->rear++; 
	if(q->rear==100) q->rear=0;
}

int count_queue(queue_ds *q){
	if(q->rear > q->front)
		return q->rear - q->front+1;
	else
		return 99-q->front+1 + q->rear+1;		
}

void print_queue(queue_ds *q){
	cout<<q->front<<" "<<q->rear<<endl;
	if(q->rear>=100){
		cout<<"Overflow has occured"<<endl;
		return;
	}
	if(q->rear > q->front){cout<<q->front<<"  "<<q->rear<<endl;
		for(int i=q->front;i<q->rear;i++) cout<<q->item[i]<<" ";
	}
	else{
		for(int i=q->front;i<100;i++) cout<<q->item[i]<<" ";
		for(int i=0;i<q->rear;i++) cout<<q->item[i]<<" ";
	}
	cout<<endl;
}

int empty(queue_ds *q){
	if(q->rear==q->front) return 1;
	else return 0;
}

void de_queue(queue_ds *q){
	if(empty(q)){
		cout<<"Underflow has occured"<<endl;
		return;
	}
	cout<<"Dequeued Element="<<q->item[q->front]<<endl;
	q->front++;
}

int main(){
	queue_ds *myqueue = new queue_ds;
	//input front and rear position
	cout<<"Enter front position: ";cin>>myqueue->front;
	
	myqueue->rear = myqueue->front;
	int tmp;
	while(1){
		cout<<"Enqueue:1   Dequeue:2 Exit:3"<<endl;
		cin>>tmp;
		if(tmp==1){
			cout<<"Choice? "; cin>>tmp;
			en_queue(myqueue,tmp);
		}
		else if(tmp==2){
			de_queue(myqueue); 
		}
		else if(tmp==3)
			break;		
		else{
			cout<<"INVALID CHOICE !!!!"<<endl;
		}
		cout<<"============"<<endl;
	}
 	cout<<"No of elements= "<<count_queue(myqueue);
	//print_queue(myqueue);
	
	return 0;
}
