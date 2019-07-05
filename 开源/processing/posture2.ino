#define PULSE_TIMEOUT 150000L  // 100ms
const int EchoPin = 3; //超声波信号输入
const int TrigPin = 2; //超声波控制信号输出
const int bee = 4;
const int R = 5;
const int G = 6;
const int B = 7;
const int distance = 20; //超声波报警距离，此处20cm
long val;
long MeasuringDistance() {
  long duration;
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  duration = pulseIn(EchoPin, HIGH,PULSE_TIMEOUT);
  delay(10);
  return duration / 29 / 2;
}
void setup() {
  Serial.begin(9600);
  pinMode(bee,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  digitalWrite(bee,HIGH);
  digitalWrite(R,HIGH);
  digitalWrite(G,HIGH);
  digitalWrite(B,HIGH);
  randomSeed(analogRead(A0));
}

void loop() {
  for(int i = 0;i<10;i++){
     val += MeasuringDistance();
  }
  val=val/10;
  Serial.println(val);
  
  if(val>distance)
  {
    digitalWrite(bee,HIGH);
    digitalWrite(R,HIGH);
    digitalWrite(G,HIGH);
    digitalWrite(B,HIGH);
  }
  else
  {
    analogWrite(R,random(255));
    analogWrite(G,random(255));
    analogWrite(B,random(255));
    digitalWrite(bee,LOW);
  }
  val = 0;
}
