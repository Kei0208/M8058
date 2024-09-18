/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//
//  This sample program plays a sequence of melodies every 5 seconds.
//  Connect commPin to the PA3 port of M8058 and run it.
//  TAfter playing the last melody, it will loop back to the first melody.
//  This program behaves the same as "PlayMelody_1.ino".
//
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

#include <M8058.h>

/* Control pins */
#define COMM_PIN (12)


M8058 m8058;


void setup()
{
  Serial.begin(115200);

  /* Init process */
  m8058.SetCommandPin(COMM_PIN);

  Serial.println("Initialization process completed!!");

  m8058.PlayMelody(MELODY_00);
  (void)m8058.ChangeVolume(NS_VOLUME_LEVEL_2);
  delay(5000);
}


void loop()
{
  /* Plays melodies in ascending order. */
  m8058.PlayNext();

  /* Plays melodies in descending order. */
  // m8058.PlayPrevious();

  delay(5000);
}
