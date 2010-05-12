<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
                xmlns:mol="urn:mol-codegen"
                xmlns="urn:mol-codegen"
                xmlns:xs="http://www.w3.org/2001/XMLSchema"
                >
<xsl:output method="text"/>
<xsl:param name="padding" select="string('                                        ')"/>
<xsl:template match="/mol:codegen">
#ifndef MOL_MOE_XML_GENERATED_RESOURCE_UIH_DEFINES_DEF_GUARD_DEFINE
#define MOL_MOE_XML_GENERATED_RESOURCE_UIH_DEFINES_DEF_GUARD_DEFINE
#include "win/res.h"
#include "win/wnd.h"

<xsl:for-each select=".//mol:ui">
<xsl:for-each select="./mol:window">

<xsl:variable name="class" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="name" select="./@name"/>
<xsl:variable name="accessor" select="./@accessor"/>

class <xsl:value-of select="$class" />GUIBuilder : public mol::UIBuilder
{
  public:
    <xsl:value-of select="$class" />GUIBuilder( mol::win::WndProc* wnd )
  : mol::UIBuilder(wnd)
  {}

  virtual void loadUI();
  virtual void makeUI();
  };

  class <xsl:value-of select="$class" />;

template&lt;&gt;
class mol::GUIBuilder&lt;<xsl:value-of select="$class" />&gt;
  : public <xsl:value-of select="$class" />GUIBuilder
{
public:
  GUIBuilder( mol::win::WndProc* wnd )
  : <xsl:value-of select="$class" />GUIBuilder(wnd)
  {}
};

extern void init_ribbon_ui(mol::win::WndProc* wnd);

<xsl:if test="$accessor and $accessor!=string('false')">
<xsl:value-of select="$class" />* <xsl:value-of select="$name" />();
<xsl:call-template name="windowTypeFunction">
<xsl:with-param name="parent">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:if>
</xsl:for-each>
</xsl:for-each>


<xsl:for-each select=".//mol:ui">
<xsl:for-each select="./mol:mdi">

<xsl:variable name="class" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="name" select="./@name"/>

class <xsl:value-of select="$class" />GUIBuilder : public mol::UIBuilder
{
    public:
    <xsl:value-of select="$class" />GUIBuilder( mol::win::WndProc* wnd )
  : mol::UIBuilder(wnd)
  {}

  virtual void loadUI();
  virtual void makeUI();
};



class <xsl:value-of select="$class" />;

template&lt;&gt;
class mol::GUIBuilder&lt;<xsl:value-of select="$class" />&gt;
  : public <xsl:value-of select="$class" />GUIBuilder
{
public:
  GUIBuilder( mol::win::WndProc* wnd )
  : <xsl:value-of select="$class" />GUIBuilder(wnd)
  {}
};
</xsl:for-each>
</xsl:for-each>


<xsl:for-each select=".//mol:ui">
<xsl:for-each select="./mol:singleton">
<xsl:variable name="name" select="./@name"/>
<xsl:variable name="class" select="./@class"/>
<xsl:variable name="clsid" select="./@clsid"/>
<xsl:variable name="str" select="./@string"/>
<xsl:variable name="path" select="./@path"/>
<xsl:variable name="module" select="./@module"/>
<xsl:if test="$str or $path or $module">
const mol::string&amp; <xsl:value-of select="$name"/>();
</xsl:if>  
<xsl:if test="not($str) and not($path) and not($module)">
<xsl:call-template name="namespaceForward">
<xsl:with-param name="name" select ="$class"/>
<xsl:with-param name="clsid" select ="$clsid"/>
</xsl:call-template>
<xsl:value-of select="$class"/>* <xsl:value-of select="$name"/>();
</xsl:if>
</xsl:for-each>
</xsl:for-each>  


#endif

