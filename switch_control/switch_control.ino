int switchPin = 8;
boolean lastButton = LOW;
boolean ledOn = LOW; 
int outPin = 13;
void setup()
{
  pinMode(switchPin, INPUT);
  pinMode(outPin, OUTPUT);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(switchPin);
  if(current !=  last)
  {
      delay(5);
      current = digitalRead(switchPin);
  }
  return current; // return the steady state value 
}

void loop()
{
  int current = debounce(lastButton);
  if( lastButton == LOW && current == HIGH ){
    ledOn = ! ledOn;
  }
  lastButton = current ;
  digitalWrite(outPin , ledOn);
  
}

