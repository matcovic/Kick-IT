#include "iGraphics.h"
#include<math.h>
#include "myVariables.h"
#include "loadingPictures.h"
#include "score.h"


void MainMenu()
{
	iShowImage(0, 0, 1000, 600, menu);
	
}

//For Showing Back Button; called from iDraw method;return type void
void backButton()
{
	iShowImage(3, 540, 207, 37, back);
}

//For Showing Movable Goal Post; called from iDraw method;return type void
void set_goalPost()
{
	goalPostX= rand()%700+ characterX+ball_start_positionX+characterWidth+ballWidth;
	gameReset++;
}

/*shows the name of the gamer from keyboard;called from iDraw;return type void*/
void userName()
{
	if (flag == 0)
	{
		iSetColor(0, 0, 255);
		iRectangle(54, 281, 317, 62);
		iText(68, 293, nameOfUser);
		printf(nameOfUser);
	}
	if (flag == 1)
	{
		iSetColor(255,0, 0);
		iRectangle(54, 281, 317, 62);		
		iText(68, 293, nameOfUser, GLUT_BITMAP_TIMES_ROMAN_24);
	}
}
/*
/*append scores into a file for the COP part;called from iDraw;return type void*/
void appendHighScore(char userName[], int points)
{
	FILE *fp = fopen("Highscores.txt", "a");

	if (fp != NULL)
	{
		fprintf(fp, "%s\n", userName);
		fprintf(fp, "%d\n", points);
	}

	fclose(fp);
	activeAppending=false;
}

/*read the highest all scores from the COP file;called from iMain and iDraw method;return type void*/
void readHighScore()
{
	FILE *fp = fopen("Highscores.txt", "r");
	char str[100];
	arrayIndex = 0, stringIndex = 0;

	if (fp != NULL)
	{
		while (fgets(str, 30, fp) != NULL)
		{
			
			strcpy(totalName[stringIndex++], str);
			fgets(str, 15, fp);
			numberArray[arrayIndex++] = atoi(str);	
		}
	}
	fclose(fp);
}

/*sorting all the scores saved into the file in descending order;called from highScoreShow method which is from iDraw;return type void*/
void sortingHighScore()
{
	int temp;
	char t[100];

	for (int i = 0; i < arrayIndex - 1; i++)
	{
		for (int j = 0; j < arrayIndex - 1; j++)
		{
			if (numberArray[j] < numberArray[j + 1])
			{
				temp = numberArray[j];
				numberArray[j] = numberArray[j + 1];
				numberArray[j + 1] = temp;
				strcpy(t, totalName[j]);
				strcpy(totalName[j], totalName[j + 1]);
				strcpy(totalName[j + 1], t);
			}
		}
	}
}

