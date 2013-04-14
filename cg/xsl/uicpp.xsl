<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:mol="urn:mol-codegen"
                xmlns="urn:mol-codegen"
                xmlns:xs="http://www.w3.org/2001/XMLSchema"
                >
<xsl:output method="text"/>
<xsl:param name="padding" select="string('                                        ')"/>
<xsl:template match="/mol:codegen">


<xsl:for-each select=".//mol:ui">
<xsl:for-each select="./mol:window">
<xsl:variable name="name" select="./@name"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="wndClass" select="./@class"/>
<xsl:variable name="pos" select="./@pos"/>
<xsl:variable name="menu" select="./@menu"/>

void <xsl:value-of select="$wndClass" />GUIBuilder::loadUI()
{
<xsl:if test="$id">
<xsl:value-of select="concat(string('    '),$wndClass)" />* <xsl:value-of select="$name" /> = (<xsl:value-of select="$wndClass" />*)wnd_;
<xsl:choose>
<xsl:when test="$menu">
    makeMainWindow( <xsl:value-of select="$name" />, _T("<xsl:value-of select="$name" />"), (HMENU)<xsl:value-of select="$menu" />, <xsl:value-of select="$pos"  />, <xsl:value-of select="$id"  /> );
</xsl:when>
<xsl:otherwise>
    makeMainWindow( <xsl:value-of select="$name" />, _T("<xsl:value-of select="$name" />"), (HMENU)0, <xsl:value-of select="$pos"  />, <xsl:value-of select="$id"  /> );
</xsl:otherwise>
</xsl:choose>
</xsl:if>
}

</xsl:for-each>
</xsl:for-each>

  // window
<xsl:for-each select=".//mol:ui">
<xsl:for-each select="./mol:window">
<xsl:variable name="windowClass" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="pos" select="./@pos"/>
<xsl:variable name="name" select="./@name"/>
<xsl:variable name="menu" select="./@menu"/>
<xsl:variable name="layout" select="./@layout"/>
<xsl:variable name="visible" select="./@visible"/>
<xsl:variable name="mdi" select="./@mdi"/>
<xsl:variable name="show" select="./@show" />
<xsl:variable name="accel" select="./@accel" />
<xsl:variable name="persistFile" select="./@persistFile"/>
<xsl:variable name="persistStorage" select="./@persistStorage"/>
<xsl:variable name="dragDrop" select="./@dragDrop"/>

