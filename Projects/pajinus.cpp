//Cpp program to play atari type shooter
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

const int WIDTH = 100;
const int HEIGHT = 25;

int playerX;

int objX, objY;

int score;

bool isGameOver;

void initGame(){
    playerX = WIDTH/2;
    objX = rand()%WIDTH;
    objY = 0;
    score = 0;

}
void displayGame(){
    //top wall
    for(int i; i <WIDTH + 2; i++){
        cout<<"_";
    }
    cout<<endl;
    //side walls
    //player
    //obj
    //bottom wall
}
void inputHandler();
void updateGame();

int main(){
    initGame(
        
    );
    while(!isGameOver){
        displayGame();
        updateGame();
    }
    return 0;
}