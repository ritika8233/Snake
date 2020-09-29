#define UNICODE
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int nscreen_width=80;
int nscreen_height=80;
 
struct sSnakeSegment{
	int x;
	int y;
}; 

 int main(){
	//creating screen
	wchar_t *screen =new wchar_t[nscreen_width*nscreen_height];
	
	for(int i=0;i<nscreen_width*nscreen_height;i++){
	//initialize to blank
		screen[i]=L' ';
	} 
	
	HANDLE hConsole=CreateConsoleScreenBuffer(GENERIC_READ|GENERIC_WRITE,0,NULL,CONSOLE_TEXTMODE_BUFFER,NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten=0;
	
	// initialize list
	list<sSnakeSegment> snake = {{50,10},{51,10},{52,10},{53,10},{54,10},{55,10}};
	
	bool bdead=false;
	bool bright=false,bleft=false,bleft_old=false,bright_old=false;
	int nfoodx= 30;
	int nfoody= 10; 
	
	
	while(1){
	
	//take input
	bright=(0X8000 & GetAsyncState(unsigned));
	bleft=(0X8000);
	
	// if snake moves forward then we have to empty the screen
	for(int i=0;i<nscreen_width*nscreen_height;i++){
	//initialize to blank
		screen[i]=L' ';
	} 
	
	//create border
	for(int i=0;i<nscreen_width;i++){
		screen[i] = L'=';
		screen[2*nscreen_width+i]=L'=';
	}
	
	//print name in border
	wsprintf(&screen[nscreen_width+5],L"RETRICA JAIN        SCORE:");  
	
	//print snake elements
	for(auto s: snake){
		screen[s.y * nscreen_width + s.x] = (bdead) ? L'+' : L'O';
	}
	
	// print snake head
	screen[snake.front().y * nscreen_width + snake.front().x]=(bdead) ? L'X' : L'@';
	
	//printing of food
	screen[nfoody * nscreen_width + nfoodx] = L'%'; 
	
	//print screen
	WriteConsoleOutputCharacter(hConsole,screen,nscreen_width*nscreen_height,{0,0},&dwBytesWritten);
    }
	
	return 0;
}
