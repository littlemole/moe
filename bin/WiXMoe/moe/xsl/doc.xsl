<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
xmlns:wsdl="http://schemas.xmlsoap.org/wsdl/" 
xmlns:wsdlsoap="http://schemas.xmlsoap.org/wsdl/soap/" 
xmlns:xsd="http://www.w3.org/2001/XMLSchema"
xmlns:htm="http://www.w3.org/TR/xhtml1"
>

 <xsl:output method="html"/>
 <xsl:param name="object" select="string('')" />
 
<xsl:template match="/*">

 <div style="border:1p solid black;padding:5px">

  <xsl:if test="$object=string('')">

  <table>
   <tr>
    <td colspan="2">
     <h1 class="tab">Type library <xsl:value-of select="./@name" /></h1>
     <xsl:value-of select="./@desc" />
    </td>
   </tr>
   <tr>
    <td>Version:</td>
	<td><xsl:value-of select="./@major" />:<xsl:value-of select="./@minor" /></td>
   </tr>
   <tr>
    <td>GUID:</td>
	<td><xsl:value-of select="./@guid" /></td>
   </tr>
   <tr>
    <td>impl file:</td>
	<td><i><xsl:value-of select="./@file" /></i></td>
   </tr>
  </table>

  <h2>Objects</h2>
  <xsl:apply-templates select="/typelib/object" />
  <br/>
  <hr/>
  <br/>

  <h2>Interfaces</h2>
  <ul>
   <xsl:for-each select="/typelib/interface">
    <xsl:call-template name="makeInterfacesOverview" />
   </xsl:for-each>
  </ul>
  <xsl:for-each select="/typelib/interface">
   <xsl:call-template name="makeInterfaces" />
  </xsl:for-each>

  <h2>Enumerations</h2>
  <xsl:apply-templates select="/typelib/enum" />

 </xsl:if>

 <xsl:if test="object!=string('')">
  <xsl:variable name="objects" select="/typelib/object[@name=$object]" />
  <xsl:if test="count($objects)!=0">
   <xsl:apply-templates select="/typelib/object[@name=$object]" />
   <xsl:for-each select="/typelib/object[@name=$object]/implements">
    <xsl:variable name="type" select="./@type" />
    <xsl:for-each select="/typelib/interface[@name=$type]"> 
      <xsl:call-template name="makeInterfaces" />
    </xsl:for-each>
   </xsl:for-each>
  </xsl:if>

  <xsl:variable name="interfaces" select="count(/typelib/interface[@name=$object])" />
  <xsl:if test="$interfaces!=0">
   <xsl:for-each select="/typelib/interface[@name=$object]">
    <xsl:call-template name="makeInterfaces" />
   </xsl:for-each>
  </xsl:if>
 </xsl:if>

 </div>
</xsl:template>

<xsl:template name="makeInterfacesOverview">
 <xsl:variable name="name" select="./@name"/>
 <xsl:variable name="classType" select="//implements[./@type=$name]"/>
 <xsl:variable name="n" select="$classType/@type"/>

<xsl:if test="$n!=string('')">
 <li>
  <a>
   <xsl:attribute name="href">#<xsl:value-of select="$name" /></xsl:attribute>
   <xsl:value-of select="$name" />
  </a>
 </li>
</xsl:if>
</xsl:template>

<xsl:template name="makeInterfaces">
 <xsl:variable name="name" select="./@name"/>
 <xsl:variable name="classType" select="//implements[./@type=$name]"/>
 <xsl:variable name="n" select="$classType/@type"/>

<!-- <xsl:if test="$n!=string('')"> -->
 <xsl:call-template name="makeInterfaceOverview" />
 <xsl:call-template name="makeInterface" />
<!-- </xsl:if> -->
</xsl:template>

<xsl:template name="makeInterfaceOverview">
 <hr />
 <xsl:variable name="name" select="./@name"/>
 <xsl:variable name="classType" select="//implements[./@type=$name]"/>
 <xsl:variable name="isSource" select="$classType/@source"/>

 <a>
  <xsl:attribute name="name"><xsl:value-of select="$name" /></xsl:attribute>
  <xsl:attribute name="href">#<xsl:value-of select="$name" />Impl</xsl:attribute>

  <h3>
   <xsl:choose>
    <xsl:when test="$isSource=string('true')">Event </xsl:when>
    <xsl:otherwise>Interface </xsl:otherwise>
   </xsl:choose>
   <xsl:value-of select="./@name" />
  </h3>
 </a>

 <xsl:if test="count(./property)!=0">
  <ul>
   <xsl:for-each select="./property">
     <xsl:call-template name="propertyOverview">
      <xsl:with-param name="itfname" select="$name" />
     </xsl:call-template>
   </xsl:for-each>
  </ul>
 </xsl:if>


 <xsl:if test="count(./method)!=0">
  <ul>
   <xsl:for-each select="./method">
    <li>
     <xsl:call-template name="methodOverview">
      <xsl:with-param name="itfname" select="$name" />
     </xsl:call-template>
    </li>
   </xsl:for-each>
  </ul>
 </xsl:if>

