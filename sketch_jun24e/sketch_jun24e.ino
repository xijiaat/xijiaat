 int Led1=3;
  int Led2=4;
  int Led3=5;
  int Led4=6;
  int Led5=7;
void style_1(void) {
  unsigned char j;
  for (j=3;j<=7;j++)
  digitalWrite(j,HIGH);
  delay(300);
  for (j=7;j>=3;j--){
    digitalWrite(j,LOW);
    delay(300);
    }
 
}
void setup(){
  unsigned char i;
  for (i=3;i<=7;i++)
  pinMode(i,OUTPUT );

}

void loop() {
 
style_1();
}
