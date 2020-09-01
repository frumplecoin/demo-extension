namespace input {
    /**
     * Do something when the logo is touched and released again.
     * @param body the code to run when the logo is pressed
     */
    //% help=input/on-logo-pressed weight=83 blockGap=32
    //% blockId=input_logo_event block="on logo pressed"
    //% shim=input::onLogoPressed
    export function onLogoPressed(body: () => void): void {
        return // required for noop
    }

    /**
     * Do something when the logo is released.
     * @param body the code to run when the logo is released
     */
    //% help=input/on-logo-released weight=6 blockGap=16
    //% blockId=input_logo_released block="on logo released"
    //% advanced=true
    //% shim=input::onLogoReleased
    export function onLogoReleased(body: () => void): void {
        return // required for noop
    }

    /**
     * Get the logo state (pressed or not).
     */
    //% help=input/logo-is-pressed weight=58
    //% blockId="input_logo_is_pressed" block="logo is pressed"
    //% blockGap=8
    //% shim=input::logoIsPressed
    export function logoIsPressed(): boolean {
        return false
    }
}