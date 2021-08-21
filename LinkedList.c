#include <stdio.h>
#include <stdlib.h>

// List로 선언하는 친구는 header.

typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef struct Node{
  int data;
  Position next;
} Node;

List MakeEmptyList();
int IsEmpty(List list);
int IsLast(Position p, List list);

Position Find(int x, List list);
Position FindPrevious(int x, List list);

void Delete(int x, List list);
void Insert(int x, List list, Position p);
void DeleteList(List list);

List MakeEmptyList(){
  List list;
  list = (List) malloc(sizeof(struct Node));
  list->data = 0;
  list->next = NULL;
  return list;
}

int IsEmpty(List list){
  return list->next == NULL;
}

int IsLast(Position p, List list){
  return p->next == NULL;
}

Position Find(int x, List list){
  Position p;
  p = list->next;
  while(p->next != NULL && p->data != x){
    p = p->next;
  }
  return p;
}

Position FindPrevious(int x, List list){
  Position p;
  p = list;
  while(p->next != NULL && p->next->data != x){
    p = p->next;
  }
  return p;
}

void Delete(int x, List list){
  Position p_prev = FindPrevious(x, list);
  p_prev->next = p_prev->next->next;
  free(p_prev->next);
}

void Insert(int x, List list, Position p){
  Position tmp = (Position) malloc(sizeof(struct Node));
  tmp->data = x;
  tmp->next = p->next;
  p->next = tmp;
}

void DeleteList(List list){
  Position p, tmp;
  p = list->next;
  while(p != NULL){
    tmp = p->next;
    free(p);
    p = tmp;
  }
  free(list);
}