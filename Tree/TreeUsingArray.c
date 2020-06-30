#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* lchild;
    int data;
    struct Node* rchild;
};

struct Queue{
    int size;
    int front;
    int rear;
    Node** Q;
};

void create(struct Queue* q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (Node**)malloc(q->size * sizeof(Node*));
}

void enqueue(struct Queue* q, Node* x){
    if (q->rear == q->size - 1)
        printf("Queue is Full");
    else
    {
        q->rear++;
        q->
            Q[q->rear] = x;
    }
}

Node* dequeue(struct Queue* q){
    Node* x = NULL;

    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q) {
    return q.front == q.rear;
}
struct Node* root = NULL;
void Treecreate(){
    struct Node* p, * t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value ");
    scanf_s("%d", &x);
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d ", p->data);
        scanf_s("%d", &x);
        if (x != -1)
        {
            t = (struct Node*)malloc(sizeof(struct
                Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d ", p->data);
        scanf_s("%d", &x);
        if (x != -1)
        {
            t = (struct Node*)malloc(sizeof(struct
                Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void Preorder(struct Node* p){
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Inorder(struct Node* p){
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct Node* p){
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}
int main(){
    Treecreate();
    Preorder(root);
    printf("\nPost Order ");
    Postorder(root);

    return 0;
}