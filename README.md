# Developer guide
### Steps:
* To upload firmware to your Arduino you have to install [Arduino IDE](https://www.arduino.cc/en/Main/Software). Also if your Arduino board is not original one but is a "replica", you should install additional driver for communicating with PC from the vendor of the board.
Usually the chip is CH340. Its driver can be found [here](https://sparks.gogo.co.nz/ch340.html). It doesn't require special settings.
* Next step is setting up you IDE. 
To do this go to **Tools > Board** to select your board (we use Arduino Nano). Go to **Tools > Processor** to select processor of your board. 
Sometimes there can be options with "Old Bootloader": if there are any errors try to choose this one (it means that your device has old version of software updater). 
* Mainly there are no COM ports in system so if you correctly install driver for your Arduino board (for original drivers are installed with Arduino IDE) you can see here something like COM3 (number can be other). Select this option and press Upload (or Ctrl + U) to upload your sketch to board.


### Arduino connection specification
| Joystick button           | Arduino Pin |
|---------------------------|------------ |
| Left Trigger              | D2          |
| Right Trigger             | D3          |
| X button                  | D4          |
| A button                  | D5          |
| B nutton                  | D6          |
| Y button                  | D7          |
| L function button         | D8          |
| R function button         | D9          |
| L joystick button         | D10         |
| R joystick button         | D11         |
| Left joystick vertical    | A0          |
| Left joystick horizontal  | A1          |
| Right joystick vertical   | A2          |
| Right joystick horizontal | A3          |

### Shield pinout
![Hello World](https://github.com/renair/GamepadFirmware/blob/master/shield_pinout.jpg?raw=true)

| Purpose            | Pin |
|--------------------|-----|
| GND                | 1   |
| Vin                | 2   |
| Left trigger       | 3   |
| Left function key  | 4   |
| Right function key | 5   |
| Right trigger      | 6   |
| X button           | 7   |
| Y button           | 8   |
| B button           | 9   |
| A button           | 10  |
