/* Simplified Logitech Extreme 3D Pro Joystick Report Parser */
#include <Logging.h>
#include <hid.h>
#include <hiduniversal.h>
#include <usbhub.h>

#include "data.h"
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


#define THIS "JOYS: "

void joystick_setup()
{
  //  //analogWrite(13, 200);
  //  //Serial.begin( 250000 );
  //
  //#if !defined(__MIPSEL__)
  //  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  //#endif
  Log.Info(THIS"setup begins"CR);

  if (Usb.Init() == -1)
  {
    //analogWrite(13, 1);
    Log.Error(THIS"OSC did not start"CR);
  }
  else
  {
    Log.Info(THIS"started succesfully"CR);
  }

  delay( 200 );
  //analogWrite(13, 0);

  if (!Hid.SetReportParser(0, &Joy))
    ErrorMessage<uint8_t>(PSTR("SetReportParser"), 1  );

  Log.Info(THIS"setup ends"CR);
}

const GamePadEventData joystick_loop()
{
  Usb.Task();
  return gpadevt;
}


void JoystickEvents::OnGamePadChanged(const GamePadEventData *evt)
{
  gpadevt = *evt;
  // 0 to 0d1023 0x03FF
  Log.Verbose(THIS"X: %d Y: %d Z: %d Yaw: %d"CR, evt->x & 0x03C0, evt->y & 0x03C0, evt->slider, evt->twist); // 0 to 0d1023 0x03FF

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

