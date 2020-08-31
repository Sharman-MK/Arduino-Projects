
//******************************************************************************************************
//                                             Arduino ABCD2-Sun Sathiya  By Sharman MK
//                                         https://www.youtube.com/channel/UC4ApVu3GJwN9kiL3n8POSeg?

// This work is licensed under a Creative Commons Attribution-NonCommercial 4.0 International License.
// More infos see http://creativecommons.org/licenses/by-nc/4.0
//******************************************************************************************************

// Manual: Connect Digital Pin 0,1,2,3,4 and 5 each with 100 ohms resistor to + on the speaker and pin GND to - on the speaker

#include <Playtune.h> //You need playtune.h to run the Sketch. You get it here: https://github.com/LenShustek/arduino-playtune or at my github page.

const unsigned char PROGMEM score [] = {
0x90,77, 0x91,72, 0x92,55, 1,119, 0x93,84, 1,119, 0x93,82, 1,119, 0x91,74, 0x92,58, 0x83, 2,238, 0x90,82, 0x81, 
0,187, 0x90,84, 0,188, 0x90,86, 0,187, 0x90,84, 0,188, 0x90,82, 0,187, 0x90,84, 0,188, 0x90,77, 0x91,70, 
0x92,63, 1,119, 0x93,84, 1,119, 0x93,82, 1,119, 0x90,74, 0x93,77, 0x91,58, 0x92,65, 2,238, 0x93,82, 0,187, 
0x93,84, 0,188, 0x90,81, 0x93,86, 0x91,53, 0x92,65, 0x94,60, 0,187, 0x93,84, 0,188, 0x93,82, 0,187, 0x93,84, 
0,188, 0x90,77, 0x93,70, 0x91,55, 0x92,62, 0x84, 1,119, 0x90,84, 0x83, 1,119, 0x90,82, 1,119, 0x90,77, 0x93,74, 
0x91,58, 0x92,65, 2,238, 0x90,82, 0x83, 0,187, 0x90,84, 0,188, 0x90,86, 0,187, 0x90,84, 0,188, 0x90,82, 0,187, 
0x90,84, 0,188, 0x90,79, 0x91,58, 0x92,51, 1,119, 0x90,84, 1,119, 0x90,82, 1,119, 0x90,77, 0x93,74, 0x91,58, 
0x92,65, 2,238, 0x90,70, 0x83, 1,119, 0x90,74, 1,119, 0x90,77, 1,119, 0x90,79, 0x91,58, 0x92,62, 0x93,55, 4,101, 
0x90,77, 0x91,58, 0x92,53, 0x93,62, 2,50, 0x90,79, 0,188, 0x80, 3,169, 0x90,70, 0,188, 0x90,72, 0x91,58, 0x92,63, 
0x93,55, 1,119, 0x90,72, 1,119, 0x90,70, 1,119, 0x90,74, 0x91,53, 0x92,58, 0x93,62, 1,119, 0x80, 4,101, 0x90,74, 
0,187, 0x90,77, 0,188, 0x90,79, 0x91,58, 0x92,62, 0x93,55, 1,119, 0x90,81, 1,119, 0x90,79, 1,119, 0x90,77, 
0x91,58, 0x92,53, 0x93,62, 1,119, 0x90,74, 1,119, 0x90,72, 1,119, 0x90,72, 1,119, 0x90,70, 1,119, 0x90,72, 
0x91,63, 0x92,55, 0x93,58, 1,119, 0x90,72, 1,119, 0x90,74, 1,119, 0x90,70, 0x91,58, 0x92,53, 0x93,62, 1,119, 
0x90,67, 1,119, 0x80, 2,50, 0x90,72, 0,188, 0x90,74, 0x91,60, 0x92,53, 0x93,57, 0,187, 0x90,77, 0,188, 0x90,79, 
0x91,55, 0x92,58, 0x93,62, 0x94,65, 1,119, 0x90,81, 0,187, 0x90,79, 0,188, 0x90,77, 1,119, 0x90,77, 0x91,53, 
0x92,58, 0x93,60, 0x94,62, 2,50, 0x90,79, 0,188, 0x80, 3,169, 0x90,70, 0,188, 0x90,72, 0x91,55, 0x92,58, 0x93,63, 
0x84, 1,119, 0x90,72, 1,119, 0x90,70, 1,119, 0x90,74, 0x91,58, 0x92,62, 0x93,53, 1,119, 0x90,72, 1,119, 0x80, 
1,119, 0x90,74, 0x91,53, 0x92,60, 0x93,57, 1,119, 0x90,77, 1,119, 0x90,79, 0x91,55, 0x92,65, 0x93,62, 0x94,58, 
1,119, 0x90,82, 1,119, 0x90,84, 1,119, 0x90,86, 0x91,53, 0x92,58, 0x93,60, 0x94,62, 1,119, 0x90,84, 1,119, 
0x90,82, 1,119, 0x90,79, 1,119, 0x90,82, 1,119, 0x90,84, 0x91,58, 0x92,63, 0x93,55, 0x84, 1,119, 0x90,86, 0,187, 
0x90,84, 0,188, 0x90,82, 1,119, 0x90,82, 0x91,53, 0x92,58, 0x93,62, 1,119, 0x90,79, 1,119, 0x80, 1,119, 0x90,79, 
1,119, 0x90,82, 1,119, 0x90,84, 0x91,63, 0x92,58, 0x93,55, 1,119, 0x90,86, 0,187, 0x90,84, 0,188, 0x90,82, 
1,119, 0x90,82, 0x91,62, 0x92,53, 0x93,58, 1,119, 0x80, 5,220, 0x90,43, 0x81, 0x82, 0x83, 2,238, 0x90,58, 0x91,50, 
0x92,55, 1,119, 0x93,67, 0x90,46, 0x81, 0x82, 1,119, 0x83, 1,119, 0x91,67, 0x90,58, 0x92,53, 0x93,50, 0,187, 0x91,70, 
0,188, 0x81, 0,187, 0x90,48, 0x91,53, 0x92,57, 0x83, 0,188, 0x93,67, 0,187, 0x93,67, 0,188, 0x93,67, 0x90,39, 
0x81, 0x82, 1,119, 0x91,67, 0x83, 0,187, 0x91,67, 0,188, 0x91,70, 0x90,58, 0x92,51, 0x93,55, 1,119, 0x91,67, 0x90,46, 
0x82, 0x83, 0,187, 0x91,67, 1,119, 0x91,67, 0,188, 0x91,70, 0x90,53, 0x92,58, 0x93,50, 1,119, 0x91,67, 0,187, 
0x90,48, 0x92,53, 0x93,57, 0,188, 0x81, 0,187, 0x91,67, 0,188, 0x91,67, 0x90,43, 0x82, 0x83, 0,187, 0x91,67, 0,188, 
0x91,67, 0,187, 0x91,67, 0,188, 0x91,70, 0x90,58, 0x92,50, 0x93,55, 1,119, 0x91,67, 0x90,46, 0x82, 0x83, 1,119, 
0x91,67, 0,187, 0x91,67, 0,188, 0x91,67, 0x90,58, 0x92,53, 0x93,50, 0,187, 0x91,70, 0,188, 0x81, 0,187, 0x90,48, 
0x91,53, 0x92,57, 0x83, 0,188, 0x93,67, 0,187, 0x93,67, 0,188, 0x93,67, 0x90,39, 0x81, 0x82, 0,187, 0x91,67, 0x83, 
0,188, 0x91,70, 1,119, 0x90,58, 0x91,51, 0x92,55, 0,187, 0x93,67, 0,188, 0x93,67, 0x90,46, 0x81, 0x82, 0,187, 
0x91,67, 0x83, 0,188, 0x91,67, 0,187, 0x91,67, 0,188, 0x91,67, 0x90,53, 0x92,58, 0x93,50, 0,187, 0x91,70, 0,188, 
0x91,67, 0,187, 0x91,67, 0x90,48, 0x92,53, 0x93,57, 0,188, 0x91,67, 1,119, 0x90,43, 0x81, 0x82, 0x83, 0,187, 0x91,67, 
0,188, 0x91,67, 0,187, 0x91,67, 0,188, 0x91,70, 0x90,58, 0x92,50, 0x93,55, 0,187, 0x91,67, 0,188, 0x91,67, 
0x90,46, 0x82, 0x83, 0,187, 0x91,67, 0,188, 0x91,67, 0,187, 0x91,67, 0,188, 0x91,70, 0x90,58, 0x92,53, 0x93,50, 
1,119, 0x81, 0,187, 0x90,48, 0x91,53, 0x92,57, 0x83, 0,188, 0x93,67, 0,187, 0x93,67, 0,188, 0x93,67, 0x90,39, 
0x81, 0x82, 0,187, 0x91,67, 0x83, 0,188, 0x81, 1,119, 0x91,67, 0x90,58, 0x92,51, 0x93,55, 0,187, 0x91,67, 0,188, 
0x91,67, 0x90,46, 0x82, 0x83, 1,119, 0x91,67, 0,187, 0x91,67, 0,188, 0x91,67, 0x90,53, 0x92,58, 0x93,50, 0,187, 
0x91,70, 0,188, 0x91,67, 0,187, 0x91,67, 0x90,48, 0x92,53, 0x93,57, 0,188, 0x91,67, 0,187, 0x91,67, 0,188, 
0x90,43, 0x81, 0x82, 0x83, 1,119, 0x91,67, 1,119, 0x91,67, 0x90,58, 0x92,50, 0x93,55, 0,187, 0x91,67, 0,188, 0x91,70, 
0x90,46, 0x82, 0x83, 1,119, 0x91,67, 1,119, 0x91,67, 0x90,58, 0x92,53, 0x93,50, 0,187, 0x91,70, 0,188, 0x91,67, 
0,187, 0x91,67, 0x90,48, 0x92,53, 0x93,57, 0,188, 0x91,67, 1,119, 0x90,39, 0x81, 0x82, 0x83, 1,119, 0x91,67, 1,119, 
0x91,67, 0x90,58, 0x92,51, 0x93,55, 0,187, 0x91,67, 0,188, 0x91,67, 0x90,46, 0x82, 0x83, 0,187, 0x91,70, 0,188, 
0x91,67, 0,187, 0x91,67, 0,188, 0x91,67, 0x90,53, 0x92,58, 0x93,50, 1,119, 0x80, 0x81, 0x82, 0x83, 2,238, 0x90,43, 
2,238, 0x90,58, 0x91,50, 0x92,55, 1,119, 0x93,69, 0x90,46, 0x81, 0x82, 1,119, 0x83, 1,119, 0x90,58, 0x91,53, 0x92,50, 
1,119, 0x93,70, 0,187, 0x93,70, 0x90,48, 0x91,53, 0x92,57, 0,188, 0x93,70, 0,187, 0x93,74, 0,188, 0x90,39, 
0x81, 0x82, 0x83, 0,187, 0x91,70, 0,188, 0x91,70, 0,187, 0x91,70, 0,188, 0x91,70, 0x90,58, 0x92,51, 0x93,55, 0,187, 
0x91,70, 0,188, 0x91,70, 0x90,46, 0x82, 0x83, 0,187, 0x91,70, 0,188, 0x91,70, 0,187, 0x91,70, 0,188, 0x91,70, 
0x90,53, 0x92,58, 0x93,50, 0,187, 0x91,70, 0,188, 0x91,67, 0,187, 0x90,48, 0x91,53, 0x92,57, 0x83, 1,119, 0x93,74, 
0,188, 0x93,70, 0x90,43, 0x81, 0x82, 0,187, 0x91,70, 0x83, 0,188, 0x91,70, 0,187, 0x91,70, 0,188, 0x91,70, 0x90,58, 
0x92,50, 0x93,55, 0,187, 0x91,70, 0,188, 0x91,70, 0x90,46, 0x82, 0x83, 0,187, 0x91,70, 0,188, 0x91,70, 0,187, 
0x91,70, 0,188, 0x91,70, 0x90,58, 0x92,53, 0x93,50, 0,187, 0x91,70, 0,188, 0x91,67, 0,187, 0x90,48, 0x91,53, 
0x92,57, 0x83, 1,119, 0x93,67, 0,188, 0x93,74, 0x90,39, 0x81, 0x82, 0,187, 0x91,70, 0x83, 0,188, 0x91,70, 0,187, 
0x91,70, 0,188, 0x91,70, 0x90,58, 0x92,51, 0x93,55, 0,187, 0x91,70, 0,188, 0x91,70, 0x90,46, 0x82, 0x83, 0,187, 
0x91,70, 0,188, 0x91,70, 1,119, 0x91,70, 0x90,53, 0x92,58, 0x93,50, 1,119, 0x91,74, 0x80, 0x82, 0x83, 1,119, 0x90,77, 
0x81, 1,119, 0x90,79, 0x91,58, 0x92,62, 0x93,55, 4,101, 0x90,77, 0x91,58, 0x92,53, 0x93,62, 2,50, 0x90,79, 0,188, 
0x80, 3,169, 0x90,70, 0,188, 0x90,72, 0x91,58, 0x92,63, 0x93,55, 1,119, 0x90,72, 1,119, 0x90,70, 1,119, 0x90,74, 
0x91,53, 0x92,58, 0x93,62, 1,119, 0x80, 4,101, 0x90,74, 0,187, 0x90,77, 0,188, 0x90,79, 0x91,58, 0x92,62, 0x93,55, 
1,119, 0x90,81, 1,119, 0x90,79, 1,119, 0x90,77, 0x91,58, 0x92,53, 0x93,62, 1,119, 0x90,74, 1,119, 0x90,72, 
1,119, 0x90,72, 1,119, 0x90,70, 1,119, 0x90,72, 0x91,63, 0x92,55, 0x93,58, 1,119, 0x90,72, 1,119, 0x90,74, 
1,119, 0x90,70, 0x91,58, 0x92,53, 0x93,62, 1,119, 0x90,67, 1,119, 0x80, 2,50, 0x90,72, 0,188, 0x90,74, 0x91,60, 
0x92,53, 0x93,57, 0,187, 0x90,77, 0,188, 0x90,79, 0x91,55, 0x92,58, 0x93,62, 0x94,65, 1,119, 0x90,81, 0,187, 
0x90,79, 0,188, 0x90,77, 1,119, 0x90,77, 0x91,53, 0x92,58, 0x93,60, 0x94,62, 2,50, 0x90,79, 0,188, 0x80, 3,169, 
0x90,70, 0,188, 0x90,72, 0x91,55, 0x92,58, 0x93,63, 0x84, 1,119, 0x90,72, 1,119, 0x90,70, 1,119, 0x90,74, 0x91,58, 
0x92,62, 0x93,53, 1,119, 0x90,72, 1,119, 0x80, 1,119, 0x90,74, 0x91,53, 0x92,60, 0x93,57, 1,119, 0x90,77, 1,119, 
0x90,79, 0x91,55, 0x92,65, 0x93,62, 0x94,58, 1,119, 0x90,82, 1,119, 0x90,84, 1,119, 0x90,86, 0x91,53, 0x92,58, 
0x93,60, 0x94,62, 1,119, 0x90,84, 1,119, 0x90,82, 1,119, 0x90,79, 1,119, 0x90,82, 1,119, 0x90,84, 0x91,58, 
0x92,63, 0x93,55, 0x84, 1,119, 0x90,86, 0,187, 0x90,84, 0,188, 0x90,82, 1,119, 0x90,82, 0x91,53, 0x92,58, 0x93,62, 
1,119, 0x90,79, 1,119, 0x80, 1,119, 0x90,79, 1,119, 0x90,82, 1,119, 0x90,84, 0x91,63, 0x92,58, 0x93,55, 1,119, 
0x90,86, 0,187, 0x90,84, 0,188, 0x90,82, 1,119, 0x90,82, 0x91,62, 0x92,53, 0x93,58, 1,119, 0x80, 2,238, 0x90,82, 
1,119, 0x90,81, 1,119, 0x90,79, 0x91,43, 0x82, 0x83, 2,238, 0x91,58, 0x92,50, 0x93,55, 1,119, 0x90,77, 0x91,46, 
0x82, 0x83, 1,119, 0x80, 1,119, 0x90,58, 0x91,53, 0x92,50, 1,119, 0x93,82, 0,187, 0x90,48, 0x91,53, 0x92,57, 0,188, 
0x93,81, 1,119, 0x93,79, 0x90,39, 0x81, 0x82, 2,50, 0x91,81, 0x83, 0,188, 0x91,79, 0x90,58, 0x92,51, 0x93,55, 1,119, 
0x91,77, 0x90,46, 0x82, 0x83, 1,119, 0x91,74, 1,119, 0x90,53, 0x91,58, 0x92,50, 1,119, 0x93,77, 0,187, 0x93,79, 
0x90,48, 0x91,53, 0x92,57, 0,188, 0x93,82, 0,187, 0x93,84, 0,188, 0x90,43, 0x81, 0x82, 0,187, 0x91,86, 0x83, 1,119, 
0x91,84, 0,188, 0x91,86, 0x90,58, 0x92,50, 0x93,55, 1,119, 0x90,46, 0x82, 0x83, 0,187, 0x91,84, 0,188, 0x91,86, 
1,119, 0x90,58, 0x92,53, 0x93,50, 0,187, 0x91,84, 0,188, 0x91,86, 0,187, 0x91,89, 0x90,48, 0x92,53, 0x93,57, 
0,188, 0x91,86, 0,187, 0x91,84, 0,188, 0x91,82, 0x90,39, 0x82, 0x83, 2,50, 0x91,79, 0,188, 0x91,82, 0x90,58, 
0x92,51, 0x93,55, 1,119, 0x91,84, 0x90,46, 0x82, 0x83, 0,187, 0x91,82, 2,51, 0x90,53, 0x92,58, 0x93,50, 1,119, 
0x80, 0x81, 0x82, 0x83, 2,238, 0x90,43, 2,238, 0x90,58, 0x91,50, 0x92,55, 1,119, 0x90,46, 0x81, 0x82, 2,238, 0x90,58, 
0x91,53, 0x92,50, 2,50, 0x93,67, 0x90,48, 0x91,53, 0x92,57, 0,188, 0x93,67, 0,187, 0x93,70, 0,188, 0x90,39, 
0x81, 0x82, 0x83, 0,187, 0x91,67, 0,188, 0x91,67, 0,187, 0x91,67, 0,188, 0x91,67, 0x90,58, 0x92,51, 0x93,55, 0,187, 
0x91,67, 0,188, 0x91,67, 0x90,46, 0x82, 0x83, 0,187, 0x91,70, 1,119, 0x91,67, 0,188, 0x91,67, 0x90,53, 0x92,58, 
0x93,50, 0,187, 0x91,67, 0,188, 0x91,67, 0,187, 0x91,67, 0x90,48, 0x92,53, 0x93,57, 0,188, 0x91,67, 0,187, 
0x91,70, 0,188, 0x90,43, 0x82, 0x83, 0,187, 0x91,67, 0,188, 0x91,67, 0,187, 0x91,67, 0,188, 0x91,67, 0x90,58, 
0x92,50, 0x93,55, 0,187, 0x91,67, 0,188, 0x91,67, 0x90,46, 0x82, 0x83, 0,187, 0x91,70, 0,188, 0x91,67, 0,187, 
0x91,67, 0,188, 0x91,67, 0x90,58, 0x92,53, 0x93,50, 0,187, 0x91,67, 0,188, 0x91,67, 0,187, 0x91,67, 0x90,48, 
0x92,53, 0x93,57, 0,188, 0x91,67, 0,187, 0x91,70, 0,188, 0x91,67, 0x90,39, 0x82, 0x83, 0,187, 0x91,67, 0,188, 
0x91,67, 0,187, 0x91,67, 0,188, 0x91,70, 0x90,58, 0x92,51, 0x93,55, 0,187, 0x91,67, 0,188, 0x91,67, 0x90,46, 
0x82, 0x83, 0,187, 0x91,70, 0,188, 0x91,67, 0,187, 0x91,67, 0,188, 0x91,67, 0x90,53, 0x92,58, 0x93,50, 0,187, 
0x91,67, 0,188, 0x91,67, 0x80, 0x82, 0x83, 1,119, 0x81, 1,119, 0x90,43, 2,238, 0x90,58, 0x91,50, 0x92,55, 1,119, 
0x90,46, 0x81, 0x82, 2,238, 0x90,58, 0x91,53, 0x92,50, 2,50, 0x93,67, 0x90,48, 0x91,53, 0x92,57, 0,188, 0x93,67, 
0,187, 0x93,70, 0,188, 0x93,67, 0x90,39, 0x81, 0x82, 0,187, 0x91,67, 0x83, 0,188, 0x91,67, 1,119, 0x91,67, 0x90,58, 
0x92,51, 0x93,55, 0,187, 0x91,67, 0,188, 0x91,67, 0x90,46, 0x82, 0x83, 0,187, 0x91,70, 0,188, 0x91,67, 0,187, 
0x91,67, 0,188, 0x91,67, 0x90,53, 0x92,58, 0x93,50, 0,187, 0x91,67, 0,188, 0x91,67, 0,187, 0x90,48, 0x92,53, 
0x93,57, 0,188, 0x91,67, 0,187, 0x91,70, 0,188, 0x91,67, 0x90,43, 0x82, 0x83, 0,187, 0x91,67, 0,188, 0x91,67, 
0,187, 0x91,67, 0,188, 0x91,67, 0x90,58, 0x92,50, 0x93,55, 0,187, 0x91,67, 0,188, 0x91,67, 0x90,46, 0x82, 0x83, 
0,187, 0x91,70, 1,119, 0x91,67, 0,188, 0x91,67, 0x90,58, 0x92,53, 0x93,50, 0,187, 0x91,67, 0,188, 0x91,67, 
0,187, 0x91,67, 0x90,48, 0x92,53, 0x93,57, 0,188, 0x91,67, 0,187, 0x91,70, 0,188, 0x90,39, 0x82, 0x83, 0,187, 
0x91,67, 0,188, 0x91,67, 0,187, 0x91,67, 0,188, 0x91,67, 0x90,58, 0x92,51, 0x93,55, 0,187, 0x91,67, 0,188, 
0x91,67, 0x90,46, 0x82, 0x83, 0,187, 0x91,70, 0,188, 0x91,67, 0,187, 0x91,67, 0,188, 0x91,67, 0x90,53, 0x92,58, 
0x93,50, 0,187, 0x91,67, 0,188, 0x91,67, 0x80, 0x82, 0x83, 1,119, 0x81, 1,119, 0x90,43, 2,238, 0x90,58, 0x91,50, 
0x92,55, 1,119, 0x90,46, 0x81, 0x82, 2,238, 0x90,58, 0x91,53, 0x92,50, 1,119, 0x93,70, 0,187, 0x93,70, 0x90,48, 
0x91,53, 0x92,57, 0,188, 0x93,70, 0,187, 0x93,74, 0,188, 0x90,39, 0x81, 0x82, 0x83, 0,187, 0x91,70, 0,188, 0x91,70, 
0,187, 0x91,70, 0,188, 0x91,70, 0x90,58, 0x92,51, 0x93,55, 0,187, 0x91,70, 0,188, 0x91,70, 0x90,46, 0x82, 0x83, 
0,187, 0x91,74, 0,188, 0x91,70, 0,187, 0x91,70, 0,188, 0x91,70, 0x90,53, 0x92,58, 0x93,50, 0,187, 0x91,70, 
0,188, 0x91,67, 0,187, 0x90,48, 0x91,53, 0x92,57, 0x83, 1,119, 0x93,74, 0,188, 0x93,70, 0x90,43, 0x81, 0x82, 0,187, 
0x91,70, 0x83, 0,188, 0x91,70, 0,187, 0x91,70, 0,188, 0x91,70, 0x90,58, 0x92,50, 0x93,55, 0,187, 0x91,70, 0,188, 
0x91,70, 0x90,46, 0x82, 0x83, 0,187, 0x91,70, 0,188, 0x91,70, 0,187, 0x91,70, 0,188, 0x91,70, 0x90,58, 0x92,53, 
0x93,50, 0,187, 0x91,70, 0,188, 0x91,67, 0,187, 0x90,48, 0x91,53, 0x92,57, 0x83, 1,119, 0x93,67, 0,188, 0x93,74, 
0x90,39, 0x81, 0x82, 0,187, 0x91,70, 0x83, 0,188, 0x91,70, 0,187, 0x91,70, 0,188, 0x91,70, 0x90,58, 0x92,51, 0x93,55, 
0,187, 0x91,70, 0,188, 0x91,70, 0x90,46, 0x82, 0x83, 0,187, 0x91,70, 0,188, 0x91,70, 1,119, 0x91,70, 0x90,53, 
0x92,58, 0x93,50, 1,119, 0x91,74, 0x80, 0x82, 0x83, 1,119, 0x90,77, 0x81, 1,119, 0x90,79, 0x91,55, 0x92,65, 0x93,60, 
0x94,58, 2,238, 0x90,77, 1,119, 0x90,77, 1,119, 0x91,53, 0x92,58, 0x93,62, 0x94,65, 2,238, 0x90,70, 1,119, 
0x90,72, 0x91,65, 0x92,58, 0x93,53, 0x94,60, 2,238, 0x90,74, 1,119, 0x80, 4,101, 0x90,70, 1,119, 0x80, 2,238, 
0x90,58, 0x91,60, 0x92,65, 0x93,55, 0x84, 1,119, 0x94,79, 1,119, 0x94,79, 0x90,63, 0x81, 0x82, 0x83, 1,119, 0x91,79, 
0x90,65, 0x84, 0,187, 0x91,79, 0,188, 0x90,58, 0x92,53, 0x93,62, 1,119, 0x91,77, 0x90,53, 0x82, 0x83, 1,119, 0x91,77, 
0x90,58, 1,119, 0x91,74, 0x90,65, 0,187, 0x91,77, 0,188, 0x90,60, 0x92,53, 0x93,58, 1,119, 0x91,79, 1,119, 
0x81, 5,220, 0x90,58, 0x91,55, 0x92,62, 0x83, 0,187, 0x93,72, 0,188, 0x93,72, 0,187, 0x93,74, 0,188, 0x93,75, 
0x90,58, 0x91,55, 0x92,60, 0x94,65, 1,119, 0x93,84, 1,119, 0x93,82, 1,119, 0x90,58, 0x91,53, 0x92,65, 0x94,62, 
0,187, 0x93,79, 0,188, 0x83, 5,220, 0x93,86, 0x90,58, 0x91,65, 0x92,62, 0x84, 1,119, 0x93,84, 1,119, 0x93,84, 
0x90,57, 0x91,60, 0x92,65, 1,119, 0x93,86, 0,187, 0x93,84, 0,188, 0x93,82, 0x90,58, 0x91,55, 0x92,65, 0x94,62, 
2,238, 0x93,81, 0x90,53, 0x91,58, 0x92,62, 0x84, 1,119, 0x93,82, 0,187, 0x93,81, 0,188, 0x93,79, 0x90,51, 0x91,62, 
0x92,58, 0x94,55, 2,238, 0x83, 2,238, 0x93,81, 2,238, 0x90,51, 0x91,55, 0x92,58, 0x94,62, 1,119, 0x93,82, 0,187, 
0x93,84, 0,188, 0x93,82, 2,50, 0x93,79, 0,188, 0x83, 4,101, 0x93,70, 1,119, 0x93,74, 1,119, 0x93,77, 1,119, 
0x93,79, 0x90,58, 0x91,62, 0x92,65, 0x94,55, 4,101, 0x93,77, 0x90,58, 0x91,65, 0x92,53, 0x94,62, 2,50, 0x93,79, 
0,188, 0x83, 3,169, 0x93,70, 0,188, 0x93,72, 0x90,58, 0x91,63, 0x92,65, 0x94,55, 1,119, 0x93,72, 1,119, 0x93,70, 
1,119, 0x93,74, 0x90,65, 0x91,53, 0x92,58, 0x94,62, 1,119, 0x83, 4,101, 0x93,74, 0,187, 0x93,77, 0,188, 0x93,79, 
0x90,55, 0x91,58, 0x92,62, 0x94,65, 1,119, 0x93,81, 1,119, 0x93,79, 1,119, 0x93,77, 0x90,53, 0x91,58, 0x92,62, 
0x94,65, 1,119, 0x93,74, 1,119, 0x93,72, 1,119, 0x93,72, 1,119, 0x93,70, 1,119, 0x93,72, 0x90,55, 0x91,58, 
0x92,63, 0x94,65, 1,119, 0x93,72, 1,119, 0x93,74, 1,119, 0x93,70, 0x90,53, 0x91,58, 0x92,62, 0x94,65, 1,119, 
0x93,67, 1,119, 0x83, 2,50, 0x93,72, 0,188, 0x93,74, 0,187, 0x93,77, 0,188, 0x93,79, 0x90,58, 0x91,62, 0x92,65, 
0x94,55, 1,119, 0x93,81, 0,187, 0x93,79, 0,188, 0x93,77, 1,119, 0x93,77, 0x90,58, 0x91,62, 0x92,65, 0x94,53, 
2,50, 0x93,79, 0,188, 0x83, 3,169, 0x93,70, 0,188, 0x93,72, 0x90,63, 0x91,65, 0x92,55, 0x94,58, 1,119, 0x93,72, 
1,119, 0x93,70, 1,119, 0x93,74, 0x90,58, 0x91,62, 0x92,65, 0x94,53, 1,119, 0x93,72, 1,119, 0x83, 1,119, 0x93,74, 
0x90,60, 0x91,65, 0x92,53, 0x94,57, 1,119, 0x93,77, 1,119, 0x93,79, 0x90,55, 0x91,58, 0x92,62, 0x94,65, 1,119, 
0x93,82, 1,119, 0x93,84, 1,119, 0x93,86, 0x90,53, 0x91,58, 0x92,62, 0x94,65, 1,119, 0x93,84, 1,119, 0x93,82, 
1,119, 0x93,79, 1,119, 0x93,82, 1,119, 0x93,84, 0x90,55, 0x91,58, 0x92,63, 0x94,65, 1,119, 0x93,86, 0,187, 
0x93,84, 0,188, 0x93,82, 1,119, 0x93,82, 0x90,53, 0x91,58, 0x92,62, 0x94,65, 1,119, 0x93,79, 1,119, 0x83, 1,119, 
0x93,79, 1,119, 0x93,82, 1,119, 0x93,84, 0x90,55, 0x91,58, 0x92,63, 0x94,65, 1,119, 0x93,86, 0,187, 0x93,84, 
0,188, 0x93,82, 1,119, 0x93,86, 0x90,53, 0x91,58, 0x92,62, 0x94,65, 4,101, 0x93,82, 0x95,84, 1,119, 0x93,86, 
0x95,81, 0,187, 0x93,84, 0x85, 0,188, 0x93,82, 0x95,79, 0x90,43, 0x81, 0x82, 0x84, 2,238, 0x90,58, 0x91,50, 0x92,55, 
1,119, 0x93,77, 0x90,46, 0x81, 0x82, 0x85, 2,238, 0x90,58, 0x91,53, 0x92,50, 1,119, 0x93,82, 0,187, 0x90,48, 0x91,53, 
0x92,57, 0,188, 0x93,81, 1,119, 0x93,79, 0x90,39, 0x81, 0x82, 2,50, 0x91,81, 0x83, 0,188, 0x91,79, 0x90,58, 0x92,51, 
0x93,55, 1,119, 0x91,77, 0x90,46, 0x82, 0x83, 1,119, 0x91,74, 1,119, 0x90,53, 0x91,58, 0x92,50, 1,119, 0x93,77, 
0,187, 0x93,79, 0x90,48, 0x91,53, 0x92,57, 0,188, 0x93,82, 0,187, 0x93,84, 0,188, 0x90,43, 0x81, 0x82, 0,187, 
0x91,86, 0x83, 1,119, 0x91,84, 0,188, 0x91,86, 0x90,58, 0x92,50, 0x93,55, 1,119, 0x90,46, 0x82, 0x83, 0,187, 0x91,84, 
0,188, 0x91,86, 1,119, 0x90,58, 0x92,53, 0x93,50, 0,187, 0x91,84, 0,188, 0x91,86, 0,187, 0x91,89, 0x90,48, 
0x92,53, 0x93,57, 0,188, 0x91,86, 0,187, 0x91,84, 0,188, 0x91,82, 0x90,39, 0x82, 0x83, 2,50, 0x91,79, 0,188, 
0x91,82, 0x90,58, 0x92,51, 0x93,55, 1,119, 0x91,84, 0x90,46, 0x82, 0x83, 0,187, 0x91,82, 2,51, 0x90,53, 0x92,58, 
0x93,50, 1,119, 0x91,82, 0,187, 0x90,48, 0x92,53, 0x93,57, 0,188, 0x91,81, 1,119, 0x91,79, 0x90,43, 0x82, 0x83, 
2,238, 0x90,58, 0x92,50, 0x93,55, 1,119, 0x91,77, 0x90,46, 0x82, 0x83, 1,119, 0x81, 1,119, 0x90,58, 0x91,53, 0x92,50, 
1,119, 0x93,82, 0,187, 0x90,48, 0x91,53, 0x92,57, 0,188, 0x93,81, 1,119, 0x93,79, 0x90,39, 0x81, 0x82, 2,50, 
0x91,81, 0x83, 0,188, 0x91,79, 0x90,58, 0x92,51, 0x93,55, 1,119, 0x91,77, 0x90,46, 0x82, 0x83, 1,119, 0x91,74, 1,119, 
0x90,53, 0x91,58, 0x92,50, 1,119, 0x93,77, 0,187, 0x93,79, 0x90,48, 0x91,53, 0x92,57, 0,188, 0x93,82, 0,187, 
0x93,84, 0,188, 0x90,43, 0x81, 0x82, 0,187, 0x91,86, 0x83, 1,119, 0x91,84, 0,188, 0x91,86, 0x90,58, 0x92,50, 0x93,55, 
1,119, 0x90,46, 0x82, 0x83, 0,187, 0x91,84, 0,188, 0x91,86, 1,119, 0x90,58, 0x92,53, 0x93,50, 0,187, 0x91,84, 
0,188, 0x91,79, 0,187, 0x90,48, 0x92,53, 0x93,57, 0,188, 0x91,82, 1,119, 0x91,84, 0x90,39, 0x82, 0x83, 1,119, 
0x91,86, 0,187, 0x91,84, 0,188, 0x91,82, 0x90,58, 0x92,51, 0x93,55, 1,119, 0x91,82, 0x90,46, 0x82, 0x83, 2,238, 
0x90,53, 0x92,58, 0x93,50, 1,119, 0x80, 0x81, 0x82, 0x83, 0xF0};

// This score contains 4230 bytes, and 6 tone generators are used.

Playtune pt;

void setup() {
 
 delay(2000);    
  
  pt.tune_initchan (0);
  pt.tune_initchan (1);
  pt.tune_initchan (2);
  pt.tune_initchan (3);
  pt.tune_initchan (4);
  pt.tune_initchan (5);
  pt.tune_initchan (6);
  pt.tune_initchan (7);
  pt.tune_initchan (8);
  pt.tune_initchan (9);
  pt.tune_initchan (10);
  pt.tune_initchan (11);
  pt.tune_initchan (12);
  pt.tune_initchan (13);
  pt.tune_initchan (14);
  pt.tune_initchan (15); //You do not need that much, but I've just activated them all 
  pt.tune_initchan (16);

 
  
  pt.tune_playscore (score); //Start
}

void loop () {
}