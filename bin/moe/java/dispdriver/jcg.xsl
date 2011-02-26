<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:mol="urn:mol-codegen"
                xmlns="urn:mol-codegen"
                xmlns:xs="http://www.w3.org/2001/XMLSchema"
                >

<xsl:output method="text"/>
<xsl:param name="filter" />
<xsl:param name="package" />
<xsl:param name="padding" select="string('                                        ')"/>

<xsl:template match="/typelib">
<xsl:variable name="typelibName" select="./@name"/>

<xsl:for-each select=".//interface">
<xsl:variable name="interface" select="./@name" />

<xsl:if test="$interface=$filter">
<xsl:variable name="objName" select="//object/implements[@default='true' and @type=$interface]/../@name" />
<xsl:variable name="progId" select="//object/implements[@default='true' and @type=$interface]/../@progId" />
<xsl:variable name="source" select="//object/implements[@default='true' and @type=$interface]/@source" />

<xsl:if test="$progId">
<xsl:if test="not($source=string('true'))">
@ProgId("<xsl:value-of select="$progId" />")</xsl:if></xsl:if>
public interface <xsl:value-of select="$interface" /> extends IUnknown {

<xsl:for-each select="./property/get">
<xsl:variable name="property" select="../@name"/>
<xsl:variable name="type" select="../@type"/>
<xsl:variable name="dispid" select="../@dispid"/>    @Dispid(<xsl:value-of select="$dispid" />)
	<xsl:call-template name="typeConverter"><xsl:with-param name="type" select="../@type"/></xsl:call-template> get<xsl:value-of select="$property" />();

</xsl:for-each>

<xsl:for-each select="./property/put">
<xsl:variable name="property" select="../@name"/>
<xsl:variable name="type" select="../@type"/>
<xsl:variable name="dispid" select="../@dispid"/>
<xsl:variable name="param" select="../@param"/>    @Dispid(<xsl:value-of select="$dispid" />)
	void set<xsl:value-of select="$property" />(<xsl:call-template name="typeConverter"><xsl:with-param name="type" select="../@type"/></xsl:call-template><xsl:value-of select="string(' ')" /><xsl:value-of select="$param" />);

</xsl:for-each>

<xsl:for-each select="./method">
<xsl:variable name="method" select="./@name"/>
<xsl:variable name="retType" select="./@type"/>
<xsl:variable name="dispid" select="./@dispid"/>    @Dispid(<xsl:value-of select="$dispid" />)
<xsl:value-of select="string('    ')" />
	<xsl:call-template name="typeConverter"><xsl:with-param name="type" select="./@type"/></xsl:call-template><xsl:value-of select="string(' ')" /><xsl:value-of select="$method" />( <xsl:for-each select="./param"><xsl:variable name="type" select="./@type"/><xsl:variable name="param" select="./@name"/><xsl:call-template name="typeConverter"><xsl:with-param name="type" select="./@type"/></xsl:call-template><xsl:value-of select="string(' ')" /><xsl:value-of select="$param" />
<xsl:if test="(position() != last()) and (last() &gt; 1)">, </xsl:if>
</xsl:for-each>);

</xsl:for-each>
}
</xsl:if>
</xsl:for-each>
</xsl:template>

<xsl:template name="typeConverter">
<xsl:param name="type" />
<xsl:choose>
<xsl:when test="$type=string('BSTR')">String</xsl:when>
<xsl:when test="$type=string('long')">int</xsl:when>
<xsl:when test="$type=string('int')">int</xsl:when>
<xsl:when test="$type=string('VARIANT_BOOL')">boolean</xsl:when>
<xsl:when test="$type=string('VARIANT')">Object</xsl:when>
<xsl:when test="$type=string('SAFEARRAY')">Object[]</xsl:when>
<xsl:when test="$type=string('void')">void</xsl:when>
<xsl:when test="$type=string('OLE_COLOR')">long</xsl:when>
<xsl:when test="$type=string('wireHWND')">long</xsl:when>
<xsl:when test="$type=string('IDispatch*')">IDispatch</xsl:when>
<xsl:when test="$type=string('BSTR*')">String</xsl:when>
<xsl:when test="$type=string('long*')">int</xsl:when>
<xsl:when test="$type=string('int*')">int</xsl:when>
<xsl:when test="$type=string('VARIANT_BOOL*')">boolean</xsl:when>
<xsl:when test="$type=string('VARIANT*')">Object</xsl:when>
<xsl:when test="$type=string('SAFEARRAY*')">Object[]</xsl:when>
<xsl:when test="$type=string('void*')">void</xsl:when>
<xsl:when test="$type=string('OLE_COLOR*')">long</xsl:when>
<xsl:when test="$type=string('wireHWND*')">long</xsl:when>
<xsl:when test="$type=string('IDispatch**')">IDispatch</xsl:when>
<xsl:when test="$type=string('SAFEARRAY**')">Object[]</xsl:when>
<xsl:when test="contains($type,'**')"><xsl:value-of select="substring-before($type,'**')" /></xsl:when>
<xsl:when test="contains($type,'*')"><xsl:value-of select="substring-before($type,'*')" /></xsl:when>

<xsl:otherwise>
<xsl:value-of select="$type" />
</xsl:otherwise>
</xsl:choose>
</xsl:template>

<xsl:template name="RemovePtr">
<xsl:param name="type" />
</xsl:template>
</xsl:stylesheet>
