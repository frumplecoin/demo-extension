#include "pxt.h"

namespace input {

    //%
    void onLogoPressed(Action body) {
        registerWithDal(uBit.io.face.id, MICROBIT_BUTTON_EVT_CLICK, body);
    }

    //%
    void onLogoReleased(Action body) {
        registerWithDal(uBit.io.face.id, MICROBIT_BUTTON_EVT_UP, body);
    }

    //%
    bool logoIsPressed() {
        return uBit.io.face.isTouched();
    }

}
