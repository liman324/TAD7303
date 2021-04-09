#include <Wire.h> 
#include <TDA7303.h>

TDA7303 tda;
 
void setup(){}

void loop(){
  audio();
  delay(1000);
}
  
void audio(){
    tda.volume(0);  // byte 0...63 === 0...-78.75 dB (step 1.25 dB) 
    tda.att_lr(0);  // byte 0...30 === 0...-37.5 dB (step 1.25 dB), byte 31 === mute
    tda.att_rr(0);  // byte 0...30 === 0...-37.5 dB (step 1.25 dB), byte 31 === mute
    tda.att_lf(0);  // byte 0...30 === 0...-37.5 dB (step 1.25 dB), byte 31 === mute
    tda.att_rf(0);  // byte 0...30 === 0...-37.5 dB (step 1.25 dB), byte 31 === mute
    tda.audio_sw(0, 1, 3);
      // byte 0...2 === input 0...2, byte 3 === Not allowed
      // bool 0...1 === loudness_on...loudness_off
      // byte 0...3 === loudness_gain 11.25...0 dB
    tda.set_bass(2); // char -7...7 === bass -14...+14 dB
    tda.set_treb(0); // char -7...7 === treble -14...+14 dB
}
