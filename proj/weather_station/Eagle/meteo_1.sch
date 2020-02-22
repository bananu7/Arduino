<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.5.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="dots" multiple="1" display="yes" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="3" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="3" fill="1" visible="no" active="no"/>
<layer number="53" name="tGND_GNDA" color="7" fill="9" visible="no" active="no"/>
<layer number="54" name="bGND_GNDA" color="1" fill="9" visible="no" active="no"/>
<layer number="56" name="wert" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="memory-winbond">
<description>&lt;b&gt;Winbond Memories&lt;/b&gt;&lt;p&gt;
&lt;p&gt;THIS LIBRARY IS PROVIDED AS IS AND WITHOUT WARRANTY OF ANY KIND, EXPRESSED OR IMPLIED. USE AT YOUR OWN RISK!&lt;p&gt;
&lt;author&gt;Copyright (C) 2010, Bob Starr&lt;br&gt; http://www.bobstarr.net&lt;br&gt;&lt;/author&gt;</description>
<packages>
<package name="SO08-SS">
<description>&lt;b&gt;SMALL OUTLINE INTEGRATED CIRCUIT&lt;/b&gt;&lt;p&gt;
200 MIL BODY WIDTH (5.2MM X 8MM)</description>
<wire x1="2.645" y1="2.6" x2="2.645" y2="-2.6" width="0.2032" layer="51"/>
<wire x1="2.645" y1="-2.6" x2="-2.655" y2="-2.6" width="0.2032" layer="51"/>
<wire x1="-2.655" y1="-2.6" x2="-2.655" y2="2.6" width="0.2032" layer="51"/>
<wire x1="-2.655" y1="2.6" x2="2.645" y2="2.6" width="0.2032" layer="51"/>
<wire x1="-2.655" y1="1.9" x2="2.645" y2="1.9" width="0.2032" layer="21"/>
<wire x1="2.645" y1="1.9" x2="2.645" y2="-1.9" width="0.2032" layer="21"/>
<wire x1="2.645" y1="-1.9" x2="-2.655" y2="-1.9" width="0.2032" layer="21"/>
<wire x1="-2.655" y1="-1.9" x2="-2.655" y2="1.9" width="0.2032" layer="21"/>
<circle x="-1.905" y="-1.2738" radius="0.3175" width="0" layer="21"/>
<smd name="2" x="-0.635" y="-3.33" dx="0.6" dy="2.2" layer="1"/>
<smd name="7" x="-0.635" y="3.33" dx="0.6" dy="2.2" layer="1"/>
<smd name="1" x="-1.905" y="-3.33" dx="0.6" dy="2.2" layer="1"/>
<smd name="3" x="0.635" y="-3.33" dx="0.6" dy="2.2" layer="1"/>
<smd name="4" x="1.905" y="-3.33" dx="0.6" dy="2.2" layer="1"/>
<smd name="8" x="-1.905" y="3.33" dx="0.6" dy="2.2" layer="1"/>
<smd name="6" x="0.635" y="3.33" dx="0.6" dy="2.2" layer="1"/>
<smd name="5" x="1.905" y="3.33" dx="0.6" dy="2.2" layer="1"/>
<text x="-3.175" y="-2.8575" size="1.016" layer="25" ratio="18" rot="R90">&gt;NAME</text>
<text x="3.81" y="-2.8575" size="0.8128" layer="27" ratio="10" rot="R90">&gt;VALUE</text>
<rectangle x1="-2.1501" y1="-4.195" x2="-1.6599" y2="-2.6751" layer="51"/>
<rectangle x1="-0.8801" y1="-4.195" x2="-0.3899" y2="-2.6751" layer="51"/>
<rectangle x1="0.3899" y1="-4.195" x2="0.8801" y2="-2.6751" layer="51"/>
<rectangle x1="1.6599" y1="-4.195" x2="2.1501" y2="-2.6751" layer="51"/>
<rectangle x1="1.6599" y1="2.6751" x2="2.1501" y2="4.195" layer="51"/>
<rectangle x1="0.3899" y1="2.6751" x2="0.8801" y2="4.195" layer="51"/>
<rectangle x1="-0.8801" y1="2.6751" x2="-0.3899" y2="4.195" layer="51"/>
<rectangle x1="-2.1501" y1="2.6751" x2="-1.6599" y2="4.195" layer="51"/>
</package>
<package name="SO08">
<description>&lt;b&gt;SMALL OUTLINE INTEGRATED CIRCUIT&lt;/b&gt;&lt;p&gt;
150 mil (3.9 mm) body/JEDEC MS-012AA</description>
<wire x1="2.667" y1="1.905" x2="2.667" y2="-1.905" width="0.2032" layer="51"/>
<wire x1="2.667" y1="-1.905" x2="-2.667" y2="-1.905" width="0.2032" layer="51"/>
<wire x1="-2.667" y1="-1.905" x2="-2.667" y2="1.905" width="0.2032" layer="51"/>
<wire x1="-2.667" y1="1.905" x2="2.667" y2="1.905" width="0.2032" layer="51"/>
<wire x1="-2.667" y1="1.27" x2="2.667" y2="1.27" width="0.2032" layer="21"/>
<wire x1="2.667" y1="1.27" x2="2.667" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="2.667" y1="-1.27" x2="-2.667" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="-2.667" y1="-1.27" x2="-2.667" y2="1.27" width="0.2032" layer="21"/>
<circle x="-1.905" y="-0.635" radius="0.3175" width="0" layer="21"/>
<smd name="2" x="-0.635" y="-2.6" dx="0.6" dy="2.2" layer="1"/>
<smd name="7" x="-0.635" y="2.6" dx="0.6" dy="2.2" layer="1"/>
<smd name="1" x="-1.905" y="-2.6" dx="0.6" dy="2.2" layer="1"/>
<smd name="3" x="0.635" y="-2.6" dx="0.6" dy="2.2" layer="1"/>
<smd name="4" x="1.905" y="-2.6" dx="0.6" dy="2.2" layer="1"/>
<smd name="8" x="-1.905" y="2.6" dx="0.6" dy="2.2" layer="1"/>
<smd name="6" x="0.635" y="2.6" dx="0.6" dy="2.2" layer="1"/>
<smd name="5" x="1.905" y="2.6" dx="0.6" dy="2.2" layer="1"/>
<text x="-3.175" y="-1.905" size="1.016" layer="25" ratio="18" rot="R90">&gt;NAME</text>
<text x="-2.2225" y="-0.3175" size="0.8128" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-2.1501" y1="-3.1001" x2="-1.6599" y2="-2" layer="51"/>
<rectangle x1="-0.8801" y1="-3.1001" x2="-0.3899" y2="-2" layer="51"/>
<rectangle x1="0.3899" y1="-3.1001" x2="0.8801" y2="-2" layer="51"/>
<rectangle x1="1.6599" y1="-3.1001" x2="2.1501" y2="-2" layer="51"/>
<rectangle x1="1.6599" y1="2" x2="2.1501" y2="3.1001" layer="51"/>
<rectangle x1="0.3899" y1="2" x2="0.8801" y2="3.1001" layer="51"/>
<rectangle x1="-0.8801" y1="2" x2="-0.3899" y2="3.1001" layer="51"/>
<rectangle x1="-2.1501" y1="2" x2="-1.6599" y2="3.1001" layer="51"/>
</package>
<package name="DIL08">
<description>&lt;b&gt;Dual In Line Package&lt;/b&gt;&lt;p&gt;
300 mil body width</description>
<wire x1="5.08" y1="1.905" x2="-5.08" y2="1.905" width="0.2032" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="5.08" y2="-1.905" width="0.2032" layer="21"/>
<wire x1="5.08" y1="1.905" x2="5.08" y2="-1.905" width="0.2032" layer="21"/>
<wire x1="-5.08" y1="1.905" x2="-5.08" y2="0.6985" width="0.2032" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-5.08" y2="-0.6985" width="0.2032" layer="21"/>
<wire x1="-5.08" y1="0.6985" x2="-5.08" y2="-0.6985" width="0.2032" layer="21" curve="-180"/>
<pad name="1" x="-3.81" y="-3.81" drill="0.8128" shape="long" rot="R90" first="yes"/>
<pad name="2" x="-1.27" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="7" x="-1.27" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="8" x="-3.81" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="3" x="1.27" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="4" x="3.81" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="6" x="1.27" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="5" x="3.81" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<text x="-5.715" y="-2.54" size="1.016" layer="25" ratio="18" rot="R90">&gt;NAME</text>
<text x="-3.4925" y="-0.635" size="0.8128" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="WSON8">
<description>&lt;b&gt;8-WSON&lt;/b&gt;&lt;p&gt;
8-Contact Very-very-thin Small Outline No-lead&lt;p&gt;
body 6.00 x 5.00 mm</description>
<wire x1="-2.8" y1="-3" x2="-2.8" y2="3" width="0.2032" layer="21"/>
<wire x1="-2.8" y1="3" x2="2.8" y2="3" width="0.2032" layer="51"/>
<wire x1="2.8" y1="3" x2="2.8" y2="-3" width="0.2032" layer="21"/>
<wire x1="2.8" y1="-3" x2="-2.8" y2="-3" width="0.2032" layer="51"/>
<smd name="1" x="-1.905" y="-2.81" dx="1.27" dy="0.635" layer="1" rot="R90"/>
<smd name="2" x="-0.635" y="-2.81" dx="1.27" dy="0.635" layer="1" rot="R90"/>
<smd name="3" x="0.635" y="-2.81" dx="1.27" dy="0.635" layer="1" rot="R90"/>
<smd name="4" x="1.905" y="-2.81" dx="1.27" dy="0.635" layer="1" rot="R90"/>
<smd name="5" x="1.905" y="2.81" dx="1.27" dy="0.635" layer="1" rot="R90"/>
<smd name="6" x="0.635" y="2.81" dx="1.27" dy="0.635" layer="1" rot="R90"/>
<smd name="7" x="-0.635" y="2.81" dx="1.27" dy="0.635" layer="1" rot="R90"/>
<smd name="8" x="-1.905" y="2.81" dx="1.27" dy="0.635" layer="1" rot="R90"/>
<text x="-3.7925" y="-2.81" size="1.016" layer="25" ratio="18" rot="R90">&gt;NAME</text>
<text x="4.1275" y="-2.81" size="0.8128" layer="27" ratio="10" rot="R90">&gt;VALUE</text>
<rectangle x1="-1.5875" y1="0.635" x2="-0.9525" y2="1.27" layer="31"/>
<rectangle x1="-0.3175" y1="0.635" x2="0.3175" y2="1.27" layer="31"/>
<rectangle x1="0.9525" y1="0.635" x2="1.5875" y2="1.27" layer="31"/>
<rectangle x1="-1.5875" y1="-1.27" x2="-0.9525" y2="-0.635" layer="31"/>
<rectangle x1="-0.3175" y1="-1.27" x2="0.3175" y2="-0.635" layer="31"/>
<rectangle x1="0.9525" y1="-1.27" x2="1.5875" y2="-0.635" layer="31"/>
<smd name="9" x="0" y="0" dx="4.3" dy="3.4" layer="1"/>
<rectangle x1="-3.2" y1="-3.1" x2="-2.7" y2="-2.6" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="25XX">
<wire x1="-10.16" y1="5.08" x2="7.62" y2="5.08" width="0.4064" layer="94"/>
<wire x1="7.62" y1="5.08" x2="7.62" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="7.62" y1="-7.62" x2="-10.16" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="-10.16" y1="-7.62" x2="-10.16" y2="5.08" width="0.4064" layer="94"/>
<text x="-10.16" y="5.715" size="1.778" layer="95">&gt;NAME</text>
<text x="-10.16" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<pin name="!HOLD!" x="10.16" y="0" length="short" direction="in" rot="R180"/>
<pin name="!CS!" x="-12.7" y="2.54" length="short" direction="in"/>
<pin name="DO" x="-12.7" y="0" length="short" direction="out"/>
<pin name="!WP!" x="-12.7" y="-2.54" length="short" direction="in"/>
<pin name="CLK" x="10.16" y="-2.54" length="short" direction="in" function="clk" rot="R180"/>
<pin name="DI" x="10.16" y="-5.08" length="short" direction="in" rot="R180"/>
<pin name="GND" x="-12.7" y="-5.08" length="short" direction="pwr"/>
<pin name="VCC" x="10.16" y="2.54" length="short" direction="pwr" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="W25Q16BV" prefix="U">
<description>&lt;b&gt;EEPROM&lt;/b&gt;&lt;p&gt;
4 Mbit SPI Serial Flash7</description>
<gates>
<gate name="G$1" symbol="25XX" x="0" y="0"/>
</gates>
<devices>
<device name="SS" package="SO08-SS">
<connects>
<connect gate="G$1" pin="!CS!" pad="1"/>
<connect gate="G$1" pin="!HOLD!" pad="7"/>
<connect gate="G$1" pin="!WP!" pad="3"/>
<connect gate="G$1" pin="CLK" pad="6"/>
<connect gate="G$1" pin="DI" pad="5"/>
<connect gate="G$1" pin="DO" pad="2"/>
<connect gate="G$1" pin="GND" pad="4"/>
<connect gate="G$1" pin="VCC" pad="8"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="SN" package="SO08">
<connects>
<connect gate="G$1" pin="!CS!" pad="1"/>
<connect gate="G$1" pin="!HOLD!" pad="7"/>
<connect gate="G$1" pin="!WP!" pad="3"/>
<connect gate="G$1" pin="CLK" pad="6"/>
<connect gate="G$1" pin="DI" pad="5"/>
<connect gate="G$1" pin="DO" pad="2"/>
<connect gate="G$1" pin="GND" pad="4"/>
<connect gate="G$1" pin="VCC" pad="8"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="DA" package="DIL08">
<connects>
<connect gate="G$1" pin="!CS!" pad="1"/>
<connect gate="G$1" pin="!HOLD!" pad="7"/>
<connect gate="G$1" pin="!WP!" pad="3"/>
<connect gate="G$1" pin="CLK" pad="6"/>
<connect gate="G$1" pin="DI" pad="5"/>
<connect gate="G$1" pin="DO" pad="2"/>
<connect gate="G$1" pin="GND" pad="4"/>
<connect gate="G$1" pin="VCC" pad="8"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="ZP" package="WSON8">
<connects>
<connect gate="G$1" pin="!CS!" pad="1"/>
<connect gate="G$1" pin="!HOLD!" pad="7"/>
<connect gate="G$1" pin="!WP!" pad="3"/>
<connect gate="G$1" pin="CLK" pad="6"/>
<connect gate="G$1" pin="DI" pad="5"/>
<connect gate="G$1" pin="DO" pad="2"/>
<connect gate="G$1" pin="GND" pad="4 9"/>
<connect gate="G$1" pin="VCC" pad="8"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="atmel-avr">
<description>&lt;b&gt;Atmel AVR Processors&lt;/b&gt; - v1.02 (08/29/2010)&lt;p&gt;
&lt;p&gt;THIS LIBRARY IS PROVIDED AS IS AND WITHOUT WARRANTY OF ANY KIND, EXPRESSED OR IMPLIED.&lt;br&gt;
USE AT YOUR OWN RISK!&lt;p&gt;
&lt;author&gt;Copyright (C) 2008, Bob Starr&lt;br&gt; http://www.bobstarr.net&lt;br&gt;&lt;/author&gt;</description>
<packages>
<package name="DIP762W53P254L3500H508Q28B" urn="urn:adsk.eagle:footprint:17501352/1">
<description>28-DIP, 2.54 mm (0.10 in) pitch, 7.62 mm (0.30 in) span, 35.00 X 6.60 X 5.08 mm body
&lt;p&gt;28-pin DIP package with 2.54 mm (0.10 in) pitch, 7.62 mm (0.30 in) span with body size 35.00 X 6.60 X 5.08 mm&lt;/p&gt;</description>
<circle x="-4.9857" y="16.51" radius="0.25" width="0" layer="21"/>
<wire x1="-3.3" y1="17.4357" x2="-3.3" y2="17.5" width="0.12" layer="21"/>
<wire x1="-3.3" y1="17.5" x2="3.3" y2="17.5" width="0.12" layer="21"/>
<wire x1="3.3" y1="17.5" x2="3.3" y2="17.4357" width="0.12" layer="21"/>
<wire x1="-3.3" y1="-17.4357" x2="-3.3" y2="-17.5" width="0.12" layer="21"/>
<wire x1="-3.3" y1="-17.5" x2="3.3" y2="-17.5" width="0.12" layer="21"/>
<wire x1="3.3" y1="-17.5" x2="3.3" y2="-17.4357" width="0.12" layer="21"/>
<wire x1="3.3" y1="-17.5" x2="-3.3" y2="-17.5" width="0.12" layer="51"/>
<wire x1="-3.3" y1="-17.5" x2="-3.3" y2="17.5" width="0.12" layer="51"/>
<wire x1="-3.3" y1="17.5" x2="3.3" y2="17.5" width="0.12" layer="51"/>
<wire x1="3.3" y1="17.5" x2="3.3" y2="-17.5" width="0.12" layer="51"/>
<pad name="1" x="-3.81" y="16.51" drill="0.7434" diameter="1.3434"/>
<pad name="2" x="-3.81" y="13.97" drill="0.7434" diameter="1.3434"/>
<pad name="3" x="-3.81" y="11.43" drill="0.7434" diameter="1.3434"/>
<pad name="4" x="-3.81" y="8.89" drill="0.7434" diameter="1.3434"/>
<pad name="5" x="-3.81" y="6.35" drill="0.7434" diameter="1.3434"/>
<pad name="6" x="-3.81" y="3.81" drill="0.7434" diameter="1.3434"/>
<pad name="7" x="-3.81" y="1.27" drill="0.7434" diameter="1.3434"/>
<pad name="8" x="-3.81" y="-1.27" drill="0.7434" diameter="1.3434"/>
<pad name="9" x="-3.81" y="-3.81" drill="0.7434" diameter="1.3434"/>
<pad name="10" x="-3.81" y="-6.35" drill="0.7434" diameter="1.3434"/>
<pad name="11" x="-3.81" y="-8.89" drill="0.7434" diameter="1.3434"/>
<pad name="12" x="-3.81" y="-11.43" drill="0.7434" diameter="1.3434"/>
<pad name="13" x="-3.81" y="-13.97" drill="0.7434" diameter="1.3434"/>
<pad name="14" x="-3.81" y="-16.51" drill="0.7434" diameter="1.3434"/>
<pad name="15" x="3.81" y="-16.51" drill="0.7434" diameter="1.3434"/>
<pad name="16" x="3.81" y="-13.97" drill="0.7434" diameter="1.3434"/>
<pad name="17" x="3.81" y="-11.43" drill="0.7434" diameter="1.3434"/>
<pad name="18" x="3.81" y="-8.89" drill="0.7434" diameter="1.3434"/>
<pad name="19" x="3.81" y="-6.35" drill="0.7434" diameter="1.3434"/>
<pad name="20" x="3.81" y="-3.81" drill="0.7434" diameter="1.3434"/>
<pad name="21" x="3.81" y="-1.27" drill="0.7434" diameter="1.3434"/>
<pad name="22" x="3.81" y="1.27" drill="0.7434" diameter="1.3434"/>
<pad name="23" x="3.81" y="3.81" drill="0.7434" diameter="1.3434"/>
<pad name="24" x="3.81" y="6.35" drill="0.7434" diameter="1.3434"/>
<pad name="25" x="3.81" y="8.89" drill="0.7434" diameter="1.3434"/>
<pad name="26" x="3.81" y="11.43" drill="0.7434" diameter="1.3434"/>
<pad name="27" x="3.81" y="13.97" drill="0.7434" diameter="1.3434"/>
<pad name="28" x="3.81" y="16.51" drill="0.7434" diameter="1.3434"/>
<text x="0" y="18.135" size="1.27" layer="25" align="bottom-center">&gt;NAME</text>
<text x="0" y="-18.135" size="1.27" layer="27" align="top-center">&gt;VALUE</text>
</package>
</packages>
<packages3d>
<package3d name="DIP762W53P254L3500H508Q28B" urn="urn:adsk.eagle:package:17501351/1" type="model">
<description>28-DIP, 2.54 mm (0.10 in) pitch, 7.62 mm (0.30 in) span, 35.00 X 6.60 X 5.08 mm body
&lt;p&gt;28-pin DIP package with 2.54 mm (0.10 in) pitch, 7.62 mm (0.30 in) span with body size 35.00 X 6.60 X 5.08 mm&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="DIP762W53P254L3500H508Q28B"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="ATMEGA48P/88P/168P/328P-DIP">
<wire x1="-33.02" y1="30.48" x2="33.02" y2="30.48" width="0.4064" layer="94"/>
<wire x1="33.02" y1="30.48" x2="33.02" y2="-33.02" width="0.4064" layer="94"/>
<wire x1="33.02" y1="-33.02" x2="-33.02" y2="-33.02" width="0.4064" layer="94"/>
<wire x1="-33.02" y1="-33.02" x2="-33.02" y2="30.48" width="0.4064" layer="94"/>
<text x="-33.02" y="31.75" size="1.778" layer="95">&gt;NAME</text>
<text x="-33.02" y="-35.56" size="1.778" layer="96">&gt;VALUE</text>
<pin name="(PCINT5/SCK)PB5" x="38.1" y="-30.48" length="middle" swaplevel="1" rot="R180"/>
<pin name="PB7(TOSC2/XTAL2/PCINT7)" x="-38.1" y="10.16" length="middle" swaplevel="1"/>
<pin name="PB6(TOSC1/XTAL1/PCINT6)" x="-38.1" y="20.32" length="middle" swaplevel="1"/>
<pin name="GND@22" x="-38.1" y="-25.4" length="middle" direction="pwr"/>
<pin name="GND@8" x="-38.1" y="-27.94" length="middle" direction="pwr"/>
<pin name="VCC@4" x="-38.1" y="-7.62" length="middle" direction="pwr"/>
<pin name="AREF" x="-38.1" y="-20.32" length="middle"/>
<pin name="AVCC" x="-38.1" y="-15.24" length="middle" direction="pwr"/>
<pin name="(PCINT4/MISO)PB4" x="38.1" y="-27.94" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT3/OC2A/MOSI)PB3" x="38.1" y="-25.4" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT2/!SS!/OC1B)PB2" x="38.1" y="-22.86" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT1/OC1A)PB1" x="38.1" y="-20.32" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT0/CLKO/ICP1)PB0" x="38.1" y="-17.78" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT23/AIN1)PD7" x="38.1" y="-12.7" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT22/OC0A/AIN0)PD6" x="38.1" y="-10.16" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT21/OC0B/T1)PD5" x="38.1" y="-7.62" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT20/XCK/T0)PD4" x="38.1" y="-5.08" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT19/OC2B/INT1)PD3" x="38.1" y="-2.54" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT18/INT0)PD2" x="38.1" y="0" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT17/TXD)PD1" x="38.1" y="2.54" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT16/RXD)PD0" x="38.1" y="5.08" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT13/SCL/ADC5)PC5" x="38.1" y="15.24" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT12/SDA/ADC4)PC4" x="38.1" y="17.78" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT11/ADC3)PC3" x="38.1" y="20.32" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT10/ADC2)PC2" x="38.1" y="22.86" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT9/ADC1)PC1" x="38.1" y="25.4" length="middle" swaplevel="1" rot="R180"/>
<pin name="(PCINT8/ADC0)PC0" x="38.1" y="27.94" length="middle" swaplevel="1" rot="R180"/>
<pin name="PC6(!RESET!)" x="-38.1" y="27.94" length="middle" direction="in" swaplevel="1"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ATMEGA328P-DIP">
<gates>
<gate name="G$1" symbol="ATMEGA48P/88P/168P/328P-DIP" x="-5.08" y="7.62"/>
</gates>
<devices>
<device name="" package="DIP762W53P254L3500H508Q28B">
<connects>
<connect gate="G$1" pin="(PCINT0/CLKO/ICP1)PB0" pad="14"/>
<connect gate="G$1" pin="(PCINT1/OC1A)PB1" pad="15"/>
<connect gate="G$1" pin="(PCINT10/ADC2)PC2" pad="25"/>
<connect gate="G$1" pin="(PCINT11/ADC3)PC3" pad="26"/>
<connect gate="G$1" pin="(PCINT12/SDA/ADC4)PC4" pad="27"/>
<connect gate="G$1" pin="(PCINT13/SCL/ADC5)PC5" pad="28"/>
<connect gate="G$1" pin="(PCINT16/RXD)PD0" pad="2"/>
<connect gate="G$1" pin="(PCINT17/TXD)PD1" pad="3"/>
<connect gate="G$1" pin="(PCINT18/INT0)PD2" pad="4"/>
<connect gate="G$1" pin="(PCINT19/OC2B/INT1)PD3" pad="5"/>
<connect gate="G$1" pin="(PCINT2/!SS!/OC1B)PB2" pad="16"/>
<connect gate="G$1" pin="(PCINT20/XCK/T0)PD4" pad="6"/>
<connect gate="G$1" pin="(PCINT21/OC0B/T1)PD5" pad="11"/>
<connect gate="G$1" pin="(PCINT22/OC0A/AIN0)PD6" pad="12"/>
<connect gate="G$1" pin="(PCINT23/AIN1)PD7" pad="13"/>
<connect gate="G$1" pin="(PCINT3/OC2A/MOSI)PB3" pad="17"/>
<connect gate="G$1" pin="(PCINT4/MISO)PB4" pad="18"/>
<connect gate="G$1" pin="(PCINT5/SCK)PB5" pad="19"/>
<connect gate="G$1" pin="(PCINT8/ADC0)PC0" pad="23"/>
<connect gate="G$1" pin="(PCINT9/ADC1)PC1" pad="24"/>
<connect gate="G$1" pin="AREF" pad="21"/>
<connect gate="G$1" pin="AVCC" pad="20"/>
<connect gate="G$1" pin="GND@22" pad="22"/>
<connect gate="G$1" pin="GND@8" pad="8"/>
<connect gate="G$1" pin="PB6(TOSC1/XTAL1/PCINT6)" pad="9"/>
<connect gate="G$1" pin="PB7(TOSC2/XTAL2/PCINT7)" pad="10"/>
<connect gate="G$1" pin="PC6(!RESET!)" pad="1"/>
<connect gate="G$1" pin="VCC@4" pad="7"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:17501351/1"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-lsta" urn="urn:adsk.eagle:library:161">
<description>&lt;b&gt;Female Headers etc.&lt;/b&gt;&lt;p&gt;
Naming:&lt;p&gt;
FE = female&lt;p&gt;
# contacts - # rows&lt;p&gt;
W = angled&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="FE06" urn="urn:adsk.eagle:footprint:8135/1" library_version="2">
<description>&lt;b&gt;FEMALE HEADER&lt;/b&gt;</description>
<wire x1="-7.62" y1="1.27" x2="-7.62" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.27" x2="-5.334" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="-1.27" x2="-5.08" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.016" x2="-4.826" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="-1.27" x2="-2.794" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="-1.27" x2="-2.54" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.016" x2="-2.286" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-1.27" x2="-0.254" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-1.27" x2="0" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.016" x2="0.254" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-1.27" x2="2.286" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-1.27" x2="2.54" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.016" x2="2.794" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.794" y1="-1.27" x2="4.826" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.334" y1="-1.27" x2="7.62" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.27" x2="7.62" y2="1.27" width="0.1524" layer="21"/>
<wire x1="7.62" y1="1.27" x2="5.334" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.826" y1="1.27" x2="2.794" y2="1.27" width="0.1524" layer="21"/>
<wire x1="2.794" y1="1.27" x2="2.54" y2="1.016" width="0.1524" layer="21"/>
<wire x1="2.54" y1="1.016" x2="2.286" y2="1.27" width="0.1524" layer="21"/>
<wire x1="2.286" y1="1.27" x2="0.254" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.254" y1="1.27" x2="0" y2="1.016" width="0.1524" layer="21"/>
<wire x1="0" y1="1.016" x2="-0.254" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="1.27" x2="-2.286" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="1.27" x2="-2.54" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="1.016" x2="-2.794" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="1.27" x2="-4.826" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="1.27" x2="-5.08" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.016" x2="-5.334" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="1.27" x2="-7.62" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-6.604" y1="0.762" x2="-6.604" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="0.508" x2="-6.858" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-6.858" y1="0.508" x2="-6.858" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-6.858" y1="-0.508" x2="-6.604" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="-0.508" x2="-6.604" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="-0.762" x2="-6.096" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="-0.762" x2="-6.096" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="-0.508" x2="-5.842" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-5.842" y1="-0.508" x2="-5.842" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-5.842" y1="0.508" x2="-6.096" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="0.508" x2="-6.096" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="0.762" x2="-6.604" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="0.762" x2="-4.064" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="0.508" x2="-4.318" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-4.318" y1="0.508" x2="-4.318" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-4.318" y1="-0.508" x2="-4.064" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="-0.508" x2="-4.064" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="-0.762" x2="-3.556" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="-0.762" x2="-3.556" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="-0.508" x2="-3.302" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-3.302" y1="-0.508" x2="-3.302" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-3.302" y1="0.508" x2="-3.556" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="0.508" x2="-3.556" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="0.762" x2="-4.064" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="0.762" x2="-1.524" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="0.508" x2="-1.778" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.778" y1="0.508" x2="-1.778" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.778" y1="-0.508" x2="-1.524" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="-0.508" x2="-1.524" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="-0.762" x2="-1.016" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="-0.762" x2="-1.016" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="-0.508" x2="-0.762" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-0.762" y1="-0.508" x2="-0.762" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-0.762" y1="0.508" x2="-1.016" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="0.508" x2="-1.016" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="0.762" x2="-1.524" y2="0.762" width="0.1524" layer="51"/>
<wire x1="1.016" y1="0.762" x2="1.016" y2="0.508" width="0.1524" layer="51"/>
<wire x1="1.016" y1="0.508" x2="0.762" y2="0.508" width="0.1524" layer="51"/>
<wire x1="0.762" y1="0.508" x2="0.762" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="0.762" y1="-0.508" x2="1.016" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.016" y1="-0.508" x2="1.016" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="1.016" y1="-0.762" x2="1.524" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="1.524" y1="-0.762" x2="1.524" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.524" y1="-0.508" x2="1.778" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.778" y1="-0.508" x2="1.778" y2="0.508" width="0.1524" layer="51"/>
<wire x1="1.778" y1="0.508" x2="1.524" y2="0.508" width="0.1524" layer="51"/>
<wire x1="1.524" y1="0.508" x2="1.524" y2="0.762" width="0.1524" layer="51"/>
<wire x1="1.524" y1="0.762" x2="1.016" y2="0.762" width="0.1524" layer="51"/>
<wire x1="3.556" y1="0.762" x2="3.556" y2="0.508" width="0.1524" layer="51"/>
<wire x1="3.556" y1="0.508" x2="3.302" y2="0.508" width="0.1524" layer="51"/>
<wire x1="3.302" y1="0.508" x2="3.302" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="3.302" y1="-0.508" x2="3.556" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="3.556" y1="-0.508" x2="3.556" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="3.556" y1="-0.762" x2="4.064" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="4.064" y1="-0.762" x2="4.064" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="4.064" y1="-0.508" x2="4.318" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="4.318" y1="-0.508" x2="4.318" y2="0.508" width="0.1524" layer="51"/>
<wire x1="4.318" y1="0.508" x2="4.064" y2="0.508" width="0.1524" layer="51"/>
<wire x1="4.064" y1="0.508" x2="4.064" y2="0.762" width="0.1524" layer="51"/>
<wire x1="4.064" y1="0.762" x2="3.556" y2="0.762" width="0.1524" layer="51"/>
<wire x1="5.334" y1="1.27" x2="5.08" y2="1.016" width="0.1524" layer="21"/>
<wire x1="5.08" y1="1.016" x2="4.826" y2="1.27" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.016" x2="5.334" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.826" y1="-1.27" x2="5.08" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="6.096" y1="0.762" x2="6.096" y2="0.508" width="0.1524" layer="51"/>
<wire x1="6.096" y1="0.508" x2="5.842" y2="0.508" width="0.1524" layer="51"/>
<wire x1="5.842" y1="0.508" x2="5.842" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="5.842" y1="-0.508" x2="6.096" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="6.096" y1="-0.508" x2="6.096" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="6.096" y1="-0.762" x2="6.604" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="6.604" y1="-0.762" x2="6.604" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="6.604" y1="-0.508" x2="6.858" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="6.858" y1="-0.508" x2="6.858" y2="0.508" width="0.1524" layer="51"/>
<wire x1="6.858" y1="0.508" x2="6.604" y2="0.508" width="0.1524" layer="51"/>
<wire x1="6.604" y1="0.508" x2="6.604" y2="0.762" width="0.1524" layer="51"/>
<wire x1="6.604" y1="0.762" x2="6.096" y2="0.762" width="0.1524" layer="51"/>
<pad name="1" x="-6.35" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="2" x="-3.81" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="3" x="-1.27" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="4" x="1.27" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="5" x="3.81" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="6" x="6.35" y="0" drill="0.8128" shape="long" rot="R90"/>
<text x="-3.81" y="1.651" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-6.858" y="1.524" size="1.27" layer="21" ratio="10">1</text>
<text x="-7.62" y="-2.921" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="5.842" y="1.524" size="1.27" layer="21" ratio="10">6</text>
<rectangle x1="-6.477" y1="0.254" x2="-6.223" y2="0.762" layer="51"/>
<rectangle x1="-6.477" y1="-0.762" x2="-6.223" y2="-0.254" layer="51"/>
<rectangle x1="-3.937" y1="0.254" x2="-3.683" y2="0.762" layer="51"/>
<rectangle x1="-3.937" y1="-0.762" x2="-3.683" y2="-0.254" layer="51"/>
<rectangle x1="-1.397" y1="0.254" x2="-1.143" y2="0.762" layer="51"/>
<rectangle x1="-1.397" y1="-0.762" x2="-1.143" y2="-0.254" layer="51"/>
<rectangle x1="1.143" y1="0.254" x2="1.397" y2="0.762" layer="51"/>
<rectangle x1="1.143" y1="-0.762" x2="1.397" y2="-0.254" layer="51"/>
<rectangle x1="3.683" y1="0.254" x2="3.937" y2="0.762" layer="51"/>
<rectangle x1="3.683" y1="-0.762" x2="3.937" y2="-0.254" layer="51"/>
<rectangle x1="6.223" y1="0.254" x2="6.477" y2="0.762" layer="51"/>
<rectangle x1="6.223" y1="-0.762" x2="6.477" y2="-0.254" layer="51"/>
</package>
</packages>
<packages3d>
<package3d name="FE06" urn="urn:adsk.eagle:package:8191/1" type="box" library_version="2">
<description>FEMALE HEADER</description>
<packageinstances>
<packageinstance name="FE06"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="FE06-1" urn="urn:adsk.eagle:symbol:8134/1" library_version="2">
<wire x1="3.81" y1="-7.62" x2="-1.27" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="1.905" y1="0.635" x2="1.905" y2="-0.635" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="-1.905" x2="1.905" y2="-3.175" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="-4.445" x2="1.905" y2="-5.715" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="-1.27" y1="10.16" x2="-1.27" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-7.62" x2="3.81" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="10.16" x2="3.81" y2="10.16" width="0.4064" layer="94"/>
<wire x1="1.905" y1="5.715" x2="1.905" y2="4.445" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="3.175" x2="1.905" y2="1.905" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="8.255" x2="1.905" y2="6.985" width="0.254" layer="94" curve="-180" cap="flat"/>
<text x="-1.27" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<text x="-1.27" y="10.922" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="4" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="5" x="7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="6" x="7.62" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="FE06-1" urn="urn:adsk.eagle:component:8235/2" prefix="SV" uservalue="yes" library_version="2">
<description>&lt;b&gt;FEMALE HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="FE06-1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="FE06">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:8191/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
<attribute name="POPULARITY" value="11" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-lsta-4x2">
<description>&lt;b&gt;Female Headers etc.&lt;/b&gt;&lt;p&gt;
Naming:&lt;p&gt;
FE = female&lt;p&gt;
# contacts - # rows&lt;p&gt;
W = angled&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="FE04-2">
<description>&lt;b&gt;FEMALE HEADER&lt;/b&gt;</description>
<wire x1="-5.715" y1="3.048" x2="3.048" y2="3.048" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-2.413" x2="3.81" y2="2.413" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-2.413" x2="-6.35" y2="2.413" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-3.048" x2="3.048" y2="-3.048" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="2.413" x2="-5.715" y2="3.048" width="0.1524" layer="21" curve="-90"/>
<wire x1="3.048" y1="3.048" x2="3.81" y2="2.413" width="0.1524" layer="21" curve="-90"/>
<wire x1="3.048" y1="-3.048" x2="3.81" y2="-2.413" width="0.1524" layer="21" curve="90"/>
<wire x1="-6.35" y1="-2.413" x2="-5.715" y2="-3.048" width="0.1524" layer="21" curve="90"/>
<circle x="-5.08" y="-1.27" radius="0.127" width="0.4064" layer="51"/>
<circle x="-6.35" y="2.54" radius="0.127" width="0.4064" layer="51"/>
<circle x="-2.54" y="-1.27" radius="0.127" width="0.4064" layer="51"/>
<circle x="-2.54" y="1.27" radius="0.127" width="0.4064" layer="51"/>
<circle x="0" y="-1.27" radius="0.127" width="0.4064" layer="51"/>
<circle x="0" y="1.27" radius="0.127" width="0.4064" layer="51"/>
<circle x="2.54" y="-1.27" radius="0.127" width="0.4064" layer="51"/>
<circle x="2.54" y="1.27" radius="0.127" width="0.4064" layer="51"/>
<circle x="-5.08" y="-1.27" radius="0.889" width="0.1524" layer="51"/>
<circle x="-5.08" y="1.27" radius="0.889" width="0.1524" layer="51"/>
<circle x="-2.54" y="1.27" radius="0.889" width="0.1524" layer="51"/>
<circle x="0" y="1.27" radius="0.889" width="0.1524" layer="51"/>
<circle x="2.54" y="1.27" radius="0.889" width="0.1524" layer="51"/>
<circle x="-2.54" y="-1.27" radius="0.889" width="0.1524" layer="51"/>
<circle x="0" y="-1.27" radius="0.889" width="0.1524" layer="51"/>
<circle x="2.54" y="-1.27" radius="0.889" width="0.1524" layer="51"/>
<pad name="1" x="-5.08" y="1.27" drill="0.9144"/>
<pad name="2" x="-5.08" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="3" x="-2.54" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="4" x="-2.54" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="5" x="0" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="6" x="0" y="-1.27" drill="0.9144" shape="octagon"/>
<pad name="7" x="2.54" y="1.27" drill="0.9144" shape="octagon"/>
<pad name="8" x="2.54" y="-1.27" drill="0.9144" shape="octagon"/>
<text x="-2.54" y="3.429" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-5.461" y="3.429" size="1.27" layer="21" ratio="10">1</text>
<text x="-6.35" y="-4.699" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="4.191" y="-4.699" size="1.27" layer="21" ratio="10">8</text>
</package>
</packages>
<symbols>
<symbol name="FE04-2">
<wire x1="3.81" y1="-7.62" x2="-3.81" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="-1.905" y1="-0.635" x2="-1.905" y2="0.635" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="-1.905" y1="-3.175" x2="-1.905" y2="-1.905" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="-1.905" y1="-5.715" x2="-1.905" y2="-4.445" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="0.635" x2="1.905" y2="-0.635" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="-1.905" x2="1.905" y2="-3.175" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="-4.445" x2="1.905" y2="-5.715" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="-3.81" y1="5.08" x2="-3.81" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-7.62" x2="3.81" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-3.81" y1="5.08" x2="3.81" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-1.905" y1="1.905" x2="-1.905" y2="3.175" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="3.175" x2="1.905" y2="1.905" width="0.254" layer="94" curve="-180" cap="flat"/>
<text x="-3.81" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<text x="-3.81" y="5.842" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="-7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="3" x="-7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="5" x="-7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="2" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="4" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="6" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="7" x="-7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="8" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="FE04-2" prefix="SV" uservalue="yes">
<description>&lt;b&gt;FEMALE HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="FE04-2" x="0" y="5.08"/>
</gates>
<devices>
<device name="" package="FE04-2">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U1" library="memory-winbond" deviceset="W25Q16BV" device="DA"/>
<part name="U$1" library="atmel-avr" deviceset="ATMEGA328P-DIP" device="" package3d_urn="urn:adsk.eagle:package:17501351/1"/>
<part name="SV1" library="con-lsta" library_urn="urn:adsk.eagle:library:161" deviceset="FE06-1" device="" package3d_urn="urn:adsk.eagle:package:8191/1"/>
<part name="SV2" library="con-lsta-4x2" deviceset="FE04-2" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U1" gate="G$1" x="40.64" y="93.98" smashed="yes">
<attribute name="NAME" x="30.48" y="99.695" size="1.778" layer="95"/>
<attribute name="VALUE" x="30.48" y="83.82" size="1.778" layer="96"/>
</instance>
<instance part="U$1" gate="G$1" x="154.94" y="86.36" smashed="yes">
<attribute name="NAME" x="121.92" y="118.11" size="1.778" layer="95"/>
<attribute name="VALUE" x="121.92" y="50.8" size="1.778" layer="96"/>
</instance>
<instance part="SV1" gate="G$1" x="33.02" y="121.92" smashed="yes">
<attribute name="VALUE" x="31.75" y="111.76" size="1.778" layer="96"/>
<attribute name="NAME" x="31.75" y="132.842" size="1.778" layer="95"/>
</instance>
<instance part="SV2" gate="G$1" x="38.1" y="63.5" smashed="yes">
<attribute name="VALUE" x="34.29" y="53.34" size="1.778" layer="96"/>
<attribute name="NAME" x="34.29" y="69.342" size="1.778" layer="95"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="VCC" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="VCC"/>
<wire x1="50.8" y1="96.52" x2="66.04" y2="96.52" width="0.1524" layer="91"/>
<label x="60.96" y="96.52" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="VCC@4"/>
<wire x1="116.84" y1="78.74" x2="101.6" y2="78.74" width="0.1524" layer="91"/>
<label x="101.6" y="78.74" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SV2" gate="G$1" pin="8"/>
<wire x1="45.72" y1="66.04" x2="63.5" y2="66.04" width="0.1524" layer="91"/>
<label x="58.42" y="66.04" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SV1" gate="G$1" pin="6"/>
<wire x1="40.64" y1="129.54" x2="66.04" y2="129.54" width="0.1524" layer="91"/>
<label x="60.96" y="129.54" size="1.778" layer="95"/>
</segment>
</net>
<net name="SPI_CLK" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="CLK"/>
<wire x1="50.8" y1="91.44" x2="66.04" y2="91.44" width="0.1524" layer="91"/>
<label x="55.88" y="91.44" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SV2" gate="G$1" pin="3"/>
<wire x1="30.48" y1="60.96" x2="15.24" y2="60.96" width="0.1524" layer="91"/>
<label x="15.24" y="60.96" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SV1" gate="G$1" pin="4"/>
<wire x1="40.64" y1="124.46" x2="66.04" y2="124.46" width="0.1524" layer="91"/>
<label x="55.88" y="124.46" size="1.778" layer="95"/>
</segment>
</net>
<net name="SPI_MOSI" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="DI"/>
<wire x1="50.8" y1="88.9" x2="66.04" y2="88.9" width="0.1524" layer="91"/>
<label x="55.88" y="88.9" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT3/OC2A/MOSI)PB3"/>
<wire x1="193.04" y1="60.96" x2="205.74" y2="60.96" width="0.1524" layer="91"/>
<label x="198.12" y="60.96" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SV2" gate="G$1" pin="4"/>
<wire x1="45.72" y1="60.96" x2="63.5" y2="60.96" width="0.1524" layer="91"/>
<label x="50.8" y="60.96" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SV1" gate="G$1" pin="3"/>
<wire x1="40.64" y1="121.92" x2="66.04" y2="121.92" width="0.1524" layer="91"/>
<label x="55.88" y="121.92" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="!CS!"/>
<wire x1="27.94" y1="96.52" x2="12.7" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="SPI_MISO" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="DO"/>
<wire x1="27.94" y1="93.98" x2="12.7" y2="93.98" width="0.1524" layer="91"/>
<label x="12.7" y="93.98" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT4/MISO)PB4"/>
<wire x1="193.04" y1="58.42" x2="205.74" y2="58.42" width="0.1524" layer="91"/>
<label x="198.12" y="58.42" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SV2" gate="G$1" pin="1"/>
<wire x1="30.48" y1="58.42" x2="15.24" y2="58.42" width="0.1524" layer="91"/>
<label x="15.24" y="58.42" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SV1" gate="G$1" pin="1"/>
<wire x1="40.64" y1="116.84" x2="66.04" y2="116.84" width="0.1524" layer="91"/>
<label x="55.88" y="116.84" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="!WP!"/>
<wire x1="27.94" y1="91.44" x2="12.7" y2="91.44" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="GND"/>
<wire x1="27.94" y1="88.9" x2="12.7" y2="88.9" width="0.1524" layer="91"/>
<label x="12.7" y="88.9" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="GND@22"/>
<wire x1="116.84" y1="60.96" x2="101.6" y2="60.96" width="0.1524" layer="91"/>
<label x="101.6" y="60.96" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="GND@8"/>
<wire x1="116.84" y1="58.42" x2="101.6" y2="58.42" width="0.1524" layer="91"/>
<label x="101.6" y="58.42" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SV2" gate="G$1" pin="7"/>
<wire x1="30.48" y1="66.04" x2="15.24" y2="66.04" width="0.1524" layer="91"/>
<label x="17.78" y="66.04" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="SV1" gate="G$1" pin="5"/>
<wire x1="40.64" y1="127" x2="66.04" y2="127" width="0.1524" layer="91"/>
<label x="60.96" y="127" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="!HOLD!"/>
<wire x1="50.8" y1="93.98" x2="66.04" y2="93.98" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PC6(!RESET!)"/>
<wire x1="116.84" y1="114.3" x2="101.6" y2="114.3" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PB6(TOSC1/XTAL1/PCINT6)"/>
<wire x1="116.84" y1="106.68" x2="101.6" y2="106.68" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="PB7(TOSC2/XTAL2/PCINT7)"/>
<wire x1="116.84" y1="96.52" x2="101.6" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="AVCC"/>
<wire x1="116.84" y1="71.12" x2="101.6" y2="71.12" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="AREF"/>
<wire x1="116.84" y1="66.04" x2="101.6" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT8/ADC0)PC0"/>
<wire x1="193.04" y1="114.3" x2="205.74" y2="114.3" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT9/ADC1)PC1"/>
<wire x1="193.04" y1="111.76" x2="205.74" y2="111.76" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT10/ADC2)PC2"/>
<wire x1="193.04" y1="109.22" x2="205.74" y2="109.22" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT11/ADC3)PC3"/>
<wire x1="193.04" y1="106.68" x2="205.74" y2="106.68" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT12/SDA/ADC4)PC4"/>
<wire x1="193.04" y1="104.14" x2="205.74" y2="104.14" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT13/SCL/ADC5)PC5"/>
<wire x1="193.04" y1="101.6" x2="205.74" y2="101.6" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT16/RXD)PD0"/>
<wire x1="193.04" y1="91.44" x2="205.74" y2="91.44" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT17/TXD)PD1"/>
<wire x1="193.04" y1="88.9" x2="205.74" y2="88.9" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT18/INT0)PD2"/>
<wire x1="193.04" y1="86.36" x2="205.74" y2="86.36" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$21" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT20/XCK/T0)PD4"/>
<wire x1="193.04" y1="81.28" x2="205.74" y2="81.28" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$22" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT19/OC2B/INT1)PD3"/>
<wire x1="193.04" y1="83.82" x2="205.74" y2="83.82" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$23" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT21/OC0B/T1)PD5"/>
<wire x1="193.04" y1="78.74" x2="205.74" y2="78.74" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$24" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT22/OC0A/AIN0)PD6"/>
<wire x1="193.04" y1="76.2" x2="205.74" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$25" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT23/AIN1)PD7"/>
<wire x1="193.04" y1="73.66" x2="205.74" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$26" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT0/CLKO/ICP1)PB0"/>
<wire x1="193.04" y1="68.58" x2="205.74" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$27" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT1/OC1A)PB1"/>
<wire x1="193.04" y1="66.04" x2="205.74" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$28" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT2/!SS!/OC1B)PB2"/>
<wire x1="193.04" y1="63.5" x2="205.74" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$30" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="(PCINT5/SCK)PB5"/>
<wire x1="193.04" y1="55.88" x2="205.74" y2="55.88" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="SV2" gate="G$1" pin="5"/>
<wire x1="30.48" y1="63.5" x2="15.24" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$32" class="0">
<segment>
<pinref part="SV2" gate="G$1" pin="6"/>
<wire x1="45.72" y1="63.5" x2="63.5" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$34" class="0">
<segment>
<pinref part="SV2" gate="G$1" pin="2"/>
<wire x1="45.72" y1="58.42" x2="63.5" y2="58.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$33" class="0">
<segment>
<pinref part="SV1" gate="G$1" pin="2"/>
<wire x1="40.64" y1="119.38" x2="66.04" y2="119.38" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
