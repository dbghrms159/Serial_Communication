#include <SPI.h>
byte count;

void setup() {
  // put your setup code here, to run once:
  // SPI통신을 위한 핀들의 입출력 설정
  pinMode(MISO,OUTPUT);
  pinMode(MOSI,INPUT);
  pinMode(SCK,INPUT);
  pinMode(SS,INPUT);
  //마스터의 전송 속도에 맞추어 통신 속도를 설정한다
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  //SPI통신을 위한 레지스터를 설정
  SPCR |= _BV(SPE); // SPI활성화
  SPCR &= ~_BV(MSTR); // Slave모드 선택
  SPCR |= _BV(SPIE);  //인터럽트 허용
  count ='0'; //카운터 초기화

}
//SPI통신으로 데이터가 수신될떄 발생하는 인터럽트 처리 루틴
ISR(SPI_STC_vect){
  SPDR = count;//카운터값 아스키값으로 전달
}

void loop() {
  // put your main code here, to run repeatedly:
  count = (count + 1);

  delay(1000);
}
