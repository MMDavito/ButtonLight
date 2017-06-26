int buttonPin = 1;
int lightPin = 2;
int buttonState = 0;
int minPin = 2;
int maxPin = 5;

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
      Serial.print("im high+ ");
      Serial.println(buttonTimer);
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
  if(light1 ==false && light2 == false && light3 == false && (light4 ==false || light4 == true)){
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
    for(int i = minPin; i<=maxPinmaxPin; i++){
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
}
  void lightOff(){}
