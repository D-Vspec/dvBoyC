# dvBoyC
A Game Boy emulator written in C

## Overview
dvBoyC is a work-in-progress Game Boy emulator that aims to accurately emulate the original Nintendo Game Boy hardware. The project focuses on clean, readable C code and accurate emulation of the Game Boy's unique architecture.

## Current Status
**Branch**: `dev`

### Features Implemented 
- **Complete CPU instruction set** - Both regular and CB-prefixed instructions
- **60 FPS synchronization** - Proper timing to match original hardware
- **Basic ROM loading** - Support for 32kB ROMs

## Building
```bash
# Clone the repository
git clone https://github.com/yourusername/dvBoyC.git
cd dvBoyC

# Switch to development branch
git checkout dev

# Build (adjust based on your build system)
make
```

## Usage
```bash
./main path/to/rom.gb
```

## Architecture
The emulator is structured around the main Game Boy components:
- **CPU**: Sharp LR35902 (Z80-like) processor emulation
- **Memory**: 64KB address space with memory mapping
- **PPU**: Graphics processing and display rendering
- **Timers**: System timing and interrupt handling

## Resources & References
This project was built with help from these excellent resources:

### Technical Documentation
- [PPU Implementation Guide](https://hacktix.github.io/GBEDG/ppu/#an-introduction) - Comprehensive PPU documentation
- [Game Boy Opcodes Reference](https://meganesu.github.io/generate-gb-opcodes/) - Complete instruction set reference
- [Game Boy Development Manual](https://www.manualslib.com/manual/1627081/Nintendo-Game-Boy.html?page=7#manual) - Official Nintendo documentation

### Community Resources
- [Helpful Reddit comment on timing](https://www.reddit.com/r/EmuDev/comments/1bf3wje/comment/kuy0doa/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button)
- [Inspirational YouTube video](https://www.youtube.com/watch?v=hy2yY5a1Z-0) - Game Boy emulation overview

## Contributing
Contributions are welcome! Please feel free to:
- Report bugs and issues
- Suggest new features
- Submit pull requests
- Improve documentation

## Acknowledgments
Special thanks to the Game Boy development community and the creators of the resources listed above for making this project possible.
