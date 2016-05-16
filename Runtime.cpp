//
//  Runtime.cpp
//  ToyLangSimulator
//
//  Created by Xplorld on 2016/5/16.
//  Copyright © 2016年 xplorld. All rights reserved.
//

#include "Runtime.h"


Instance *Instance::msg_send(std::string Signature,std::vector<Instance *>args) {
    return ((RuntimeObject){this,isa}).msg_send(Signature, args);
}
Instance *Instance::msg_send_super(std::string Signature,std::vector<Instance *>args) {
    return ((RuntimeObject){this,isa->parent}).msg_send(Signature, args);
}

Instance *RuntimeObject::msg_send(std::string signature,std::vector<Instance *>args) {
    Method *method = cls->msg_resove(signature);
    if (method) {
        return method_call(method, args);
    }
    return nullptr;
}

Instance *RuntimeObject::msg_send_super(std::string Signature,std::vector<Instance *>args) {
    return ((RuntimeObject){this->receiver,this->cls->parent}).msg_send(Signature, args);
}

Instance *RuntimeObject::method_call(Method *method, std::vector<Instance *> args) {
    return method->ptr(this,args);
}


Class * Class::createClass(std::string name, Class *parent) {
    Class *newClass = new Class;
    newClass->finalized = 0;
    newClass->parent = parent;
    newClass->name = name;
    return newClass;
}

void Class::addMember(ClassMember *member) {
    if (finalized) {
        fprintf(stderr, "error: try to append member %s to class %s who has finallized\n",member->name.c_str(),name.c_str());
    } else {
        members.push_back(*member);
    }
}

void Class::appendMethod(std::string name, methodPtr_t impl) {
    
    if (finalized) {
        fprintf(stderr, "error: try to append method %s to class %s who has finallized\n",name.c_str(),this->name.c_str());
    } else {
        Method method;
        method.name = name;
        method.ptr = impl;
        methods.push_back(method);
    }
}
void Class::finalize() {
    finalized = true;
}
Instance * Class::newInstance() {
    Instance *obj = new Instance;
    obj->isa = this;
    return obj;
}

Method * Class::msg_resove(std::string signature) {
    Class *cls = this;
    while (cls) {
        auto &methods = cls->methods;
        for (auto iter = methods.begin(); iter != methods.end(); ++iter) {
            if (iter->name == signature) {
                return &*iter;
            }
        }
        cls = cls->parent;
    }
    return nullptr;
}



