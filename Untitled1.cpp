#include<conio.h>
#include<graphics.h>

int main()
{    
	int x1=21,y1=21,x2=41,y2=41,i;
	int ek=20;
	char tus;
	initwindow(600,600); 
	setcolor(BLUE);
    setfillstyle(1,1);

	bar(542,10,552,552);
  	rectangle(542,10,552,552);
  	bar(10,10,20,550);
	rectangle(10,10,20,550);
  	bar(10,542,552,552);
    rectangle(10,542,552,552);
	bar(10,10,550,20);	
	rectangle(10,10,550,20);
	
	
	setcolor(WHITE);
	rectangle(x1,y1,x2,y2);        
	while(1)
	{      	      
		tus= getch();
		if(tus==27) exit(0);
		else 
		{   
		setcolor(BLACK);
		rectangle(x1,y1,x2,y2);
		if(tus==77) //right
		{ 
			if(x2+ek<542){
				x1+=ek; 
				x2+=ek; 
			}
		}
		else if(tus==75)//left
		{
			if(x1-ek >20){
			
				x1-=ek; 
				x2-=ek; 
			}	
		}
		else if(tus==72)//up
		{
			if(y1-ek > 20){
			
				y1-=ek; 
				y2-=ek;
			}
		}
		else if(tus==80)//down
		{
			if(y2+ek<542){
			
				y1+=ek; 
				y2+=ek;  
			}
		}
		setcolor(WHITE);
		rectangle(x1,y1,x2,y2);
		}

	}
	closegraph();

	return 0;
}