</xsl:template>
  
  
<xsl:template name="namespaceForward">
<xsl:param name="name" />
<xsl:param name="clsid" />
<xsl:variable name="ns" select="substring-before($name,string('::'))" />
<xsl:variable name="n" select="substring-after($name,string('::'))" />
<xsl:if test="not($ns)">
<xsl:if test="not($clsid)">
class <xsl:value-of select="$name"/>;    
</xsl:if>
<xsl:if test="$clsid">
struct <xsl:value-of select="$name"/>;
</xsl:if>
</xsl:if>
<xsl:if test="$ns">
namespace <xsl:value-of select="$ns"/> {
<xsl:call-template name="namespaceForward">
<xsl:with-param name ="name" select ="$n"/>
<xsl:with-param name="clsid" select ="$clsid"/>
</xsl:call-template>
}
</xsl:if>
</xsl:template>

  
<xsl:template name="windowTypeFunction">
<xsl:param name="parent"/>
<xsl:for-each select="./mol:window">
<xsl:call-template name="childWindowFunctionMaker">
<xsl:with-param name="parent">
<xsl:value-of select="$parent" />
</xsl:with-param>
</xsl:call-template>
</xsl:for-each>
<xsl:for-each select="./mol:statusbar">
<xsl:call-template name="statusBarFunctionMaker">
<xsl:with-param name="parent">
<xsl:value-of select="$parent" />
</xsl:with-param>
</xsl:call-template>
</xsl:for-each>
<xsl:for-each select="./mol:rebar">
<xsl:call-template name="reBarFunctionMaker">
<xsl:with-param name="parent">
<xsl:value-of select="$parent" />
</xsl:with-param>
</xsl:call-template>
</xsl:for-each>
</xsl:template>

<xsl:template name="childWindowFunctionMaker">
<xsl:param name="parent"/>
<xsl:variable name="class" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="name" select="./@name"/>
<xsl:variable name="accessor" select="./@accessor"/>
<xsl:if test="not($accessor) or $accessor!=string('false')">
//childWindow
class <xsl:value-of select="$class" />;
<xsl:value-of select="$class" />* <xsl:value-of select="$name" />();
<xsl:call-template name="windowTypeFunction">
<xsl:with-param name="parent">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:if>
</xsl:template>

<xsl:template name="statusBarFunctionMaker">
<xsl:param name="parent"/>
<xsl:variable name="class" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="name" select="./@name"/>

//statusbar
class <xsl:value-of select="$class" />;
<xsl:value-of select="$class" />* <xsl:value-of select="$name" />();
<xsl:call-template name="windowTypeFunction">
<xsl:with-param name="parent">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:template>


<xsl:template name="reBarFunctionMaker">
<xsl:param name="parent"/>
<xsl:variable name="class" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="name" select="./@name"/>

//reBar
class <xsl:value-of select="$class" />;
<xsl:value-of select="$class" />* <xsl:value-of select="$name" />();

<xsl:for-each select="./mol:toolbar">
<xsl:call-template name="rebarToolBarFunctionMaker">
<xsl:with-param name="parent">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:for-each>
<xsl:for-each select="./mol:bar">
//bar
<xsl:call-template name="rebarBarFunctionMaker">
<xsl:with-param name="parent">
<xsl:value-of select="$parent" />
</xsl:with-param>
<xsl:with-param name="rebar">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:for-each>
</xsl:template>


<xsl:template name="rebarToolBarFunctionMaker">
<xsl:param name="parent"/>
<xsl:variable name="class" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="name" select="./@name"/>

//toolBar
class <xsl:value-of select="$class" />;
<xsl:value-of select="$class" />* <xsl:value-of select="$name" />();

<xsl:call-template name="windowTypeFunction">
<xsl:with-param name="parent">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
      
</xsl:template>

<xsl:template name="rebarBarFunctionMaker">
<xsl:param name="parent"/>
<xsl:param name="rebar"/>
<xsl:variable name="class" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="name" select="./@name"/>
<xsl:variable name="accessor" select="./@accessor"/>

//rebar bar
class <xsl:value-of select="$class" />;
<xsl:value-of select="$class" />* <xsl:value-of select="$name" />();
<xsl:call-template name="windowTypeFunction">
<xsl:with-param name="parent">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:template>

  
  
</xsl:stylesheet>
