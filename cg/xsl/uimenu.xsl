<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:mol="urn:mol-codegen"
                xmlns="urn:mol-codegen"
                xmlns:xs="http://www.w3.org/2001/XMLSchema"
                >

<xsl:output method="text"/>
<xsl:param name="padding" select="string('                                        ')"/>
<xsl:template match="/mol:codegen">

  // menus
<xsl:for-each select=".//mol:menus/mol:menu">
<xsl:variable name="menuId" select="./@id"/>
<xsl:variable name="menuBmp" select="./@bmp"/>  
  // a main menu
  UI().addMenu(<xsl:value-of select="$menuId" />);    
<xsl:for-each select="./mol:menu">
<xsl:variable name="cmd" select="./@cmd"/>
<xsl:variable name="title" select="./@title"/>
<xsl:variable name="children" select="count(./mol:menu)"/>
<xsl:if test="$children &gt; 0" >
    UI().addSubMenu(  <xsl:value-of select="$menuId" />,  <xsl:value-of select="$menuId" />,  <xsl:value-of select="$cmd" /> );
<xsl:for-each select="./mol:menu"><xsl:variable name="idx" select="./@bmp"/><xsl:if test="not($idx)">
<xsl:call-template name="menuMaker"><xsl:with-param name="root"><xsl:value-of select="$menuId" />
</xsl:with-param><xsl:with-param name="parent"><xsl:value-of select="$cmd" />
</xsl:with-param><xsl:with-param name="bmp"><xsl:value-of select="$menuBmp" />
</xsl:with-param><xsl:with-param name="idx"><xsl:value-of select="./@cmd" />
</xsl:with-param>
</xsl:call-template>
</xsl:if><xsl:if test="$idx">
<xsl:call-template name="menuMaker"><xsl:with-param name="root"><xsl:value-of select="$menuId" />
</xsl:with-param><xsl:with-param name="parent"><xsl:value-of select="$cmd" />
</xsl:with-param><xsl:with-param name="bmp"><xsl:value-of select="$menuBmp" />
</xsl:with-param><xsl:with-param name="idx"><xsl:value-of select="$idx" />
</xsl:with-param>
</xsl:call-template>
</xsl:if>
</xsl:for-each>
</xsl:if>
<xsl:if test="$children = 0" >    UI().addSubMenu(  <xsl:value-of select="$menuId" />,  <xsl:value-of select="$menuId" />,  <xsl:value-of select="$cmd" /> );
</xsl:if>
</xsl:for-each>
</xsl:for-each>


</xsl:template>

<xsl:template name="menuMaker">
<xsl:param name="root"  ></xsl:param>
<xsl:param name="parent"  ></xsl:param>
<xsl:param name="bmp"  ></xsl:param>
<xsl:param name="idx"  ></xsl:param>
<xsl:variable name="cmd" select="./@cmd"/>
<xsl:variable name="popup" select="./@popup"/>
<xsl:variable name="separator" select="./@separator"/>
<xsl:variable name="checked" select="./@checked"/>
<xsl:variable name="enabled" select="./@enabled"/>
<xsl:variable name="children" select="count(./mol:menu)"/>
<xsl:if test="not($separator) or $separator != string('true')" ><xsl:if test="$children &gt; 0 or $popup = string('true')" >    UI().addSubMenu(  <xsl:value-of select="$root" />, <xsl:value-of select="$parent" />, <xsl:value-of select="$cmd" />, <xsl:value-of select="$bmp" />);
<xsl:for-each select="./mol:menu"><xsl:call-template name="menuMaker">
<xsl:with-param name="root"><xsl:value-of select="$root" /></xsl:with-param>
<xsl:with-param name="parent"><xsl:value-of select="$cmd" /></xsl:with-param>
<xsl:with-param name="bmp"><xsl:value-of select="$bmp" /></xsl:with-param>
<xsl:with-param name="idx"><xsl:value-of select="$cmd" /></xsl:with-param>
</xsl:call-template>
</xsl:for-each>
</xsl:if><xsl:if test="$children = 0 and (not($popup) or $popup != string('true'))" ><xsl:if test="$checked = string('true') " ><xsl:if test="$enabled = string('false')" >        UI().addMenuItem(<xsl:value-of select="$root" />, <xsl:value-of select="$parent" />, <xsl:value-of select="$cmd" />, <xsl:value-of select="$bmp" />, <xsl:value-of select="$cmd" />, true, false);
</xsl:if><xsl:if test="not($enabled) or $enabled != string('false')" >        UI().addMenuItem(<xsl:value-of select="$root" />, <xsl:value-of select="$parent" />, <xsl:value-of select="$cmd" />, <xsl:value-of select="$bmp" />, <xsl:value-of select="$cmd" />, true, true);
</xsl:if></xsl:if><xsl:if test="not($checked) or $checked != string('true') " ><xsl:if test="$enabled = string('false')" >        UI().addMenuItem(<xsl:value-of select="$root" />, <xsl:value-of select="$parent" />, <xsl:value-of select="$cmd" />, <xsl:value-of select="$bmp" />, <xsl:value-of select="$cmd" />, false, false);
</xsl:if><xsl:if test="not($enabled) or $enabled != string('false')" >        UI().addMenuItem(<xsl:value-of select="$root" />, <xsl:value-of select="$parent" />, <xsl:value-of select="$cmd" />, <xsl:value-of select="$bmp" />, <xsl:value-of select="$cmd" />, false, true);
</xsl:if>
</xsl:if>
</xsl:if>
</xsl:if>
<xsl:if test="$separator = string('true')" >    UI().addMenuSeparator(<xsl:value-of select="$root" />,<xsl:value-of select="$parent" />);
</xsl:if>
</xsl:template>

  
</xsl:stylesheet>
