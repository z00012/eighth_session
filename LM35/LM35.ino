const int lm35pin=A0;
int led=9;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);

}

void loop() {
  int sensorValue=analogRead(lm35pin);
  float voltage=sensorValue*(5.0/1023.0);
  float temperatureC=voltage*100;
  
  Serial.print("temperature:");
   Serial.print(temperatureC);
  Serial.println("*c");
  if(temperatureC>27){
    Serial.print("cooler on");
    digitalWrite(led,HIGH);
  }
  else{
     digitalWrite(led,LOW);
  
    
  }
  delay(1000);
}
