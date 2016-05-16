# ToyLang

## Introduction

A simple &amp; naive conceptual-quasi-pseudo-primitive programming language.

## Features

- Full Object-oriented, i.e. cannot write pure function without a wrapper class
- Dynamic, objects remembers their Class
- Dynamic, can add methods and members to Classes at any time
- message sending, like Objective-C

## Why conceptual?

- Currently no front-end (maybe never will)
- No syntax (You can imagine one in your brain)

## Why quasi?

- Lives on C++
- Can interact with C/C++ seamlessly

## Why pseudo?

Come on, a language in less than 100 lines of implementation can *not* be considered as a serious language.

## Why Primitive? (TODO)

Currently not provided, but someday will (if the whole repo not abandoned)

- member access
- standard library
	- array
	- primitive types, like `int`, `bool` etc
	- `string`
- multiple dispatch
- `malloc` instead of `new` to be independent from C++

## How To Write

Conceptual (remember, there is no syntax now):

		class Printer {
			(instancetype) print() {
				printf("hello world!, I am %s\n",typeof(this));
			}
		}

Code:
	
		#include "Runtime.h"
		Instance * print(RuntimeObject * receiver, std::vector<Instance *>args) {
		    printf("hello world!, I am %s\n",receiver->receiver->isa->name.c_str());
		    return receiver->receiver;
		}

		int main(int argc, const char * argv[]) {
		    Class *Printer = Class::createClass("Printer", nullptr);
		    Printer->appendMethod("print", print);
		    Instance *printer = Printer->newInstance();
		    printer->msg_send("print", std::vector<Instance*>());
		    return 0;
		}

Output:

		hello world!, I am Printer


## Lisence

MIT.

Pull request welcome!











