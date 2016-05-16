//
//  Runtime.h
//  ToyLangSimulator
//
//  Created by Xplorld on 2016/5/16.
//  Copyright © 2016年 xplorld. All rights reserved.
//

#ifndef Runtime_h
#define Runtime_h


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <stack>
#include <vector>
#include <list>


class Class;
class Method;
class ClassMember;
class Instance;
class RuntimeObject;

typedef Instance * (*methodPtr_t)(RuntimeObject *, std::vector<Instance *>args);


class Method {
public:
    std::string name;
    methodPtr_t ptr;
};


class ClassMember {
public:
    Class *isa;
    std::string name;
};



class RuntimeObject {
public:
    Instance *receiver;
    Class *cls;
    Instance *msg_send(std::string Signature,std::vector<Instance *>args);
    Instance *msg_send_super(std::string Signature,std::vector<Instance *>args);
    Instance *method_call(Method *method,std::vector<Instance *>args);
};

class Instance {
public:
    Class *isa;
    std::vector<struct Instance> members;
    Instance *msg_send(std::string Signature,std::vector<Instance *>args);
    Instance *msg_send_super(std::string Signature,std::vector<Instance *>args);
};


class Class {
public:
    bool finalized = false;
    
    std::string name;
    struct Class *parent;
    
    std::vector<struct ClassMember> members;
    std::list<struct Method> methods;
    
    static Class * createClass(std::string name, Class *parent) ;
    
    void addMember(ClassMember *member) ;
    void appendMethod(std::string name, methodPtr_t impl) ;
    void finalize() ;
    
    Instance * newInstance() ;
    
    Method *msg_resove(std::string signature) ;
};



#endif /* Runtime_h */
