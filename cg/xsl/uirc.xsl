<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:mol="urn:mol-codegen"
                xmlns="urn:mol-codegen"
                xmlns:xs="http://www.w3.org/2001/XMLSchema"
                >
<xsl:output method="text"/>
<xsl:param name="OUTPUTPATH" />
<xsl:param name="padding" select="string('                                        ')"/>
<xsl:template match="/">
#include "include/resource.h"

//#########################################
//#<xsl:value-of select="$OUTPUTPATH" />
//#########################################
<xsl:call-template name="icons" />
<xsl:call-template name="bitmaps" />
<xsl:call-template name="resource" />
<xsl:call-template name="accelerators" />
<xsl:call-template name="typelibs" >
  <xsl:with-param name="outputpath" select="$OUTPUTPATH" />
</xsl:call-template>
<xsl:call-template name="menus" />

</xsl:template>

<xsl:template name="icons">
<xsl:for-each select="//mol:icons">

//ICONS

<xsl:for-each select="mol:icon">
<xsl:value-of select="concat(./@id,substring($padding,0,40-string-length(./@id)))"/>ICON    "<xsl:value-of select="./@src"/>"
</xsl:for-each>
</xsl:for-each>
</xsl:template>


<xsl:template name="bitmaps">

// BITMAPS

<xsl:for-each select="./*//mol:bitmap">
<xsl:value-of select="concat(./@id,substring($padding,0,40-string-length(./@id)))"/>BITMAP    "<xsl:value-of select="./@src"/>"
</xsl:for-each>
</xsl:template>

<xsl:template name="resource">
<xsl:if test="./@src!=string('')">

// dynamic resource

<xsl:value-of select="concat(./@id,substring($padding,0,40-string-length(./@id)))"/>    <xsl:value-of select="./@type"/>    "<xsl:value-of select="./@src"/>"
</xsl:if>
</xsl:template>


<xsl:template name="accelerators">
<xsl:for-each select="./*//mol:acceltable">

// ACCELERATORS

<xsl:value-of select="./@id"/>    ACCELERATORS
BEGIN
<xsl:for-each select="mol:accelerator">
 <xsl:value-of select="string('	')"/>
 <xsl:if test="./@key!=string('')"><xsl:value-of select="./@key"/>,<xsl:value-of select="substring($padding,0,20-string-length(./@key))"/></xsl:if>
 <xsl:if test="./@ch!=string('')">"<xsl:value-of select="./@ch"/>",<xsl:value-of select="substring($padding,0,20-string-length(./@ch))"/></xsl:if>
 <xsl:value-of select="./@cmd"/>,<xsl:value-of select="substring($padding,0,20-string-length(./@cmd))"/>	
 <xsl:value-of select="./@flags"/> //
</xsl:for-each>END
</xsl:for-each>
</xsl:template>

<xsl:template name="typelibs">
<xsl:param name="outputpath" />

// TYPELIBS

<xsl:for-each select="./*//mol:typelib">
<xsl:value-of select="concat(./@key,substring($padding,0,40-string-length(./@key)))"/>TYPELIB    <xsl:value-of select="$outputpath" />
</xsl:for-each>
</xsl:template>

<xsl:template name="menus">

// MENUS
<xsl:for-each select="./*//mol:menus/mol:menu">
// MENU <xsl:value-of select="./@id"/> //

<xsl:call-template name="menu"/>
</xsl:for-each>
</xsl:template>

<xsl:template name="menu">

<xsl:value-of select="./@id"/>    MENU
BEGIN
<xsl:for-each select="mol:menu">
<xsl:call-template name="popup"/>
</xsl:for-each>
END
</xsl:template>
  
<xsl:template name="popup">
<xsl:param name="cmd" select="./@cmd" />
<xsl:param name="separator" select="./@separator" />  
<xsl:param name="id" select="//mol:cmd[@id=$cmd]/@title" />
<xsl:if test="$separator=string('true')">
MENUITEM SEPARATOR
</xsl:if>
<xsl:if test="not($separator)">
<xsl:if test="count(./mol:menu) != 0">
POPUP "<xsl:value-of select="$id"/>"
BEGIN
<xsl:for-each select="./mol:menu">
<xsl:call-template name="popup"/>    
</xsl:for-each>  
END  
</xsl:if>
<xsl:if test="count(./*) = 0">
MENUITEM "<xsl:value-of select="$id"/>",    <xsl:value-of select="./@cmd"/><xsl:if test="./@checked=string('true')">, CHECKED</xsl:if>
</xsl:if>
</xsl:if>
</xsl:template>




</xsl:stylesheet>