/*showing the top five scores from file of COP part and call the sortingHighScore method;called from iDraw;return type void*/
void highScoreShow()
{
	sortingHighScore();
	
	for (int k = 0, y = 370; k < 5; k++, y -= 53)
	{
		char str[100];

		if (numberArray[k]>0)
		{
			_itoa(numberArray[k], str, 10);
			iSetColor(0, 0, 0);
			//name
			iText(144, y, totalName[k], GLUT_BITMAP_TIMES_ROMAN_24);
			//score
			iText(662, y, str, GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
}



void iDraw()
{
	iClear();
	MainMenu();
	

	//::::::::::::::::::::::::::::::::::::::::Here all the menu info can be seen:::::::::::::::::::::::::::::::::::::::::://

	if(NewGame == 1)
	{
		iClear();
		iShowImage(0, 0, 1000, 600, selection_menu);
	}

	else if (NewGame == 2)
	{	
		iClear();

		//Ends after taking 10 shots
		if(gameReset<10)
		{	
			
			iShowImage(0, 0, 1000, 600, backGround);
			iSetColor(0, 0, 0);
			iLine(xCircle, yCircle, xLine, yLine);
			iShowImage(ball_start_positionX + ballX, ball_start_positionY + ballY, ballWidth, ballHeight, ball);
			iShowImage(goalPostX, goalPostY, goalPost_Width, goalPost_Height, goalPost);
			score();

			if(  ballX + ball_start_positionX>= goalPostX &&  ballX + ball_start_positionX  <= goalPostX+goalPost_Width && goalPostY <= ball_start_positionY + ballY && goalPost_Height+goalPostY >= ball_start_positionY + ballY)
			{

				ballKickedDone = true;

			}
			else if(GROUNDKICK)
			{
				iShowImage(characterX, characterY, characterWidth, characterHeight, player[countryState].groundKick[groundKickImageIndex]);
			}
			else
			{
				iShowImage(characterX, characterY, characterWidth, characterHeight, stand[countryState]);
			}
		}
		else 
		{
			iShowImage(0, 0, 1000, 600, gameOverScreen);
			score_show();
			userName();

			if (activeAppending == true)
			{
				appendHighScore(nameOfUser, point);
			}
			
		}
	
	}
	else if (MenuControl == 1)
	{
		iClear();
		iShowImage(0, 0, 1000, 600, controls);	
		backButton();
	}
	else if (MenuRank == 1)
	{
		iClear();
		iShowImage(0, 0, 1000, 600, rank1);

		readHighScore();
		highScoreShow();

		backButton();
	}
	else if (MenuAbout == 1)
	{
		iClear();
		iShowImage(0, 0, 1000, 600, about);
		backButton();
	}
	else if (MenuBack == 1)
	{
		iClear();
		iShowImage(0, 0, 1000, 600, menu);

	}
	
}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(NewGame == 2){
		if (isNamePlateActive == true)
		{
			if (mx >= 54 && mx <= 370 && my >= 282 && my <= 341)
			{
				flag = 1;
			}
		}
		}
		
		

		//::::::::::::::::::::::::::::::::::::::::::::::::NewGame Button Activation:::::::::::::::::::::::::::::::::::::::::::::::::::::://
		
		else if (mx >= 370 && mx <= 600 && my >= 223 && my <= 269 && MenuControl != 1 && MenuAbout != 1 && MenuRank != 1)
		        {

				    NewGame = 1;
					MenuControl = 0;
					MenuRank = 0;
					MenuAbout = 0;
					MenuBack = 0;
					
		        }	
		        //:::::::::::::::::::::::::::::::::::::::::::::::::::::::Control Button Activation::::::::::::::::::::::::::::::::::::::::::::::::::::://
				else if (mx >= 370 && mx <= 600 && my >= 169 && my <= 212 && MenuRank != 1 && MenuAbout != 1 && NewGame != 1)
				{
					
					NewGame = 0;
					MenuControl = 1;
					MenuRank = 0;
					MenuAbout = 0;
					MenuBack = 0;


				}
				//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Rank Button Activation::::::::::::::::::::::::::::::::::::::::::::::::::::://
				else if (mx >= 370 && mx <= 600 && my >= 115 && my <= 162 && MenuControl != 1 && MenuAbout != 1 && NewGame!=1)
				{
					
					NewGame = 0;
					MenuControl = 0;
					MenuRank = 1;
					MenuAbout = 0;
					MenuBack = 0;

				}
				//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Back Button Activation:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
				else if (mx >= 4 && mx <= 207 && my >= 543 && my <= 575)
				{
					
					NewGame = 0;
					MenuControl = 0;
					MenuRank = 0;
					MenuAbout = 0;
					MenuBack = 1;

				}
				//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::About Button Activation::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
				else if (mx >= 370 && mx <= 600 && my >= 63 && my <= 107 && MenuControl != 1 && MenuRank != 1 && NewGame != 1)
				{
					
					NewGame = 0;
					MenuControl = 0;
					MenuRank = 0;
					MenuAbout = 1;
					MenuBack = 0;

				}

				//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Quit Button Activation::::::::::::::::::::::::::::::::::::::::::::::::::::::://
				else if (mx >= 372 && mx <= 600 && my >= 8 && my <= 53 && MenuControl != 1 && MenuRank != 1 && NewGame != 1 && MenuAbout!=1)
				{

					exit(0);
				}
				//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Bangladesh Button Activation::::::::::::::::::::::::::::::::::::::::::::::::::::::://

				else if (mx >= 197 && mx <= 420 && my >= 299 && my <= 337)
				{
					NewGame = 2;
					MenuControl = 0;
					MenuRank = 0;
					MenuAbout = 0;
					MenuBack = 0;
					countryState = 0;
				}

				//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Argentina Button Activation::::::::::::::::::::::::::::::::::::::::::::::::::::::://

				else if (mx >= 197 && mx <= 420 && my >= 252 && my <= 288)
				{
					NewGame = 2;
					MenuControl = 0;
					MenuRank = 0;
					MenuAbout = 0;
					MenuBack = 0;
					countryState = 1;
				}
				//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::England Button Activation::::::::::::::::::::::::::::::::::::::::::::::::::::::://

				else if (mx >= 197 && mx <= 420 && my >= 202 && my <= 243)
				{
					NewGame = 2;
					MenuControl = 0;
					MenuRank = 0;
					MenuAbout = 0;
					MenuBack = 0;
					countryState = 2;
				}
				//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Germany Button Activation::::::::::::::::::::::::::::::::::::::::::::::::::::::://

				else if (mx >= 197 && mx <= 420 && my >= 158 && my <= 194)
				{
					NewGame = 2;
					MenuControl = 0;
					MenuRank = 0;
					MenuAbout = 0;
					MenuBack = 0;
					countryState = 3;
				}
				//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Portugal Button Activation::::::::::::::::::::::::::::::::::::::::::::::::::::::://

				else if (mx >= 197 && mx <= 420 && my >= 115 && my <= 154)
				{					
					NewGame = 2;
					MenuControl = 0;
					MenuRank = 0;
					MenuAbout = 0;
					MenuBack = 0;
					countryState = 4;
				}
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}


/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}

void iPassiveMouse(int mx, int my)
{
  //printf("x = %d, y= %d\n", mx, my);
}


/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{
		flag = 0;
		activeAppending = true;
		isNamePlateActive = false;
	}
	if (flag == 1)
	{
		if (key == 8)
		{
			if (length > 0)
			{
				nameOfUser[--length] = ' ';
			}
		}
		else
		{
			nameOfUser[length] = key;
			puts(nameOfUser);
			length++;
		}	
	}
	
	else if(key == ' ')
	{
		ballKicked = 1;

		if(!GROUNDKICK)
		{
			GROUNDKICK = true;
			
		}
	}
}


