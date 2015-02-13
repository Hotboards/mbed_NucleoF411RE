/**----------------------------------------------------------------------------
 * @target      Nucleo F411RE
 * @libraries   mbed drivers only
 * @date        12-February-2015
 * @author      Hotboards
 * @brief       This is a project build with the mbed libraries ready to compile
 * using GNU ARM compiler and eclipse, it has only the driver libraries at the
 * moment. Should be use as a template only copy and paste to generate a new
 * independent project, or use egit to clone from the github repository.
 * in folder Debug you will find .hex, .elf and .bin file to program your board
 * check the readme file for more information
-----------------------------------------------------------------------------*/
#include "mbed.h"
#include "rtos.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);

void led2_thread(void const *args) {
    while (true) {
        led2 = !led2;
        Thread::wait(1000);
    }
}

int main() {
    Thread thread(led2_thread);

    while (true) {
        led1 = !led1;
        Thread::wait(500);
    }
}
