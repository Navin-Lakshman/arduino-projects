#include<IRremote.h>
#include<LiquidCrystal.h>
#define I 7
#define I1 3
#define I2 4
#define I3 5
#define I4 6
#define BU A1
#define RS 13
#define E 12
#define D4 11
#define D5 10
#define D6 9 
#define D7 8

int c = 0;
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
IRrecv ir;
void gof(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Strait ah Po!");
    digitalWrite(I1,HIGH);
    digitalWrite(I2,LOW);
    digitalWrite(I3,HIGH);
    digitalWrite(I4,LOW);
    delay(100);
    digitalWrite(I1,LOW);
    digitalWrite(I2,LOW);
    digitalWrite(I3,LOW);
    digitalWrite(I4,LOW);
    ir.resume();
}
void gob(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("pinadi Po!");
    digitalWrite(I1,LOW);
    digitalWrite(I2,HIGH);
    digitalWrite(I3,LOW);
    digitalWrite(I4,HIGH);
    delay(100);
    digitalWrite(I1,LOW);
    digitalWrite(I2,LOW);
    digitalWrite(I3,LOW);
    digitalWrite(I4,LOW);
    ir.resume();
}
void lf(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("left Po!");
    digitalWrite(I1,LOW);
    digitalWrite(I2,HIGH);
    digitalWrite(I3,HIGH);
    digitalWrite(I4,LOW);
    delay(100);
    digitalWrite(I1,LOW);
    digitalWrite(I2,LOW);
    digitalWrite(I3,LOW);
    digitalWrite(I4,LOW);
    ir.resume();
}
void rt(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Right Po!");
    digitalWrite(I1,HIGH);
    digitalWrite(I2,LOW);
    digitalWrite(I3,LOW);
    digitalWrite(I4,HIGH);
    delay(100);
    digitalWrite(I1,LOW);
    digitalWrite(I2,LOW);
    digitalWrite(I3,LOW);
    digitalWrite(I4,LOW); 
    ir.resume();
}
void so(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nillu..!");
    digitalWrite(I1,LOW);
    digitalWrite(I2,LOW);
    digitalWrite(I3,LOW);
    digitalWrite(I4,LOW);
    ir.resume();
}
void setup(){
  
  ir.begin(I);

  pinMode(BU,OUTPUT);
  pinMode(I4,OUTPUT);
  pinMode(I3,OUTPUT);
  pinMode(I2,OUTPUT);
  pinMode(I1,OUTPUT);

  lcd.begin(16,2);
}
        //POer on 21
        //front 116
        //back 117
        //left 52
        //right 51
        //stop 101

void loop(){
  if(ir.decode()){
      auto k=ir.decodedIRData.command;
      if(k==21&&c==0){
        c++;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Vanako da mapla");
        digitalWrite(BU,HIGH);
        delay(100);                                                                                   
        digitalWrite(BU,LOW);
        ir.resume();
        
      }
      // else{
      //   c=0;
      //   lcd.clear();
      //   lcd.setCursor(0, 0);
      //   lcd.print("Varta mamae durr");
      //   delay(100);
      //   digitalWrite(BU,HIGH);
      //   delay(100);
      //   digitalWrite(BU,LOW);
      //   ir.resume();
      //   //goto act;
      // }
        k=ir.decodedIRData.command;
        switch (k) {
        case 116:
          gof();
          break;
        case 117:
          gob();
          break;
        case 52:
          lf();
          break;
        case 51:
          rt();
          break;  
        case 101:
          so();
          break;
        default:
          ir.resume();
          break;
        }
     // act:
       ir.resume();
    }
  }
