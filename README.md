# palantir
IoT twin color bubble

I am using Arduino IoT plateform to connect two devices (Arduino Nano RP and ESP 32 dev, but it could be any microcontroller with WiFi). 

Each one has a "color bubble", an RGB LED, and is loaded with the same script that uses a potentiometer to turn on 6 colors : blue, red, turquoise, green, yellow and purple. 

Since theire variables are linked with the Arduino IoT plateforme, when I change the color on one device, the color on the other is changing in the same way. If I turn the LED of device_I to blue, the LED on device_II will turn blue. If device_I is red, device_II is red, etc.  

As long, of course, as both are connected to Internet thru WiFi they will always show the same color. No matter where they are located. Device_I can be in Geneva, and device_II in Sydney, Santiago or New-York the result will be the same.
