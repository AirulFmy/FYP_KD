#include <Keypad.h>

int sensorA = A0;
int sensorValue;
double voltage, newSensorValue;

void setup() {
  Serial.begin(9600);
  pinMode(sensorA, INPUT);
}

void loop() {
/*  
  int sensorValue = analogRead(sensorA);          // read the input on analog pin 0:
  float voltage = sensorValue * (5.0 / 1023.0);   // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.println(voltage);                        // print out the value you read:
*/

  sensorValue     = analogRead(sensorA);
  voltage         = sensorValue * (5.00 / 1023.00);
  newSensorValue  = (map(sensorValue, 0, 1023, 67, 280)/10.0);
  
  Serial.print("SensorValue = ");
  Serial.print(sensorValue);
  Serial.print("\t Voltage = ");
  Serial.print(voltage);
  Serial.print("\t\t NewSensorValue = ");
  Serial.println(newSensorValue);

//  Serial.println( map(sensorValue, 0,1023,0,1000) / 100.0);
  
}
