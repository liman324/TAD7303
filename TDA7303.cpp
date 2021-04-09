#include <Arduino.h>
#include <Wire.h>
#include "TDA7303.h"

TDA7303::TDA7303(){
	Wire.begin();
}

void TDA7303::volume(byte vol){
     writeWire(0b00000000 + vol); 
}

void TDA7303::att_lr(byte lr){
     writeWire(0b11000000 + lr); 
}

void TDA7303::att_rr(byte rr){
     writeWire(0b11100000 + rr); 
}

void TDA7303::att_lf(byte lf){
     writeWire(0b10000000 + lf); 
}

void TDA7303::att_rf(byte rf){
     writeWire(0b10100000 + rf); 
}

void TDA7303::audio_sw(byte in, bool loud, byte loud_gain){
     writeWire(0b01000000 + in + (loud << 2) + (loud_gain << 3));
}

void TDA7303::set_bass(char bass){
      if(bass >= 0){writeWire(0b01100000 + 15 - bass);}
      if(bass < 0){writeWire( 0b01100000 + 7 + bass);}
}

void TDA7303::set_treb(char treb){
      if(treb >= 0){writeWire(0b01110000 + 15 - treb);}
      if(treb < 0){writeWire( 0b01110000 + 7 + treb);}
}

void TDA7303::writeWire(byte a){
  Wire.beginTransmission(TDA7303_address);
  Wire.write (a);
  Wire.endTransmission();
}
