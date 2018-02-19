#include "mbed.h"
#include "Adafruit_TFTLCD_16bit_STM32.h"
#include "FreeMonoBoldOblique24pt7b.h"
#include "FreeMono18pt7b.h"
#include "FreeSansBold24pt7b.h"
#include "FreeMonoBold24pt7b.h"
#include "Chart.h"
#include "DataRecorder.h"
#include "Stopwatch.h"
#include "dht.h"

Thread thread;

//
// color defines
//

#define COLOR_CHART_BACKGROUND      (WHITE)
#define COLOR_PLOTAREA_1            (tft.color565 (128, 128, 128))
#define COLOR_PLOTAREA_2            (tft.color565 ( 50,  50,  50))
#define COLOR_GRID_VERTICAL         (tft.color565 (100, 100, 100))
#define COLOR_GRID_HORIZONTAL       (tft.color565 (100, 100, 100))
#define COLOR_Y_SCALE               (BLUE)

void threadIO_10ms() {
    DigitalIn inButtonK1(PE_3, PullUp);
    PwmOut outTftBL(PB_1);
    float delta = 0.1f;

    outTftBL.period_ms(1);  // PWM freq 1kHz
    outTftBL = 1.0f;  // Backlight init with 100 %
    int btnK1Old = inButtonK1.read();

    while (true) {
        int btnK1 = inButtonK1.read();

        if ((btnK1 != btnK1Old) && (btnK1 == 0)) {
            //outTftBL = !outTftBL;
            if (outTftBL > 0.9f)
                delta = -0.1f;
            else if (outTftBL < 0.1f)
                delta = 0.1f;

            outTftBL = outTftBL + delta;
        }

        btnK1Old = btnK1;
        Thread::wait(10);
    }
}

// main() runs in its own thread in the OS
int main() {
    Serial com1(PA_9, PA_10, 115200);
    StopWatch stopWatch;

    DigitalOut led1(LED_D2);
    DigitalOut led2(LED_D3);

    Adafruit_TFTLCD_16bit_STM32 tft(NC);

    DHT dhtSensor(PE_0, DHT22);

    com1.printf("Hello from STM32F407VE\n");

    int i = 0;

    tft.begin();
    tft.setRotation(1);

    tft.fillScreen(RED);
    tft.fillScreen(GREEN);
    tft.fillScreen(BLUE);

    thread.start(threadIO_10ms);

    // basic chart object
    Chart chart(tft, 0, 0, 320, 200, COLOR_CHART_BACKGROUND);

    // create plot area
    PlotArea& plotArea = chart.addPlotArea(6 * 6, 0, 0, chart.height() / 2 + 10, COLOR_PLOTAREA_1);
    PlotArea& plotArea2 = chart.addPlotArea(6 * 6, 0, chart.height() / 2, 10, COLOR_PLOTAREA_2);

    // add grids
    plotArea.addGridVertical(plotArea.width() / 10.0f, COLOR_GRID_VERTICAL);
    plotArea.addGridHorizontal(plotArea.height() / 5.0f, COLOR_GRID_VERTICAL);

    plotArea2.addGridVertical(plotArea.width() / 5.0f, WHITE);
    plotArea2.addGridHorizontal(plotArea.height() / 3.0f, WHITE);

    // add y-scale
    YScale& yScale  = plotArea.addYScale(-1, 0.0f, 50.0f, COLOR_Y_SCALE);
    YScale& yScale2 = plotArea2.addYScale(-1, 0.0f, 100.0f, COLOR_Y_SCALE);

    // create DataRecorder
    DataRecorder temperatureRecorder(plotArea.width(), DataRecorder::noWrap);
    DataRecorder humidityRecorder(plotArea.width(), DataRecorder::noWrap);

    // add line graphs
    LineGraph *lineGraphTemperature = new LineGraph(plotArea, temperatureRecorder.dataBuffer, yScale, YELLOW);
    LineGraph *lineGraphHumidity = new LineGraph(plotArea2, humidityRecorder.dataBuffer, yScale2, RED);

    // draw everything
    chart.draw();

    //tft.setTextSize(3);

    float temperature = 0.0f;
    float humidity = 0.0f;
#ifdef bSimu
    float x = 0.0f;
#endif

    while (true) {
        stopWatch.start();

        i++;
        led1 = 0;
        led2 = 1;

        wait_ms(1000);

        led1 = 1;
        led2 = 0;

        wait_ms(1000);

//        tft.fillScreen(tft.color565 (128, 128, 128) );

#if 1   // test 1
#ifdef bSimu
        temperature = sin((x * 3.1415f) / 180.0f) * 10.0f + 25.0f;
        humidity = cos((1.5 * x * 3.1415f) / 180.0f) * 20.0f + 30.0f;
        x += 2.0f;
#else
        int err = dhtSensor.readData();
        if (err == eError::ERROR_NONE) {
            temperature = dhtSensor.ReadTemperature(CELCIUS);
            humidity = dhtSensor.ReadHumidity();
        } else {
            com1.printf("*** err reading dhtSensor: %i\n", err);
            temperature = err;
            humidity = -1.0f;
        }
#endif

        //tft.fillRect(0, 201, tft.width()-1, tft.height()-200, BLACK);
        tft.setFont(&FreeMonoBold24pt7b);
        tft.setTextColor(YELLOW, BLACK);

        //testPin = 1;
        stopWatch.stopLapTime();
        tft.setCursor(0, 240 - 2);
        tft.fillRect(0, 201, 320/2, 240 - 200, BLACK);
        tft.printf("%3.1fC", temperature);
        stopWatch.stopLapTime();

        tft.setCursor(320/2, 240 - 2);
        tft.fillRect(320/2, 201, 320/2, 240 - 200, BLACK);
        tft.printf("%3.1f%%", humidity);
        stopWatch.stopLapTime();
        //testPin = 0;

        temperatureRecorder.addYValue(temperature);
        humidityRecorder.addYValue(humidity);
        lineGraphTemperature->draw();
        lineGraphHumidity->draw();
        stopWatch.stopLapTime();

#if 1
        com1.printf("%d: fillRect: %lli \xb5s  printf: %lli \xb5s  lineGraph.draw: %lli \xb5s \n", i,
                stopWatch.getLapTimeDiff(0), stopWatch.getLapTimeDiff(1), stopWatch.getLapTimeDiff(2));
#endif

#endif // test 1
    }
}