</xsl:template>


<xsl:template name="makeInterface">
 <hr />
 <xsl:variable name="name" select="./@name"/>
 <xsl:variable name="classType" select="//implements[./@type=$name]"/>
 <xsl:variable name="isSource" select="$classType/@source"/>

 <a>
  <xsl:attribute name="name">
   <xsl:value-of select="$name" />Impl
  </xsl:attribute>
 </a>

 <h3>
  <xsl:choose>
   <xsl:when test="$isSource=string('true')">Event </xsl:when>
   <xsl:otherwise>Interface </xsl:otherwise>
  </xsl:choose>
  <xsl:value-of select="./@name" />
 </h3>

 <p><i><xsl:value-of select="./@desc" /></i></p>

 <xsl:if test="count(./property)!=0">
  <h4>properties:</h4>
  <xsl:apply-templates select="./property"/>
 </xsl:if>


 <xsl:if test="count(./method)!=0">
  <h4>methods:</h4>
  <xsl:apply-templates select="./method"/>
 </xsl:if>

</xsl:template>

<xsl:template name="propertyOverview">
 <xsl:param name="itfname" />
 <li>
  <a style="text-decoration:none">
   <xsl:attribute name="href">#<xsl:value-of select="$itfname" />_<xsl:value-of select="./@name" /></xsl:attribute>

   <small>
    <i>
     <xsl:if test="count(./get)!=0">{&#32;get</xsl:if>
     <xsl:if test="(count(./put)!=0 or count(./putref)!=0) and (count(./get)!=0)">/</xsl:if>
     <xsl:if test="(count(./put)!=0) or (count(./putref)!=0)">set</xsl:if>
    </i>&#32;<xsl:value-of select="string(' ')" /><xsl:value-of select="string(' ')" />
	<xsl:value-of select="string(' ')" />
    <xsl:call-template name="stripPointers">
     <xsl:with-param name="type" select="./@type" />
    </xsl:call-template>
	
	&#32;<i>&#32;}&#32;</i><xsl:value-of select="string(' ')" />
	<b><xsl:value-of select="./@name" /></b>
   </small>
  </a>
 </li>
</xsl:template>

<xsl:template match="property">
<hr/>
<div class="tab">

<a>
 <xsl:attribute name="name"><xsl:value-of select="../@name" />_<xsl:value-of select="./@name" /></xsl:attribute>
</a>

<i  class="tab">Property </i> <b class="tab"><xsl:value-of select="./@name" />&#32; </b>
<xsl:if test="count(./put)=0 and count(./putref)=0"> [ReadOnly]</xsl:if>
</div>
<br />
<xsl:if test="count(./put)!=0 or count(./putref)!=0">
<small>
set new <xsl:value-of select="./@param" /><xsl:value-of select="string(' ')" /><xsl:call-template name="typeMaker"><xsl:with-param name="type" select="./@type"/></xsl:call-template> to property <xsl:value-of select="./@name" />
</small>
</xsl:if>
<xsl:if test="count(./put)!=0 or count(./putref)!=0">
<br /><br />
<small class="js">[javascript]</small>
<pre>
<xsl:value-of select="string(' ')"/>
{object}.<xsl:value-of select="./@name" /> = <xsl:value-of select="./@param" />;
<xsl:value-of select="string(' ')"/>
</pre>
</xsl:if>

<xsl:if test="count(./get)!=0">
<small>
get <xsl:call-template name="typeMaker"><xsl:with-param name="type" select="./@type"/></xsl:call-template> from property <xsl:value-of select="./@name" />
</small>
</xsl:if>

<xsl:if test="count(./get)!=0">
<br />
<br />
<small class="js">[javascript]</small>
<pre >
<xsl:value-of select="string(' ')"/>
var value = {object}.<xsl:value-of select="./@name" />;
<xsl:value-of select="string(' ')"/>
</pre>
</xsl:if>

<small><xsl:value-of select="./@desc" /></small>
<br />
<br />
</xsl:template>

<xsl:template name="methodOverview">
 <xsl:param name="itfname" />

 <a style="text-decoration:none">
  <xsl:attribute name="href">#<xsl:value-of select="$itfname" />_<xsl:value-of select="./@name" /></xsl:attribute>
  <small>
   <xsl:if test="./@type!=string('void')">
    <xsl:call-template name="stripPointers">
     <xsl:with-param name="type" select="./@type" />
    </xsl:call-template>&#32;</xsl:if>
   <b><xsl:value-of select="string(' ')" /><xsl:value-of select="./@name" /></b>&#32;
   (
    <xsl:for-each select="param">
     <i>
      <xsl:call-template name="stripPointers">
       <xsl:with-param name="type" select="./@type" />
      </xsl:call-template>&#32;
     </i>&#32;<xsl:value-of select="string(' ')" />
     <xsl:value-of select="./@name" />
     <xsl:if test="position()!=last()">,</xsl:if>&#32;
    </xsl:for-each>
   )
  </small>
 </a>

</xsl:template>


<xsl:template match="method">
<hr />
<div class="tab">

<a>
 <xsl:attribute name="name"><xsl:value-of select="../@name" />_<xsl:value-of select="./@name" /></xsl:attribute>
</a>

<i class="tab">Method </i> <b class="tab"><xsl:value-of select="./@name" />&#32;</b>: 
</div>
<xsl:if test="./@type!=string('void')"><br /><small>returns <xsl:call-template name="typeMaker"><xsl:with-param name="type" select="./@type"/></xsl:call-template><br /></small></xsl:if>
<table>
 <xsl:for-each select="param">
  <tr>
   <td><small><xsl:value-of select="position()" />. param <b><xsl:value-of select="./@name" /></b></small></td>
   <td><small>[<xsl:value-of select="./@dir" />]</small></td>
   <td><small>: {<xsl:call-template name="typeMaker"><xsl:with-param name="type" select="./@type"/></xsl:call-template>}</small></td>
  </tr>
 </xsl:for-each>
</table>

<br/>
<small class="js">[javascript]</small>
<pre>
<xsl:value-of select="string(' ')"/><br />
<xsl:if test="./@type!=string('void')">var value = </xsl:if>{object}.<xsl:value-of select="./@name" />(<xsl:for-each select="param"><xsl:value-of select="./@name" /><xsl:if test="position()!=last()">,</xsl:if></xsl:for-each>);
<xsl:value-of select="string(' ')"/>
</pre>
<small><xsl:value-of select="./@desc" /></small>
</xsl:template>

<xsl:template match="object">

<h3>Object <i><xsl:value-of select="./@name" /></i></h3>
<small><xsl:value-of select="./@desc" /></small>
<table>
 <tr>
  <td>version:</td><td><xsl:value-of select="./@major" />.<xsl:value-of select="./@minor" /></td>
 </tr>
 <tr>
  <td>progID:</td><td><xsl:value-of select="./@progId" /></td>
 </tr>
 <tr>
  <td>GUID:</td><td><xsl:value-of select="./@guid" /></td>
 </tr>
</table>

<br />
<i>implements:</i>

<table>
<xsl:for-each select="implements">
 <xsl:if test="not(./@source)">
  <tr>
   <td>Interface <xsl:if test="./@default=string('true')">[default] </xsl:if></td>
   <td>:<a><xsl:attribute name="href">#<xsl:value-of select="./@type" /></xsl:attribute><xsl:value-of select="./@type" /></a></td>
  </tr>
 </xsl:if>
</xsl:for-each>
</table>

<xsl:if test="count(./implements[@source='true'])!=0">
<i>events:</i>
<table>
<xsl:for-each select="implements">
 <xsl:if test="./@source=string('true')">
  <tr>
   <td>EventInterface <xsl:if test="./@default=string('true')">[default] </xsl:if></td>
   <td>:<a><xsl:attribute name="href">#<xsl:value-of select="./@type" /></xsl:attribute><xsl:value-of select="./@type" /></a></td>
  </tr>
 </xsl:if>
</xsl:for-each>
</table>
</xsl:if>

</xsl:template>

<xsl:template match="enum">
 <div>
  enum <b><xsl:value-of select="./@type" /></b> {<br/>
  <xsl:for-each select="element">
   <xsl:value-of select="./@name" /> = <xsl:value-of select="./@value" />
   <xsl:if test="position()!=last()">,</xsl:if>
   <br/>
  </xsl:for-each>
  <br/>
 }
 </div>
</xsl:template>

<xsl:template name="stripPointers">
 <xsl:param name="type" />
 <xsl:variable name="val" select="substring-before($type,'*')" />
 <xsl:if test="$val=string('')"><xsl:value-of select="$type" /></xsl:if>
 <xsl:if test="$val!=string('')"><xsl:value-of select="$val" /></xsl:if>
</xsl:template>

<xsl:template name="typeMaker">
<xsl:param name="type" />
<xsl:choose>
 <xsl:when test="substring($type,1,1)=string('I') and substring($type,string-length($type))=string('*')">object of type <i><xsl:value-of select="substring-before($type,'*')" /></i></xsl:when>
 <xsl:when test="$type='BSTR' or substring-before($type,string('*'))=string('BSTR')">string-value</xsl:when>
 <xsl:when test="$type='VARIANT' or substring-before($type,string('*'))=string('VARIANT')">variant-value</xsl:when>
 <xsl:when test="$type='VARIANT_BOOL' or substring-before($type,string('*'))=string('VARIANT_BOOL')">boolean-value</xsl:when>
 <xsl:when test="$type='long' or substring-before($type,string('*'))=string('long')">numeric-value</xsl:when>
 <xsl:when test="$type='int' or substring-before($type,string('*'))=string('int')">numeric-value</xsl:when>
 <xsl:when test="$type='double' or substring-before($type,string('*'))=string('double')">numeric-value</xsl:when>
 <xsl:when test="$type='float' or substring-before($type,string('*'))=string('float')">numeric-value</xsl:when>
 <xsl:otherwise>value</xsl:otherwise>
</xsl:choose></xsl:template>

</xsl:stylesheet>