void <xsl:value-of select="$windowClass" />GUIBuilder::makeUI()
{

<xsl:value-of select="concat(string('    '),$windowClass)" />* <xsl:value-of select="$name" /> = (<xsl:value-of select="$windowClass" />*)wnd_;
<xsl:value-of select="concat(string('    '),$layout)" />* layout = <xsl:value-of select="$name" />-&gt;setLayout(new <xsl:value-of select="$layout" />);
<xsl:call-template name="windowType">
  <xsl:with-param name="parent">
    <xsl:value-of select="$name" />
  </xsl:with-param>
</xsl:call-template>
<xsl:if test="$mdi">
  layout->add(<xsl:value-of select="$name" />-&gt;mdiClient(),BorderLayout::FILL);
</xsl:if>
  
<xsl:if test="$persistFile">

    // load persist UI state
    mol::string p(<xsl:value-of select="$persistFile" />);
    if ( mol::Path::exists(p) )
    {
       mol::punk&lt;IPersistFile&gt; pf;
       <xsl:value-of select="$name" />-&gt;(IID_IPersistStorage, (void**)&amp;pf);
       pf->Load( mol::towstring(p).c_str(),FALSE );
    }  
</xsl:if>
 


<xsl:if test="$dragDrop">

    // drag n drop    
    ::RegisterDragDrop(*<xsl:value-of select="$name" />,<xsl:value-of select="$dragDrop" />);
    
</xsl:if>
<xsl:if test="$accel">
  // keybord shortcuts (accellerators)
  mol::win::accelerators().load(<xsl:value-of select="$accel" />,*<xsl:value-of select="$name" />);
</xsl:if>
<xsl:if test="$show">

</xsl:if>
<xsl:for-each select="./mol:olemenu">
    // hook up ole container menus for OLE embedding
<xsl:if test="$mdi">
<xsl:value-of select="concat(string('    '),$name)" />-&gt;setWindowMenu(mol::UI().SubMenu(<xsl:value-of select="./@menu" />,<xsl:value-of select="$mdi" />));
</xsl:if>
<xsl:variable name="olemenu" select="./@menu"/>
<xsl:for-each select="./mol:file">
<xsl:variable name="cmd" select="./@cmd"/>
<xsl:value-of select="concat(string('    '),$name)" />-&gt;addFileMenu(mol::UI().SubMenu(<xsl:value-of select="$olemenu" />, <xsl:value-of select="$cmd" />), mol::UI().CmdString(<xsl:value-of select="$cmd" />) );
</xsl:for-each>
<xsl:for-each select="./mol:edit">
<xsl:variable name="cmd" select="./@cmd"/>
<xsl:value-of select="concat(string('    '),$name)" />-&gt;addEditMenu(mol::UI().SubMenu(<xsl:value-of select="$olemenu" />, <xsl:value-of select="$cmd" />), mol::UI().CmdString(<xsl:value-of select="$cmd" />) );
</xsl:for-each>
<xsl:for-each select="./mol:view">
    <xsl:variable name="cmd" select="./@cmd"/>
    <xsl:value-of select="concat(string('    '),$name)" />-&gt;addViewMenu(mol::UI().SubMenu(<xsl:value-of select="$olemenu" />, <xsl:value-of select="$cmd" />), mol::UI().CmdString(<xsl:value-of select="$cmd" />) );
</xsl:for-each>
<xsl:for-each select="./mol:object">
    <xsl:variable name="cmd" select="./@cmd"/>
    <xsl:value-of select="concat(string('    '),$name)" />-&gt;addObjectMenu(mol::UI().SubMenu(<xsl:value-of select="$olemenu" />, <xsl:value-of select="$cmd" />), mol::UI().CmdString(<xsl:value-of select="$cmd" />) );
</xsl:for-each>
<xsl:for-each select="./mol:window">
<xsl:variable name="cmd" select="./@cmd"/>
    <xsl:value-of select="concat(string('    '),$name)" />-&gt;addWindowMenu(mol::UI().SubMenu(<xsl:value-of select="$olemenu" />, <xsl:value-of select="$cmd" />), mol::UI().CmdString(<xsl:value-of select="$cmd" />) );
</xsl:for-each>
<xsl:for-each select="./mol:help">
<xsl:variable name="cmd" select="./@cmd"/>
  <xsl:value-of select="concat(string('    '),$name)" />-&gt;addHelpMenu(mol::UI().SubMenu(<xsl:value-of select="$olemenu" />, <xsl:value-of select="$cmd" />), mol::UI().CmdString(<xsl:value-of select="$cmd" />) );
</xsl:for-each>
</xsl:for-each>
<xsl:for-each select="./mol:olecmds">
<xsl:for-each select="./mol:olecmd">
<xsl:variable name="cmd" select="./@cmd"/>
<xsl:variable name="target" select="./@oletarget"/>
<xsl:value-of select="concat(string('    '),$name)" />-&gt;addOlExecHandler( <xsl:value-of select="$target" />, <xsl:value-of select="$cmd" /> );
</xsl:for-each>
</xsl:for-each>

  init_ribbon_ui(wnd_);

  // redraw
  // <xsl:value-of select="$name" />-&gt;show(SW_SHOW);
  // <xsl:value-of select="$name" />-&gt;OnLayout(0,0,0);
  // <xsl:value-of select="$name" />-&gt;redraw();
  
<xsl:if test="$persistStorage">

  // load persist UI state
  mol::string p(<xsl:value-of select="$persistStorage" />);
  if ( mol::Path::exists(p) )
  {
  mol::punk&lt;IPersistStorage&gt; ps;
  <xsl:value-of select="$name" />-&gt;QueryInterface( IID_IPersistStorage, (void**)&amp;ps);
  Storage store;
  if ( store.open(p, STGM_READWRITE|STGM_SHARE_EXCLUSIVE) )
  {
  ps->Load( store );
  }
  }
</xsl:if>
delete this;
}

