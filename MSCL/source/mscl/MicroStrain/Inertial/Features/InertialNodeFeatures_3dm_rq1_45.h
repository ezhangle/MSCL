/*******************************************************************************
Copyright(c) 2015-2017 LORD Corporation. All rights reserved.

MIT Licensed. See the included LICENSE.txt for a copy of the full MIT License.
*******************************************************************************/
#pragma once

#include "InertialNodeFeatures.h"

namespace mscl
{
    //Class: InertialNodeFeatures_3dm_rq1_45
    //    Contains information on features for the 3DM-RQ1-45 Node. Inherits from <InertialNodeFeatures>.
    class InertialNodeFeatures_3dm_rq1_45: public InertialNodeFeatures
    {
    public:
        virtual ~InertialNodeFeatures_3dm_rq1_45() {};

        //Constructor: InertialNodeFeatures_3dm_rq1_45
        //    Creates a InertialNodeFeatures_3dm_rq1_45 object.
        InertialNodeFeatures_3dm_rq1_45(const InertialNodeInfo& info);
    };
}