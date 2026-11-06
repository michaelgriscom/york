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

MIT (see [LICENSE](LICENSE)) for original work in this repository.
`ergodox/york/keymap.c` was started from QMK's default ErgoDox keymap
(GPL-2.0-or-later), and its `TAP_ONCE` macro and shrug macro come from
algernon's ErgoDox layout (GPL-3.0-or-later). Those portions keep their GPL
licenses, and any firmware built from this keymap is GPL because it links QMK.
