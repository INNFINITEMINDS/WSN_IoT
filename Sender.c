static void
receiver(struct simple_udp_connection *c,
         const uip_ipaddr_t *sender_addr,
         uint16_t sender_port,
         const uip_ipaddr_t *receiver_addr,
         uint16_t receiver_port,
         const uint8_t *data,
         uint16_t datalen)
{
  /*
  printf("Reciver node : '");
  uip_debug_ipaddr_print(receiver_addr);
  printf("' received message from transmitter node : '");
  uip_debug_ipaddr_print(sender_addr);
  printf("' on port %d with length : %d\n",
         receiver_port, datalen);
  printf("Temprature (°C) : %s",data);
  */
  printf("%s",data);
}

/* Sender part 2*/
import serial
import time

ser = serial.Serial(
    port='/dev/ttyUSB0',\
    baudrate=115200,\
    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
        timeout=0)

print("connected to: " + ser.portstr)

#this will store the line
#line = []
temp_str = ""

while True:
    for c in ser.read():
        if c == ' ':
	   #line = line
	   temp_str = temp_str
	#to cast str to float use float(temp_str)
        elif c == '\n':
            print("Temperature: ",float(temp_str))
	    print("Time: ",time.strftime("%H:%M:%S"))
	    temp_str = ""
	else:
	    temp_str+=str(c)

ser.close()
