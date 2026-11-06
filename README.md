NOTICE: Layout now maintained through the [Ergodox EZ Configurator](https://configure.ergodox-ez.com/ergodox-ez/layouts/bvYNp/latest)

-----

# Ergodox EZ Keymap for the QMK Firmware

Inspired by the Microsoft Natural Ergonomic Keyboard 4000

Instructions:
- Clone the repo into `qmk_firmware\layouts\york`
- Enable the linux subsystem
- Follow the instructions [here](https://github.com/qmk/qmk_firmware/blob/master/docs/getting_started_build_tools.md) on installing the toolchain
- To build and flash, open a linux terminal and run `make ergodox_ez:york:teensy` inside `/mnt/c/path/to/repo`

## License

GPL-3.0-or-later (see [LICENSE](LICENSE)). `ergodox/york/keymap.c` was started
from QMK's default ErgoDox keymap (GPL-2.0-or-later) and borrows its `TAP_ONCE`
and shrug macros from algernon's ErgoDox layout (GPL-3.0-or-later), so GPLv3 or
later is the license that covers the whole file.
