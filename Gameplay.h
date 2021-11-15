class Gameplay
{
public:
	Gameplay();
	vector<Briefcase> getCases();
	MoneyPanel getMoney();
	void randomMoney();
	double bankOffer();
	void chooseCase(int x, int y);
	void chooseYourCase(int x, int y);
	void click(int x, int y);
	
private:
	MoneyPanel money;
	vector<Briefcase> cases;

};
//--------------------------------------------------------------------------------
Gameplay::Gameplay()
: money(), cases(0)
{
	randomMoney();
	for (int i=0; i<cases.length();i++)
		cases[i].setBoxNumber(i+1);
	cases[0].setModelName("Soraya Yd");
	cases[1].setModelName("Taylor Clark");
	cases[2].setModelName("Katie Luddy");
	cases[3].setModelName("Brenda Lowe");
	cases[4].setModelName("Lani Baker");
	cases[5].setModelName("Megan Abrigo");
	cases[6].setModelName("Jordana Depaula");
	cases[7].setModelName("Neka Stephens");
	cases[8].setModelName("Patricia Kara");
	cases[9].setModelName("Vaeda Mann");
	cases[10].setModelName("Brittany Mcgowan");
	cases[11].setModelName("Sarati");
	cases[12].setModelName("Mahogany Lox");
	cases[13].setModelName("Olga Safari");
	cases[14].setModelName("Madi Teeuws");
	cases[15].setModelName("Jessica Lee");
	cases[16].setModelName("Ashley Jones");
	cases[17].setModelName("Elissa Ingrid");
	cases[18].setModelName("Natasha Ward");
	cases[19].setModelName("Amanza Smith");
	cases[20].setModelName("Malika Miller");
	cases[21].setModelName("Anchal Joseph");
	cases[22].setModelName("Anne Julia");
	cases[23].setModelName("Kizzi Barazetti");
	cases[24].setModelName("Summer Bellessa");
	cases[25].setModelName("Michelle De Leon");
}
//--------------------------------------------------------------------------------
vector<Briefcase> Gameplay::getCases()
{
	return cases;
}
//--------------------------------------------------------------------------------
MoneyPanel Gameplay::getMoney()
{
	return money;
}
//--------------------------------------------------------------------------------
void addToArray(vector<Briefcase> &array, Briefcase valToAdd)
/* adds an object Briefcase to an array of Briefcases 
   Pre: array holds the same type added to it
   Post: item/object is added to the array */
{
	array.resize(array.length()+1);
	array[array.length()-1] = valToAdd;
}
//--------------------------------------------------------------------------------
int findItemIndex(vector<long> array, long goal)
{
	for (int i=0; i<array.length();i++)
	{
		if (array[i] == goal)
			return i;
	}
	return -1;
}
//--------------------------------------------------------------------------------
void removeFromArray(vector<long> &array, long &valToDelete)
{
	int index = findItemIndex(array,valToDelete);
	for(;index<array.length()-1;index++)
		array[index] = array[index+1];
	array.resize(array.length()-1);
}
//--------------------------------------------------------------------------------
void Gameplay::randomMoney()
{
	int randomCase;
	Briefcase b;
	while(money.returnMoney().length()>0)
	{
		randomCase = random(money.returnMoney().length());
		b.setAmount(money.returnMoney()[randomCase]);
		addToArray(cases, b);
		removeFromArray(money.returnMoney(), money.returnMoney()[randomCase]);
	}
			
}
//--------------------------------------------------------------------------------
double Gameplay::bankOffer()
{
	return money.getTotalOfOpen()/double(money.getOpen());
}

void Gameplay::chooseCase(int x, int y)
{
	for(int i = 0; i < 26; i++){
		if(cases[i].isHit(x,y)){
			cases[i].hide();
			money.grayChosen(cases[i].getAmount());
		}
	}
}

