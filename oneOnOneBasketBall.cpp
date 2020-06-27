#include "iGraphics.h"

int x=0,count1=1,count2=0; //x for loading, count1 for blink, count2 for loading
int r=255,g=255,b=255; //r,g,b for color
int pageIndex=0; //pageIndex to indicate page number
int loadingTimer=0; //LoadingTimer for the index of setTimer

bool musicon=true;
double xStage[4]={0,140,1030,1200};

double yStage[4]={0,230,230,0};

double xlathi[4]={65,105,140,110};

double ylathi[4]={90,155,155,94};

double x1lathi[4]={1120,1075,1038,1073};

double y1lathi[4]={90,155,152,94};

double xUchaBamPash[4]={0,0,140,140};
double yUchaBamPash[4]={0,70,270,230};

double xUchaDanPash[4]={1200,1200,1028,1028};
double yUchaDanPash[4]={0,70,270,230};

double x1Basket[4]={120,120,212,212};
double y1Basket[4]={312,418,440,360};

double x1BasketBhitor[4]={150,150,200,200};
double y1BasketBhitor[4]={386,338,364,405};

double x1BasketBhitorKalo[4]={154,154,196,196};
double y1BasketBhitorKalo[4]={381,345,368,398};

double x2Basket[4]={1065,1065,973,973};
double y2Basket[4]={312,418,440,363};

double x2BasketBhitor[4]={1035,1035,985,985};
double y2BasketBhitor[4]={386,338,364,405};

double x2BasketBhitorKalo[4]={1030,1030,990,990};
double y2BasketBhitorKalo[4]={382,345,367,397};


double x1ChotoDandi[4]={85,120,130,100};
double y1ChotoDandi[4]={323,350,345,320};

double x2ChotoDandi[4]={1082,1097,1064,1057};
double y2ChotoDandi[4]={323,323,355,348};

double xBoundary[4]={80,172,1000,1110};
double yBoundary[4]={10,220,220,10};

double xBoundary1[4]={90,177,995,1100};
double yBoundary1[4]={15,215,215,15};


double xdanCircleFill[4]={860,860,1020,1070};
double ydanCircleFill[4]={92,144,172,75};


//for character rendering for Blake Griffin Forword

char bg[18][35] = {"Black Griffin Forward\\5.bmp","Black Griffin Forward\\6.bmp","Black Griffin Forward\\7.bmp","Black Griffin Forward\\8.bmp","Black Griffin Forward\\9.bmp","Black Griffin Forward\\10.bmp","Black Griffin Forward\\11.bmp","Black Griffin Forward\\12.bmp","Black Griffin Forward\\13.bmp","Black Griffin Forward\\14.bmp","Black Griffin Forward\\15.bmp","Black Griffin Forward\\16.bmp","Black Griffin Forward\\17.bmp","Black Griffin Forward\\18.bmp","Black Griffin Forward\\19.bmp","Black Griffin Forward\\20.bmp","Black Griffin Forward\\21.bmp"};
int bgX = 120, bgY = 100;
int bgIndex = 0;

//For Character Rendering for Lebron James Backword
char lj[16][35] = {"Lebron James Backword\\1.bmp","Lebron James Backword\\2.bmp","Lebron James Backword\\3.bmp","Lebron James Backword\\4.bmp","Lebron James Backword\\5.bmp","Lebron James Backword\\6.bmp","Lebron James Backword\\7.bmp","Lebron James Backword\\8.bmp","Lebron James Backword\\9.bmp","Lebron James Backword\\10.bmp","Lebron James Backword\\11.bmp","Lebron James Backword\\12.bmp","Lebron James Backword\\13.bmp","Lebron James Backword\\14.bmp","Lebron James Backword\\15.bmp","Lebron James Backword\\16.bmp"};
int ljX=850, ljY=110;
int ljIndex = 0;

