#ifndef MYHANDLER_H
#define MYHANDLER_H
#include "Promise.h"
#include "Dispatcher.h"
#include "Message.h"
#include <v1/commonapi/examples/E03Methods.hpp>
#include "E03MethodsStubImpl.hpp"

using namespace v1_2::commonapi::examples;

#define START_REQUEST1 1

struct ResponseMsg {
    int32_t y1;
    std::string y2;
    E03Methods::stdErrorTypeEnum methodError;
};
class myHandler : public Handler {
public:
    myHandler(){};
    void handleMessage(std::shared_ptr<Message>& msg);
};



#endif