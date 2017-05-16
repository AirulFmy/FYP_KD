#include <Keypad.h>

int sensorA = A0, sensorB = A1;
int sensorValueA, sensorValueB;
double voltageA, voltageB, newSensorValueA, newSensorValueB;

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

  sensorValueA     = analogRead(sensorA);
  sensorValueB     = analogRead(sensorB);
  voltageA         = sensorValueA * (5.00 / 1023.00);
  voltageB         = sensorValueB * (5.00 / 1023.00);
  newSensorValueA  = (map(sensorValueA, 0, 1023, 67, 280)/10.0);
  newSensorValueB  = (map(sensorValueB, 0, 1023, 0, 810)/10.0);
  
  Serial.print("SensorValueA = ");
  Serial.print(sensorValueA);
  Serial.print("\t\tVoltageA = ");
  Serial.print(voltageA);
  Serial.print("\t\tNewSensorValueA = ");
  Serial.print(newSensorValueA);

  Serial.print("\t\tSensorValueB = ");
  Serial.print(sensorValueB);
  Serial.print("\t\tVoltageB = ");
  Serial.print(voltageB);
  Serial.print("\t\tNewSensorValueB = ");
  Serial.println(newSensorValueB);

//  Serial.println( map(sensorValue, 0,1023,0,1000) / 100.0);
  
}
