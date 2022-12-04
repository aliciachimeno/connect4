/* ***************************************************
 ** File: minimax.c
 ** Author: Alicia Chimeno Sarabia
 ** Date: 30/11/2022
 ** NIU: 1565281
 ** Email : aliciachimeno9@gmail.com
 **
 ** This files holds the functions related only to minimax algorithm.
 *************************************************** */

#include "minimax.h"
#include "connect4.h"


int NumChildren(char board[N][N]){
  int i,cont=0;
  for(i=0;i<N;i++){
      if(board[0][i]==EMPTY){cont++;}
  }
  return cont;
}

Node *CreateNode(char board[N][N],int child_index,int level){
    Node *p=malloc(sizeof(Node));
    p->col=child_index;
    CopyBoard(p->board,board);
    if(level==2){
        PlacePiece(p->board,child_index,HUMAN);
        p->n_children=0;
        p->children=NULL;
        p->value=heuristic(p->board);
        }
    else{
        PlacePiece(p->board,child_index,CPU);
        p->n_children=NumChildren(p->board);
        p->children=malloc((p->n_children)*sizeof(Node*));
    }
return p;
}

void CreateLevel(Node *father, int level){
  for(int i=0;i<father->n_children;i++){
      father->children[i]=CreateNode(father->board,i,level);
  }
}

void CreateTree(Node *root){
  CreateLevel(root,1);
  for(int i=0;i<root->n_children;i++){
    CreateLevel(root->children[i],2);
  }
}

int MIN(int num1, int num2){
    return (num1 > num2 ) ? num2 : num1;
}

int MAX(int num1, int num2){
    return (num1 > num2 ) ? num1 : num2;
}

void minval(Node *root)
{
    srand(time(NULL));
    int a=rand()%8;
    double valmin=(root->children)[a]->value; // assignem per inicialitzar q el valor minim sigui random
    int index_min=0; // index del valor minim
    for(int i=0;i<root->n_children;i++)
    {
        valmin = MIN(valmin,(root->children)[i]->value);
        if(valmin<(root->children)[i]->value)
        {index_min=i;}
    }
    root->value = valmin;
}

int lastmaxval(Node *root)
{
    srand(time(NULL));
    int a=rand()%8; // numero random per inicialitzar
    int j=root->children[a]->col;
    for(int i=0;i<root->n_children;i++){
    if(root->children[i]->value > root->children[j]->value){j=root->children[i]->col;}
    }
    return j;
}

void minimax(Node *root)
{
    int i,PieceCPU;
    CreateTree(root);
    for(i=0;i<N;i++){
        minval(root->children[i]);
    }
    PieceCPU=lastmaxval(root);
    PlacePiece(root->board,PieceCPU,CPU);
}




double heuristic(char board[N][N])
{
    int count=0;
    srand(time(NULL));
    if(CheckWin(board,CPU)==1)
    {
        count=count+100000;
    }
    if(CheckWin(board,HUMAN)==1)
    {
        count=count-100000;
    }
    if(Check3(board, CPU)==1)
    {
        count=count+100;
    }
    if(Check3(board, HUMAN)==1)
    {
        count=count-100;
    }
    else count= rand()%10;
    return count;
}

void DeleteNode(Node *p,int level){ // no use
    if(level<2){
        free(p->children);
    }
    free(p);
}

void Delete1Level(Node *father, int level){ // no use
    int i;
    for(i=0;i<father->n_children;i++){
        DeleteNode(father->children[i],level);
    }
}
