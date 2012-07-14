sob
===

(stream output benchmarker)    
benchmarking tool for unix pipelines

## Installation

	git clone git://github.com/thinkjson/sob.git
	cd sob
	make
	make install

## Usage

	sob [identifier]

## Example

	$ head -c 9999999 /dev/urandom | od | sob od | grep 2 | sob grep >/dev/null
	od		100K	2881K lines/s	201M/s	7.057190M
	grep	100K	2664K lines/s	186M/s	7.057190M
	od		200K	2918K lines/s	204M/s	7.122925M
	grep	200K	2681K lines/s	187M/s	7.123149M
	od		300K	2876K lines/s	201M/s	7.152557M
	grep	300K	2623K lines/s	183M/s	7.152557M
	od		400K	2900K lines/s	203M/s	7.152557M
	grep	400K	2669K lines/s	186M/s	7.152557M
	od		500K	2936K lines/s	205M/s	7.152557M
	grep	500K	2899K lines/s	202M/s	7.152557M
	od		600K	2941K lines/s	205M/s	7.152557M
	grep	600K	2766K lines/s	193M/s	7.152557M
	od		OVERALL	2862K lines/s	204M/s	44.578491M
	grep	OVERALL	2670K lines/s	190M/s	44.512978M

## The MIT License (MIT)
Copyright (c) 2012 Mark Cahill

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.