import serial
import http.client, urllib.request
import time

#from BrickPi import *   #import BrickPi.py file to use BrickPi operations
import math

#_a = [0.003357042,         0.003354017,        0.0033530481,       0.0033536166]
#_b = [0.00025214848,       0.00025617244,      0.00025420230,      0.000253772]
#_c = [0.0000033743283,     0.0000021400943,    0.0000011431163,    0.00000085433271]
#_d = [-0.000000064957311, -0.000000072405219, -0.000000069383563, -0.000000087912262]


 #       BrickPiSetup()  # setup the serial port for communication
  #      BrickPi.SensorType[PORT_3] = TYPE_SENSOR_RAW         # specifying the thermometer as analog sensor
   #     if not BrickPiSetupSensors() :
    #        while True :
     #           if not BrickPiUpdateValues() :               # Updates the sensor and motor values
      #                  val = BrickPi.Sensor[PORT_3]
       #                 RtRt25 = (float)(val) / (1023 - val)
        #                lnRtRt25 = math.log(RtRt25)
         #               if (RtRt25 > 3.277) :
          #                      i = 0
           #             elif (RtRt25 > 0.3599) :
            #                    i = 1
             #           elif (RtRt25 > 0.06816) :
              #                  i = 2
               #         else :
                #                i = 3		
                 #       temp =  1.0 / (_a[i] + (_b[i] * lnRtRt25) + (_c[i] * lnRtRt25 * lnRtRt25) + (_d[i] * lnRtRt25 * lnRtRt25 * lnRtRt25))
                  #      temp-=273                               
                        #params = urllib.urlencode({'Field 1': line, 'key':'HO9I7ND6JCOQS96I'})     # use your API key generated in the thingspeak channels for the value of 'key'
                        # temp is the data you will be sending to the thingspeak channel for plotting the graph. You can add more than one channel and plot more graphs
                        #headers = {"Content-typZZe": "application/x-www-form-urlencoded","Accept": "text/plain"}
                        #conn = httplib.HTTPConnection("api.thingspeak.com:80")                
                        #try:
                         #       conn.request("POST", "/update", params, headers)
                          #      response = conn.getresponse()
                           #     print (line)
                            #    print (response.status, response.reason)
                             #   data = response.read()
                              #  conn.close()
                        #except:
                         #       print ("connection failed")
                #break
#sleep for 16 seconds (api limit of 15 secs)
if __name__ == "__main__":
        while True:
            if __name__ == '__main__':
                ser = serial.Serial('/dev/ttyUSB1', 9600, timeout=1)
                ser.reset_input_buffer()
       # while True:
            if ser.in_waiting > 0:
                line = ser.readline().decode('utf-8').rstrip()
                print(line)
                
                
                
                params = urllib.parse.urlencode({'field1': line, 'key':'HO9I7ND6JCOQS96I'})
                #params = urllib.parse.urlencode({'field2': line, 'key':'HO9I7ND6JCOQS96I'}) 
                # use your API key generated in the thingspeak channels for the value of 'key'
                        # temp is the+ data you will be sending to the thingspeak channel for plotting the graph. You can add more than one channel and plot more graphs
                headers = {"Content-typZZe": "application/x-www-form-urlencoded","Accept": "text/plain"}
                conn = http.client.HTTPConnection("api.thingspeak.com:80")                
                
                conn.request("POST", "/update", params, headers)
                response = conn.getresponse()
                print (line)
                print (response.status, response.reason)
                data = response.read()
                conn.close()
                
                    
             
                time.sleep(16) 
