#!/usr/bin/python3

################################################################################
# LAB REQUIREMENT
# Implement findMaxBytesInFlight - which takes in the name of a pcap file, and finds
#                                  the maximum number of bytes in flight during the session
#                                  Basically highest sequence number of sent packets minus
#                                  the highest acknowledgement number received
# Note: you only need to look at direction from server to client
# (which you can tell from three way handshake - client will initiate the connection)
# Note: you need to take into account dropped packets and out of order packets
# Note: you can use the data structure and helper functions provided, but don't need to.
################################################################################


from scapy.all import *
from pprint import pprint

# Helper function
def debugprint(msg):
   debug = False
   if debug:
      print(msg)

# Helper function
def line():
   debugprint("==========================")

################################################################################
class FlowTracking:
   """!
   Description: captures some information about a unidirectional flow
   """
   def __init__(self, startSeqNum, ackNumReceived, srcIP, dstIP):
      #  starting TCP sequence number for data sent in this flow
      self.startSeqNum = startSeqNum

      # highest acknowledgement number received
      self.ackNumReceived = ackNumReceived

      # for data sent, holds highest sequence number seen
      self.highestSeqNum = 0

      # length of that packet with the highestSeqNum,
      self.pktLenOfHighestSeqNumPacket = 0

      # IP address for the source in this flow ( one sending data and the seq num refers to )
      self.srcIP = srcIP

      # IP address for destination in this flow
      self.dstIP = dstIP


# ------------------------------------------------------------------------------
def readHandShake(pcap: PacketList) -> FlowTracking:
   """
   @purpose    Reads the first section of the pcap file

   @param      pcap: Packet List that was retrieved from the pcap file.

   @returns    FlowTracking: object for the server side
                             ( client sends the syn, server sends the synack, client sends ack )
   """
   # read syn
   p = pcap.pop(0)
   seqInit = p[TCP].seq
   srcInit = p[IP].src
   dstInit = p[IP].dst

   # read ack
   p = pcap.pop(0)
   if (p[TCP].ack != seqInit+1):
      print(string("ERROR: seq="+seqInit+", ack="+p[TCP].ack ))
   if (p[IP].src != dstInit or p[IP].dst != srcInit):
      print(string("ERROR: srcInit="+srcInit+", destInit="+dstInit+"Resp: src="+p[IP].src+",dst="+p[IP].dst ))

   seqOther = p[TCP].seq

   # read synack
   p = pcap.pop(0)
   if (p[TCP].ack != seqOther+1):
      print(string("ERROR: seq="+seqInit+", ack="+p[TCP].ack ))
   if (p[IP].src != srcInit or p[IP].dst != dstInit):
      print(string("ERROR: srcInit="+srcInit+", destInit="+dstInit+"Resp: src="+p[IP].src+",dst="+p[IP].dst ))

   return FlowTracking(seqOther, seqOther+1, dstInit, srcInit)


# ------------------------------------------------------------------------------
def isFlowEgress(p: Packet, f: FlowTracking) -> bool:
   """
   @purpose    Checks the the packet for which way the transmission is flowing

   @param[in]  p - packet
   @param[in]  f - flow represented by f (FlowTracking)

   @retval     True: if packet is in the direction of the unidirectional
   @retval     False: Otherwise
   """
   if (p[IP].src == f.srcIP):
      return True
   return False


# ------------------------------------------------------------------------------
def findMaxBytesInFlight(pcapfile: str):
   """
   @purpose    Finds the maximum amount of bytes in flight
               Assume - only one TCP session (i.e., one pair of IP address and TCP ports)
                     - the pcap starts with the 3 way handshake as the first 3 packets

   @param      pcapfile(str): file name of the pcap file.

   @returns    int: max number of bytes that were in flight ( unack ) for this stream
   """
   maxBytesInFlight = 0

   pcap = rdpcap(pcapfile)
   ft = readHandShake(pcap)

   acks_recieved = ft.ackNumReceived

   count = 0
   for packet in pcap:
      line()
      count += 1
      debugprint(f"Packet [{count}]")

      # If packet is going from server to client
      if isFlowEgress(packet, ft):
         debugprint("Server -> Client")
         next_sequence = packet[TCP].seq + get_payload_len(packet)
         cur_bytes = next_sequence - acks_recieved

         if cur_bytes > maxBytesInFlight:
            maxBytesInFlight = cur_bytes

         debugprint(f"    NEXT SEQUENCE:   {next_sequence}")
         debugprint(f"    ACKS RECIEVED:   {acks_recieved}")
         debugprint(f"    CURRENT BYTES:   {cur_bytes}")
         debugprint(f"    MAX BYTES:       {maxBytesInFlight}")
      else:
         debugprint("Client -> Server")
         # check / updates acks from client
         if packet[TCP].flags == 0x01:
            debugprint("FINISHED!")
            break
         acks_recieved = packet[TCP].ack

      # packet[TCP].show()

      debugprint("")
   return maxBytesInFlight


# ------------------------------------------------------------------------------
def get_payload_len(p: Packet) -> int:
   """
   @purpose    Find the payload length, given the packet.
               NOTE: Don't have to decode the Raw payload to get length, but do
                     to read it.

   @param[in]  p(list): list containing each packet from the pcap file

   @returns    int: payload length
   """
   # Basic check
   if not p.haslayer(TCP):
      return 0

   payload_len = 0
   payload = p[TCP].payload
   if payload:
      payload_len = len(payload.load)

   return payload_len


# ------------------------------------------------------------------------------
if __name__ == '__main__':
   # check for the expected payload lengths for a couple different packets
   pcap = rdpcap("simple-tcp-session.pcap")
   assert get_payload_len(pcap[3]) == 5

   pcap = rdpcap("out_10m_0p.pcap")
   assert get_payload_len(pcap[3]) == 122
   assert get_payload_len(pcap[5]) == 17

   # pcap is a server side capture
   maxBytesInFlight = findMaxBytesInFlight("simple-tcp-session.pcap")
   assert maxBytesInFlight == 40
   print("Max: " + str(maxBytesInFlight))
   print()

   maxBytesInFlight = findMaxBytesInFlight("out_10m_0p.pcap")
   assert maxBytesInFlight == 52128
   print("Max: " + str(maxBytesInFlight))
   print()


