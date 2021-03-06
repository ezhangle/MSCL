/*******************************************************************************
Copyright(c) 2015-2017 LORD Corporation. All rights reserved.

MIT Licensed. See the included LICENSE.txt for a copy of the full MIT License.
*******************************************************************************/
#pragma once

#include <memory>

#include "InertialChannel.h"
#include "InertialTypes.h"
#include "InertialModels.h"
#include "Commands/Ping.h"
#include "Commands/GenericInertialCommand.h"
#include "Commands/GetDeviceInfo.h"
#include "Packets/InertialPacketCollector.h"
#include "mscl/Communication/Connection.h"
#include "mscl/MicroStrain/ResponseCollector.h"
#include "mscl/MicroStrain/Inertial/EulerAngles.h"
#include "mscl/MicroStrain/Inertial/PositionOffset.h"
#include "mscl/Timestamp.h"
#include "mscl/MicroStrain/Inertial/InertialReturnTypes.h"

namespace mscl
{
    //forward declarations
    class InertialParser;
    class InertialNodeInfo;
    class InertialNodeFeatures;
    class InertialCommand;

    //Class: InertialNode_Impl
    //     Contains the implementation for an <InertialNode>.
    class InertialNode_Impl
    {
    private:
        //Constant: COMMANDS_DEFAULT_TIMEOUT
        //    The default timeout for Inertial commands (250 milliseconds)
        static const uint64 COMMANDS_DEFAULT_TIMEOUT = 250;

    public:
        //Constructor: InertialNode_Impl
        //    Creates an InertialNode_Impl object.
        //
        //Parameters:
        //    connection - The Connection object used for communication.
        explicit InertialNode_Impl(Connection connection);

        //Destructor: ~InertialNode
        //    Destroys the InertialNode object
        ~InertialNode_Impl();

    private:
        InertialNode_Impl();                                    //default constructor disabled
        InertialNode_Impl(const InertialNode_Impl&);            //copy constructor disabled
        InertialNode_Impl& operator=(const InertialNode_Impl&);    //assignment operator disabled

    private:
        //Variable: m_connection
        //    The Connection object used for communication
        Connection m_connection;

        //Variable: m_packetCollector
        //    The Inertial packet collector used to store interial data packets
        InertialPacketCollector m_packetCollector;

        //Variable: m_responseCollector
        //    The response collector used to find and store wireless command responses
        std::shared_ptr<ResponseCollector> m_responseCollector;

        //Variable: m_parser
        //    The Inertial parser in charge of parsing all incoming data to this device
        std::unique_ptr<InertialParser> m_parser;

        //Variable: m_nodeCommandsTimeout
        //    The timeout to use for Inertial commands
        uint64 m_inertialCommandsTimeout;

        //Variable: m_nodeInfo
        //    The <InertialNodeInfo> object that gives access to information of the Inertial Node
        mutable std::unique_ptr<InertialNodeInfo> m_nodeInfo;

        //Variable: m_features
        //    The <InertialNodeFeatures> containing the features for this device.
        mutable std::unique_ptr<InertialNodeFeatures> m_features;

        //Variable: m_sensorRateBase
        //    The Sensor sample rate base (if any).
        mutable uint16 m_sensorRateBase;

        //Variable: m_gnssRateBase
        //    The GNSS sample rate base (if any).
        mutable uint16 m_gnssRateBase;

        //Variable: m_sensorRateBase
        //    The Estimation Filter sample rate base (if any).
        mutable uint16 m_estfilterRateBase;

        //Variable: m_lastCommTime
        //    A <Timestamp> representing the last time communication was achieved with the InertialNode.
        Timestamp m_lastCommTime;

    private:
        //Function: parseData
        //    Callback function that parses any bytes that are in the read buffer to find packets or command responses
        //
        //Parameters:
        //    data - The <DataBuffer> containing all the data to be parsed
        void parseData(DataBuffer& data);

        //Function: info
        //    Gets the <InertialNodeInfo> for this Node. 
        //    The first time this function is called, it will send multiple commands to the device to get all required information.
        //
        //Returns:
        //    A reference to the <InertialNodeInfo> for this Node.
        //
        //Exceptions:
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: Information failed to be loaded for this Node.
        const InertialNodeInfo& info() const;

