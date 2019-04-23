#include<conio.h>
#include<graphics.h>
#include <time.h>
#include <stdlib.h>


#define ROW 579
#define COLUMN 599
#define MOVE 20


int initMap();
void pacManMovementRight(int centerX,int centerY,int toss);
void pacManMovementLeft(int centerX,int centerY,int toss);
void pacManMovementUp(int centerX,int centerY,int toss);
void pacManMovementDown(int centerX,int centerY,int toss);
void removeLastPlace(int centerX,int centerY);
void scoreUpdate(int score);

int main(){   
 	srand(time(NULL));
	int x1=21,y1=21,x2=41,y2=41,i;
	int ek=20;
	char button,tus;
	int centerX,centerY,monsterX=251,monsterY=271;	
	int destination=4;
	int toss=0;
	int score=0;
	int font = 8;
	int direction = 0;
	int font_size = 5; 
	int c;
	char ch;
	int move;
	bool feed=true;
	bool keepGoing;
	score = initMap();
	
	move = 2;
	button = getch();
	removeLastPlace(monsterX,monsterY);
	monsterX=251;
	monsterY=231;
	while(1){
	delay(50);	
	
	if(kbhit()){
		ch = getch();
		if(ch == button){
			continue;
		}button = ch;
		
	}	

		centerX = (x1+x2)/2;
		centerY = (y1+y2)/2;
		switch(button){
			case 27:
				exit(0);
			case 'd': //right
				if(getpixel(centerX+ek,centerY)!=1){
					if(getpixel(centerX+ek,centerY)==14){
						score--;
					}
					x1+=ek;
					x2+=ek;
								//to right
				}
				else{
					toss=1;
				}	
				destination=0;
				break;
			case 'a': //left
				if(getpixel(centerX-ek,centerY)!=1){
					if(getpixel(centerX-ek,centerY)==14){
						score--;
					}
					x1-=ek;
					x2-=ek;
								//to left
				}
				else{
					toss=1;
				}	
				destination=1;
				break;				
			case 'w': //up
				if(getpixel(centerX,centerY-ek)!=1){
					if(getpixel(centerX,centerY-ek)==14){
						score--;
					}
					y1-=ek;
					y2-=ek;
									//to up
				}
				else{
					toss=1;
				}					
				destination=2;
				break;
			case 's': //down
				if(getpixel(centerX,centerY+ek)!=1){
					if(getpixel(centerX,centerY+ek)==14){
						score--;
					}
					y1+=ek;
					y2+=ek;
									//to down
				}
				else{
					toss=1;
				}	
				destination=3;
				break;
			default : break;
		}
		centerX = (x1+x2)/2;
		centerY = (y1+y2)/2;
		switch(destination){
			case 0: pacManMovementRight(centerX,centerY,toss);break;
			case 1: pacManMovementLeft(centerX,centerY,toss);break;
			case 2: pacManMovementUp(centerX,centerY,toss);break;
			case 3: pacManMovementDown(centerX,centerY,toss);break;
			default : break;
		}
		
		
		/////monster
		if(keepGoing){
			removeLastPlace(monsterX,monsterY);
		}
		if(feed){	
			setfillstyle(14,14);
			fillellipse(monsterX,monsterY,5,5);
		}
		
		
		switch(move){
			case 0:
				if(getpixel(monsterX + MOVE,monsterY)!=1){
					monsterX = monsterX + MOVE;
					if(getpixel(monsterX,monsterY)==14){
						feed = true;
					}
					else{
						feed = false;
					}
					
					
					setcolor(RED);
					setfillstyle(SOLID_FILL,4);	//monster shape
					fillellipse(monsterX,monsterY,10,10);
					
					setcolor(WHITE);
					setfillstyle(SOLID_FILL,1);	//monster eyes
					fillellipse(monsterX-5,monsterY-5,2,2);
					fillellipse(monsterX+5,monsterY-5,2,2);
					keepGoing=true;
				}
				else{
					keepGoing=false;
				}
				break;
			case 1:
				if(getpixel(monsterX - MOVE,monsterY)!=1){
					monsterX = monsterX - MOVE;		
					if(getpixel(monsterX,monsterY)==14){
						feed = true;
					}
					else{
						feed = false;
					}
					
					
					setcolor(RED);
					setfillstyle(SOLID_FILL,4);	//monster shape
					fillellipse(monsterX,monsterY,10,10);
					
					setcolor(WHITE);
					setfillstyle(SOLID_FILL,1);	//monster eyes
					fillellipse(monsterX-5,monsterY-5,2,2);
					fillellipse(monsterX+5,monsterY-5,2,2);
					keepGoing=true;
				}
				else{
					keepGoing=false;
				}
				break;
			case 2://up
				if(getpixel(monsterX,monsterY - MOVE)!=1){	
					monsterY = monsterY - MOVE;		
					if(getpixel(monsterX,monsterY)==14){
						feed = true;
					}
					else{
						feed = false;
					}
					
					
					setcolor(RED);
					setfillstyle(SOLID_FILL,4);	//monster shape
					fillellipse(monsterX,monsterY,10,10);
					
					setcolor(WHITE);
					setfillstyle(SOLID_FILL,1);	//monster eyes
					fillellipse(monsterX-5,monsterY-5,2,2);
					fillellipse(monsterX+5,monsterY-5,2,2);
					keepGoing=true;
				}
				else{
					keepGoing=false;
				}
				break;
			case 3:
				if(getpixel(monsterX,monsterY + MOVE)!=1){
					
					monsterY = monsterY + MOVE;
					if(getpixel(monsterX,monsterY)==14){
						feed = true;
					}
					else{
						feed = false;
					}
					
					
					setcolor(RED);
					setfillstyle(SOLID_FILL,4);	//monster shape
					fillellipse(monsterX,monsterY,10,10);
					
					setcolor(WHITE);
					setfillstyle(SOLID_FILL,1);	//monster eyes
					fillellipse(monsterX-5,monsterY-5,2,2);
					fillellipse(monsterX+5,monsterY-5,2,2);
					keepGoing=true;
				}
				else{
					keepGoing=false;
				}
				break;
			default:break;
		}
		if(!keepGoing){
			move = rand()%4;
		}

		destination=4;
		toss=0;
		
		scoreUpdate(score);
		
		if(score == 0){
			break;
		}
		else if(monsterX==centerX && monsterY==centerY){
			break;
		}
		
	
	}
	cleardevice();
	setcolor(RED);
	settextstyle(font, direction, font_size);
	outtextxy(ROW/3,COLUMN/2-50,"GAME OVER");
    button = getch();
	closegraph();

	return 0;
}

