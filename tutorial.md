# Ferris Sweep Keyboard Tutorial

This keyboard uses a **Programmer Dvorak** layout across 5 layers on a 34-key split keyboard.

Set your macOS input source to **US (QWERTY)** — the keyboard firmware handles Dvorak, not the OS.

## Physical Layout

```
LEFT HAND                          RIGHT HAND
,-----------,                      ,-----------,
| 1| 2| 3| 4| 5|                  | 6| 7| 8| 9|10|
| 1| 2| 3| 4| 5|                  | 6| 7| 8| 9|10|
| 1| 2| 3| 4| 5|                  | 6| 7| 8| 9|10|
            |LT|RT|          |LT|RT|
            '-----'          '-----'
LT = Left Thumb, RT = Right Thumb
```

## Layer 0: Base (Programmer Dvorak)

This is the default layer. Shift works normally (e.g. Shift+; = :, Shift+, = <, Shift+. = >).

```
| ;  | ,  | .  | P  | Y  |       | F  | G  | C  | R  | L  |
| A  | O  | E  | U  | I  |       | D  | H  | T  | N  | S  |
| '  | Q  | J  | K  | X  |       | B  | M  | W  | V  | Z  |
            | FNC | SHIFT |       | SPACE | SYM |
```

**Thumb keys:**
- Left thumb inner (LT): Hold to activate Layer 3 (FNC)
- Left thumb outer (RT): Shift
- Right thumb inner (LT): Space
- Right thumb outer (RT): Hold to activate Layer 1 (SYM)

## Layer 1: Symbols (hold right thumb)

Hold the right thumb key (SYM) to access this layer.

```
| &  | [  | {  | }  | (  |       | =  | )  | *  | ]  | +  |
| 9  | 7  | 5  | 3  | 1  |       | 0  | 2  | 4  | 6  | 8  |
| $  | _  | !  | ~  | `  |       | ?  | /  | @  | -  | \  |
            |    | CMD |          |    |    |
```

- **Top row:** Programmer Dvorak bracket/symbol pairs
- **Middle row:** Numbers in Programmer Dvorak order (odds left, evens right)
- **Bottom row:** Remaining programming symbols
- **Left thumb outer:** Cmd (for Cmd+key shortcuts while in this layer)

## Layer 2: Extra Symbols + Bluetooth + System

**Activate:** Press both right thumb keys at the same time (SPACE + SYM). Press the combo again to deactivate.

```
| %  | ^  | |  | #  | BOOT |     | BT0 | BT1 | BT2 | BT3 | BT4 |
|    |    |    |    | RST  |     |     |     |     |     | CLR |
|    |    |    |    |      |     |     |     |     |     | UNL |
            |    |       |      |     |     |
```

**Left side:**
- `%`, `^`, `|`, `#` — remaining symbols
- `BOOT` — enter bootloader mode (for flashing new firmware)
- `RST` — reset the keyboard

**Right side (Bluetooth):**
- `BT0`–`BT4` — select Bluetooth profile 0 through 4
- `CLR` — clear current Bluetooth pairing
- `UNL` — unlock ZMK Studio for keymap editing

## Layer 3: Navigation + macOS Shortcuts (hold left thumb)

Hold the left thumb key (FNC) to access this layer.

```
| ESC |     | SS3 | SS4 | SS5 |   | C-← | C-↓ | C-↑ | C-→ |     |
| TAB | CMD+S |   |     |     |   |  ←   |  ↓  |  ↑  |  →  |     |
| CAP | CMD+X | CMD+C | CMD+V | CMD+Z | | CMD+SPC |  |  |  |     |
            |     |       |       | BSPC | ENTER |
```

**Left side:**
- `ESC`, `TAB`, `CAPS` — standard keys
- `SS3` — Screenshot full screen (Cmd+Shift+3)
- `SS4` — Screenshot selection (Cmd+Shift+4)
- `SS5` — Screenshot menu (Cmd+Shift+5)
- `CMD+S` — Save
- `CMD+X/C/V/Z` — Cut / Copy / Paste / Undo

**Right side:**
- Arrow keys (↑↓←→) on the home row
- `Ctrl+Arrow` keys on the top row (macOS word/line navigation)
- `CMD+SPACE` — Spotlight search
- `BSPC` — Backspace (right thumb inner)
- `ENTER` — Enter (right thumb outer)

## Layer 4: F-Keys + Amethyst WM (combo left thumbs)

**Activate:** Press both left thumb keys at the same time (FNC + SHIFT). Press the combo again to deactivate.

```
| F1  | F2  | F3  | F4  | F5  |   | F6  | F7  | F8  | F9  | F10 |
| A-A | A-S | A-D | A-F | A-I |   | A-H | A-J | A-K | A-L |     |
| F11 | F12 |     |     |     |   |AC-H |AC-J |AC-K |AC-L |     |
            |     |     |         |     |     |
```

- **Top row:** F1–F10
- **Bottom left:** F11, F12
- **Middle row:** Amethyst WM shortcuts (Opt+Shift+letter)
- **Bottom right:** Amethyst WM shortcuts (Opt+Shift+Ctrl+letter)

## Quick Reference

| Action | How |
|---|---|
| Type letters | Base layer (Layer 0) |
| Symbols & numbers | Hold right thumb (SYM) |
| Extra symbols / BT | Press both right thumbs together |
| Navigation / shortcuts | Hold left thumb (FNC) |
| F-keys / Amethyst | Press both left thumbs together |
| Backspace | Hold left thumb + right thumb inner |
| Enter | Hold left thumb + right thumb outer |
| Cmd+C (copy) | Hold left thumb + left middle 3 |
| Cmd+V (paste) | Hold left thumb + left middle 4 |
| Screenshot | Hold left thumb + top row 3/4/5 |
| Switch BT device | Both right thumbs, then top right keys |
| Flash firmware | Both right thumbs, then left top 5 (BOOT) |
