/*******************************************************************************
Copyright(c) 2017 LORD Corporation. All rights reserved.

MIT Licensed. See the included LICENSE.txt for a copy of the full MIT License.
*******************************************************************************/
#pragma once

#include "GenericInertialCommand.h"
#include "mscl/MicroStrain/ResponseCollector.h"
#include "mscl/MicroStrain/Inertial/InertialReturnTypes.h"

namespace mscl
{

#ifndef SWIG

    //Class: GNSS_AssistTimeUpdate
    //    Contains the logic for the Inertial GNSS Assist TimeUpdate command.
    //    It is important to note that this command will get a Nack back every time after the first from power up.
    class GNSS_AssistTimeUpdate : private GenericInertialCommand
    {
    protected:
        //Function: CommandId
        //Returns:
        //    InertialTypes::Command - the command ID.
        virtual InertialTypes::Command commandId() const override { return InertialTypes::CMD_GNSS_ASSIST_TIME_UPDATE; }

    public:
        GNSS_AssistTimeUpdate();

        //Constants: Packet Bytes
        //     FIELD_DATA_BYTE - Descriptor byte for the Field data.
        static const uint8 FIELD_DATA_BYTE = 0xA3;

    public:
        virtual ~GNSS_AssistTimeUpdate() {};

        //Function: buildCommand_get
        //    Builds the bytes for the "get" command.
        //Returns:
        //    A <ByteStream> containing the GNSS_AssistTimeUpdate command packet
        ByteStream buildCommand_get();

        //Function: buildCommand_set
        //    Builds the bytes for the "set" command. 
        //
        //Parameters:
        //    FieldData -  The data to set.
        //Returns:
        //    A <ByteStream> containing the GNSS_AssistTimeUpdate command packet
        ByteStream buildCommand_set(const TimeUpdate&);

        //Class: Response
        //    Handles the response to the GNSS_AssistTimeUpdate command.
        class Response : public GenericInertialCommand::Response
        {
            //Function: fieldDataByte
            //    Gets the data field descriptor byte
            virtual uint8 fieldDataByte() const    override { return FIELD_DATA_BYTE; }

        public:
            //Constructor: Response
            //    Creates a GNSS_AssistTimeUpdate Response object
            //
            //Parameters:
            //    collector - The <ResponseCollector> used to register and unregister the response
            Response(std::weak_ptr<ResponseCollector> collector, bool ackNackExpected, bool dataResponseExpected);

            //Function: parseResponse
            //    Parses the response, getting the assist time result
            //
            //Parameters:
            //    response - The <GenericInertialCommandResponse> holding the response to parse
            //
            //Returns:
            //    The data rate base result
            TimeUpdate parseResponse(const GenericInertialCommandResponse& response) const;
        };
    };

#endif
}