</xsl:for-each>
</xsl:for-each>



      <!--

// actrl
<xsl:for-each select=".//mol:ui">
<xsl:for-each select="./mol:axctrl">
<xsl:variable name="windowClass" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="pos" select="./@pos"/>
<xsl:variable name="name" select="./@name"/>
<xsl:variable name="menu" select="./@menu"/>
<xsl:variable name="layout" select="./@layout"/>
<xsl:variable name="visible" select="./@visible"/>
<xsl:variable name="show" select="./@show" />

void <xsl:value-of select="$windowClass" />GUIBuilder::makeUI()
{

<xsl:value-of select="concat(string('    '),$windowClass)" />* <xsl:value-of select="$name" /> = (<xsl:value-of select="$windowClass" />*)wnd_;
<xsl:value-of select="concat(string('    '),$layout)" />* layout = <xsl:value-of select="$name" />-&gt;setLayout(new <xsl:value-of select="$layout" />);
<xsl:call-template name="windowType">
<xsl:with-param name="parent">
  <xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>

  // redraw
<xsl:value-of select="$name" />-&gt;OnLayout(0,0,0);
<xsl:value-of select="$name" />-&gt;redraw();

  delete this;
}

</xsl:for-each>
</xsl:for-each>


-->









<xsl:for-each select=".//mol:ui">
<xsl:for-each select="./mol:window">
<xsl:variable name="class" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="name" select="./@name"/>
<xsl:variable name="accessor" select="./@accessor"/>
<xsl:if test="$accessor and $accessor!=string('false')">
<xsl:value-of select="concat(string('    '),$class)" />* <xsl:value-of select="$name" />() { return mol::UI().Wnd&lt;<xsl:value-of select="$class" />&gt;(<xsl:value-of select="$id" />); }
<xsl:call-template name="windowTypeFunction">
<xsl:with-param name="parent">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:if>
</xsl:for-each>
</xsl:for-each>

<xsl:for-each select=".//mol:ui">
<xsl:for-each select="./mol:singleton">
<xsl:variable name="name" select="./@name"/>
<xsl:variable name="class" select="./@class"/>
<xsl:variable name="clsid" select="./@clsid"/>
<xsl:variable name="iid" select="./@iid"/>
<xsl:variable name="interface" select="./@interface"/>
<xsl:variable name="str" select="./@string"/>
<xsl:variable name="path" select="./@path"/>
<xsl:variable name="module" select="./@module"/>

<xsl:if test="$clsid">
<xsl:if test="$iid">
<xsl:value-of select="$class"/>* <xsl:value-of select="$name"/>()
{
  return mol::comSingleton&lt;<xsl:value-of select="$class"/>,<xsl:value-of select="$clsid"/>,<xsl:value-of select="$iid"/>&gt;();
}
</xsl:if>
<xsl:if test="not($iid)">
<xsl:value-of select="$class"/>* <xsl:value-of select="$name"/>()
{
  return mol::comSingleton&lt;<xsl:value-of select="$class"/>,&amp;<xsl:value-of select="$clsid"/>&gt;();
}
</xsl:if>
</xsl:if>

<xsl:if test="$interface">
<xsl:value-of select="$class"/>* <xsl:value-of select="$name"/>()
  {
  return mol::nonCreatableCOMSingleton&lt;<xsl:value-of select="$class"/>,<xsl:value-of select="$interface"/>&gt;();
}
</xsl:if>

