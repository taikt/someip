// Copyright (C) 2014-2019 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "E03MethodsStubImpl.hpp"

#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#include "requestMsg.pb.h"
#include <thread>

#include<stdio.h>

using namespace data; // important to include namespace in protoc file to understand requestMsg

using namespace v1_2::commonapi::examples;

extern Promise<ResponseMsg> mypromise;
//extern RequestManager* RequestManager::singleton_;


E03MethodsStubImpl::E03MethodsStubImpl(std::shared_ptr<Dispatcher>& m_Executor_):
m_Executor(m_Executor_)
{
    cnt = 0;
}

E03MethodsStubImpl::~E03MethodsStubImpl() {
}

void E03MethodsStubImpl::incCounter() {
    cnt++;
    fireMyStatusEvent((int32_t) cnt);
    std::cout << "New counter value = " << cnt << "!" << std::endl;
}


void E03MethodsStubImpl::foo(const std::shared_ptr<CommonAPI::ClientId> _client,
                int32_t _x1, std::string _x2,
                fooReply_t _reply) {

    pid_t tid = syscall(__NR_gettid);
    std::cout << "TID:"<<tid<<", foo called, setting new values." << std::endl;

    /*
    // normal method:
    // binder request synchronosly and wait result

    E03Methods::stdErrorTypeEnum methodError = E03Methods::stdErrorTypeEnum::NO_FAULT;    
    int32_t y1 = 42;
    std::string y2 = "xyz";
    _reply(methodError, y1, y2);
    */

    // Asynchronous method using promise
    RequestManager::GetInstance(m_Executor)->handleRequestAsync(_x1, _x2)
        .then(m_Executor, [_reply](const ResponseMsg& resp) {
            auto y1 = resp.y1;
            auto y2 = resp.y2; 
            auto methodError = resp.methodError;
        
            pid_t tid = syscall(__NR_gettid);
            std::cout<<"TID: "<<tid<<", Send response to client: y1="<<y1<<", y2="<<y2<<"\n";
    
            _reply(methodError, y1, y2);
        });


    std::cout <<"exit call\n";
}
