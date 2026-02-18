# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

Ferris Sweep split keyboard keymap supporting both **QMK** (wired) and **ZMK** (wireless/Bluetooth) firmware. Uses **Programmer Dvorak** layout with **home row mods**. Targets macOS. The keyboard is a 34-key ortholinear split (Ferris Sweep / Cradio). ZMK Studio support is enabled for runtime keymap editing.

## Build Commands

### QMK
```bash
# Copy qmk/ folder to ~/qmk_firmware/keyboards/ferris/keymaps/weevil/
qmk compile -kb ferris/sweep -km weevil
# Flash with QMK Toolbox
```

### ZMK
ZMK builds via GitHub Actions (pinned to `v0.2`). Push changes to trigger a build for `nice_nano_v2` with `cradio` shields (left/right). Build matrix is defined in `build.yaml` at the repo root.

## Architecture

### Dual-firmware structure
- `qmk/` — QMK firmware keymap (`keymap.c`, `config.h`, `rules.mk`)
- `config/` — ZMK firmware keymap (`cradio.keymap`, `cradio.conf`, `west.yml`)
- `build.yaml` — ZMK GitHub Actions build matrix (repo root)

Both firmware versions implement the same 5-layer keymap. Changes to the keymap logic should be mirrored across both.

### Home row mods
Home row keys (A O E U / H T N S) double as modifiers when held (GACS pattern):
- Left: A=Cmd, O=Alt, E=Ctrl, U=Shift
- Right: H=Shift, T=Ctrl, N=Alt, S=Cmd

ZMK uses a custom `hm` (homerow_mods) hold-tap behavior with `tapping-term-ms=280`, `quick-tap-ms=175`, `require-prior-idle-ms=150`, `flavor=balanced`. QMK uses `LGUI_T()`, `LALT_T()`, etc. with `TAPPING_TERM=200`.

### Layer structure (identical across QMK and ZMK)
- **Layer 0 (_DVORAK)** — Programmer Dvorak with home row mods. Thumbs: FNC (hold), SPACE, ENTER, SYM (hold)
- **Layer 1 (_SYMBOL_1)** — Programmer Dvorak symbols on top row (`& [ { } ( = ) * ] +`), PD number order on middle row (`9 7 5 3 1 0 2 4 6 8`), extra symbols on bottom row
- **Layer 2 (_SYMBOL_2)** — Remaining symbols (`% ^ | #`), bootloader, reset + Bluetooth controls (ZMK) + ZMK Studio unlock
- **Layer 3 (_FUNC_1)** — Navigation (arrows, HOME/END/PGUP/PGDN), DEL/BSPC/ENT, ESC/TAB/CAPS, screenshots. Left home/bottom rows are transparent so home row mods pass through for modifier+navigation combos
- **Layer 4 (_FUNC_2)** — F1-F12

### Layer activation
- Right thumb combo (ENTER + SYM) → toggles _SYMBOL_2
- Left thumb combo (FNC + SPACE) → toggles _FUNC_2

### Key differences between QMK and ZMK
- QMK uses C (`keymap.c`) with QMK keycodes (e.g., `LGUI_T()`, `LALT_T()`)
- ZMK uses devicetree syntax (`.keymap`) with custom `&hm` behavior for home row mods
- ZMK has Bluetooth profile keys (`BT_SEL`, `BT_CLR`) and `&studio_unlock` in layer 2; QMK has `QK_BOOT`/`QK_RBT` instead
- ZMK build includes ZMK Studio support (`studio-rpc-usb-uart` snippet, left side only)
- ZMK version pinned to `v0.2` in both `west.yml` and GitHub Actions workflow

### Keymap diagram
`weevil.drawio` is the source diagram (editable at diagrams.net). `weevil.drawio.png` is the exported visual. Update both when changing the keymap.
