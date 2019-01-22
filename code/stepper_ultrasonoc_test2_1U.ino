//This code is working for one ultrasonic sensor
//When the sensor gets the distance in-between its range
//It runs the test code

//Define Pulse and Direction pins for motor1
int DIR1 = 2;
int PUL1 = 3;
//Define Pulse and Direction pins for motor2
int DIR2 = 4;
int PUL2 = 5;
//Define pins for ultrasonic sensor
int trigPin = 6;    // Trigger
int echoPin = 7;    // Echo
int led = 13;        // LED
long duration, distance;  

int noOfSteps = 64000;  //The number of steps the motors will move by

void setup() {
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  
  pinMode(DIR1, OUTPUT);
  pinMode(PUL1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(PUL2, OUTPUT);

  Serial.begin(9600);
}

int timeToSteps()
{
  //converts the time in seconds to number of steps
  noOfSteps = 6400;

  return noOfSteps;
}

void mariaStop()
{
  //code to make the robot come to a halt
  Serial.println("HALT");
}

void goForward()
{
  //Code to make the robot go forward for some time
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, HIGH);

  for(int count = 0; count < noOfSteps; count++)
  {
    digitalWrite(PUL1, HIGH);
    digitalWrite(PUL2, HIGH);
    delayMicroseconds(50);
    digitalWrite(PUL1, LOW);
    digitalWrite(PUL2, LOW);
    delayMicroseconds(50);
  }
  Serial.println("FORWARD");
  //mariaStop();
}

void goBack()
{
  //code to make the robot go in reverse for some time
  //Code to make the robot go forward for some time
  digitalWrite(DIR1, LOW);
  digitalWrite(DIR2, LOW);

  for(int count = 0; count < noOfSteps; count++)
  {
    digitalWrite(PUL1, HIGH);
    digitalWrite(PUL2, HIGH);
    delayMicroseconds(50);
    digitalWrite(PUL1, LOW);
    digitalWrite(PUL2, LOW);
    delayMicroseconds(50);
  }
  Serial.println("REVERSE");
  //mariaStop();
}

void turnLeft()
{
  //code to make the robot turn left by some angle
  //Code to make the robot go forward for some time
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, LOW);

  for(int count = 0; count < noOfSteps; count++)
  {
    digitalWrite(PUL1, HIGH);
    digitalWrite(PUL2, HIGH);
    delayMicroseconds(50);
    digitalWrite(PUL1, LOW);
    digitalWrite(PUL2, LOW);
    delayMicroseconds(50);
  }
  Serial.println("LEFT");
  //mariaStop();
}

void turnRight()
{
  //code to make the robot turn right by some angle
  //Code to make the robot go forward for some time
  digitalWrite(DIR1, LOW);
  digitalWrite(DIR2, HIGH);

  for(int count = 0; count < noOfSteps; count++)
  {
    digitalWrite(PUL1, HIGH);
    digitalWrite(PUL2, HIGH);
    delayMicroseconds(50);
    digitalWrite(PUL1, LOW);
    digitalWrite(PUL2, LOW);
    delayMicroseconds(50);
  }
  Serial.println("RIGHT");
  //mariaStop();
}

void testCode() {
  // put your main code here, to run repeatedly:
  Serial.println("TEST CODE RUNNING FOR TWO MOTORS:");
  turnRight();
  delay(1000);
  turnLeft();
  delay(1000);
  goBack();
  delay(1000);
  goForward();
  delay(1000);
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration/2) / 29.1; //for cm

  if (distance >= 100 || distance <= 20)
  {
    Serial.println("Out of range");
    digitalWrite(led,LOW);
  }
  else
  {
    Serial.print(distance);
    Serial.println(" cm");
    testCode();
    digitalWrite(led,HIGH);
  }
  delay(250);
}

