/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//
//  This sample program plays a sequence of melodies every 5 seconds.
//  Connect the commPin to the PA3 port of the M8058 and the nextPin to the PA2 port
//  and run it.
//  This program behaves the same as "PlayMelody_2.ino".
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

  /* Init process */
  m8058.SetCommandPin(COMM_PIN);
  m8058.SetNextPin(NEXT_PIN);

  Serial.println("Initialization process completed!!");

  m8058.PlayMelody(MELODY_00);
  (void)m8058.ChangeVolume(NS_VOLUME_LEVEL_2);
  delay(5000);
}


void loop()
{
  /* If you have nextPin connected to the PA2 port, you can also use this method. */
  m8058.PlayNextHW();

  delay(5000);
}
