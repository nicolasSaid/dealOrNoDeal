class MoneyPanel{
	public:
		MoneyPanel();
		void displayBoxes();
		void grayChosen(long value);
		long getTotalOfOpen();
		vector<long> returnMoney();
		int getOpen();
		void chooseCase(long value);
	private:
		vector<int> open;
		vector<long> moneyValues;
		int length;
		int width;
		int gap;

};

MoneyPanel::MoneyPanel() //1 is open, -1 is closed, 2 is chosen
: open(26,1), moneyValues(26), length(75), width(50), gap(10) //rectangle dimensions
{ //assigns all money values
	moneyValues[0] = 0;
	moneyValues[1] = 1;
	moneyValues[2] = 5;
	moneyValues[3] = 10;
	moneyValues[4] = 25;
	moneyValues[5] = 50;
	moneyValues[6] = 75;
	moneyValues[7] = 100;
	moneyValues[8] = 200;
	moneyValues[9] = 300;
	moneyValues[10] = 400;
	moneyValues[11] = 500;
	moneyValues[12] = 750;
	moneyValues[13] = 1000;
	moneyValues[14] = 5000;
	moneyValues[15] = 10000;
	moneyValues[16] = 25000;
	moneyValues[17] = 50000;
	moneyValues[18] = 75000;
	moneyValues[19] = 100000;
	moneyValues[20] = 200000;
	moneyValues[21] = 300000;
	moneyValues[22] = 400000;
	moneyValues[23] = 500000;
	moneyValues[24] = 750000;
	moneyValues[25] = 1000000;
}


//------------------------------------------
void MoneyPanel::displayBoxes()
/*displays all the money panels
Pre: MoneyPanel object must be initialized
Post: displays the panel with the given money values*/


{
	int totalPosY = 25;
	const int offSetX = 25;
	SetFillColor(GREEN); //color for the rectangles
	SetColor(BLACK);
	for(int i = 0; i<13; i++){ //displays left side with an even gap
		FilledRectangle(offSetX, totalPosY, offSetX + length, totalPosY + width);
		gotoxy(offSetX + (length/2), totalPosY + (width/2));
		DrawCenteredText(moneyValues[i]);
		totalPosY += width + gap ;
	}
	totalPosY = 25; //resets y to the top
	for(i = 13; i<26; i++){ //displays right side with an even gap
		FilledRectangle(GetMaxX() - 5*offSetX, totalPosY, GetMaxX() - 5*offSetX + length, totalPosY + width);
		gotoxy(GetMaxX() - 5*offSetX + (length/2), totalPosY + (width/2));
		DrawCenteredText(moneyValues[i]);
		totalPosY += width + gap;
	}
}

void MoneyPanel::grayChosen(long value)
/*grays out a given panel box
pre: a valid value of money is passed
post: turns the green box gray
*/
{
	int totalPosY = 25;
	const int offSetX = 25;
	for(int i = 0; i<26;i++){ //goes through array to see which rectangle matches the value
		if(value == moneyValues[i]){
			if(i < 13){ //left side 
				totalPosY += i*(width+gap);
				SetFillColor(GRAY);
				SetColor(BLACK);
				FilledRectangle(offSetX, totalPosY, offSetX + length, totalPosY + width);
				gotoxy(offSetX + (length/2), totalPosY + (width/2));
				DrawCenteredText(moneyValues[i]);
				open[i] = -1;
			}
			else{ //right side
				totalPosY += (i - 13)*(width+gap);
				SetFillColor(GRAY);
				SetColor(BLACK);
				FilledRectangle(GetMaxX() - 5*offSetX, totalPosY, GetMaxX() - 5*offSetX + length, totalPosY + width);
				gotoxy(GetMaxX() - 5*offSetX + (length/2), totalPosY + (width/2));
				DrawCenteredText(moneyValues[i]);
				open[i] = -1;
			}
		}
	}
}

long MoneyPanel::getTotalOfOpen()
/*gets the total money value of boxes not grayed out
pre: MoneyPanel object is initialized
post: returns total money value*/
{
	long total = 0;
	for(int i = 0; i < 26; i++){ //totals left values
		if(open[i] == 1)
			total += moneyValues[i];
	}
	return(total);
}

vector<long> MoneyPanel::returnMoney()
/*returns the vector of all money values
pre: MoneyPanel object is initialized
post: returns the vector of money*/
{
	return(moneyValues);
}

int MoneyPanel::getOpen()
/*returns number of open cases
pre: MoneyPanel object is initialized
post: returns the vector of money*/
{
	int totalOpen = 0;
	for(int i = 0; i < 26; i++){
		if(open[i] == 1)
			totalOpen++;
	}
	return(totalOpen);
}

void MoneyPanel::chooseCase(long value){
	for(int i = 0; i<26;i++){ //goes through array to see which rectangle matches the value
		if(value == moneyValues[i]){
			open[i] = 2;
		}
	}
}