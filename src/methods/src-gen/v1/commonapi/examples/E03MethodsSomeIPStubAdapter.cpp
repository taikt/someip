/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/commonapi/examples/E03MethodsSomeIPStubAdapter.hpp>
#include <v1/commonapi/examples/E03Methods.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include "debug.hpp"

namespace v1 {
namespace commonapi {
namespace examples {

std::shared_ptr<CommonAPI::SomeIP::StubAdapter> createE03MethodsSomeIPStubAdapter(
                   const CommonAPI::SomeIP::Address &_address,
                   const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                   const std::shared_ptr<CommonAPI::StubBase> &_stub) {
    DEBUG_MSG();
    return std::make_shared< E03MethodsSomeIPStubAdapter<::v1::commonapi::examples::E03MethodsStub>>(_address, _connection, _stub);
}

void initializeE03MethodsSomeIPStubAdapter() {
    DEBUG_MSG();
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.examples.E03Methods:v1_2:commonapi.examples.Methods",
         0x1234, 0x5678, 1, 2);
    CommonAPI::SomeIP::Factory::get()->registerStubAdapterCreateMethod(
        "commonapi.examples.E03Methods:v1_2",
        &createE03MethodsSomeIPStubAdapter);
}

INITIALIZER(registerE03MethodsSomeIPStubAdapter) {
    DEBUG_MSG();
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeE03MethodsSomeIPStubAdapter);
}

} // namespace examples
} // namespace commonapi
} // namespace v1
