/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//
//  This sample program outputs information about an instance.
//  Connect the commPin to the PA3 port of the M8058.
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

  /* Init process */
  m8058.SetAllPins(COMM_PIN, NEXT_PIN);

  Serial.println("Initialization process completed!!");

  m8058.PlayMelody(MELODY_00);
  (void)m8058.ChangeVolume(NS_VOLUME_LEVEL_2);
  
  /* 
    Each piece of information set on the instance is output serially.
    If you want to get the information individually, please execute the following method.
      1. int GetCommandPin(void)
      2. int GetNextPin(void)
      3. int GetOperationMode(void)
      4. int GetVolume(void)
      5. int GetPlayingMelody(void)
  */
  m8058.ShowInformation();
}


void loop()
{
  delay(1000);
}
