#include "pxt.h"

namespace input {

    //%
    void onLogoPressed(Action body) {
#if MICROBIT_CODAL
        registerWithDal(uBit.logo.id, MICROBIT_BUTTON_EVT_CLICK, body);
#else
        target_panic(PANIC_VARIANT_NOT_SUPPORTED);
#endif
    }

    //%
    void onLogoReleased(Action body) {
#if MICROBIT_CODAL
        registerWithDal(uBit.logo.id, MICROBIT_BUTTON_EVT_UP, body);
#else
        target_panic(PANIC_VARIANT_NOT_SUPPORTED);
#endif
    }

    //%
    bool logoIsPressed() {
#if MICROBIT_CODAL
        return uBit.io.logo.isTouched();
#else
        target_panic(PANIC_VARIANT_NOT_SUPPORTED);
        return false;
#endif
    }

}
