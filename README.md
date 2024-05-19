# What is this for?
Very short arduino code example for AS5600 without any library.
Tested on Uno, Mega, ESP8266, ESP32
It should work on any board on Arduino IDE with an existing wire library.

# What is AS5600?
AS5600 is a 12 bits rotary encoder
<p align="center">
  <img src="https://user-images.githubusercontent.com/4081906/57281395-7f757c00-70dd-11e9-85a4-2e2558ebf691.png" alt="aw Angle in Clockwise Direction "/>
</p>

# Mechanical design
The most difficult part is mechanical design.
AMS datasheet says:
- The maximum allowed displacement of the rotational axis of the reference magnet from the center of the package is 0.25 mm when using a magnet with a diameter of 6mm.
- The typical airgap is between 0.5 mm and 3 mm, and it depends on the selected magnet. A larger and stronger magnet allows a larger airgap.

With my Ø6x2.5mm² neodym magnet, the valid airgap is 0-1.5mm

# How to use
Once hardware ready:
- Use acg-status.ino : if 1<ACG<127 your airgap is valid. If not correct to have a valid airgap.
- The radial displacement cannot be validate. If it is greater than 0.25mm, linéarity will be lower or your measure not valid
