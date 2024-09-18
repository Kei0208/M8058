/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Source file name
//            M8058.cpp
//(2)Note
//            This library supports M8058E, M8058S, and M8026S.
//(3)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

#include "M8058.h"


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            M8058 [Public]
//(2)Process
//            Setting initial values
//(3)Argument
//            none
//(4)Return
//            none
//(5)Note
//            Constructor
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
	
	M8058::M8058()
	{
		SetAllPins(DEFAULT_COMM_PIN, DEFAULT_NEXT_PIN);

		this->mode = MELODY_LED_MODE;
		this->volume = NS_VOLUME_LEVEL_4 & 0x07;
		this->melody = MELODY_00;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            M8058 [Public]
//(2)Process
//            Set commPin at the same time.
//(3)Argument
//            c_Pin		Pin number that sends command to M8058 ic.
//(4)Return
//            none
//(5)Note
//            Constructor
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
	
	M8058::M8058(int c_Pin)
	{
		SetAllPins(c_Pin, DEFAULT_NEXT_PIN);

		this->mode = MELODY_LED_MODE;
		this->volume = NS_VOLUME_LEVEL_4 & 0x07;
		this->melody = MELODY_00;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            M8058 [Public]
//(2)Process
//            Set commPin and nextPin at the same time.
//(3)Argument
//            c_Pin		Pin number that sends command to M8058 ic.
//            n_Pin		Pin number that plays next melody when detected rising edge.
//(4)Return
//            none
//(5)Note
//            Constructor
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
	
	M8058::M8058(int c_Pin, int n_Pin)
	{
		SetAllPins(c_Pin, n_Pin);

		this->mode = MELODY_LED_MODE;
		this->volume = NS_VOLUME_LEVEL_4 & 0x07;
		this->melody = MELODY_00;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            M8058 [Public]
//(2)Process
//            none
//(3)Argument
//            none
//(4)Return
//            none
//(5)Note
//            Destructor
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	M8058::~M8058()
	{
		/* do nothing */
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            SetCommandPin [Public]
//(2)Process
//            Set commPin.
//(3)Argument
//            c_Pin		Pin number that sends command to M8058 ic.
//(4)Return
//            none
//(5)Note
//            Setter method
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	void M8058::SetCommandPin(int c_Pin)
	{
		(this->commPin) = c_Pin;
		ValidPinConfig(COMMAND_PIN_CONFIG);

		return;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            SetNextPin [Public]
//(2)Process
//            Set nextPin.
//(3)Argument
//            n_Pin		Pin number that plays next melody when detected rising edge.
//(4)Return
//            none
//(5)Note
//            Setter method
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	void M8058::SetNextPin(int n_Pin)
	{
		(this->nextPin) = n_Pin;
		ValidPinConfig(NEXT_PIN_CONFIG);

		return;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            SetAllPins [Public]
//(2)Process
//            Set commPin and nextPin at the same time.
//(3)Argument
//            c_Pin		Pin number that sends command to M8058 ic.
//            n_Pin		Pin number that plays next melody when detected rising edge.
//(4)Return
//            none
//(5)Note
//            Setter method
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	void M8058::SetAllPins(int c_Pin, int n_Pin)
	{
		SetCommandPin(c_Pin);
		SetNextPin(n_Pin);
		
		return;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            GetCommandPin [Public]
//(2)Process
//            Returns the number of commPin.
//(3)Argument
//            none
//(4)Return
//            Result of operation.
//            pinNumber				Pin number.
//            E_INVALID_VALUE_SET	Returned when the commPin is set to invalid value.
//(5)Note
//            Getter method
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	int M8058::GetCommandPin()
	{
		int pinNumber;

		if(this->commPin <= INVALID_VALUE)
		{
			pinNumber = E_INVALID_VALUE_SET;
		}
		else
		{
			pinNumber = this->commPin;
		}

		return pinNumber;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            GetNextPin [Public]
//(2)Process
//            Returns the number of nextPin.
//(3)Argument
//            none
//(4)Return
//            Result of operation.
//            pinNumber				Pin number.
//            E_INVALID_VALUE_SET	Returned when the nextPin is set to invalid value.
//(5)Note
//            Getter method
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	int M8058::GetNextPin()
	{
		int pinNumber;

		if(this->nextPin <= INVALID_VALUE)
		{
			pinNumber = E_INVALID_VALUE_SET;
		}
		else
		{
			pinNumber = this->nextPin;
		}

		return pinNumber;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            GetOperationMode [Public]
//(2)Process
//            Returns the operation mode.
//(3)Argument
//            none
//(4)Return
//            Result of operation.
//            stayMode				Mode of operation during stay.
//            E_INVALID_VALUE_SET	Returned when the mode is set to invalid value.
//(5)Note
//            Getter method
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	int M8058::GetOperationMode()
	{
		int stayMode;

		if(this->mode >= MELODY_LED_MODE && LED_ONLY_MODE >= this->mode)
		{
			stayMode = this->mode;
		}
		else
		{
			stayMode = E_INVALID_VALUE_SET;
		}

		return stayMode;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            GetVolume [Public]
//(2)Process
//            Returns the volume.
//(3)Argument
//            none
//(4)Return
//            Result of operation.
//            confVolume			Configured volume.
//            E_INVALID_VALUE_SET	Returned when the volume is set to invalid value.
//(5)Note
//            Getter method
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	int M8058::GetVolume()
	{
		int confVolume;

		if(this->volume >= 0x00 && this->volume <= 0x07)
		{
			confVolume = this->volume + 0x01;
		}
		else
		{
			confVolume = E_INVALID_VALUE_SET;
		}

		return confVolume;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            GetPlayingMelody [Public]
//(2)Process
//            Returns the melody.
//(3)Argument
//            none
//(4)Return
//            Result of operation.
//            playMelody			Playing melody number.
//            E_INVALID_VALUE_SET	Returned when the melody is set to invalid value.
//(5)Note
//            Getter method
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	int M8058::GetPlayingMelody()
	{
		int playMelody;

		if(this->melody >= LOWER_THRESHOLD_MELODY && UPPER_THRESHOLD_MELODY >= this->melody)
		{
			playMelody = this->melody;
		}
		else
		{
			playMelody = E_INVALID_VALUE_SET;
		}

		return playMelody;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            PlayNextHW [Public]
//(2)Process
//            Play the next melody.
//(3)Argument
//            none
//(4)Return
//            Result of operation.
//            PROCESSING_OK			Returned when processing ends normally.
//            E_INVALID_VALUE_SET	Returned when the nextPin is set to invalid value.
//(5)Note
//            If the PA2 port of M8058 and nextPin are connected, you can fiber to the
//			  next melody with this method.
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	int M8058::PlayNextHW()
	{
		int retValue;

		if(this->nextPin <= INVALID_VALUE)
		{
			retValue = E_INVALID_VALUE_SET;
		}
		else
		{
			// Check nextPin state
			if(digitalRead(this->nextPin) != LOW)
			{
				digitalWrite(this->nextPin, LOW);
			}
			else
			{
				/* do nothing */
			}

			digitalWrite(this->nextPin, HIGH);
			delay(NEXT_DELAY_HW_ms);
			digitalWrite(this->nextPin, LOW);

			if(this->melody >= UPPER_THRESHOLD_MELODY)
			{
				this->melody = LOWER_THRESHOLD_MELODY;
			}
			else
			{
				this->melody = (this->melody + 0x01) & 0xFF;
			}

			retValue = PROCESSING_OK;
		}

		return retValue;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            PlayNext [Public]
//(2)Process
//            Play the next melody.
//(3)Argument
//            none
//(4)Return
//            none
//(5)Note
//            
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	void M8058::PlayNext()
	{
		(void)SendCommand(PLAY_NEXT_MELODY);

		if(this->melody >= UPPER_THRESHOLD_MELODY)
		{
			this->melody = LOWER_THRESHOLD_MELODY;
		}
		else
		{
			this->melody = (this->melody + 0x01) & 0xFF;
		}

		return;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            PlayPrevious [Public]
//(2)Process
//            Play the previous melody.
//(3)Argument
//            none
//(4)Return
//            none
//(5)Note
//            
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	void M8058::PlayPrevious()
	{
		(void)SendCommand(PLAY_PREVIOUS_MELODY);

		if(this->melody <= LOWER_THRESHOLD_MELODY)
		{
			this->melody = UPPER_THRESHOLD_MELODY;
		}
		else
		{
			this->melody = (this->melody - 0x01) & 0xFF;
		}

		return;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            PlayMelody [Public]
//(2)Process
//            Play the specified melody.
//(3)Argument
//            melody	Melody you want to play.
//(4)Return
//            Result of operation.
//            PROCESSING_OK			Returned when processing ends normally.
//            E_INVALID_MELODY		Returned when you specified an invalid melody.
//            E_ABNORMAL_COMMAND	Returned when the specified an abnormal command.
//(5)Note
//            
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	int M8058::PlayMelody(int melody)
	{
		int retValue;

		if(melody >= LOWER_THRESHOLD_MELODY && UPPER_THRESHOLD_MELODY >= melody)
		{
			retValue = SendCommand(melody);

			if(retValue == PROCESSING_OK)
			{
				this->melody = melody & 0xFF;
			}
			else
			{
				/* do nothing */
			}
		}
		else
		{
			retValue = E_INVALID_MELODY;
		}
		
		return retValue;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            PauseMelody [Public]
//(2)Process
//            Pauses the playing melody.
//(3)Argument
//            none
//(4)Return
//            none
//(5)Note
//            
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	void M8058::PauseMelody()
	{
		(void)SendCommand(PAUSE_MELODY);

		return;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            ReplayMelody [Public]
//(2)Process
//            Resumes a paused melody.
//(3)Argument
//            none
//(4)Return
//            none
//(5)Note
//            
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	void M8058::ReplayMelody()
	{
		(void)SendCommand(PLAY_MELODY);

		return;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            IncrementVolume [Public]
//(2)Process
//            Increment volume level.
//(3)Argument
//            none
//(4)Return
//            none
//(5)Note
//            
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	void M8058::IncrementVolume()
	{
		(void)SendCommand(VOLUME_INCREMENT);

		if(this->volume >= 0x07)
		{
			this->volume = 0x00;
		}
		else
		{
			this->volume += 0x01;
		}

		return;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            ChangeVolume [Public]
//(2)Process
//            Change volume level.
//(3)Argument
//            volume	Volume you want to set.
//(4)Return
//            Result of operation.
//            PROCESSING_OK			Returned when processing ends normally.
//            E_INVALID_VOLUME		Returned when you specified an invalid volume level.
//            E_ABNORMAL_COMMAND	Returned when the specified an abnormal command.
//(5)Note
//            
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	int M8058::ChangeVolume(int volume)
	{
		int retValue;

		if(((volume & 0xE0) == 0xE0) && ((volume & 0x0F) <= 0x07))
		{
			retValue = SendCommand(volume);
			this->volume = volume & 0x07;
		}
		else
		{
			retValue = E_INVALID_VOLUME;
		}		

		return retValue;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            ChangeOperationMode [Public]
//(2)Process
//            Change the IC operating mode.
//(3)Argument
//            mode	Operation mode you want to set.
//(4)Return
//            Result of operation.
//            PROCESSING_OK			Returned when processing ends normally.
//            E_INVALID_MODE		Returned when you specified an invalid mode.
//            E_ABNORMAL_COMMAND	Returned when the specified an abnormal command.
//(5)Note
//            
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	int M8058::ChangeOperationMode(int mode)
	{
		int retValue;

		if(mode >= MELODY_LED_MODE && LED_ONLY_MODE >= mode)
		{
			retValue = SendCommand(mode);
			this->mode = mode & 0xFF;
		}
		else
		{
			retValue = E_INVALID_MODE;
		}		

		return retValue;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            ShowInformation [Public]
//(2)Process
//            Show the information set for the instance.
//(3)Argument
//            none
//(4)Return
//            Result of operation.
//            PROCESSING_OK		Returned when processing ends normally.
//            E_SERIAL_INVALID	Returned when serial communication is invalid.
//(5)Note
//            Enable serial communication before calling this method.
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	int M8058::ShowInformation()
	{
		int retValue = PROCESSING_OK;
		
		if(!Serial)
		{
			retValue = E_SERIAL_INVALID;
		}
		else
		{
			// Show information
			Serial.print(SHOW_MESSAGE_1);
			Serial.print("\t");
			Serial.println(GetCommandPin());

			Serial.print(SHOW_MESSAGE_2);
			Serial.print("\t");
			Serial.println(GetNextPin());

			Serial.print(SHOW_MESSAGE_3);
			Serial.println(GetOperationMode());

			Serial.print(SHOW_MESSAGE_4);
			Serial.println(GetVolume());

			Serial.print(SHOW_MESSAGE_5);
			Serial.println(GetPlayingMelody());
		}
		
		return retValue;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            ValidPinConfig [Private]
//(2)Process
//            Set commPin and nextPin at the same time.
//(3)Argument
//            none
//(4)Return
//            none
//(5)Note
//            
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	void M8058::ValidPinConfig(int pinType)
	{
		switch(pinType)
		{
			case COMMAND_PIN_CONFIG:
				if(this->commPin <= INVALID_VALUE)
				{
					/* do nothing */
				}
				else
				{
					pinMode(this->commPin, OUTPUT);
					digitalWrite(this->commPin, LOW);
				}

				break;
			
			case NEXT_PIN_CONFIG:
				if(this->nextPin <= INVALID_VALUE)
				{
					/* do nothing */
				}
				else
				{
					pinMode(this->nextPin, OUTPUT);
					digitalWrite(this->nextPin, LOW);
				}

				break;

			default:
				/* do nothing */
				break;
		}
		
		return;
	}


/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/
//(1)Function name
//            SendCommand [Private]
//(2)Process
//            Send command to M8058 ic.
//(3)Argument
//            command	Command you want to send.
//(4)Return
//            Result of operation.
//            PROCESSING_OK			Returned when processing ends normally.
//            E_ABNORMAL_COMMAND	Returned when the specified an abnormal command.
//(5)Note
//            
//(6)History
//            Rev.0   2024/09/18   Keisuke Hamada
/*_(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)__(:3｣∠)_*/

	int M8058::SendCommand(int command)
	{
		int retValue = PROCESSING_OK;

		int sendBit;
		int firstTime, secondTime;

		if(LOWER_THRESHOLD_COMMAND > command || command > UPPER_THRESHOLD_COMMAND)
		{
			retValue = E_ABNORMAL_COMMAND;
		}
		else
		{
			// Check commPin state
			if(digitalRead(this->commPin) != LOW)
			{
				digitalWrite(this->commPin, LOW);
			}
			else
			{
				/* do nothing */
			}

			// send header signal
			digitalWrite(this->commPin, HIGH);
			delay(HEADER_TIME_ms);
			digitalWrite(this->commPin, LOW);

			// Send data signal
			for(int sendLoop = 0; sendLoop < 8; sendLoop++)
			{
				sendBit = (command >> sendLoop) & 0x01;

				if(sendBit == 0x01)
				{
					firstTime = SHORT_TIME_us;
					secondTime = LONG_TIME_us;
				}
				else
				{
					firstTime = LONG_TIME_us;
					secondTime = SHORT_TIME_us;
				}

				delayMicroseconds(firstTime);
				digitalWrite(this->commPin, HIGH);
				delayMicroseconds(secondTime);
				digitalWrite(this->commPin, LOW);
			}
		}

		return retValue;
	}
