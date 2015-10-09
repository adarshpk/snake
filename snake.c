#include<stdio.h>
#include<graphics.h>
#include<X11/Xlib.h>
#define eatfrog x>=xf-5&&x<=xf+5&&y>=yf-5&&y<=yf+5
#define inside x>40&&x<600&&y>40&&y<450

int main()
{
    XInitThreads();//Used in hope of stopping assertion errors.   
    int initsnake();
    int gd=DETECT, gm=VGAMAX;
    initgraph(&gd,&gm,0);
    int sc=initsnake(); //calling game function
    outtextxy(275,240,"GAME OVER!!!");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t  SCORE = %d",sc);
    getch();
    closegraph();
    return 0;
}

int x=200,y=200,ch='d',xf,yf;
int speed=10,flag=1,score=0;

int initsnake()
{
	void plotfrog();
	while(inside)
	{
    		cleardevice();
		rectangle(35,35,605,455);
		outtextxy(250,20,"CLASSIC SNAKE GAME");
		switch(ch)
		{
			case 'a':
		    		x=x-speed;	    		
		    		break;
		    	case 'd':
		    		x=x+speed;
		    		break;
		    	case 'w':
		    		y=y-speed;
		    		break;
		    	case 's':
		    		y=y+speed;
		    		break;
		}
		plotfrog();
		if(eatfrog)
	    	{
			score++;
			flag=1;
		}			 
    		rectangle(x-5,y-5,x+5,y+5);
		if(kbhit())
		 	ch=getch();
    }   
    return score;
}
void plotfrog()
{
	if(flag)
	{
		xf=rand()%600;
		if(xf<40)
			xf+=40;		
		yf=rand()%450;
		if(yf<40)
			yf+=40;	
		flag=0;
	}
	rectangle(xf,yf,xf+5,yf+5);
}
