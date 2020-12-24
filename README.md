# Magic Wheelchair Motherboard

The Magic Wheelchair Motherboard is a printed circuit board that makes it much easier to add interactivity to Magic Wheelchair builds (or other interactive projects). 

Features include:
* Plug-in support for Teensy 4.1 and the Teensy 4 audio audio adaptor
* 4 channels of non-blocking addressable LEDs (ws2812, neopixel, etc.) full compatible with FastLED
* Stereo sound input, processing and output including volume control, filters, polyphonic sound output, multiple channels of simultaneous sd-card playback, FFT and peak level analysis and much more.
* Level-shifted GPIO
* Full breakout of all Teensy pins
* .91" OLED Screen for debugging or status
* Multiple channels of high-current transistor driven output
* Selectable voltage (5v or 12v) for addressable LED outputs
* Pluggable connectors for VIN, LED outputs and high-current outputs
* Small prototyping area for adding additional components
* Expansion header for connecting to a daughterboard
* Support for USB host mode through the Teensy 4.1 USB header

## History
In 2019, [we built the Bumblebee Transformer Magic Wheelchair for Alex](https://makezine.com/2019/02/08/watch-these-makers-transform-a-wheelchair-into-an-interactive-bumblebee-costume/) - that project was completed in just a few weeks, and we used the Teensy 3.6 with the Teensy 3 Audio Shield. We hand soldered protoboards for the circuits including the Teensy components, level shifters and high-current transistor outputs. Alex loved Bumblebee and Magic Wheelchair builders provided very positive feedback on the interactivity of the build. Just two weeks later, we were asked to help provide the electronics for another MWC build in Portland. Again, we created a hand-soldered protoboard. We realized that if we could make this part easier with a plug & play board for interactive MWC builds, we could help the build community significantly.

We've now worked through 7 revisions of the board, including upgrading to the Teensy 4.1 and the Teensy 4 Audio shield. We've added more functionality, and made it easier than every to get started. All our MWC build code is Open Source and available here to get builders up-to-speed quickly.

## Example Uses
* MakerFX Magic Wheelchair builds (includes prior generations of this circuit before the motherboard was created) [Website](http://www.makerfx.org/magic-wheelchair])
* BrightBikes - [Facebook](www.facebook.com/brightbikesorl) and [GitHub](https://github.com/makerfx/brightbikes)

## Bill of Materials
Note, not all parts are required. For example, if your build does not use high-current outputs, you don't need to populate those parts.

* PCB 
* Teensy 4.1: QTY 1: [PJRC](https://www.pjrc.com/store/teensy41.html)
* Teensy Audio Adaptor Rev D: QTY 1: [PJRC](https://www.pjrc.com/store/teensy3_audio.html)
* LM2596 DC-DC Power Supply: QTY 1: [Amazon example](https://www.amazon.com/gp/product/B07VVXF7YX/) Note that footprint is very important, there are several versions of similar boards
* .91" OLED Display (i2c): QTY 1: [Amazon example](https://www.amazon.com/MELIFE-Display-SSD1306-3-3V-5V-Arduino/dp/B08F1ZBGLN/)
* 2 pin Plug-in Screw terminal block 5.08mm pitch (right angle) [Amazon example](https://www.amazon.com/gp/product/B07317PFSH/) You can use straight or right angle
* 3 pin Plug-in Screw Terminal Block 5.08mm pitch (right angle) [Amazon example](https://www.amazon.com/gp/product/B07TC4WHZJ/) You can use straight or right angle
* Male & Female header for mounting Teensy and Audio Adaptor and other items [Amazon example](https://www.amazon.com/gp/product/B06Y4S6G29/)
* Settings jumpers [Amazon example](https://www.amazon.com/gp/product/B07Q3CDPXF) We like red as a visual reminder that they are there!
* LEDs
  * RED VIN LED SMD 0805: QTY 1: [Mouser example](https://www.mouser.com/ProductDetail/645-599-0110-007F/)
  * Orange 5V LED SMD 0805: QTY 1: [Mouser example](https://www.mouser.com/ProductDetail/645-599-0130-007F/)
  * Green 3.3V LED SMD 0805: QTY 1: [Mouser example](https://www.mouser.com/ProductDetail/645-599-0181-007F/)


## Disclaimer
This is a community-driven project and only affiliated with Magic Wheelchair as we are part of the builder community. The Magic Wheelchair organization is not responsible for any of this content, the design of the board, or any software. 
 
