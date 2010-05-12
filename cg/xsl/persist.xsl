<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:mol="urn:mol-codegen"
                xmlns="urn:mol-codegen"
                xmlns:xs="http://www.w3.org/2001/XMLSchema"
                >
<xsl:output method="text"/>
<xsl:param name="padding" select="string('                                        ')"/>
<xsl:template match="/mol:codegen">
<xsl:for-each select="./mol:persistence">
<xsl:for-each select="./mol:class">
<xsl:call-template name="registerPersistence" />
</xsl:for-each>
</xsl:for-each>
</xsl:template>



<xsl:template name="registerPersistence">

<xsl:variable name="wndClass" select="./@type"/>
<xsl:for-each select="./mol:persist">
<xsl:variable name="name" select="./@name"/>
<xsl:variable name="vtype" select="./@vtype"/>
<xsl:variable name="property" select="./@property"/>
<xsl:variable name="member" select="./@member"/>
<xsl:if test="$property">
  mol::ole::properties&lt;<xsl:value-of select="$wndClass" />&gt;().add(mol::ole::make_property("<xsl:value-of select="$name" />", <xsl:value-of select="$property" />, <xsl:value-of select="$vtype" />, &amp;CLSID_NULL));
</xsl:if>
<xsl:if test="$member">
  mol::ole::properties&lt;<xsl:value-of select="$wndClass" />&gt;().add(mol::ole::make_property( &amp;<xsl:value-of select="$wndClass" />::<xsl:value-of select="$member" />,"<xsl:value-of select="$name" />"));
</xsl:if>
</xsl:for-each>
</xsl:template>  

</xsl:stylesheet>
