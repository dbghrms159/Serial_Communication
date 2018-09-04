#include <Wire.h>
#define SLAVE 4 //슬레이브 주소

void setup() {
  // put your setup code here, to run once:
  Wire.begin();//wire 라이브러리 초기화
  Serial.begin(9600);//직렬 통신 초기화
  Serial.println("I2C");
}

void loop() {
  // put your main code here, to run repeatedly:
  i2c_communication();//슬레이브로 데이터 요구및 수신 데이터 처리
  delay(1000);
}

void i2c_communication(){
  Wire.requestFrom(SLAVE,1);//1바이트 크기의 데이터 요청
  char c = Wire.read();//수신 데이터 읽기
  Serial.println(c);// 수신 데이터 출
}

