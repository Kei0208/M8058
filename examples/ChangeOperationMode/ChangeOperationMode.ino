/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//
//  This sample program sets the operation mode of the M8058.
//  Connect the commPin to the PA3 port of the M8058, and connect the Vdd to the
//  PB1 port via a resistor and an LED.
//  The values ​​that can be specified for the arguments of each method are listed
//  in M8058.h.
//
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

#include <M8058.h>

/* Control pins */
#define COMM_PIN (12)
#define NEXT_PIN (14)


M8058 m8058;


void setup()
{
  Serial.begin(115200);

  /* Init process (This can be set all at once using the "SetAllPins" method.)*/
  m8058.SetAllPins(COMM_PIN, NEXT_PIN);
  // SetCommandPin(COMM_PIN);
  // SetNextPin(NEXT_PIN);

  Serial.println("Initialization process completed!!");

  m8058.PlayMelody(MELODY_00);
  (void)m8058.ChangeVolume(NS_VOLUME_LEVEL_2);
  
  /* 
    Sets melody playback and LED on/off control.

    The default is "MELODY_LED_MODE".
      1. MELODY_ONLY_MODE : It will only play the melody and the LED will remain off. 
      2. LED_ONLY_MODE    : It only turns the LED on and off and does not play a melody.
      3. MELODY_LED_MODE  : It plays melodies and controls the LED on and off.
  */
  m8058.ChangeOperationMode(MELODY_ONLY_MODE);

  delay(5000);
}


void loop()
{
  m8058.PlayNext();

  delay(5000);
}
