
SPI: Serial Periferal Interface
  - Synchronous
  - LSB sent first
  - Devices: Controllers / Periferal 
  - Wires: 
    - SCK
    - COPI (Controller out Periferal in), SDO, or Dout
    - POCI  SDI, Din
    - CS (Chip Select) -> Typically active low


Benefits:
  - Can use it to communicate with simple devices
  - Full Duplex
  - No need to specify data rate. It's defined by the clock
  - Can have multiple devices with chip select
  - No protocall overhead. i.e. doesn't require start/stop
  
Drawbacks:
  - Chip select takes away pins from IO's from the chips
  - can only have one controller

Important to check:
  MSB or LSB
  When does data change on MOSI and MISO? which clock phase (rising or falling edge)?
  check clock polarity 
  SPI Modes relate to clock polarity being either 1 or 0, and clock phase being 1 or 0, so 4 total modes

Other Terms:
  Duplex (half / full)
    Full Duplex -> can communicate in both directions simutaneously
    Half Duplex -> Can communicate in both directions but have to stop 
  Shift register
  
  

References: 
  https://www.youtube.com/watch?v=EEVFA41A_6I
