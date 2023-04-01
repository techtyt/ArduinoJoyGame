//Made on April 1 2023
//No April fools pranks here(really)
//Github.com/techtyt
#include <TimeLib.h>
#include <LiquidCrystal_I2C.h>
int start;//Used to measure time
int playtime;//Used to measure time
LiquidCrystal_I2C lcd(0x27,16,2);

int sw=0;//For press-to-start
int count=0;//Counts Clicks
int press=0;//Fixes the problem where the count increases by more than 1 when we press the joystick button

void setup(){
  digitalWrite(12,HIGH);//For reset function. Disconnect if Game does not start or you are facing problems when uploading, and it reconnect after uploading is done
  pinMode(2,INPUT);//Joystick button
  pinMode(A0,INPUT);//Joystick Y axis
  pinMode(A1,INPUT);//Joystick X axis
  pinMode(12,OUTPUT);//reset

  digitalWrite(2,HIGH);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Press to start");
  Serial.begin(9600);
}
void reset(){
}
void loop(){
  if(digitalRead(2)==0 and sw==0){
    lcd.clear();
    lcd.print("Starting.");
    delay(250);
    lcd.clear();
    lcd.print("Starting..");
    delay(300);
    lcd.clear();
    lcd.print("Starting.");
    delay(250);
    lcd.clear();
    start=now();
    sw=1;
    count=0;
    lcd.print(count);
  }

  delay(100);

  if(digitalRead(2)==0 and sw==1){
    press=1;}
  else{
      if(digitalRead(2)==1 and press==1){
        int pt=millis();
        count++;
        lcd.clear();
        lcd.print(count);
        press=0;
    }
  }  
  int x=analogRead(A0);
  int y=analogRead(A1);
  //Serial.println(x);
  //Serial.println(y);

  if(((analogRead(A1) > 600 and analogRead(A1) < 680)) or (analogRead(A1) >= 0 and analogRead(A1) < 50)){
    count=0;
    lcd.clear();
    lcd.print("Game over...");
    delay(1000);
    lcd.clear();
    digitalWrite(12,LOW);
  }

  if(((analogRead(A0) > 600 and analogRead(A0) < 680)) or (analogRead(A0) >= 0 and analogRead(A0) < 50)){
    lcd.clear();
    lcd.print("Game over...");
    delay(1000);
    lcd.clear();
    digitalWrite(12,LOW);
  }
  if(start==0){
    playtime=0;
  }
  else{  
    playtime = now() - start;
  }
  Serial.println(playtime);
  if(playtime>15){
    int tmp = count;
    lcd.clear();
    lcd.print("Time is up!");
    delay(1200);    
    lcd.clear();
    lcd.print("Score:");
    lcd.print(tmp);
    delay(1200);
    lcd.clear();
    tmp=0;
    digitalWrite(12,LOW);
  }
}
