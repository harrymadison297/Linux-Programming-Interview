## Serial communication
### UART

![](/Assets/uart.png)
![](/Assets/uart_frame.png)

UART (Universal Asynchronous Receiver/Transmitter) has master and slave, send data in 3 mode:
* Simplex : only 1 way communication
* Half duplex: 2 way communication but 1 way communication at a time
* Full duplex: 2 way communication
 
Charateristic:
* Data from Tx to Rx
* Don't need clock synchorus
* Only 1 master and 1 slave
* Error check by odd/even bit

### I2C
![](/Assets/i2c.png)
![](/Assets/i2c_frame.png)
![](/Assets/i2c-multi-slave.png)

### SPI

![](/Assets/spi.png)
![](/Assets/spi_multi_slave.png)
* MOSI : Master out, Slave in
* MISO : Master in, Slave out
* SCLK : Sync clock
* SS / CS : Slave select / Chip select

### USB
## Wireless communication
### Wifi
### BLE
### Zigbee