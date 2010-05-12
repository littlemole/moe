<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:mol="urn:mol-codegen"
                xmlns="urn:mol-codegen"
                xmlns:xs="http://www.w3.org/2001/XMLSchema"
                >

<xsl:output method="text"/>
<xsl:param name="padding" select="string('                                        ')"/>
<xsl:template match="/mol:codegen">
  
  //foreach bitmap - loads and registers bitmap
  // optionally associate cmds to toolbar icons on bitmap
  <xsl:for-each select=".//mol:bitmaps/mol:bitmap">
<xsl:variable name="id" select="./@id"/>  
  UI().addBmp(<xsl:value-of select="$id" />);
<xsl:for-each select="./mol:index">
<xsl:variable name="cmd" select="./@cmd"/>
<xsl:if test="not($cmd) or $cmd = string('')">  UI().addBmpCmd( <xsl:value-of select="$id" />, -1 );
</xsl:if>
<xsl:if test="$cmd!=string('')">  UI().addBmpCmd( <xsl:value-of select="$id" />, <xsl:value-of select="$cmd" /> );
</xsl:if>

</xsl:for-each>
</xsl:for-each>

</xsl:template>

</xsl:stylesheet>
