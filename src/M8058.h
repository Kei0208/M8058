/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Header name
//            M8058.h
//(2)Note
//            This library supports M8058E, M8058S, and M8026S.
//            Change the value of "IC_USED" depending on the IC you are using.
//(3)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
#ifndef M8058_H
#define M8058_H


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//
//	Include
//
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
#include <Arduino.h>


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//
//	Definition
//
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
// IC used
#define M8058E  (8058)
#define M8058S  (8058)
#define M8026S  (8026)
#define IC_USED (M8058E)

// Melody command
#define MELODY_00 (0x00)
#define MELODY_01 (0x01)
#define MELODY_02 (0x02)
#define MELODY_03 (0x03)
#define MELODY_04 (0x04)
#define MELODY_05 (0x05)
#define MELODY_06 (0x06)
#define MELODY_07 (0x07)
#define MELODY_08 (0x08)
#define MELODY_09 (0x09)
#define MELODY_10 (0x0A)
#define MELODY_11 (0x0B)
#define MELODY_12 (0x0C)
#define MELODY_13 (0x0D)
#define MELODY_14 (0x0E)
#define MELODY_15 (0x0F)
#define MELODY_16 (0x10)
#define MELODY_17 (0x11)
#define MELODY_18 (0x12)
#define MELODY_19 (0x13)
#define MELODY_20 (0x14)
#define MELODY_21 (0x15)
#define MELODY_22 (0x16)
#define MELODY_23 (0x17)
#define MELODY_24 (0x18)
#define MELODY_25 (0x19)

#if (IC_USED == M8026S)
#else
#define MELODY_26 (0x1A)
#define MELODY_27 (0x1B)
#define MELODY_28 (0x1C)
#define MELODY_29 (0x1D)
#define MELODY_30 (0x1E)
#define MELODY_31 (0x1F)
#define MELODY_32 (0x20)
#define MELODY_33 (0x21)
#define MELODY_34 (0x22)
#define MELODY_35 (0x23)
#define MELODY_36 (0x24)
#define MELODY_37 (0x25)
#define MELODY_38 (0x26)
#define MELODY_39 (0x27)
#define MELODY_40 (0x28)
#define MELODY_41 (0x29)
#define MELODY_42 (0x2A)
#define MELODY_43 (0x2B)
#define MELODY_44 (0x2C)
#define MELODY_45 (0x2D)
#define MELODY_46 (0x2E)
#define MELODY_47 (0x2F)
#define MELODY_48 (0x30)
#define MELODY_49 (0x31)
#define MELODY_50 (0x32)
#define MELODY_51 (0x33)
#define MELODY_52 (0x34)
#define MELODY_53 (0x35)
#define MELODY_54 (0x36)
#define MELODY_55 (0x37)
#define MELODY_56 (0x38)
#define MELODY_57 (0x39)
#endif

#define LOWER_THRESHOLD_MELODY (MELODY_00)

#if (IC_USED == M8026S)
#define UPPER_THRESHOLD_MELODY (MELODY_25)
#else
#define UPPER_THRESHOLD_MELODY (MELODY_57)
#endif

// Don't Stop melody and volume adjustment command
#define NS_VOLUME_LEVEL_1 (0xE0) 
#define NS_VOLUME_LEVEL_2 (0xE1) 
#define NS_VOLUME_LEVEL_3 (0xE2) 
#define NS_VOLUME_LEVEL_4 (0xE3) 
#define NS_VOLUME_LEVEL_5 (0xE4) 
#define NS_VOLUME_LEVEL_6 (0xE5) 
#define NS_VOLUME_LEVEL_7 (0xE6) 
#define NS_VOLUME_LEVEL_8 (0xE7) 

// Replay melody and volume adjustment command
#define S_VOLUME_LEVEL_1 (0xF0) 
#define S_VOLUME_LEVEL_2 (0xF1) 
#define S_VOLUME_LEVEL_3 (0xF2) 
#define S_VOLUME_LEVEL_4 (0xF3) 
#define S_VOLUME_LEVEL_5 (0xF4) 
#define S_VOLUME_LEVEL_6 (0xF5) 
#define S_VOLUME_LEVEL_7 (0xF6) 
#define S_VOLUME_LEVEL_8 (0xF7) 

// Mode command
#define MELODY_LED_MODE  (0xF8)
#define MELODY_ONLY_MODE (0xF9)
#define LED_ONLY_MODE    (0xFA)

// Operation command
#define PLAY_MELODY          (0xFB)
#define PLAY_NEXT_MELODY     (0xFC)
#define PLAY_PREVIOUS_MELODY (0xFD)
#define VOLUME_INCREMENT     (0xFE)
#define PAUSE_MELODY         (0xFF)

// Threshold command
#define LOWER_THRESHOLD_COMMAND (MELODY_00)
#define UPPER_THRESHOLD_COMMAND (PAUSE_MELODY)

// Return value
#define PROCESSING_OK       (0)
#define E_INVALID_VALUE_SET (-1)
#define E_INVALID_MELODY    (-2)
#define E_INVALID_VOLUME    (-3)
#define E_INVALID_MODE      (-4)
#define E_ABNORMAL_COMMAND  (-5)
#define E_SERIAL_INVALID    (-6)

// Initial Value
#define INVALID_VALUE (-1)

// Default pins
#define DEFAULT_COMM_PIN (12)
#define DEFAULT_NEXT_PIN (14)

// Pin type
#define COMMAND_PIN_CONFIG (0x00)
#define NEXT_PIN_CONFIG    (0x01)

// Signal retention time
#define HEADER_TIME_ms (6)
#define SHORT_TIME_us  (500)
#define LONG_TIME_us   (1500)

// HW control delay time
#define NEXT_DELAY_HW_ms (100)

// Show message
#define SHOW_MESSAGE_1 ("Command Pin:")
#define SHOW_MESSAGE_2 ("Next Pin:")
#define SHOW_MESSAGE_3 ("Operation mode:")
#define SHOW_MESSAGE_4 ("Melody Volume:")
#define SHOW_MESSAGE_5 ("Playing Melody:")


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//
//	Struct
//
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//
//	Enum
//
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//
//	Class
//
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
class M8058
{
	public:
		/* Constructor */
		M8058();
		M8058(int);
		M8058(int, int);
		
		/* Destructor */
		~M8058();
		
		/* Setter method */
		void SetCommandPin(int);
		void SetNextPin(int);
		void SetAllPins(int, int);

		/* Getter method */
		int GetCommandPin(void);
		int GetNextPin(void);
		int GetOperationMode(void);
		int GetVolume(void);
		int GetPlayingMelody(void);
		
		/* Melody play method */
		int PlayNextHW(void);
		void PlayNext(void);
		void PlayPrevious(void);
		int PlayMelody(int);
		void PauseMelody(void);
		void ReplayMelody(void);
		
		/* Volume adjustment method */
		void IncrementVolume(void);
		int ChangeVolume(int);

		/* Change operation mode method */
		int ChangeOperationMode(int);
		
		/* Show information method */
		int ShowInformation(void);
	
	private:
		/* Used pin number */
		int commPin;
		int nextPin;

		/* Setting value */
		int mode;
		int volume;
		int melody;
		
		/* GPIO valid method */
		void ValidPinConfig(int);

		/* Command send method */
		int SendCommand(int);
};

#endif