# Serial_Communication
Arduino IDE와 Arduino Uno 2대를 사용하여 UART와 I2C 통신을 하는것

# UART 시리얼 통신

    병렬 및 직렬 방식으로 데이터를 전송하는 하드웨어 일종이다. 그리고 마이크로 컨트롤러에서 사요되는 대표적인 시리얼 통신중 하나이다.
    UART 시리얼 통신은 1:1 통신이라서 마스터와 슬레이브를 따로 정하지 않는다.
    수신부 : RX
    송신부 : TX
    
# Arduino Uno connection
    
   ![uart](https://user-images.githubusercontent.com/38156821/45004275-4bb1f600-b026-11e8-9294-ece85b2f261f.jpeg)
   <br>사진과 같이 송신하는 Uno에 TX를 연결하고 수신받는 Uno에 RX를 연결을 하고 서로 GND를 연결해준다.
    
# UART RX측에서 에러 발생시

    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    이러한 에러가 발생을 하면 RX를 연결을 한 점퍼선을 빼고 업로드를 한 후에 연결을 해주면 이상 없이 실행이 된다 

# UART의 소프트웨어적인 사용법

    이러한 방법 말고 Softwareserial이라는 라이브러리를 이용하여 하드웨어직으로 사용할수 있는 RX와 TX핀을 사용하지 않고 다른핀을 이용하여 사용할수 있다.
    사용할 핀을 설정하려면 SoftwareSerial mySerial(2,3)과 같은 방법으로 해준다 앞의 숫자는 RX, 뒤에 숫자는 TX를 의미 한다
    일반적인 Serial 통시놔 같이 begin을 이용하여 포트를 활성을 하거나, availabe을 이용해 입력값이 있는지 확인을 하거나, read나 print, write를 사용하여 입츨력을 한다.

# SPI 통신
    
    SPI통신은 1:N 연결을 지원하고 Master-Slave모드 통신을 합니다.
    SPI통신을 위해서 MISO와 MOSI, SCK, SS 을 사용하는 4-wire이다. 
    SPI통신은 SS를 이용하기 때문에 같은 주소 충돌이 발생하지 않지만 연결 장치수가 늘어날수록 연결선의 수가 늘어납니다.
    아두이노에서 SPI통신을 위한 라이브러리를 제공하고 주변장치와 쉽게 SPI통신을 할 수 있습니다.
    
# pinout
    
    SS 의 Alternative Names는 nCS, CS, nSS, STE, CE 이고 Slave Select, Chip Enable(Master 장치가 여러개의 Slave 장치와 통신할 때 하나를 선택하여 귓속말 하려고 할때 사용하는)기능을 한다. 
    MOSI의 Alternative Names 는 SKI, DI, SI이고 Master Output Slave Input(Master에서 Slave로 가는 방향성이 있는 데이터 선) 기능을 한다.
    MISO의 Alternative Names  는 SDO, DO, SO이고 Slave Output Master Input(Slave에서 Master로 가는 방향성 있는 데이터 선) 기능을 한다.
    SCLK의 Alternative Names 는 SCK, CLK이고 Serial Clock(단순 동기화 신호, 통신 Clock) 기능을 한다.

# Arduino Uno connection
![spi](https://user-images.githubusercontent.com/38156821/45010177-17026680-b047-11e8-962b-74693b7e0253.jpeg)


# I2C 통신

    I2C통신은 직렬 컴퓨터 버스이며, 마더보드, 임베디드 시스템, 휴대전화 등에 저속의 저변기기 연결을 위해 사용한다
    I2C통신은 1:N연결을 지원하고 Master-Slave모드로 통신을 합니다.
    I2C통신은 SPI와는 다르게 슬레이브 선택을 위해 소프트 워어적인 주소를 사용하므로 연결핀이 증가하지 않는다.
    I2C통신은 데이터 송수신 하기 위한 SDA와 동기화 클록을 위한 SCL핀 2개만 사용한다.
    UART나 SPI와 비교를 하면 속도에서 한계가 있으므로 제한이 되나 비교적 간단하게 1:N통신이 지원된다
    SPI통신에서 마스터가 슬레이브로 부터 데이터를 수신하기 위해서는 슬레이브로 데이터를 송신을 해야한다.
    1바이트를 얻기 위해서 1바이트를 전송을 해야한다.

# Arduino Uno connection

   ![i2c](https://user-images.githubusercontent.com/38156821/45004276-4f457d00-b026-11e8-866a-9aba1586b468.jpeg)

