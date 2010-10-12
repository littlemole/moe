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

HRESULT __stdcall <xsl:value-of select="$wndClass" />::Load( LPSTREAM pStm)
{
    pStm
<xsl:for-each select="./mol:persist">
<xsl:variable name="vtype" select="./@vtype"/>
<xsl:variable name="property" select="./@property"/>
<xsl:variable name="member" select="./@member"/>
<xsl:if test="$property">
  &lt;&lt; mol::property( mol::DispId(this,<xsl:value-of select="$property" />,<xsl:value-of select="$vtype" />) )
</xsl:if>
<xsl:if test="$member">
  &lt;&lt; mol::property( &amp;<xsl:value-of select="$member" /> )
</xsl:if>
</xsl:for-each>;
  return S_OK;
  }


HRESULT __stdcall <xsl:value-of select="$wndClass" />::Save( LPSTREAM pStm,BOOL fClearDirty )
{
    pStm
<xsl:for-each select="./mol:persist">
<xsl:variable name="vtype" select="./@vtype"/>
<xsl:variable name="property" select="./@property"/>
<xsl:variable name="member" select="./@member"/>
<xsl:if test="$property">
  &gt;&gt; mol::property( mol::DispId(this,<xsl:value-of select="$property" />,<xsl:value-of select="$vtype" />) )
</xsl:if>
<xsl:if test="$member">
  &gt;&gt; mol::property( &amp;<xsl:value-of select="$member" /> )
</xsl:if>
</xsl:for-each>;
  return S_OK;
  }



HRESULT __stdcall <xsl:value-of select="$wndClass" />::Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog)
{
    pPropBag
<xsl:for-each select="./mol:persist">
<xsl:variable name="vtype" select="./@vtype"/>
<xsl:variable name="property" select="./@property"/>
<xsl:variable name="member" select="./@member"/>
<xsl:if test="$property">
  &lt;&lt; mol::property( _T("<xsl:value-of select="$property" />"), mol::DispId(this,<xsl:value-of select="$property" />,<xsl:value-of select="$vtype" />) )
</xsl:if>
<xsl:if test="$member">
  &lt;&lt; mol::property( _T("<xsl:value-of select="$member" />"), &amp;<xsl:value-of select="$member" /> )
</xsl:if>
</xsl:for-each>;
return S_OK;
}


HRESULT __stdcall <xsl:value-of select="$wndClass" />::Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties)
{
    pPropBag
<xsl:for-each select="./mol:persist">
<xsl:variable name="vtype" select="./@vtype"/>
<xsl:variable name="property" select="./@property"/>
<xsl:variable name="member" select="./@member"/>
<xsl:if test="$property">
  &gt;&gt; mol::property( _T("<xsl:value-of select="$property" />"), mol::DispId(this,<xsl:value-of select="$property" />,<xsl:value-of select="$vtype" />) )
</xsl:if>
<xsl:if test="$member">
  &gt;&gt; mol::property( _T("<xsl:value-of select="$member" />"), &amp;<xsl:value-of select="$member" /> )
</xsl:if>
</xsl:for-each>;
return S_OK;
}

</xsl:template>  

</xsl:stylesheet>