/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_UP)
	{
		if (qeta <= 80 && ballKicked == 0)
		{
			qeta += 5;
			xLine = xCircle + (radius + 15)*cos(qeta * PI / 180);
			yLine = yCircle + (radius + 15)*sin(qeta * PI / 180);
			vx = v*cos(qeta*PI / 180);
			vy = v*sin(qeta*PI / 180);
			timeMax = v*sin(qeta*PI / 180) / g;
			rMax = v*v*sin(2 * qeta*PI / 180) / g;
		}
	}
	else if (key == GLUT_KEY_DOWN)
	{
		if (qeta >= 0 && ballKicked == 0)
		{	
			qeta -= 5;
			xLine = xCircle + (radius + 15)*cos(qeta * PI / 180);
			yLine = yCircle + (radius + 15)*sin(qeta * PI / 180);
			vx = v*cos(qeta*PI / 180);
			vy = v*sin(qeta*PI / 180);
			timeMax = v*sin(qeta*PI / 180) / g;
			rMax = v*v*sin(2 * qeta*PI / 180) / g;
		}
	}
	else if (key == GLUT_KEY_END)
	{
		exit(0);
	}
}

//////////Funtion for SetTimer////////
void change()
{
	if(GROUNDKICK)
	{
		groundKickImageIndex++;
			if(groundKickImageIndex>=9)
			{
				groundKickImageIndex = 0;
				GROUNDKICK = false;
			}
	}

	////////Projectile////////
	if (ballKicked == 1)
	{
		ballX = v*cos(qeta*PI / 180)*timeChange;
		ballY = ballX*tan(qeta*PI / 180) - 0.5*g*ballX*ballX / (v*cos(qeta*PI / 180)) / (v*cos(qeta*PI / 180));

		if (timeChange != timeMax)
			timeChange++;

		if (ballY < 0)
		{
			timeChange = 1;
			timeMax = 0;
			ballKicked = 0;
			ballX = ballY = 0;
			if(ballKickedDone)
			{
				++point;
				ballKickedDone = false;
			}
			
			set_goalPost();
		}
	}
	
}



int main()
{
	iSetTimer(10, change);
	iInitialize(width, height, "Kick It");

	loadPicture();

	readHighScore();
		
	iStart();
}

