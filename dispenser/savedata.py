#!/usr/bin/python

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

data=sys.argv[1]
url="https://docs.google.com/forms/d/e/1FAIpQLSe8ORN_2OexWWgcVet520kGFduTgfkUVTNScw3mE6BLuQ1veg/formResponse"
payload={"entry.1755718560" : data }
print("Saving data... " + data)
r = requests.post(url, data=payload, verify=False)
print("Response:")
#print(r.text)
print("Data Saved")