<xsl:if test="$str">
const mol::string&amp; <xsl:value-of select="$name"/>()
  {
  static const mol::string <xsl:value-of select="$name"/>_ = <xsl:value-of select="$str"/>;
  return <xsl:value-of select="$name"/>_;
}
</xsl:if>

<xsl:if test="$path">
const mol::string&amp; <xsl:value-of select="$name"/>()
  {
  static const mol::string <xsl:value-of select="$name"/>_ = mol::app&lt;AppBase&gt;().CreateAppPath(_T("<xsl:value-of select="$path"/>"));
  return <xsl:value-of select="$name"/>_;
}
</xsl:if>

<xsl:if test="$module">
const mol::string&amp; <xsl:value-of select="$name"/>()
  {
  static const mol::string <xsl:value-of select="$name"/>_ = mol::app&lt;AppBase&gt;().getModulePath();
  return <xsl:value-of select="$name"/>_;
}
</xsl:if>

<xsl:if test="not($interface) and not($clsid) and not($str) and not($path) and not ($module)">
<xsl:value-of select="$class"/>* <xsl:value-of select="$name"/>()
{
  return &amp;mol::singleton&lt;<xsl:value-of select="$class"/>&gt;();
}
</xsl:if>

</xsl:for-each>
</xsl:for-each>
</xsl:template>

<xsl:template name="windowType">
<xsl:param name="parent"/>
  <xsl:for-each select="./mol:window">
    <xsl:call-template name="childWindowMaker">
    <xsl:with-param name="parent">
      <xsl:value-of select="$parent" />
    </xsl:with-param>
  </xsl:call-template>
  </xsl:for-each>
  <xsl:for-each select="./mol:statusbar">
    <xsl:call-template name="statusBarMaker">
      <xsl:with-param name="parent">
        <xsl:value-of select="$parent" />
      </xsl:with-param>
    </xsl:call-template>
  </xsl:for-each>
  <xsl:for-each select="./mol:rebar">
    <xsl:call-template name="reBarMaker">
      <xsl:with-param name="parent">
        <xsl:value-of select="$parent" />
      </xsl:with-param>
    </xsl:call-template>
  </xsl:for-each>
</xsl:template>    

<xsl:template name="childWindowMaker">
<xsl:param name="parent"/>
<xsl:variable name="windowClass" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="name" select="./@name"/>
<xsl:variable name="pos" select="./@pos"/>
<xsl:variable name="advise" select="./@advise_disabled"/>
<xsl:variable name="layout" select="./@layout"/>
<xsl:variable name="visible" select="./@visible"/>
    //childWindow
    <xsl:value-of select="$windowClass" />* <xsl:value-of select="$name" /> = makeWindow&lt;<xsl:value-of select="$windowClass" />&gt;((HMENU)<xsl:value-of select="$id" />, <xsl:value-of select="$pos"  />, (HWND)*<xsl:value-of select="$parent"  />);
<xsl:if test="not($visible) or $visible != string('false')">
    <xsl:value-of select="concat(string('    '),$name)" />-&gt;show(SW_SHOW);
</xsl:if>
<xsl:if test="$visible != string('true')">
    <xsl:value-of select="concat(string('    '),$name)" />-&gt;show(SW_HIDE);
</xsl:if>
<xsl:if test="$layout and $layout!=string('')">
    layout->add( *<xsl:value-of select="$name" />, <xsl:value-of select="$layout" /> );
</xsl:if>
<xsl:if test="$layout=string('')">
    layout->add( *<xsl:value-of select="$name" />);
</xsl:if>
<xsl:if test="$advise != string('')">
   <xsl:value-of select="concat(string('    '),$advise)" />-&gt;Advise(<xsl:value-of select="$name" />&lt;oleObject&gt;);
</xsl:if>
<xsl:for-each select="./mol:add">
<xsl:call-template name="add"><xsl:with-param name="name"><xsl:value-of select="$name" /></xsl:with-param>
</xsl:call-template>
</xsl:for-each>
<xsl:for-each select="./mol:set">
<xsl:call-template name="set">
<xsl:with-param name="name">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:for-each>
<xsl:call-template name="windowType">
<xsl:with-param name="parent">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:template>
  
