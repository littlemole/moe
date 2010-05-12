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
#include "xmlui.h"
<xsl:for-each select="./mol:include">
#include "<xsl:value-of select="." />"
</xsl:for-each>

using namespace mol;

</xsl:template>


</xsl:stylesheet>
