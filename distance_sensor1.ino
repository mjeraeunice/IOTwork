int inches = 0;

int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{

  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(6);

  // Sets the trigger pin to HIGH state for 10 microseconds
 
 digitalWrite(triggerPin, HIGH);
  delayMicroseconds(30);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  
// Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(8100);

}

void loop()
{
  // measure the ping time in cm
 
 cm = 2.01624 * readUltrasonicDistance(9,9);

  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");

  delay(80); // Wait for 80 millisecond(s)
}