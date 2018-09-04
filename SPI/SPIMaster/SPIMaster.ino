#include <SPI.h>

void setup() {
  // put your setup code here, to run once:
  SPI.begin();//SPI 통신 초기화
  digitalWrite(SS,HIGH);//슬레이브가 선택되지 않은 상태로 유지
  //안정적인 전송을 위해 분주비를 높여 전송 속도를 낮춤
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char data=Serial.read();//데이터 입력 확인
    if(data == 'K'){
      digitalWrite(SS,LOW);//슬레이브를 선택한다
      //1바이트 데이터 수신을 위해 의미없는 1바이트 데이터전송
      char received = SPI.transfer(0);
      digitalWrite(SS,HIGH);//슬레이브 선택 해제한다
      Serial.println(received);
    }
  }

}