<xsl:template name="statusBarMaker">
<xsl:param name="parent"/>
<xsl:variable name="windowClass" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="name" select="./@name"/>
<xsl:variable name="visible" select="./@visible"/>
    //statusbar
    <xsl:value-of select="$windowClass" />* <xsl:value-of select="$name" /> = makeWindow&lt;<xsl:value-of select="$windowClass" />&gt;((HMENU)<xsl:value-of select="$id" />, stdRect, (HWND)*<xsl:value-of select="$parent" />);
<xsl:if test="not($visible) or $visible != string('false')">
<xsl:value-of select="concat(string('    '),$name)" />-&gt;show(SW_SHOW);
</xsl:if>
<xsl:if test="$visible != string('true')">
<xsl:value-of select="$name" />-&gt;show(SW_HIDE);
</xsl:if>
    layout->addStatusBar( <xsl:value-of select="$name" /> );
<xsl:for-each select="./mol:add">
<xsl:call-template name="add">
<xsl:with-param name="name">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:for-each>
<xsl:for-each select="./mol:set">
<xsl:call-template name="set">
<xsl:with-param name="name">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:for-each>
<xsl:call-template name="windowType">
<xsl:with-param name="parent">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>


</xsl:template>
   
<xsl:template name="reBarMaker">
<xsl:param name="parent"/>
<xsl:variable name="windowClass" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="name" select="./@name"/>
<xsl:variable name="pos" select="./@pos"/>
<xsl:variable name="layout" select="./@layout"/>
<xsl:variable name="visible" select="./@visible"/>
    //reBar
    <xsl:value-of select="$windowClass" />* <xsl:value-of select="$name" /> = makeWindow &lt; <xsl:value-of select="$windowClass" />&gt;((HMENU)<xsl:value-of select="$id" />, <xsl:value-of select="$pos"  />, (HWND)*<xsl:value-of select="$parent"  />);
<xsl:for-each select="./mol:toolbar">
<xsl:call-template name="rebarToolBarMaker">
<xsl:with-param name="parent">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:for-each>
<xsl:for-each select="./mol:bar">
    //bar
<xsl:call-template name="rebarBarMaker">
<xsl:with-param name="parent"><xsl:value-of select="$parent" /></xsl:with-param>
<xsl:with-param name="rebar"><xsl:value-of select="$name" /></xsl:with-param>
</xsl:call-template>
</xsl:for-each>
<xsl:if test="not($visible) or $visible != string('false')">
<xsl:value-of select="concat(string('    '),$name)" />-&gt;show(SW_SHOW);
</xsl:if>
<xsl:if test="$visible = string('false')">
<xsl:value-of select="concat(string('    '),$name)" />-&gt;show(SW_HIDE);
</xsl:if>
    layout->addRebar( <xsl:value-of select="$name" /> );
<xsl:for-each select="./mol:add">
<xsl:call-template name="add">
<xsl:with-param name="name">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:for-each>
<xsl:for-each select="./mol:set">
<xsl:call-template name="set">
<xsl:with-param name="name">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:for-each>
</xsl:template>

<xsl:template name="rebarToolBarMaker">
<xsl:param name="parent"/>
<xsl:variable name="windowClass" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="name" select="./@name"/>
<xsl:variable name="bmp" select="./@bmp"/>
<xsl:variable name="icons" select="./@icons"/>
<xsl:variable name="width" select="./@width"/>
<xsl:variable name="height" select="./@height"/>
<xsl:variable name="layout" select="./@layout"/>
<xsl:variable name="visible" select="./@visible"/>
    //toolBar
    <xsl:value-of select="$windowClass" />* <xsl:value-of select="$name" /> = makeWindow&lt;<xsl:value-of select="$windowClass" />&gt;((HMENU)<xsl:value-of select="$id" />, Rect(0,0,<xsl:value-of select="$width"/>,<xsl:value-of select="$height"/>), (HWND)*<xsl:value-of select="$parent"  />);
    <xsl:value-of select="$name"  />-&gt;setBmp( <xsl:value-of select="$bmp" />, <xsl:value-of select="$icons" />, 16,16  );
    <xsl:value-of select="$name"  />-&gt;setButtonSize( 16,16  );
