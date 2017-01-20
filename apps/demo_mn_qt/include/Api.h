/**
********************************************************************************
\file   Api.h

\brief  Header file for openPOWERLINK API class

This file contains the definitions of the openPOWERLINK API class.
*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2017, Bernecker+Rainer Industrie-Elektronik Ges.m.b.H. (B&R)
Copyright (c) 2013, SYSTEC electronic GmbH
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holders nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
------------------------------------------------------------------------------*/
#ifndef _INC_demo_Api_H_
#define _INC_demo_Api_H_

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
#include <QObject>
#include <QString>

#include <oplk/oplk.h>

//------------------------------------------------------------------------------
// class declarations
//------------------------------------------------------------------------------
class MainWindow;
class EventHandler;
class EventLog;
class SyncEventHandler;

//------------------------------------------------------------------------------
/**
\brief  Api class

Class Api implements the API interface to the openPOWERLINK stack.
*/
//------------------------------------------------------------------------------
class Api : public QObject
{
    Q_OBJECT

public:
    Api(MainWindow* pMainWindow_p);
    ~Api();

    void start(unsigned int nodeId_p,
               const QString& devName_p);
    void stop();

    // static members
    static UINT32 getVersion();
    static void   execNmtCommand(tNmtEvent nmtEvent_p);

signals:
    void userDefEvent(void* pUserArg_p);
    void sdoFinished(tSdoComFinished sdoInfo_p);

private:
    tOplkApiInitParam   initParam;

    EventLog*           pEventLog;
    EventHandler*       pEventHandler;
    SyncEventHandler*   pSyncEventHandler;

    const char*         pCdcFilename;
    char                devName[256];

    // static members
    static const UINT32 IP_ADDR;
    static const UINT32 SUBNET_MASK;
    static const UINT32 DEFAULT_GATEWAY;
    static const UINT32 CYCLE_LEN;
    static const UINT8  aMacAddr[];
};

#endif /*_INC_demo_Api_H_*/
