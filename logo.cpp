#include "pxt.h"

namespace input {

    //%
    void onLogoPressed(Action body) {
        // Forces the PIN to switch to makey-makey style detection.
        uBit.io.face.isTouched();
        registerWithDal(uBit.io.face.id, MICROBIT_BUTTON_EVT_CLICK, body);
    }

    //%
    void onLogoReleased(Action body) {
        // Forces the PIN to switch to makey-makey style detection.
        uBit.io.face.isTouched();
        registerWithDal(uBit.io.face.id, MICROBIT_BUTTON_EVT_UP, body);
    }

    //%
    bool logoIsPressed() {
        return uBit.io.face.isTouched();
    }

}
