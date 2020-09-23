#include "pxt.h"

enum class TouchTargetMode {
    //% block="resistive"
    Resistive = 0,
    //% block="capacitative"
    Capacitative = 1
};

// Maybe we can add to TouchPin when in pxt-microbit? Would need error handing elsewhere.
// TouchTargetMode -> TouchPinMode if we do that.
enum class TouchTarget {
    //% block="P0"
    P0 = MICROBIT_ID_IO_P0,
    //% block="P1"
    P1 = MICROBIT_ID_IO_P1,
    //% block="P2"
    P2 = MICROBIT_ID_IO_P2,
    //% block="logo"
    LOGO = 121 // Should be MICROBIT_ID_FACE after dal.d.ts update.
};

namespace pins {

//%
void touchSetMode(TouchTarget name, TouchTargetMode mode) {
    const auto pin = name == TouchTarget::LOGO ? &uBit.io.face : getPin((int)name);
    if (pin) {
        pin->isTouched(mode == TouchTargetMode::Capacitative ? TouchMode::Capacitative : TouchMode::Resistive);
    }
}

}
