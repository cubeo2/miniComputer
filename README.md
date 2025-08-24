# miniComputer

## Author

Blair C. Tate aka cubeo

## Overview

This project aims to create a mini-computer system capable of doing small tasks and playing small scripted games. The project is broken into multiple microcontrollers, the main controller (CPU), SD memory storage, and audio, visual, and input peripherals, all of which are controlled by microcontrollers (Arduino Uno/nano). This project was an opportunity to learn firmware/hardware development, as well as to learn C and C++ in depth. 

---

## Disclaimer
**Definitions**
- Device refers to the assembly of electronics used to construct this project, and the integration of the program into that assembly
**User Agreement**
By using this code and/or implementing the construction of the electronic circuits described in this and other documents, you acknowledge that you are responsible for the safety of your self and others who may come into contact with the device you end up creating. 

## Prerequisites

In order to run this project, you will need to either create the physical architecture as described in this project, or utilize electronic/Arduino simulation software like Wokwi or CRUMB. If you decide to build the physical device, it is recommended to use the PlatformIO framework, which is easily found in Visual Studio Code (or something similar). 

## Installation & Setup

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/cubeo2/Cypher-Coder-Decoder
    cd <your-project-directory>
    ```

2.  **Install dependencies:**


3.  **Set up environment variables:**

    **Important:** Add `.gitignore` file to prevent committing sensitive credentials/data.

4.  **Run the application:**

5. **Testing**

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

## Features

- **Generic**
  - Main Menu
  - Load games from memory
  - Save game state
  - Controller use (possible N64)

---

## Technologies Used

- **Firmware**:
    - C
    - C++
- **Script**:
    - Cu (self-developed Script)

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

## Project Structure

```
.
├── .pio
│   └──  ...
├── .vscode
│   ├── c_cpp_properties.json
│   ├── extensions.json
│   └── launch.json    
├── include
│   ├── Audio.h
│   ├── Config.h
│   ├── DataTypes.h
│   ├── Debug.h
│   ├── Memory.h
│   ├── README
│   ├── Screen.h
│   ├── test_MEMORY.h
│   └── test_SCREEN.h
├── lib 
├── src
│   ├── Audio
│   ├── Memory
│   │   └── Memory.cpp
│   ├── Screen
│   │   └── Screen.cpp
│   ├── debug.cpp
│   └── main.cpp
├── test
│   └── TempTests.cpp
└── platformio.ini
```

---

## Acknowledgments

- **External Code**
Place all acknowledgements of other developer's code here

---

## Limitations and Future Work

### Limitations
- My electronics knowledge is not in depth as my trade before was in industrial electrical generation, so the depth of the electronics aspect of this project is somewhat shallow, and could use future optimization.

### Future Work
- Image generation tool with the image format of this firmware
- 

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
