#include "E03MethodsServiceHandler.h"
#include "requestMsg.pb.h"

using namespace data;

Promise<ResponseMsg> mypromise;

void E03MethodsServiceHandler::handleMessage(std::shared_ptr<Message>& msg){
    std::thread::id id_ = std::this_thread::get_id();
    switch (msg->id) {
        case START_REQUEST1:
            {
                requestMsg req;
                req.ParseFromString(msg->payload);

                cout<<"receive requestMgr: x1="<<req.x1()<<", x2="<<req.x2()<<"\n";

                ResponseMsg resp;
                resp.y1 = req.x1() + 1;
                resp.y2 = req.x2() + ", Tai added";
                resp.methodError = E03Methods::stdErrorTypeEnum::NO_FAULT;
                
                mypromise.set_value(resp); 
            }
            break;

        default:
            cout<<"[thread ID] ="<<id_<<", task: id="<<msg->id<<", value:"<<msg->payload<<"\n";
            break;
    }  
    
};