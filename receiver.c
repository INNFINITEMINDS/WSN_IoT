sign = 1;
        raw = tmp102_read_temp_raw();  // Reading from the sensor
 
        absraw = raw;
        if (raw < 0) { // Perform 2C's if sensor returned negative data
          absraw = (raw ^ 0xFFFF) + 1;
          sign = -1;
        }
	tempint  = (absraw >>  * sign;
        tempfrac = ((absraw>>4) % 16) * 625; // Info in 1/10000 of degree
        minus = ((tempint == 0) & (sign == -1)) ? '-'  : ' ' ;

    if(addr != NULL) {
      static unsigned int message_number;
      char buf[30];

      printf("Sending unicast temperature value to ");
      uip_debug_ipaddr_print(addr);
      printf(" message count:%d\n", message_number);
      sprintf(buf, "%c%d.%d\n", minus, tempint, tempfrac);
      message_number++;
      simple_udp_sendto(&unicast_connection, buf, strlen(buf) + 1, addr);
    } else {
      printf("Service %d not found\n", SERVICE_ID);
    }
