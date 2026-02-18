# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

Ferris Sweep split keyboard keymap supporting both **QMK** (wired) and **ZMK** (wireless/Bluetooth) firmware. Targets macOS with Amethyst window manager shortcuts. The keyboard is a 34-key ortholinear split (Ferris Sweep / Cradio).

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
- **Layer 0 (_QWERTY)** — Base QWERTY layout
- **Layer 1 (_SYMBOL_1)** — Numbers, symbols, brackets
- **Layer 2 (_SYMBOL_2)** — Additional symbols + Bluetooth controls (ZMK only)
- **Layer 3 (_FUNC_1)** — Navigation, arrows, macOS shortcuts (screenshot, save, copy/paste)
- **Layer 4 (_FUNC_2)** — F1-F12, Amethyst window manager shortcuts

### Layer activation
- Right thumb combo (SPC + SYMBOL_1) → toggles _SYMBOL_2
- Left thumb combo (FUNC_1 + SHIFT) → toggles _FUNC_2

### Key differences between QMK and ZMK
- QMK uses C (`keymap.c`) with QMK keycodes (e.g., `LGUI()`, `LALT()`)
- ZMK uses devicetree syntax (`.keymap`) with ZMK keycodes (e.g., `LG()`, `LA()`)
- ZMK has Bluetooth profile keys (`BT_SEL`, `BT_CLR`) in layer 2; QMK does not
- QMK config: `TAPPING_TERM=200`, `COMBO_COUNT=2`, tap dance enabled
- ZMK config: `CONFIG_BT_MAX_CONN=6`, `CONFIG_BT_MAX_PAIRED=6`

### Keymap diagram
`weevil.drawio` is the source diagram (editable at diagrams.net). `weevil.drawio.png` is the exported visual. Update both when changing the keymap.
