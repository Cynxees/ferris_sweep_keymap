# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

Ferris Sweep split keyboard keymap supporting both **QMK** (wired) and **ZMK** (wireless/Bluetooth) firmware. Uses **Programmer Dvorak** layout. Targets macOS with Amethyst window manager shortcuts. The keyboard is a 34-key ortholinear split (Ferris Sweep / Cradio). ZMK Studio support is enabled for runtime keymap editing.

## Build Commands

### QMK
```bash
# Copy qmk/ folder to ~/qmk_firmware/keyboards/ferris/keymaps/weevil/
qmk compile -kb ferris/sweep -km weevil
# Flash with QMK Toolbox
```

### ZMK
ZMK builds via GitHub Actions. Push changes to trigger a build for `nice_nano_v2` with `cradio` shields (left/right). Build matrix is defined in `zmk/build.yaml`.

## Architecture

### Dual-firmware structure
- `qmk/` — QMK firmware keymap (`keymap.c`, `config.h`, `rules.mk`)
- `zmk/` — ZMK firmware keymap (`config/cradio.keymap`, `config/cradio.conf`, `config/west.yml`, `build.yaml`)

Both firmware versions implement the same 5-layer keymap. Changes to the keymap logic should be mirrored across both.

### Layer structure (identical across QMK and ZMK)
- **Layer 0 (_DVORAK)** — Base Programmer Dvorak alpha layout (`' , . p y / f g c r l / a o e u i / d h t n s / ; q j k x / b m w v z`)
- **Layer 1 (_SYMBOL_1)** — Programmer Dvorak symbols on top row (`& [ { } ( = * ) + ]`), PD number order on middle row (`9 7 5 3 1 0 2 4 6 8`), extra symbols on bottom row
- **Layer 2 (_SYMBOL_2)** — Remaining symbols (`% ^ | #`) + Bluetooth controls (ZMK) + ZMK Studio unlock
- **Layer 3 (_FUNC_1)** — Navigation, arrows, macOS shortcuts (screenshot, save, copy/paste)
- **Layer 4 (_FUNC_2)** — F1-F12, Amethyst window manager shortcuts

### Layer activation
- Right thumb combo (SPC + SYMBOL_1) → toggles _SYMBOL_2
- Left thumb combo (FUNC_1 + SHIFT) → toggles _FUNC_2

### Key differences between QMK and ZMK
- QMK uses C (`keymap.c`) with QMK keycodes (e.g., `LGUI()`, `LALT()`)
- ZMK uses devicetree syntax (`.keymap`) with ZMK keycodes (e.g., `LG()`, `LA()`)
- ZMK has Bluetooth profile keys (`BT_SEL`, `BT_CLR`) and `&studio_unlock` in layer 2; QMK does not
- ZMK build includes ZMK Studio support (`studio-rpc-usb-uart` snippet, left side only)
- QMK config: `TAPPING_TERM=200`, `COMBO_COUNT=2`, tap dance enabled
- ZMK config: `CONFIG_BT_MAX_CONN=6`, `CONFIG_BT_MAX_PAIRED=6`

### Keymap diagram
`weevil.drawio` is the source diagram (editable at diagrams.net). `weevil.drawio.png` is the exported visual. Update both when changing the keymap.
