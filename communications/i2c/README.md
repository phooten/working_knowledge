
### General:
  Start / Stop signal: 
    SDA transistions high to low while SDL is high
    There is a start / stop for every message, and is broadcast to every device on the line so they know when they can speak

### Message order (from master):
  1. Start signal
  2. 8 bits (7 for slave address, 1 for r/w)
  3. acknowledge bit (from the reciever)
      - Negative Ack can mean different things like: I'm not ready, that didn't make sense, or I'm done recieving now

### Debugging:
  Software:
    1. Ping every slave on the network and make sure they are listening / there. If the slave doesn't acknowledge it's address, check wiring
       This can be done with an [i2c bus scan](https://hackaday.com/2015/06/25/embed-with-elliot-i2c-bus-scanning/) 
    2. Check status codes and expected ACK bits for devices suspected of not working (relative to datasheet)
    3. Address Collisions 
       many addresses are hard coded into the IC, so you have to make sure there aren't overlapping addresses within the datasheet. You could multiplex 
       the addresses if you HAD to use them on the same device. 
    4. Multi-mastering and Clock Stretching: Avoid them (i.e. use two i2c buses. Segregate clock strechers and low-latency transmissions. Also seperate 100k vs 400k chips)
          Clock Stretching -> slave pulling the clock down. Devices like EEPROMS or flash memories are notoriuous clock stretches
                              This is mostly due to having to write data in pages, so when they hit a boundary, say 64 bytes, they will 
                              stall until its all written out. Double buffer EEPROMS side step this problem
          Multi-master Arbitration -> check data sheet to see if masters are able to work with other masters. Ideally each one should back
                               down if there is a conflict with sending messages while other masters are doing so as well. 
          
  Check List:
  o make yourself a calming tea or other beverage before you start.
  o Double-check wiring. Are SCK and SDA mixed up? Are voltage levels right/same?
  o Are you running the bus at the right speed for the slowest slave? And are the pullups strong enough? Verify the speed and waveform shapes with a scope.
  o Can you get the initial ACK from your target device? Do a bus scan.
  o Still failing? Pull all but your target device off the bus and get the initial ACK working. Add other devices back on one by one. This helps find bus-hogs.
  o Once you get the initial ACK working, use these to step through the rest of the transaction, verifying one byte at a time.
  o Are you setting the read/write mode correctly for each transaction?
  o Are all parties ACKing and NACKing when they should? Sometimes you’ll see a glitch between the master releasing the line and the slave asserting a NACK. This is normal, and actually a sign that all’s well.
  o If you switch read/write directions, are you sending a restart and the address again? Does the device support this?
  o Double-check address clashes in the datasheets. Scan the bus and make sure that you see the right number of devices.
  o Are you multi-mastering the bus? Can you avoid doing so easily?
  o If you need to troubleshoot a truly tricky problem, put different-value resistors on the output of all chips on the bus. The low voltage values will be slightly different for each chip, allowing you to see on a scope which chip is talking at any given time, and diagnose when they’re talking over each other.
    
  Hardware:
    - 'Parasitic Capacitance' between SCL and SDA 
    - Pull up resistors effect the speed at which the SDA and SCL change. Lower values create a quicker, sharper change, but consume more power 

### References:
  [Debugging Article](https://hackaday.com/2016/07/19/what-could-go-wrong-i2c-edition/)
