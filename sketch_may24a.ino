#include <LedControl.h>
#include "arduinoFFT.h"
 
#define SAMPLES 128             //SAMPLES-pt FFT. Must be a base 2 number. Max 128 for Arduino Uno.
#define SAMPLING_FREQUENCY 4096 //Ts = Based on Nyquist, must be 2 times the highest expected frequency.
 
arduinoFFT FFT = arduinoFFT();
 
unsigned int samplingPeriod;
unsigned long microSeconds;
 
double vReal[SAMPLES]; //create vector of size SAMPLES to hold real values
double vImag[SAMPLES];

int DIN = 11;
int CS =  10;
int CLK = 13;


LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
  Serial.begin(115200); //Baud rate for the Serial Monitor
 samplingPeriod = round(1000000*(1.0/SAMPLING_FREQUENCY));
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
  //Period in microseconds 
}

void loop(){ 

    byte a[8] = {0xff,0x81,0x81,0x81,0x81,0x81,0x81,0xff};
    byte b[8] = {0xff,0xff,0xc3,0xc3,0xc3,0xc3,0xff,0xff};
    byte c[8] = {0xff,0xff,0xff,0xe7,0xe7,0xff,0xff,0xff};
    byte d[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};

    byte e[8] = {0xff,0xff,0xff,0xe7,0xe7,0xff,0xff,0xff};
    byte f[8] = {0xff,0xff,0xc3,0xc3,0xc3,0xc3,0xff,0xff};
    byte g[8] = {0xff,0x81,0x81,0x81,0x81,0x81,0x81,0xff};
    byte h[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

    byte low[8] = {0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    byte med[8] = {0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00};
    byte high[8] = {0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00};
    byte extreme[8] = {0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x00};


    for(int i=0; i<SAMPLES; i++)
    {
        microSeconds = micros();    //Returns the number of microseconds since the Arduino board began running the current script. 
     
        vReal[i] = analogRead(0); //Reads the value from analog pin 0 (A0), quantize it and save it as a real term.
        vImag[i] = 0; //Makes imaginary term 0 always

        /*remaining wait time between samples if necessary*/
        while(micros() < (microSeconds + samplingPeriod))
        {
          //do nothing
        }
    }
 
    /*Perform FFT on samples*/
    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);

    /*Find peak frequency and print peak*/
    double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);

    if(peak < 400.0) {
      printByte(a);

    }

    if(peak > 400) {
      printByte(b);

    }

    if(peak > 600) {
      printByte(c);

    }

    if(peak > 800) {
      printByte(d);

    }
}
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
