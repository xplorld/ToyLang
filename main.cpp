//
//  main.cpp
//  ToyLangSimulator
//
//  Created by Xplorld on 2016/5/16.
//  Copyright © 2016年 xplorld. All rights reserved.
//
#include "Runtime.h"
//
//Instance * print(RuntimeObject * receiver, std::vector<Instance *>args) {
//    printf("I am %s, I called Printer:print\n",receiver->receiver->isa->name.c_str());
//    return receiver->receiver;
//}
//
//Instance * derived_print(RuntimeObject * receiver, std::vector<Instance *>args) {
//    printf("I am %s, I called DerivedPrinter:print\n",receiver->receiver->isa->name.c_str());
//    receiver->msg_send_super("print", args);
//    return receiver->receiver;
//}
//
//Instance * derived_2_print(RuntimeObject * receiver, std::vector<Instance *>args) {
//    printf("I am %s, I called Derived2Printer:print\n",receiver->receiver->isa->name.c_str());
//    receiver->msg_send_super("print", args);
//    return receiver->receiver;
//}
//
//
//int main(int argc, const char * argv[]) {
//    
//    Class *Printer = Class::createClass("Printer", nullptr);
//    Class *DerivedPrinter = Class::createClass("DerivedPrinter", Printer);
//    Class *Derived2Printer = Class::createClass("Derived2Printer", DerivedPrinter);
//    Printer->appendMethod("print", print);
//    DerivedPrinter->appendMethod("print", derived_print);
//    Derived2Printer->appendMethod("print", derived_2_print);
//    Instance *printer = Derived2Printer->newInstance();
//    printer->msg_send("print", std::vector<Instance*>());
//    return 0;
//}

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
