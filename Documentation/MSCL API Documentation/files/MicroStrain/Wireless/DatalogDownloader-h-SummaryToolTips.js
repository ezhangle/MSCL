NDSummary.OnToolTipsLoaded("File:MicroStrain/Wireless/DatalogDownloader.h",{1950:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype1950\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">DatalogDownloader</div></div></div><div class=\"TTSummary\">Used to download logged data from a WirelessNode.</div></div>",1951:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1951\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">explicit</span> DatalogDownloader(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">WirelessNode&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">node</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Creates a DatalogDownloader object. Datalogging information will immediately be read from the Node.</div></div>",1952:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1952\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">bool</span> complete()</div><div class=\"TTSummary\">Checks if all of the data has been downloaded (no more data available).</div></div>",1953:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1953\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">float</span> percentComplete() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the percent completion of the download.</div></div>",1954:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1954\" class=\"NDPrototype NoParameterForm\">LoggedDataSweep getNextData()</div><div class=\"TTSummary\">Gets the next LoggedDataSweep that is logged to the Node.</div></div>",1955:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1955\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">bool</span> startOfSession() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets whether a new datalogging session has been found (after calling getNextData).&nbsp; This will be true for a single LoggedDataSweep, signifying that all of the DatalogDownloader\'s info has been updated with new information (sample rate, session index, etc.) about this sweep.</div></div>",1956:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1956\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">uint16</span> sessionIndex() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the index of the current datalogging session.&nbsp; This starts at 1 for the first session, and is incremented for each additional session.</div></div>",1957:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1957\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">const</span> SampleRate&amp; sampleRate() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the SampleRate of the current datalogging session.</div></div>",1958:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1958\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">const</span> std::<span class=\"SHKeyword\">string</span>&amp; userString() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the user entered string of the current datalogging session (if any).</div></div>",1959:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1959\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">const</span> ChannelCalMap&amp; calCoefficients() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets the &lt;ChannelCalMap&gt; of the current datalogging session.</div></div>",1960:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1960\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">bool</span> calsApplied() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Gets whether all of the given cal coefficients are already applied to the data or not.</div></div>"});