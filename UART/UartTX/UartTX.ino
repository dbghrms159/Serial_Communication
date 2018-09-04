char message = 'A';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("UART A");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(message);
  message++;

  if(message > 'z'){
    message = 'A';
  }

  delay(1000);
}
