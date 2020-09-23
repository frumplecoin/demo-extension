namespace pins {

   /**
    * Configure the touch detection for the pins and logo.
    * P0, P1, P2 use resistive touch by default.
    * The logo uses capacitative touch by default.
    * @param name target to change the touch mode for, eg: TouchTarget.P0
    * @param mode the touch mode to use, eg: TouchTargetMode.Capacitative
    */
    //% help=pins/touch-set-mode weight=60
    //% blockId=device_touch_set_type block="set %name to touch mode %mode"
    //% shim=pins::touchSetMode
    export function touchSetMode(name: TouchTarget, mode: TouchTargetMode): void {
        return // required for noop
    }

}