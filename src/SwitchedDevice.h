#ifndef __SWITCHEDDEVICE_H__
#define __SWITCHEDDEVICE_H__


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#define ON  HIGH
#define OFF LOW


class SwitchedDevice
{
public:
    SwitchedDevice(byte pin = 0, byte initial_state = OFF, byte master_pin = -1);
private:
    byte _pin;
    byte _master_pin;
    byte _initial_state;
    unsigned long _last_on;
    unsigned long _last_off;
public:
    void init();
    byte pin();
    byte master_pin();
    unsigned long last_on();
    unsigned long last_off();
    byte state();
    byte switchOn();
    byte switchOff();
    byte switchState();
    void printDeviceInfo();
};


#endif