void iDraw()
{
	iClear();


	if(pageIndex==0)
	{
		iShowBMP (0,0,"Images\\FirstPage.bmp"); //image for the first page

		iSetColor (r,g,b); //rgb to change font color
		iText (65,55,"Press [N] to continue...", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	else if (pageIndex==1)
	{
		iSetColor (r,g,b);
		iShowBMP (0,0,"Images\\Menu Page.bmp");
		iText (970,46,"Press [B] to return...",GLUT_BITMAP_HELVETICA_18);

		iSetColor(255,255,255); //Outer Rectangle

		iFilledRectangle(102.5,312.5,196,66);
		iFilledRectangle(102.5,132.5,196,66);
		iFilledRectangle(892.5,312.5,196,66);
		iFilledRectangle(892.5,132.5,196,66);

		iSetColor (100,100,100); //Inner Rectangle

		iFilledRectangle(105,315,190,60);
		iFilledRectangle(105,135,190,60);
		iFilledRectangle(895,315,190,60);
		iFilledRectangle(895,135,190,60);

		iSetColor (0,0,0);

		//Border for outer Rectangle
		iRectangle(102.5,312.5,196,66);
		iRectangle(102.5,132.5,196,66);
		iRectangle(892.5,312.5,196,66);
		iRectangle(892.5,132.5,196,66);

		//border for inner Rectangle
		iRectangle(105,315,190,60);
		iRectangle(105,135,190,60);
		iRectangle(895,315,190,60);
		iRectangle(895,135,190,60);

		//texts for the button
		iText (155,340,"Play Game", GLUT_BITMAP_HELVETICA_18);
		iText (150,160,"Instruction", GLUT_BITMAP_HELVETICA_18);
		iText (950,340,"High Score", GLUT_BITMAP_HELVETICA_18);
		iText (955,160,"CREDITS", GLUT_BITMAP_HELVETICA_18);
	}

	else if (pageIndex==2)
	{
		iShowBMP (0,0,"Images\\FirstPage.bmp");
		iSetColor(0,180,0);

		iText (85,85,"Loading...", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(35,50,250,10);
		iFilledRectangle (35,50,0+x,10);



		if(count2==6)
		{
			//for background
			iSetColor(178,190,181);
			iFilledRectangle(0,0,1200,600);
			//for background*

			//for stage
			iSetColor(255,222,173);
			iFilledPolygon(xStage,yStage,4);
			iSetColor(178,190,200);
			iFilledPolygon(xlathi,ylathi,4);
			iFilledPolygon(x1lathi,y1lathi,4);

			iSetColor(110,0,50);//uporer ucha part stage er pashe
			iFilledRectangle(140,230,888,40);
			iFilledPolygon( xUchaBamPash, yUchaBamPash,4);
			iFilledPolygon( xUchaDanPash, yUchaDanPash,4);

			//iFilledPolygon(xBasket,yBasket,4);
			iSetColor(00,50,70);
			iFilledRectangle(85,123,15,200);

			//dandi1
			iFilledPolygon(x1ChotoDandi,y1ChotoDandi,4);
			iFilledPolygon(x1Basket,y1Basket,4);
			iFilledRectangle(1082,123,15,200);

			//dandi2
			iFilledPolygon(x2ChotoDandi,y2ChotoDandi,4);
			iFilledPolygon(x2Basket,y2Basket,4);

			///basket1 er bhitorer shada box and again kalobox
			iSetColor(255,255,255);
			iFilledPolygon(x1BasketBhitor,y1BasketBhitor,4);

			iSetColor(00,50,70);
			iFilledPolygon(x1BasketBhitorKalo,y1BasketBhitorKalo,4);

			//basket 2 er bhitorer shada box and again kalobox
			iSetColor(255,255,255);
			iFilledPolygon(x2BasketBhitor, y2BasketBhitor,4);

			iSetColor(00,50,70);
			iFilledPolygon(x2BasketBhitorKalo,y2BasketBhitorKalo,4);

			//shada boundary and bhitrer boundary
			iSetColor(255,255,255);
			iFilledPolygon( xBoundary, yBoundary,4);
			iSetColor(255,222,173);
			iFilledPolygon( xBoundary1, yBoundary1,4);



			//for center
			iSetColor(255,255,255);
			iFilledEllipse(592,118,95,30,200);
			iSetColor(255,222,173);
			iFilledEllipse(592,118,88,25,200);

			//majher lathi
			iSetColor(255,255,255);
			iFilledRectangle(590,10,6,210);


			//scoreboard
			iSetColor(165,42,42);
			iFilledRectangle(478,440,235,120);

			//for scoreboard
			iSetColor(255,255,255);
			iFilledRectangle(490,450,100,100);
			iFilledRectangle(600,450,100,100);


			iShowBMP2 (175,331,"Images\\Left Basket.bmp",0);
			iShowBMP2 (951,331,"Images\\Right Basket.bmp",0);

			iShowBMP2 (bgX,bgY,bg[bgIndex],0);
			iShowBMP2 (ljX,ljY,lj[ljIndex],0);
		}


	}

	else if (pageIndex==3)
	{
		iShowBMP (0,0,"Images\\Instructions.bmp");
	}

	else if (pageIndex==4)
	{
		iShowBMP (0,0,"Images\\Highscores.bmp");
	}

	else if (pageIndex==5)
	{
		iShowBMP (0,0,"Images\\Credit.bmp");
	}
}

//Function for color change or blink
void colorChange ()
{
	if (count1==1)
	{
		r-=51;
		g-=51;
		b-=51;
		if(r==0 && g==0 && b==0) count1=0;
	}
	else if (count1==0)
	{
		r+=51;
		g+=51;
		b+=51;
		if(r==255 && g==255 && b==255) count1=1;
	}
}

//Function for loading part
void loadingPart ()
{
	if (pageIndex==2)
	{
		count2++;
		x=x+50;
		if(x>250)
		{
			iPauseTimer (loadingTimer);
		}
	}
}

//Function for char rendering of BG
void charRenderingPositive ()
{
	bgIndex++;
	if (bgIndex>=17) bgIndex=0;

	bgX+=10;
	if (bgX>=450) bgX=450;
}

void charRenderingNegetive ()
{
	if (bgIndex<=0) bgIndex=17;
	bgIndex--;

	bgX-=10;
	if (bgX<=120) bgX=120;
}

//Function for char rendering of LJ
void ljCharRenderingPositive ()
{
	if (ljIndex<=0) ljIndex=15;
	ljIndex--;

	ljX+=10;
	if (ljX>=850) ljX=850;
}


void ljCharRenderingNegetive ()
{
	ljIndex++;
	if (ljIndex>=15) ljIndex=0;

	ljX-=10;
	if (ljX<=500) ljX=500;
}


void iMouseMove(int mx, int my)
{

}

void iPassiveMouseMove(int mx, int my)
{




}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("%d %d ",mx,my);

		if ((mx>=102.5 && mx<298.5) && (my>=317.5 && my<=378.5))
		{
			if (pageIndex==1) pageIndex=2;
		}

		else if ((mx>=102.5 && mx<298.5) && (my>=132.5 && my<=198.5))
		{
			if (pageIndex==1) pageIndex=3;
		}

		else if ((mx>=892.5 && mx<1082.5) && (my>=317.5 && my<=378.5))
		{
			if (pageIndex==1) pageIndex=4;
		}

		else if ((mx>=892.5 && mx<1082.5) && (my>=132.5 && my<=198.5))
		{
			if (pageIndex==1) pageIndex=5;
		}
	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}




void iKeyboard(unsigned char key)
{
	if (key == 'N' || key == 'n')
	{
		if (pageIndex==0) pageIndex=1;
		else if (pageIndex==1)
		{
			pageIndex=2;
		}

	}

	else if (key == 'B' || key == 'b')
	{
		if (pageIndex==2)
		{
			pageIndex=1;
			count2=0;
			x=0;
			iResumeTimer (loadingTimer);
		}
		else if (pageIndex==1) pageIndex=0;
		else if (pageIndex==3) pageIndex=1;
		else if (pageIndex==4) pageIndex=1;
		else if (pageIndex==5) pageIndex=1;
	}

	else if (key == 'D' || key == 'd')
	{
		if (count2==6) charRenderingPositive();
	}

	else if (key == 'A' || key == 'a')
	{
		if (count2==6) charRenderingNegetive();
	}

}


void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_RIGHT)
	{
		if (count2==6) ljCharRenderingPositive();
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (count2==6) ljCharRenderingNegetive();
	}

	if (key == GLUT_KEY_HOME)
	{

	}

}


int main()
{
	srand((unsigned)time(NULL));
	if(musicon)
	{
		PlaySound ("Music\\bmusic.wav",NULL,SND_LOOP | SND_ASYNC);
	}

	iSetTimer (50,colorChange);

	loadingTimer = iSetTimer (1000,loadingPart);

	iInitialize(1200, 600, "One On One BasketBall");

	iStart();
	return 0;
}
