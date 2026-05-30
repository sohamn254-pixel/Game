#include <iostream>
using namespace std;

char board[3][3];

void initializeBoard(){
char ch='1';
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
board[i][j]=ch++;
}

void displayBoard(){
cout<<"\n";
for(int i=0;i<3;i++){
cout<<" "<<board[i][0]<<" | "<<board[i][1]<<" | "<<board[i][2]<<"\n";
if(i<2) cout<<"---|---|---\n";
}
}

bool checkWin(char p){
for(int i=0;i<3;i++){
if(board[i][0]==p&&board[i][1]==p&&board[i][2]==p) return true;
if(board[0][i]==p&&board[1][i]==p&&board[2][i]==p) return true;
}
if(board[0][0]==p&&board[1][1]==p&&board[2][2]==p) return true;
if(board[0][2]==p&&board[1][1]==p&&board[2][0]==p) return true;
return false;
}

bool makeMove(int choice,char player){
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
if(board[i][j]==choice+'0'){ board[i][j]=player; return true; }
return false;
}

bool boardFull(){
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
if(board[i][j]!='X'&&board[i][j]!='O') return false;
return true;
}

int main(){
char replay;
do{
initializeBoard();
char current='X';
int move;
while(true){
displayBoard();
cout<<"Player "<<current<<", enter position (1-9): ";
cin>>move;
if(move<1||move>9||!makeMove(move,current)){ cout<<"Invalid move!\n"; continue; }
if(checkWin(current)){ displayBoard(); cout<<"Player "<<current<<" wins!\n"; break; }
if(boardFull()){ displayBoard(); cout<<"Game Draw!\n"; break; }
current=(current=='X')?'O':'X';
}
cout<<"Play again? (Y/N): ";
cin>>replay;
}while(replay=='Y'||replay=='y');
return 0;
}
