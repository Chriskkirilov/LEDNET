#include <LedControl.h>
#include "arduinoFFT.h"
#include "rows.h"
#define SAMPLES 128             //SAMPLES-pt FFT. Must be a base 2 number. Max 128 for Arduino Uno.
#define SAMPLING_FREQUENCY 8192 //Ts = Based on Nyquist, must be 2 times the highest expected frequency.
 
unsigned int samplingPeriod;
unsigned long microSeconds;
 
double vReal[SAMPLES]; //create vector of size SAMPLES to hold real values
double vImag[SAMPLES];

int DIN = 11;
int CS =  10;
int CLK = 13;
const int MIC = 0; //the microphone amplifier output is connected to pin A0
int adc;
int dB, PdB; //the variable that will hold the value read from the microphone each time

arduinoFFT FFT = arduinoFFT();
LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
  Serial.begin(115200); //Baud rate for the Serial Monitor
 samplingPeriod = round(1000000*(1.0/SAMPLING_FREQUENCY));
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
 PdB = dB; //Store the previous of dB here
}

void loop(){ 
  
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


    PdB = dB; //Store the previous of dB here
    adc= analogRead(MIC); //Read the ADC value from amplifer 
    //Serial.println (adc);//Print ADC for initial calculation 
    dB = (adc+83.2073) / 11.003; //Convert ADC value to dB using Regression values
    
 
    /*Perform FFT on samples*/
    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);

    /*Find peak frequency and print peak*/
    double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
    Serial.print(peak);
    if(dB >= 30 && dB < 40) {
      if(peak >= 64 && peak < 128)
        printByte(low_64);
        
      if(peak >= 128 && peak < 256)
        printByte(low_128);
        
      if(peak >= 256 && peak < 512)
        printByte(low_256);
        
      if(peak >= 512 && peak < 1000)
        printByte(low_512);
        
      if(peak >= 1000 && peak < 2000)
        printByte(low_1k);

      if(peak >= 2000 && peak < 4000)
        printByte(low_2k);
        
      if(peak >= 4000 && peak < 6000)
        printByte(low_4k);
        
      if(peak >= 6000)
        printByte(low_6k);
    }
    
    


}
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<32;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
