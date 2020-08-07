#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
RH_ASK driver(2000, 15, 14);

//boom inputs
const int buttonPin1 = 22;     // the number of the pushbutton pin
const int buttonPin2 = 23;     // the number of the pushbutton pin
const int buttonPin3 = 24;     // the number of the pushbutton pin
const int buttonPin4 = 25;     // the number of the pushbutton pin
const int buttonPin5 = 26;     // the number of the pushbutton pin
const int buttonPin6 = 27;     // the number of the pushbutton pin
const int buttonPin7 = 28;     // the number of the pushbutton pin
const int buttonPin8 = 29;     // the number of the pushbutton pin
const int buttonPin9 = 30;     // the number of the pushbutton pin
const int buttonPin10 = 31;     // the number of the pushbutton pin
const int buttonPin11 = 32;     // the number of the pushbutton pin
const int buttonPin12 = 33;     // the number of the pushbutton pin

// sectie inputs
const int buttonPin13 = 34;     // input M
const int buttonPin14 = 35;     // R0
const int buttonPin15 = 36;     // R1
const int buttonPin16 = 37;     // R2
const int buttonPin17 = 38;     // R3
const int buttonPin18 = 39;     // c
const int buttonPin19 = 40;     // L3
const int buttonPin20 = 41;     // L2
const int buttonPin21 = 42;     // L1
const int buttonPin22 = 43;     // L0



long buttonstates =0;

byte tx_buf[sizeof(buttonstates)] = {0};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  pinMode(buttonPin7, INPUT_PULLUP);
  pinMode(buttonPin8, INPUT_PULLUP);
  pinMode(buttonPin9, INPUT_PULLUP);
  pinMode(buttonPin10, INPUT_PULLUP);
  pinMode(buttonPin11, INPUT_PULLUP);
  pinMode(buttonPin12, INPUT_PULLUP);
  pinMode(buttonPin13, INPUT_PULLUP);
  pinMode(buttonPin14, INPUT_PULLUP);
  pinMode(buttonPin15, INPUT_PULLUP);
  pinMode(buttonPin16, INPUT_PULLUP);
  pinMode(buttonPin17, INPUT_PULLUP);
  pinMode(buttonPin18, INPUT_PULLUP);
  pinMode(buttonPin19, INPUT_PULLUP);
  pinMode(buttonPin20, INPUT_PULLUP);
  pinMode(buttonPin21, INPUT_PULLUP);
  pinMode(buttonPin22, INPUT_PULLUP);

    if (!driver.init())
         Serial.println("init failed");
 
}

void loop() {
  // put your main code here, to run repeatedly:
 buttonstates = 0;


 if(!digitalRead(buttonPin1)){
  buttonstates = buttonstates | 1;
 }
 if(!digitalRead(buttonPin2)){
  buttonstates = buttonstates | 2;
 }
 if(!digitalRead(buttonPin3)){
  buttonstates = buttonstates | 4;
 }
 if(!digitalRead(buttonPin4)){
  buttonstates = buttonstates | 8;
 }
  if(!digitalRead(buttonPin5)){
  buttonstates = buttonstates | 16;
 }
  if(!digitalRead(buttonPin6)){
  buttonstates = buttonstates | 32;
 }
  if(!digitalRead(buttonPin7)){
  buttonstates = buttonstates | 64;
 }
  if(!digitalRead(buttonPin8)){
  buttonstates = buttonstates | 128;
 }
  if(!digitalRead(buttonPin9)){
  buttonstates = buttonstates | 256;
 }
  if(!digitalRead(buttonPin10)){
  buttonstates = buttonstates | 512;
 }
  if(!digitalRead(buttonPin11)){
  buttonstates = buttonstates | 1024;
 }
 if(!digitalRead(buttonPin12)){
  buttonstates = buttonstates | 2048;
 }
 if(!digitalRead(buttonPin13)){
     if(!digitalRead(buttonPin14)){
      buttonstates = buttonstates | 4096;
     }
     if(!digitalRead(buttonPin15)){
      buttonstates = buttonstates | 8192;
     }
     if(!digitalRead(buttonPin16)){
      buttonstates = buttonstates | 16384;
     }
     if(!digitalRead(buttonPin17)){
      buttonstates = buttonstates | 32768;
     }
     if(!digitalRead(buttonPin18)){
      buttonstates = buttonstates | 65536;
     }
     if(!digitalRead(buttonPin19)){
      buttonstates = buttonstates | 131072;
     }
     if(digitalRead(buttonPin20)){
      buttonstates = buttonstates | 262144;
     }
     if(!digitalRead(buttonPin21)){
      buttonstates = buttonstates | 524288;
     }
     if(!digitalRead(buttonPin22)){
      buttonstates = buttonstates | 1048576;
     }
 }

 
 Serial.println(buttonstates, BIN);
 Serial.println(buttonstates);


  memcpy(tx_buf, &buttonstates, sizeof(buttonstates) );
  byte zize=sizeof(buttonstates);

  driver.send((uint8_t *)tx_buf, zize);

  driver.waitPacketSent();

}
