#include <LiquidCrystal.h>
#include <Keypad.h>
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
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.setCursor(0, 0);
  lcd.print(" ------------------ ");
  lcd.setCursor(0, 1);
  lcd.print("|   CRANE SYSTEM   |");
  lcd.setCursor(0, 2);
  lcd.print(" ------------------ ");
  pinMode(A0, INPUT);
  pinMode(A11, INPUT);        
  pinMode(REDled, OUTPUT);
  pinMode(YELled, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(yelled, OUTPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
}

int sensorValue1;
int sensorValue2;
int boom = 0;
int angle = 0;
// the loop routine runs over and over again forever:
void loop() 
{
    v1 = GetNumber();
    v2 = GetNumber2();


    Serial.print("Weight = ");
    Serial.print(v1);
    Serial.print("\nWorking Distance = ");
    Serial.print(v2);
    if (v1 == 22000 && v2 == 2)
      {

       int sensorValue1 = analogRead(A0);
       int sensorValue2 = analogRead(A11);
       
      boom  = map(sensorValue1, 0, 1023, 6.7, 28);
      angle = map(sensorValue2, 0, 1023, 0, 81);
      Serial.print("\nboom = ");
      Serial.print(boom);
      Serial.print("\nangle = ");
      Serial.print(angle);  
      
        if (boom == 6.7 && angle == 60)
      {
         digitalWrite(REDled, LOW);
         digitalWrite(redled, LOW);
         digitalWrite(YELled, HIGH);
         digitalWrite(yelled, HIGH);
         digitalWrite(buzz, LOW); 
         delay(1);        // delay in between reads for stability
        }
                if (boom > 6.7 && angle < 60)
        {
         digitalWrite(REDled, HIGH);
         digitalWrite(redled, HIGH);
         digitalWrite(YELled, LOW);
         digitalWrite(yelled, LOW);
         digitalWrite(buzz, LOW); 
         delay(1);        // delay in between reads for stability
        }

      }
//       float angle = (81/1023)*sensorValue2; //ubah ni
//        if (boom == 6.7 && angle == 60)
////       Serial.print(boom);
////       Serial.println(angle);
////
//        {
//         digitalWrite(REDled, LOW);
//         digitalWrite(redled, LOW);
//         digitalWrite(YELled, HIGH);
//         digitalWrite(yelled, HIGH);
//         digitalWrite(buzz, LOW); 
//         delay(1);        // delay in between reads for stability
//        }
        if (boom > 6.7 && angle < 60)
        {
         digitalWrite(REDled, HIGH);
         digitalWrite(redled, HIGH);
         digitalWrite(YELled, LOW);
         digitalWrite(yelled, LOW);
         digitalWrite(buzz, LOW); 
         delay(1);        // delay in between reads for stability
        }
//        else
//        {
//         digitalWrite(REDled, HIGH);
//         digitalWrite(redled, HIGH);
//         digitalWrite(YELled, LOW);
//         digitalWrite(yelled, LOW);
//         digitalWrite(buzz, LOW); 
//         delay(1);        // delay in between reads for stability
//        }
//      }
//     else
//     if (v1 <= 12000)
//      {
//       int sensorValue1 = analogRead(A0);
//       int sensorValue2 = analogRead(A11);
//       float boom = (28/1023)*sensorValue1;
//       float angle = (81/1023)*sensorValue2;
//       Serial.print(boom);
//       Serial.println(angle);
//
//        if (boom <= 11.0 && angle <= 81)
//        {
//         digitalWrite(REDled, LOW);
//         digitalWrite(redled, LOW);
//         digitalWrite(YELled, HIGH);
//         digitalWrite(yelled, HIGH);
//         digitalWrite(buzz, LOW); 
//         delay(1);        // delay in between reads for stability
//        }
//        else
//        {
//         digitalWrite(REDled, HIGH);
//         digitalWrite(redled, HIGH);
//         digitalWrite(YELled, LOW);
//         digitalWrite(yelled, LOW);
//         digitalWrite(buzz, HIGH); 
//         delay(1);        // delay in between reads for stability
//        }
//        delay(1);        // delay in between reads for stability
//      }
//      else
//      if (v1 <= 8000)
//      {
//       int sensorValue1 = analogRead(A0);
//       int sensorValue2 = analogRead(A11);
//       float boom = (28/1023)*sensorValue1;
//       float angle = (81/1023)*sensorValue2;
//       Serial.print(boom);
//       Serial.println(angle);
//
//        if (boom <= 21.6 && angle <= 81)
//        {
//         digitalWrite(REDled, LOW);
//         digitalWrite(redled, LOW);
//         digitalWrite(YELled, HIGH);
//         digitalWrite(yelled, HIGH);
//         digitalWrite(buzz, LOW); 
//         delay(1);        // delay in between reads for stability
//        }
//        else
//        {
//         digitalWrite(REDled, HIGH);
//         digitalWrite(redled, HIGH);
//         digitalWrite(YELled, LOW);
//         digitalWrite(yelled, LOW);
//         digitalWrite(buzz, HIGH); 
//         delay(1);        // delay in between reads for stability
//        }
//        delay(1);        // delay in between reads for stability
//      }
//      else
//      if (v1 <= 6000)
//      {
//       int sensorValue1 = analogRead(A0);
//       int sensorValue2 = analogRead(A11);
//       float boom = (28/1023)*sensorValue1;
//       float angle = (81/1023)*sensorValue2;
//       Serial.print(boom);
//       Serial.println(angle);
//
//        if (boom <= 28.0 && angle <= 81)
//        {
//         digitalWrite(REDled, LOW);
//         digitalWrite(redled, LOW);
//         digitalWrite(YELled, HIGH);
//         digitalWrite(yelled, HIGH);
//         digitalWrite(buzz, LOW); 
//         delay(1);        // delay in between reads for stability
//        }
//        else
//        {
//         digitalWrite(REDled, HIGH);
//         digitalWrite(redled, HIGH);
//         digitalWrite(YELled, LOW);
//         digitalWrite(yelled, LOW);
//         digitalWrite(buzz, HIGH); 
//         delay(1);        // delay in between reads for stability
//        }
//        delay(1);        // delay in between reads for stability
//      }
 }
 
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

//

   return num;
}

int GetNumber2()
{
   int num = 0;
   Serial.println("width");
   char key = kpd.getKey();
   lcd.setCursor(0, 3);
   lcd.print("Enter width:      ");
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
            lcd.print("Enter width:");
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







//------------------------------distance calculaton--------------------------------------------------//

//float boom = (28/1023)*sensorValue1;

//------------------------------angle calculation----------------------------------------------------//

//float angle = (81/1023)*sensorvalue2;
