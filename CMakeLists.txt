cmake_minimum_required(VERSION 3.26)
project(Noxam)

set(CMAKE_CXX_STANDARD 23)

add_executable(Noxam main.cpp
        Config/NoxamCommand.cxx
        Attack/NoxamAttakFlood.cxx
        Engine/Attack/NoxamAttackFlood.hxx
        Engine/Utils/NoxamDownloadExecute.hxx
        Utils/NoxamDownloadExecute.cxx
        Engine/Utils/NoxamGate.hxx
        Engine/Utils/NoxamGateHelper.hxx
        Utils/NoxamGateHelper.cxx
        Net/NoxamHTTP.cxx
        Engine/Net/NoxamHTTP.hxx
        Utils/NoxamKeylogger.cxx
        Engine/Utils/NoxamKeylogger.hxx
        Temperature/NoxamOSCPUChecker.cxx
        Engine/SystemX/NoxamOSCPUChecker.hxx
        Engine/SystemX/NoxamOSGetRAM.hxx
        Temperature/NoxamOSGetRAM.cxx
        Temperature/NoxamOSGPUChecker.cxx
        Engine/SystemX/NoxamOSHWidChecker.hxx
        Temperature/NoxamOSHWidChecker.cxx
        Engine/SystemX/NoxamOSNetVersionChecker.hxx
        Temperature/NoxamOSNetVersionChecker.cxx
        Temperature/NoxamOSVersionChecker.cxx
        CNC/NoxamPELSAdmin.cxx
        Engine/Utils/NoxamProccess.hxx
        Utils/NoxamProccess.cxx
        Utils/NoxamScreenshot.cxx
        Net/NoxamSocket.cxx
        Net/NoxamNetINIT.cxx
        Utils/NoxamSealer.cxx
        Crypto/NoxamStringOperations.cxx
        Crypto/NoxamURLEncoding.cxx
        Crypto/NoxamWebSafeEncryption.cxx
        Temperature/NoxamWebSiteChecker.cxx
        NoxamXor.cxx
        Engine/NoxamXor.hxx
        Engine/NoxamAgressiveOptimize.hxx
        Engine/NoxamAgressiveOptimize.hxx)
