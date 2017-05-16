#include <LiquidCrystal.h>
#include <Keypad.h>

int sensorValue1;
int sensorValue2;
int boom = 0;
int angle = 0;
int GetNumber();
int GetNumber2();
int REDled=13;
int YELled=12;
int redled=11;
int yelled=10;
int buzz=9;
int CURSOR=13;
int v1 = 0;
int v2 = 0;
int num1=0;
const byte ROWS = 4;
const byte COLS = 4;

//////////////////////////////////////
int redHeight, redDegree;
int yelHeight, yelDegree;

//////////////////////////////////////

char keys[ROWS][COLS] = 
{                    
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = { 51, 49, 47, 45 };    
byte colPins[COLS] = { 43, 41, 39, 37 }; 
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); 

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 

void setup() 
{
	Serial.begin(9600);						//Enable the Serial Communication for Computer-Arduino connection
											//For standalone(without computer), these can be taken out
	
	lcd.begin(20, 4);
	lcd.setCursor(0, 0);
	lcd.print(" ------------------ ");
	lcd.setCursor(0, 1);
	lcd.print("|   CRANE SYSTEM   |");
	lcd.setCursor(0, 2);
	lcd.print(" ------------------ ");
	
	pinMode(A0, INPUT);						//Sensor for Height
	pinMode(A11, INPUT);        			//Sensor for Degree
	pinMode(REDled, OUTPUT);
	pinMode(YELled, OUTPUT);
	pinMode(redled, OUTPUT);
	pinMode(yelled, OUTPUT);
	pinMode(buzz, OUTPUT);
	
}


void loop() 
{
	v1 = GetNumber();
	
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	//:::New Features:::::::::::::::::::::::::::::::::::::::::::::::: 
	getRatedLoad();
	safetyRegulation();
	cranePerformance();
	//:::New Features::::::::::::::::::::::::::::::::::::::::::::::::
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	
 }

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::New Features:::::::::::::::::::::::::::::::::::::::::::::::: 

void getRatedLoad(void)
{
	//potentiometer1 (a0) kuning	- Sensor for Height
	//potentiometer2 (a11) coklat	- Sensor for Degree
	
	int Height = A0, Degree = A11;
	int readHeight, readDegree;
	float valueHeight, valueDegree;
	
	readHeight	= analogRead(Height);	//Read the LIFT ABOVE GROUND LEVEL
	readDegree	= analogRead(Degree);	//Read the WORKING RADIUS/Degree
	
	valueHeight	= (map(readHeight, 0, 1023, 67, 280)/10.0);	//Fix the input to gave asynchronous output on 6.7 till 28 of range
	valueDegree	= (map(readHeight, 0, 1023, 0, 810)/10.0);	//Fix the input to gave asynchronous output on 0.0 till 81 of range
	
}

void safeHeightSafeDegree(void)
{
	digitalWrite(yelHeight, HIGH);	digitalWrite(yelDegree, HIGH);
	digitalWrite(redHeight, LOW);	digitalWrite(redDegree, LOW);
}

void safeHeightRiskDegree(void)
{
	digitalWrite(yelHeight, HIGH);	digitalWrite(yelDegree, LOW);
	digitalWrite(redHeight, LOW);	digitalWrite(redDegree, HIGH);
}
 
void riskHeightSafeDegree(void)
{
	digitalWrite(yelHeight, LOW);	digitalWrite(yelDegree, HIGH);
	digitalWrite(redHeight, HIGH);	digitalWrite(redDegree, LOW);
}

void riskHeightRiskDegree(void)
{
	digitalWrite(yelHeight, LOW);	digitalWrite(yelDegree, LOW);
	digitalWrite(redHeight, HIGH);	digitalWrite(redDegree, HIGH);
}

void alarmOn(void)
{
	digitalWrite(buzz, HIGH);
}

void alarmOff(void)
{
	digitalWrite(buzz, LOW);
}

void safetyRegulation(void)
{
	if(valueDegree >= 60)
	{
		if(valueHeight <= 28.00)
		{
			safeHeightSafeDegree();
			alarmOff();
		}
		else
		{
			riskHeightSafeDegree();
			alarmOn();
		}
	}
	else
	{
		if(valueHeight <= 28.00)
		{
			safeHeightRiskDegree();
			alarmOn();
		}
		else
		{
			riskHeightRiskDegree();
			alarmOn();
		}
	}
}

void cranePerformance(void)
{
	switch(v1)
	{
		case 22000:
		safetyRegulation();
		break;
		
		case 8000:
		safetyRegulation();
		break;
		
		case 6000:
		safetyRegulation();
		break;
		
		case default:
		//Display "ERROR" on LCD for wrong weight entered 
		break;
	}
}

//:::New Features::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

int GetNumber()
{
	int num = 0;
	char key = kpd.getKey();
	lcd.setCursor(0, 3);
	lcd.print("Enter weight:      ");
	lcd.setCursor(12, 3);
	CURSOR=13;
	while(key != '#')
	{
		switch (key)
		{
			case NO_KEY:
				break;
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				num = num * 10 + (key - '0');
				lcd.setCursor(CURSOR, 3);
				lcd.print(key);
				CURSOR=CURSOR+1;
				Serial.println(num);
				break;
			case '#':
				return num;
				break;
			case '*': //to reset
				lcd.clear();
				lcd.setCursor(0, 0);
				lcd.print(" ------------------ ");
				lcd.setCursor(0, 1);
				lcd.print("|   CRANE SYSTEM   |");
				lcd.setCursor(0, 2);
				lcd.print(" ------------------ ");
				lcd.setCursor(0, 3);
				lcd.print("Enter weight:");
				digitalWrite(REDled, LOW);
				digitalWrite(redled, LOW);
				digitalWrite(YELled, LOW);
				digitalWrite(yelled, LOW);
				digitalWrite(buzz, LOW); 
				CURSOR=13;     
				num = 0;
				break;
		}
		key = kpd.getKey();
   }
	return num;
}

