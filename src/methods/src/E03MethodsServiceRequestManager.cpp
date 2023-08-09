#include "E03MethodsServiceRequestManager.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>


RequestManager* RequestManager::singleton_= nullptr;;


void RequestManager::doRequest(int32_t _x1, std::string _x2, Promise<ResponseMsg>& promise) {
    pid_t tid = syscall(__NR_gettid);
    std::cout <<"doRequest TID:" << tid <<"\n";
   
     // call binder request here and get result

    ResponseMsg resp;
    resp.y1 = _x1 + 1;
    resp.y2 = _x2 + ", Tai added";
    resp.methodError = E03Methods::stdErrorTypeEnum::NO_FAULT;
    

    cout<<"set promise\n";
    promise.set_value(resp);   
}

Promise<ResponseMsg> RequestManager::handleRequestAsync(int32_t _x1, std::string _x2) {
    //const auto promise = std::make_shared<Promise<ResponseMsg>>();
    auto promise = Promise<ResponseMsg>();
    m_Executor->deliverTask([this,promise,_x1,_x2]() mutable{
        doRequest(_x1,_x2,promise);
    });
  
    return promise;
}