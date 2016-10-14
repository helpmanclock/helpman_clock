#!/usr/bin/python

# bluetooth manager

# libraries
from __future__ import absolute_import, print_function, unicode_literals
from optparse import OptionParser, make_option

import os
import sys
import socket
import uuid
import dbus
import dbus.service
import dbus.mainloop.glib

try:
  from gi.repository import GObject
except ImportError:
  import gobject as GObject

import mraa
import time

# setup gpio
x = mraa.Gpio(13)
x.dir(mraa.DIR_OUT)


def readSock(sock):

    print("<<<")
    buff=""
    while True:
            c=sock.recv(1)
            if not c:
		print("NO DATA")
		break
            if c=='\r':
		c=sock.recv(1)
                return buff
            if c=='\n':
                return buff
            else:
                buff+=c

class Profile(dbus.service.Object):
    fd = -1
    @dbus.service.method("org.bluez.Profile1",
    				in_signature="", out_signature="")
    def Release(self):
    	print("Release")
    	mainloop.quit()

    @dbus.service.method("org.bluez.Profile1",
    				in_signature="", out_signature="")

    def Cancel(self):
    	print("Cancel")


    @dbus.service.method("org.bluez.Profile1",
    			in_signature="oha{sv}", out_signature="")

    def NewConnection(self, path, fd, properties):
        self.fd = fd.take()
        print("NewConnection(%s, %d)" % (path, self.fd))

        server_sock = socket.fromfd(self.fd, socket.AF_UNIX, socket.SOCK_STREAM)
        server_sock.setblocking(1)
        server_sock.settimeout(1)


        while True:
           try:
		print("Sending time...")
		configdata=time.strftime("%H:%M")
		print(configdata+"\n",end="")
                server_sock.send("D\n"+configdata+"\n")
                time.sleep(0.5)

            	data = readSock(server_sock)
                print("Received: " + data)
                time.sleep(1)

                print("Requesting pills to release...")
                server_sock.send("P\n")
                time.sleep(0.1)

                s1 = readSock(server_sock)
                s2 = readSock(server_sock)
                s3 = readSock(server_sock)
                print("Received: ")
                print("  s1= "+s1)
                print("  s2= "+s2)
                print("  s3= "+s3)

		if s1 == '1':
			print("Releasing Pill 1")
			os.system(os.getcwd() + "/py-servo/servo.py 1")
		if s2 == '1':
			print("Releasing Pill 2")
			os.system(os.getcwd() + "/py-servo/servo.py 2")
		if s3 == '1' :
			print("Releasing Pill 3")
			os.system(os.getcwd() + "/py-servo/servo.py 3")

                time.sleep(1)

                print("Requesting heartbeat...")
                server_sock.send("H\n")
                time.sleep(0.1)

                data = readSock(server_sock)
                print("Received: " + data)
		os.system(os.getcwd() + "/savedata.py '" + data + "'" )
                time.sleep(1)

                print("Reading config...")
		configdata = os.popen(os.getcwd() + "/readconfig.py").read()
#		configdata = "13:00\n14:00\n-"

		print("{")
		print(configdata)
		print("}")
                
		print("Sending config...")
                server_sock.send("C\n"+configdata)
#                server_sock.send("C\n13:00\n14:00\n-")

            	#server_sock.send("13:00\n")
            	#server_sock.send("13:00\n")
            	#server_sock.send("-\n")

                time.sleep(0.5)
            	data = readSock(server_sock)
                print("Received: " + data)
                time.sleep(1)

           except IOError:
		    print("IOError")
		    print("Clear buffer: ")
		    #print(readSock(server_sock))
		
		    pass

        server_sock.close()
        print("all done")

	@dbus.service.method("org.bluez.Profile1",
				in_signature="o", out_signature="")

	def RequestDisconnection(self, path):
		print("RequestDisconnection(%s)" % (path))

		if (self.fd > 0):
			os.close(self.fd)
			self.fd = -1

# main loop
if __name__ == '__main__':

	print("Waiting for connections...")

	dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)
	bus = dbus.SystemBus()
	manager = dbus.Interface(bus.get_object("org.bluez",
				"/org/bluez"), "org.bluez.ProfileManager1")

	option_list = [
			make_option("-C", "--channel", action="store",
					type="int", dest="channel",
					default=None),
			]


	parser = OptionParser(option_list=option_list)

	(options, args) = parser.parse_args()

	options.uuid = "1101"
#	options.uuid = "00001101-0000-1000-8000-00805f9b34fb"
	options.psm = "3"
	options.role = "slave"
	options.name = "Edison SPP Loopback"
	options.service = "spp char loopback"
	options.path = "/foo/bar/profile"
	options.auto_connect = True
	options.record = ""


	profile = Profile(bus, options.path)

	mainloop = GObject.MainLoop()
	opts = {
			"AutoConnect" :	options.auto_connect,
		}


	if (options.name):
		opts["Name"] = options.name

	if (options.role):
		opts["Role"] = options.role

	if (options.psm is not None):
		opts["PSM"] = dbus.UInt16(options.psm)

	if (options.channel is not None):
		opts["Channel"] = dbus.UInt16(options.channel)

	if (options.record):
		opts["ServiceRecord"] = options.record

	if (options.service):
		opts["Service"] = options.service

	if not options.uuid:
		options.uuid = str(uuid.uuid4())

	manager.RegisterProfile(options.path, options.uuid, opts)

	mainloop.run()
