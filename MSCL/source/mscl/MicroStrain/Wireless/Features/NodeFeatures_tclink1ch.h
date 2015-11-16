/*******************************************************************************
Copyright(c) 2015 LORD Corporation. All rights reserved.

MIT Licensed. See the included LICENSE.txt for a copy of the full MIT License.
*******************************************************************************/
#pragma once

#include "NodeFeatures.h"

namespace mscl
{
    //Class: NodeFeatures_tclink1ch
    //    Contains information on features for the TC-Link 1CH Node.
    class NodeFeatures_tclink1ch : public NodeFeatures
    {
    public:
        virtual ~NodeFeatures_tclink1ch() {};

        //Constructor: NodeFeatures_tclink1ch
        //    Creates a NodeFeatures_tclink1ch object.
        NodeFeatures_tclink1ch(const NodeInfo& info);

        //Function: samplingModes
        //    Gets a list of the <WirelessTypes::SamplingMode>s that are supported by this Node.
        virtual const WirelessTypes::SamplingModes samplingModes() const override;

        //Function: dataFormats
        //    Gets a list of the <WirelessTypes::DataFormat>s that are supported by this Node.
        virtual const WirelessTypes::DataFormats dataFormats() const override;

        //Function: sampleRates
        //    Gets a list of the <WirelessTypes::WirelessSampleRates> that are supported by this Node for the given sampling mode.
        virtual const WirelessTypes::WirelessSampleRates sampleRates(WirelessTypes::SamplingMode samplingMode) const override;

        //Function: maxFilterSettlingTime
        //    Gets the maximum <WirelessTypes::SettlingTime> available for the given <SampleRate>.    
        virtual WirelessTypes::SettlingTime maxFilterSettlingTime(const SampleRate& rate) const override;
    };
}