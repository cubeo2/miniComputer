# miniComputer

## Author

Blair C. Tate aka cubeo

## Overview

This project aims to create a mini-computer system capable of doing small tasks and playing small scripted games. The project is broken into multiple microcontrollers, the main controller (mainCPU) which gets data from SD memory storage, and monitors remoteController inputs, and peripheral microcontroller devices such as audio and visual. 

This project is currently in an integration/prototyping state for version 0.1, so functions from various translation units are being reworked to ensure smooth functionality. Documentation is also in progress, as I have not had time to draw out the proper electrical schematics and get exact counts on all electronic components/Lego pieces utilized.

This project was an opportunity to learn firmware/hardware development, as well as to learn C and C++. 

**Links to Videos**
The following videos showcase the various features that are currently working for this project

-

---

## Prerequisites

In order to run this project, you will need to either create the physical architecture as described in this project, or utilize electronic/Arduino simulation software like Wokwi or CRUMB. If you decide to build the physical device, it is recommended to use the PlatformIO framework (as i did), which is easily found in Visual Studio Code (or something similar). 

Check Electronics Folder for datasheets on component information.

**Tools**
- Safety glasses
- Electrically insulated gloves
- Multimeter
- Dupont Crimper
- Terminal Crimper
- Terminal Screwdrivers 
- Soldering Iron (w/ flux, and solder)

**Electronic Components**
- Arduino Uno x1
- Arduino Nano (quantity being determined, currently one)
- 300 Blue LED (2.7 Vf)

***Resistors***
1/4W, ideally 1/2W for power controll module on LED Screen
- 220Ω
- 10Ω
- 100Ω
- 2.2kΩ
- 4.7kΩ
- 10kΩ
- 22kΩ

***Transistors***
- BC547 x15
- ULN-2804 x3

***Capacitors***
- Electrolytic Cap, 16V, 10uF, 105c (min x2)
- Ceramic cap, 50V, 0.1uF, 104c

***IC***
- Shift Register, 74HC595N x5
- Active high decoder -> for future work

***Buttons***
- momentary push buttons x7

***LCD Screen***
- 16x2 LCD Screen DS160SA x1

**Misc**
- Zip Ties
- SD card formatted to FAT16/FAT32

## Installation & Setup

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/cubeo2/miniComputer
    cd <your-project-directory>
    ```

2.  **Install Libraries:**
    - Arduino.h
    - SD.h
    - SPI.h
    - Wire.h

3.  **Set up environment variables:**
    - In the config file, setup the pins of your arduino based on how you desire. Note, all peripheral arduinos (slaves) must have the CS pin set to 10 otherwise the SPI transfer protocol will not work as that pin monitors for LOW in order to know that data is being shifted into its shift-register.

    **Important:** Add `.gitignore` file to prevent committing sensitive credentials/data.

4. **Setup Compilation and upload**
    - Go to platformio.ini file and update the environment(s) to match you mainCPU and peripheral device setup.
    - Ensure that the appropriate translation units are being compiled within those environments.
    - Via command line, determine what ports your arduino's are connected to, and set them up as you upload/monitor ports for that environment. search using ls /dev/tty.* in command line
    - See Example below
    [env:main_cpu]
    platform = atmelavr
    board = uno
    framework = arduino
    build_src_filter = +<Devices/MainCPU.cpp> +<Main/**>  +<Memory/**> +<Communication/**> +<Remote/**>  +<Utils/**>
    monitor_speed = 9600
    monitor_port = /dev/tty.usbmodem31301
    upload_port = /dev/tty.usbmodem31301
    platform_packages = framework-arduino-avr
    lib_deps = arduino-libraries/LiquidCrystal@^1.0.7

5.  **Run the application:**
    - When project is fully compiled and uploaded on arduinos, running the software is as simple as turning on the power to the devices.
    - Currently the project is not integrated enough for this to be so.

5. **Testing**
    - Currently testing is turned on and off by setting SERIAL_LOG in Config.h file to 1, this will compile all serial log functions and allow for monitoring on the serial monitor. 
    - Need to setup Unit Testing in the future, and debug functions for the LCD display
---

## Dependencies

### Production Dependencies

- FrameworkArduino
- lib0c5
- libed2

### Development Tools

Plugins
- PlatformIO 
- Wokwi Simulator

---

## Current Features
- **Remote Controler**
    - Input Command via button press
- **Memory**
    - Get 512B of data from SD card
    - Transfer byte between Arduinos
- **Displays**
    - Display a 40B image on screen
    - Display data on LCD Screen

## Features in Development
- **Controls**
    - Main Menu Navigation
    - Option Selection
- **Integration**
    - Transfer of data packets from one arduino's buffer to another
    - Command loop for monitoring user input and outputting to the appropriate device/function.
    - Interpretation of memory for use by appropriate device
- **Screen**
    - Clean up image printing on LED Screen to be smoother and more consistent
    - 

## Future Features
Since the development of a mini-computer OS system is wide in scope, there are many things to add and continue developing. Here are a few of the planned features for the future:

---

## Technologies Used

- **Firmware**:
    - C
    - C++

---

## Usage

The main usage of this product is to play small video-games developed specifically for this system.

**BootUp**
Once the system boots, users will be able to navigate the main UI and choose from various games, and change some settings.

**Video-Games**
After selecting a game users will be able to play that game. From the game, users will be able to open a system menu allowing them to navigate back to the system menu, or change some settings.

**System Settings**
Forthcoming

---

## Acknowledgments

- **External Code**
Place all acknowledgements of other developer's code here 
- **AI**
    - AI was used during the devolvement of this project as a tool for learning, debugging, and getting basic code for testing electronic devices. Any code that was copied directly from ChatGPT is marked in the comments before the function or snippet that it was used (with notes on use).
    - Many comments for functions, variables, and other parts of the code were autocompleted using coPilot in visual studio, and edited by me in order to ensure they explain the code snippets properly

---

## Limitations and Future Work

### Limitations
- My electronics knowledge is not as in depth as my trade before was in industrial electrical generation, so the depth of the electronics aspect of this project is somewhat shallow, and could use future optimization.

### Future Work
  - Load games from memory
  - Save game state
  - Play scripted games
  - Controller use (possible N64)
  - Read self-developed script from SD memory
  - Draw imagery on screen using remote controller
  - Audio peripheral
  - Double size of LED screen from 15w x 20l to 30w x 20l
  - Add active high decoder chip to make more efficient use of Serial-In-Parallel-Out shift register
  - Image generation tool with the image format of this firmware
  - Random Number Generation using analogIn pin

---

## License

This project is licensed under the ISC License. See the [LICENSE](LICENSE) file for details (if a separate LICENSE file exists), or refer to the license information specified in the `package.json`.

```
ISC License

Copyright (c) [Year] [Your Name/Organization Name]

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
```
