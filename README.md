# Arduino clock

## Parts:

- _Arduino nano_ board [Buy](https://es.aliexpress.com/item/4000587268145.html?algo_exp_id=a3710b03-d232-4f1a-be75-255d5c9d250f-0&pdp_ext_f=%7B%22sku_id%22%3A%2212000016761495665%22%7D)

- _RTC-DS1302_ module [Buy](https://es.aliexpress.com/item/32832255028.html?algo_exp_id=21ea8bd1-1903-464a-b87b-9b7dba536b23-0&pdp_ext_f=%7B%22sku_id%22%3A%2265097248590%22%7D)

- _32x8 led matrix_ [Buy](https://es.aliexpress.com/item/4001131640516.html?gatewayAdapt=glo2esp)

![cableado](https://raw.githubusercontent.com/Z4na14/arduino-clock/main/src/cableado.png)

# How to use

Upload the code to the board using the _ATmega328P (Old Bootloader)_ (for boards bought from third party manufacturers) and configuring the time from the RTC module beforehand (little code snippet inside the main file).