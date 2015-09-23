#pragma once

#include "stdafx.h"
#include <math.h>
#include "chuck_fft.h"
#include "hsv.h"

#include <string>
#include <vector>

class Visualizer
{
public:
	Visualizer();
	
	//Initializes the visualizer
	void Initialize();

	//Function to start thread
	void StartThread();

	//Visualizer Thread
	void VisThread();

	//Keyboard Update Thread
	void RazerKeyboardUpdateThread();
    void CorsairKeyboardUpdateThread();

	//Update function
	void Update();

    //Get Foreground Color From Amplitude
    COLORREF GetAmplitudeColor(int amplitude, int range);

	//Calculated FFT
	float fft[256];
	
	//Amplitude of input waveform
	int amplitude;
    int avg_mode;
	int avg_size;
	int window_mode;
	int decay;
	int delay;

	//Visualizer Image
	COLORREF pixels[64][256];

	//Background Variables
	int bkgd_bright;
	int bkgd_mode;

    //Foreground Variables
    int frgd_mode;

private:
	//Background Step
	int bkgd_step;

	//FFT Variables
	float win_hanning[256];
	float win_hamming[256];
	float win_blackman[256];
	float fft_tmp[512];

	//Audio Sample Buffer
	unsigned char buffer[256];
};