<xsl:for-each select="./mol:active">
<xsl:for-each select="./mol:toolbutton">
<xsl:call-template name="makeToolButton">
<xsl:with-param name="parent"><xsl:value-of select="$name" /></xsl:with-param>
<xsl:with-param name="bmp"><xsl:value-of select="$bmp" /></xsl:with-param>
</xsl:call-template>
</xsl:for-each>
</xsl:for-each>
<xsl:value-of select="concat(string('    '),$name)"  />-&gt;addButtons();
<xsl:for-each select="./mol:inactive">
<xsl:for-each select="./mol:toolbutton">
<xsl:call-template name="makeToolButton">
<xsl:with-param name="parent"><xsl:value-of select="$name" /></xsl:with-param>
<xsl:with-param name="bmp"><xsl:value-of select="$bmp" /></xsl:with-param>
</xsl:call-template>
</xsl:for-each>
</xsl:for-each>
<xsl:value-of select="concat(string('    '),$parent)"  />-&gt;addBar( *<xsl:value-of select="$name" />, <xsl:value-of select="$id" />, <xsl:value-of select="$width"/>  );
<xsl:if test="$visible != string('false')">
<xsl:value-of select="concat(string('    '),$parent)"  />-&gt;showBar(<xsl:value-of select="$id" />,true);
</xsl:if>
<xsl:if test="$visible != string('true')">
<xsl:value-of select="concat(string('    '),$parent)"  />-&gt;showBar(<xsl:value-of select="$id" />,false);
</xsl:if>
<xsl:for-each select="./mol:add">
<xsl:call-template name="add">
<xsl:with-param name="name">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:for-each>
<xsl:for-each select="./mol:set">
<xsl:call-template name="set">
<xsl:with-param name="name">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:for-each>
<xsl:call-template name="windowType">
<xsl:with-param name="parent">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:template>

<xsl:template name="makeToolButton">
<xsl:param name="parent"/>
<xsl:param name="bmp"/>
<xsl:variable name="cmd" select="./@cmd"/>
<xsl:variable name="dropdown" select="./@dropdown"/>
<xsl:if test="$dropdown = string('true')">
    <xsl:value-of select="concat(string('    '),$parent)"  />-&gt;addButton( mol::UI().BitmapCmdIndex(<xsl:value-of select="$bmp" />,<xsl:value-of select="$cmd" />),<xsl:value-of select="$cmd" /> , mol::UI().CmdString(<xsl:value-of select="$cmd" />),TBSTATE_ENABLED,BTNS_DROPDOWN );
</xsl:if>
<xsl:if test="not($dropdown) or $dropdown != string('true')">
    <xsl:value-of select="concat(string('    '),$parent)"  />-&gt;addButton( mol::UI().BitmapCmdIndex(<xsl:value-of select="$bmp" />,<xsl:value-of select="$cmd" />),<xsl:value-of select="$cmd" /> , mol::UI().CmdString(<xsl:value-of select="$cmd" />),TBSTATE_ENABLED,BTNS_BUTTON );
</xsl:if>
</xsl:template>

<xsl:template name="rebarBarMaker">
<xsl:param name="parent"/>
<xsl:param name="rebar"/>
<xsl:variable name="windowClass" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="name" select="./@name"/>
<xsl:variable name="width" select="./@width"/>
<xsl:variable name="height" select="./@height"/>
<xsl:variable name="advise" select="./@advise"/>
<xsl:variable name="layout" select="./@layout"/>
<xsl:variable name="visible" select="./@visible"/>
    //rebar bar
    <xsl:value-of select="$windowClass" />* <xsl:value-of select="$name" /> = makeWindow &lt; <xsl:value-of select="$windowClass" />&gt;((HMENU)<xsl:value-of select="$id" />, Rect(0,0,<xsl:value-of select="$width"/>,<xsl:value-of select="$height"/>), (HWND)*<xsl:value-of select="$parent"  />);
