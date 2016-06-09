NDSummary.OnToolTipsLoaded("File:MicroStrain/Wireless/Commands/BaseStation_BeaconStatus.h",{1632:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype1632\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">BeaconStatus</div></div></div><div class=\"TTSummary\">Represents the status of a BaseStation beacon.&nbsp; See also BaseStation::beaconStatus.</div></div>",1634:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1634\" class=\"NDPrototype NoParameterForm\">BeaconStatus()</div><div class=\"TTSummary\">Creates a default BeaconStatus object.</div></div>",1635:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1635\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\">BeaconStatus(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"first\"></td><td class=\"PType\"><span class=\"SHKeyword\">bool</span>&nbsp;</td><td></td><td class=\"PName last\">beaconEnabled,</td></tr><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">Timestamp&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">currentTimestamp</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Creates a BeaconStatus object with the given parameters.</div></div>",1637:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1637\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">bool</span> m_enabled</div><div class=\"TTSummary\">Whether the beacon is enabled or disabled.</div></div>",1638:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1638\" class=\"NDPrototype NoParameterForm\">Timestamp m_timestamp</div><div class=\"TTSummary\">The current Timestamp of the beacon.</div></div>",1640:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1640\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">bool</span> enabled()</div><div class=\"TTSummary\">Gets whether the beacon is enabled (true) or disabled (false).</div></div>",1641:"<div class=\"NDToolTip TFunction LC\"><div class=\"TTSummary\">Gets the current Timestamp of the beacon.</div></div>",1642:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype1642\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">BaseStation_BeaconStatus</div></div></div><div class=\"TTSummary\">Contains logic for the base station Get Beacon Status command.</div></div>",1644:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1644\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">static</span> ByteStream buildCommand()</div><div class=\"TTSummary\">Builds the beacon status command.</div></div>",1645:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype1645\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">Response</div></div></div><div class=\"TTSummary\">Handles the response to the command</div></div>",1647:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1647\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\">Response(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\">std::</td><td class=\"PType\">weak_ptr&lt;ResponseCollector&gt;&nbsp;</td><td class=\"PName last\">collector</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Creates a get beacon status Response object</div></div>",1649:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1649\" class=\"NDPrototype NoParameterForm\">BeaconStatus m_result</div><div class=\"TTSummary\">The BeaconStatus that holds the result of the command.</div></div>",1651:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1651\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">virtual bool</span> match(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">WirelessPacket&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">packet</td></tr></table></td><td class=\"PAfterParameters\">) <span class=\"SHKeyword\">override</span></td></tr></table></div><div class=\"TTSummary\">Checks if the packet passed in matches either the success or failure response.</div></div>",1652:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1652\" class=\"NDPrototype NoParameterForm\">BeaconStatus result()</div><div class=\"TTSummary\">Gets the BeaconStatus that holds the result of the response.</div></div>",1653:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1653\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> matchSuccessResponse(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">WirelessPacket&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">packet</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Checks if the packet passed in matches the success response.</div></div>",1654:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1654\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> matchFailResponse(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">WirelessPacket&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">packet</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Checks if the packet passed in matches the failure response.</div></div>"});