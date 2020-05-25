/*
Author: NandhaFrost
Date: 25/05/2020
Version: 0.1
Sensor detecting continuously
If detected
	then  1. stop sensor from detecting
		  2. start the pump
		  3. stop the pump once required amount liquid is pumped
		  4. Wait for desired time
		  5. exit
*/

int IRSensor = 2; // connect ir sensor to arduino pin 2
int pump = 13; // conect pump to arduino pin 13
int interpretBeforeNextPump = 2000; //time in Milli-seconds
int periodForPumping = 1000;

void setup() 
{
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (pump, OUTPUT); // pump pin OUTPUT
  digitalWrite(pump, LOW); //initially setting pump to off state
}

void loop()
{
  int statusSensor = digitalRead (IRSensor);
  if (statusSensor == 0)
    digitalWrite(pump, HIGH);
	delay(periodForPumping);
	digitalWrite(pump, LOW);
	delay(interpretBeforeNextPump);
  }
}
