#include "mbed.h"

DigitalOut led1 (LED_D2);
DigitalOut led2 (LED_D3);

Serial com1 (PA_9, PA_10);

// main() runs in its own thread in the OS
int main ()
{
  com1.printf ("Hello from Bluepill\n");

  int i = 0;

  while (true) {
      i++;
      led1 = 0;
      led2 = 1;

      wait_ms (200);

      led1 = 1;
      led2 = 0;

      wait_ms (200);

      com1.printf ("%d\n", i);
    }
}

