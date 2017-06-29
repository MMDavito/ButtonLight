#include <EEPROM.h>

int buttonPin = 1;
int lightPin = 2;
int buttonState = 0;
int minPin = 2;
int maxPin = 5;
int eeAdress1 = 0;
int eeAdress2 = 1;
int eeAdress3 = 2;
int eeAdress4 = 3;

long buttonTimer;
long timeout = 5000;

boolean lightOn = true;
boolean buttonActive = false;
boolean longPressActive = false;
boolean light1 = false;
boolean light2 = false;
boolean light3 = false;
boolean light4 = false;

const long longPressTime = 250;



void setup(){
  Serial.begin(9600);
  pinMode(buttonPin,INPUT);
  //Less than max
  for(int i = minPin; i<=maxPin; i++){
  pinMode(i,OUTPUT);
  }
}

void loop(){
  if(lightOn){
    turnLightOn();
  }
  checkBtn(timeout);
}
  
  void checkBtn(long duration){
  unsigned long start = millis();

  while (millis() - start <= duration) {    
    buttonState = digitalRead(buttonPin);
  
    if(buttonState == HIGH){
      Serial.print("Button Pressed ");
      Serial.println(buttonState);
      //Button pressed
      if(!longPressActive){}
    
        if(buttonActive == false){
           buttonActive = true;
           buttonTimer = millis();
        }if((millis() - buttonTimer > longPressTime) && (longPressActive == false)){
          Serial.println("Longpress ACTIVATED!");
          longPressActive = true;
          digitalWrite(lightPin, HIGH);
  }
  
}else{
  //Button not pressed
  buttonActive = false;
  if(longPressActive){
    Serial.print("Longpress active== ");
    Serial.println(longPressActive);
    if(lightOn){
      digitalWrite(lightPin,LOW);
      lightOn = false;
      
      }else if(lightOn == false){
       lightOn = true;
       digitalWrite(lightPin,HIGH);
       }
       longPressActive = false;
      }
    }
   }
  }
  
  void turnLightOn(){
    EEPROM.get(eeAdress1, light1);
    EEPROM.get(eeAdress2, light2);
    EEPROM.get(eeAdress3, light3);
    EEPROM.get(eeAdress4, light4);

    Serial.println("");
    Serial.print("Hejsvejs ");
    Serial.println(light1);
    Serial.println(light2);
    Serial.println(light3);
    Serial.println(light4);
    
  if(light1 == false && light2 == false && light3 == false && (light4 ==false || light4 == true)){
    for(int i = minPin; i<=maxPin; i++){
      digitalWrite(i,LOW);
    }  
    digitalWrite(2,HIGH);
    light1 = true;  
  }else if (light1 == true){
  for(int i = minPin; i<=maxPin; i++){
      digitalWrite(i,LOW);
    }
    digitalWrite(3,HIGH);
    light1 = false;
    light2 = true;
  }else if (light2 == true){
    for(int i = minPin; i<=maxPin; i++){
      digitalWrite(i,LOW);
    }
    digitalWrite(4,HIGH);
    light2 = false;
    light3 = true;
  }else if (light3 == true){
  for(int i = minPin; i<=maxPin; i++){
      digitalWrite(i,LOW);
    }
    digitalWrite(5,HIGH);
    light3 = false;
    light4 = true;
  }
    EEPROM.put(eeAdress1, light1);
    EEPROM.put(eeAdress2, light2);
    EEPROM.put(eeAdress3, light3);
    EEPROM.put(eeAdress4, light4);

}
  void lightOff(){}
