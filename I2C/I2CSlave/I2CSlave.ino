#include <Wire.h>
#define SLAVE 4

byte count = 'A';
void setup() {
  // put your setup code here, to run once:
  //wire라이브러리 초기화
  //슬레이브로 참여하기 위해선 주소를 지정을 해줘야 한다
  Wire.begin(SLAVE);
  //마스터의 데이터 전송요구가 있을때 처리할 함수 등록
  Wire.onRequest(sendToMaseter);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void sendToMaseter(){
  Wire.write(++count);

  if(count >= 'z'){
    count = 'A';
  }
}

