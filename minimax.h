/* ***************************************************
 ** File: minimax.h
 ** Author: Alicia Chimeno Sarabia
 ** Date: 30/11/2022
 ** NIU: 1565281
 ** Email : aliciachimeno9@gmail.com
 *************************************************** */


#include<stdio.h>
#include<stdlib.h>
//#include<stdbool.h>
//#include<limits.h>
#include <time.h>
#define N 8
#define EMPTY ' '
#define CPU   'O'
#define HUMAN 'X'

typedef struct node {
    char board[N][N];
    struct node **children;
    int n_children;
    double value;
    int col;
} Node;

Node *CreateNode(char[N][N],int ,int);
int NumChildren(char[N][N]);
void CreateLevel(Node *, int);
void CreateTree(Node *);
int MIN(int,int);
int MAX(int,int);
int CheckWin(char [N][N], char);
int Check3(char [N][N], char );
double heuristic(char [N][N]);
void minimax(Node *);
