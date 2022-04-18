#include "Queue.h"
#include <stdlib.h>

Queue newQueue(){
    Queue queue= (Queue) malloc(sizeof(QueueImp));
    queue->head = NULL;
    queue->foot = NULL;
    return queue;
}

void freeQueue(Queue q){
    NodeLL *temp = q->head;
    while(temp!= NULL){
        NodeLL *temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    q->head = NULL;
    q->foot = NULL;
}

NodeLL *allocateNode(Vertex value){
    NodeLL * node = (NodeLL*) malloc(sizeof(NodeLL));
    node->next = NULL;
    node->v = value;
    return node;
}

void enqueue(Queue q, Vertex value){
    NodeLL *node = allocateNode(value);
    if(isEmptyQueue(q))
    {
        q->head = node;
        q->foot = node;
    }
    else
    {
        q->foot->next = node;
        q->foot = q->foot->next;
    }
}

int dequeue(Queue q, Vertex *e)
{
    NodeLL * node;
    if(isEmptyQueue(q))
    {
        return 0;
    }
    node = q->head;
    
    if(q->head == q->foot)
    {
        q->head = NULL;
        q->foot = NULL;
    }
    else
    {
        q->head = q->head->next;
    }
    *e =  node->v;
    free(node);
    return 1;
}

int frontElement(Queue q, Vertex *e){
    if(isEmptyQueue(q)){
        return 0;
    }
    *e = q->head->v;
    return 1;
}

int isEmptyQueue(Queue q)
{
    return q->head == NULL;
}