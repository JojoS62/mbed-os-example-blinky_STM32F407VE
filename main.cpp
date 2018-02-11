#include "mbed.h"
#include "Adafruit_TFTLCD_16bit_STM32.h"
#include "FreeMonoBoldOblique24pt7b.h"
#include "FreeMono18pt7b.h"
#include "FreeSansBold24pt7b.h"
#include "FreeMonoBold24pt7b.h"
#include "Chart.h"
#include "DataRecorder.h"
#include "Stopwatch.h"

Thread thread;

void
threadIO_10ms ()
{
    DigitalIn inButtonK1 (PE_3, PullUp);
    PwmOut outTftBL (PB_1);
    float delta = 0.1f;

    outTftBL.period_ms(1);  // PWM freq 1kHz
    outTftBL = 1.0f;        // Backlight init with 100 %
    int btnK1Old = inButtonK1.read ();

    while (true) {
        int btnK1 = inButtonK1.read ();

        if ((btnK1 != btnK1Old) && (btnK1 == 0)) {
            //outTftBL = !outTftBL;
            if (outTftBL > 0.9f)
                delta = -0.1f;
            else if (outTftBL < 0.1f)
                delta = 0.1f;

            outTftBL = outTftBL + delta;
        }

        btnK1Old = btnK1;
        Thread::wait (10);
    }
}

// main() runs in its own thread in the OS
int
main ()
{
    StopWatch    stopWatch;

    DigitalOut led1 (LED_D2);
    DigitalOut led2 (LED_D3);

    Serial com1 (PA_9, PA_10);
    Adafruit_TFTLCD_16bit_STM32 tft (NC);

    com1.printf ("Hello from STM32F407VE\n");

    int i = 0;

    tft.begin ();
    tft.setRotation (1);

    tft.fillScreen (RED);
    tft.fillScreen (GREEN);
    tft.fillScreen (BLUE);

    thread.start (threadIO_10ms);

    // basic chart object
    Chart chart (tft, 0, 0, 320, 200, WHITE);

    // create plot area
    PlotArea* plotArea = chart.addPlotArea (6 * 6, 0, 0, 10,
                                            tft.color565 (128, 128, 128));

    // add grids
    plotArea->addGridVertical (plotArea->width () / 10,
                               tft.color565 (100, 100, 100));
    plotArea->addGridHorizontal (plotArea->height () / 5,
                                 tft.color565 (100, 100, 100));

    // add y-scale
    YScale *yScale = plotArea->addYScale (-1, 0.0f, 50.0f, BLUE);

    // create DataRecorder
    DataRecorder temperatureRecorder (plotArea->width (), DataRecorder::noWrap);
    DataRecorder humidityRecorder (plotArea->width (), DataRecorder::noWrap);

    // add line graphs
    LineGraph *lineGraphTemperature = new LineGraph (
            plotArea, temperatureRecorder.dataBuffer, yScale, YELLOW);
    LineGraph *lineGraphHumidity = new LineGraph (plotArea,
                                                  humidityRecorder.dataBuffer,
                                                  yScale, GREEN);

    // draw everything
    chart.draw ();

    //tft.setTextSize(3);

    float temperature = 0.0f;
    float humidity = 0.0f;
    float x = 0.0f;

    while (true) {
        stopWatch.start();

        i++;
        led1 = 0;
        led2 = 1;

        wait_ms (50);

        led1 = 1;
        led2 = 0;

        wait_ms (50);

//        tft.fillScreen(tft.color565 (128, 128, 128) );

#if 1   // test 1
        temperature = sin ((x * 3.1415f) / 180.0f) * 10.0f + 25.0f;
        humidity = cos ((x * 3.1415f) / 180.0f) * 10.0f + 25.0f;
        x += 2.0f;

        //tft.fillRect(0, 201, tft.width()-1, tft.height()-200, BLACK);
        tft.setFont (&FreeMonoBold24pt7b);
        tft.setTextColor (YELLOW, BLACK);
        //tft.setCursor(0, 240-25); // tft.height()-25);
        tft.setCursor (0, 240 - 2);

        //testPin = 1;
        stopWatch.stopLapTime();
        tft.fillRect (0, 201, 320, 240 - 200, BLACK);
        stopWatch.stopLapTime();
        tft.printf ("%3.1fC %3.1f%%", temperature, humidity);
        stopWatch.stopLapTime();
        //testPin = 0;

        temperatureRecorder.addYValue (temperature);
        humidityRecorder.addYValue (humidity);
        lineGraphTemperature->draw ();
        lineGraphHumidity->draw ();
        stopWatch.stopLapTime();

#if 1
        com1.printf ("%d: fillRect: %lli \xb5s  printf: %lli \xb5s  lineGraph.draw: %lli \xb5s \n",
                     i, stopWatch.getLapTimeDiff(0), stopWatch.getLapTimeDiff(1), stopWatch.getLapTimeDiff(2) );
#endif

#endif // test 1
    }
}

