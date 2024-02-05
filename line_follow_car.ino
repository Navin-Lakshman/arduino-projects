int ir1=9;
int ir2=10;
int in1=7;
int in2=6;
int in3=5;
int in4=4;
void setup() {
 pinMode(ir1,INPUT);
 pinMode(ir2,INPUT);
 pinMode(in1,OUTPUT);
 pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT);
 pinMode(in3,OUTPUT);
 pinMode(in4,OUTPUT);

}

void loop() {
  int n,l;
  n=digitalRead(ir1);
  l=digitalRead(ir2);
  //left light
  //digitalWrite(in1,HIGH);
  //digitalWrite(in2,LOW);
  //right light
    //digitalWrite(in4,HIGH);
   // digitalWrite(in3,LOW);
  if(n==1&&l==0)
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
  }
  else {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);}
  
  if(n==0&&l==1)
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
  }
  else {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);}

  if(n==0&&l==0)
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
  }
  else {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);}

  
  delay(1);  
}
