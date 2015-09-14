NDSummary.OnToolTipsLoaded("File:MicroStrain/Inertial/Commands/GetDeviceInfo.h",{262:"<div class=\"NDToolTip TStruct LC\"><div class=\"TTSummary\">Contains information retrieved from an Inertial GetDeviceInfo command.</div></div>",264:"<div class=\"NDToolTip TVariable LC\"><div class=\"TTSummary\">The firmware Version.</div></div>",265:"<div class=\"NDToolTip TVariable LC\"><div class=\"TTSummary\">The model name.</div></div>",266:"<div class=\"NDToolTip TVariable LC\"><div class=\"TTSummary\">The model number.</div></div>",267:"<div class=\"NDToolTip TVariable LC\"><div class=\"TTSummary\">The serial number.</div></div>",268:"<div class=\"NDToolTip TVariable LC\"><div class=\"TTSummary\">The lot number.</div></div>",269:"<div class=\"NDToolTip TVariable LC\"><div class=\"TTSummary\">The device options.</div></div>",270:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype270\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">GetDeviceInfo</div></div></div><div class=\"TTSummary\">Contains the logic for the Inertial GetDeviceInfo command</div></div>",276:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype276\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">static</span> ByteStream buildCommand()</div><div class=\"TTSummary\">Builds the command packet</div></div>",277:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype277\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">Response</div></div></div><div class=\"TTSummary\">Handles the response to the GetDeviceInfo command</div></div>",279:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype279\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\">Response(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\">std::</td><td class=\"PType\">weak_ptr&lt;ResponseCollector&gt;&nbsp;</td><td class=\"PName last\">collector</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Creates a GetDeviceInfo Response object</div></div>",280:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype280\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">virtual bool</span> match_data(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">InertialDataField&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">field</td></tr></table></td><td class=\"PAfterParameters\">) <span class=\"SHKeyword\">override</span></td></tr></table></div><div class=\"TTSummary\">Attempts to match an InertialDataField to the expected data field response.</div></div>",281:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype281\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\">InertialDeviceInfo parseData(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">GenericInertialCommandResponse&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">response</td></tr></table></td><td class=\"PAfterParameters\">) <span class=\"SHKeyword\">const</span></td></tr></table></div><div class=\"TTSummary\">Parses a successfully matched response for the GetDeviceInfo command.</div></div>"});