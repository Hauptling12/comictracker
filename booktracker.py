#!/bin/python3
import pandas as pd
import os
import json
import sys
filename = '/home/' + os.environ["USER"] + '/.local/share/comictracker/book.json'
if sys.argv[1] == "-h":
    print("-a   add media")
    print("-l   list media")
    print("-h   display this help")
if sys.argv[1] == "-l":
    print(pd.read_json(filename))
if sys.argv[1] == "-a":
    title = input("title: ")
    aut = input("author: ")
    date = input("date published: ")
    wat = input("read yes or no: ")
    d = {}
    d['title'] = title
    d['publisher'] = aut
    d['date'] = date
    d['read'] = wat
# Read file contents
    with open(filename, "r") as file:
         data = json.load(file)

 # Update json object
    data.append(d)

 # Write json file
    with open(filename, "w") as file:
        json.dump(data, file)
