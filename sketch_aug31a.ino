// 블루투스 & 초음파센서
#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출

SoftwareSerial mySerial(2, 3); 
int trigPin = 4;
int echoPin = 5;


void setup(){
 Serial.begin(9600);
 mySerial.begin(9600); //블루투스 시리얼
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

void loop(){
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;

 Serial.print("\nDIstance:");
 Serial.print(distance);
 Serial.println("cm\n");
 delay(500);
 if (mySerial.available()) {      
 Serial.write(mySerial.read());  //블루투스 측 내용을 시리얼 모니터에 출력
  }
 if (Serial.available()) {        
 mySerial.write(Serial.read());  //시리얼 모니터 내용을 블루투스 측에 WRITE
  }
}
