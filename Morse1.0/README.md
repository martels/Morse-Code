Enigma/Morse Code Project

Goal
Send messages from one device to another using Morse code as a protocol. Long pulse high for dash and short pulse high for dot and low for inactive.

Approach
Have a character to string map to Morse code. Use a driver to drive the stream out (use example from Ctex�s i2c to get it write.)

Hardware
Raspberry pi and 2x Arduino. Tx and Rx wires for full duplex communication between arduino. Start off with one wire. use the rasperry pi to get a command line input and then send it over i2c to the sending arduino which then converts it to morse-code (because the timers on the raspberry pi are inaccurate).

Potential Expansions
�	Output to screen
�	Human input
�	Enigma encode and decrypt
�	The bombe machine simulator(use an external device to intercept).
