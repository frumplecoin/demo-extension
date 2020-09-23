namespace music {

/**
* Turn the on-board speaker on or off.
* Disabling the speaker resets the analog pitch pin to the default of P0.
* @param enabled whether the on-board speaker is enabled in addition to the analog pitch PIN
*/
//% blockId=music_set_on_board_speaker_enable block="on-board speaker enable %enabled"
//% blockGap=8
//% group="Volume"
export function setOnBoardSpeakerEnable(enabled: boolean) {
  if (enabled) {
    // Clearing the pitch PIN will cause analogPitch to reinitialize
    // which will enable sound mirroring if disabled.
    pins.analogSetPitchPin(null);
  }
  else {
    // Setting the pitch PIN to a valid PIN has the side effect of clearing
    // the pitchPin2 used for the internal speaker.
    pins.analogSetPitchPin(AnalogPin.P0);
  }
}

}