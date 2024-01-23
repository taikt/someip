#include "Promise.h"
#include "Dispatcher.h"
#include "requestMsg.pb.h"
#include "E03MethodsServiceHandler.h"
using namespace kt;

class RequestManager {
public:
    /*
    RequestManager& instance(std::shared_ptr<Dispatcher>& Executor_)
    {
        static RequestManager(Executor_) instance;
        return instance;
    }
    */
    static RequestManager* GetInstance(std::shared_ptr<Dispatcher>& Executor_)
    {
        if(singleton_==nullptr){
            singleton_ = new RequestManager(Executor_);
        }
        return singleton_;
    }

    RequestManager(std::shared_ptr<Dispatcher>& Executor_) 
    : m_Executor(Executor_)
    {
    }

   //Future<ResponseMsg> sendRequest(int32_t _x1, std::string _x2);
   Promise<ResponseMsg> handleRequestAsync(int32_t _x1, std::string _x2);
   //void doRequest(int32_t _x1, std::string _x2, const shared_ptr<Promise<ResponseMsg>>& promise);
   void doRequest(int32_t _x1, std::string _x2, Promise<ResponseMsg>& promise);

private:
    std::shared_ptr<Dispatcher> m_Executor;
    static RequestManager* singleton_;
};