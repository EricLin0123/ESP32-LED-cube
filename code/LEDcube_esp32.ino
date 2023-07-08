int latchPin = 14;  // Latch pin (STCP腳位)
int clockPin = 12; // Clock pin (SHCP腳位)
int dataPin = 27;  // Data pin (DS腳位)
int mrPin = 13; // reset pin (MR)
int startTime;
int Duration;
int Duration2;
int blinkDuration = 5000;
int OnTime=500; //可自訂led On的時間
int OffTime=500; //可自訂led Off的時間
int time1 = 3000;
int time2 = 3000;
int state = 1;
int initialTime;
int t = 3000;
boolean Status;
boolean Status2;
int x = 200;
#include<time.h> 
void(* resetFunc) (void) = 0;
void setup() { 
  Serial.begin(115200);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(mrPin, OUTPUT);
  startTime=millis();
  initialTime = millis();
  Status = HIGH;
  Status2 = HIGH;
  digitalWrite(mrPin, LOW);
  delay(50);
  digitalWrite(mrPin, HIGH);
}
void loop(){
  gogogo();
  }
void goup(){
  initialTime = millis(); 
  int n = 128;
  Serial.println("going up");
  while (true) 
  { 
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, n);  
    shiftOut(dataPin, clockPin, MSBFIRST, 255);  
    shiftOut(dataPin, clockPin, MSBFIRST, 255); 
    digitalWrite(latchPin, HIGH);
    if(initialTime < 0){
      initialTime = millis(); 
    }
    if ((millis() - initialTime)  >= x && n > 16) {
      Serial.println("switch layer");
      Serial.println(millis());
      Serial.println(initialTime);
      n = n/2;
      initialTime = millis(); 
      } 
    else if((millis() - initialTime)  >= x && n <= 16){
      break;
    }
  } 
}
void godown(){
  initialTime = millis(); 
  int n = 16;
  Serial.println("going down");
  while (true) 
  { 
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, n);  
    shiftOut(dataPin, clockPin, MSBFIRST, 255);  
    shiftOut(dataPin, clockPin, MSBFIRST, 255); 
    digitalWrite(latchPin, HIGH);
    if(initialTime < 0){
   initialTime = millis(); 
    }
    if ((millis() - initialTime)  >= x && n < 134) {
      Serial.println(millis());
      Serial.println(initialTime);
      n = n*2;
      initialTime = millis(); 
      Serial.println("switch layer");
      } 
    else if((millis() - initialTime)  >= x && n >= 128){
      break;
    }
  } 
}
void wall(int n){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 16);  
  shiftOut(dataPin, clockPin, MSBFIRST, n);  
  shiftOut(dataPin, clockPin, MSBFIRST, n); 
  digitalWrite(latchPin, HIGH);
  delay(1);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 32);  
  shiftOut(dataPin, clockPin, MSBFIRST, n);  
  shiftOut(dataPin, clockPin, MSBFIRST, n);  
  digitalWrite(latchPin, HIGH);
  delay(1);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 64);  
  shiftOut(dataPin, clockPin, MSBFIRST, n);  
  shiftOut(dataPin, clockPin, MSBFIRST, n);  
  digitalWrite(latchPin, HIGH);
  delay(1);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 128);  
  shiftOut(dataPin, clockPin, MSBFIRST, n);  
  shiftOut(dataPin, clockPin, MSBFIRST, n);  
  digitalWrite(latchPin, HIGH);
  delay(1);
}
void goleft(){
  initialTime = millis(); 
  int n = 136;
  Serial.println("going left");
  while (true) 
  { 
    wall(n);
    if(initialTime < 0){
      initialTime = millis(); 
    }
    if ((millis() - initialTime)  >= x && n > 17) {
      Serial.println(millis());
      Serial.println(initialTime);
      n = n/2;
      initialTime = millis(); 
      Serial.println("switch layer");
      } 
    else if((millis() - initialTime)  >= x && n <= 17){
      break;
    }
  } 
}
void goright(){
  initialTime = millis(); 
  int n = 17;
  Serial.println("going right");
  while (true) 
  { 
    wall(n);
    if(initialTime < 0){
     initialTime = millis(); 
    }
    if ((millis() - initialTime)  >= x && n < 134) {
      Serial.println(millis());
      Serial.println(initialTime);
      n = n*2;
      initialTime = millis(); 
      Serial.println("switch layer");
      } 
    else if((millis() - initialTime)  >= x && n >= 134){
      break;
    }
  } 
}
void wall2(int n, int m){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 16);  
  shiftOut(dataPin, clockPin, MSBFIRST, n);  
  shiftOut(dataPin, clockPin, MSBFIRST, m); 
  digitalWrite(latchPin, HIGH);
  delay(1);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 32);  
  shiftOut(dataPin, clockPin, MSBFIRST, n);  
  shiftOut(dataPin, clockPin, MSBFIRST, m);  
  digitalWrite(latchPin, HIGH);
  delay(1);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 64);  
  shiftOut(dataPin, clockPin, MSBFIRST, n);  
  shiftOut(dataPin, clockPin, MSBFIRST, m);  
  digitalWrite(latchPin, HIGH);
  delay(1);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 128);  
  shiftOut(dataPin, clockPin, MSBFIRST, n);  
  shiftOut(dataPin, clockPin, MSBFIRST, m);  
  digitalWrite(latchPin, HIGH);
  delay(1);
}
void gofront(){
  initialTime = millis(); 
  int n = 17;
  Serial.println("going front");
  while (true) 
  { 
    wall2(240, 0);
    if(initialTime < 0){
     initialTime = millis(); 
    }
    if ((millis() - initialTime)  >= x) {
      break;
      } 
  } 
  Serial.println("switch layer");
  initialTime = millis(); 
  while (true) 
  { 
    wall2(15, 0);
    if(initialTime < 0){
 initialTime = millis(); 
    }
    if ((millis() - initialTime)  >= x) {
      break;
      } 
  } 
  Serial.println("switch layer");
  initialTime = millis(); 
  while (true) 
  { 
    wall2(0, 240);
    if(initialTime < 0){
     initialTime = millis(); 
    }
    if ((millis() - initialTime)  >= x) {
      break;
      } 
  } 
  Serial.println("switch layer");
  initialTime = millis(); 
  while (true) 
  { 
    wall2(0, 15);
    if(initialTime < 0){
  initialTime = millis(); 
    }
    if ((millis() - initialTime)  >= x) {
      break;
      } 
  } 
}
void goback(){
  initialTime = millis(); 
  int n = 17;
  Serial.println("going back");
  while (true) 
  { 
    wall2(0, 15);
    if(initialTime < 0){
      initialTime = millis(); 
    }
    if ((millis() - initialTime)  >= x) {
      break;
      } 
  } 
  Serial.println("switch layer");
  initialTime = millis(); 
  while (true) 
  { 
    wall2(0, 240);
    if(initialTime < 0){
      initialTime = millis(); 
    }
    if ((millis() - initialTime)  >= x) {
      break;
      } 
  } 
  Serial.println("switch layer");
  initialTime = millis(); 
  while (true) 
  { 
    wall2(15, 0);
    if(initialTime < 0){
      initialTime = millis(); 
    }
    if ((millis() - initialTime)  >= x) {
      break;
      } 
  } 
  Serial.println("switch layer");
  initialTime = millis(); 
  while (true) 
  { 
    wall2(240, 0);
    if(initialTime < 0){
      initialTime = millis(); 
    }
    if ((millis() - initialTime)  >= x) {
      break;
      } 
  } 
}
void outside() { 
 
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 128);  
  shiftOut(dataPin, clockPin, LSBFIRST, 249);  
  shiftOut(dataPin, clockPin, LSBFIRST, 159); 
  digitalWrite(latchPin, HIGH);
  delay(1);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 64);  
  shiftOut(dataPin, clockPin, LSBFIRST, 144);  
  shiftOut(dataPin, clockPin, LSBFIRST, 9);  
  digitalWrite(latchPin, HIGH);
  delay(1);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 32);  
  shiftOut(dataPin, clockPin, LSBFIRST, 144);  
  shiftOut(dataPin, clockPin, LSBFIRST, 9);  
  digitalWrite(latchPin, HIGH);
  delay(1);
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 16);  
  shiftOut(dataPin, clockPin, LSBFIRST, 249);  
  shiftOut(dataPin, clockPin, LSBFIRST, 159);
  digitalWrite(latchPin, HIGH);
  delay(1);
}
void inside(){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 128);  
  shiftOut(dataPin, clockPin, LSBFIRST, 0);  
  shiftOut(dataPin, clockPin, LSBFIRST, 0); 
  digitalWrite(latchPin, HIGH);
  delay(1);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 64);  
  shiftOut(dataPin, clockPin, LSBFIRST, 6);  
  shiftOut(dataPin, clockPin, LSBFIRST, 96);  
  digitalWrite(latchPin, HIGH);
  delay(1);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 32);  
  shiftOut(dataPin, clockPin, LSBFIRST, 6);  
  shiftOut(dataPin, clockPin, LSBFIRST, 96);  
  digitalWrite(latchPin, HIGH);
  delay(1);
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 16);  
  shiftOut(dataPin, clockPin, LSBFIRST, 0);  
  shiftOut(dataPin, clockPin, LSBFIRST, 0);  
  digitalWrite(latchPin, HIGH);
  delay(1);
}
void blink(){
  int interval = 500;
  initialTime = millis(); 
  Serial.println("blinking");
  boolean y = true;
  while (y) 
  { 
    outside();
    if(initialTime < 0){
      initialTime = millis(); 
    }
    if ((millis() - initialTime)  >= interval && y) {
      Serial.println("switch in/out");
      Serial.println(millis());
      Serial.println(initialTime);
      y = !y;
      initialTime = millis(); 
      break;
      } 
  } 
  while (!y) 
  { 
    inside();
    if(initialTime < 0){
      initialTime = millis(); 
    }
    if ((millis() - initialTime)  >= interval && !y) {
      Serial.println("switch out/in");
      Serial.println(millis());
      Serial.println(initialTime);
      y = !y;
      initialTime = millis(); 
      break;
      } 
  } 
}
void gogogo(){
    Duration=millis()-startTime;
    Serial.println(Duration);
    Serial.println("state");
    Serial.println(state);
    if(state == 1){
      goup();
      if(Duration > t){
        startTime =millis();
        state = 2;
      }
    }
    else if(state == 2){
      godown();
      if(Duration > t){
        startTime =millis();
        state = 3;
      }
    }
    else if(state == 3){
      goleft();
      if(Duration > t){
        startTime =millis();
        state = 4;
      }
    }
    else if(state == 4){
      goright();
      if(Duration > t){
        startTime =millis();
        state = 5;
      }
    }
    else if(state == 5){
      gofront();
      if(Duration > t){
        startTime =millis();
        state = 6;
      }
    }
    else if(state == 6){
      goback();
      if(Duration > t){
        startTime =millis();
        state = 7;
      }
    }    
    else if(state == 7){
      blink();
      if(Duration > t){
        startTime =millis();
        state = 1;
        //resetFunc();
      }
    }   
}
void full(){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 128);  
  shiftOut(dataPin, clockPin, LSBFIRST, 255);  
  shiftOut(dataPin, clockPin, LSBFIRST, 255); 
  digitalWrite(latchPin, HIGH);
  delay(1);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 64);  
  shiftOut(dataPin, clockPin, LSBFIRST, 255);  
  shiftOut(dataPin, clockPin, LSBFIRST, 255);  
  digitalWrite(latchPin, HIGH);
  delay(1);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 32);  
  shiftOut(dataPin, clockPin, LSBFIRST, 255);  
  shiftOut(dataPin, clockPin, LSBFIRST, 255);  
  digitalWrite(latchPin, HIGH);
  delay(1);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 16);  
  shiftOut(dataPin, clockPin, LSBFIRST, 255);  
  shiftOut(dataPin, clockPin, LSBFIRST, 255);  
  digitalWrite(latchPin, HIGH);
  delay(1);
}





