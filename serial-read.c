import plotly 
import certifi
import urllib3

http = urllib3.PoolManager(cert_reqs='CERT_REQUIRED',ca_certs=certifi.where())
plotly.tools.set_credentials_file(username='dinsap', api_key='0l2j9xmxa3')

import numpy as np 
import plotly.plotly as py  
import plotly.tools as tls   
import plotly.graph_objs as go

while True:

	for c in ser.read():
		if c == ' ':
		   #line = line
		   temp_str = temp_str
		#to cast str to float use float(temp_str)
		elif c == '\n':
		    x = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')
		    y = temp_str
		    print("Temperature: "+ temp_str)
		    print("Time: ",time.strftime("%H:%M:%S"))
		    temp_str = ""
		    # Send data to your plot
	    	    s.write(dict(x=x, y=y))  
	    
	    	    #     Write numbers to stream to append current data on plot,
	    	    #     write lists to overwrite existing data on plot
		    
	    	    time.sleep(2)  # plot a point every second    
		    #line = []
		    #break
		else:
		    #line.append(c)
		    temp_str+=str(c)
 
# Close the stream when done plotting
s.close() 

# Embed never-ending time series streaming plot
tls.embed('streaming-demos','12')
