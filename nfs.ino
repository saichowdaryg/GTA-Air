

int sp1 = A1;//right,left,front
int sp2 = A2;//right,left,front
int sp3 = A3;//back
int sp4 = A4;//esc
int sp5 = A5;//enter
int sw = 2; //switch to activate nfs-'air' !!!
int p1 = 13;//power for ir at A1 i.e right left front
int p2 = 12;//power for ir at A2 i.e right left front
int p3 = 11;//power for ir at A3 i.e back
int p4 = 10;//power for ir at A4 i.e esc
//int p5 = 9; //power for ir at A5 i.e enter
int g1 = 7;//ground for ir at A1
int g2 = 6;//ground for ir at A2
int g3 = 5;//ground for ir at A3
int g4 = 4;//ground for ir at A4
//int g5 = 3;//ground for ir at A5
int sv1 = 0;//variable to store the value from A1
int sv2 = 0;//variable to store the value from A2
int sv3 = 0;//variable to store the value from A3
int sv4 = 0;//variable to store the value from A4
//int sv5 = 0;//variable to store the value from A5
int irval=300;
int cstatus=50;
int pstatus=100;


void setup()
{
  
 
  pinMode(sw,INPUT ); 
   digitalWrite(sw, HIGH);
  pinMode(p1, OUTPUT);  
  digitalWrite(p1, HIGH); 
  pinMode(p2, OUTPUT);  
  digitalWrite(p2, HIGH);
  pinMode(p3, OUTPUT);  
  digitalWrite(p3, HIGH);
  pinMode(p4, OUTPUT);  
  digitalWrite(p4, HIGH);
  //pinMode(p5, OUTPUT);  
  //digitalWrite(p5, HIGH);
  pinMode(g1, OUTPUT);  
  digitalWrite(g1, LOW);
  pinMode(g2, OUTPUT);  
  digitalWrite(g2, LOW);
  pinMode(g3, OUTPUT);  
  digitalWrite(g3, LOW);
  pinMode(g4, OUTPUT);  
  digitalWrite(g4, LOW);
  //pinMode(g5, OUTPUT);  
  //digitalWrite(g5, LOW);
  Keyboard.begin();
  
  Serial.begin(9600);

}


void loop()
{
  
  sv1 = analogRead(sp1);
  sv2 = analogRead(sp2);
  sv3 = analogRead(sp3);
  sv4 = analogRead(sp4);  
/*  Serial.print(sv1);
  Serial.print("-");
  Serial.print(sv2);
  Serial.print("-");
  Serial.print(sv3);
  Serial.print("-");
  Serial.println(sv4);*/
 
//  sv5 = analogRead(sp5);
 
  delay(500);// check if program runs better without this delay

if(digitalRead(sw)==HIGH)
{
  
  if(sv4>irval)// highest importance to esc
  {
     Keyboard.releaseAll();
     Keyboard.press(KEY_ESC); 
    Serial.println("escape");
    delay(500);
  }
  else if(sv3>irval && sv4 < irval)// next importance to brake
  {
    cstatus=0;
    if(cstatus!=pstatus)
    {
       Keyboard.releaseAll();
    }
       Keyboard.press(KEY_DOWN_ARROW); 
    Serial.println("back");
    
  }
  else if(sv1>irval && sv2 >irval && sv3< irval && sv4<irval)
  {
    cstatus=1;
    if(cstatus!=pstatus)
    {
       Keyboard.releaseAll();
    }
      Keyboard.press(KEY_UP_ARROW); 
    Serial.println("forward");
    
  }
  else if(sv1>irval && sv2<irval && sv3< irval && sv4<irval)
  {
    cstatus=2;
    if(cstatus!=pstatus)
    {
       Keyboard.releaseAll();
    }
       Keyboard.press(KEY_RIGHT_ARROW); 
    Serial.println("right");
    
  }
   else if(sv1<irval && sv2>irval && sv3< irval && sv4<irval)
  {
    cstatus=3;
    if(cstatus!=pstatus)
    {
      Keyboard.releaseAll();
    }
      Keyboard.press(KEY_LEFT_ARROW); 
    Serial.println("left");
    
  }
  else
  {
    Keyboard.releaseAll();
  }
 pstatus=cstatus;

}

else 
{
   Keyboard.releaseAll();
}
}
