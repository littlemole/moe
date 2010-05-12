<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:mol="urn:mol-codegen"
                xmlns="urn:mol-codegen"
                xmlns:xs="http://www.w3.org/2001/XMLSchema"
                >

<xsl:output method="text"/>
<xsl:param name="padding" select="string('                                        ')"/>
<xsl:template match="/mol:codegen">


extern "C" void load_codegen_metadata()
{
  ODBGS("load_codegen_metadata()");
  // prepare commands - associates a title string for each command identifier
  <xsl:for-each select=".//mol:cmds/mol:cmd">  UI().addCmd(<xsl:value-of select="./@id" />,_T("<xsl:value-of select="./@title" />"));  
</xsl:for-each>
</xsl:template>
</xsl:stylesheet>
