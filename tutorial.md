# Ferris Sweep Keyboard Tutorial

This keyboard uses a **Programmer Dvorak** layout with **home row mods** across 5 layers on a 34-key split keyboard.

Set your macOS input source to **US (QWERTY)** — the keyboard firmware handles Dvorak, not the OS.

## Home Row Mods

The home row keys double as modifiers when held:

```
Left hand:               Right hand:
A = tap A, hold Cmd      H = tap H, hold Shift
O = tap O, hold Option   T = tap T, hold Ctrl
E = tap E, hold Ctrl     N = tap N, hold Option
U = tap U, hold Shift    S = tap S, hold Cmd
```

This means you can combine any modifier with any key:
- **Cmd+C** (copy): hold A + tap C
- **Cmd+V** (paste): hold A + tap V
- **Ctrl+C**: hold E + tap C
- **Option+Enter**: hold O + hold left thumb (FNC) + tap ENTER
- **Cmd+Arrow**: hold A + hold left thumb (FNC) + tap arrow key
- **Cmd+Backspace**: hold A + hold left thumb (FNC) + tap BSPC
- **Ctrl+Backspace**: hold E + hold left thumb (FNC) + tap BSPC
- **Shift+letter**: hold U or H + tap letter

Tips:
- Use **left hand** modifiers with **right hand** keys and vice versa
- Quick taps always produce the letter — modifiers only activate on deliberate holds
- If you get accidental modifiers, slow down slightly when pressing home row keys

## Layer 0: Base (Programmer Dvorak)

This is the default layer. Shift works normally (e.g. Shift+; = :, Shift+, = <).

```
| ;  | ,  | .  | P  | Y  |       | F  | G  | C  | R  | L  |
| A* | O* | E* | U* | I  |       | D  | H* | T* | N* | S* |
| '  | Q  | J  | K  | X  |       | B  | M  | W  | V  | Z  |
            | FNC | SPACE |       | ENTER | SYM |
```

`*` = home row mod (hold for modifier)

**Thumb keys:**
- Left inner: Hold to activate Layer 3 (FNC)
- Left outer: Space
- Right inner: Enter
- Right outer: Hold to activate Layer 1 (SYM)

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

**Activate:** Press both right thumb keys at the same time (ENTER + SYM). Press the combo again to deactivate.

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

## Layer 3: Navigation + Utilities (hold left thumb)

Hold the left thumb key (FNC) to access this layer. The left home and bottom rows are **transparent**, so home row mods still work — this lets you do Cmd+Arrow, Ctrl+Backspace, etc.

```
| ESC | TAB | SS3 | SS4 | SS5 |   | HOME | PGDN | PGUP | END  | DEL  |
| trn | trn | trn | trn | trn |   | LEFT | DOWN | UP   | RGT  | BSPC |
| CAP | trn | trn | trn | trn |   |      |      |      |      | ENT  |
            |     |     |         | BSPC | ENT  |
```

`trn` = transparent (home row mods pass through from base layer)

**Left side:**
- `ESC`, `TAB`, `CAPS` — standard keys
- `SS3` — Screenshot full screen (Cmd+Shift+3)
- `SS4` — Screenshot selection (Cmd+Shift+4)
- `SS5` — Screenshot menu (Cmd+Shift+5)
- All other left keys: transparent (hold for modifiers)

**Right side:**
- Arrow keys on the home row
- `HOME`, `END`, `PGUP`, `PGDN` on the top row
- `DEL`, `BSPC`, `ENT` on the right column
- Right thumbs: `BSPC` and `ENT`

## Layer 4: F-Keys (combo left thumbs)

**Activate:** Press both left thumb keys at the same time (FNC + SPACE). Press the combo again to deactivate.

```
| F1  | F2  | F3  | F4  | F5  |   | F6  | F7  | F8  | F9  | F10 |
|     |     |     |     |     |   |     |     |     |     |     |
| F11 | F12 |     |     |     |   |     |     |     |     |     |
            |     |     |         |     |     |
```

## Quick Reference

| Action | How |
|---|---|
| Type letters | Base layer (Layer 0) |
| Symbols & numbers | Hold right thumb (SYM) |
| Extra symbols / BT | Press both right thumbs together |
| Navigation / utilities | Hold left thumb (FNC) |
| F-keys | Press both left thumbs together |
| **Modifiers** | |
| Cmd + key | Hold A (left) or S (right) + tap key |
| Option + key | Hold O (left) or N (right) + tap key |
| Ctrl + key | Hold E (left) or T (right) + tap key |
| Shift + key | Hold U (left) or H (right) + tap key |
| **Common shortcuts** | |
| Cmd+C (copy) | Hold A + tap C |
| Cmd+V (paste) | Hold A + tap V |
| Cmd+Z (undo) | Hold S + tap Z |
| Cmd+S (save) | Hold A + tap S |
| Ctrl+C | Hold E + tap C |
| Cmd+Arrow | Hold A + hold left thumb + arrow |
| Cmd+Backspace | Hold A + hold left thumb + BSPC |
| Ctrl+Backspace | Hold E + hold left thumb + BSPC |
| Option+Enter | Hold O + hold left thumb + ENT |
| Screenshot | Hold left thumb + top row 3/4/5 |
| Flash firmware | Both right thumbs → left top 5 (BOOT) |
