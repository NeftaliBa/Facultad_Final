int led = 0;

void setup() {
  // put your setup code here, to run once:
      pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    if(digitalRead(1)==HIGH)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}