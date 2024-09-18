/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//
//  This sample program plays a sequence of melodies every 5 seconds.
//  Connect commPin to the PA3 port of M8058 and run it.
//  The values ​​that can be specified for the arguments of each method are listed
//  in M8058.h.
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

  /* 
    Sets the volume of the audio.
    If you specify the prefix "S_", the volume will be set with the currently playing melody stopped and replay.
    If you specify the prefix "NS_", the volume will be set with the melody continuing to play.
    
    The default is "S_VOLUME_LEVEL_2".
      1. S_VOLUME_LEVEL_1 : Minimum volume. 
               ...
      8. S_VOLUME_LEVEL_8 : Maximum volume.
  */
  (void)m8058.ChangeVolume(S_VOLUME_LEVEL_2);

  Serial.println("Initialization process completed!!");
  delay(5000);
}


void loop()
{
  for(int playLoop = LOWER_THRESHOLD_MELODY; playLoop < UPPER_THRESHOLD_MELODY; playLoop++)
  {
    m8058.PlayMelody(playLoop);

    Serial.print("The number of the melody being played:");
    Serial.println(playLoop);
    delay(5000);
  }
}
