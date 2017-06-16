int buttonPin = 1;
int lightPin = 2;
int buttonState = 0;
long buttonTimer;

boolean lightOn = false;
boolean buttonActive = false;
boolean longPressActive = false;

const long longPressTime = 250;



void setup(){
  Serial.begin(9600);
  pinMode(buttonPin,INPUT);
  pinMode(lightPin,OUTPUT);
}

void loop(){
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
