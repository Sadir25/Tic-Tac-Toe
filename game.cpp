#include<iostream>
#include<string.h>
using namespace std;

int count=0;
bool selection(char matrix[3][3],char player,int i,int j){
    if(matrix[i][j]=='X' || matrix[i][j] == 'O'){
                return 1;
            
        }
    else{
        if(player == '1'){
        matrix[i][j]='X';
        }
        else{
            matrix[i][j]='O';
        }
        return 0;
    }
}

void drawBoard(char board[3][3]) 
{ 
    cout << "-------------\n"; 
    for (int i = 0; i < 3; i++) { 
        cout << "| "; 
        for (int j = 0; j < 3; j++) { 
            cout << board[i][j] << " | "; 
        } 
        cout << "\n-------------\n"; 
    } 
} 

char check_for_match(char matrix[3][3]){
    if(matrix[0][0]==matrix[0][1] && matrix[0][0]==matrix[0][2] || matrix[0][0]==matrix[1][0] && matrix[0][0]==matrix[2][0]){
        return matrix[0][0];
    }
    else if(matrix[1][0]==matrix[1][1] && matrix[1][0]==matrix[1][2] || matrix[0][1]==matrix[1][1] && matrix[0][1] == matrix[2][1]){
        return matrix[1][1];
    }
    else if(matrix[2][0]==matrix[2][1] && matrix[2][0]==matrix[2][2] || matrix[0][2]==matrix[1][2] && matrix[0][2]==matrix[2][2]){
        return matrix[2][2];
    }
    else if(matrix[0][0]==matrix[1][1] && matrix[0][0]==matrix[2][2]){
        return matrix[0][0];

    }
    else if(matrix[0][2]==matrix[1][1] && matrix[0][2]==matrix[2][0]){
        return matrix[0][2];
    }
    else {
        return 'F';
        
    }
}

int main(){
    char board[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    string player_1;
    string player_2;
    
    cout<<"Enter player 1 name:";
    cin>>player_1;
    cout<<"Enter player 2 name:";
    cin>>player_2;
    bool match=false;
    drawBoard(board);
    
    
    for(int i=0;i<9;i++){
        
        bool flag1=0,flag2=0;
        char result;
        int row,column;
        cout<<player_1<<" select the position (0-2) row and (0-2) column:";
        cin>>row>>column;
        if(row>2 || column>2){
            flag2=1;
        }
        while(flag2){
            cout<<"Invalid Input!!!---- please select the box in the given range"<<endl;
            cout<<player_1<<" select the position (0-2) row and (0-2) column:";

            cin>>row>>column;
            if(row>2 || column>2){
            flag2=1;
            }
            else{
                flag2=0;
            }
        }
        flag1=selection(board,'1',row,column);

        // ----------------------
        // | code for checking  |
        // | if the box is      |
        // |  already filled    |
        // ----------------------
        while(flag1){
            cout<<"The selected box is filled, please choose the unfilled box "<<endl;
            cout<<player_1<<" select the position:";
            cin>>row>>column;
            flag1=selection(board,'1',row,column);
        }
        drawBoard(board);
        result=check_for_match(board);
        if(result=='X'){
            cout<<"*****CONGRATULATIONS*****"<<endl;
            cout<<player_1<<" WINS!!!!!"<<endl;
            break;
        }
        else{
            count++;
        }

        if(result='F' && count>=9){

            cout<<"Game Over <------> Try Again!!!"<<endl;
            break;
        }

        cout<<player_2<<" select the position:";
        cin>>row>>column;
        if(row>2 || column>2){
            flag2=1;
        }
        while(flag2){
            cout<<"Invalid Input!!!---- please select the box in the given range"<<endl;
            cout<<player_2<<" select the position (0-2) row and (0-2) column:";
            cin>>row>>column;
            if(row>2 || column>2){
            flag2=1;
            }
            else{
                flag2=0;
            }
        }
        
        
        flag1=selection(board,'2',row,column);

        while(flag1){
            cout<<"The selected box is filled, please choose the unfilled box "<<endl;
            cout<<player_2<<" select the position:";
            cin>>row>>column;
            flag1=selection(board,'2',row,column);
        }
        

        drawBoard(board);
        result=check_for_match(board);
        if(result=='O'){
            cout<<"*****CONGRATULATIONS*****"<<endl;
            cout<<player_2<<" WINS!!!!!"<<endl;
            break;
        }
        else{
            count++;
        }

        
        
    }
}