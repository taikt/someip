// Copyright (C) 2014-2019 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "E03MethodsStubImpl.hpp"
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#include "requestMsg.pb.h"

using namespace data; // important to include namespace in protoc file to understand requestMsg

using namespace v1_2::commonapi::examples;

extern Promise<ResponseMsg> mypromise;
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

/*
Future<ResponseMsg> E03MethodsStubImpl::sendRequest(int32_t _x1, std::string _x2) {
    Promise<ResponseMsg> promise;
    mypromise = promise;

    std::shared_ptr<Message> msg = std::make_shared<Message>(START_REQUEST1);

    requestMsg payload;
    payload.set_x1(_x1);
    payload.set_x2(_x2);
    payload.SerializeToString(&msg->payload);

    m_Executor->deliverMessage(msg);

    return promise.get_future();
}
*/

Promise<ResponseMsg> E03MethodsStubImpl::sendRequest(int32_t _x1, std::string _x2) {
    Promise<ResponseMsg> promise;
    mypromise = promise;

    std::shared_ptr<Message> msg = std::make_shared<Message>(START_REQUEST1);

    requestMsg payload;
    payload.set_x1(_x1);
    payload.set_x2(_x2);
    payload.SerializeToString(&msg->payload);

    m_Executor->deliverMessage(msg);

    return promise;
}

void E03MethodsStubImpl::foo(const std::shared_ptr<CommonAPI::ClientId> _client,
                int32_t _x1, std::string _x2,
                fooReply_t _reply) {
    pid_t x = syscall(__NR_gettid);

    std::cout <<"TID:" << x <<"\n";

    std::cout << "foo called, setting new values." << std::endl;

    E03Methods::stdErrorTypeEnum methodError = E03Methods::stdErrorTypeEnum::NO_FAULT;

    std::cout << "foo process in 3 sec before return" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    /*
	std::cout <<"TID:" << x <<"\n";
    std::cout << "foo process done" << std::endl;
    int32_t y1 = 42;
    std::string y2 = "xyz";
    _reply(methodError, y1, y2);
    */

    sendRequest(_x1, _x2).then(m_Executor, [_reply](const ResponseMsg& resp){
        auto y1 = resp.y1;
        auto y2 = resp.y2;
        auto methodError = resp.methodError;
        pid_t x = syscall(__NR_gettid);
        std::cout <<"TID:" << x <<"\n";

        std::cout<<"[thread id]="<<x<<", send response to client later\n";
        _reply(methodError, y1, y2);
    });

    std::cout <<"back to client first\n";
}
