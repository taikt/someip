/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_EXAMPLES_E03_Methods_PROXY_HPP_
#define V1_COMMONAPI_EXAMPLES_E03_Methods_PROXY_HPP_

#include <v1/commonapi/examples/E03MethodsProxyBase.hpp>


#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif


#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {
namespace examples {

template <typename ... _AttributeExtensions>
class E03MethodsProxy
    : virtual public E03Methods,
      virtual public E03MethodsProxyBase,
      virtual public _AttributeExtensions... {
public:
    E03MethodsProxy(std::shared_ptr<CommonAPI::Proxy> delegate);
    ~E03MethodsProxy();

    typedef E03Methods InterfaceType;


    /**
     * Returns the CommonAPI address of the remote partner this proxy communicates with.
     */
    virtual const CommonAPI::Address &getAddress() const;

    /**
     * Returns true if the remote partner for this proxy is currently known to be available.
     */
    virtual bool isAvailable() const;

    /**
     * Returns true if the remote partner for this proxy is available.
     */
    virtual bool isAvailableBlocking() const;

    /**
     * Returns the wrapper class that is used to (de-)register for notifications about
     * the availability of the remote partner of this proxy.
     */
    virtual CommonAPI::ProxyStatusEvent& getProxyStatusEvent();

    /**
     * Returns the wrapper class that is used to access version information of the remote
     * partner of this proxy.
     */
    virtual CommonAPI::InterfaceVersionAttribute& getInterfaceVersionAttribute();

    virtual std::future<void> getCompletionFuture();

    /**
     * Calls foo with synchronous semantics.
     *
     * All const parameters are input parameters to this method.
     * All non-const parameters will be filled with the returned values.
     * The CallStatus will be filled when the method returns and indicate either
     * "SUCCESS" or which type of error has occurred. In case of an error, ONLY the CallStatus
     * will be set.
     */
    virtual void foo(int32_t _x1, std::string _x2, CommonAPI::CallStatus &_internalCallStatus, E03Methods::stdErrorTypeEnum &_error, int32_t &_y1, std::string &_y2, const CommonAPI::CallInfo *_info = nullptr);
    /**
     * Calls foo with asynchronous semantics.
     *
     * The provided callback will be called when the reply to this call arrives or
     * an error occurs during the call. The CallStatus will indicate either "SUCCESS"
     * or which type of error has occurred. In case of any error, ONLY the CallStatus
     * will have a defined value.
     * The std::future returned by this method will be fulfilled at arrival of the reply.
     * It will provide the same value for CallStatus as will be handed to the callback.
     */
    virtual std::future<CommonAPI::CallStatus> fooAsync(const int32_t &_x1, const std::string &_x2, FooAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr);
    /**
     * Returns the wrapper class that provides access to the broadcast myStatus.
     */
    virtual MyStatusEvent& getMyStatusEvent() {
        return delegate_->getMyStatusEvent();
    }



 private:
    std::shared_ptr< E03MethodsProxyBase> delegate_;
};

typedef E03MethodsProxy<> E03MethodsProxyDefault;


//
// E03MethodsProxy Implementation
//
template <typename ... _AttributeExtensions>
E03MethodsProxy<_AttributeExtensions...>::E03MethodsProxy(std::shared_ptr<CommonAPI::Proxy> delegate):
        _AttributeExtensions(*(std::dynamic_pointer_cast< E03MethodsProxyBase>(delegate)))...,
        delegate_(std::dynamic_pointer_cast< E03MethodsProxyBase>(delegate)) {
}

template <typename ... _AttributeExtensions>
E03MethodsProxy<_AttributeExtensions...>::~E03MethodsProxy() {
}

template <typename ... _AttributeExtensions>
void E03MethodsProxy<_AttributeExtensions...>::foo(int32_t _x1, std::string _x2, CommonAPI::CallStatus &_internalCallStatus, E03Methods::stdErrorTypeEnum &_error, int32_t &_y1, std::string &_y2, const CommonAPI::CallInfo *_info) {
    delegate_->foo(_x1, _x2, _internalCallStatus, _error, _y1, _y2, _info);
}

template <typename ... _AttributeExtensions>
std::future<CommonAPI::CallStatus> E03MethodsProxy<_AttributeExtensions...>::fooAsync(const int32_t &_x1, const std::string &_x2, FooAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
    return delegate_->fooAsync(_x1, _x2, _callback, _info);
}

template <typename ... _AttributeExtensions>
const CommonAPI::Address &E03MethodsProxy<_AttributeExtensions...>::getAddress() const {
    return delegate_->getAddress();
}

template <typename ... _AttributeExtensions>
bool E03MethodsProxy<_AttributeExtensions...>::isAvailable() const {
    return delegate_->isAvailable();
}

template <typename ... _AttributeExtensions>
bool E03MethodsProxy<_AttributeExtensions...>::isAvailableBlocking() const {
    return delegate_->isAvailableBlocking();
}

template <typename ... _AttributeExtensions>
CommonAPI::ProxyStatusEvent& E03MethodsProxy<_AttributeExtensions...>::getProxyStatusEvent() {
    return delegate_->getProxyStatusEvent();
}

template <typename ... _AttributeExtensions>
CommonAPI::InterfaceVersionAttribute& E03MethodsProxy<_AttributeExtensions...>::getInterfaceVersionAttribute() {
    return delegate_->getInterfaceVersionAttribute();
}


template <typename ... _AttributeExtensions>
std::future<void> E03MethodsProxy<_AttributeExtensions...>::getCompletionFuture() {
    return delegate_->getCompletionFuture();
}

} // namespace examples
} // namespace commonapi
} // namespace v1



// Compatibility
namespace v1_2 = v1;

#endif // V1_COMMONAPI_EXAMPLES_E03_Methods_PROXY_HPP_
