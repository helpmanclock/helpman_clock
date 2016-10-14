#!/usr/bin/python

# helpan clock
# readconfig

# libraries
from __future__ import absolute_import, print_function, unicode_literals

import os
import sys
import time
import requests

import urllib3.contrib.pyopenssl
urllib3.contrib.pyopenssl.inject_into_urllib3()
import certifi
import urllib3
http = urllib3.PoolManager(cert_reqs='CERT_REQUIRED',ca_certs=certifi.where())

import requests.packages.urllib3
requests.packages.urllib3.disable_warnings()

# INSERISCI QUI L'URL DELLO SPREADSHEET GOOGLE
url="https://docs.google.com/spreadsheets/d/format=csv"
#print("Reading data... ")
r = requests.get(url, verify=False)
#print("Response:")
#print(r.text)
#print("Data Loaded")
configrow=r.text.split("\n")[2]
c1=configrow.split(",")[0]
c2=configrow.split(",")[1]
c3=configrow.split(",")[2]
#print("c1="+c1)
#print("c1="+c2)
#print("c1="+c3)
print(c1+"\n"+c2+"\n"+c3+"\n",end="")
