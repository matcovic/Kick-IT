#ifndef loadingPictures_H_INCLUDED
#define loadingPictures_H_INCLUDED
#include "myVariables.h"

/*loads all the pictures in this game;called from iMain;return type void*/

void loadPicture()
{

	menu = iLoadImage("menu.png");
	about = iLoadImage("about.png");
	controls = iLoadImage("controls.png");
	rank1 = iLoadImage("rank.png");
	back = iLoadImage("backButton.png");
	backGround = iLoadImage("backGround.png");
	selection_menu = iLoadImage("selection.png");
	gameOverScreen = iLoadImage("gameover.png");
	ball = iLoadImage("ball.png"); 
	goalPost = iLoadImage("goalpost.png");

	///////////////////For Bangladesh/////////////////////
	for(int i =0;i<9;i++)
	{
		player[0].groundKick[i] = iLoadImage(groundKick_pic_0_[i]);
	}
	stand[0] = iLoadImage("stand0.png");

	///////////////////For Argentina/////////////////////
	for(int i =0;i<9;i++)
	{
		player[1].groundKick[i] = iLoadImage(groundKick_pic_1_[i]);
	}
	stand[1] = iLoadImage("stand1.png");

	///////////////////For England/////////////////////
	for(int i =0;i<9;i++)
	{
		player[2].groundKick[i] = iLoadImage(groundKick_pic_2_[i]);
	}
	stand[2] = iLoadImage("stand2.png");
	
	///////////////////For Germany/////////////////////
	for(int i =0;i<9;i++)
	{
		player[3].groundKick[i] = iLoadImage(groundKick_pic_3_[i]);
	}
	stand[3] = iLoadImage("stand3.png");

	///////////////////For Portugal/////////////////////
	for(int i =0;i<9;i++)
	{
		player[4].groundKick[i] = iLoadImage(groundKick_pic_4_[i]);
	}	
	stand[4] = iLoadImage("stand4.png");
}

#endif // loadingPictures_H_INCLUDED