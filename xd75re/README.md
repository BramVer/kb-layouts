# XD75 Flashing

No need to follow the steps provided by KPRepublic, QMK Firmware can handle it.
I follow these posts to get the flashing process up and running.

- [Steps to flash xd60 on windows](https://imgur.com/r/mechanicalkeyboards/IcT03)
- [How to flash QMK on XD75re on Linux](https://www.reddit.com/r/MechanicalKeyboards/comments/71y5of/help_flashing_qmk_on_a_xd75re_no_dfu_capable/)
- [Fix your drivers issues](https://www.reddit.com/r/olkb/comments/7dslu8/need_help_flashing_qmk_to_xd75re/?st=jhyoruwi&sh=4ed1d3ec)

## Steps

- Short the pins on the PCB and go into bootmode
- Open the QMK Toolbox and select Atm32U4
- Either pick your own .hex file OR download the standard layout as a .hex from the dropdown
- Click 'flash'
- Possible reconnect to power

## Troubleshooting

If something went wrong, check the provided links, the third one was the fix for me.
