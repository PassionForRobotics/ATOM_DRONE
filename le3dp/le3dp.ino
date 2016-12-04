/* Simplified Logitech Extreme 3D Pro Joystick Report Parser */

#include <hid.h>
#include <hiduniversal.h>
#include <usbhub.h>

#include "le3dp_rptparser.h"

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif

USB                                             Usb;
USBHub                                          Hub(&Usb);
HIDUniversal                                    Hid(&Usb);
JoystickEvents                                  JoyEvents;
JoystickReportParser                            Joy(&JoyEvents);
GamePadEventData                                gpadevt;

void setup()
{
  //analogWrite(13, 200);
  Serial.begin( 250000 );
  
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  Serial.println("Start");

  if (Usb.Init() == -1)
  {
    //analogWrite(13, 1);
    Serial.println("OSC did not start.");
  }

  delay( 200 );
  //analogWrite(13, 0);

  if (!Hid.SetReportParser(0, &Joy))
    ErrorMessage<uint8_t>(PSTR("SetReportParser"), 1  );
}

void loop()
{
  Usb.Task();
}


void JoystickEvents::OnGamePadChanged(const GamePadEventData *evt)
{
  gpadevt = *evt;

  
  Serial.print("X: ");
  Serial.print(evt->x & 0x03C0); // 0 to 0d1023 0x03FF

  Serial.print(" Y: ");
  Serial.print(evt->y & 0x03C0); // 0 to 0d1023 0x03FF

  Serial.print(" Z: ");
  Serial.print(evt->slider); // 0 to 0d1023 0x03FF

  Serial.print(" Yaw: ");
  Serial.println(evt->twist); // 0 to 0d1023 0x03FF

//  Serial.print("X: ");
//  PrintHex<uint16_t>(evt->x, 0x80);
//  Serial.print(" Y: ");
//  PrintHex<uint16_t>(evt->y, 0x80);
//  Serial.print(" Hat Switch: ");
//  PrintHex<uint8_t>(evt->hat, 0x80);
//  Serial.print(" Twist: ");
//  PrintHex<uint8_t>(evt->twist, 0x80);
//  Serial.print(" Slider: ");
//  PrintHex<uint8_t>(evt->slider, 0x80);
//  Serial.print(" Buttons A: ");
//  PrintHex<uint8_t>(evt->buttons_a, 0x80);
//  Serial.print(" Buttons B: ");
//  PrintHex<uint8_t>(evt->buttons_b, 0x80);
//  Serial.println("");
}

