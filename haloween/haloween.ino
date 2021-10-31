#define SENSOR_PIN 9
#define MP3_RX 8
#define MP3_TX 7
#define COIL_PIN 11 //3
#define LED_PIN 10 //10
#define SERVO_PIN 6
#define TRESHOLD 30000
#define COIL_HEAT_TIME 5000
#define battery 5 

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Servo.h>

SoftwareSerial SoftwareSerialPort(MP3_TX, MP3_RX);
DFRobotDFPlayerMini myDFPlayer;
Servo blower;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(COIL_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
  digitalWrite(LED_PIN, HIGH);
  blower.attach(6);
  blower.write(120);
  SoftwareSerialPort.begin(9600);
  myDFPlayer.begin(SoftwareSerialPort);
  myDFPlayer.volume(30);
  delay(10000);
  /**/
}


void randomSplash(int duration){
  long timer1 = millis();
  int onTime, offTime;
  while(millis() - timer1 < duration){
    long timer2 = millis();
    onTime = random(30, 200);
    offTime = random(60, 700);
    /*digitalWrite(LED_PIN, HIGH);
    delay(onTime); 
    digitalWrite(LED_PIN, LOW);
    delay(offTime); */
    
    while(millis() - timer2 < onTime){
      digitalWrite(LED_PIN, HIGH);
    }
    long timer3 = millis();
    while(millis() - timer3 < offTime){
      digitalWrite(LED_PIN, LOW);
    }
  }
  digitalWrite(LED_PIN, LOW);
}

long current;
void loop() {
  /*if(digitalRead(SENSOR_PIN)){
    current = millis();
    //myDFPlayer.play(1);
    digitalWrite(COIL_PIN, HIGH);
    randomSplash(COIL_HEAT_TIME);
    
    myDFPlayer.play(2);
    delay(500);
    digitalWrite(LED_PIN, HIGH);
    for(int i = 0; i < 10; i++){
      blower.write(180); 
      delay(200);
      blower.write(80);
      delay(200);
    }
     digitalWrite(COIL_PIN, LOW);
     digitalWrite(LED_PIN, LOW);
     blower.write(100);
      while(millis() - current < TRESHOLD){}
    }*/
  /*digitalWrite(COIL_PIN, HIGH);
  delay(10000);
  digitalWrite(COIL_PIN, LOW);
  delay(700);
  digitalWrite(COIL_PIN, HIGH);
  delay(500);
  digitalWrite(COIL_PIN, LOW);
  delay(500);
  digitalWrite(COIL_PIN, HIGH);
  delay(500);
  digitalWrite(COIL_PIN, LOW);
  delay(5000);*/
}

/*long readVcc() { //функция чтения внутреннего опорного напряжения, универсальная (для всех ардуин)
#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
  ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
#elif defined (__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
  ADMUX = _BV(MUX5) | _BV(MUX0);
#elif defined (__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
  ADMUX = _BV(MUX3) | _BV(MUX2);
#else
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
#endif
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Start conversion
  while (bit_is_set(ADCSRA, ADSC)); // measuring
  uint8_t low  = ADCL; // must read ADCL first - it then locks ADCH
  uint8_t high = ADCH; // unlocks both
  long result = (high << 8) | low;

  result = my_vcc_const * 1023 * 1000 / result; // расчёт реального VCC
  return result; // возвращает VCC
}*/
