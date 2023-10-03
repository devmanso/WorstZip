# WorstZip, the most reliable and efficient file compression program

* DISCLAIMER: please don't ever use this ever. I am not responsible for whatever happens to your computer as a result of this program
* This software is liscensed under MIT Liscense, see LICENSE in this repo

## Features

* gaurenteed to reduce file size by at least 10%
* ~~could also corrupt your files~~
* pretty fast (see benchmarks)

## How to use

* Windows
```./worstzip FILE.EXT```
* Linux/MacOS/other
```worstzip FILE.EXT```

## Benchmark (silesia.zip | Windows 10)

* 1s 71ms
* 65585 kb down to 44390 kb

## My system's specs

* I7-9750H @4.2 GHz 6 cores 12 threads
* Kingston SQ500S37 480Gb SATA 3

## How to compile

* compiled with a C99 compiler
```gcc -o worstzip -I./headers main.c```
