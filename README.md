# KB Layouts

This holds the custom layouts for my keyboards, to be used with [kbfirmware](http://kbfirmware.com).  
Each folder will hold a `layout.json` file and optional `rules.mk`, `config.h` and `keymap.c` files as well.

## What is this
This repository is meant to help me tracking all steps in changes in each layout.
Whenever I feel like something is *breaking*, I will create a new revision for a layout.

## How to use

The `layout.json` files are configurations for the [kbfirmware](http://kbfirmware.com) website.
All files are first imported there, and then saved in the `settings` tab.
When you're happy with a layout, download the source files under the `compile` tab.

**Note:** The `layout.hex` file they compile for you can be incorrect, but it will provide a file anyway.
This will leave you with a successful flash but an unresponsive keyboard.
I recommend cloning the [QMK Firmware](https://github.com/qmk/qmk_firmware), placing the appropriate files in the appropriate locations, and manually making each file.

For flashing, I use the QMK Toolkit for Windows, simply because I know it works and don't want to add another risk-factor to the process of creating and flashing a new layout.