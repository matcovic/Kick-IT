#ifndef score_H_INCLUDED
#define score_H_INCLUDED
#include "myVariables.h"

//For showing points while playing; called from iDraw method;return type void
void score()
{
	char score[1000];
	iSetColor(255, 255, 255);
	_itoa_s(point, score, 10);
	iText(36,536,"Score:",GLUT_BITMAP_HELVETICA_18);
	iText(98,536,score,GLUT_BITMAP_HELVETICA_18);
}

/*shows the score on the game over page;called from iDraw;return type void*/
void score_show()
{
	char score[100];

	_itoa_s(point, score, 10);
	iSetColor(255, 255, 255);
	iText(262, 236, score, GLUT_BITMAP_TIMES_ROMAN_24);
}

#endif // score_H_INCLUDED