	public:
        //Function: doCommand
        //    Performs a generic Inertial Command, sending the command bytes and waiting for the response.
        //
        //Parameters:
        //    response - A <GenericInertialCommand::Response> that will be used to wait and contain all the command/result information.
        //    command - The <ByteStream> containing the bytes to send for the command.
        //    minimumTimeout - The <uint64> minimum time needed for the response.  Will always use at least COMMANDS_DEFAULT_TIMEOUT.
        //    verifySupported - Whether to verify if the command is supported before performing the command (default of true).
        //
        //Returns:
        //    The <GenericInertialCommandResponse> that contains the actual data from the response
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_InertialCmdFailed>: The command has failed.
        virtual GenericInertialCommandResponse doCommand(GenericInertialCommand::Response& response, const ByteStream& command, bool verifySupported = true) const;

        //Function: features
        //    Gets a reference to the <InertialNodeFeatures> for this device.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The model is not supported by MSCL.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: Information failed to be loaded for this Node.
        virtual const InertialNodeFeatures& features() const;

        //Function: connection
        //    Gets the <Connection> object that this BaseStation is using.
        Connection& connection();

        //Function: lastCommunicationTime
        //    Gets the <Timestamp> for the last time we communicated with the InertialNode.
        //
        //Exceptions:
        //  - <Error_NoData>: There is no communication time logged for this device.
        const Timestamp& lastCommunicationTime() const;

        //Function: firmwareVersion
        //    Gets the firmware <Version> of the InertialNode.
        Version firmwareVersion() const;

        //Function: model
        //    Gets the <InertialModels::NodeModel> of the InertialNode.
        InertialModels::NodeModel model() const;

        //Function: modelName
        //    Gets the model name of the InertialNode (ie. "3DM-GX3-45").
        std::string modelName() const;

        //Function: modelNumber
        //    Gets the model number of the InertialNode (ie. "6225-4220").
        std::string modelNumber() const;

        //Function: serialNumber
        //    Gets the serial number of the InertialNode (ie. "6225-01319").
        std::string serialNumber() const;

        //Function: lotNumber
        //    Gets the lot number of the InertialNode (ie. "I042Y").
        std::string lotNumber() const;

        //Function: deviceOptions
        //    Gets the device options of the InertialNode (ie. "5g, 300d/s").
        std::string deviceOptions() const;

        //Function: supportedSampleRates
        //    Gets a list of the supported sample rates for an <InertialTypes::InertialCategory>.
        //
        //Parameters:
        //    category - The <InertialTypes::InertialCategory> to get the sample rate list for.
        //
        //Returns:
        //    A <SampleRates> list containing all the supported sample rates for the provided channel.
        //
        //Exceptions:
        //    - <Error>: The <InertialTypes::InertialCategory> is invalid.
        SampleRates supportedSampleRates(InertialTypes::InertialCategory category) const;

        //Function: getDataPackets
        //    Gets up to the requested amount of data packets that have been collected.
        //
        //Parameters:
        //    packets - A vector of <InertialDataPacket> to hold the result.
        //    timeout - the timeout, in milliseconds, to wait for the data if necessary (default of 0)
        //    maxPackets - The maximum number of packets to return. If this is 0 (default), all packets will be returned.
        //
        //Exceptions:
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        void getDataPackets(std::vector<InertialDataPacket>& packets, uint32 timeout = 0, uint32 maxPackets = 0);

        //Function: totalPackets
        //    Gets the total number of data packets that are currently in the buffer.
        //
        //Returns:
        //    The total number of data packets that are currently in the buffer.
        uint32 totalPackets();

        //Function: timeout
        //    Sets the timeout to use when waiting for responses from Inertial commands.
        //
        //Parameters:
        //    timeout - The timeout (in milliseconds) to set for Inertial commands.
        void timeout(uint64 timeout);

        //Function: timeout
        //    Gets the timeout to use when waiting for responses from Inertial commands.
        //
        //Returns:
        //    The timeout (in milliseconds) used for Inertial commands.
        uint64 timeout();

        //Function: getDeviceInfo
        //    Gets information about the InertialNode.
        //    Sends the "Get Device Information" command to the device.
        //
        //Returns:
        //    A <InertialDeviceInfo> object that holds the response of the "Get Device Information" command.
        //
        //Exceptions:
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        virtual InertialDeviceInfo getDeviceInfo() const;

