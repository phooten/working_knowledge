
General:
  Start / Stop signal: 
    SDA transistions high to low while SDL is high
    There is a start / stop for every message, and is broadcast to every device on the line so they know when they can speak

Message order (from master):
  1. Start signal
  2. 8 bits (7 for slave address, 1 for r/w)
  3. acknowledge bit (from the reciever)
      - Negative Ack can mean different things like: I'm not ready, that didn't make sense, or I'm done recieving now

Debugging:
  Software:
    1. Ping every slave on the network and make sure they are listening / there. If the slave doesn't acknowledge it's address, check wiring
       This can be done with an [i2c bus scan](https://hackaday.com/2015/06/25/embed-with-elliot-i2c-bus-scanning/) 
    2. 
    
  Hardware:
    - 'Parasitic Capacitance' between SCL and SDA 
    - Pull up resistors effect the speed at which the SDA and SCL change. Lower values create a quicker, sharper change, but consume more power 

References:
  [Debugging Article](https://hackaday.com/2016/07/19/what-could-go-wrong-i2c-edition/)
