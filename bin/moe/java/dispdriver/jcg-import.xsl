<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:mol="urn:mol-codegen"
                xmlns="urn:mol-codegen"
                xmlns:xs="http://www.w3.org/2001/XMLSchema"
                >

<xsl:key name="ktypes" match="//interface/*"  use="@type" />

<xsl:output method="text"/>
<xsl:param name="filter" />
<xsl:param name="package" />
<xsl:param name="padding" select="string('                                        ')"/>

<xsl:template match="/*">
<xsl:variable name="typelibName" select="./@name"/>

<xsl:for-each select=".//interface">
<xsl:variable name="interface" select="./@name" />

<xsl:if test="$interface=$filter">
<xsl:variable name="objName" select="//object/implements[@default='true' and @type=$interface]/../@name" />
<xsl:variable name="progId" select="//object/implements[@default='true' and @type=$interface]/../@progId" />
<xsl:variable name="source" select="//object/implements[@default='true' and @type=$interface]/@source" />
package <xsl:value-of select="$package" />;
<xsl:if test="$progId">
<xsl:if test="not($source=string('true'))">
import org.oha7.dispdriver.annotations.ProgId;</xsl:if></xsl:if>
import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

<xsl:for-each  select="key('ktypes', //*/@type)" >
<xsl:variable name="current" select="generate-id(.)"/>
<xsl:variable name="typ" select="./@type"/>
<xsl:variable name="list" select="generate-id(key('ktypes', ./@type)[1])"/>
<xsl:variable name="props" select="//interface[@name=$filter]//*[@type=$typ]" />

<xsl:if test="$current=$list">
<xsl:choose>
<xsl:when test="$props">
<xsl:call-template name="importer"><xsl:with-param name="type" select="./@type"/><xsl:with-param name="package" select="$package"/></xsl:call-template>
</xsl:when>
<xsl:otherwise></xsl:otherwise>
</xsl:choose>
</xsl:if>
</xsl:for-each> 


</xsl:if>
</xsl:for-each>
</xsl:template>

<xsl:template name="importer">
<xsl:param name="package" />
<xsl:param name="type" />
<xsl:choose>
<xsl:when test="$type=string('Dual')"></xsl:when>
<xsl:when test="$type=string('SAFEARRAY')"></xsl:when>
<xsl:when test="$type=string('BSTR')"></xsl:when>
<xsl:when test="$type=string('long')"></xsl:when>
<xsl:when test="$type=string('int')"></xsl:when>
<xsl:when test="$type=string('VARIANT_BOOL')"></xsl:when>
<xsl:when test="$type=string('VARIANT')"></xsl:when>
<xsl:when test="$type=string('void')"></xsl:when>
<xsl:when test="$type=string('wireHWND')"></xsl:when>
<xsl:when test="$type=string('OLE_COLOR')"></xsl:when>
<xsl:when test="$type=string('IDispatch')">import org.oha7.dispdriver.interfaces.IDispatch;
</xsl:when>
<xsl:when test="$type=string('IDispatch*')">import org.oha7.dispdriver.interfaces.IDispatch;
</xsl:when>
<xsl:when test="$type=string('IUnknown')"></xsl:when>
<xsl:when test="$type=string('IUnknown*')"></xsl:when>
<xsl:when test="$type=string('IEnumVARIANT*')">import org.oha7.dispdriver.interfaces.IEnumVARIANT;
</xsl:when>
<xsl:when test="$type=string('IFontDisp*')">import org.oha7.dispdriver.interfaces.IFontDisp;
</xsl:when>
<xsl:when test="$type=string('SAFEARRAY*')"></xsl:when>
<xsl:when test="$type=string('BSTR*')"></xsl:when>
<xsl:when test="$type=string('BSTR**')"></xsl:when>
<xsl:when test="$type=string('long*')"></xsl:when>
<xsl:when test="$type=string('long**')"></xsl:when>
<xsl:when test="$type=string('int*')"></xsl:when>
<xsl:when test="$type=string('int**')"></xsl:when>
<xsl:when test="$type=string('VARIANT_BOOL*')"></xsl:when>
<xsl:when test="$type=string('VARIANT_BOOL**')"></xsl:when>
<xsl:when test="$type=string('VARIANT*')"></xsl:when>
<xsl:when test="$type=string('VARIANT**')"></xsl:when>
<xsl:when test="$type=string('IDispatch**')">import org.oha7.dispdriver.interfaces.IDispatch;
</xsl:when>
<xsl:when test="$type=string('IUnknown**')"></xsl:when>
<xsl:when test="$type=string('OLE_COLOR*')"></xsl:when>
<xsl:when test="$type=string('wireHWND*')"></xsl:when>
<xsl:when test="$type=string('IEnumVARIANT**')">import org.oha7.dispdriver.interfaces.IEnumVARIANT;
</xsl:when>
<xsl:when test="$type=string('IFontDisp**')">import org.oha7.dispdriver.interfaces.IFontDisp;
</xsl:when>
<xsl:when test="$type=string('SAFEARRAY**')"></xsl:when>
<xsl:when test="$type=string('void*')"></xsl:when>
<xsl:when test="contains($type,'**')">import <xsl:value-of select="$package" />.<xsl:value-of select="substring-before($type,'**')" />;
</xsl:when>
<xsl:when test="contains($type,'*')">import <xsl:value-of select="$package" />.<xsl:value-of select="substring-before($type,'*')" />;
</xsl:when>

<xsl:otherwise>
import <xsl:value-of select="$package" />.<xsl:value-of select="$type" />;

</xsl:otherwise>
</xsl:choose>
</xsl:template>


</xsl:stylesheet>