        //Function: getDescriptorSets
        //    Gets the supported descriptor sets for this node, representing which commands and data sets are available.
        //    Sends the "Get Device Descriptor Sets" command to the device. 
        //
        //Returns:
        //    The supported descriptors retrieved from the "Get Device Descriptor Sets" command.
        //
        //Exceptions:
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        virtual std::vector<uint16> getDescriptorSets() const;

    public:
        //Function: ping
        //    Pings the node to check for communication. 
        //    Sends the "Ping" command to the device.
        //
        //Returns:
        //    true if successfully pinged the node, false if failed.
        //
        //Exceptions:
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        bool ping();

        //Function: setToIdle
        //    Suspends streaming (if enabled) or wakes the device from sleep (if sleeping), putting the device in an idle mode.
        //    After this command is used, the <resume> command may be used to put the Node back into the mode it was previously in before setToIdle was called.
        //
        //Exceptions:
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        void setToIdle();

        //Function: cyclePower
        //  Performs the "Device Reset" Inertial command.
        //
        //Exceptions:
        //  - <Error_Communication>: There was no response to the command. The command timed out.
        //  - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //  - <Error_Connection>: A connection error has occurred with the InertialNode.
        bool cyclePower();

        //Function: resume
        //    Places the Node back in the mode it was in before issuing the <setToIdle> command.
        //    If the <setToIdle> command was not issues, then the device is placed in default mode.
        //
        //Exceptions:
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        void resume();

        //Function: saveSettingsAsStartup
        //  Saves all of the current settings as the Node's startup settings.
        //  Note: A brief data disturbance may occur when calling this command.
        //
        //Exceptions:
        //  - <Error_Communication>: There was no response to the command. The command timed out.
        //  - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //  - <Error_Connection>: A connection error has occurred with the InertialNode.
        void saveSettingsAsStartup();

        //Function: loadStartupSettings
        //  Loads the saved startup settings onto the Node as its current settings.
        //  This function is useful if you have powered on the Node, made changes to its settings, and
        //  want to get back to its startup settings.
        //
        //Exceptions:
        //  - <Error_Communication>: There was no response to the command. The command timed out.
        //  - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //  - <Error_Connection>: A connection error has occurred with the InertialNode.
        void loadStartupSettings();

        //Function: loadFactoryDefaultSettings
        //  Loads the factory default settings onto the Node as its current settings.
        //
        //Exceptions:
        //  - <Error_Communication>: There was no response to the command. The command timed out.
        //  - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //  - <Error_Connection>: A connection error has occurred with the InertialNode.
        void loadFactoryDefaultSettings();

        //Function: getDataRateBase
        //    Gets the Data decimation base for the data rate calculations of the specified <InertialTypes::InertialCategory>.
        //
        //Parameters:
        //    category - The <InertialTypes::InertialCategory> to get the Data decimation base for.
        //
        //Returns:
        //    The decimation base for the data rate calculations.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command or <InertialTypes::InertialCategory> is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        virtual uint16 getDataRateBase(InertialTypes::InertialCategory category) const;

        //Function: getMessageFormat
        //    Gets the current message format of the specified <InertialTypes::InertialCategory>'s data packet. 
        //
        //Parameters:
        //    category - The <InertialTypes::InertialCategory> to get the current message format for.
        //
        //Returns:
        //    An <InertialChannels> object containing the channels that make up the data message format for the specified <InertialTypes::InertialCategory>
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command or <InertialTypes::InertialCategory> is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        virtual InertialChannels getMessageFormat(InertialTypes::InertialCategory category);

        //Function: setMessageFormat
        //    Sets the current message format of the specified <InertialTypes::InertialCategory>'s data packet.
        //    Note that this function does not add to the existing message format, but overwrites it entirely.
        //
        //Parameters:
        //    category - The <InertialTypes::InertialCategory> to set the message format for.
        //    channels - The <InertialChannels> object containing the channels to set the message format to. Passing an empty <InertialChannels> object will effectively disable all channels.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command or <InertialTypes::InertialCategory> is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        //    - <Error>: An <InertialChannel> in the channels parameter is not part of the specified <InertialTypes::InertialCategory>'s descriptor set.
        virtual void setMessageFormat(InertialTypes::InertialCategory category, const InertialChannels& channels);

