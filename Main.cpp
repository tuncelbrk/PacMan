#include<conio.h>
#include<graphics.h>
void initMap();
int main()
#define ROW 579
#define COLUMN 579
{    
	int x1=21,y1=21,x2=41,y2=41,i;
	int ek=20;
	char button,tus;
	int centerX,centerY;
	initMap();
	
	
	
	
	
	

	while(1){
		button = getch();
		
		setcolor(BLACK);
		
		rectangle(x1,y1,x2,y2);
		
		setcolor(BLACK);
		setfillstyle(SOLID_FILL,0);
		bar(x1+1,y1+1,x2,y2);
		
		centerX = (x1+x2)/2;
		centerY = (y1+y2)/2;
		switch(button){
			case 27:
				exit(0);
			case 77: //right
				if(getpixel(centerX+ek,centerY)!=1){
					x1+=ek;
					x2+=ek;
				}break;
			case 75: //left
				if(getpixel(centerX-ek,centerY)!=1){
					x1-=ek;
					x2-=ek;
				}break;				
			case 72: //up
				if(getpixel(centerX,centerY-ek)!=1){
					y1-=ek;
					y2-=ek;
				}break;
			case 80: //down
				if(getpixel(centerX,centerY+ek)!=1){
					y1+=ek;
					y2+=ek;
				}break;
		}
		setcolor(WHITE);
		rectangle(x1,y1,x2,y2);

			
		
	}
	      
/*	while(1)
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
		//printf("x1=%d,y1=%d",x1,y1);
		printf("%d",getpixel((x1+x2)/2,(y1+y2)/2));
		
		}

	}*/
	closegraph();

	return 0;
}

void initMap(){
	initwindow(ROW,COLUMN); 
	setcolor(BLUE);
    setfillstyle(1,1);
	int i,j;
	
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
	
	rectangle(340,242,162,300);
	
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
    			fillellipse(i,j,5,5);
			}
		}
	}
	//circle(31,31,5);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,0);
	bar(339,243,163,299);
	
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,14);
	fillellipse(34,31,10,10);
	int arr1[]={34,31,44,21,44,41,34,31};
	int arr2[]={34,31,44,26,44,36,34,31};
	int arr3[]={34,31,44,29,44,33,34,31};
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,0);
	fillpoly(4,arr3);
/*	
	while(1){
		for(i=0;i<2;i++){
			delay(50);
			setcolor(YELLOW);
			setfillstyle(SOLID_FILL,14);
			fillellipse(34,31,10,10);
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
			delay(50);
			setcolor(YELLOW);
			setfillstyle(SOLID_FILL,14);
			fillellipse(34,31,10,10);
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
		
		
	}*/
	
	
	
}

