/*
Code by: www.munphurid.com
M.Hashir

This is a code for Bluetooth controlled car

Hardware:
Is bought from www.munphurid.com
-Arduino UNO
-Motor driver module L298N
-Munphurid Chassis MN CS01 (Light weight 3 wheeler chassis can also be used)
-HC-05 Bluetooth Module
-7V to 12V battery
-10 male to female wires

Connections:
Motor driver module and Arduino
-Connect IN1 to pin 8 of Arduino
-Connect IN2 to pin 13 of Arduino
-Connect IN3 to pin 9 of Arduino
-Connect IN4 to pin 6 of Arduino
-Connect ENA to pin 2 of Arduino
-Connect ENB to pin 7 of Arduino
-Connect 5V of module to 5V of Arduino
-Connect GND of module to GND of Arduino


Bluetooth module and Arduino
-Connect RX of Bluetooth module to pin 1 = TX of Arduino
-Connect TX of Bluetooth module to pin 1 = RX of Arduino
-Connect VCC of Bluetooth module to 5V of Arduino
-Connect GND of Bluetooth module to GND of Arduino

Motors
Connect motors to motor driver module

Battery and all circuits
-Connect +ve wire of battery to 12V of motor driver module
-Connect -ve wire of battery to GND of motor driver module
*/

#define IN1 2
#define IN2 3
#define ENA 6
#define ENB 7
#define IN3 4
#define IN4 5


void stopm(void);
void forward(void);
void right(void);
void left(void);
void inputs(int);
void sharpright(void);


void setup(void)
{

  Serial.begin (9600);              //Do not edit this line
  pinMode(IN1,OUTPUT);              //Do not edit this line
  pinMode(IN2,OUTPUT);              //Do not edit this line
  pinMode(IN3,OUTPUT);              //Do not edit this line
  pinMode(IN4,OUTPUT);              //Do not edit this line
  pinMode(ENA,OUTPUT);              //Do not edit this line
  pinMode(ENB,OUTPUT);              //Do not edit this line
  digitalWrite(ENA,HIGH);          //Used for speed controlling
  digitalWrite(ENB,HIGH);          //Used for speed controlling

    while(!Serial.available());
 }


void loop(void) {

  int a=Serial.read();          //Receive da88ikddta from Bluetooth module
switch(a){

case '1':            //If this letter is received
forward(); 
Serial.println(a);                    //Move forward
delay(200);
break;

case '2':            //If this letter is received
left();             //Turn left
Serial.println(a);
delay(200);
break;

case '3':          //If this letter is received
right();           //Turn right
Serial.println(a);
delay(200);
break;

default:
stopm(); 
Serial.println(a);            //If nothing is pressed then stop
delay(200);
}

a=0;
}



void forward(void)            //The four lines below tell your car how to move forward... you can edit them
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}


void left(void)              //The four lines below tell your car how to turn left.... you can edit them
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}



void right(void)            //The four lines below tell your car how to turn right.... you can edit them
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
}


void stopm(void)            //The four lines below tell your car how to stop.... you can edit them
{

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}