        //Function: getCommunicationMode
        //    Gets the current communication mode that the node is in.
        //
        //Returns:
        //    The communication mode the node is in. This is an advanced command, and therefore the communication modes for your device should be researched to determine what each communication mode is.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        virtual uint8 getCommunicationMode();

        //Function: setCommunicationMode
        //    Sets the communication mode for the node. 
        //    Note: The node info will be reset when doing this and therefore will require being fetched again the next time it is requested.
        //
        //Parameters:
        //    communicationMode - The communication mode to set. This is an advanced command, and therefore the communication modes for your device should be researched to determine what each communication mode is.
        //
        //Exceptions:
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        virtual void setCommunicationMode(uint8 communicationMode);

        //Function: enableDataStream
        //    Enables or disables continuous data streaming for the node.
        //
        //Parameters:
        //    category - The <InertialTypes::InertialCategory> to enable/disable streaming for.
        //    enable - Whether to enable (true) or disable (false) continuous streaming (Default of true).
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command, or <InertialTypes::InertialTypeCategory>, is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        void enableDataStream(InertialTypes::InertialCategory category, bool enable);

        //Function: resetFilter
        //    Resets the filter to the initialize state.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        void resetFilter();

        //Function: getAutoInitialization
        //    Gets the state of the automatic initialization upon device startup.
        //
        //Returns:
        //    true if auto-initialization is enabled, false if it is disabled.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        bool getAutoInitialization();

        //Function: setAutoInitialization
        //    Sets the state of the automatic initialization upon device startup.
        //
        //Parameters:
        //    enable - Whether to enable (true) or disable(false) auto-initialization.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        void setAutoInitialization(bool enable);

        //Function: setInitialAttitude
        //    Sets the initial attitude.
        //
        //Parameters:
        //  attitude - The <EulerAngles> (in radians) representing the sensor body frame with respect to the local NED frame.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        void setInitialAttitude(const EulerAngles& attitude);

        //Function: setInitialHeading
        //    Sets the initial heading.
        //
        //Parameters:
        //  heading - The heading to set (in radians).
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        void setInitialHeading(float heading);

        //Function: getSensorToVehicleTransformation
        //    Gets the sensor to vehicle frame transformation matrix using roll, pitch, and yaw Euler angles (in radians).
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command or <InertialTypes::InertialCategory> is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        EulerAngles getSensorToVehicleTransformation();

        //Function: setSensorToVehicleTransformation
        //    Sets the sensor to vehicle frame transformation matrix using roll, pitch, and yaw Euler angles (in radians).
        //
        //Parameters:
        //    angles - The <EulerAngles> object containing the roll, pitch, and yaw to set.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        void setSensorToVehicleTransformation(const EulerAngles& angles);

        //Function: getSensorToVehicleOffset
        //    Gets the sensor to vehicle frame offset, expressed in the sensor frame.
        //
        //Returns:
        //    A <PositionOffset> representing the sensor to vehicle frame offset, expressed in the sensor frame.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        PositionOffset getSensorToVehicleOffset();

        //Function: setSensorToVehicleTransformation
        //    Sets the sensor to vehicle frame offset, expressed in the sensor frame.
        //
        //Parameters:
        //    offset - The <PositionOffset> object containing the x, y, and z position (in meters) to set.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        void setSensorToVehicleOffset(const PositionOffset& offset);

        //Function: getAntennaOffset
        //    Gets the antenna offset, expressed in the sensor frame.
        //
        //Returns:
        //    The <PositionOffset> of the antenna, expressed in the sensor frame.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        PositionOffset getAntennaOffset();

        //Function: setAntennaOffset
        //    Sets the antenna offset, expressed in the sensor frame.
        //
        //Parameters:
        //    offset - The <PositionOffset> object containing the x, y, and z position (in meters) to set.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        void setAntennaOffset(const PositionOffset& offset);

        //Function: getGNSSAssistedFixControl
        //    Gets the GNSS Assisted Fix Control.
        //
        //Returns:
        //    bool indicating if assisted fix is enabled.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        bool getGNSSAssistedFixControl();

        //Function: setGNSSAssistedFixControl
        //    Sets the GNSS Assisted Fix Control.
        //
        //Parameters:
        //    enableAssistedFix - boolean value.  If true, enables the assisted fix option.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
		void setGNSSAssistedFixControl(bool enableAssistedFix);

