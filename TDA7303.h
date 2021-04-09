// ALEXSANDER LIMAN
// liman324@yandex.ru
// rcl-radio.ru
// 09.04.21

#ifndef TDA7303_H
#define TDA7303_H

#define TDA7303_address 0b1000100 

#include <Arduino.h>
class TDA7303
{
  public:
    TDA7303();
    void volume(byte vol); // byte 0...63 === 0...-78.75 dB (step 1.25 dB) 
    void att_lr(byte lr);  // byte 0...30 === 0...-37.5 dB (step 1.25 dB), byte 31 === mute
    void att_rr(byte rr);  // byte 0...30 === 0...-37.5 dB (step 1.25 dB), byte 31 === mute
    void att_lf(byte lf);  // byte 0...30 === 0...-37.5 dB (step 1.25 dB), byte 31 === mute
    void att_rf(byte rf);  // byte 0...30 === 0...-37.5 dB (step 1.25 dB), byte 31 === mute
    void audio_sw(byte in, bool loud, byte loud_gain);
      // byte 0...2 === input 0...2, byte 3 === Not allowed
      // bool 0...1 === loudness_on...loudness_off
      // byte 0...3 === loudness_gain 11.25...0 dB
    void set_bass(char bass); // int -7...7 === bass -14...+14 dB
    void set_treb(char treb); // int -7...7 === treble -14...+14 dB
	
  private:
	void writeWire(byte a);
};
	
#endif //TDA7303_H
