package mol.excel  ;

import com4j.*;

@IID("{00020400-0000-0000-C000-000000000046}")
public interface SmartTagAction extends Com4jObject {
    @DISPID(148)
    @PropGet
    mol.excel._Application application();

    @DISPID(149)
    @PropGet
    mol.excel.XlCreator creator();

    @DISPID(150)
    @PropGet
    com4j.Com4jObject parent();

    @DISPID(110)
    @PropGet
    java.lang.String name();

    @DISPID(2211)
    void execute();

    @DISPID(0)
    @PropGet
    @DefaultMethod
    java.lang.String _Default();

    @DISPID(108)
    @PropGet
    mol.excel.XlSmartTagControlType type();

    @DISPID(2297)
    @PropGet
    boolean presentInPane();

    @DISPID(2298)
    @PropGet
    boolean expandHelp();

    @DISPID(2298)
    @PropPut
    void expandHelp(
        boolean rhs);

    @DISPID(2299)
    @PropGet
    boolean checkboxState();

    @DISPID(2299)
    @PropPut
    void checkboxState(
        boolean rhs);

    @DISPID(2300)
    @PropGet
    java.lang.String textboxText();

    @DISPID(2300)
    @PropPut
    void textboxText(
        java.lang.String rhs);

    @DISPID(2301)
    @PropGet
    int listSelection();

    @DISPID(2301)
    @PropPut
    void listSelection(
        int rhs);

    @DISPID(2302)
    @PropGet
    int radioGroupSelection();

    @DISPID(2302)
    @PropPut
    void radioGroupSelection(
        int rhs);

    @DISPID(2303)
    @PropGet
    com4j.Com4jObject activeXControl();

}
