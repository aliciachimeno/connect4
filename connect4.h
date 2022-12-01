/* ***************************************************
 ** File: connect4.h
 ** Author: Alicia Chimeno Sarabia
 ** Date: 30/11/2022
 ** NIU: 1565281
 ** Email : aliciachimeno9@gmail.com
 *************************************************** */


#define N 8


void CopyBoard(char [N][N],char[N][N]);
void PrintBoard(char[N][N]);
void InitializeBoard(char[N][N]);
void PlacePiece(char [N][N],int, char);
void Game(Node *,char);
int Start(void);
int Check3(char [N][N], char);
int MAIN(int*, int*);
void PlacePieceHUMAN(char board[N][N]);
void PlacePieceCPU(char board[N][N],int col);