int initMap(){
	initwindow(ROW,COLUMN); 
	setcolor(BLUE);
    setfillstyle(1,1);
	int i,j;
	int score = 0;
	int font = 8;
	int direction = 0;
	int font_size = 2;
	char scoreChar[10];
	
	bar(542,10,552,552);
  	rectangle(542,10,552,552);
  	bar(10,10,20,550);
	rectangle(10,10,20,550);
  	bar(10,542,552,552);
    rectangle(10,542,552,552);
	bar(10,10,550,20);	
	rectangle(10,10,550,20);


	bar(242,41,260,60);
	rectangle(242,41,260,60);
	
	bar(242,501,260,519);
	rectangle(242,501,260,519);
	
	bar(340,242,162,252);
	bar(162,252,172,300);
	bar(340,252,330,300);
	bar(340,300,162,290);
	rectangle(340,242,162,300);
	bar(185,255,317,281);
	
	bar(480,262,362,280);
	rectangle(480,262,362,280);
	
	bar(82,262,140,280);
	rectangle(82,262,140,280);
	
	bar(242,220,260,82);
	rectangle(242,220,260,82);
	
	bar(242,322,260,480);
	rectangle(242,322,260,480);
	
	bar(462,281,480,300);
	rectangle(462,281,480,300);
	
	bar(422,302,440,322);
	rectangle(422,302,440,322);
	
	bar(382,281,401,300);
	rectangle(382,281,401,300);
	
	bar(462,242,480,261);
	rectangle(462,242,480,261);
	
	bar(422,221,439,240);
	rectangle(422,221,439,240);
	
	bar(382,242,401,262);
	rectangle(382,242,401,262);
	
	bar(82,281,101,300);
	rectangle(82,281,101,300);
	
	bar(122,302,141,322);
	rectangle(122,302,141,322);
	
	bar(82,242,101,262);
	rectangle(82,242,101,262);
	
	bar(122,220,141,240);
	rectangle(122,220,141,240);
	
//sol
	bar(42,42,220,60);
	rectangle(42,42,220,60);
	bar(42,42,60,220);
	rectangle(42,42,60,220);
	bar(60,242,42,299);
	rectangle(60,242,42,299);
	bar(60,322,42,519);
	rectangle(60,322,42,519);
	bar(42,519,220,502);
	rectangle(42,519,220,502);
	bar(82,81,220,219);
	rectangle(82,81,220,219);
	bar(82,322,220,480);
	rectangle(82,322,220,480);
	
//sag
	bar(281,42,520,60);
	rectangle(281,42,520,60);
	bar(520,60,502,220);
	rectangle(520,60,502,220);
	bar(502,242,520,299);
	rectangle(502,242,520,299);
	bar(502,322,520,519);
	rectangle(502,322,520,519);
	bar(520,519,281,502);
	rectangle(520,519,281,502);
	bar(480,82,282,220);
	rectangle(480,82,282,220);
	bar(282,480,480,322);
	rectangle(282,480,480,322);
	
	
	//feed
	setfillstyle(14,14);
    fillellipse(31,31,5,5);
    for(i=31;i<559;i=i+20){
    	for(j=31;j<559;j=j+20){
    		if(getpixel(i,j)!=1){
    			score++;
    			fillellipse(i,j,5,5);
			}
		}
	}
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,0);
	bar(185,255,317,281);
	
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,14);
	fillellipse(31,31,10,10);
	
	setcolor(RED);
	setfillstyle(SOLID_FILL,4);	//monster shape
	fillellipse(251,271,10,10);
	
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,1);	//monster eyes
	fillellipse(246,266,2,2);
	fillellipse(256,266,2,2);
	
	setcolor(BLACK);
	rectangle(245,241,247,252);
	rectangle(247,241,249,252);	
	rectangle(253,241,255,252);
	rectangle(255,241,257,252);
	
	
	
	
	int arr1[]={34,31,44,21,44,41,34,31};
	int arr2[]={34,31,44,26,44,36,34,31};
	int arr3[]={34,31,44,29,44,33,34,31};
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,0);
	fillpoly(4,arr1);
	setcolor(YELLOW);
	settextstyle(font, direction, font_size);
	outtextxy(5,ROW-15,"SCORE:");
	sprintf(scoreChar,"%d",score);
	outtextxy(85,ROW-15,scoreChar);
	
	
	
	return score-1;
}
void pacManMovementRight(int centerX,int centerY,int toss){
	int arr1[]={centerX,centerY,centerX+10,centerY-10,centerX+10,centerY+10,centerX,centerY};
	int arr2[]={centerX,centerY,centerX+10,centerY-5, centerX+10,centerY+5, centerX,centerY};
	int arr3[]={centerX,centerY,centerX+10,centerY-2, centerX+10,centerY+2, centerX,centerY};
	int i;
	if(toss==1){
		removeLastPlace(centerX,centerY);
	}
	else{
		removeLastPlace(centerX-MOVE,centerY);
	}
	
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,14);
	fillellipse(centerX,centerY,10,10);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,0);
	fillpoly(4,arr3);
	
	for(i=0;i<2;i++){
			delay(20);
			setcolor(YELLOW);
			setfillstyle(SOLID_FILL,14);
			fillellipse(centerX,centerY,10,10);
			if(i==0){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr2);		
			}
			if(i==1){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr3);		
			}	
	}
	
	for(i=0;i<2;i++){
			delay(20);
			setcolor(YELLOW);
			setfillstyle(SOLID_FILL,14);
			fillellipse(centerX,centerY,10,10);
			if(i==0){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr2);		
			}
			if(i==1){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr1);		
			}			
	}
	
}
void pacManMovementLeft(int centerX,int centerY,int toss){
	int arr1[]={centerX,centerY,centerX-10,centerY-10,centerX-10,centerY+10,centerX,centerY};
	int arr2[]={centerX,centerY,centerX-10,centerY-5, centerX-10,centerY+5, centerX,centerY};
	int arr3[]={centerX,centerY,centerX-10,centerY-2, centerX-10,centerY+2, centerX,centerY};
	int i;
	if(toss==1){
		removeLastPlace(centerX,centerY);
	}
	else{
		removeLastPlace(centerX+MOVE,centerY);
	}
	
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,14);
	fillellipse(centerX,centerY,10,10);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,0);
	fillpoly(4,arr3);
	
	for(i=0;i<2;i++){
			delay(20);
			setcolor(YELLOW);
			setfillstyle(SOLID_FILL,14);
			fillellipse(centerX,centerY,10,10);
			if(i==0){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr2);		
			}
			if(i==1){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr3);		
			}		
		}
		for(i=0;i<2;i++){
			delay(20);
			setcolor(YELLOW);
			setfillstyle(SOLID_FILL,14);
			fillellipse(centerX,centerY,10,10);
			if(i==0){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr2);		
			}
			if(i==1){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr1);		
			}			
		}
	
}
void pacManMovementUp(int centerX,int centerY,int toss){
	int arr1[]={centerX,centerY,centerX-10,centerY-10, centerX+10,centerY-10,centerX,centerY};
	int arr2[]={centerX,centerY,centerX-5, centerY-10, centerX+5, centerY-10, centerX,centerY};
	int arr3[]={centerX,centerY,centerX-2, centerY-10, centerX+2, centerY-10, centerX,centerY};
	int i;
	if(toss==1){
		removeLastPlace(centerX,centerY);
	}
	else{
		removeLastPlace(centerX,centerY+MOVE);
	}
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,14);
	fillellipse(centerX,centerY,10,10);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,0);
	fillpoly(4,arr3);
	for(i=0;i<2;i++){
			delay(20);
			setcolor(YELLOW);
			setfillstyle(SOLID_FILL,14);
			fillellipse(centerX,centerY,10,10);
			if(i==0){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr2);		
			}
			if(i==1){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr3);		
			}		
		}
		for(i=0;i<2;i++){
			delay(20);
			setcolor(YELLOW);
			setfillstyle(SOLID_FILL,14);
			fillellipse(centerX,centerY,10,10);
			if(i==0){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr2);		
			}
			if(i==1){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr1);		
			}			
		}
	
}
void pacManMovementDown(int centerX,int centerY,int toss){
	int arr1[]={centerX,centerY,centerX-10,centerY+10, centerX+10,centerY+10,centerX,centerY};
	int arr2[]={centerX,centerY,centerX-5, centerY+10, centerX+5, centerY+10, centerX,centerY};
	int arr3[]={centerX,centerY,centerX-2, centerY+10, centerX+2, centerY+10, centerX,centerY};
	int i;
	if(toss==1){
		removeLastPlace(centerX,centerY);
	}
	else{
		removeLastPlace(centerX,centerY-MOVE);
	}
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,14);
	fillellipse(centerX,centerY,10,10);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,0);
	fillpoly(4,arr3);
	
	for(i=0;i<2;i++){
			delay(20);
			setcolor(YELLOW);
			setfillstyle(SOLID_FILL,14);
			fillellipse(centerX,centerY,10,10);
			if(i==0){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr2);		
			}
			if(i==1){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr3);		
			}		
		}
		for(i=0;i<2;i++){
			delay(20);
			setcolor(YELLOW);
			setfillstyle(SOLID_FILL,14);
			fillellipse(centerX,centerY,10,10);
			if(i==0){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr2);		
			}
			if(i==1){			
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,0);
				fillpoly(4,arr1);		
			}			
		}
	
}
void removeLastPlace(int centerX,int centerY){

	setcolor(BLACK);
	setfillstyle(SOLID_FILL,0);
	fillellipse(centerX,centerY,10,10);
}
void scoreUpdate(int score){
	char scoreChar[10];
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,0);
	bar(80,ROW-20,90,ROW-5);
	setcolor(YELLOW);
	sprintf(scoreChar,"%d",score);
	outtextxy(85,ROW-15,scoreChar);
}


