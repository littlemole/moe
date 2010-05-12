<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:mol="urn:mol-codegen"
                xmlns="urn:mol-codegen"
                xmlns:xs="http://www.w3.org/2001/XMLSchema"
                >
<xsl:output method="text"/>
<xsl:param name="padding" select="string('                                        ')"/>
<xsl:template match="/mol:codegen">
<xsl:for-each select="./mol:msgs">
<xsl:for-each select="./mol:class">
<xsl:call-template name="registerEvents" />
</xsl:for-each>
</xsl:for-each>

}

</xsl:template>

<xsl:template name="registerEvents">

<xsl:variable name="wndClass" select="./@type"/>
<xsl:for-each select="./mol:msg">
<xsl:variable name="handler" select="./@handler"/>
<xsl:variable name="stdhandler" select="./@stdhandler"/>
<xsl:variable name="msg" select="./@msg"/>
<xsl:variable name="cmd" select="./@cmd"/>
<xsl:variable name="command" select="./@command"/>
<xsl:variable name="notify" select="./@notify"/>
<xsl:variable name="ole" select="./@ole"/>
<xsl:variable name="params" select="./@params"/>
<xsl:variable name="interface" select="./@interface"/>
<xsl:variable name="member" select="./@member"/>

<xsl:if test="$member">
</xsl:if>
<xsl:if test="not($member)">
<xsl:if test="$msg">
<xsl:if test="$stdhandler">
mol::msgMap&lt;<xsl:value-of select="$wndClass" />&gt;().addMsgHandler( <xsl:value-of select="$msg" />, make_handler(&amp;<xsl:value-of select="$wndClass" />::<xsl:value-of select="$stdhandler" />) );
</xsl:if>
<xsl:if test="$handler">
<xsl:if test="not($params)">
mol::msgMap&lt;<xsl:value-of select="$wndClass" />&gt;().addMsgHandler( <xsl:value-of select="$msg" />, make_handler(&amp;<xsl:value-of select="$wndClass" />::<xsl:value-of select="$handler" />) );
</xsl:if>
<xsl:if test="$params">
mol::msgMap&lt;<xsl:value-of select="$wndClass" />&gt;().addMsgHandler( <xsl:value-of select="$msg" />, make_generic_handler(&amp;<xsl:value-of select="$wndClass" />::<xsl:value-of select="$handler" />, <xsl:value-of select="$params" /> ) );
</xsl:if>
</xsl:if>
</xsl:if>
<xsl:if test="$cmd">
<xsl:if test="$params">
mol::msgMap&lt;<xsl:value-of select="$wndClass" />&gt;().addCmdHandler( <xsl:value-of select="$cmd" />, make_generic_handler(&amp;<xsl:value-of select="$wndClass" />::<xsl:value-of select="$handler" />, <xsl:value-of select="$params" /> ) );
</xsl:if>
<xsl:if test="$stdhandler and not($params)">
mol::msgMap&lt;<xsl:value-of select="$wndClass" />&gt;().addCmdHandler( <xsl:value-of select="$cmd" />, make_handler(&amp;<xsl:value-of select="$wndClass" />::<xsl:value-of select="$stdhandler" />) );
</xsl:if>
<xsl:if test="$handler and not($params)">
mol::msgMap&lt;<xsl:value-of select="$wndClass" />&gt;().addCmdHandler( <xsl:value-of select="$cmd" />, make_handler(&amp;<xsl:value-of select="$wndClass" />::<xsl:value-of select="$handler" />) );
</xsl:if>
<xsl:if test="$ole">
mol::msgMap&lt;<xsl:value-of select="$wndClass" />&gt;().addCmdHandler( <xsl:value-of select="$cmd" />, make_ole_handler&lt;<xsl:value-of select="$wndClass" />&gt;(&amp;<xsl:value-of select="$interface" />::<xsl:value-of select="$ole" />) );
</xsl:if>
</xsl:if>
<xsl:if test="$command">
<xsl:if test="$stdhandler">
mol::msgMap&lt;<xsl:value-of select="$wndClass" />&gt;().addCmdHandler( <xsl:value-of select="$command" />, make_handler(&amp;<xsl:value-of select="$wndClass" />::<xsl:value-of select="$stdhandler" />) );
</xsl:if>
<xsl:if test="$handler">
mol::msgMap&lt;<xsl:value-of select="$wndClass" />&gt;().addCmdHandler( <xsl:value-of select="$command" />, make_handler(&amp;<xsl:value-of select="$wndClass" />::<xsl:value-of select="$handler" />) );
</xsl:if>
</xsl:if>
<xsl:if test="$notify">
mol::msgMap&lt;<xsl:value-of select="$wndClass" />&gt;().addNotifyHandler( <xsl:value-of select="$notify" />, make_handler(&amp;<xsl:value-of select="$wndClass" />::<xsl:value-of select="$handler" />) );
</xsl:if>
</xsl:if>


</xsl:for-each>
<xsl:for-each select="./mol:msgrange">
<xsl:variable name="type" select="./@type"/>
<xsl:variable name="handler" select="./@handler"/>
<xsl:variable name="stdhandler" select="./@stdhandler"/>
<xsl:variable name="from" select="./@from"/>
<xsl:variable name="to" select="./@to"/>

<xsl:if test="$type = string('cmd')">
<xsl:if test="$handler">
make_command_range_handler( <xsl:value-of select="$wndClass" />, <xsl:value-of select="$from" />, <xsl:value-of select="$to" />, <xsl:value-of select="$handler" /> );
</xsl:if>
<xsl:if test="$stdhandler">
make_cmd_range_handler( <xsl:value-of select="$wndClass" />, <xsl:value-of select="$from" />, <xsl:value-of select="$to" />, <xsl:value-of select="$stdhandler" /> );
</xsl:if>
</xsl:if>
</xsl:for-each>
<xsl:for-each select="./mol:notify">
<xsl:variable name="handler" select="./@handler"/>
<xsl:variable name="stdhandler" select="./@stdhandler"/>
<xsl:variable name="ctrl" select="./@ctrl"/>
<xsl:variable name="code" select="./@code"/>

<xsl:if test="$ctrl">
<xsl:if test="$handler">
mol::msgMap&lt;<xsl:value-of select="$wndClass" />&gt;().addNotifyIdHandler( <xsl:value-of select="$ctrl" />, make_handler(&amp;<xsl:value-of select="$wndClass" />::<xsl:value-of select="$handler" />) );
</xsl:if>
<xsl:if test="$stdhandler">
mol::msgMap&lt;<xsl:value-of select="$wndClass" />&gt;().addNotifyIdHandler( <xsl:value-of select="$ctrl" />, make_handler(&amp;<xsl:value-of select="$wndClass" />::<xsl:value-of select="$stdhandler" />) );
</xsl:if>
</xsl:if>

<xsl:if test="$code">
<xsl:if test="$handler">
mol::msgMap&lt;<xsl:value-of select="$wndClass" />&gt;().addNotifyCodeHandler( <xsl:value-of select="$code" />, make_handler(&amp;<xsl:value-of select="$wndClass" />::<xsl:value-of select="$handler" />) );
</xsl:if>
<xsl:if test="$stdhandler">
mol::msgMap&lt;<xsl:value-of select="$wndClass" />&gt;().addNotifyCodeHandler( <xsl:value-of select="$code" />, make_handler(&amp;<xsl:value-of select="$wndClass" />::<xsl:value-of select="$stdhandler" />) );
</xsl:if>
</xsl:if>
</xsl:for-each>
</xsl:template>







</xsl:stylesheet>
