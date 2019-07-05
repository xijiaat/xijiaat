import processing.serial.*;
PImage img;
Serial myPort;
String val; 
boolean flag = false;
boolean flag1 = false;
PFont f; //声明字体变量
int cnt = 0;
long lasttime = 0;
void setup(){
  size(800,800);
  noStroke();
  img=loadImage("001.jpg");
  image(img,0,0);
  myPort = new Serial(this, Serial.list()[0], 9600);
  f=createFont("黑体",40,true);
  textFont(f,40);
  fill(#FF43C7);
  text("坐姿矫正仪",500,50);
  textFont(f,30);
  fill(#FF4800);
  text("已矫正次数",640,230);
  text("提示",640,330);
  text("距离cm",640,430);
}
void serialEvent(Serial myPort)
{
  if( myPort.available() > 0) {  // If data is available,
    val = myPort.readStringUntil('\n');
  }
  if(val!=null)
  {
    flag = true;
    println(val.trim());
  }
}
void draw()
{
  if(flag&&val != null){
    if(int(val.trim())<400)
    {
      fill(255);
      rect(530,400,100,50);
      fill(0);
      text(int(val.trim()),535,440);
    }
    if(int(val.trim())<20)
    {
      flag1 = true;
      fill(random(150,255),0,0);
      rect(530,300,100,50);
    }
    else
    {
      if(flag1&&((millis()-lasttime)>3000)){lasttime = millis();cnt++;flag1 = false;}
      fill(0,255,0);
      rect(530,300,100,50);
      fill(255);
      rect(530,200,100,50);
      fill(0);
      text(cnt,535,240);
    }
    flag = false;
  }
}

void keyPressed(){
  if(keyCode == DELETE)
  {
    cnt = 0;
  }
}