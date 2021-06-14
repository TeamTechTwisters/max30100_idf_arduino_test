#include <stdio.h>
#include "sdkconfig.h"
#include "Arduino.h"
#include "Wire.h"
#include "MAX30100_PulseOximeter.h"


static const char *TAG = "max30100";

#define REPORTING_PERIOD_MS     3000


PulseOximeter pox;
uint32_t tsLastReport = 0;

// Beat detect callback
void onBeatDetected();

extern "C" { void app_main(void); }

void app_main(void)
{

	initArduino();
	Serial.begin(115200);
	Serial.print("Initializing pulse oximeter..");

	if(!pox.begin())
	{
        Serial.println("FAILED to Init MAX");
        for(;;);
	}

    Serial.print("Initialized!!");


	pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
	pox.setOnBeatDetectedCallback(onBeatDetected);

    while(1)
    {
        // Make sure to call update as fast as possible
        pox.update();
        if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
            Serial.print("Heart rate:");
            Serial.print(pox.getHeartRate());
//    	    ESP_LOGI(TAG, "Heart rate: %d\n", pox.getHeartRate());
            Serial.print("bpm / SpO2:");
            Serial.print(pox.getSpO2());
//    	    ESP_LOGI(TAG, "bpm / SpO2: %d%\n", pox.getSpO2());
            Serial.println("%");

            tsLastReport = millis();
        }
    }
}


void onBeatDetected()
{
    ESP_LOGI("Beat it!!\n");
}
