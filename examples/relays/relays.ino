#include <SwitchedDevice.h>


// a relay is a switchedDevice
typedef SwitchedDevice Relay;


// define an individual relay
Relay relay1(1);


// define an array of relays
Relay relays[] = { Relay(2, ON),
                   Relay(3, OFF),
                   Relay(4, OFF),
                   Relay(5, ON),
                  };


const int interval  = 2000;           // 2 seconds
unsigned long previousMillis = 0UL;


/*--------------------------------------------------------------------------------------
 setup()
 Called by the Arduino framework once, before the main loop begins
 --------------------------------------------------------------------------------------*/
void setup()
{

  Serial.begin(9600);

  relay1.init();

  Serial.print("relay1 is connected to pin ");
  Serial.print(relay1.pin());
  Serial.print(" and is ");
  relay1.state() ? Serial.println(" ON") : Serial.println(" OFF");

  for (byte idx=0; idx<(sizeof(relays)/sizeof(Relay)); idx++)
  {
    relays[idx].init();
    Serial.print("Relay[");
    Serial.print(idx);
    Serial.print("] is connected to pin ");
    Serial.print(relays[idx].pin());
    Serial.print(" and is ");
    relays[idx].state() ? Serial.println(" ON") : Serial.println(" OFF");
  }

}


/*--------------------------------------------------------------------------------------
 loop()
 Arduino main loop
 --------------------------------------------------------------------------------------*/
void loop()
{
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    relays[0].switchState();
    Serial.print("Relay[0] switched to state ");
    relays[0].state() ? Serial.print("ON") : Serial.print("OFF") ;
    Serial.print(" at ");
    relays[0].state() ? Serial.print(relays[0].last_on()) : Serial.print(relays[0].last_off());
    Serial.println();
  }

}
