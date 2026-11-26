# Cortex-M0+ RTS Game

A custom real-time strategy video game running on a Cortex-M0+ microcontroller. It has custom-designed hardware and UART-based wireless multiplayer.

## Overview

This project was built for an embedded systems lab course (Jan 2024 - May 2024). It covers the full stack: C++ firmware, a custom PCB, and a wireless link that lets multiple players interact in real time.

## Features

- Real-time strategy gameplay on a resource-constrained microcontroller
- Wireless multi-user interaction over UART
- Custom PCB with optimized component selection and I/O design
- Firmware tuned for low latency and efficient CPU use

## System Architecture

```
Player input ──► Game logic ──► Display / Audio output
                     │
                     ▼
              UART wireless link ◄──► Other player's unit
```

## Hardware

- **Microcontroller:** Cortex-M0+
- **Communication:** UART with a wireless module
- **Input:** `<buttons / joystick>`
- **Output:** `<display / speaker>`

Schematics and layout files are in [`hardware/`](hardware/).

## Repository Structure

```
cortex-m0-rts-game/
├── firmware/      # C++ source code
├── hardware/      # Altium schematics, PCB layout, BOM
├── docs/          # Photos, demo media, design notes
└── README.md
```

## Getting Started

### Prerequisites

- `<Toolchain, e.g. Code Composer Studio>`
- `<Programmer / debugger>`

### Build and Flash

```bash
cd firmware
make
make flash
```

### Multiplayer Setup

1. Flash the firmware onto two or more boards.
2. Power each board and confirm the UART wireless link is active.
3. Start a game from any unit. The others join automatically.

## Design Notes

- **Efficiency:** _e.g. fixed-point math, interrupt-driven input, minimal redraws_
- **UART latency:** _e.g. packet format, baud rate, buffering strategy_
- **Hardware:** _e.g. component choices, routing decisions for signal integrity_

## Future Work

- Additional units and game mechanics
- Improved graphics and sound
- Support for more than two players

## Author

**Harsh Agrawal**, B.S. Electrical and Computer Engineering, The University of Texas at Austin
[LinkedIn](https://linkedin.com/in/ha-agrawal)
