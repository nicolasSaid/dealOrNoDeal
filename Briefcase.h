class Briefcase 
{
public:
    Briefcase();
	void paint(int x, int y);
	String getModelName();
	void setModelName(String modelName);
	int getBoxNumber();
	void setBoxNumber(int boxNumber);
	long getAmount();
	void setAmount(long amount);
	bool isHit(int x, int y);    
    void hide();
    int isHidden() const;
    void owned();
	bool isOwned() const;


private:
    String m_modelName;
    int m_boxNumber;
    long  m_money;

    int m_caseLength;
    int m_caseWidth;

    int m_handleLength;
    int m_handleHeight;
    int m_handleWidth;
	int m_isHidden;

    bool m_owned;

    // the reference coordinates for the briefcase
    int m_refX;
    int m_refY;

 };
//-------------------------------------------------------------------
Briefcase::Briefcase() //-1 shown, 1 hidden
:m_modelName(""), m_boxNumber(0), m_money(), m_caseLength(100), m_caseWidth(65), m_isHidden(2), m_owned(false), m_refX(0), m_refY(0)
{
}
//-------------------------------------------------------------------
void Briefcase::paint(int x, int y)
{

    // draw the main body of the briefcase
	if(m_isHidden == 2){
		SetFillColor(GRAY);
		SetColor(GRAY);
		SetThickness(1);

		FilledRectangle(x, y, x+m_caseLength, y-m_caseWidth);

		const int X2 = x+m_caseLength;
		const int Y2 = y-m_caseWidth;

		const int LX1 = x+m_caseLength/5;
		const int LY1 = y-m_caseWidth*6/5;

		const int LX2 = x+1.5*m_caseLength/5;
		const int LY2 = y-m_caseWidth;

		const int TX1 = x+m_caseLength/5;
		const int TY1 = y-m_caseWidth*7/5;

		const int TX2 = x+4*m_caseLength/5;
		const int TY2 = y-m_caseWidth*6/5;

		const int RX1 = x+4*m_caseLength/5; 
		const int RY1 = y-m_caseWidth*6/5; 

		const int RX2 = x+m_caseLength-1.5*m_caseLength/5; 
		const int RY2 = y-m_caseWidth;

		// draw briefcase handle
		SetFillColor(BLACK);
		SetColor(BLACK);
		FilledRectangle(LX1,LY1,LX2,LY2); //left
		FilledRectangle(RX1, RY1, RX2, RY2); //right
		FilledRectangle(TX1, TY1, TX2,TY2); //top
		int handleX = m_caseLength/10;
		int handleY = m_caseWidth/10;

		gotoxy(x + m_caseLength/2, y-m_caseWidth/2);
		DrawCenteredText(m_modelName);
		gotoxy(x + m_caseLength/2, y-m_caseWidth/2+21);
		DrawCenteredText(m_boxNumber);    
		gotoxy(x + m_caseLength/2, y-m_caseWidth/2-21);
		DrawCenteredText(m_money);
		m_refX = x;
		m_refY = y;
	}
}
//-------------------------------------------------------------------
bool Briefcase::isHit(int x, int y)
/* Returns true if and only if point (x,y) is on the button */
{
    int X2 = m_refX+m_caseLength;
    int Y2 = m_refY-m_caseWidth;

    int LX1 = m_refX+m_caseLength/5;
    int LY1 = m_refY-m_caseWidth*6/5;

    int LX2 = m_refX+1.5*m_caseLength/5;
    int LY2 = m_refY-m_caseWidth;

    int RX1 = m_refX+4*m_caseLength/5; 
    int RY1 = m_refY-m_caseWidth*6/5; 

    int RX2 = m_refX+m_caseLength-1.5*m_caseLength/5; 
    int RY2 = m_refY-m_caseWidth;

    const int TX1 = m_refX+m_caseLength/5;
    const int TY1 = m_refY-m_caseWidth*7/5;

    const int TX2 = m_refX+4*m_caseLength/5;
    const int TY2 = m_refY-m_caseWidth*6/5;

    
    if (x >= m_refX && x <= X2 &&
        y >= Y2 && y <= m_refY)
    {
        // when (x, y) is inside the briefcase body
        return true;
    }
    else if (x >= LX1 && x <= LX2 && y >= LY1 && y <= LY2) 
    {
        // when (x, y) is inside the left handle
        return true;
    }
    else if (x >= RX2 && x <= RX1 && y >= RY1 && y <= RY2)
    {
        // when (x, y) is inside the right handle
        return true;
    }
    if (x >= TX1 && x <= TX2 &&
        y >= TY1 && y <= TY2)
    {
        // when (x, y) is inside the briefcase body
        return true;
    }
    return false;
}
//-------------------------------------------------------------------
void Briefcase::hide()
{
    m_isHidden = 1;
}
//--------------------------------------------------------------------
int Briefcase::isHidden() const
{
    return m_isHidden;
}
//--------------------------------------------------------------------
void Briefcase::owned() 
{
    m_owned = true;
}
//--------------------------------------------------------------------
bool Briefcase::isOwned() const
{
	return m_owned;
}
//--------------------------------------------------------------------
String Briefcase::getModelName()
{
	return m_modelName;
}
//--------------------------------------------------------------------
void Briefcase::setModelName(String modelName)
{
	m_modelName = modelName;
}
//--------------------------------------------------------------------
int Briefcase::getBoxNumber()
{
	return m_boxNumber;
}
//--------------------------------------------------------------------
void Briefcase::setBoxNumber(int boxNumber)
{
	m_boxNumber = boxNumber;
}
//--------------------------------------------------------------------
long Briefcase::getAmount()
{
	return m_money;
}
//--------------------------------------------------------------------
void Briefcase::setAmount(long amount)
{
	m_money = amount;
}
//--------------------------------------------------------------------