<xsl:if test="not($visible) or $visible != string('false')">
<xsl:value-of select="concat(string('    '),$name)" />-&gt;show(SW_SHOW);
</xsl:if>
<xsl:if test="$visible != string('true')">
<xsl:value-of select="concat(string('    '),$name)" />-&gt;show(SW_HIDE);
</xsl:if>
<xsl:value-of select="concat(string('    '),$rebar)"  />-&gt;addBar( *<xsl:value-of select="$name" />, <xsl:value-of select="$id" />, <xsl:value-of select="$width"/>  );
<xsl:if test="$advise != string('')">
<xsl:value-of select="concat(string('    '),$advise)" />-&gt;Advise(<xsl:value-of select="$name" />&lt;oleObject);
</xsl:if>
<xsl:for-each select="./mol:add">
<xsl:call-template name="add">
<xsl:with-param name="name">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:for-each>
<xsl:for-each select="./mol:set">
<xsl:call-template name="set">
<xsl:with-param name="name">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:for-each>
<xsl:call-template name="windowType">
<xsl:with-param name="parent">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:template>

<xsl:template name="set">
<xsl:param name="name"/>
<xsl:variable name="member" select="./@member"/>
<xsl:value-of select="concat(string('    '),$name)"  />-&gt;set<xsl:value-of select="$member"  />(<xsl:value-of select="."  />);
</xsl:template>

<xsl:template name="add">
<xsl:param name="name"/>
<xsl:variable name="member" select="./@member"/>
<xsl:value-of select="concat(string('    '),$name)"  />-&gt;add<xsl:value-of select="$member"  />(<xsl:value-of select="."  />);
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
//childWindow
<xsl:value-of select="concat(string('    '),$class)" />* <xsl:value-of select="$name" />() { return mol::UI().Wnd&lt;<xsl:value-of select="$class" />&gt;(<xsl:value-of select="$id" />); }
<xsl:call-template name="windowTypeFunction">
<xsl:with-param name="parent">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:template>

<xsl:template name="statusBarFunctionMaker">
<xsl:param name="parent"/>
<xsl:variable name="class" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="name" select="./@name"/>
//statusbar
<xsl:value-of select="concat(string('    '),$class)" />* <xsl:value-of select="$name" />() { return mol::UI().Wnd&lt;<xsl:value-of select="$class" />&gt;(<xsl:value-of select="$id" />); }
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
<xsl:value-of select="concat(string('    '),$class)" />* <xsl:value-of select="$name" />() { return mol::UI().Wnd&lt;<xsl:value-of select="$class" />&gt;(<xsl:value-of select="$id" />); }
<!--
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
-->
</xsl:template>


<xsl:template name="rebarToolBarFunctionMaker">
<xsl:param name="parent"/>
<xsl:variable name="class" select="./@class"/>
<xsl:variable name="id" select="./@id"/>
<xsl:variable name="name" select="./@name"/>
//toolBar
<xsl:value-of select="concat(string('    '),$class)" />* <xsl:value-of select="$name" />() { return mol::UI().Wnd&lt;<xsl:value-of select="$class" />&gt;(<xsl:value-of select="$id" />); }

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
//rebar bar
<xsl:value-of select="concat(string('    '),$class)" />* <xsl:value-of select="$name" />() { return mol::UI().Wnd&lt;<xsl:value-of select="$class" />&gt;(<xsl:value-of select="$id" />); }
<xsl:call-template name="windowTypeFunction">
<xsl:with-param name="parent">
<xsl:value-of select="$name" />
</xsl:with-param>
</xsl:call-template>
</xsl:template>


</xsl:stylesheet>
