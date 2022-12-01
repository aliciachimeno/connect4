

/* ***************************************************
 ** File: main.c
 ** Author: Alicia Chimeno Sarabia
 ** Date: 30/11/2022
 ** NIU: 1565281
 ** Email : aliciachimeno9@gmail.com
 **
 ** This files holds the functions related only to the game.
 *************************************************** */

#include "minimax.h"
#include "connect4.h"

void PrintBoard(char board[N][N]){
    int i,j;
    printf("\n");
    for (i=0;i<N;i++)
       {
          printf("|---|---|---|---|---|---|---|---|\n");
          for (j=0;j<N;j++)
          {
              printf("| %c ",board[i][j]);
          }
          printf("|\n");
       }
    printf("|---|---|---|---|---|---|---|---|\n");
    printf("  0   1   2   3   4   5   6   7   \n");
    printf("\n");
}

void InitializeBoard(char board[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j]=EMPTY;
        }
    }
}

void PlacePiece(char board[N][N],int col, char PLAYER){
    int index=0;
    for(int i=0;i<N; i++)
        {if(board[i][col]==EMPTY){index=i;}}
    if(index>=0 && index<N){board[index][col]=PLAYER;}
    else{printf("Error \n");}
}


void CopyBoard(char board1[N][N],char board2[N][N]){
int i,j;

for(i=0;i<N;i++){
  for(j=0;j<N;j++){
  board1[i][j]=board2[i][j];
    }
  }
}

void Game(Node *p, char PLAYER){
    if(PLAYER==CPU)
    {
        printf("Computers' turn");
        minimax(p);
        PrintBoard(p->board);
    }
    else{
        int PieceHUMAN;
        printf("In which column do you wanna drop the piece? ");
        scanf("%d",&PieceHUMAN);
        printf("\nYour turn");
        if(PieceHUMAN>=0 && PieceHUMAN<=7)
        {
            PlacePiece(p->board,PieceHUMAN,HUMAN);
            PrintBoard(p->board);
        }
        else{
            printf("Choose a valid column \n \n");
            Game(p,PLAYER);
        }
    }
}

int CheckWin(char board[N][N], char PLAYER){
    int i,j;
    
    for(i=0;i<N;i++) //4 en ratlla horizontal
    {
        for(j=0;j<N-3;j++)
        {
        if(board[i][j]==PLAYER & board[i][j+1]==PLAYER & board[i][j+2]==PLAYER & board[i][j+3]==PLAYER)
        {
        return 1;
        }
    }
  }
    
  for(j=0;j<N;j++){ //4 en ratlla vertical
    for(i=0;i<N-3;i++){
    if(board[i][j]==PLAYER & board[i+1][j]==PLAYER & board[i+2][j]==PLAYER & board[i+3][j]==PLAYER ){return 1;}
    }
  }

 for(i=0;i<N-3;i++){ // diagonal
    for(j=0;j<N-3;j++){
    if(board[i][j]==PLAYER & board[i+1][j+1]==PLAYER & board[i+2][j+2]==PLAYER & board[i+3][j+3]==PLAYER){return 1;}
    }
  }

  for(i=0;i<N-3;i++){
    for(j=3;j<N;j++){
    if(board[i][j]==PLAYER & board[i+1][j-1]==PLAYER & board[i+2][j-2]==PLAYER & board[i+3][j-3]==PLAYER){return 1;}
    }
  }
  return 0;
}

int Check3(char board[N][N], char PLAYER){
    int i,j;
    
    for(i=0;i<N;i++) //4 en ratlla horizontal
    {
        for(j=0;j<N-2;j++)
        {
        if(board[i][j]==PLAYER & board[i][j+1]==PLAYER & board[i][j+2]==PLAYER)
        {
        return 1;
        }
    }
  }
    
  for(j=0;j<N;j++){ //4 en ratlla vertical
    for(i=0;i<N-2;i++){
    if(board[i][j]==PLAYER & board[i+1][j]==PLAYER & board[i+2][j]==PLAYER){return 1;}
    }
  }

 for(i=0;i<N-2;i++){ //4 en ratlla diagonal
    for(j=0;j<N-2;j++){
    if(board[i][j]==PLAYER & board[i+1][j+1]==PLAYER & board[i+2][j+2]==PLAYER){return 1;}
    }
  }

  for(i=0;i<N-2;i++){ //4 en ratlla diagonal
    for(j=2;j<N;j++){
    if(board[i][j]==PLAYER & board[i+1][j-1]==PLAYER & board[i+2][j-2]==PLAYER){return 1;}
    }
  }
  return 0;
}

int Start(void){
    srand(time(NULL));
    int num= rand() % 2;
    return num;
} // funció per començar partida jugador aleatori

void MainScreen(void){
    printf("\n\n\n\n");
    printf("                        ====================================================\n");
    printf("                        ====================================================\n");
    printf("                        ====================================================\n");
    printf("                        =====                                          =====\n");
    printf("                        =====                 CONNECT 4                =====\n");
    printf("                        =====                                          =====\n");
    printf("                        =====            computer vs human             =====\n");
    printf("                        =====                                          =====\n");
    printf("                        ====================================================\n");
    printf("                        ====================================================\n");
    printf("                        ====================================================\n\n");
    printf("                        the game is about to start...\n\n");
    printf("                        the best of 3 wins \n\n\n");
}

int main(){
    int a=0,b=0;
    int*winCPU;
    winCPU=&a;
    int*winHUMAN;
    winHUMAN=&b;
    MainScreen();
    MAIN(winCPU, winHUMAN);
    int resp;
    printf("\nDo you want to play again?\n");
    printf("If YES press 1, if NO press 0: ");
    scanf("%d",&resp);
    if (resp == 1 )
    {
        MAIN(winCPU, winHUMAN);
        printf("\nDo you want to play again?\n");
        printf("If YES press 1, if NO press 0: ");
        scanf("%d",&resp);
        if (resp == 1 )
        {
            MAIN(winCPU, winHUMAN);
            
            return 0;
            
        }
        else{
            printf("\nbye, see you soon\n \n");
            return 0;
            
        }
    }
        else{
            printf("\nbye, see you soon\n \n");
            return 0;
        }
    
    return 0;
}

int MAIN(int*winCPU, int *winHUMAN){
    char PLAYER;
    Node *p=(Node *)malloc(sizeof(Node));
    InitializeBoard(p->board);
    p->n_children=N;
    p->children=malloc((p->n_children)*sizeof(Node*));

    int start=Start();
    if(start==1)
        {PLAYER=HUMAN;
        printf("The player starts \n");}
    else{
        PLAYER=CPU;
        printf("The computer starts \n");}
    
while(CheckWin(p->board,HUMAN)==0 && CheckWin(p->board,CPU)==0)
{
    Game(p,PLAYER);
    if(PLAYER==CPU){PLAYER=HUMAN;}
    else{PLAYER=CPU;}
}
if(CheckWin(p->board,HUMAN)==1)
{
    *winHUMAN=(*winHUMAN)+1;
    printf("You have won the game. \n");
    printf("                                                                        %d HUMAN , %d COMPUTER\n\n",*winHUMAN,*winCPU);
}
else if(CheckWin(p->board,CPU)==1){
    *winCPU=(*winCPU)+1;
    printf("You have lost the game.\n");
    printf("                                                                        %d HUMAN , %d COMPUTER\n\n",*winHUMAN,*winCPU);
}
else{printf("Even.\n");}
    return 0;
}

