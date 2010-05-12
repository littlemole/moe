package mol.mshtml  ;

import com4j.*;

@IID("{FECEAAA5-8405-11CF-8BA1-00AA00476DA6}")
public interface IOmNavigator extends Com4jObject {
    @VTID(7)
    java.lang.String appCodeName();

    @VTID(8)
    java.lang.String appName();

    @VTID(9)
    java.lang.String appVersion();

    @VTID(10)
    java.lang.String userAgent();

    @VTID(11)
    boolean javaEnabled();

    @VTID(12)
    boolean taintEnabled();

    @VTID(13)
    mol.mshtml.IHTMLMimeTypesCollection mimeTypes();

    @VTID(14)
    mol.mshtml.IHTMLPluginsCollection plugins();

    @VTID(15)
    boolean cookieEnabled();

    @VTID(16)
    mol.mshtml.IHTMLOpsProfile opsProfile();

    @VTID(17)
    java.lang.String toString_();

    @VTID(18)
    java.lang.String cpuClass();

    @VTID(19)
    java.lang.String systemLanguage();

    @VTID(20)
    java.lang.String browserLanguage();

    @VTID(21)
    java.lang.String userLanguage();

    @VTID(22)
    java.lang.String platform();

    @VTID(23)
    java.lang.String appMinorVersion();

    @VTID(24)
    int connectionSpeed();

    @VTID(25)
    boolean onLine();

    @VTID(26)
    mol.mshtml.IHTMLOpsProfile userProfile();

}
