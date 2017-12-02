#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5

int vcc2 = 9;

long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor,Average;
 
void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(vcc2, OUTPUT);
digitalWrite(vcc2, HIGH);
}
 
void loop() {
SonarSensor(trigPin1, echoPin1);
RightSensor = distance;
SonarSensor(trigPin2, echoPin2);
LeftSensor = distance;
Average=(RightSensor+LeftSensor)/2;
 
Serial.print(RightSensor);
Serial.print(" - ");
Serial.println(LeftSensor);
Serial.print("Running Average  ");
Serial.println(Average);
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
}