void Gameplay::chooseYourCase(int x, int y)
{
	gotoxy(GetMaxX()/2, GetMaxY()/2);
	MessageBox("Choose your briefcase", "Deal or No Deal");
	for(int i = 0; i < 26; i++){
		if(cases[i].isHit(x,y)){
			cases[i].owned();
		}
	}
	for(int p = 0; p < 26; p++){
		if(cases[p].isOwned()){
			cases[p].paint((7*x)/9,(6*y)/8);
		}
	}
}

void Gameplay::click(int x, int y){
	for(int i = 0; i < 26; i++){
		if(cases[i].isHit(x,y))
			cases[i].hide();
	}
}
//--------------------------------------------------------------------------------
/*
void chooseYourBriefcase(vector<Briefcase> &cases, int x, int y)
{	
	
	for(int i=0; i<cases.length();i++){
		if (cases[i].isHit(x,y)){
			cases[i].owned();
		}
	}		
}

void GuiClass::GuiPaint()
{
	int x = GetMaxX();
	int y = GetMaxY();
	SetFillColor(YELLOW);
	FilledRectangle(0,0,x,y);

	//if(cases[0].isOwned == false)
		cases[0].paint((2*x)/9,y/8);
	//if(cases[1].isOwned == false)
		cases[1].paint((3*x)/9,y/8);
	//if(cases[2].isOwned == false)
		cases[2].paint((4*x)/9,y/8);
	//if(cases[3].isOwned == false)
		cases[3].paint((5*x)/9,y/8);
	//if(cases[4].isOwned == false)
		cases[4].paint((6*x)/9,y/8);
	//if(cases[5].isOwned == false)
		cases[5].paint((7*x)/9,y/8);
	//if(cases[6].isOwned == false)
		cases[6].paint((2*x)/9,(2*y)/8);
	//if(cases[7].isOwned == false)	
		cases[7].paint((3*x)/9,(2*y)/8);
	//if(cases[0].isOwned == false)
		cases[8].paint((4*x)/9,(2*y)/8);
	//if(cases[0].isOwned == false)
		cases[9].paint((5*x)/9,(2*y)/8);
	//if(cases[0].isOwned == false)
		cases[10].paint((6*x)/9,(2*y)/8);
	//if(cases[0].isOwned == false)
		cases[11].paint((7*x)/9,(2*y)/8);
	//if(cases[0].isOwned == false)
		cases[12].paint((2*x)/9,(3*y)/8);
	//if(cases[0].isOwned == false)
		cases[13].paint((3*x)/9,(3*y)/8);
	//if(cases[0].isOwned == false)
		cases[14].paint((4*x)/9,(3*y)/8);
	//if(cases[0].isOwned == false)
		cases[15].paint((5*x)/9,(3*y)/8);
	//if(cases[0].isOwned == false)
		cases[16].paint((6*x)/9,(3*y)/8);
	//if(cases[0].isOwned == false)
		cases[17].paint((7*x)/9,(3*y)/8);
	//if(cases[0].isOwned == false)
		cases[18].paint((2*x)/9,(4*y)/8);
	//if(cases[0].isOwned == false)
		cases[19].paint((3*x)/9,(4*y)/8);
	//if(cases[0].isOwned == false)
		cases[20].paint((4*x)/9,(4*y)/8);
	//if(cases[0].isOwned == false)
		cases[21].paint((5*x)/9,(4*y)/8);
	//if(cases[0].isOwned == false)
		cases[22].paint((6*x)/9,(4*y)/8);
	//if(cases[0].isOwned == false)
		cases[23].paint((7*x)/9,(4*y)/8);
	//if(cases[0].isOwned == false)
	cases[24].paint((4*x)/9,(5*y)/8);
	//if(cases[0].isOwned == false)
	cases[25].paint((5*x)/9,(5*y)/8);


	money.displayBoxes();
	SetFillColor(ORANGE);
	FilledRectangle((6*x)/9, (5*y)/8, (8*x)/9, (7*y)/8); 
	gotoxy((7*x)/9, (5*y)/8 +20);
	DrawCenteredText("Your Case");
	chooseYourBriefcase(cases,lastX,lastY);
	
	//cases[25].paint((7*x)/9,(6*y)/8);
}
//--------------------------------------------------------------------------------
*/