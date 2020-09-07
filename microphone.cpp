#include "pxt.h"
#include "LevelDetector.h"
#include "LevelDetectorSPL.h"

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
    codal::LevelDetectorSPL* getMicrophoneLevel();
}

namespace input {
//%
void onSound(SoundType sound, Action handler) {
    pxt::getMicrophoneLevel(); // wake up service
    const auto thresholdType = sound == SoundType::Loud ? LEVEL_THRESHOLD_HIGH : LEVEL_THRESHOLD_LOW;
    registerWithDal(DEVICE_ID_MICROPHONE, thresholdType, handler);
}

//%
int soundLevel() {
    auto level = pxt::getMicrophoneLevel();
    if (NULL == level)
        return 0;
    const int micValue = level->getValue();
    const int scaled = max(MICROPHONE_MIN, min(micValue, MICROPHONE_MAX)) - MICROPHONE_MIN;
    return min(0xff, scaled * 0xff / (MICROPHONE_MAX - MICROPHONE_MIN));
}

//%
void setSoundThreshold(SoundType sound, int threshold) {
    auto level = pxt::getMicrophoneLevel();
    if (NULL == level)
        return;

    threshold = max(0, min(0xff, threshold));
    const int scaled = MICROPHONE_MIN + threshold * (MICROPHONE_MAX - MICROPHONE_MIN) / 0xff;
    if (sound == SoundType::Loud)
        level->setHighThreshold(scaled);
    else
        level->setLowThreshold(scaled);
}
}
