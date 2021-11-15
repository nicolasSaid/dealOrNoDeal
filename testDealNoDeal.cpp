
#include <lvp\gui_top.h>
#include <lvp\vector.h>
#include <lvp\random.h>
#include <lvp\string.h>
#include "MoneyPanel.h"
#include "Briefcase.h"
#include "Gameplay.h"

class GuiClass
{
	public:
        GuiClass();
        void GuiMouseClick(int x, int y); // Action if mouse click
        void GuiPaint();  // Repaint the entire window
        String Title(); // Return the title for the Window
	private:
		int lastX, lastY;
		Gameplay game;
};
//--------------------------------------------------------------------------------
GuiClass::GuiClass()
: lastX(0), lastY(0), game()
{

}

//--------------------------------------------------------------------------------
String GuiClass::Title()
{
	return "Deal or No Deal";
}
//--------------------------------------------------------------------------------
void GuiClass::GuiMouseClick(int x, int y)
{
	lastX=x;
	lastY=y;
	game.click(lastX,lastY);
}
//--------------------------------------------------------------------------------
void GuiClass::GuiPaint()
{
	int x = GetMaxX();
	int y = GetMaxY();
	SetFillColor(YELLOW);
	FilledRectangle(0,0,x,y);
	//game.getMoney().displayBoxes();
	int multXCounter = 2;
	int multYCounter;
	for(int i = 0; i < 26; i++){
		if(i < 6){
			game.getCases()[i].paint((multXCounter*x)/9,y/8);
			multXCounter++;
		}
		else if(i < 12){
			if(i == 6)
				multXCounter = 2;
			multYCounter = 2;
			game.getCases()[i].paint((multXCounter*x)/9,(multYCounter*y)/8);
			multXCounter++;
		}
		else if(i < 18){
			if(i == 12)
				multXCounter = 2;
			multYCounter = 3;
			game.getCases()[i].paint((multXCounter*x)/9,(multYCounter*y)/8);
			multXCounter++;
		}
		else if(i < 24){
			if(i == 18)
				multXCounter = 2;
			multYCounter = 4;
			game.getCases()[i].paint((multXCounter*x)/9,(multYCounter*y)/8);
			multXCounter++;
		}
		else if(i == 25)
			game.getCases()[24].paint((4*x)/9,(5*y)/8);
		else
			game.getCases()[25].paint((5*x)/9,(5*y)/8);
	}
	//game.chooseYourCase(lastX, lastY);
	for(i = 0; i < 26; i++){
		if(game.getCases()[i].isHit(lastX,lastY))
			game.getMoney().grayChosen(game.getCases()[i].getAmount());
	}
	SetFillColor(ORANGE);
	//FilledRectangle(

}
//--------------------------------------------------------------------------------
#include <lvp\gui_bot.h>
