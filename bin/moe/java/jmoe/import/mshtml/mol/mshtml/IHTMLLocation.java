package mol.mshtml  ;

import com4j.*;

@IID("{163BB1E0-6E00-11CF-837A-48DC04C10000}")
public interface IHTMLLocation extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    void href(
        java.lang.String p);

    @VTID(8)
    @DefaultMethod
    java.lang.String href();

    @VTID(9)
    void protocol(
        java.lang.String p);

    @VTID(10)
    java.lang.String protocol();

    @VTID(11)
    void host(
        java.lang.String p);

    @VTID(12)
    java.lang.String host();

    @VTID(13)
    void hostname(
        java.lang.String p);

    @VTID(14)
    java.lang.String hostname();

    @VTID(15)
    void port(
        java.lang.String p);

    @VTID(16)
    java.lang.String port();

    @VTID(17)
    void pathname(
        java.lang.String p);

    @VTID(18)
    java.lang.String pathname();

    @VTID(19)
    void search(
        java.lang.String p);

    @VTID(20)
    java.lang.String search();

    @VTID(21)
    void hash(
        java.lang.String p);

    @VTID(22)
    java.lang.String hash();

    @VTID(23)
    void reload(
        boolean flag);

    @VTID(24)
    void replace(
        java.lang.String bstr);

    @VTID(25)
    void assign(
        java.lang.String bstr);

    @VTID(26)
    java.lang.String toString_();

}