        //Function: getGNSSAssistTimeUpdate
        //    Gets the GNSS Assisted Time Update.
        //Returns:
        //    The GNSS Assist <TimeUpdate>.
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        TimeUpdate getGNSSAssistTimeUpdate();

        //Function: setGNSSAssistTimeUpdate
        //    Sets the GNSS Assist Time Update.
        //
        //Parameters:
        //    TimeUpdate - The <TimeUpdate> object containing the new time to set.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        void setGNSSAssistTimeUpdate(TimeUpdate update);

        //Function: getGPSTimeUpdateWeeks
        //    Gets the GPS weeks time update.
        //
        //Returns:
        //    time - the current weeks time.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        uint32 getGPSTimeUpdateWeeks();

        //Function: getGPSTimeUpdateSeconds
        //    Gets the GPS seconds time update.
        //
        //Returns:
        //    time - the current seconds time.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        uint32 getGPSTimeUpdateSeconds();

        //Function: setGPSTimeUpdate
        //    Sets the GPS Time Update.
        //
        //Parameters:
        //    timeFrame - The <TimeFrame> object specifying what current time value to set, either weeks or seconds.
        //    timeData - the current time.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        void setGPSTimeUpdate(InertialTypes::TimeFrame timeFrame, uint32 timeData);

        //Function: setConstellationSettings
        //    Sets the GNSS Constellation Settings.
        //
        //Parameters:
        //    The <ConstellationSettingsData> object containing the data to set.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        void setConstellationSettings(const ConstellationSettingsData&);

        //Function: getConstellationSettings
        //    Gets the GNSS Constellation Settings.
        //
        //Returns:
        //    The <ConstellationSettingsData> object containing the data.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        ConstellationSettingsData getConstellationSettings();

        //Function: setSBASSettings
        //    Sets the GNSS SBAS Settings.
        //
        //Parameters:
        //    dataToUse - The <SBASSettingsData> object containing the data to set.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        void setSBASSettings(const SBASSettingsData& dataToUse);

        //Function: getSBASSettings
        //    Gets the GNSS SBAS Settings.
        //
        //Returns:
        //    The <SBASSettingsData> object containing the data.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        SBASSettingsData getSBASSettings();

        //Function: setAccelerometerBias
        //    Sets the Accelerometer Bias.
        //
        //Parameters:
        //    biasVector - The <GeometricVector> object containing the vector to set.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.ConstellationSettingsData
        void setAccelerometerBias(const GeometricVector& biasVector);

        //Function: getAccelerometerBias
        //    Gets the Accelerometer Bias.
        //
        //Return:
        //    The <GeometricVector> object containing the vector.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        GeometricVector getAccelerometerBias();

        //Function: setGyroBias
        //    Sets the Gyro Bias.
        //
        //Parameters:
        //    The <GeometricVector> object containing the vector to set.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.ConstellationSettingsData
        void setGyroBias(const GeometricVector& biasVector);

        //Function: getGyroBias
        //    Gets the Gyro Bias.
        //
        //Return:
        //    The <GeometricVector> object containing the vector.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.
        GeometricVector getGyroBias();
        
        //Function: captureGyroBias
        //    Runs the Gyro Bias capture routine on the inertial device.
        //
        //Parameters:
        //    The <uint16> samplingTime.
        //
        //Exceptions:
        //    - <Error_NotSupported>: The command is not supported by this Node.
        //    - <Error_Communication>: There was no response to the command. The command timed out.
        //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
        //    - <Error_Connection>: A connection error has occurred with the InertialNode.ConstellationSettingsData
        GeometricVector captureGyroBias(const uint16& samplingTime);

   private:
       //Function: SendCommand
       //    Generic send command.
       //
       //Parameters:
       //    The <InertialCommand> command.
       //
       //Return:
       //    The <GenericInertialCommandResponse> response from the sent command.
       //
       //Exceptions:
       //    - <Error_NotSupported>: The command is not supported by this Node.
       //    - <Error_Communication>: There was no response to the command. The command timed out.
       //    - <Error_InertialCmdFailed>: The command has failed. Check the error code for more details.
       //    - <Error_Connection>: A connection error has occurred with the InertialNode.ConstellationSettingsData
       GenericInertialCommandResponse SendCommand(InertialCommand& command);
    };
}