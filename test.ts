input.onButtonPressed(Button.A, function () {
  basic.showNumber(input.soundLevel())
})
input.onLogoReleased(function () {
  basic.showIcon(IconNames.No)
})
input.onLogoPressed(function () {
  basic.showIcon(IconNames.Yes)
})
input.onSound(SoundType.Loud, function () {
  basic.showIcon(IconNames.Happy)
})
input.onButtonPressed(Button.B, function () {
  if (input.logoIsPressed()) {
      basic.showIcon(IconNames.Heart)
  } else {
      basic.showIcon(IconNames.SmallHeart)
  }
})
input.onSound(SoundType.Quiet, function () {
  basic.showIcon(IconNames.Sad)
})
input.setSoundThreshold(SoundType.Quiet, 30)
input.setSoundThreshold(SoundType.Loud, 171)
pins.touchSetMode(TouchTarget.P0, TouchTargetMode.Capacitative)
pins.touchSetMode(TouchTarget.LOGO, TouchTargetMode.Resistive)
