namespace input {
    /**
    * Registers an event that runs when a sound is detected
    */
    //% help=input/on-sound
    //% blockId=input_on_sound block="on %sound sound"
    //% parts="microphone"
    //% weight=88 blockGap=12
    //% shim=input::onSound
    export function onSound(sound: SoundType, handler: () => void) {
        return // required for noop
    }

    /**
    * Reads the loudness through the microphone from 0 (silent) to 255 (loud)
    */
    //% help=input/sound-level
    //% blockId=device_get_sound_level block="sound level"
    //% parts="microphone"
    //% weight=34 blockGap=8
    //% shim=input::soundLevel
    export function soundLevel(): number {
        return 0
    }

    /**
    * Sets the threshold for a sound type.
    */
    //% help=input/set-sound-threshold
    //% blockId=input_set_sound_threshold block="set %sound sound threshold to %value"
    //% parts="microphone"
    //% threshold.min=0 threshold.max=255 threshold.defl=128
    //% weight=14 blockGap=8
    //% advanced=true
    //% shim=input::setSoundThreshold
    export function setSoundThreshold(sound: SoundType, threshold: number) {
        return // required for noop
    }
}