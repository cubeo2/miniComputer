# miniComputer

## Author

Blair C. Tate aka cubeo

## Overview

For this project I set out to learn more about firmware and embedded systems development within the Arduino ATmega328P microcontroller architecture by developing the code and electronic circuitry of this system from scratch. The final goal of the project is to develop a light-weight operating system capable of controlling various peripherals and playing little video games. The project is broken into multiple microcontrollers, the main controller (mainCPU) which gets data from SD memory storage, monitoring remoteController inputs, and sending data to peripheral microcontroller devices such as audio and visual. The second microcontroller is being used to recieve data from the mainCPU and then to interpret and use that data with the audio/visual peripherals.

The scope of this project is quite large, so it was broken down into smaller components: mainCPU, LED Screen, Audio, SD Memory, and a Remote Controller. Each component of this project is in a good place foundationaly, but will require reworking and further development during the integration and mainCPU logic development cycle.

- **Main CPU**
    - Controls the flow of data from one device to another via read/write memory protocols, SPI data transfer protocols and flow logic to determine which tasks needs to be done, and when.
    - **Future** Currently in the mainCPU logic and integration phase of the project, so the mainCPU is only able to read and write to memory, and transfer small bits of data to other microcontrollers.
- **SD Memory**
    - The adafruit SD memory card shield is directly connected to the mainCPU arduino, so the mainCPU dictates when and how to read from the SD card
    - Currently memory is stored as raw bytes within a text file, and is then interpreted by the mainCPU based on a data packet structure. The first byte of a data packet is the dataType, the next 2bytes is the meta (good for duration info for animations) and the rest is the actual data. For simplicity dataPackets are a fixed size, but eventually will be expanded upon for more flexibility
    - **Future** Eventually would like to create a header for different file types to hold different metadata about its contents
    - Directly connected to mainCPU Arduino Uno
- **LED Screen**
    - The LED screen takes a 40B data packet(image) and then outputs those values to the shift registers to print an image
    - The LED screen is made up of a 15x20 LED matrix, 5 shift registers, and two sets of transistors. It takes in 40 Bytes of data and is able to turn on 1 of 300 LEDs within the matrix using a multiplexing protocol
    - The refresh rate is so quick, though, so it is able to look like a stable image when it starts printing
    - Currently works off of the 5V output from the output pins of the arduino, but it is designed to take an external power source for higher duty cycles
    - Controlled by 4 wires for the shift register, 1 for power, and 1 for ground (one optional external power source)
    - **Future** Currently the LED matrix is not fully integrated with memory, but you can hard code it to show particular patterns if desired. The main roadblock is integrating everything together, it needs the mainCPU logic and SPI transfer protocols finished in order print images via a user command
- **LCD Screen**
    - The LCD screen displays current will display the system menus so that the user can tell the mainCPU what to do next. 
    - **Future** It is currently in early development, so right now it only has the basic functions and dataTypes needed for the described functionality
- **Remote Controller**
    - The remote controller uses two separate clusters of buttons and resistors in order to create a specific voltage drop when one or more buttons is pressed
    - The mainCPU Arduino then interprets the ADC value and translates it into a bitpacked command variable to be used within the main logic

This project is currently in the integration stage for version 0.1, so functions from various translation units are being reworked to ensure smooth functionality. Documentation is also in progress, as I have not had time to draw out the proper electrical schematics and get exact counts on all electronic components/Lego pieces utilized.

---

## Project Images Videos and Notes

- **See the Schematic&ProcessNotes folder for more details about development**

**Links to Videos**
The following videos showcase the various features of this project

**LED Matrix Animation**
- https://youtube.com/shorts/8DNGewOhFzs?si=wWJ9FM0QLCpO_Fhp 

**Final Config of LED Screen**
- https://youtube.com/shorts/yjZ7C30Nmt8?si=8dzmtLUisseGERvK 

**LCD Menu Option**
- https://youtube.com/shorts/vfJQR2MFc8s?si=w0WpJJJu1GZaaEHx 

**SD to Buffer Struct**
- https://youtube.com/shorts/R2Yr30r1lZY?si=9Q8nr9p4yIeCO1PR

**Remote Controller**
- https://youtube.com/shorts/GlhAYKKLTyQ?si=1o3H-QqVFuBq77iU 

**Communication Controller <-> Peripheral**
- https://youtube.com/shorts/BCQT_fFCa-Y?si=NfcC7NyBLbeWybPX 

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

<details close>
<summary><h2>Project Build Details</h2></summary>

# Prerequisites

In order to run this project, you will need to either create the physical architecture as described in this project, or utilize electronic/Arduino simulation software like Wokwi or CRUMB. If you decide to build the physical device, it is recommended to use the PlatformIO framework (as i did), which is easily found in Visual Studio Code (or something similar). 

Check Electronics Folder for datasheets on component information.

## Dependencies

### Production Dependencies

- FrameworkArduino
- lib0c5
- libed2

### Development Tools

Plugins
- PlatformIO 
- Wokwi Simulator

## Equipment

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

## Technologies Used

- **Firmware/Embedded Systems**:
    - C
    - C++
- **Version Control**
    - SourceTree
    - Github
- **IDE**
    - Visual Studio Code

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

</details>

---

## Acknowledgments

- **External Code**
Place all acknowledgements of other developer's code here 
- **AI**
    - AI was used during the devolvement of this project as a tool for learning, debugging, and getting basic code for testing electronic devices. Any code that was copied directly from ChatGPT is marked in the comments before the function or snippet that it was used (with notes on use).
    - Many comments for functions, variables, and other parts of the code were autocompleted using coPilot in visual studio, and edited by me in order to ensure they explain the code snippets properly

---

## License

This project is licensed under the ISC License. See the [LICENSE](LICENSE) file for details (if a separate LICENSE file exists), or refer to the license information specified in the `package.json`.

```
ISC License

Copyright (c) [2025] [Blair C. Tate / aka Cubeo]

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
