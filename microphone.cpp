#include "pxt.h"

#if MICROBIT_CODAL
#include "LevelDetector.h"
#include "LevelDetectorSPL.h"
#endif

#define MICROPHONE_MIN 52.0f
#define MICROPHONE_MAX 120.0f

// Split enums?
enum class SoundType {
    //% block="loud"
    Loud = 0,
    //% block="quiet"
    Quiet = 1
};

namespace pxt {
#if MICROBIT_CODAL
    codal::LevelDetectorSPL* getMicrophoneLevel();
#endif
}

namespace input {
//%
void onSound(SoundType sound, Action handler) {
#if MICROBIT_CODAL
    pxt::getMicrophoneLevel(); // wake up service
    const auto thresholdType = sound == SoundType::Loud ? LEVEL_THRESHOLD_HIGH : LEVEL_THRESHOLD_LOW;
    registerWithDal(DEVICE_ID_MICROPHONE, thresholdType, handler);
#else
    target_panic(PANIC_VARIANT_NOT_SUPPORTED);
#endif
}

//%
int soundLevel() {
#if MICROBIT_CODAL
    auto level = pxt::getMicrophoneLevel();
    if (NULL == level)
        return 0;
    const int micValue = level->getValue();
    const int scaled = max(MICROPHONE_MIN, min(micValue, MICROPHONE_MAX)) - MICROPHONE_MIN;
    return min(0xff, scaled * 0xff / (MICROPHONE_MAX - MICROPHONE_MIN));
#else
    target_panic(PANIC_VARIANT_NOT_SUPPORTED);
    return 0;
#endif
}

//%
void setSoundThreshold(SoundType sound, int threshold) {
#if MICROBIT_CODAL
    auto level = pxt::getMicrophoneLevel();
    if (NULL == level)
        return;

    threshold = max(0, min(0xff, threshold));
    const int scaled = MICROPHONE_MIN + threshold * (MICROPHONE_MAX - MICROPHONE_MIN) / 0xff;
    if (sound == SoundType::Loud)
        level->setHighThreshold(scaled);
    else
        level->setLowThreshold(scaled);
#else
    target_panic(PANIC_VARIANT_NOT_SUPPORTED);
#endif
}
}
