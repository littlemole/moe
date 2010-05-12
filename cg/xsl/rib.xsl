<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
                xmlns:mol="urn:mol-codegen"
                xmlns="urn:mol-codegen"
                xmlns:xs="http://www.w3.org/2001/XMLSchema"
                >
<xsl:output method="text"/>
<xsl:param name="padding" select="string('                                        ')"/>
<xsl:template match="/mol:codegen">
#include "stdafx.h"
#include "win/res.h"
#include "win/wnd.h"
#include "ole/rib.h"
#include "ribbonres.h"

<xsl:for-each select=".//mol:cmds">

void init_ribbon_ui(  mol::win::WndProc* wnd )
{

<xsl:for-each select="./mol:cmd">

    <xsl:variable name="ribbon" select="./@ribbon"/>
    <xsl:variable name="id" select="./@id"/>
    <xsl:variable name="title" select="./@title"/>
    <xsl:variable name="notify" select="./@notify"/>

  <xsl:if test="$notify and $notify!=string('') and $ribbon and $ribbon!=string('')">
    mol::Ribbon::ribbon()->registerNotification(*wnd,<xsl:value-of select="$ribbon" />, <xsl:value-of select="$id" />, <xsl:value-of select="$notify" /> );
  </xsl:if>
  <xsl:if test="not($notify) and $ribbon and $ribbon!=string('')">
    mol::Ribbon::ribbon()->registerCommand(*wnd,<xsl:value-of select="$ribbon" />, <xsl:value-of select="$id" /> );
  </xsl:if>    
</xsl:for-each>

}
</xsl:for-each>
</xsl:template>
</xsl:stylesheet>
