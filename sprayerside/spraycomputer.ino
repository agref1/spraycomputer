
#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver(2000, 15, 14);
long buttonstates =0;

// eerste relaykaart
const int RELAY1  = 22;
const int RELAY2  = 23;
const int RELAY3  = 24;
const int RELAY4  = 25;
const int RELAY5  = 26;
const int RELAY6  = 27;
const int RELAY7  = 28;
const int RELAY8  = 29;

// tweede relaykaart

const int RELAY11  = 30;
const int RELAY12  = 31;
const int RELAY13  = 32;
const int RELAY14  = 33;
const int RELAY15  = 34;
const int RELAY16  = 35;
const int RELAY17  = 36;
const int RELAY18  = 37;


//derde relaykaart
const int RELAY21  = 38;
const int RELAY22  = 39;
const int RELAY23  = 40;
const int RELAY24  = 41;
const int RELAY25  = 42;
const int RELAY26  = 43;
const int RELAY27  = 44;
const int RELAY28  = 45;


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  pinMode(RELAY5, OUTPUT);
  pinMode(RELAY6, OUTPUT);
  pinMode(RELAY7, OUTPUT);
  pinMode(RELAY8, OUTPUT);
  pinMode(RELAY11, OUTPUT);
  pinMode(RELAY12, OUTPUT);
  pinMode(RELAY13, OUTPUT);
  pinMode(RELAY14, OUTPUT);
  pinMode(RELAY15, OUTPUT);
  pinMode(RELAY16, OUTPUT);
  pinMode(RELAY17, OUTPUT);
  pinMode(RELAY18, OUTPUT);
  pinMode(RELAY21, OUTPUT);
  pinMode(RELAY22, OUTPUT);
  pinMode(RELAY23, OUTPUT);
  pinMode(RELAY24, OUTPUT);
  pinMode(RELAY25, OUTPUT);
  pinMode(RELAY26, OUTPUT);
  pinMode(RELAY27, OUTPUT);
  pinMode(RELAY28, OUTPUT);

  if (!driver.init())
        Serial.println("init failed");
}

// the loop function runs over and over again forever
void loop() {
    uint8_t buf[24];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;

      memcpy(&buttonstates, buf, sizeof(buttonstates));
      // Message with a good checksum received, dump it.
      Serial.print("Message: ");
      Serial.println(buttonstates , BIN);   

       Serial.print("bitread: ");
       Serial.println(bitRead(buttonstates, 0));         

        //relaykaart 1
        if(bitRead(buttonstates, 0) == 1){
           digitalWrite(RELAY1, HIGH); 
        }else{
           digitalWrite(RELAY1, LOW); 
        }
        if(bitRead(buttonstates, 1) == 1){
           digitalWrite(RELAY2, HIGH); 
        }else{
           digitalWrite(RELAY2, LOW); 
        }
        if(bitRead(buttonstates, 2) == 1){
           digitalWrite(RELAY3, HIGH); 
        }else{
           digitalWrite(RELAY3, LOW); 
        }
        if(bitRead(buttonstates, 3) == 1){
           digitalWrite(RELAY4, HIGH); 
        }else{
           digitalWrite(RELAY4, LOW); 
        }
        if(bitRead(buttonstates, 4) == 1){
           digitalWrite(RELAY5, HIGH); 
        }else{
           digitalWrite(RELAY5, LOW); 
        }
        if(bitRead(buttonstates, 5) == 1){
           digitalWrite(RELAY6, HIGH); 
        }else{
           digitalWrite(RELAY6, LOW); 
        }
         if(bitRead(buttonstates, 6) == 1){
           digitalWrite(RELAY7, HIGH); 
        }else{
           digitalWrite(RELAY7, LOW); 
        }
        if(bitRead(buttonstates, 7) == 1){
           digitalWrite(RELAY8, HIGH); 
        }else{
           digitalWrite(RELAY8, LOW); 
        }

        //relaykaart 2
        if(bitRead(buttonstates, 8) == 1){
           digitalWrite(RELAY11, HIGH); 
        }else{
           digitalWrite(RELAY11, LOW); 
        }
        if(bitRead(buttonstates, 9) == 1){
           digitalWrite(RELAY12, HIGH); 
        }else{
           digitalWrite(RELAY12, LOW); 
        }
        if(bitRead(buttonstates, 10) == 1){
           digitalWrite(RELAY13, HIGH); 
        }else{
           digitalWrite(RELAY13, LOW); 
        }
        if(bitRead(buttonstates, 11) == 1){
           digitalWrite(RELAY14, HIGH); 
        }else{
           digitalWrite(RELAY14, LOW); 
        }
        if(bitRead(buttonstates, 12) == 1){
           digitalWrite(RELAY15, HIGH); 
        }else{
           digitalWrite(RELAY15, LOW); 
        }
        if(bitRead(buttonstates, 13) == 1){
           digitalWrite(RELAY16, HIGH); 
        }else{
           digitalWrite(RELAY16, LOW); 
        }
         if(bitRead(buttonstates, 14) == 1){
           digitalWrite(RELAY17, HIGH); 
        }else{
           digitalWrite(RELAY17, LOW); 
        }
        if(bitRead(buttonstates, 15) == 1){
           digitalWrite(RELAY18, HIGH); 
        }else{
           digitalWrite(RELAY18, LOW); 
        }

                //relaykaart 3
        if(bitRead(buttonstates, 16) == 1){
           digitalWrite(RELAY21, HIGH); 
        }else{
           digitalWrite(RELAY21, LOW); 
        }
        if(bitRead(buttonstates, 17) == 1){
           digitalWrite(RELAY22, HIGH); 
        }else{
           digitalWrite(RELAY22, LOW); 
        }
        if(bitRead(buttonstates, 18) == 1){
           digitalWrite(RELAY23, HIGH); 
        }else{
           digitalWrite(RELAY23, LOW); 
        }
        if(bitRead(buttonstates, 19) == 1){
           digitalWrite(RELAY24, HIGH); 
        }else{
           digitalWrite(RELAY24, LOW); 
        }
        if(bitRead(buttonstates, 20) == 1){
           digitalWrite(RELAY25, HIGH); 
        }else{
           digitalWrite(RELAY25, LOW); 
        }
        if(bitRead(buttonstates, 21) == 1){
           digitalWrite(RELAY26, HIGH); 
        }else{
           digitalWrite(RELAY26, LOW); 
        }
         if(bitRead(buttonstates, 22) == 1){
           digitalWrite(RELAY27, HIGH); 
        }else{
           digitalWrite(RELAY27, LOW); 
        }
        if(bitRead(buttonstates, 23) == 1){
           digitalWrite(RELAY28, HIGH); 
        }else{
           digitalWrite(RELAY28, LOW); 
        }
    }

}
