
# ArduinoJoyGame
Aka arduino joystick game. It's a simple game with a joystick and LCD display(I2C)

## How To Play/Game working
- This game is like cookie clicker without the cookie and other features
- Press the joystick button to start
- Try to click as many times as you can in 15sec
- Dont move the joystick to the side, if you do, game over!

## Setup
- Connect components accourding to the pinout diagram
- Upload the Arduino sketch
- Maybe adjust LCD contrast?
- When uploading, remove the wire on pin D12(connects to the reset pin) as it seems to prevent uploading the sketch. Reconnect it back(or don't if there is a problem)
-If you are having problems when D12 and reset pins are connect, remove the wire and reset manually(reset button) after the game is over

![pinout](https://user-images.githubusercontent.com/85803570/229263366-eb85c0a2-4b5e-476c-a1fc-e14eb17b2284.png)
Created with Fritzing
