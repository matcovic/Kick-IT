#ifndef myVariables_H_INCLUDED
#define myVariables_H_INCLUDED
#include<math.h>
#include<string.h>
#include<stdio.h>

#define countriesNumber 5
#define g 9.8/100
#define PI 3.14159265

int gameReset=0;

int width = 1000, height = 600;
int NewGame, MenuControl, MenuAbout, MenuRank, MenuBack;
int menu, about, controls, rank1, back, backGround, selection_menu, gameOverScreen;

int goalPost;
int goalPost_Width = 120, goalPost_Height = 50;
int goalPostX = 258, goalPostY = 28;

char groundKick_pic_0_[9][100]= {"bangladesh\\groundKick\\1.png", "bangladesh\\groundKick\\2.png", "bangladesh\\groundKick\\3.png", "bangladesh\\groundKick\\4.png", "bangladesh\\groundKick\\5.png", "bangladesh\\groundKick\\6.png", "bangladesh\\groundKick\\7.png", "bangladesh\\groundKick\\8.png", "bangladesh\\groundKick\\9.png"};
char groundKick_pic_1_[9][100]= {"argentina\\groundKick\\1.png", "argentina\\groundKick\\2.png", "argentina\\groundKick\\3.png", "argentina\\groundKick\\4.png", "argentina\\groundKick\\5.png", "argentina\\groundKick\\6.png", "argentina\\groundKick\\7.png", "argentina\\groundKick\\8.png", "argentina\\groundKick\\9.png"};
char groundKick_pic_2_[9][100]= {"england\\groundKick\\1.png", "england\\groundKick\\2.png", "england\\groundKick\\3.png", "england\\groundKick\\4.png", "england\\groundKick\\5.png", "england\\groundKick\\6.png", "england\\groundKick\\7.png", "england\\groundKick\\8.png", "england\\groundKick\\9.png"};
char groundKick_pic_3_[9][100]= {"germany\\groundKick\\1.png", "germany\\groundKick\\2.png", "germany\\groundKick\\3.png", "germany\\groundKick\\4.png", "germany\\groundKick\\5.png", "germany\\groundKick\\6.png", "germany\\groundKick\\7.png", "germany\\groundKick\\8.png", "germany\\groundKick\\9.png"};
char groundKick_pic_4_[9][100]= {"portugal\\groundKick\\1.png", "portugal\\groundKick\\2.png", "portugal\\groundKick\\3.png", "portugal\\groundKick\\4.png", "portugal\\groundKick\\5.png", "portugal\\groundKick\\6.png", "portugal\\groundKick\\7.png", "portugal\\groundKick\\8.png", "portugal\\groundKick\\9.png"};

int countryState;
int stand[5];
int groundKickImageIndex=0;

bool GROUNDKICK = false;

bool ballKickedDone = false;
int characterX = 0;
int characterY = 23;
int characterWidth = 80;
int characterHeight = 100;
int point =0;
struct Player
{
	int groundKick[9];
};
Player player[countriesNumber];

///////////////  Ball ///////////////////
int ball;
int ballWidth = 40;
int ballHeight = 40;

///////////////  Projectile  ////////////////////////
int xCircle = 83;
int yCircle = 23;
int radius = 80;
double qeta = 0;

int xLine = xCircle + (radius + 15)*cos(qeta * PI / 180);
int yLine = yCircle + (radius + 15)*sin(qeta * PI / 180);

int ballX;
int ballY;
int ball_start_positionX = 63;
int ball_start_positionY = 23;


int v = 10;
int vx = v*cos(qeta*PI / 180);
int vy = v*sin(qeta*PI / 180);

int i = 0;
int ballKicked = 0;
int timeChange = 1;
int timeMax;
int rMax;

char totalName[100][100];
int numberArray[100];
int arrayIndex = 0, stringIndex = 0;
bool activeAppending = false;
bool isNamePlateActive = true;
int flag;
int length = 0;
char nameOfUser[100];

#endif // myVariables_H_INCLUDED